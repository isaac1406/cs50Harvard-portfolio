#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <time.h>

// Structure to store patient information
typedef struct {
    char name[100]; // Patient's name
    int severity; // Severity level of symptoms
    time_t arrival_time; // Arrival time
    int position; // Current position in the list
} RECORD;

// Node structure of the linked list
typedef struct aux {
    RECORD rec;
    struct aux* next; // Pointer to the next patient in the list
} PATIENT;

typedef PATIENT* POINTER;

// Structure for the patient list
typedef struct {
    POINTER start;
} LIST;

// Function to initialize the patient list
void initializeList(LIST* l);

// Function to create a new patient
POINTER createPatient(const char* name, int severity, time_t arrival_time);

// Function to update the positions in the list
void updatePositions(const LIST* l);

// Function to insert a patient into the list in an ordered manner
void insertPatientOrdered(LIST* l, POINTER new_patient);

// Function to search for a patient by name
POINTER searchPatient(const LIST* l, const char* name);

// Function to remove a patient from the list based on the name
void removePatient(LIST* l, const char* name);

// Function to save the patient list to a binary file
void savePatientsToFile(const LIST* l, char* file_name);

// Function to display a specific number of ordered patients in the list
void displayList(const LIST* l, int quantity);

// Function to free the memory allocated for the patient list
void freeList(LIST* l);

#endif // FUNCTIONS_H
