#include <iostream>
namespace n1{
    void fun1(){
       std::cout<<"n1::fun1\n";
    }

    void fun2(){
       std::cout<<"n1::fun2\n";
    }
}

namespace n2{
    void fun1(){
       std::cout<<"n2::fun1\n";
    }

    void fun2(){
       std::cout<<"n2::fun2\n";
    }
}

using namespace n1 ;

int main(){
    fun1(); //default to n1 n1::fun1
    fun2(); //n1::fun2
    return 0;
}



