#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

namespace Records {
    const int DefaultRaiseAndDemeritAmount{1'000};

    class Employee {
    public:
        Employee(const std::string& firstName,
                 const std::string& lastName
        );

        void promote(int raiseAmount = DefaultRaiseAndDemeritAmount);
        void demote(int demeritAmount = DefaultRaiseAndDemeritAmount);
        void hire();
        void fire();
        void display() const;

        void setFirstName(const std::string& firstName);
        // 前const 表示返回值不可修改 后const 表示函数不可修改成员变量
        const std::string& getFirstName() const;

        void setLastName(const std::string& lastName);
        const std::string& getLastName() const;

        void setEmployeeNumber(int employeeNumber);
        int getEmployeeNumber() const;

        void setSalary(int newSalary);
        int getSalary() const;

        bool isHired() const;

    private:
        std::string m_firstName;
        std::string m_lastName;
        int m_employeeNumber {-1};
        int m_salary;
        bool m_hired {false};
    };
}
#endif //EMPLOYEE_H
