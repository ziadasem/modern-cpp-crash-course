#include <iostream>
int main(){
    int x {10} ;
    switch (x)
    {
    case 10:
        std::cout << "case 10\n" ;
        [[fallthrough]];
    case 15:
         std::cout << "case 15\n" ;
         break ;
    case 20:
         std::cout << "case 20\n" ;
    
    default:
        break;
    }
}