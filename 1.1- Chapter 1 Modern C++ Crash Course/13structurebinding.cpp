
#include <array>
#include <iostream>

struct s {
    int a, b, c ;
};

int main(){
    //1- bind from array
    std::array vals {1,2,3};

    //should be defined with keyword auto
    auto [x1, x2, x3] {vals};
    //or
    auto [y1, y2, y3]  = vals;

    std::cout << x1 << " " << x2 << " " << x3 << "\n";

    //auto [z1, z2] {vals}; //error
    //int [z1, z2] {vals}; //error

    //2- bind from struct
    s s1 {1,2,3};
    auto [a1, a2, a3] {s1};
    std::cout << a1 << " " << a2 << " " << a3 << "\n";

    //3- bind from tuple
    std::tuple t1 {1,2,3};
    auto [b1, b2, b3] {t1};
    std::cout << b1 << " " << b2 << " " << b3 << "\n";

    //4- bind from pair
    std::pair p1 {1,2};
    auto [c1, c2] {p1};
    std::cout << c1 << " " << c2 << "\n";

    return 0;

}