#include <iostream>
#include <tuple>
#include <fstream>
#include <map>
#include "Employee.hpp"

std::map<std::string, Employee *> readData(const std::string file_name)
{
    std::fstream FILE;
    FILE.open(file_name, std::ios::in);
    std::map<std::string, Employee *> MyEmployees;
    std::string S;
    while (getline(FILE, S))
    {
        std::stringstream X(S);
        std::string item;
        getline(X, item, ',');
        std::string id = item;
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

void StoreData(std::map<std::string, Employee *> Employees, const std::string file_name)
{
    std::ofstream FILE;
    FILE.open(file_name, std::ios::binary | std::ios::app);
    int Size = Employees.size();
    FILE.write((char*)&Size, 4);
    for (auto [ID, EMP] : Employees)
    { 
        std::string emp = EMP->GetEmployee();
        FILE.write((char *)&emp, sizeof(emp));
    }
    FILE.close();
}

void readDataAsBinary(const std::string file_name)
{
    std::ifstream File;
    File.open(file_name, std::ios::in | std::ios::binary);
    std::map<std::string, Employee *> MyEmployees;
    Employee* obj;
    if (!File)
    {
        std::cout << "Cannot open file!" << std::endl;
        return;
    }
    int Size;
    File.read((char*)&Size, 4);
    std::cout << Size << std::endl;
    std::string emp;
    File >> emp;
    std::cout << emp << std::endl;
    File.close();
}

int main()
{
    // auto Employees = readData("data.txt");
    // StoreData(Employees, "checking.dat");
    readDataAsBinary("checking.dat");
    // for(auto [ID, Employee]: Employees){
    //     std::cout << Employee;
    // }
}