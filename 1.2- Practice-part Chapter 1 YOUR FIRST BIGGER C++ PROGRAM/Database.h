#include <iostream>
#include <vector>
#include "Employee.h"



namespace Records {
    const int firsEmployeeNum {100};
    class Database {
        public:
            Employee& addEmployee(const std::string firstName, const std::string lastName);
            Employee& getEmployee(const std::string& firstName, const std::string& lastName);
            Employee& getEmployee(int employeeNumber);

            void displayAll() const;
            void displayCurrent() const;
            void displayPast() const;
        
        private:
            std::vector<Employee> m_employees ;
            int m_nextEmployeeNum {firsEmployeeNum};
    };
}