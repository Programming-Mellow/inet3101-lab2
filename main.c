// Lab 2
// Created by Wendy Vang & Venice Fan

// wendy -> create own realloc() function for extra credit. NO linked list!

//venice -> create struct for part (number, name, size, size metric, cost)

void printRecords(){
    printf("\nYou have entered the Print All Records function\n\n");
}

void addRecord() {
    int parts = 0;
    int number;
    char name[50];
    float size;
    char metric[10];
    float cost;

    while (parts <= 4) {
        printf("\nPlease enter in your selection\n");
        if (parts == 0) {
            printf("\nINTEGER ONLY:\nPart Number -> ");
            scanf("%d", &number);
        }   
        else if (parts == 1) {
            printf("\nSTRING ONLY:\nPart Name -> ");
            scanf(" %[^\n]", name);
        }
        else if (parts == 2) {
            printf("\nFLOAT ONLY:\nPart Size -> ");
            scanf("%f", &size);
        }
        else if (parts == 3) {
            printf("\nSTRING ONLY:\nPart Size Metric -> ");
            scanf(" %[^\n]", metric);
        }
        else {
            printf("\nFLOAT ONLY:\nPart Cost -> ");
            scanf("%f", &cost);
        }
        parts++;
    }

    printf("\nYou entered\n  Part Number = %d\n  Part Name = '%s'\n  Part Size = %f\n  Part Size Metric = '%s'\n  Part Cost = $%f", number, name, size, metric, cost);
}

void deleteRecord() {
    printf("\nYou have entered the Delete Last Record function\n\n");
}

void numberOfRecords() {
    printf("\nYou have entered the Print Number of Records function\n\n");
}

void databaseSize() {
    printf("\nYou have entered the Print Database Size function\n\n");
}

void printChanges(int selection, int *modifications) {
    if (selection == 1) {
        printf("\nYou have modified the database %d times so far", *modifications);
    }
    else if (selection == 2) {
        (*modifications)++;
        printf("\n%d modifications so far", *modifications);
    }
    else {
        printf("Invalid selection!");
    }
}

int main() {
    int looper = 6;
    int selection;
    int changesSelection;
    int modifications = 0;

    // Display the menu for the user to make their selection and to call correct methods for the user to be able to make changes or view the database.
    while (looper <= 6){

        printf("\n\nParts Inventory Manager\n\n");
        printf("1. Print All Records\n");
        printf("2. Add a Record\n");
        printf("3. Delete a Record\n");
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
            break;

            default:
                printf("\nInvalid option! Please select a valid command.");
                break;
        }
    }

    return 0;
}