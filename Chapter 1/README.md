# Notes from Chaptr 1:&nbsp;&nbsp;A Crash Course in C++ and the Standard Library

Note: this is some notes from the chapter, not a comprehensive summary of it

**C vs C++**

The C++ language is often viewed as a “better C” or a “superset of C.” It was mainly designed to be an object-oriented C, commonly called as “C with classes. **But if you are familiar with C programming does it mean that you don't need to learn C++ ?**

**No**, if you are an experienced C programmer. The two languages certainly have their differences, though. As evidence, **the C23 standard specification document is a little fewer than 800 pages** in size, while the **C++23 standard specification document is more than 2,000 pages.** So, if you’re a C programmer but also if you are coming from other languages such as Java, C#, Python, and so on, be on the lookout for new or unfamiliar syntax!

  ## 1- Headers, Imports, and I/O Streams

the  **Hello World!** program
```c++

//main.c

#include  <iostream>

// import std; //C++ 23

int  main()

{

//std::println("Hello, World!"); //c++23

std:cout<<"Hello World! \n" ;

return  0;

}

```

- Comments

`// and /* */`

  

**Importing Modules**

Support for modules was one of the big four new features of C++20, replacing the old mechanism of header files. If you want to use functionality from a module, you simply import that module. This is done with an import declaration. Starting with C++23, you can get access to the entire C++ Standard Library by importing a single standard named module called std.

  

import std;

</br>  </br>

**How the Compiler Processes Your Source Code**

- **Preprocessor** : First, the code is run through a preprocessor, which recognizes meta-information about the code and handles preprocessor directives, such as `#include` directives. A source file in which all preprocessor directives are handled is called a translation unit

- **Translation unit** : Next, all translation units are independently compiled, or translated, into machine-readable object files in which references to functions and so on are not yet defined.

- **Linker** : Resolving those references is done in the final phase by the linker, which links all object files together into the final executable

  

**Printing**

new features :

- starting from C++ 23:

```c++

std::println("{} + {} = {}", 2, 4, 6); // 2 + 4 = 6

```

- starting from C++20:

```c++

std::cout << std::format("There are {} ways I love you.", 219) << std::endl;

//there are 219 ways I love you.

```

&nbsp;

**Use `endl` or `\n` ?**

  

>  `endl` inserts a new line into the stream and **flushes everything**

>  **Currently in its buffers down the chute**. **Overusing endl, for example

> In a loop, is not recommended because it will have a performance

> impact.** On the other hand, inserting `\n` into the stream also inserts

> a new line **but does not automatically flush the buffers.**

  

**Where are printf and scanf of C ?**

If you’re new to C++ and coming from a C background, you’re probably wondering what has been done with the trusty old printf() and scanf() functions. **While these functions can still be used** in C++, I strongly recommend using the modern print(), println(), and format() functions and the streams library instead, **mainly because the printf() and scanf() family of functions do not provide any type safety.**

  

**return from main**

```c++

return  0 ;

```

return from the main function returns the control to the operating system. When

doing so, it passes the value 0, which usually signals to the operating system that there were no errors while executing the program. For error cases, you can return non-zero values.

**A return statement in main() is optional.** If you don’t write one, the compiler will implicitly add a return 0; for you.

**Some Escape charachters**
| ESCAPE SEQUENCE | MEANING                                                                                                       
|-----------------|--------------------------------------------------------
| \n              | New line: moves the cursor to the beginning of the next line                                                  |
| \r              | Carriage return: moves the cursor to the beginning of the current line, but does not advance to the next line |
| \t              | Tab                                                                                                           |
| \\              | Backslash character                                                                                           |
| \"              | Quotation mark                                                                                                |

```c++
int  main(){

//1.5 escape characters
std::cout  <<  "This is a word will be replaced"  <<"\r"  <<"Hello there"  <<  std::endl;
//Hello thereord will be replaced
return  0 ;
}
```
**Print Errors**
to print errors use `cerr`, but what is the difference between `cout`, `cerr`, and `clog`:

