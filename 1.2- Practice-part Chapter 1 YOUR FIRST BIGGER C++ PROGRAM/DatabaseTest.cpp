#include "Database.h"
using namespace Records;
int main()
{
    Database myDB;
    Employee& emp1 { myDB.addEmployee("Ziad", "Assem") };
    emp1.fire();
    Employee& emp2 { myDB.addEmployee("Ziad", "Muhammad") };
    emp2.setSalary(100'000);
    Employee& emp3 { myDB.addEmployee("Assem", "Ziad") };
    emp3.setSalary(10'000);
    emp3.promote();
    std::cout<<"All employees:\n==============";
    myDB.displayAll();
    std::cout<<"\nCurrent employees:\n==================";
    myDB.displayCurrent();
    std::cout<<"\nFormer employees:\n=================";
    myDB.displayPast();
}