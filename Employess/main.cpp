#include "EmployeeService.hpp"

int main()
{
    auto Employees = EmployeeService::readData("Data.dat");
    std::cout << "Press Enter: ";
    int x;
    std::cin >> x;
}