* **Standard output stream (cout):**  `cout`  is the instance of the  `ostream`  class.  `cout`  is used to produce output on the standard output device which is usually the display screen. The data needed to be displayed on the screen is inserted in the standard output stream (`cout`) using the insertion operator (`<<`).

* **Un-buffered standard error stream (cerr):**  `cerr`  is the standard error stream that is used to output the errors. This is also an instance of the  `ostream`  class. As  `cerr`  is  **un-buffered**  so it is used when we need to display the error message immediately. It does not have any buffer to store the error message and display it later.

* **Buffered standard error stream (clog):**  This is also an instance of  `ostream`  class and is used to display errors but unlike  `cerr`  the error is first inserted into a  **buffer**  and is stored in the buffer until it is not fully filled.

```c++
int main(){
    //1.6 errors
    std::cerr << "Errors" << std::endl; //unbuffered cerr
    return 0 ;
}
```
in **modern c++** use `std::println(std::cerr, "Error: {}", 6);`

### 2- Namespaces
A namespace is a feature added in C++ and is **not present in C.** A namespace is a declarative region that provides a scope to the identifiers (names of functions, variables, or other user-defined data types) inside it. **Multiple namespace blocks with the same name are allowed.**

Namespaces address the problem of naming conflicts between different pieces of code. For example, you might be writing some code that has a function called foo(). One day, you decide to start using a third-party library, which also has a foo() function. The compiler has no way of knowing which version of foo() you are referring to within your code. You can’t change the library’s function name, and it would be a big pain to change your own.
Namespaces come to the rescue in such scenarios because you can define the context in which names are defined. To place code in a namespace, enclose it within a namespace block. Here’s an example:
```c
namespace mycode {
void foo()
{
	std::println("foo() called in the mycode namespace");
}
}
```

**Creating and using namespaces**
suppose we have two versions of arithmetic operations; one on the real domain and one on the imaginary domain, the imaginary domain will be represented with 0+0i.
we will create two versions of add functions one for real and one for imaginary.

```cpp
#include <iostream>
namespace realoperaton{
    int add(int a, int b){
        return a+b;
    }
}

namespace imaginaryoperaton{
	//will be discussed later
    struct complexNum{
        int a;
        int b ;
    };
    complexNum add(complexNum z1, complexNum z2){
        complexNum z ;
        z.a = z1.a + z2.a;
        z.b =  z1.b + z2.b;
        return z;
    }
}

int main(){
    std::cout<<realoperaton::add(2,3)<<"\n";
    imaginaryoperaton::complexNum z1,z2;
    z1.a = 2;
    z1.b = 3;
    z2.a = 4;
    z2.b = 5;
    imaginaryoperaton::complexNum z = imaginaryoperaton::add(z1,z2);
    std::cout<<z.a<<"+" << z.b<< "i\n";
    return 0;
}
```
```sh
5
6+8i
```

Any code that falls within a namespace block can call other code within the same namespace without explicitly prepending the namespace. This implicit namespace is useful in making the code more readable.

**using multiple namespaces with same name**

```cpp
#include <stdio.h>

//2.2 using multiple namespaces
namespace n1 { int add(int x, int y){return x + y;}}
namespace n1 { int sub(int x, int y){return x - y;}}
namespace n1 { int sub(int x){return x;}}

int main() {
    n1::add(1,2);
    n1::sub(1,2);
}
```
multiple namespaces with the same name can be used without compilation error, to be aware while defining a new namespace.

