#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include "employee.h"

namespace Records {

    class Database {
    public:
        Database();
        Employee& addEmployee(const std::string& firstName, const std::string& lastName);
        // 重载
        Employee& getEmployee(int employeeNumber);
        Employee& getEmployee(const std::string& firstName, const std::string& lastName);

        void displayAll() const;
        void displayCurrent() const;
        void displayFormer() const;

    private:
        std::vector<Employee> m_employees;
        int m_nextEmployeeNumber;
    };
}

#endif //DATABASE_H
