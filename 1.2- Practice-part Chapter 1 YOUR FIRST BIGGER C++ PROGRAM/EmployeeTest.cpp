#include "Employee.cpp"

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