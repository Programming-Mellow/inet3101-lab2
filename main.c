// Lab 2
// Created by Wendy Vang & Venice Fan

// wendy -> create own realloc() function for extra credit. NO linked list!

//venice -> create struct for part (number, name, size, size metric, cost)

//ideas for the methods:
//printrecords -> we can assume that all structs are the same size. if so, then we can jump the pointer a certain amount of bytes to the next struct if we are unable to utilize an array or linked list.. let me look more into this. (wendy will work on this)
//add -> create a struct and then prompt user to fill out the data. assign the associated parts to the correct parts of the struct. once added, update static variable of how many records in the database. use malloc() & pointers to ensure that the struct has life outside of the function. if no structs exist (aka number of records = 0) then assign beginning of database pointer to the newly created struct. if it isn't the first struct created, assign a "which record is this" pointer to it. (venice will work on this, ask questions if any pops up)
//printsizeofdatabase -> return sizeof(struct) * number of records (wendy will work on this)
//printnumberofrecords -> return static variable that keeps track of how many records exist in the database (venice will work on this)
//delete -> use the free() on the pointer that keeps track of which record is this (aka the last struct created). (this is up for dibs)


//struct 
struct Part {
    int number;
    char name[50];
    float size;
    char metric[10];
    float cost;
};

static int recordCount = 0;

//ptr to struct Part
struct Part *database = 0;

void printRecords(){
    printf("\nYou have entered the Print All Records function\n\n");
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
    struct Part *newDatabase = malloc(recordCount * sizeof(struct Part));

    for (int i = 0; i < recordCount - 1; i++) {
        newDatabase[i] = database[i];
    }

    //insert newPart into the end of the new database
    newDatabase[recordCount - 1] = newPart;

    free(database);

    database = newDatabase;

}

void deleteRecord() {
    printf("\nYou have entered the Delete Last Record function\n\n");

    if (recordCount == 0) {
        printf("There are no records in the database.\n");
    }

    recordCount--;

    if (recordCount == 0) {
        free(database);
        database = 0;
    }
}

int numberOfRecords() {
    return recordCount;
}

int databaseSize() {
    return sizeof(struct Part) * recordCount;
}

int main() {
    int looper = 6;
    int selection;
    int changesSelection;
    int modifications = 0;

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
            free(database);
            break;

            default:
                printf("\nInvalid option! Please select a valid command.");
                break;
        }
    }

    return 0;
}