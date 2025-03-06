int main() {
    int looper = 6;
    int selection;
    int changesSelection;
    int modifications = 0;

    // Display the menu for the user to make their selection and to call correct methods for the user to be able to make changes or view the database.
    while (looper <= 6){
        //test
        printf("\n\nParts Inventory Manager\n\n");
        printf("1. Print All Records\n");
        printf("2. Add a Record\n");
        printf("3. Delete a Record\n");
        printf("4. Print Number of Records\n");
        printf("5. Print Database Size\n");
        printf("6. Print Number of Changes\n");
        printf("7. Exit\n\n");

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
                printf("\nYou have selected the 'Print Number of Changes' function, would you like to:\n1. Print out the number of changes to the database (Type '1')\n2. Increment the changes to the database by 1 (Type '2')\n\n");
                scanf("%d", &changesSelection);
                printChanges(changesSelection, &modifications);
                break;

            case 7:
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