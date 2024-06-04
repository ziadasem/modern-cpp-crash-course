## 2- The Employee Class

> the complete code in `Employee.h`, `Employee.cpp`, and `EmployeeTest.cpp`.

as designed in the Design phase, it is required to implement the following class diagram (see `#1- Requirements elicitation and Project design.md` ) to understand the following class diagram:

![Employee Class diagram](https://i.ibb.co/N9tnMhp/Employee.jpg)


### The Employee.h file
The first file is the Employee.h header file which defines the Employee class. 

the first lines include the iostream and define the `Records` namespace which is the namespace that is used throughout this program for application-specific code.

within this namespace, we will define the constants that are used by the Employee class

```cpp
#include <iostream>

namespace Records {
    const int DefaultStartingSalary { 30'000 };
    const int DefaultRaiseAndDemeritAmount { 1'000 };
};
```

next, we will define the class and declare the required functions in addition to setters and getters under the public section (make it accessible by the project), the required functions are stated in the class diagram:

```cpp
    class Employee {
        public:
            Employee(const std::string& firstName,const std::string& lastName);
            void promote(int raiseAmount = DefaultRaiseAndDemeritAmount);
            void demote(int demeritAmount = DefaultRaiseAndDemeritAmount);
            void hire(); // Hires or rehires the employee
            void fire(); // Dismisses the employee
            void display() const; // Prints employee info to console

 // Getters and setters
            void setFirstName(const std::string& firstName);
            const std::string& getFirstName() const;
            void setLastName(const std::string& lastName);
            const std::string& getLastName() const;
            void setEmployeeNumber(int employeeNumber);
            int getEmployeeNumber() const;
            void setSalary(int newSalary);
            int getSalary() const;
            bool isHired() const;
 };
```

some functions shouldn't update object variables inside it (i.e. consider the member variables as constant variables), so we will add the `const` keyword at the end of the function prototype such as `int getSalary() const;`

A constructor is provided that accepts a first and last name. The promote() and demote() member functions both have integer parameters that have a default value equal to DefaultRaiseAndDemeritAmount `(int raiseAmount = DefaultRaiseAndDemeritAmount)`. In this way, other codes are free to not use the parameter, and the default value will automatically be used. Member functions to hire and fire an employee are provided, together with a member function to display information about an employee. 

Several setters and getters provide functionality to change the information or to query the current information of an employee.

**Define data members**
for defining the data members, it is recommended to define them under the private section, to be not accessed directly by other code, this has many advantages including that a developer can change the representation of the data members without affecting the client code that uses this class since they will use the setter/getters functions only.

```cpp
private:
    std::string m_firstName;
    std::string m_lastName;
    int m_employeeNumber { -1 };
    int m_salary { DefaultStartingSalary };
    bool m_hired { false };
```

the complete code is available in `Employee.h`

### The Employee.cpp implementation file
in this file, the header file is included and implemented, in the first line is the inclusion of the header file, the definition of the `Records` namespace.

```cpp
#include "Employee.h"
namespace Records {

};
```

to implement a function outside a class you should use the scope operator `::`, as the following definition of the constructor
```cpp
#include "Employee.h"

namespace Records {
Employee::Employee(const std::string& firstName, const std::string& lastName) 
: //initialize members 
m_firstName {firstName}, m_lastName {lastName} 
// implementation of the constructor
{

}

};
```

The `promote()` and `demote()` member functions increase and decrease the salary of the employee, hence it will simply call `setSalary()` with a new value. The default values for the integer parameters are not repeated here; they are allowed only in a function declaration, not in a definition.

for `promote()` :
```
return_type scope :: function () {}
```
```cpp
void Employee::promote(int raiseAmount){}
```

the complete implementation:

```cpp
void Employee::promote(int raiseAmount){
    setSalary(getSalary() + raiseAmount);
}

void Employee::demote(int raiseAmount){
    int newSalary = getSalary() - raiseAmount ;
    setSalary(newSalary <= 0 ? 0 : getSalary() - raiseAmount);
}
```
Notice that for getting the current salary, the getter is used.

for The hire() and fire() member functions just set the m_hired data member appropriately:
```cpp
void Employee::hire() { m_hired = true; }
void Employee::fire() { m_hired = false; }
```

The `display()` member function uses cout to display information about the current employee.
Because this code is part of the Employee class, it could access data members, such as m_salary, directly instead of using getters, such as getSalary(). but, it is considered a good style to make use of getters and setters when they exist, even from within the class.

```cpp
void Employee::display() const {
    std::cout << m_firstName << " " << m_lastName << std::endl;
    std::cout<<getEmployeeNumber() << std::endl;
    std::cout << "Salary: " << getSalary() << std::endl;
    std::cout << "Hired: " << (m_hired? "Current Employee": "Not a current Employee") << std::endl;
}
```
Note: the function is marked as const which prevents any write operation for class data member in it, to edit class data member within this const function use `static_const` explained in Chapter 1

finally generating the setters and getters which is a boring task, that can be automated via tools or even AI tools. 

```cpp
void Employee::setFirstName(const std::string& firstName) {
 m_firstName = firstName;
}

void Employee::setLastName(const std::string& lastName) {
 m_lastName = lastName;
}

void Employee::setEmployeeNumber(int number) {
 m_employeeNumber = number;
}

void Employee::setSalary(int salary) {
 m_salary = salary;
}

// Getters definitions
const std::string& Employee::getFirstName() const {
    return m_firstName;
}

const std::string& Employee::getLastName() const {
    return m_lastName;
}

int Employee::getEmployeeNumber() const {
    return m_employeeNumber;
}

int Employee::getSalary() const {
    return m_salary;
}

bool Employee::isHired() const {
    return m_hired;
}

```

Even though these member functions seem trivial, it’s better to have trivial getters and setters than to make your data members public. For example, in the future, you may want to perform bounds checking in the setSalary() member function. Getters and setters also make debugging easier because you can insert a breakpoint in them to inspect values when they are retrieved or set. Another reason is that when you decide to change how you are storing the data in your class, you only need to modify these getters and setters, while other code using your class can remain untouched.

### EmployeeTest.cpp

As you write individual classes, it is often useful to test them in isolation. the EmployeeTest.cpp file includes a `main()` function that performs some simple operations using the Employee class. Once you are confident that the Employee class works, you should remove or comment out this file so that you don’t attempt to compile your code with multiple main() functions. the professional method for testing a class is called unit testing, it is a much better way to test individual classes which is discussed in Chapter 30 of the book, Unit tests are small pieces of code to test specific functionality that remains in the code base. All unit tests are frequently executed; for example, they can automatically be executed by your build system. The benefit of doing this is that if you make some changes to existing functionality, the unit tests will instantly warn you if you break something.


```cpp

int main(){
    Records::Employee e1 = Records::Employee("Ziad", "Assem");
    e1.setFirstName("Zeyad");
    e1.setLastName("Asem");
    e1.display();

    e1.setSalary(10000);
    e1.promote();
    e1.display();

    e1.demote();
    e1.display();

    e1.setEmployeeNumber(189);
    e1.hire();
    e1.display();
    return 0;
}
```