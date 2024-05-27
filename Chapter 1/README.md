
# Notes from Chaptr 1:&nbsp;&nbsp;A Crash Course in C++ and the Standard Library

Note: this is some notes from the chapter, not a comprehensive guide of it

- [1- Headers, Imports, and I/O Streams](#1--headers-imports-and-i/o-streams)
- [2- Namespaces](#2--namespaces)
- [3- Literals](#3--literals)
- [4- Variables](#4--variables)
- [4- Enumerations](#4--enumerations)
- [5- Structs](#5--structs)
- [6- Conditional Statements and Logical Operators](#6--conditional-statements-and-logical-operators)
- [7- Functions](#7--functions)
- [8- Attributes](#8--attributes)
- [9- C-Style Array, std::array, and vector](#9--c-style-array-std::array-and-vector)
- [10- std::pair](#10--std::pair)
- [11-std::optional and value_or](#11-std::optional-and-value_or)
- [12-std::tuple](#12-std::tuple)
- [13-Structured Bindings](#13-structured-bindings)
- [14- Loops](#14--loops)
- [15- Initializer Lists](#15--initializer-lists)
- [16- C++ as an Object-Oriented Language](#16--c++-as-an-object-oriented-language)
- [17- Scope Resolution](#17--scope-resolution)
- [18- Uniform Initialization](#18--uniform-initialization)
- [19- Designated Initializers](#19--designated-initializers)

**C vs C++**

The C++ language is often viewed as a “better C” or a “superset of C.” It was mainly designed to be an object-oriented C, commonly called as “C with classes. **But if you are familiar with C programming does it mean that you don't need to learn C++ ?**

**No**, if you are an experienced C programmer. The two languages certainly have their differences, though. As evidence, **the C23 standard specification document is a little fewer than 800 pages** in size, while the **C++23 standard specification document is more than 2,000 pages.** So, if you’re a C programmer but also if you are coming from other languages such as Java, C#, Python, and so on, be on the lookout for new or unfamiliar syntax!

### 1- Headers, Imports, and I/O Streams

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

- **Translation unit**: Next, all translation units are independently compiled, or translated, into machine-readable object files in which references to functions and so on are not yet defined.

- **Linker**: Resolving those references is done in the final phase by the linker, which links all object files together into the final executable

  

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

* **Buffered standard error stream (clog):**  This is also an instance of the `ostream`  class and is used to display errors but unlike  `cerr`  the error is first inserted into a  **buffer**  and is stored in the buffer until it is not fully filled.

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
so the main method should be defined inside the global namespace, and defining the main function inside a namespace will not be considered a program entry point.
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
num class PieceType: unsigned long
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

### 8- Attributes
**Attributes** are one of the key features of modern C++ which allows the programmer to **specify additional information to the compiler to enforce constraints(conditions), optimise certain pieces of code, suppress warnings or do some specific code generation**. Attributes are standardized in C++ since C++11, is standardized by using the double square brackets syntax [[attribute]].
*[recommended video for some attributes](https://www.youtube.com/watch?v=BpulWncdn9Y)*

**1- [[fallthrough]]**
recalling switch-case statement, 
```cpp
int main(){
    int x {10} ;
    switch (x)
    {
    case 10:
        std::cout << "case 10\n" ;
    case 15:
         std::cout << "case 15\n" ;
         break ;
    case 20:
         std::cout << "case 20\n" ;
    
    default:
        break;
    }
}
```
the output should be `case 10` but it is
```
case 10
case 15
```
this issue is because there isn't a break statement at the end of case 10, this issue is called fallthrough. so a compiler returns a warning message at this line.
when the developer wants to suppress this warning (i.e. this is the required behavior), a `[[fallthrough]]` attribute should be used.

```c++
int main(){
    int x {10} ;
    switch (x)
    {
    case 10:
        std::cout << "case 10\n" ;
        [[fallthrough]];
    case 15:
         std::cout << "case 15\n" ;
         break ;
    case 20:
         std::cout << "case 20\n" ;
    default:
        break;
    }
}
```

**2- [[nodiscard]]**
when a developer designs a function and wants to enforce to use of its return value in case of being called (i.e. to not discard it) or make the compiler issue a warning, he should use the `[[nodiscard]]` attribute.

```c++
[[nodiscard]] int func() { return 42; }  
int main()  
{  
func();  
}
```
The compiler issues a warning similar to the following:  
> warning C4834: discarding return value of a function with 'nodiscard' attribute

it may be used with functions that return an error status code.

**3- [[maybe_unused]]**
to suppress the warning of a compiler on unused variables, for example
```cpp
int x = 10 ;
int main(){
	return 0 ;
}
```
`warning C4100: 'x': unreferenced formal parameter`

by using `[[maybe_unused]]` before `int x = 10`, the warning will disappered.
```cpp
[[maybe_unused]] int x = 10 ;
int main(){
	return 0 ;
}
```
**4- [[noreturn]]**
every function when it finishes, returns the control to the calling function, but some functions don't return the control to the calling function, such as a function that has an infinite loop, a function that throws an exception, or causes some kind of termination.

for example:
```cpp
void noReturnControlToTheCaller(){
    while(1){}
}
int func(int p){
    if (p  < 0){
        return 10 ;
    }
    noReturnControlToTheCaller();
} //warning
int main(){
    return 0 ;
}
```
`non-void function does not return a value in all control paths [-Wreturn-type]`
the compiler issues a warning since it expects that func may reach its end (i.e. after  ` noReturnControlToTheCaller();` ) and didn't return a value, although it will never pass this line (`noReturnControlToTheCaller();`), since calling noReturnControlToTheCaller will never return the control to `func`. to suppress this warning use `[[noreturn]]` before `void noReturnControlToTheCaller(){`

```cpp
[[noreturn]] void noReturnControlToTheCaller(){
    while(1){}
}

int func(int p){
    if (p  < 0){
        return 10 ;
    }
    noReturnControlToTheCaller();
}
int main(){
    return 0 ;
}
```
the warning is suppressed.

**5- [[deprecated]]**
if a developer uses APIs from libraries or a framework, the developers of these libraries may mention that a function(API) will be removed in the next update of this library, so they want to warn the developer from using this function. it is done by using the attribute `[[deprecated]]`.
for example:
```cpp
//math.cpp
int add(int a, int b){ return a + b ; } 
int add_complex(int a, int b){ return a + b ; } 
```

if a developer developed a library for math, and the addition was limited to real numbers only, in the new update the addition is expanded to support complex numbers and it should be standardized. the developer can't remove the old function of add **to not violate the backward compatibility of the code in case a developer that uses the library updates it**, instead he will force the compiler to issue a warning to him to not use this function as it will be removed in the next updates. this is done by using `[[deprecated]]` as follows:
```cpp
//math.cpp
[[deprecated("this function will be removed use add_complex instead ")]]int add(int a, int b){ return a + b ; } 
int add_complex(int a, int b){ return a + b ; } 
```
or to show a deprecation warning  without any further information:
```cpp
//math.cpp
[[deprecated]]int add(int a, int b){ return a + b ; } 
int add_complex(int a, int b){ return a + b ; } 
```

**6- [[likely]] and [[unlikely]]**
to force the compiler to optimize a certain piece of code that is more likely to be executed we use `[[likely]]` attribute, and the same for branches in which more unlikely to be executed.
These attributes can, for example, be used to mark branches of if and switch statements according to how likely it is that a branch will be taken. However, these attributes are rarely required. Compilers and hardware these days have powerful branch predictions to figure it out themselves, but in certain cases, such as performance-critical code, you might have to help the compiler.  
The syntax is as follows:  
```cpp
int value { /* ... */ };  
if (value > 11) [[unlikely]] { /* Do something ... */ }  
else { /* Do something else ... */ }  
switch (value)  
{  
[[likely]] case 1:  
// Do something ...  
break;  
case 2:  
// Do something ...  
break;  
[[unlikely]] case 12:  
// Do something ...  
break;  
}
```

**7- [[assume]]**
this attribute is introduced in C++23.
```cpp
double divide(int num, int d){
	if (d != 0 ){
		return num/d ;
	}else{
		return num; //error
	}
}
```
to optimize the code to remove the else branch, use the `[[assume]]` keyword to assume that `d` will never equal to `0`.
```cpp
double divide(int num, int d){
	[[assume(d != 0)]];  
	if (d != 0 ){
		return num/d ;
	}
} 
```

another example:

an example, let’s look at the following function:  
```cpp
int divideBy32(int x)  
{  
return x / 32;  
}  
```
The function accepts a signed integer, so the compiler has to produce code to make sure the division works for both positive and negative numbers. If you are sure that x will never be negative, and for  some reason, you cannot make x of type unsigned, you can add an assumption as follows:  
```cpp
int divideBy32(int x)  
{  
[[assume(x >= 0)]];  
return x / 32;  
}  
```
With this assumption in place, the compiler can omit any code to handle negative numbers and optimize the division into a single instruction, a simple right shift of five bits.

[more](https://www.geeksforgeeks.org/attributes-in-c/)

### 9- C-Style Array, std::array, and vector 
This section briefly explains C-style arrays, as you will encounter them  
in legacy code. However, in C++, it is best to avoid C-style arrays and instead use  
Standard Library functionality, such as std::array in case of fixed size and vector in case of dynamic size.

**Legacy  C-Style Array**

to initialize an array:
```cpp
int myArray[3];  
myArray[0] = 0;  
myArray[1] = 0;  
myArray[2] = 0;
```
or set values via a loop.

an alternative method to initially initialize all elements to 0 is by doing the following:
```cpp
int myArray[3] = { 0 };
//or
int myArray[3] = {  }; //{} init with 0 by default
//or
int myArray[3] {}
//or to init with values other than 0
int myArray[3] {1,9,8}
//or
int myArray[] {1,9,0,8}
//or 
int myArray[5] {1} //{1. 0,0,0,0}
```

**size of array**
by using `std::size` defined in `<array>`
`std::size_t arraySize { std::size(myArray) };`

or by using the sizeof operator which returns the size of all elements of the array in bytes and divides it by the size of the first element to get the count.
```cpp
std::size_t arraySize { sizeof(myArray) / sizeof(myArray[0]) };
```

**std::array**
a `std::array` is a wrapper around the old C-Style array. it is defined in `<array>`.
the advantages of using std::arrays compared to C-style arrays are:

 - They always know their own size
 - They are not automatically cast to a pointer to avoid certain types of bugs
 - They have iterators to easily loop over the elements

`array<int, 3> arr { 1, 9, 8 };`


you can notice an angular bracket after array `<int, 3>`, the first parameter is the datatype of elements of the array and the second is the length of the array `<datatype, length>`, this angular brackets and the arguments passed between it is called class template arguments for class, a class template makes the code generic and will be discussed in detail further.

also, C++ can deduce the type of the elements without explicitly specifying it this is called class template argument deduction (CTAD) and will be discussed with `templates`.

```cpp
array arr { 9, 8, 7 };
```

type deduction should be done in initialization only.

for using a dynamic size array use `vector`

 
**vector**
declared in <vector>, a vector class replaces the concept of C-style arrays with a much more flexible and safer mechanism. , declared in <vector>, is an example of such a container. The vector class replaces the concept of C-style arrays with a much more flexible and safer mechanism.
```c++
// Create a vector of integers.
vector<int> myVector { 11, 22 };
// Add some more integers to the vector using push_back().
myVector.push_back(33);
myVector.push_back(44);
// Access elements.
println("1st element: {}", myVector[0]);
```
same as std::array, vector supports CTAD so a vector can be defined as follows:
```c++
vector myVector { 11, 22 };
```

### 10- std::pair
as its name suggests, pair stores two values with different types, defined in \<utility>.
```cpp
#include  <utility>
int main(){
	std::pair<double, int>  p{ 1.8, 9 };
}
```
to access pair values use `.first` and `.second`
```cpp
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
```
```bash
1.8
9
```
pair also supports CTAD, so you can define myPair as follows:  
```cpp
#include<utility>

int main(){
    std::pair p  {1.8, 9};
}
```
**NOTE** *While you could write a function returning an std::pair, it is recommended to write a small struct or class containing the two values and return that from the function. The downside of returning a pair is that **client code must be used first and second to access the two values. By returning a proper struct or class, you can give more meaningful names to the two values**.*

### 11-std::optional and value_or
std::optional, defined in <optional>, hold a value of a specific type, or nothing. 
optional can be used in :
 - to make a parameter of a function optional 
 - return a from a function or return error, 
returning an optional value from a function removes the need to return “special” values from functions such as nullptr, -1,  EOF, and so on. It also removes the need to write the function as returning a Boolean, representing success or failure.
The optional type is a class template, so you have to specify the actual type that you need between angle brackets, as in optional<int>. This syntax is similar to how you specify the type stored in a vector, for example, vector<int>.
```cpp
std::optional<int> getValue(bool success){
    if (success){
        return 181;
    }
    return std::nullopt; // or {}

}
```
to get the value from `std::optional`use `.value()` or with the dereferencing operator `*`.

```cpp
int main(){
    std::optional<int> withValue {getValue(true)};
    std::optional<int> withoutValue {getValue(false)};

    std::cout << "access value with method 1: "<< withValue.value()  << " \n";
    std::cout << "access value with method 2: "<< *withValue  << " \n";
}
```
```bash
access value with method 1: 181 
access value with method 2: 181
```
  

 to determine whether it has value or not use `has_value()` member function, or use the optional in an if statement.
```cpp
int main(){
    std::optional<int> withValue {getValue(true)};
    std::optional<int> withoutValue {getValue(false)};
    if (withValue){
         std::cout << "access value with method 1: "<< withValue.value()  << " \n";
        std::cout << "access value with method 2: "<< *withValue  << " \n";
    }
    if (withValue.has_value()) {
         std::cout << "access value with method 1: "<< withValue.value()  << " \n";
         std::cout << "access value with method 2: "<< *withValue  << " \n";
    }
   
   if (withoutValue){
         std::cout << "access value with method 1: "<< withoutValue.value()  << " \n";
        std::cout << "access value with method 2: "<< *withoutValue  << " \n";
    }
    if (withoutValue.has_value()) {
         std::cout << "access value with method 1: "<< withoutValue.value()  << " \n";
         std::cout << "access value with method 2: "<< *withoutValue  << " \n";
    }
}
```
```
access value with method 1: 181 
access value with method 2: 181
access value with method 1: 181
access value with method 2: 181
```
**handling empty values**
If you call `value()` on an empty optional, a `std::bad_optional_access` exception is thrown.  Exceptions are introduced later in this readme. to handle these issues without using `.has_value()` or ` if (withoutValue)` value_or() can be used to return either the value of an optional or another value when the optional is empty:

```cpp
std::cout << "value is "<< withoutValue.value_or(-1)  << "\n";

```

You cannot store a reference (discussed later in this readme) in an optional, so optional<T&> does
not work. Instead, you can store a pointer in an optional.

### 12-std::tuple
A tuple is an object that can hold several elements. The elements can be of different data types. The elements of tuples are initialized as arguments in the order in which they will be accessed. std::pair can only have two values - not zero, one, three, or more. TWO values. A tuple, however, has almost no semantic limitation on the number of values. An std::pair, therefore, is a more accurate, type-safe type to use if you actually want to specify a pair of values.

**to set values for a tuple use `make_tuple`, or `()` as following:**

```cpp
#include <tuple>
#include <iostream>
int main(){
    std::tuple<int, float, char> t ;
    t = std::make_tuple(1, 8.9, 'c');
}
```
or

```cpp
#include <tuple>
#include <iostream>
int main(){
    std::tuple<int, float, char> t(1, 8.9, 'c');
}
```
**to get value from tuple:**

use  get\<index>(tuple_name)
```cpp
int main(){
    std::tuple<int, float, char> t ;
    t = std::make_tuple(1, 8.9, 'c');
    std::cout << std::get<0>(t) << std::endl;
    std::cout << std::get<1>(t) << std::endl;
    std::cout << std::get<2>(t) << std::endl;
    return 0;
}
```
```
1
8.9
c
```

[more](https://www.geeksforgeeks.org/tuples-in-c/)

### 13-Structured Bindings
A structured binding allows you to declare multiple variables that are initialized with elements from a
data structure such as an array, struct, or pair.

**from array**
```cpp
#include <array>
#include <iostream>

int main(){
    //1- bind from array
    std::array vals {1,2,3};

    //should be defined with the keyword auto
    auto [x1, x2, x3] {vals};
    //or
    auto [y1, y2, y3]  = vals;

    std::cout << x1 << " " << x2 << " " << x3 << "\n"

}
```
**some note**:
*  you have to use the auto keyword for structured bindings, i.e., you cannot, for example, specify int instead of auto

* The number of variables declared with the structured binding has to match the number of values in the expression on the right

```cpp
int main(){
    auto [z1, z2] {vals}; //error
    int [z1, z2] {vals}; //error
}
```

**from structs**
Structured bindings also work with structs if all non-static members are public.

```cpp
struct s {
    int a, b, c ;
};

int main(){
    
    s s1 {1,2,3};
    auto [a1, a2, a3] {s1};
    std::cout << a1 << " " << a2 << " " << a3 << "\n";
    return 0;
}
```

**from tuples**
```cpp
int main(){
    std::tuple t1 {1,2,3};
    auto [b1, b2, b3] {t1};
    std::cout << b1 << " " << b2 << " " << b3 << "\n";
    return 0;
}    
```

**from pair**
```cpp
int main(){
    std::pair p1 {1,2};
    auto [c1, c2] {p1};
    std::cout << c1 << " " << c2 << "\n";
}
```
### 14- Loops
in the book `while`, `do-while`, and `for` loops are discussed, this readme is not a comprehensive guide, so some points are shown for this section **(Loops)**.

**continue vs break**

The keyword **break** can be used within a loop to immediately get out of the loop and resume execution of the program starting at the line of code following the loop.

The keyword **continue** can be used to return to the top of the loop and reevaluate the while expression. However, using continue
in loops is often considered **poor style because it causes the execution of a program to jump around somewhat haphazardly**, so use it sparingly.

**The Range-Based for Loop**

The range-based for loop allows  easy iteration over elements
of a container. This type of loop works for 
* C-style arrays
* Initializer lists (discussed later in the next section) 
* Any type that supports begin() and end() functions returning iterators (discussed later)

The following example first defines an array of four integers. The range-based for loop then iterates over a copy of every element in this array and prints out each value. To iterate over the elements themselves without making copies.

```cpp
array arr { 1, 2, 3, 4 };
for (int i : arr) { cout<<i<<"\n"; }
```

### 15- Initializer Lists
every function accepts a defined number of arguments, but if a function requires a variable number of parameters it requires another method. which is **Initializer Lists**.

Initializer lists are defined in \<initializer_list> and make it easy to write functions that can accept a variable number of arguments. The `std::initializer_list` type is a class template, and so it requires you to specify the type of elements in the list between angle brackets, similar to how you specify the type of elements stored in a vector. The following example shows how to use an initializer list:

```cpp
#include <iostream>
int sum(std::initializer_list<int> values)
{
    int total { 0 };
    for (int value : values) {
    total += value;
    }
    return total;
}
```

This function can be used as follows:
```cpp
int a { sum({ 1, 2, 3 }) };
int b { sum({ 10, 20, 30, 40, 50, 60 }) };
```
Initializer lists are type-safe. All elements in such a list must be of the same type. For the sum() function shown here, all elements of the initializer list must be integers. Trying to call it with a double, as shown next, results in a compilation error or warning stating that converting from double to int
requires narrowing.

```cpp
int c { sum({ 1, 2, 3.0 }) };
```

### 16- C++ as an Object-Oriented Language
If you are a C programmer, you may have viewed the features covered so far in this chapter as convenient additions to the C language. As the name C++ implies, in many ways the language is just
a “better C.” There is one major point that this view overlooks: unlike C, C++ is an object-oriented language. Object-oriented programming (OOP) is a different, arguably more natural, way to write code. 
OOP is a big interesting topic with theories, concepts, and best practices independent of a programming language (i.e. the concepts can be applied to any programming language that supports OOP). hence it can't be covered in just a section of a summary of a chapter, but it will be covered further in another chapter (Chapter 5, “Designing with
Classes,”  in the book).
this section is intended to show basic C++ object syntax if you already know the theory of OOP.

**Defining Classes**

A class defines the characteristics of an object. In modern C++, classes are usually defined and exported from
a module interface file (.cppm), while their definitions can either be directly in the same module interface file or in a corresponding module implementation file (.cpp). or in defined in a header file and implemented in .cpp files.
A basic class definition for an airline ticket class is shown in the following example. The class can calculate the price of the ticket based on the number of miles on the flight and whether the customer is
a member of the Elite Super Rewards Program.

The definition begins by declaring the class name after the keyword `class`. 
```cpp
class AirlineTicket {

}
```
between the set of curly braces, the data members
(properties/variables) of the class and its member functions (behaviors) are declared. Each data member and
member function is associated with a particular access level:
* Public

     Public members can be accessed from outside the class
* Protected  

    Members that are protected can be accessed by derived classes,  derived classes explained in detail further in the context of inheritance
* Private

     Private members cannot be accessed from anywhere outside the class

```cpp
class AirlineTicket
{
public:

private:

};
```

It’s recommended to make all your data members private,
and if needed, to give access to them with public or protected getters to retrieve data from an object and public or protected setters to set data for an object. **This way, you can easily change the
representation of your data while keeping the public/protected interface the same.**

Remember, on writing a module interface file, don’t forget to use an export module declaration (for C++ 20) to specify which module you are writing, and don’t forget to explicitly export the types you want to
make available to users of your module.

```cpp
 class AirlineTicket
{
public:
    AirlineTicket(); //constructor
    ~AirlineTicket(); //destructor
    double calculatePriceInDollars();
    std::string getPassengerName();
    void setPassengerName(std::string name);
    int getNumberOfMiles();
    void setNumberOfMiles(int miles);
    bool hasEliteSuperRewardsStatus();
    void setHasEliteSuperRewardsStatus(bool status);
private:
    std::string m_passengerName;
    int m_numberOfMiles;
    bool m_hasEliteSuperRewardsStatus;
};
```

it is noticed that the convention to prefix each data member of a class with a lowercase m followed by an underscore, such as m_passengerName is followed. 

**Constructor and Destructor**

The member function that has the same name as the class with no return type is a constructor. It is automatically called when an object of the class is created.

The member function with a tilde (~) character followed by the class name is a destructor. It is automatically called when an object is destroyed.

```cpp
//oop.h
 class AirlineTicket
{
public:
    AirlineTicket(); //constructor
    ~AirlineTicket(); //destructor
...
```

**Initialize members in constructors**
c++ provides three methods:
* implement inside the class constructor in the same file

```cpp

 class AirlineTicket
{
public:
    AirlineTicket(){
        .... //initialize members
    } //instead of  AirlineTicket()
...
```
* put the initializations in the body of the constructor, outside the class definition
```cpp
//oop.cpp
AirlineTicket :: AirlineTicket(){
    // Initialize data members.
    m_passengerName = "Unknown Passenger";
    m_numberOfMiles = 0;
    m_hasEliteSuperRewardsStatus = false;    
}
```

* use a constructor initializer, which follows a colon after the constructor header
```cpp
//opp.cpp
AirlineTicket::AirlineTicket(): m_passengerName { "Unknown Passenger" }, m_numberOfMiles { 0 }, m_hasEliteSuperRewardsStatus { false }

{

}
```
If your class additionally needs to perform some other types of initializations, such as opening a
file, allocating memory, and so on, then write a constructor to handle those initializations.


**Deleting members in destructor**

Destructors are required if you need to perform some cleanup,
such as closing files, and freeing memory but usually destructor doesn’t do anything and can simply be removed from this class unless what is mentioned.

in our case, we don't have pointers or opened files, so we can write an empty destructor.

```cpp
AirlineTicket::~AirlineTicket()
{
// Nothing to do in terms of cleanup
}
```

**Definitions of the class members**
as in a constructor, it can be defined within the class or outside the class.

**outside the class**
```cpp
double AirlineTicket::calculatePriceInDollars()
{
    if (hasEliteSuperRewardsStatus()) {
        // Elite Super Rewards customers fly for free!
        return 0;
    }
    // The cost of the ticket is the number of miles times 0.1.
    // Real airlines probably have a more complicated formula!
    return getNumberOfMiles() * 0.1;
}
string AirlineTicket::getPassengerName() { return m_passengerName; }
void AirlineTicket::setPassengerName(string name) { m_passengerName = name; }
int AirlineTicket::getNumberOfMiles() { return m_numberOfMiles; }
void AirlineTicket::setNumberOfMiles(int miles) { m_numberOfMiles = miles; }
bool AirlineTicket::hasEliteSuperRewardsStatus()
{
    return m_hasEliteSuperRewardsStatus;
}
void AirlineTicket::setHasEliteSuperRewardsStatus(bool status)
{
    m_hasEliteSuperRewardsStatus = status;
}
```
**inside the class**
```cpp
class AirlineTicket
{
public:
    double calculatePriceInDollars()
    {
        if (hasEliteSuperRewardsStatus()) { return 0; }
        return getNumberOfMiles() * 0.1;
    }
    std::string getPassengerName() { return m_passengerName; }
    void setPassengerName(std::string name) { m_passengerName = name; }
    int getNumberOfMiles() { return m_numberOfMiles; }
    void setNumberOfMiles(int miles) { m_numberOfMiles = miles; }
    bool hasEliteSuperRewardsStatus() { return m_hasEliteSuperRewardsStatus; }
    void setHasEliteSuperRewardsStatus(bool status)
    {
        m_hasEliteSuperRewardsStatus = status;
    }
private:
    std::string m_passengerName { "Unknown Passenger" };
    int m_numberOfMiles { 0 };
    bool m_hasEliteSuperRewardsStatus { false };
};
```

**using class**
the code that uses the class called the client code, to define a class, includes the header file.

```cpp
#include "16oop.cpp"
int main() {
    AirlineTicket myTicket;
    myTicket.setPassengerName("Ziad Assem");
    myTicket.setNumberOfMiles(700);
    double cost { myTicket.calculatePriceInDollars() };
    std::cout<<"This ticket will cost " <<cost;;
    return 0;
}
```

### 17- Scope Resolution
As a C++ programmer, you need to familiarize yourself with the concept of a scope, which defines where an item is visible. Every name in your program, including variable, function, and class names,
is in a certain scope. You create scopes with 
* namespaces 
* function definitions
* blocks delimited by curly braces 
* class definitions

Variables that are initialized in the initialization statement of for
loops and range-based for loops are scoped to that for loop and are not visible outside the for loop.
Similarly, variables initialized in an initializer for if or switch statements are scoped to that if or switch statement and are not visible outside that statement.

on accessing a variable, function, or class, the name is first looked up in the nearest enclosing scope, then the parent scope, and so forth, up to the global scope. Any name not in a namespace, function, block delimited by curly braces, or class is assumed to be in the global scope. If it is not found in the global scope, at that point the
the compiler generates an undefined symbol error.

Sometimes names in scopes hide identical names in other scopes. Other times, the scope you want is not part of the default scope resolution from that particular line in the program. If you don’t want the
default scope resolution for a name, you can qualify the name with a specific scope using the scope
resolution operator::. 

```cpp
class Demo
{
public:
int get() { return 5; }
};
int get() { return 10; }
namespace NS
{
int get() { return 20; }
}
```

The global scope is unnamed, but you can access it specifically by using the scope resolution operator by itself (with no name prefix). The different get() functions can be called as follows. In this example, the code itself is in the main() function, which is always in the global scope:

```cpp
int main()
{
    Demo d;
    println("{}", d.get()); // prints 5
    println("{}", NS::get()); // prints 20
    println("{}", ::get()); // prints 10
    println("{}", get()); // prints 10
}
```

**unnamed namespace and the global namespace**
If the earlier namespace called NS is defined as an unnamed /anonymous namespace, that is, a namespace without a name as follows:
```cpp
namespace
{
int get() { return 20; }
}
```
then the following line will cause a compilation error about ambiguous name resolution because you would have a `get()` defined in the global scope, and another `get()` defined in the unnamed
namespace.

```cpp
std::cout<< get();
```

The same error occurs if you add the following using a directive right before the main() function:
```cpp
using namespace NS;
```

### 18- Uniform Initialization

Before C++11, the initialization of types was not always uniform. For example, the definitions of a structure, a class, and variables are different. the uniform initialization provides a consistent syntax for initializing different types of objects. in addition to that uniform initialization provides more advantages that will be discussed in this section:

* it provides a consistent syntax for initializing different types of objects
* it performs zero-initialization of variables;by just specifying an
empty set of curly braces
* it prevents narrowing
* initializer to initialize arrays that are members of a class

**consistent syntax for initializing different types of objects**
take the following definitions of a circle, once as a structure, and once as a class:

```cpp
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
```

before uniform initialization, the initialization of a variable of type CircleStruct, a variable of type CircleClass, and an array looked different:
```cpp
CircleStruct myCircle1 = { 10, 10, 2.5 };
CircleClass myCircle2(10, 10, 2.5);
int arr[] = {0,1};
```

after uniform initialization, initialization of a variable of type Circle struct, a variable of type CircleClass, and an array are the same.
```cpp
    CircleStruct myCircle5 { 10, 10, 2.5 };
    CircleClass myCircle6 { 10, 10, 2.5 };
    int arr[] {1,2,3};
```
Uniform initialization is not limited to structures and classes. You can use it to initialize almost anything in C++. For example, the following code initializes all four variables with the value 3:

```cpp
int a = 3;
int b(3);
int c = { 3 }; // Uniform initialization
int d { 3 }; // Uniform initialization
```

**zero-initialization of variables**
Uniform initialization can be used to perform zero-initialization of variables; you just specify an
empty set of curly braces, as shown here:
```cpp
int e { }; // Uniform initialization, e will be 0
```
This syntax can also be used with structures. If you create an instance of the Employee struct as follows, then its data members are default initialized, which, for primitive types such as char and int, means they’ll contain whatever random data is left in memory.
However, if you create the instance as follows, then all data members are zero-initialized:

```cpp
int main(){
    CircleStruct zerosCircle {};
    std::cout<<zerosCircle.x << " "<<zerosCircle.y <<" " << zerosCircle.radius <<"\n";

    CircleStruct randomCircle ;
    std::cout<<randomCircle.x << " "<<randomCircle.y <<" " << randomCircle.radius <<"\n";

}
```

```bash
0 0 0
-1732831152 32758 6.95136e-310
```
**prevents narrowing**
A benefit of using uniform initialization is that it prevents narrowing. When using the old-style assignment syntax to initialize variables, C++ implicitly performs narrowing, as shown here:
```cpp
int main()
{
    int x = 3.14;
}
```

For the statement in main(), C++ automatically truncates 3.14 to 3 before assigning it to x. Some compilers might issue a warning about this narrowing, while others won’t. In any case, narrowing
conversions **should not go unnoticed, as they might cause subtle or not-so-subtle bugs**.

With uniform initialization, the assignment to x must generate a compilation error if your compiler fully conforms
to the C++11 standard:
```cpp
int main(){
    int b {3.14}; //error   
}
```
type 'double' cannot be narrowed to 'int' in the initializer list [-Wc++11-narrowing].

**initializer to initialize arrays that are members of a class**
```cpp
class MyClass
{
public:
MyClass()
: m_array { 0, 1, 2, 3 }
{
}
private:
int m_array[4];
};
```
Uniform initialization can be used with the Standard Library containers as well—such as `std::vector`, already demonstrated earlier in this Readme.

### 19- Designated Initializers
Designated initializers initialize data members of aggregates using their name (c++20). 

An aggregate type is
* an object of an array type
* an object of a structure 
* a class that satisfies the following restrictions:
  * public data members
  * no user-declared or inherited constructors, no virtual functions (discussed later in chapter 10 in the book), and no virtual, private, or protected base classes (see Chapter 10).

A designated initializer starts with a dot followed by the name of a data member. 

Let’s take a look at a slightly modified Employee structure. This time the salary data member has a default value of 75,000.
```cpp
struct Employee {
    char firstInitial;
    char lastInitial;
    int employeeNumber;
    int salary { 75'000 };
};

int main(){
    Employee anEmployee {
        .firstInitial = 'J',
        .lastInitial = 'D',
        .employeeNumber = 42,
        .salary = 80'000
};
}
```

Designated initializers must be in the same order as the declaration order of the data members. Mixing designated initializers and nondesignated initializers is not allowed. Any data members that are not initialized using a designated initializer are initialized with their default values.

```cpp
int main(){
      Employee anEmployee {
        .lastInitial = 'D', //error
        .firstInitial = 'J',
        .employeeNumber = 42,
        .salary = 80'000
    };
}
```

A benefit of using such designated initializers is that it’s much easier to understand what a designated initializer is initializing compared to using the uniform initialization syntax.
With designated initializers, you can skip the initialization of certain members if you are satisfied with their default values.

For example, when creating an employee, you could skip initializing
employeeNumber, in which case employeeNumber is zero-initialized as it doesn’t have an in-class initializer:
```cpp
Employee anEmployee {
.firstInitial = 'J',
.lastInitial = 'D',
.salary = 80'000
};
```
With the uniform initialization syntax, this is not possible, and you have to specify 0 for the employee number as follows:
```cpp
Employee anEmployee { 'J', 'D', 0, 80'000 };
```
If you skip initializing the salary data member as follows, then salary gets its default value, which is its in-class initialization value, 75,000:
```cpp
Employee anEmployee {
.firstInitial = 'J',
.lastInitial = 'D'
};
```
A final benefit of using designated initializers **is that when members are added to the data structure, existing code using designated initializers keeps working. The new data members will just be initialized with their default values**.

