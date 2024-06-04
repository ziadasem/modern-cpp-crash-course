#include <stdio.h>

//2.2 using multiple namespaces
namespace n1 { int add(int x, int y){return x + y;}}
namespace n1 { int sub(int x, int y){return x - y;}}
namespace n1 { int sub(int x){return x;}}


int main() {
    n1::add(1,2);
    n1::sub(1,2);

}
