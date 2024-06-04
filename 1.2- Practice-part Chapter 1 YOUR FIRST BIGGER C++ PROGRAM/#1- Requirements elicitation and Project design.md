## 1- Requirements elicitation and Project design

### Requirements elicitation
the first phase of creating a software project is gathering requirements from the stakeholders. The goal of requirements elicitation is to ensure that the software development process is based on a clear and comprehensive understanding of the customer’s needs and requirements. The output of this phase is some documents, the phases and documentation of designing a software project are out of the scope of this repo, to know more about Software Engineering, [Software Engineering by Ian Sommerville](https://www.amazon.com/Software-Engineering-10th-Ian-Sommerville/dp/0133943038) Book is recommended.

the required system is a program to manage a company’s employee records with the following feature set:
1. Add and fire employees
2. Promote and demote employees
3. View all employees, past and present
4. View all current employees
5. View all former employees

these are the main features, but after more meetings and interviews with the stakeholders to give more information about their employees, company policies, and salaries. new information is provided regarding the employees which are:
1. the default starting salary is 30,000 
2. the default raise and demerit amount is 1000 and varies according to the promotion/demotion
3. an employee is defined by 
    * first name
    * last name
    * employee number
    * salary
    * is hired

and for managing the employees, their number isn't defined (dynamic) and every employee will have a generated employee number, For inquiries for an employee you can use the employee number or employee name.

the requirements for the user interface are:
* a user interface is a menu-based user interface
* hire/fire employee
* promote/demote employee
* display employees

for creating this project with a GUI it is recommended to use [Qt framework](https://www.youtube.com/watch?v=cXojtB8vS2E), but it is out of the scope of the book.
### Classes Design
the project encapsulates many employees within a data structure, so we will define a class to handle a single employee and another class that manages the data structure that stores all the employees

every class should be split into two sections, the module interface file (`.cppm`) and the implementation file (`.cpp`)

#### 1- Employee Class
the first entity of the project is the employee, This class should maintain all the information about an employee. Its member functions provide a way to query and change that information. An Employee also knows how to display itself (e.g. on the console). Additionally, member functions exist to adjust the employee’s salary and employment status. Also within this entity, some constants should be defined such as `DefaultStartingSalary` and `DefaultRaiseAndDemeritAmount`.

below is a class diagram that shows the member variables and member functions their datatypes and the defined arguments. these properties are defined from the given requirements.

![Employee Class diagram](https://i.ibb.co/N9tnMhp/Employee.jpg)
this diagram shows that:

* the required member variables are:
    * m_firstName with the type of string
    * m_lastName with the type of string
    * m_employeeNumber with the type of int and initial value =-1
    * m_salary with the type of int and initial value = DefaultStartingSalary
    * m_hired with the type of boolean and initial value  = false

* the required member functions are:
    * promote (int raiseAmount with an initial value of DefaultStartingSalary) and returns void
    * demote (int demeritAmount with an initial value of DefaultStartingSalary) and returns void
    * hire which returns void
    * fire which returns void
    * display which returns void
    * the setters and getters

the implementation of this class is in `#2- The Employee Class.md` and its associated files

#### 2- Database Class
It is required to create a central repository of the data, where this entity manages the storing and retrieving of the data and defines the data structure. For more complex projects new entities should define the logic for the system, but no need for this entity in this project.

the central data repository entity is the Database class and here are the required functions and data members:
![class diagram of databases](https://i.ibb.co/gVGQ6kM/Employee.jpg)

* the required member variables are:
    * m_employees with the type of vector, since it is required to have a dynamic array
    * m_nextEmployeeNum with the type of int and initial value = firsEmployeeNum

* the required member functions are:
    * addEmployee
    * getEmployee by first name and last name
    * getEmployee by employee number
    * displayAll to display all the employees
    * displayCurrent display the hired employees
    * displayPast() which displays the past employees

the implementation of this class is in `#3- The Database Class.md` and its associated files
