#include <tuple>
#include <iostream>
int main2(){
    std::tuple<int, float, char> t ;
    t = std::make_tuple(1, 8.9, 'c');
    //or
    //std::tuple<int, float, char> t(1, 8.9, 'c');

    std::cout << std::get<0>(t) << std::endl;
    std::cout << std::get<1>(t) << std::endl;
    std::cout << std::get<2>(t) << std::endl;
    return 0;
}

