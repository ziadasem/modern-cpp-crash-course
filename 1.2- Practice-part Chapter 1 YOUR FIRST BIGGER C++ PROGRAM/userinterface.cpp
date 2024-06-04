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

//get from the user a employee number, assuming that the user will enter a number
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
      std::cerr<< "Unable to terminate employee: "<<exception.what()<<std::endl;
    }
}
//takes an employee number and the required raise amount
//updates an employee salary in the database
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