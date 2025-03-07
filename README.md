# INET3101 Lab 2

## Code for INET3101 Lab 2

**Who wrote the program (ensure all members are listed in the doc):**

Wendy Vang (5859671) and Venice Fan (5895808)

**Program description paragraph:**

The program acts as a basic database system where users can interact through a menu within the terminal. Users can interact with the menu by printing all records, adding a record, deleting the last record, printing the number of records and/ or printing the size of the database. The program can also be finished when the user decides they want to exit the program.

**Menu definition and usage:**

The menu function is used to display to the users, within the terminal, the following text:
1. Print all records
2. Add a record
3. Delete the last record
4. Print the number of records
5. Print database size
6. Exit

The users can then select one of the following numbers to run certain tasks. Once the 6 is pressed, the menu exits

**Each function defined with:**

1. printAllRecords()
- Input type(s) (if any):
None
- Output type:
Prints all of the records created in the program.
- Algorithm description:
Utilizes pointer arithmetic to jump from one database to another, once the pointer lands on a valid entry, print out the associated parts of the struct.

2. addRecord()
- Input type(s) (if any):
User inputs (integers, string and float values)
- Output type:
Prints out the information is the user inputs.
- Algorithm description:
Tells the user to input the part number, part name, part size, part size metric and part cost.Scanner is used to read the user's inputs. Displays in terminal the user's entered values. The code allocates memory dymanically for new database in order to store the new record. Then copies the existing reccords into the new allocated space. The new record is inserted into the end of the database. The database pionter is then freed of old memory space.

3. deleteRecord()
- Input type(s) (if any):
None
- Output type:
Prints the message: “You have entered the Delete Last Record function.” Also prints the updated number of records in the database.
- Algorithm description: 
The code prints a message that indicates that the function was called. recordCount is decremented to reflect the last removed record. Realloc is used to resize the database dynamically. The existing records, not including the removed one, gets copied into newly allocated memory. The updated database pointer is used to reflect new size. Also prints the number of existing records.

4. numberOfRecords()
- Input type(s) (if any):
None
- Output type: 
Returns the total number of records that is stored within the database.
- Algorithm description: 
The function returns the value of recordCount.

5. databaseSize()
- Input type(s) (if any):
None
- Output type: “You have entered the Print database size function”
Prints the message:
- Algorithm description: 
Prints out the size of the entries currently in the database by calculating the size of the struct and multiplying it by the amount of records in the database.

6. main()
- Input type(s) (if any):
User selection (integer)
- Output type:
Depending on the integer the user types, a certain function will be called.
- Algorithm description:
Displays a menu in the terminal in a while loop. Reads user input and calls the corresponding function using a case/switch statement. If user inserts invalid input, a error message will appear and prompts the user to make a new selection. Then exits when the user inputs 6.

**Listing of files required and what type they are (.h header, .c c code, etc..):**

main.c -> .c code
#include <stdlib.h> -> .h header
#include <stdio.h> -> .h header