**main function inside namespace**
can we use the main function inside a namespace? let's try
```cpp
namespace n1{
    int main(){
        return 0 ;
    }
}
```
```sh
PS F:\Chapter 1> (g++ .\2.3main_inside_namespace.cpp) 
F:/mingew64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/13.2.0/../../../../x86_64-w64-mingw32/bin/ld.exe: F:/mingew64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/13.2.0/../../../../x86_64-w64-mingw32/lib/../lib/libmingw32.a(lib64_libmingw32_a-crtexewin.o):crtexewin.c:(.text+0x130): undefined reference to `WinMain'
collect2.exe: error: ld returned 1 exit status
```
so the main method should be defined inside the global namespace, and defining the main function inside a namespace will not be considered as program entry point.
```cpp
#include <iostream>
namespace n1{
    int main(){
        std::cout << "inside n1" ;
        return 0 ;
    }
}
int main(){
    std::cout << "inside global namespace" ;
}
```



```sh
PS F:\cpp nti\Chapter 1> (g++ .\2.3main_inside_namespace.cpp) 
PS F:\cpp nti\Chapter 1> .\a.exe
inside global namespace
```

**'using' directive**
You can also avoid prepending of namespaces with a **using** directive. This directive  
tells the compiler that the subsequent code is making use of names in the specified namespace. The  namespace is thus implied for the code that follows:
```cpp
using namespace mycode;  
int main()  
{  
	foo(); // Implies mycode::foo();  
}
```
A single source file can contain multiple using directives, but beware of overusing this shortcut. In the extreme case, if you declare that you’re using all of the available namespaces, you’re effectively eliminating namespaces entirely! Name conflicts will again result if you are using two namespaces that contain the same names. It is also important to know in which namespace your code is operating so that you don’t end up accidentally calling the wrong version of a function.  

```cpp
#include <iostream>
namespace n1{
    void fun1(){
       std::cout<<"n1::fun1\n";
    }

    void fun2(){
       std::cout<<"n1::fun2\n";
    }
}

namespace n2{
    void fun1(){
       std::cout<<"n2::fun1\n";
    }

    void fun2(){
       std::cout<<"n2::fun2\n";
    }
}

using namespace n1 ;

int main(){
    fun1(); //default to n1 n1::fun1
    fun2(); //n1::fun2
    return 0;
}
```
```bash
n1::fun1
n1::fun2
```

**WARNING** *Never put a using directive or using declaration in a header file at  
global scope; otherwise, you force it on everyone who includes your header file.  
Putting it in a smaller scope, for instance at namespace or class scope, is OK, even  
in a header file. It’s also perfectly fine to put a using directive or declaration in a  
module interface file, as long as you don’t export it. However, this book always  
fully qualifies all types in module interface files, as I think it makes it easier to  
understand an interface. Module interface files and exporting entities from modules are explained later in this chapter.*

**Nested Namespace**

```cpp
#include <iostream>
namespace n1 { 
    void fun1(){
        std::cout << "n1::fun1\n";
    }
}
namespace n2 { 
    void fun1(){
        std::cout << "n2::fun1\n";
    }
    namespace n2_sub{
    void fun(){
        fun1(); //sub from n2
    }
}
}
int main(){
    n2::n2_sub::fun();
    return 0;
}
```
This compact syntax is  available after C++17 is:
```cpp
namespace MyLibraries::Networking::FTP {  
/* ... */  
}
```

**Namespace Alias**

to set an alias for 
```cpp 
n2::n2_sub::fun();
``` 
we can use
```cpp
namespace n2alias= n2::n2_sub:
```

for example:

```cpp
#include <iostream>

namespace n2 { 
    void fun1(){
        std::cout << "n2::fun1\n";
    }
    namespace n2_sub{
    void fun(){
        std::cout << "n2_sub::fun1\n";
        fun1(); //sub from n2
    }
    namespace n2_sub_sub
    {
        void funct(){
            std::cout << "n2::n2_sub::fun1\n";
            fun(); //sub from n2
        }
    } 
    

}
}
namespace n2SubSub = n2::n2_sub::n2_sub_sub;

int main(){
    n2SubSub::funct();
    return 0;
}

