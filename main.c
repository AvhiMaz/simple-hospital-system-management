#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100

// Structure to store patient information
struct Patient {
    char name[50];
    int age;
    char gender;
    char condition[100];
};

// Function to display menu
void displayMenu() {
    printf("\nHospital Management System\n");
    printf("1. Add Patient\n");
    printf("2. View Patients\n");
    printf("3. Search Patient by Name\n");
    printf("4. Display Patient Statistics\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

// Function to search for a patient by name
int searchPatient(const struct Patient patients[], int patientCount, const char *name) {
    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].name, name) == 0) {
            return i; // Return the index of the found patient
        }
    }
    return -1; // Patient not found
}

// Function to display patient statistics
void displayStatistics(const struct Patient patients[], int patientCount) {
    int maleCount = 0, femaleCount = 0;
    int totalAge = 0;

    for (int i = 0; i < patientCount; i++) {
        totalAge += patients[i].age;
        if (patients[i].gender == 'M' || patients[i].gender == 'm') {
            maleCount++;
        } else if (patients[i].gender == 'F' || patients[i].gender == 'f') {
            femaleCount++;
        }
    }

    printf("\nPatient Statistics:\n");
    printf("Total Patients: %d\n", patientCount);
    printf("Male Patients: %d\n", maleCount);
    printf("Female Patients: %d\n", femaleCount);
    printf("Average Age: %.2f\n", (float)totalAge / patientCount);
}

int main() {
    struct Patient patients[MAX_PATIENTS];
    int patientCount = 0;

    int choice;
    #include <stdio.h>

    printf("  _                     _ _        _                                                               _                   _                 \n");
    printf(" | |                   (_) |      | |                                                             | |                 | |                \n");
    printf(" | |__   ___  ___ _ __  _| |_ __ _| |  _ __ ___   __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_   ___ _   _ ___| |_ ___ _ __ ___  \n");
    printf(" | '_ \\ / _ \\/ __| '_ \\| | __/ _` | | | '_ ` _ \\ / _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __| / __| | | / __| __/ _ \\ '_ ` _ \\ \n");
    printf(" | | | | (_) \\__ \\ |_) | | || (_| | | | | | | | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_  \\__ \\ |_| \\__ \\ ||  __/ | | | | |\n");
    printf(" |_| |_|\\___/|___/ .__/|_|\\__\\__,_|_| |_| |_| |_|\\__,_|_| |_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__| |___/\\__, |___/\\__\\___|_| |_| |_|\n");
    printf("                 | |                                           __/ |                                     __/ |                      \n");
    printf("                 |_|                                          |___/                                     |___/                       \n");

    printf("\033[1;31m");
    printf("*********** Made by  ***********\n");
    printf("*********** Avhi Mazumder  ***********\n");
    printf("*********** Jaishri Mahalia  ***********\n");
    printf("*********** Affan Khan  ***********\n");
    printf("*********** Md Sibgatullah  ***********\n");
    printf("*********** Arnab Nath  ***********\n");
    printf("\033[0m");

    do {    
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (patientCount < MAX_PATIENTS) {
                    printf("\nEnter patient details:\n");
                    printf("Name: ");
                    scanf("%s", patients[patientCount].name);
                    printf("Age: ");
                    while(scanf("%d",&patients[patientCount].age) != 1 || patients[patientCount].age < 0){
                        printf("Invalid age! Please enter a valid age: ");
                        scanf("%*s");
                    }
                    printf("Gender (M/F): ");
                    scanf(" %c", &patients[patientCount].gender);
                    printf("Condition: ");
                    scanf("%s", patients[patientCount].condition);

                    printf("\nPatient added successfully!\n");
                    patientCount++;
                } else {
                    printf("\nMaximum number of patients reached!\n");
                }
                break;

            case 2:
                printf("\nPatient List:\n");
                if (patientCount > 0) {
                    for (int i = 0; i < patientCount; i++) {
                        printf("Name: %s, Age: %d, Gender: %c, Condition: %s\n",
                               patients[i].name, patients[i].age,
                               patients[i].gender, patients[i].condition);
                    }
                } else {
                    printf("No patients found.\n");
                }
                break;

            case 3:
                if (patientCount > 0) {
                    char searchName[50];
                    printf("\nEnter the name of the patient to search: ");
                    scanf("%s", searchName);
                    int index = searchPatient(patients, patientCount, searchName);
                    if (index != -1) {
                        printf("\nPatient found:\n");
                        printf("Name: %s, Age: %d, Gender: %c, Condition: %s\n",
                               patients[index].name, patients[index].age,
                               patients[index].gender, patients[index].condition);
                    } else {
                        printf("\nPatient not found.\n");
                    }
                } else {
                    printf("\nNo patients found.\n");
                }
                break;

            case 4:
                if (patientCount > 0) {
                    displayStatistics(patients, patientCount);
                } else {
                    printf("\nNo patients found.\n");
                }
                break;

            case 5:
                printf("\nExiting program. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}
