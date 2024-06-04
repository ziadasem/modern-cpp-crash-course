#include "Employee.h"

namespace Records {
Employee::Employee(const std::string& firstName, const std::string& lastName) 
: //initialize members 
m_firstName {firstName}, m_lastName {lastName} 
// implementation of constructor
{

}

void Employee::promote(int raiseAmount){
    setSalary(getSalary() + raiseAmount);
}

void Employee::demote(int raiseAmount){
    int newSalary = getSalary() - raiseAmount ;
    setSalary(newSalary <= 0 ? 0 : getSalary() - raiseAmount);
}

void Employee::hire() { m_hired = true; }
void Employee::fire() { m_hired = false; }

void Employee::display() const {
    std::cout << m_firstName << " " << m_lastName << std::endl;
    std::cout<<getEmployeeNumber() << std::endl;
    std::cout << "Salary: " << getSalary() << std::endl;
    std::cout << "Hired: " << (m_hired? "Current Employee" : "Not a current Employee") << std::endl;
}

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

};