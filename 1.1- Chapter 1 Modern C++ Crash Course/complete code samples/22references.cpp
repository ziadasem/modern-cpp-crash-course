#include <iostream>

class MyClass
{
public:
    MyClass(int& ref) : m_ref { ref } { /* Body of constructor */ }
private:
    int& m_ref;
};


void addOne(int* i)
{
    (*i)++ ;
}
int main(int argv, char **argc){
    int aaa = 0 ;
    int* i = &aaa ;
    addOne(i);
    std::cout<<aaa<<std::endl; ;


    int a {4};
    //int& aRef ;  //error: declaration of reference variable 'aRef' requires an initializer

    int x { 3 }, y { 4 };
    int& xRef { x };
    xRef = y; // Changes value of x to 4. Doesn't make xRef refer to y.

    //reference to unamed value
    const int& xRef2 {4};
    int&& rValueRef {5};
    rValueRef = 12 ;
    std::cout << rValueRef << "\n";

    return 0;
    
}

