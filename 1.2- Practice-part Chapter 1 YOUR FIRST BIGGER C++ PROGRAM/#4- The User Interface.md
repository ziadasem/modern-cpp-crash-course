## 4- The User Interface Class

> the complete code in `userinterface.cpp`.

The final part of the program is a menu-based user interface that makes it easy for users to work with the employee database. for simplicity, we will design it through CLI/Terminal instead of GUI, to use GUI use the [Qt framework](https://www.youtube.com/watch?v=cXojtB8vS2E). In designing the logic user interface it is assumed that the user will not provide any wrong inputs (e.g. he will not type a letter when he asks for a number), It is important to identify the weakness points of the system and this assumption is one of them.

this module is divided into functions for reusability and to be easily debugged.

we will instantiate one Database object that handles all the employee's data and pass this object to the functions that manipulate it.

### displayMenu
the first component of UI is displaying the menu, we will print to the user the available options with their numbers read from the input number and return it to the caller function.

first include the required files.
```cpp
#include "Database.h"
```

define the function and declare its prototype
```cpp
#include "Database.h"

int displayMenu();
//print to the console the available options
//returns the selected option
int displayMenu()
{
    int selection;
    std::cout<<"Employee Database\n";
    std::cout<<"-----------------\n";
    std::cout<<("1) Hire a new employee\n");
    std::cout<<("2) Fire an employee\n");
    std::cout<<("3) Promote an employee\n");
    std::cout<<("4) List all employees\n");
    std::cout<<("5) List all current employees\n");
    std::cout<<("6) List all former employees\n");
    std::cout<<("0) Quit\n");
    std::cout<<("---> \n");
    std::cin >> selection;
    return selection;
}
```

based on the selection, an action will be triggered. To handle this a switch case will be used. the display menu will keep displaying until the user exits the application, hence we will put the switch case inside an infinite while loop

```cpp
int main()
{
    bool done { false };
    while (!done) {
        int selection { displayMenu() };
        switch (selection) {
        case 0: //exit
 done = true;
            break;
        case 1:
 //do hire
            break;
        case 2:
 // do fire
            break;
        case 3:
 // do promote
            break;
        case 4:
 // display all
            break;
        case 5:
 // display current employees
            break;
        case 6:
 // display past employees
            break;
        default:
            std::cerr<<"Unknown command.\n";
            break;
 }
 }
}
```

### Database class and display employees
the database class will be instantiated once in the main method before the while loop, and call display methods in their appropriate cases.
```cpp
int main()
{
    Records::Database employeeDB;
    bool done { false };
    while (!done) {
        int selection { displayMenu() };
        switch (selection) {
        case 0://exit
 done = true;
            break;
        case 1:
 //do hire
            break;
        case 2:
 //do fire
            break;
        case 3:
 //do promote
            break;
        case 4:
            employeeDB.displayAll();
            break;
        case 5:
            employeeDB.displayCurrent();
            break;
        case 6:
            employeeDB.displayPast();
            break;
        default:
            std::cerr<<"Unknown command.\n";
            break;
 }
 }
}
```
### Register a new employee and hire him
The Hire new employee option creates a new employee and hires him, this is implemented in `doHire()` function that gets the new employee’s name from the user and tells the database to add the employee:

```cpp
int displayMenu();
void doHire(Records::Database& db);

//take from the user the first and last name of the employee
// add a new employee to the database
void doHire(Records::Database& db)
{
std::string firstName;
std::string lastName;
std::cout<<("First name? ");
std::cin >> firstName;
std::cout<<("Last name? ");
std::cin >> lastName;
auto& employee { db.addEmployee(firstName, lastName) };
std::cout<<"Hired employee "<<firstName <<" "<<lastName<<" with employee number "<<employee.getEmployeeNumber()<<". \n";
}

```

### Fire an employee
to fire an employee, the system will search for an employee by employee number and set isHired to `false`, searching for an employee may throw an exception as we defined in the function, so it should be surrounded by a try-catch block.

```cpp
int displayMenu();
void doHire(Records::Database& db);
void doFire(Records::Database& db);

//get from the user an employee number, assuming that the user will enter a number
//set isHired tp false to an employee in Database 
void doFire(Records::Database& db)
{
    int employeeNumber;
    std::cout<<("Employee number? \n");
    std::cin >> employeeNumber;
    try {
    auto& emp { db.getEmployee(employeeNumber) };
    emp.fire();
    std::cout<<"Employee "<<employeeNumber<<" terminated.\n";
 } catch (const std::logic_error& exception) {
      std::cerr<< "Unable to terminate an employee: "<<exception.what()<<std::endl;
 }
}
```

### Promote an employee

promote an employee to increase his salary by the value given by the user. also, it should be surrounded by the try-catch block.
```cpp
void doPromote(Records::Database& db);

//takes an employee number and the required raise amount
//updates an employee's salary in the database
void doPromote(Records::Database& db)
{
    int employeeNumber;
    std::cout<<"Employee number? \n";
    std::cin >> employeeNumber;
    int raiseAmount;
    std::cout<<"How much of a raise? \n";
    std::cin >> raiseAmount;
    try {
        auto& emp { db.getEmployee(employeeNumber) };
        emp.promote(raiseAmount);
 } catch (const std::logic_error& exception) {
        std::cerr<<"Unable to promote employee: "<< exception.what() << std::endl;
 }
}
```

the complete main function:

```cpp
#include "Database.h"
int displayMenu();
void doHire(Records::Database& db);
void doFire(Records::Database& db);

void doPromote(Records::Database& db);

int main()
{
    Records::Database employeeDB;
    bool done { false };
    while (!done) {
        int selection { displayMenu() };
        switch (selection) {
        case 0://exit
 done = true;
            break;
        case 1:
            doHire(employeeDB);
            break;
        case 2:
            doFire(employeeDB);
            break;
        case 3:
            doPromote(employeeDB);
            break;
        case 4:
            employeeDB.displayAll();
            break;
        case 5:
            employeeDB.displayCurrent();
            break;
        case 6:
            employeeDB.displayPast();
            break;
        default:
            std::cerr<<"Unknown command.\n";
            break;
 }
 }
}
```