```

### 3- Literals

| Example                   | Literals                             |
|---------------------------|--------------------------------------|
| 123                       | Decimal literal                      |
| 0123                      | Octal literal (starts with a zero)   |
| 0x7B                      | Hexadecimal literal (starts with 0x) |
| 0b1111011                 | Binary literal (starts with 0b)      |
| 3.14f                     | A floating-point value               |
| 3.14                      | A double floating-point value        |
| 0x3.ABCp-10 and 0Xb.cp12l | A hexadecimal floating-point literal |


**WARNING** *Never put a zero, 0, in front of a numerical literal, unless it’s an octal literal!*

```cpp
int main(){
    int x = 0129 ; //invalid octal value
    int xx = 129; //valid integer value
}
```

Single-quote characters can be used as digit separators in numeric literals. For example:
```
int main(){
    int a = 23'456'789 ; // same as 23456789
}
```
Multiple string literals separated only by whitespace are automatically concatenated into a single string. For example:
```cpp
#include <iostream>
int main(){
    std::cout << "Hello," "world!";  // same as "Hello, world!"
}
```

### 4- Variables
notes on variables, not a comprehensive guide.
In C++11 and later a new initialization method is introduced, which is called uniform initialization.

```cpp
type var_name{arg1, arg2, ....arg n}
```
for example:
```cpp
// uninitialized built-in type
int i;    
// initialized built-in type
int j=10; 
// initialized built-in type
int k(10);
// Aggregate initialization
int a[]={1, 2, 3, 4} 

//and other initialization will be listed in the next sections
```
by using uniform initialization:
```cpp
int i{};     // initialized built-in type, equals to int i{0};
int j{10}; // initialized built-in type
int a[]{1, 2, 3, 4} // Aggregate initialization
```

the benefits of uniform initialization will be discussed later in this document, as some topics should be introduced.

**Numerical Limits**
```cpp
numeric_limits<int>::max()
```
replace \<int> with the datatype you want.

```cpp
println("int:");  
println("Max int value: {}", numeric_limits<int>::max());  
println("Min int value: {}", numeric_limits<int>::min());  
println("Lowest int value: {}", numeric_limits<int>::lowest());  
println("\ndouble:");  
println("Max double value: {}", numeric_limits<double>::max());  
println("Min double value: {}", numeric_limits<double>::min());  
println("Lowest double value: {}", numeric_limits<double>::lowest());
```

```cpp
The output of this code snippet on my system is as follows:  
int:  
Max int value: 2147483647  
Min int value: -2147483648  
Lowest int value: -2147483648  
double:  
Max double value: 1.7976931348623157e+308  
Min double value: 2.2250738585072014e-308  
Lowest double value: -1.7976931348623157e+308
```

**Note** the differences between `min()` and `lowest()`. 
**For an integer:** the minimum value equals the lowest value. 
**For floating-point types:** the **minimum value is the smallest positive value**  that can be represented, while the **lowest value is the most negative value representable,** which  equals -max()

**Casting**
Variables can be converted to other types by casting them. For example, a float can be cast to an int.
C++ provides three ways to explicitly change the type of a variable. 
1. The first method is a  holdover from C; it is not recommended but, unfortunately, still commonly used 
2. The second method is rarely used
3. The third method is the most verbose but is also the cleanest one and is therefore  recommended

```cpp
float myFloat { 3.14f };  
int i1 { (int)myFloat }; // method 1  
int i2 { int(myFloat) }; // method 2  
int i3 { static_cast<int>(myFloat) }; // method 3
```
**Floating-Point Numbers**
some special floating-point numbers
| Number      | Descp                                                                                                             |
|-------------|-------------------------------------------------------------------------------------------------------------------|
| +/-infinity | Represents positive and negative infinity, for example, the result of dividing a nonzero number by zero            |
| NaN         | Abbreviation for not-a-number, for example, the result of dividing zero by zero, a mathematically undefined result |

To check whether a given floating-point number is not a number, use `std::isnan()`. To check for infinity, use `std::isinf()`. Both functions are defined in \<cmath>.

more floating point types introduced in c++23
https://en.cppreference.com/w/cpp/types/floating-point

### 4- Enumerations
enumerations define a range of values for a variable. The following code declares a new type, PieceType, which has four possible values, called  enumerators, representing four directions:
```cpp
enum class Directions {
    UP,
    DOWN,
    LEFT,
    RIGHT
};
```
the enum name is `Directions` and every entry has a constant value. to define a new direction from the Directions enum do the following:
```cpp
int main(){
    Directions d1 = Directions::UP; 
    //or
    Directions d2 {Directions::DOWN};
}
```
the `UP, DOWN, LEFT, RIGHT` values are just integer values `0,1,2,3`. values can be set explicitly as follows: 
```cpp
enum class Directions {
    UP =10,
    DOWN,
    LEFT =30,
    RIGHT
};
```
value of `DOWN` by default will take the value of the previous entry + 1 (i.e. `DOWN=11` )/
Although directions are integer values, they can't be used in integer variables.

```cpp
enum class Directions {
    UP = 10,
    DOWN,
    LEFT,
    RIGHT
};
int main(){
    Directions d1 = Directions::UP ; 
    Directions d2 {Directions::DOWN};

    std::cout << d1 << std::endl;  //error, not an integer constant
    int d1Val = d1;  //error, not an integer constant

    d1 = d1 + 3; //error can't perform arithmetic operations

    //to use the value of the enum 
    std::cout << static_cast<int>(d2) << std::endl;  //cast enum to int //11

    return 0;
}
```
Starting with C++23, you can use `std::to_underlying()`. For example:  
`int underlyingValue { to_underlying(d2) }; //underlyingValue = 11 ` 

