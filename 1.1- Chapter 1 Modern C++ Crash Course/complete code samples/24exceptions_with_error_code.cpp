#include <iostream>

enum class ErrorCodes {
    NoError = 0,
    DivisionByZero = -1,
    InvalidInput = -2,
};

void handleError(ErrorCodes& error, double value);



double divideNumbers(double numerator, double denominator, ErrorCodes& error)
{   
    if (denominator == 0){
        error = ErrorCodes::DivisionByZero;
        return 0 ;
    }
    return numerator / denominator;
}

int main(){
    ErrorCodes error = ErrorCodes::NoError;
    double value ;
    value =  divideNumbers(10, 1, error) ;
    handleError(error, value);
        
    divideNumbers(10, 0, error);
    handleError(error, value);

}

void handleError(ErrorCodes& error, double value){
    switch(error){
            case ErrorCodes::DivisionByZero:
                std::cout<<"Division by zero is not allowed"<<std::endl;
                error = ErrorCodes::NoError;
                break;
            case ErrorCodes::InvalidInput:
                std::cout<<"Invalid input"<<std::endl;
                error = ErrorCodes::NoError;
                break;
            case ErrorCodes::NoError:
                std::cout<<value<<std::endl;
                break;
        }
}