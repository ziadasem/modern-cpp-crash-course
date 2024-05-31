#include <iostream>
void addOne(int* i)
{
  (*i)++ ;  //increment the pointer then increment the new place, unexpected behaviour
   
}

void addOne1(int* i)
{
  *i++ ;  
  //increment the  copy of pointer then dereference the new place, without doing anything to it, hence the compiler 
  //issues a warning: expression result unused
   
}

void addOne2(int* i)
{
  *(i)++ ;  
  //increment the copy of pointer then dereference the new place, without doing anything to it, hence the compiler 
  //issues a warning: expression result unused
   
}


void addOne3(int* i)
{
  (*i++)++ ;  
  //increment the pointer then dereference the new place, and increment it; unexpected behaviour
   
}


int main(){
    int val {0};
    int* i {&val} ;

    addOne(i); 
    std::cout << val << "\n";


    val = 0;
    addOne1(i); 
    std::cout << val << "\n";


    val = 0;
    addOne2(i); 
    std::cout << val << "\n";
    return 0;

}