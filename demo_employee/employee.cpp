#include "employee.h"
#include <iostream>
#include <format>
using namespace std;

// 匿名命名空间 防止暴露给其他文件
namespace {
    const int DefaultStartingSalary{30'000};
}

namespace Records {
    Employee::Employee(const string& firstName, const string& lastName)
        // m_salary 技巧 默认值不想暴露给外部时在定义文件设置匿名命名空间并赋值 可以暴露的在头文件声明时直接初始化
        : m_firstName(firstName), m_lastName(lastName), m_salary(DefaultStartingSalary) {
    }

    void Employee::promote(int raiseAmount) {
        setSalary(getSalary() + raiseAmount);
    }

    void Employee::demote(int demeritAmount) {
        setSalary(getSalary() - demeritAmount);
    }

    void Employee::hire() {
        m_hired = true;
    }

    void Employee::fire() {
        m_hired = false;
    }

    void Employee::display() const {
        cout << format("Employee: {}, {}", getLastName(), getFirstName()) << endl;
        cout << "-------------------------" << endl;
        cout << (isHired() ? "Current Employee" : "Former Employee") << endl;
        cout << format("Employee Number: {}", getEmployeeNumber()) << endl;
        cout << format("Salary: ${}", getSalary()) << endl;
        cout << endl;
    }

    void Employee::setFirstName(const string& firstName) {
        m_firstName = firstName;
    }

    const string& Employee::getFirstName() const {
        return m_firstName;
    }

    void Employee::setLastName(const string& lastName) {
        m_lastName = lastName;
    }

    const string& Employee::getLastName() const {
        return m_lastName;
    }

    void Employee::setEmployeeNumber(int employeeNumber) {
        m_employeeNumber = employeeNumber;
    }

    int Employee::getEmployeeNumber() const {
        return m_employeeNumber;
    }

    void Employee::setSalary(int newSalary) {
        m_salary = newSalary;
    }
    int Employee::getSalary() const {
        return m_salary;
    }
    bool Employee::isHired() const {
        return m_hired;
    }
}