By default, the underlying type of an enumerator is an integer, but this can be changed as follows:
```cpp
num class PieceType : unsigned long
{
King = 1,
Queen,
Rook = 10,
Pawn
};
```

**exporting of enumeration names**
For an enum class, the enumerator names are not automatically exported to the enclosing scope.  This means they cannot clash with other names already defined in the parent scope. As a result,  
different strongly typed enumerations can have enumerators with the same name. For example:
```cpp
#include <iostream>
enum class AppState {
    Running = 5,
    Paused,
    Exiting
};

enum class ServerState {
    Running = 12,
    Paused,
    Exiting
};

int main(){
    //no conflict
    AppState appState{AppState::Running};
    ServerState serverState{ServerState::Running};

    std::cout <<static_cast<int>(appState)<<std::endl;
    std::cout <<static_cast<int>(serverState)<<std::endl;

    //same enumerator name, but different values and no conflicts

    return 0;
}
```
A big benefit of this is that you can give short names to the enumerators, for example, `Paused`  instead of `ServerPaused` and `AppPaused`. 

you can use the **using** declarative with enums as follows:
```cpp
  int main(){
    //c++ > 20
    using  class ServerState;
    std::cout <<static_cast<int>(Running)<<std::endl; //12
  }
```

**Old-Style Enumerations**
New code should always use the strongly typed enumerations (`enum class NAME`) explained in the previous section.  However, in legacy code bases, you might find old-style enumerations, also known as unscoped enumerations: `enum` instead of `enum class`. The enumerators of such old-style enumerations are exported to the enclosing scope. This means that in the parent scope, you can use the names of the enumerators without fully qualifying them. this may lead to conflicts for example:

```cpp
enum class StrongEnum {
    A,
    B,
    C
};

enum class NonConflictingEnum {
    A,
    B,
    C
};

enum  OldEnum {
    AA,
    BB,
    CC
};

enum  ConflictingEnum {
    AA, //error: redefinition of enumerator 'AA'
    BB,
    CC
};

int main(){
    OldEnum oldEnum{AA};  //without qualifying parent enum
}
```

**WARNING** *Always use strongly typed enum class enumerations instead of old style, unscoped, type-unsafe enum enumerations*

