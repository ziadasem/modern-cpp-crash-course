#include <iostream>
struct CircleStruct
{
    int x, y;
    double radius;
};

class CircleClass
{
public:
    CircleClass(int x, int y, double radius)
    : m_x { x }, m_y { y }, m_radius { radius } {}
private:
    int m_x, m_y;
    double m_radius;
};

int main(){

    //uniform initialization
    CircleStruct myCircle5 { 10, 10, 2.5 };
    CircleClass myCircle6 { 10, 10, 2.5 };
    int arr[] {1,2,3};

    //zero init
    CircleStruct zerosCircle {};
    std::cout<<zerosCircle.x << " "<<zerosCircle.y <<" " << zerosCircle.radius <<"\n";
    
    CircleStruct randomCircle ;
    std::cout<<randomCircle.x << " "<<randomCircle.y <<" " << randomCircle.radius <<"\n";

    //narrowing
    int a = 3.14 ;
    //int b {3.14}; //error   
}