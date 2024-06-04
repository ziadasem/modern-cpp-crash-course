#include <iostream>
int main(){
    //1.5 escape characters
    std::cout << "This is a word will be replaced"  <<"\r" <<"Hello there" << std::endl; 
    //Hello thereord will be replaced

    //1.6 errors
    std::cerr << "Errors" << std::endl; //unbuffered cerr

    return 0 ;
}