### 5- Structs
Structs let you encapsulate one or more existing types into a new type.
A struct can be imported as a module.
define a struct in a module interface file. aModule interface files usually have  
.cppm as an extension. The first line in the module interface file is a module declaration and states that this file defines a module called employee. Furthermore, a module needs to explicitly state what it exports, **i.e., what will be visible when this module is imported somewhere else**. Exporting a type from a module is done with the export keyword in front of, for example, a struct.  
```cpp
export module employee;  
export struct Employee {  
char firstInitial;  
char lastInitial;  
int employeeNumber;  
int salary;  
};
```
A variable declared with the type Employee has all of these fields built in. The individual fields of a struct can be accessed by using the `.` operator. The example that follows creates and then outputs the record for an employee. Just as with the standard named module std, you don’t use angle brackets when importing custom modules.  
```cpp
import std;  
import employee; // Import our employee module  
using namespace std;  
int main()  
{  
// Create and populate an employee.  
Employee anEmployee;  
anEmployee.firstInitial = 'J';  
anEmployee.lastInitial = 'D';  
anEmployee.employeeNumber = 42;  
anEmployee.salary = 80000;  
// Output the values of an employee.  
println("Employee: {}{}", anEmployee.firstInitial,  
anEmployee.lastInitial);  
println("Number: {}", anEmployee.employeeNumber);  
println("Salary: ${}", anEmployee.salary);  
}
```

### 6- Conditional Statements and Logical Operators
**if/else Statements**

    if (cond) {
    }else{
    }

The expression between the parentheses of an if statement must be a Boolean value or evaluate to a Boolean value. A value of 0 evaluates to false, while any non-zero value evaluates to true.

**Initializers for if Statements**
C++ allows you to include an initializer inside an if statement using the following syntax:
```cpp
if (<initializer>; <conditional_expression>) {  
<if_body>  
} else if (<else_if_expression>) {  
<else_if_body>  
} else {  
<else_body>  
}
```
Any variable introduced in the <initializer> is available only in the `<conditional_expression>`,  in the `<if_body>`, in all `<else_if_expression>s` and `<else_if_body>`s, and in the `<else_body>`.  
Such variables are not available outside the if statement.

```cpp
#include <iostream>
int main(){
    if (int a = 5, b = 10 ; a > 10){
          std::cout << a<<"\n";
    }else if (b = 11 ; a < 10 ){ //visible
        std::cout << b<<"\n"; //visible
    }else {
        std::cout << a<<"\n"; //visible
    }
}
```
```bash
PS F:\> .\a.exe
11
```

**Initializers for switch Statements**
Just as for if statements, you can use initializers with switch statements. The syntax is as follows:  
`switch (<initializer>; <expression>) { <body> }  `
Any variables introduced in the \<initializer> are available only in the \<expression> and in the  \<body>. They are not available outside the switch statement.

**The Conditional Operator**
C++ has one operator that takes three arguments, known as a ternary operator. It is used as a shorthand conditional expression of the form “if [something] then [perform action], otherwise [perform  some other action].” The conditional operator is represented by
``(condition) ?[execute this if true]  : [execute this if false]``
The advantage of the conditional operator is that it is an expression, not a statement like the if and switch statements. Hence, a conditional operator can occur within almost any context. for example, it can occur within a passing argument.
```cpp
void foo (int i){
	std::cout<<i;
}
int main(){
	foo (2>3 ? 5 : 4); // 4
}
```


**Logical Evaluation Operators**

C++ uses short-circuit logic when evaluating logical expressions. That means that once the final result is certain, the rest of the expression won’t be evaluated.

```cpp
#include <iostream>
bool a(int i){
    std::cout <<i << " a\n" ;
    return false ;
}

bool b(int i){
    std::cout << i << " b\n" ;
    return false;
}

int errorFunction(){
    std::cout<<"Error\n";
    return 1/0;
}

int main(){
    if (true || a(0) || b(1)) {
        //pass
    }

    if (  a(2) || true  || b(3)) {
         //pass
    }

    if ( !a(4) || errorFunction() ) {
        //the shortcircuit logic will save the program from executing the error function, but if the value of !a()
        // is changed, this will lead to new problems that may be undiscovered in the previous runs
        std::cout << "No Errors\n" ;
    }

    if ( a(5)  && b(6) && true) {
      
    }
}
```

