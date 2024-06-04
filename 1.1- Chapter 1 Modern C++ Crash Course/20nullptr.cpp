#include <iostream>

void fun(int N)   { std::cout << "fun(int)"; return;}

// Overloaded function with char pointer argument
void fun(char* s)  { std::cout << "fun(char *)"; return;}

int main() 
{
    // Ideally, it should have called fun(char *),
    // but it causes compiler error.
    //fun(NULL);   //compilation error
    fun(nullptr); //fun(char *)
}