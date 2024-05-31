#include <iostream>

//not recommended to create a function that performs two operations
void sumanddiff(int a, int b, int& sum, int& diff){
    sum = a+b ;
    diff = a-b ;
}


int main(){
    int a = 10, b = 5, sum, diff;
    sumanddiff(a, b, sum, diff);
    std::cout << "Sum: " << sum << "\n"; //15
     std::cout << "Difference: " << diff<< "\n"; //5
    return 0;
}