```bash
 .\a.exe
2 a
4 a
No Errors
5 a
No Errors
```

Short-circuiting can be beneficial for performance. You can put less resource-intensive tests first so that more expensive tests are not even executed when the logic short-circuits. It is also useful in the context of pointers to avoid parts of the expression being executed when a pointer is not valid. Pointers and short-circuiting with pointers are discussed later in this chapter.

**Three-Way Comparisons**
the `<,>, <=, ==, >=` operators are used to answer a single question (greater than, smaller than, ...), but don't answer multiple questions as (is `a` is greater than or smaller than or equal to `b` ?), to do so we will use a spaceship operator (The three-way comparison), this operator is introduced in c++20.
since this operator can't return a single answer (boolean) it will return an enumeration-like type,  defined in \<compare> in the std namespace. called a `strong ordering` and can be one of the following:

* **strong_ordering::less**: First operand less than second, its value is <0
* **strong_ordering::greater**: The first operand is greater than the second,  its value is >0
* **strong_ordering::equal**: First operand equal to second,  its value is 0
```cpp
int i { 11 };  
strong_ordering result { i <=> 0 };  
if (result == strong_ordering::less) { println("less"); }  
if (result == strong_ordering::greater) { println("greater"); }  
if (result == strong_ordering::equal) { println("equal"); }
```

or using values
```cpp
// C++ program to illustrate the 3-way comparison
// (spaceship) operator
#include <compare>
#include <iostream>
using namespace std;
int main()
{
	int x = 10;
	int y = 20;
	// saving the result of the 3-way comparison operator
	auto res = x <=> y;
	// executing statements based on the above comparison
	if (res < 0)
		cout << "Less";
	else if (res > 0)
		cout << "Greater";
	else if (res == 0)
		cout << "Same";
	else
		cout << "Unordered";

	return 0;
}
```

Certain types don’t have a strong ordering. For example, not-a-number floating-point values are never equal, less than, or greater than any other floating-point value. Thus, such comparisons result in a  `partial ordering`:
* partial_ordering::less: First operand less than second
* partial_ordering::greater: First operand greater than second
*  partial_ordering::equivalent: First operand equivalent to second, meaning
!(a<b) && !(b<a); for example, -0.0 is equivalent to +0.0, but they are not equal
* partial_ordering::unordered: If one or both of the operands are not a number


### 7- Functions
For programs of any significant size, placing all the code inside of main() is unmanageable. To make programs easier to understand, you need to break up, or decompose, code into concise functions.  
In C++, you first declare a function to make it available for other code to use. **If the function is used only inside a particular file, you generally declare and define the function in that source file.** If the function is for use by **other modules or files, you export a declaration for the function from a module interface file,** while the function’s definition can be either in the same module interface file or in a module implementation file.

**NOTE** Some definitions:
* Function declarations are often called function prototypes or function headers to emphasize that they represent how the function can be accessed, but not the code behind it
`void myFunction(int i, char c);`

* Function signature is used to denote the combination of the function name and its parameter list but without the return type.

**NOTE** *In C++, unlike C, a function that takes no parameters just has an empty  
parameter list. It is not necessary to use void to indicate that no parameters are  
taken. However, you must still use void to indicate when no value is returned.*

**Function Return Type Deduction**
You can ask the compiler to figure out the return type of a function automatically. To make use of  
this functionality, just specify auto as the return type.  
```cpp
auto addNumbers(int number1, int number2)  
{  
	return number1 + number2;  
}
```

**Current Function’s Name**
Every function has a local predefined variable __func__ containing the name of the current function.  
One use of this variable could be for logging purposes.  
```cpp
int addNumbers(int number1, int number2)  
{  
	std::cout<<__func__;
	return number1 + number2;  
}
```