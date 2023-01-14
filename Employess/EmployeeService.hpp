#include <fstream>
#include <map>
#include "Employee.hpp"
class EmployeeService
{
    public:
    static std::map<std::string, Employee *> readData(const std::string file_name)
    {
        std::fstream FILE;
        FILE.open(file_name, std::ios::in);
        std::map<std::string, Employee *> MyEmployees;
        std::string S;
        while (getline(FILE, S))
        {
            std::stringstream X(S);
            std::string item;
            std::string id = item;
            getline(X, item, ',');
            getline(X, item, ',');
            std::string Name = item;
            getline(X, item, ',');
            int age = stoi(item);
            getline(X, item, ',');
            float Salary = stof(item);
            MyEmployees.insert({id, new Employee(Name, id, Salary, age)});
        }
        FILE.close();
        return MyEmployees;
    }

    static void StoreData(std::map<std::string, Employee *> Employees, const std::string file_name)
    {
        std::ofstream FILE;
        FILE.open(file_name, std::ios::binary | std::ios::trunc);
        for (auto [id, EMP] : Employees) FILE << EMP->GetEmployee() << std::endl;
        FILE.close();
    }
};