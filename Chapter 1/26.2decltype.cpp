#include <iostream>
int main(){

    //1- using decltype with references

    int val{3};
    int& valRef {val};
    decltype(valRef)  valRefRef {valRef};//returns int&

    valRefRef = 10;
    std::cout<<val<<std::endl;

    //2- using decltype with const references
    const int const_val{3};
    const int& const_val_ref {val};
    decltype(const_val_ref)  const_val_ref_ref {const_val_ref};//returns int&

    //const_val_ref_ref = 12 ; //error constant value

}