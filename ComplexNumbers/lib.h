#include <iostream>
#include <stdexcept>

class Complex{
    private:
    float real_part;
    float imaginary_part;

    public:
    Complex(float a, float b){
        this->real_part = a;
        this->imaginary_part = b;
    }
    void setReal(float real){
        this->real_part = real;
    }
    void setImaginary(float imaginary){
        this->imaginary_part = imaginary;
    }
    Complex getMultInverse(){
        float Denom = (this->real_part * this->real_part) + (this->imaginary_part*this->imaginary_part);
        float NewReal = this->real_part / Denom;
        float NewImaginary = (-1*this->imaginary_part) / Denom;
        Complex res(NewReal, NewImaginary);
        return res;
    }
    Complex operator + (Complex const &obj) {
        Complex res(this->real_part + obj.real_part, this->imaginary_part + obj.imaginary_part);
        return res;
    }
    Complex operator - (Complex const &obj) {
        Complex res(this->real_part - obj.real_part, this->imaginary_part - obj.imaginary_part);
        return res;
    }
    Complex operator * (Complex const &obj) {
        float NewReal = this->real_part*obj.real_part - this->imaginary_part*obj.imaginary_part;
        float NewImaginary = this->real_part*obj.imaginary_part + this->imaginary_part*obj.real_part;
        Complex res(NewReal, NewImaginary);
        return res;
    }
    Complex operator / (Complex const &obj) {
        float Denom = (obj.real_part * obj.real_part) + (obj.imaginary_part * obj.imaginary_part);
        float NewReal = (this->real_part*obj.real_part + this->imaginary_part*obj.imaginary_part) / Denom;
        float NewImaginary = (this->imaginary_part*obj.real_part - this->real_part*obj.imaginary_part) / Denom;
        Complex res(NewReal, NewImaginary);
        return res;
    }
    auto operator [] (int i) {
        if(i == 0) return this->real_part;
        else if(i == 1) return this->imaginary_part;
        else throw std::invalid_argument("For Real Part Argument must be 0 or for imaginary part it's must be 1");
    }

    std::string GetInfo(){
        return "(" + std::to_string(this->real_part) + ", " + std::to_string(this->imaginary_part) + "i)";
    }
};

std::ostream& operator<<(std::ostream& stream, Complex &obj){
    stream << "(" << std::to_string(obj[0]) << ", " << std::to_string(obj[1]) << "i)";
    return stream;
}
