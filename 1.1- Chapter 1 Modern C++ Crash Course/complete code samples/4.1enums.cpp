#include <iostream>
enum class Directions {
    UP = 10,
    DOWN,
    LEFT,
    RIGHT
};

int main(){
    Directions d1 = Directions::UP ; 
    Directions d2 {Directions::DOWN};

    std::cout << d1 << std::endl;  //error, not an integer constant
    int d1Val = d1;  //error, not an integer constant

    d1 = d1 + 3; //can't perform arithmetic operations

    //to use the value of the enum 
    std::cout << static_cast<int>(d2) << std::endl;  //cast enum to int

    return 0;
}