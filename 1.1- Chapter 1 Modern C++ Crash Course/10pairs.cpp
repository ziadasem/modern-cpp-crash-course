#include<utility>
#include<iostream>

int main(){
    std::pair<double,int> p  {1.8, 9};
    //or
    //p.first = 1.8;
    //p.second = 9;
    std::cout<<p.first<<std::endl;
    std::cout<<p.second<<std::endl;
    return 0;
}