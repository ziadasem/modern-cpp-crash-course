## 3- The Database Class

> the complete code in `Database.h`, `Database.cpp`, and `DatabaseTest.cpp`.

as designed in the Design phase, it is required to implement the following class diagram (see `#1- Requirements elicitation and Project design.md` ) to understand the following class diagram:

![class diagram of databases](https://i.ibb.co/gVGQ6kM/Employee.jpg)


### The Database.h file

the first lines include the iostream, `vectors`, and `Employee` that will be used in this class then define the `Records` namespace which is the namespace that is used throughout this program for application-specific code.

within this namespace, we will define the constants that are used by the Database class, since it is the responsibility of the Database class to give every employee a unique number, a starting employee number should be defined as a constant

```cpp
#include <iostream>
#include <vector>
#include "Employee.h"

namespace Records {
    const int FirstEmployeeNumber { 1'000 };
};
```

next, we will define the class and declare the required functions in addition to setters and getters under the public section (make it accessible by the project), the required functions are stated in the class diagram:

```cpp
    class Employee {
         public:
            Employee& addEmployee(const std::string firstName, const std::string lastName);
            Employee& getEmployee(const std::string& firstName, const std::string& lastName);
            Employee& getEmployee(int employeeNumber);

            void displayAll() const;
            void displayCurrent() const;
            void displayPast() const;
 };
```

some functions shouldn't update object variables inside it (i.e. consider the member variables as constant variables), so we will add the `const` keyword at the end of the function prototype such as `void displayAll() const;`

as required the database provides an easy way to add a new employee by providing a first and last name. For convenience, this member function returns a reference to the new employee. according to the requirements, there are two overloads of the `getEmployee()` member function. One allows retrieval by employee number. The other requires a first and last name.

Because the database is the central repository for all employee records, it has the following member functions to display all employees, the employees who are currently hired, and the employees who are no longer hired.

the private data members, `std::vector` is used to implement the dynamic memory, using `std::vector<Employee> m_employees;` and passing the `Employee` class between the `<>` to indicate that this array is an array of `Employee`.
defining m_employees under the private section has many advantages including is flexibility to change the data structure of m_employees without affecting the classes that use the database, or to abstract the complexity of dealing with vectors from the developers who will use this class by providing setters and getters.

the next employee number should be stored in the private section to protect it from external misuse or unexpected modifications.

```cpp
private:
std::vector<Employee> m_employees;
int m_nextEmployeeNumber { FirstEmployeeNumber };
```

the complete code is available in `Database.h`

### The Database.cpp implementation file
in this file, the header file is included and implemented. In the first line is the inclusion of the header file, the definition of the `Records` namespace.

```cpp
#include "Database.h"
namespace Records {

};
```

the first function is `addEmployee`, to add a new employee a new employee object is instantiated with a given first name and last name.
```cpp
 Employee e {firstName, lastName};
```
then it will be assigned with a new employee number  and incrementally this variable for the next employee
```cpp
e.setEmployeeNumber(m_nextEmployeeNum++);
```
make this employee active/hired
```cpp
e.hire();
```

then add this object to the vector, to add an object to a vector use the `.push_back( )` method and pass the object to it

```cpp
m_employees.push_back(e);
```

for convenience we should return a reference to the inserted object, we can't pass the created object within the function, since this object will be destroyed after the function call, instead, we will return a reference to the last element in the vector (the newly added element)

```cpp
return m_employees.back(); 
```

here is the complete implementation of the function

```cpp
#include "Database.h"

namespace Records {

    Employee& Database::addEmployee(const std::string firstName, const std::string lastName){
 Employee e {firstName, lastName};
        e.setEmployeeNumber(m_nextEmployeeNum++);
        e.hire();
        m_employees.push_back(e);
        return m_employees.back(); 
 }
```
**Get Employee methods**
instead of returning a copy from the Employee object, the getEmployee method returns a reference to the employee in the vector, also to make any change of the returned object reflects on the vector. The requirements were to get the Employee by name or by number.

```cpp
Employee& Database::getEmployee(const std::string& firstName, const std::string& lastName) {}
```
then using ranged-loop with the `auto` keyword
```cpp
Employee& Database::getEmployee(const std::string& firstName, const std::string& lastName) {
        for (auto& employee : m_employees){
            if (employee.getFirstName() == firstName && employee.getLastName() == lastName){
                return employee;
 }
 }
        throw std::logic_error("Employee not found");
 }
```
Note: Use `auto&` to define an employee as a reference to the object in the vector not a copy of it. The same implementation is used for the overloaded method `getEmployee` that returns the employee based on the employee number.

```cpp
    Employee& Database::getEmployee(int employeeNumber) {
        for (auto& employee : m_employees){
            if (employee.getEmployeeNumber() == employeeNumber){
                return employee;
 }
 }
        throw std::logic_error("Employee not found");
 }
```

**Display methods**

Again using the range-based iterators with the `auto&` keyword.
```cpp
    void Database::displayAll() const{
        for (auto& employee : m_employees){
            employee.display();
 }
 }

    void Database::displayCurrent() const{
        for (auto& employee : m_employees){
            if (employee.isHired()){
                employee.display();
 }
 }
 }

    void Database::displayPast() const{
        for (auto& employee : m_employees){
            if (!employee.isHired()){
                employee.display();
 }
 }
 }
```

### DatabaseTest.cpp

finally, the tester file
```cpp
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
```