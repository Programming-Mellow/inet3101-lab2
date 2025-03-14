#include <stdlib.h>
#include <stdio.h>

// Lab 2
// Created by Wendy Vang & Venice Fan

//struct 
struct Part {
    int number;
    char name[50];
    float size;
    char metric[10];
    float cost;
};

static int recordCount = 0;

//ptr to latest struct Part
struct Part *database = 0;

//ptr to start of database
struct Part *beginning = 0;

void printRecords() {
    if (recordCount <= 0) {
        printf("\nThere is nothing to print.\n");
    }

    //assign the jump pointer to the beginning of the database
    struct Part *jump = beginning;
    for (int i = 0; i < recordCount; i++) {
        printf("\nPart Number: %d\n", jump->number);
        printf("Part Name: %s\n", jump->name);
        printf("Part Size: %.2f\n", jump->size);
        printf("Part Size Metric: %s\n", jump->metric);
        printf("Part Cost: %.2f\n", jump->cost);

        //utilizing pointer arithmetic to jump from one entry to another. cast the pointer from a struct pointer to a char pointer so byte arithmetic stuff can be performed. we can assume that the structs are stored next to each other in memory. yay CSCI 2021 knowledge!
        jump = (struct Part *)((char *)jump + sizeof(struct Part));
    }
}

void addRecord() {
    struct Part newPart;

    printf("\nPlease enter in your selection\n");
    
    printf("\nINTEGER ONLY:\nPart Number -> ");
    scanf("%d", &newPart.number);
    
    printf("\nSTRING ONLY:\nPart Name -> ");
    scanf(" %[^\n]", newPart.name);
    
    printf("\nFLOAT ONLY:\nPart Size -> ");
    scanf("%f", &newPart.size);
    
    printf("\nSTRING ONLY:\nPart Size Metric -> ");
    scanf(" %[^\n]", newPart.metric);
    
    printf("\nFLOAT ONLY:\nPart Cost -> ");
    scanf("%f", &newPart.cost);
    
    recordCount++;

    printf("\nYou entered\n  Part Number = %d\n  Part Name = '%s'\n  Part Size = %f\n  Part Size Metric = '%s'\n  Part Cost = $%f", newPart.number, newPart.name, newPart.size, newPart.metric, newPart.cost);

    //create new ptr and allocate space and assign address to the allocated memory
    struct Part *newDatabase = realloc(database, recordCount * sizeof(struct Part));

    for (int i = 0; i < recordCount - 1; i++) {
        newDatabase[i] = database[i];
    }

    //insert newPart into the end of the new database
    newDatabase[recordCount - 1] = newPart;

    database = newDatabase;

    //set beginning ptr if we just newly created the database
    if (recordCount == 1) {
        beginning = database;
    }

}

void deleteRecord() {
    recordCount--;
    
    struct Part *newDatabase = realloc(database, recordCount * sizeof(struct Part));
    
    for (int i = 0; i < recordCount; i++) {
        newDatabase[i] = database[i];
    }

    database = newDatabase;

    printf("\nDatabase now contains %d records.\n", recordCount);
}

void numberOfRecords() {
    printf("There are %d entries in the database.\n", recordCount);
}

void databaseSize() {
    printf("The database size is currently %zu bytes.\n", (sizeof(struct Part) * recordCount));
}

int main() {
    int looper = 6;
    int selection;

    while (looper <= 6){
        printf("\n\nParts Inventory Manager\n\n");
        printf("1. Print All Records\n");
        printf("2. Add a Record\n");
        printf("3. Delete the Last Record\n");
        printf("4. Print Number of Records\n");
        printf("5. Print Database Size\n");
        printf("6. Exit\n\n");

        printf("Please enter your selection: ");
        scanf("%d", &selection);

        switch (selection) {

            case 1:
                printRecords();
                break;

            case 2:
                addRecord();
                break;

            case 3:
                deleteRecord();
                break;

            case 4:
                numberOfRecords();
                break;
            
            case 5:
                databaseSize();
                break;

            case 6:
                printf("\n\nExiting Now...\n\n");
                looper = selection;
                free(database);
                return 1;

            default:
                printf("\nInvalid option! Please select a valid command.");
                break;
        }
    }

    return 0;
}