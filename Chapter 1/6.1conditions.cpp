#include <iostream>
int main(){
    if (int a = 5, b = 10 ; a > 10){
          std::cout << a<<"\n";
    }else if (b = 11 ; a < 10 ){ //visiable
        std::cout << b<<"\n"; //visiable
    }else {
        std::cout << a<<"\n"; //visiable
    }
}