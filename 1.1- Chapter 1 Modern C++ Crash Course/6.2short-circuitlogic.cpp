#include <iostream>
bool a(int i){
    std::cout <<i << " a\n" ;
    return false ;
}

bool b(int i){
    std::cout << i << " b\n" ;
    return false;
}

int errorFunction(){
    std::cout<<"Error\n";

    return 1/0;
}

int main(){


    if (true || a(0) || b(1)) {
        //pass
    }

    if (  a(2) || true  || b(3)) {
         //pass
    }

    if ( !a(4) || errorFunction() ) {
        //the shortcircuit logic will save the program from executing the error function, but if the value of !a()
        // is changed, this will lead to a new problems may be undiscovered in the previous runs
        std::cout << "No Errors\n" ;
    }

    if ( a(5)  && b(6) && true) {
      
    }
}