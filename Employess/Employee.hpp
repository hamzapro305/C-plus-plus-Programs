#include <iostream>
#include <sstream>

class Employee
{
private:
    std::string Name;
    float Salary;
    int Age;
    std::string Id;

public:
    Employee() {}
    Employee(std::string Name, std::string Id, float Salary, int Age) {
        this->Name = Name;
        this->Salary = Salary;
        this->Age = Age;
        this->Id = Id;
    }
    Employee(const Employee& EMP) {
        this->Name = EMP.Name;
        this->Salary = EMP.Salary;
        this->Age = EMP.Age;
        this->Id = EMP.Id;
    }
    std::string getName() const { return Name; }
    float getSalary() const { return Salary; }
    int getAge() const { return Age; }
    std::string getId() const { return Id; }

    void setName(std::string Name) { this->Name = Name; }
    void setSalary(float Salary) { this->Salary = Salary; }
    void setAge(int Age) { this->Age = Age; }
    void setId(std::string Id) { this->Id = Id; }
    void CopyEmployee(Employee *EMP) {
        this->Name = EMP->Name;
        this->Salary = EMP->Salary;
        this->Age = EMP->Age;
    }
    std::string GetEmployee()
    {
        std::stringstream ss;
        ss << this->getId() << "," << this->getName() << "," << this->getAge() << "," << this->getSalary();
        return ss.str();
    }
};

std::ostream& operator << (std::ostream& ss, const Employee &obj){
        ss << "Name: " << std::left;
        if (obj.getName().length() > 20){
            ss.width(16);
            ss << obj.getName().substr(0, 16);
            ss.width(4);
            ss << std::left << "...   ";
        }
        else{
            ss.width(20);
            ss << obj.getName() << "  ";
        }
        ss << "ID: " << std::left;
        ss.width(5);
        ss << obj.getId() << "  ";
        ss << "Age: " << std::left;
        ss.width(4);
        ss << obj.getAge() << "  ";
        ss << "Salary: " << std::left;
        ss.width(40);
        ss << obj.getSalary() << std::endl;
        return ss;
}