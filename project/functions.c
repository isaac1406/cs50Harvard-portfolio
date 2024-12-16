#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to initialize the patient list
void initializeList(LIST* l){
    l->start = NULL;
}

// Function to create a new patient
POINTER createPatient(const char* name, int severity, time_t arrival_time){
    PATIENT *new = (PATIENT *)malloc(sizeof(PATIENT));
    if(new == NULL) {
        printf("Error allocating memory");
        return NULL;
    }
    strcpy(new->rec.name, name);
    new->rec.severity = severity;
    new->rec.arrival_time = arrival_time;
    new->rec.position = 0;
    new->next = NULL;

    return new;
}

// Function to update the positions in the list
void updatePositions(const LIST* l) {
    // Initialize the position of the first patient
    int pos = 1;

    // Traverse the updated list
    PATIENT* current = l->start;
    while (current != NULL) {
        current->rec.position = pos; // Assign the position to the patient
        current = current->next; // Move to the next patient
        pos++; // Increment the position
    }
}

// Function to insert a patient into the list in an ordered manner
void insertPatientOrdered(LIST* l, POINTER new_patient) {
    // Create a copy of the patient to ensure it is not shared between lists
    PATIENT* patient_copy = (PATIENT*)malloc(sizeof(PATIENT));
    if (!patient_copy) {
        printf("Error allocating memory for the patient.\n");
        return;
    }
    *patient_copy = *new_patient; // Deep copy of the patient

    // If the list is empty, add directly at the start
    if (l->start == NULL) {
        l->start = patient_copy;
        patient_copy->next = NULL;
    } else {
        PATIENT* current = l->start;

        // Patient should be inserted at the start if more urgent or with earlier arrival time
        if (current->rec.severity < patient_copy->rec.severity ||
            (current->rec.severity == patient_copy->rec.severity &&
             current->rec.arrival_time > patient_copy->rec.arrival_time)) {
            patient_copy->next = l->start;
            l->start = patient_copy;
        } else {
            // Advance in the list while:
            // 1. The next patient has higher severity, or
            // 2. Severity is equal and the next patient arrived earlier
            while (current->next != NULL &&
                   (current->next->rec.severity > patient_copy->rec.severity ||
                   (current->next->rec.severity == patient_copy->rec.severity &&
                    current->next->rec.arrival_time <= patient_copy->rec.arrival_time))) {
                current = current->next;
            }

            // Insert the patient after the found point
            patient_copy->next = current->next;
            current->next = patient_copy;
        }
    }

    // Update positions in the list
    updatePositions(l);
}

// Function to search for a patient by name
POINTER searchPatient(const LIST* l, const char* name)
{
    POINTER current = l->start;

    while(current != NULL){
        if(strcmp(current->rec.name, name) == 0){
            return current;  // If equal to 0, both strings are the same, hence, patient found
        }
        current = current->next;
    }

    return NULL;  // Patient not found
}

// Function to remove a patient from the list based on the name
void removePatient(LIST* l, const char* name)
{
    if (l == NULL || l->start == NULL) {  // Check if the list is empty
        printf("The list is empty.\n");
        return;
    }

    POINTER patient = searchPatient(l, name);

    // Check if the patient is in the list
    if(patient == NULL){
        printf("------------------------\n");
        printf("Patient not found.\n");
        printf("------------------------\n");
        return;
    }

    // The desired patient is at the start of the list
    if(l->start == patient){

        l->start = l->start->next;
        free(patient);
        printf("-------------------------------\n");
        printf("Patient successfully removed.\n");
        printf("-------------------------------\n");
        updatePositions(l);
        return;
    }

    POINTER current = l->start;

    // The desired patient is at another position in the list
    while(current != NULL){

        if(current->next == patient){

            current->next = patient->next;
            free(patient);
            printf("-------------------------------\n");
            printf("Patient successfully removed.\n");
            printf("-------------------------------\n");
            updatePositions(l);
            return;
        }

        current = current->next;
    }
    printf("------------------------\n");
    printf("Patient not found.\n");
    printf("------------------------\n");
}

// Function to save the patient list to a binary file
void savePatientsToFile(const LIST* l, char* file_name)
{
    FILE *file = fopen(file_name, "wb");
    // Check if there was an error creating the file
    if(file == NULL){
        printf("Error opening the file\n");
        return;
    }

    // Check if the list is empty
    if (l == NULL || l->start == NULL) {
        fclose(file);
        printf("-------------------\n");
        printf("The list is empty.\n");
        printf("-------------------\n");
        return;
    }

    POINTER current = l->start;

    // Traverse the list, writing the data to the file
    while(current != NULL){

        fwrite(&(current->rec), sizeof(RECORD), 1, file);

        current = current->next;
    }
    // Closing the file and declaring success
    fclose(file);
    printf("---------------------------------\n");
    printf("Patients saved in the file '%s'.\n", file_name);
    printf("---------------------------------\n");
}

// Function to display a specific number of ordered patients in the list
void displayList(const LIST* l, int quantity)
{
    if (l == NULL || l->start == NULL) {  // Check if the list is empty
        printf("----------------------------------------------------------\n");
        printf("The list is empty or the requested quantity is invalid.\n");
        printf("----------------------------------------------------------\n");
        return;
    }

    if (quantity <= 0) {  // Ensure "quantity" is positive and greater than 0
        printf("----------------------------------\n");
        printf("Requested quantity is invalid.\n");
        printf("----------------------------------\n");
        return;
    }

    POINTER current = l->start;
    int count = 0;

    while((current != NULL) && (count < quantity)){
        printf("------------------------\n");
        printf("Position: %d \n", current->rec.position);
        printf("Name: %s", current->rec.name);
        printf("Severity: %d \n", current->rec.severity);
        printf("Arrival Time: %s", ctime(&current->rec.arrival_time));
        printf("------------------------\n");  // Visually facilitates separation between patients
        current = current->next;
        count++;
    }
}

// Function to free the memory allocated for the patient list
void freeList(LIST* l){
    if(l == NULL)  // Check if the list is empty
        return;

    POINTER current = l->start;

    while(current != NULL){
        POINTER to_delete = current;
        current = current->next;
        free(to_delete);
    }

    l->start = NULL;
}