#include <iostream>

namespace n2 { 
    void fun1(){
        std::cout << "n2::fun1\n";
    }
    namespace n2_sub{
    void fun(){
        std::cout << "n2_sub::fun1\n";
        fun1(); //sub from n2
    }
    namespace n2_sub_sub
    {
        void funct(){
            std::cout << "n2::n2_sub::fun1\n";
            fun(); //sub from n2
        }
    } 
    

}
}
namespace n2SubSub = n2::n2_sub::n2_sub_sub;

int main(){
    n2SubSub::funct();
    return 0;
}

