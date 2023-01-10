#include<iostream>

class Snake{
    private:
    int x = 0;
    int y = 0;
    int Size = 0;
    public:
    void setX(int x){
        this->x = x;
    }
    void setY(int y){
        this->y = y;
    }
    void setSize(int Size){
        this->Size = Size;
    }
    Snake(int x, int y, int Size){
        this->x = x;
        this->y = y;
        this->Size = Size;
    }
    int operator [] (int i){
        if(i == 0) return this->x;
        else if(i == 1) return this->y;
        else if(i == 2) return this->Size;
        return -1;
    }
};

std::ostream& operator << (std::ostream& stream, Snake &obj){
    stream << "(" << std::to_string(obj[0]) << ", ";
    stream << std::to_string(obj[1]) << ", ";
    stream << std::to_string(obj[2]) << ")";
    return stream;
}