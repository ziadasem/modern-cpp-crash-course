#include <iostream>
#include <stdexcept>


double divideNumbers(double numerator, double denominator)
{   
    if (denominator == 0){
        throw std::invalid_argument { "Division by zero is not allowed" } ;
    }
    return numerator / denominator;
}

int main(){
    try{
        std::cout << divideNumbers(10, 1) <<std::endl;
        std::cout << divideNumbers(10, 0) <<std::endl;

    }catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }

}

