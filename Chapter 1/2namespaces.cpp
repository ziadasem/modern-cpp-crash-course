#include <iostream>
namespace realoperaton{
    int add(int a, int b){
        return a+b;
    }
}

namespace imaginaryoperaton{
    
}

namespace imaginaryoperaton{
    //will be discussed later
    struct complexNum{
        int a;
        int b ;
    };
    complexNum add(complexNum z1, complexNum z2){
        complexNum z ;
        z.a = z1.a + z2.a;
        z.b =  z1.b + z2.b;
        return z;
    }
}

int main(){
    std::cout<<realoperaton::add(2,3)<<"\n";
    imaginaryoperaton::complexNum z1,z2;
    z1.a = 2;
    z1.b = 3;
    z2.a = 4;
    z2.b = 5;
    imaginaryoperaton::complexNum z = imaginaryoperaton::add(z1,z2);
    std::cout<<z.a<<"+" << z.b<< "i\n";
    return 0;
}