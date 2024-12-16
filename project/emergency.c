#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 100

int main() {
    // Declaration of the list of all patients of the day and the list that will be updated throughout the day
    LIST* totalList = (LIST*)malloc(sizeof(LIST));
    if (!totalList) {
        puts("Error allocating memory for totalList");
        return 1;
    }
    LIST* currentList = (LIST*)malloc(sizeof(LIST));
    if (!currentList) {
        puts("Error allocating memory for currentList");
        return 1;
    }

    // Initialize lists
    initializeList(totalList);
    initializeList(currentList);

    // Declaration of all variables that will be used throughout the main
    int severity;
    time_t arrival_time;
    int option = 0;
    int access = 0;
    int quantity = 0;

    // Execute the following commands...
    do {
        char name[MAX];
        // Functionalities available for the user to choose
        printf("\t==========================\n");
        puts("Queue System for Hospital Reception");
        printf("\t==========================\n");
        puts("\t1. Add patient");
        puts("\t2. Remove patient");
        puts("\t3. Search patient");
        puts("\t4. View ordered list");
        puts("\t5. Save and exit");
        printf("Choose an option: ");
        // Read chosen option
        scanf("%d", &option);

        switch(option) {
            // Add patient
            case 1:
                // Read patient's name
                printf("\nPatient's name: ");
                getchar();
                fgets(name, MAX, stdin);
                // Read Severity of Symptoms
                printf("\nSeverity of symptoms (1-10): ");
                scanf("%d", &severity);
                // Get Arrival Time
                arrival_time = time(NULL);
                // Create Patient
                PATIENT* new_patient = createPatient(name, severity, arrival_time);
                // Insert patient into lists and order them (Insertion Sort)
                insertPatientOrdered(totalList, new_patient);
                insertPatientOrdered(currentList, new_patient);
                break;

            // Remove attended patient from the current list
            case 2:
                // Read patient's name
                printf("\nPatient's name or F to exit: ");
                getchar();
                fgets(name, MAX, stdin);
                if (strcmp(name, "F\n") != 0 && strcmp(name, "f\n") != 0) {
                    // Remove patient
                    removePatient(currentList, name);
                    // Update list positions
                    updatePositions(currentList);
                }
                else {
                    printf("Exiting... \n");
                    break;
                }
                break;

            // Search Patient in the current list
            case 3:
                // Read desired patient's name
                printf("\nPatient's name to search: ");
                getchar();
                fgets(name, MAX, stdin);
                // Search patient in the list (Sequential search)
                PATIENT* found = searchPatient(currentList, name);

                // If the patient was found...
                if (found != NULL) {
                    // Print their data
                    printf("--------------------------------------------\n");
                    printf("Patient found:\nName: %sSeverity: %d\nPosition: %d\nArrival time: %s\n",
                           found->rec.name, found->rec.severity, found->rec.position,
                           ctime(&found->rec.arrival_time));
                    printf("--------------------------------------------\n");
                }
                // If not...
                else {
                    printf("------------------------\n");
                    puts("Patient not found.");
                    printf("------------------------\n");
                }
                break;

            // View ordered list
            case 4:
                // Decide which list to access
                printf("\nEnter 1 to access the total list or enter 2 for the current list: ");
                scanf("%d", &access);

                // Read the quantity
                printf("\nDesired number of patients to be seen from the list: ");
                scanf("%d", &quantity);

                // Display total list
                if (access == 1){
                    displayList(totalList, quantity);
                }
                // Display current list
                else if (access == 2){
                    displayList(currentList, quantity);
                }
                // Invalid option
                else{
                    puts("Invalid list option.");
                }
                break;

            // Save and exit
            case 5:
                // Get the current time
                time_t now = time(NULL);
                struct tm* t = localtime(&now);

                // Create a string for the file name with date
                char file_name_date[150];
                strftime(file_name_date, sizeof(file_name_date),
                    "attendance_control_%d-%m-%Y.bin", t);

                // Save patient list to a binary file
                savePatientsToFile(totalList, file_name_date);
                // Free allocated memory for the list
                freeList(totalList);
                freeList(currentList);
                // Exit message
                printf("Data saved. Exiting...\n");
                break;

            // Invalid option
            default:
                printf("Invalid option.\n");
        }
    } while(option != 5); // Stay in the loop while option is different from 5

    return 0;
}
