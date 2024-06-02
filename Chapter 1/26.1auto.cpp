#include <iostream>
int main(){
    const int value {3};
    const int& valueRef {value};
    auto valueRefRef {valueRef};

    //valueRef = 5 ; //error since it is constant
    valueRefRef  = 10 ; //no errors

    std::cout<<value<<std::endl;
    std::cout<<valueRefRef<<std::endl;

    //2- using auto&

    int val{3};
    int& valRef {val};
    auto& valRefRef {valRef};

    valRefRef = 10;
    std::cout<<val<<std::endl;

    //3- using const auto
    const int const_val{3};
    const auto const_val_ref {val};
    //const_val = 12 ; //error

    //4- using auto*
    int i { 123 };
    auto p { &i };  //same as int* p {&i}
    *p = 189;
    std::cout<<&i<<std::endl;
    std::cout<<p <<std::endl;
    std::cout<<*p<<std::endl;

}