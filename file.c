#include <stdio.h>
#include <string.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *file = fopen("contacts.csv", "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        // Replace any existing commas in fields with spaces for CSV safety
        char safeName[50], safePhone[20], safeEmail[50];
        strcpy(safeName, addressBook->contacts[i].name);
        strcpy(safePhone, addressBook->contacts[i].phone);
        strcpy(safeEmail, addressBook->contacts[i].email);
        
        // Replace commas with spaces
        for (char *p = safeName; *p; p++) if (*p == ',') *p = ' ';
        for (char *p = safePhone; *p; p++) if (*p == ',') *p = ' ';
        for (char *p = safeEmail; *p; p++) if (*p == ',') *p = ' ';

        fprintf(file, "%s,%s,%s\n", safeName, safePhone, safeEmail);
    }

    fclose(file);
    printf("Contacts saved to contacts.csv successfully!\n");
}


void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *file = fopen("contacts.csv", "r");
    if (!file) 
    {
        printf("No existing contact file found. Starting fresh.\n");
        return;
    }

    addressBook->contactCount = 0; // Reset counter
    
    while (fscanf(file, "%49[^,],%19[^,],%49[^\n]\n", 
                 addressBook->contacts[addressBook->contactCount].name,
                 addressBook->contacts[addressBook->contactCount].phone,
                 addressBook->contacts[addressBook->contactCount].email) == 3) 
                 {
        
        addressBook->contactCount++;
        if (addressBook->contactCount >= MAX_CONTACTS) 
        {
            break;
        }
    }

    fclose(file);
    printf("Loaded %d contacts from file.\n", addressBook->contactCount);
}
