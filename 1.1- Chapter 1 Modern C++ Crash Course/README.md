
# Chapter 1:&nbsp;&nbsp;A Crash Course in C++ and the Standard Library

A disscussion of the topics in this chapter with more information from different resources and more topics are added.

- [1- Headers, Imports, and I/O Streams](#1--headers-imports-and-io-streams)
- [2- Namespaces](#2--namespaces)
- [3- Literals](#3--literals)
- [4- Variables](#4--variables)
- [4- Enumerations](#4--enumerations)
- [5- Structs](#5--structs)
- [6- Conditional Statements and Logical Operators](#6--conditional-statements-and-logical-operators)
- [7- Functions](#7--functions)
- [8- Attributes](#8--attributes)
- [9- C-Style Array, std::array, and vector](#9--c-style-array-stdarray-and-vector)
- [10- std::pair](#10--stdpair)
- [11- std::optional and value_or](#11--stdoptional-and-value_or)
- [12- std::tuple](#12--stdtuple)
- [13-Structured Bindings](#13--structured-bindings)
- [14- Loops](#14--loops)
    - [continue vs break](#continue-vs-break)
    - [The Range-Based for Loop](#the-range-based-for-loop)
- [15- Initializer Lists](#15--initializer-lists)
- [16- C++ as an Object Oriented Language](#16--c-as-an-object-oriented-language)
    - [Defining Classes](#defining-classes)
    - [Constructor and Destructor](#constructor-and-destructor)
    - [Initialize members in constructors](#initialize-members-in-constructors)
    - [Deleting members in destructor](#deleting-members-in-destructor)
    - [Definitions of the class members](#definitions-of-the-class-members)
    - [using class](#using-class)
- [17- Scope Resolution](#17--scope-resolution)
    - [unnamed namespace and the global namespace](#unnamed-namespace-and-the-global-namespace)
- [18- Uniform Initialization](#18--uniform-initialization)
    - [consistent syntax for initializing different types of objects](#consistent-syntax-for-initializing-different-types-of-objects)
    - [zero-initialization of variables](#zeroinitialization-of-variables)
    - [prevents narrowing](#prevents-narrowing)
    - [initializer to initialize arrays that are members of a class](#initializer-to-initialize-arrays-that-are-members-of-a-class)
- [19- Designated Initializers](#19--designated-initializers)
- [20- Pointers and Dynamic Memory](#20--pointers-and-dynamic-memory)
    - [Stack](#stack)
    - [Free Store/Heap](#free-storeheap)
    - [Working with Pointers](#working-with-pointers)
    - [Null Pointers and nullptr](#null-pointers-and-nullptr)
    - [Memory Allocation in C++ using new](#memory-allocation-in-c-using-new)
    - [Dereferencing a struct or a class](#dereferencing-a-struct-or-a-class)
    - [Dynamically Allocated Arrays](#dynamically-allocated-arrays)
    - [new/delete instead of malloc()/free()](#newdelete-instead-of-mallocfree)
- [21- The Use of const](#21--the-use-of-const)
    - [const as a Qualifier for a Type](#const-as-a-qualifier-for-a-type)
    - [const with Pointers](#const-with-pointers)
    - [const to Protect Parameters](#const-to-protect-parameters)
    - [const Member Functions](#const-member-functions)
- [22- References](#22--references)
    - [Reference Variables](#reference-variables)
    - [Reference Variables; References to a const variable](#reference-variables-references-to-a-const-variable)   
    - [Reference Variables; References to Pointers and Pointers to References](#reference-variables-references-to-pointers-and-pointers-to-references)
    - [Reference Variables; Structured Bindings and References](#reference-variables-structured-bindings-and-references)
    - [Reference Data Members](#reference-data-members)
    - [Reference Parameters](#reference-parameters)
    - [Reference Parameters; Pass-by-Reference-to-const](#reference-parameters-passbyreferencetoconst)
    - [Reference Return Values](#reference-return-values)
    - [Deciding Between References and Pointers](#deciding-between-references-and-pointers)
    - [Does Reference take memory? the Disassembly will answer](#does-reference-take-memory-the-disassembly-will-answer)
    - [How Does reference to rValue/const ref works on Assembly Level](#how-does-reference-to-rvalueconst-ref-works-on-assembly-level)
- [23- const_cast()](#23--constcast)
    - [casting away constness](#casting-away-constness)
    - [change non const class members inside a const member function](#change-non-const-class-members-inside-a-const-member-function)
- [24- Exceptions](#24--exceptions)
    - [Syntex of try-catch](#syntex-of-trycatch)
    - [The Flow of the try-catch block](#the-flow-of-the-trycatch-block)
- [25- Type Aliases](#25--type-aliases)
- [26- typedefs](#26--typedefs)
- [27- Type Inference](#27--type-inference)
    - [The auto Keyword](#the-auto-keyword)
    - [The auto Keyword; The auto& Syntax](#the-auto-keyword-the-auto-syntax)
    - [The auto Keyword; The auto* Syntax](#the-auto-keyword-the-auto-syntax)
    - [The auto Keyword; Copy List vs. Direct List Initialization](#the-auto-keyword-copy-list-vs-direct-list-initialization)
    - [The decltype Keyword](#the-decltype-keyword)
- [28- The Standard Library](#28--the-standard-library)              

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

### 11- std::optional and value_or
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

### 12- std::tuple
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

### 13- Structured Bindings
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

#### continue vs break

The keyword **break** can be used within a loop to immediately get out of the loop and resume execution of the program starting at the line of code following the loop.

The keyword **continue** can be used to return to the top of the loop and reevaluate the while expression. However, using continue
in loops is often considered **poor style because it causes the execution of a program to jump around somewhat haphazardly**, so use it sparingly.

#### The Range-Based for Loop

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

### 16- C++ as an Object Oriented Language
If you are a C programmer, you may have viewed the features covered so far in this chapter as convenient additions to the C language. As the name C++ implies, in many ways the language is just a “better C.” There is one major point that this view overlooks: unlike C, C++ is an object-oriented language. Object-oriented programming (OOP) is a different, arguably more natural, way to write code. 
OOP is a big interesting topic with theories, concepts, and best practices independent of a programming language (i.e. the concepts can be applied to any programming language that supports OOP). hence it can't be covered in just a section of a summary of a chapter, but it will be covered further in another chapter (Chapter 5, “Designing with Classes,”  in the book), also in the practice part of this chapter (`Practice-part Chapter 1; YOUR FIRST BIGGER C++ PROGRAM`) an OOP project is introduced and explained.
this section is intended to show basic C++ object syntax if you already know the theory of OOP.

#### Defining Classes

A class defines the characteristics of an object. In modern C++, classes are usually defined and exported from a module interface file (.cppm), while their definitions can either be directly in the same module interface file or in a corresponding module implementation file (.cpp). or in defined in a header file and implemented in .cpp files.
A basic class definition for an airline ticket class is shown in the following example. The class can calculate the price of the ticket based on the number of miles on the flight and whether the customer is a member of the Elite Super Rewards Program.

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

#### Constructor and Destructor

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

#### Initialize members in constructors
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


#### Deleting members in destructor

Destructors are required if you need to perform some cleanup,
such as closing files, and freeing memory but usually destructor doesn’t do anything and can simply be removed from this class unless what is mentioned.

in our case, we don't have pointers or opened files, so we can write an empty destructor.

```cpp
AirlineTicket::~AirlineTicket()
{
// Nothing to do in terms of cleanup
}
```

#### Definitions of the class members
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

#### using class
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

#### unnamed namespace and the global namespace
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

#### consistent syntax for initializing different types of objects
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

#### zero-initialization of variables
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
#### prevents narrowing
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

#### initializer to initialize arrays that are members of a class
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


### 20- Pointers and Dynamic Memory
before understanding pointers, let's introduce how does memory is organized in a C++ program. Memory in a C++ program is divided into two parts the stack and the free store (heap). 

#### Stack

One way to visualize the stack is as a
deck of cards. The current top card represents the current scope of the program, usually the function that is currently being executed. All variables declared inside the current function will take up memory in the top stack frame, the top card of the deck. If the current function, for example, `foo()`, calls another function `bar()`, a new card (stack frame) is put on the deck so that `bar()` has its own stack frame to work with. Any parameters passed from `foo()` to `bar()` are copied from the `foo()` stack frame into the `bar()` stack frame.

Stack frames are nice because they provide an isolated memory workspace for each function. If a variable is declared inside the `foo()` stack frame, calling the `bar()` function won’t change it unless you specifically tell it to. Also, when the `foo()` function finishes its execution (i.e. reaches its end), the stack frame is removed from the memory with all of the variables declared within the function.

Variables that are stackallocated do not need to be deallocated (deleted) by the programmer; since it happens automatically.


#### Free Store/Heap
The free store is an area of memory that is completely independent of the current function or stack frame. You can put variables on the free store if you want them to exist even when the function in which they were created has finished its execution and been removed from the memory. 

The free store is less structured than the stack. You can think of it as just a collection of bits. Your program can add new bits to this collection at any time or modify bits that are already in this collection. 

unlike stack frames, You have to make sure that you deallocate (delete) any memory that you allocated on the free store. This does not happen automatically unless you use **smart pointers**, which are discussed later in the book in Chapter 7, “Memory Management.


#### Working with Pointers
**WARNING** *Pointers are introduced here because you will encounter them, especially in legacy code bases. In the new code, however, such raw/naked pointers are allowed only if there is no ownership involved. Otherwise, you should use one of the smart pointers.*

You can put anything on the free store by explicitly allocating memory for it. For example, to put an
integer on the free store, you need to allocate memory for it, but first you need to declare a pointer:

```cpp
int* myIntegerPointer;
```
the declared pointer does not yet point to anything specific because it is not assigned to anything; it is an uninitialized variable. Hence it has a random memory address. Working with such pointers will most likely make your program crash. since you don't know where it points and where it will go hence its name is **Wild Pointer**, That’s why you should always declare and initialize your pointers at the same time! You can initialize them to a null pointer (`nullptr`) if you don’t want to allocate memory.

```cpp
int* myIntegerPointer { nullptr };
```

#### Null Pointers and nullptr
A null pointer is a special default value that no valid pointer will ever have and converts to false when used in a Boolean expression. Here’s an example:
```cpp
if (!myIntegerPointer) { /* myIntegerPointer is a null pointer. */ }
```

`nullptr` replaced the legacy `NULL` macro  in C, since both of them can be used in C++ but it is advised to use nullptr for the following reasons:
* NULL is typically defined as (void *)0 and conversion of NULL to integral types is allowed. So it may cause calling some functions to be ambiguous such as the following:

```cpp
// C++ program to demonstrate the problem with NULL
#include <bits/stdc++.h>
using namespace std;

// function with integer argument
void fun(int N)   { cout << "fun(int)"; return;}

// Overloaded function with char pointer argument
void fun(char* s)  { cout << "fun(char *)"; return;}

int main() 
{
 // Ideally, it should have called fun(char *),
 // but it causes a compiler error.
    fun(NULL);  
}
```
since the NULL macro is `0`, it can be considered as integer `0` not only a null pointer, hence it can invoke `void fun(int N) ` and `void fun(char* s)`, although it should invoke `void fun(char* s)` only. hence the error of ambiguity is issued.


In the above program, if  NULL is replaced with nullptr, the output will be
```
fun(char *)
```

* nullptr is convertible to bool, so a pointer can be checked before dereferencing via if-condition

nullptr is a keyword that can be used at all places where NULL is expected. Like NULL, nullptr is implicitly convertible and comparable to any pointer type. Unlike NULL, it is not implicitly convertible or comparable to integral types.

nullptr is a [prvalue](https://stackoverflow.com/questions/3601602/what-are-rvalues-lvalues-xvalues-glvalues-and-prvalues) of type nullptr_t that converts integral literal to 0 while the typecast of NULL is (void *)0 whose integer constant is 0.

#### Memory Allocation in C++ using new

You use the `new` operator to allocate the memory:
```cpp
myIntegerPointer = new int;
```

In this case, the pointer points to the address of just a single integer value. To access this value, you need to dereference the pointer. Think of dereferencing as following the pointer’s arrow to the actual value on the free store. To set the value of the newly allocated free store integer, you would use code like the following:

```cpp
*myIntegerPointer = 8;
```

After you are finished with your dynamically allocated memory, you need to deallocate the memory using the delete operator. To prevent the pointer from being used after having deallocated the memory it points to, it’s recommended to set it to nullptr, or it will point to freed memory as it will dangling, hence it will be called a dangling pointer.

```cpp
delete myIntegerPointer;
myIntegerPointer = nullptr;
```

**WARNING** *A pointer must be valid before it is dereferenced Dereferencing a null pointer or an uninitialized pointer causes undefined behavior. Your program might crash, but it might just as well keep running and start giving strange results.*

Pointers don’t always point to free-store memory. You can declare a pointer that points to a variable on the stack, even another pointer. To get a pointer to a variable, you use the & (“address
of”) operator:
```cpp
int i { 8 };
int* myIntegerPointer { &i }; // Points to the variable with the value 8
```

#### Dereferencing a struct or a class

C++ has a special syntax for dealing with pointers to structures or classes. Technically, if you have a pointer to a structure or a class, you can access its fields by first dereferencing it with *, and then
using the normal `.` syntax, as in the code that follows. This code snippet also demonstrates how to dynamically allocate and deallocate an Employee instance.
```cpp
Employee* anEmployee { new Employee { 'J', 'D', 42, 80'000 } };
cout<<(*anEmployee).salary;
delete anEmployee;
anEmployee = nullptr;
```
This syntax is a little messy. The `->` (arrow) operator lets you perform both the dereference and the field access in one step. The following statement is equivalent to the previous cout call but is easier to read:
```cpp
cout<<anEmployee->salary;
```
Remember the concept of short-circuiting logic, discussed earlier in this chapter? This can be useful in combination with pointers to avoid using an **invalid pointer**, as in the following example:
```cpp
bool isValidSalary { anEmployee && anEmployee->salary > 0 }; //anEmployee is dereferenced to get the salary only if it is a valid pointer. 
//or to be more verbose
bool isValidSalary { anEmployee != nullptr && anEmployee->salary > 0 };
```

#### Dynamically Allocated Arrays
The free store can also be used to dynamically allocate arrays. You use the `new[]` operator to allocate memory for an array.
```cpp
int arraySize { 8 };
int* myVariableSizedArray { new int[arraySize] };
```

This allocates enough memory to hold arraySize integers. the pointer variable will reside on the stack, but the array that was dynamically created will live on the free store. Now that the memory has been allocated, you can work with `myVariableSizedArray` as though it
were a regular stack-based array:
```cpp
myVariableSizedArray[3] = 2;
```

When your code is done with the array, it should remove the array from the free store so that other variables can use the memory. In C++, you use the `delete[]` operator to do this:
```cpp
delete[] myVariableSizedArray;
myVariableSizedArray = nullptr;
```
The brackets after delete indicate that the delete keyword will delete an array.

#### new/delete instead of malloc()/free()
If you do need dynamically allocated memory, avoid using malloc() and free() from C. Instead, use new and delete, or new[] and delete[] from C++. However, in modern C++, the goal is to avoid new, delete, new[], and delete[] altogether, and use more modern constructs such as Standard Library containers, e.g., std::vector, and smart pointers.

**why to use new/delete instead of malloc()/free()**

* new and delete are built into C++ and take advantage of all C++ features. malloc() and free() are just function calls.

* malloc() just returns some bytes. It doesn’t set them to any particular value. If you want to put a class instance into the bytes, you have to call the constructor explicitly, which is what new does.

* free() doesn’t destroy objects. delete does.

* malloc() sometimes returns nullptr, which the program then has to handle, but this happens so infrequently that many programs don’t bother, leading to a crash at run time. new throws an exception, which allows the program to clean up before exiting. If you are suspicious of exception handling for some reason, there is a variant of new that returns nullptr.

* The behavior of new can be overridden for specific types, to implement special (like more efficient) allocation strategies for heavily used object types. new can also be overridden globally. You can link in your custom malloc(), but it changes the behavior of every allocation, which is less useful.

[source](https://www.quora.com/Why-is-using-malloc-or-its-relatives-considered-bad-in-modern-C)


**WARNING** *To prevent memory leaks, every call to new should be paired with a call to delete, and every call to new[] should be paired with a call to delete[]. Not calling delete or delete[], or mismatching calls, results in memory leaks or worse.*

### 21- The Use of const
const keyword has different usages in C++, it will be discussed in this section.
#### const as a Qualifier for a Type
the keyword const for a variable prevents this variable from being modified. In C, programmers often use the preprocessor `#define` to declare symbolic names for values that won’t change during the execution of the program, such as the **version number**. In C++, programmers are encouraged to avoid #define in favor of using const to define constants. 

The big advantage of `const` over `#define` is type checking. `#defines` can't be type-checked, so this can cause problems when trying to determine the data type. If the variable is, instead, a constant then we can grab the type of data that is stored in that constant variable.

Defining a constant with const is just like defining a variable, except that the compiler guarantees that the code cannot change the value. Here are some examples:

```cpp
const int versionNumberMajor { 2 };
const int versionNumberMinor { 1 };
const std::string productName { "Super Hyper Net Modulator" };
const double PI { 3.141592653589793238462 };
```

You can mark any variable const, including global variables and class data members.

#### const with Pointers

When a variable contains one or more levels of indirection via a pointer, applying const becomes
trickier. Consider the following lines of code:
```cpp
int* ip;
ip = new int[10];
ip[4] = 5;
```
Suppose that you decide to apply const to ip. consider what it means. 
* Do you want to prevent the ip variable itself from being changed 
* Do you want to prevent the values to which it points from being changed

```cpp
int* const ip {nullptr}
ip = new int[10];
ip[4] = 5; 
```

for example, the previous code implies which statement, is it the first or the second? to figure out this complicated variable declaration here is an easy-to-remember rule:

> Read from right to left. For example, int* const ip reads from
right to left as “ip is a const pointer to an int.” Further, int const* ip reads as "ip is a pointer to a const int," and const int* ip reads as “ip is a pointer to an int constant.

hence the previous example will issue a compilation error on the second line

```cpp
int* const ip {nullptr}
ip = new int[10];// DOES NOT COMPILE!
ip[4] = 5; // Error: dereferencing a null pointer
```

```cpp
const int* ip;
ip = new int[10];
ip[4] = 5; // DOES NOT COMPILE!
```
it reads as a pointer to constant int so the third line (changing the pointee) will issue a compilation error.

```cpp
int const* ip;
ip = new int[10];
ip[4] = 5; // DOES NOT COMPILE!
```
Putting the const before or after the int makes no difference in its functionality.

```cpp
int const* const ip { nullptr };
```
const pointer to constant int pointee.


```cpp
const int * const * const * const ip { nullptr };
```

declares ip as a constant pointer to a constant pointer to a constant pointer to a constant integer, and initializes ip to nullptr. This means ip itself and all levels of pointers it eventually points to are constant and cannot be changed.


#### const to Protect Parameters

In C++, you can cast a non-const variable to a const variable. Why would you want to do this? It offers some degree of protection from other code changing the variable. If you are calling a function that a co-worker of yours is writing and you want to ensure that the function doesn’t change
the value of an argument you pass in, you can tell your co-worker to have the function take a const parameter. If the function attempts to change the value of the parameter, it will not compile (i.e. to protect the passed parameter by reference from being edited).
In the following code, a string* is automatically cast to a const string* in the call to mysteryFunction(). If the author of mysteryFunction() attempts to change the value of the passed string, the code will not compile. There are ways around this restriction, but using them requires conscious effort. C++ only protects against accidentally changing const variables.
```cpp
void mysteryFunction(const string* someString)
{
*someString = "Test"; // Will not compile
}
int main()
{
string myString { "The string" };
mysteryFunction(&myString); // &myString is a string*
}
```
also use const can be used on primitive-type parameters to prevent accidentally changing them in the body of the function. For example, the following function has a const integer parameter. In the body of the function, you cannot modify the param integer. If you do try to modify it, the compiler will generate an error.
```cpp
void func(const int param) { /* Not allowed to change param... */ }
```

#### const Member Functions
A second use of the const keyword is to mark class member functions as const, preventing them from modifying data members of the class. for example the member size in a vector, or the length in a string.

The AirlineTicket class introduced earlier can be modified to mark all read-only member functions as const. The const must be added to both the member function declaration and its definition. If any const member function tries to modify one of the AirlineTicket data members, the compiler will emit an error.

```cpp
class AirlineTicket
{
public:
    double calculatePriceInDollars() const;
    std::string getPassengerName() const;
    void setPassengerName(std::string name);
    int getNumberOfMiles() const;
    void setNumberOfMiles(int miles);
    bool hasEliteSuperRewardsStatus() const;
    void setHasEliteSuperRewardsStatus(bool status);
    private:
    std::string m_passengerName { "Unknown Passenger" };
    int m_numberOfMiles { 0 };
    bool m_hasEliteSuperRewardsStatus { false };
};

std::string AirlineTicket::getPassengerName() const
{
return m_passengerName;
}
....
```



### 22- References

A reference in C++ is an alias for another variable. All modifications to the reference change the value of the
variable to which it refers. a reference can be viewed as an implicit constant pointer that saves the trouble of taking the address of variables and dereferencing the pointer. or, references can be viewed as just another name for the original variable. 

references can be created to the following: 
* reference to variables
* reference to  data members in classes
* references to parameter to a function
* reference to a return from a function

every stated point will be discussed in detail in this section.

#### Reference Variables

```cpp
int x { 3 };
int& xRef { x };
```

defeniation of `xRef` with `int&` identifier and assigning it to `x`, means that xRef is another name of x, every action executed on x/xRef will be executed on xRef/x.

```cpp
x = 5 ;
xRef = 12 ;
std::cout << x  ;// 12
x = 5 ;
std::cout << xRef  ;// 5
```
Attaching `&` to a type (e.g. `int`) indicates that the variable is a reference.


Reference variables must be initialized as soon as they are created, like this:

```cpp
int main(){
    int a {4};
    int& aRef ;
}
```
```
declaration of reference variable 'aRef' requires an initializer
```
so **A reference variable must always be initialized when it’s created.**

**Modifying References**
**can a reference variable reference to another variable after being assigned?** References cannot be changed once they are created. If you assign a variable to a reference when the reference is declared, the reference refers to that variable. However, if you assign a variable to a reference after that, the variable to which the reference refers is changed to the value of the variable being assigned. you can think when calling a reference as doing implicit dereferencing.

```cpp
int x { 3 }, y { 4 };
int& xRef { x };
xRef = y; // Changes value of x to 4. Doesn't make xRef refer to y.
```

does the following work?
```cpp
 xRef = &y;
```
**no**, because you are dereferencing an int (xRef) and setting an address to int, so **it will not compile**.

does the following make zRef reference to xRef?

```cpp
int x { 3 }, z { 5 };
int& xRef { x };
int& zRef { z };
zRef = xRef;
```

**no**, dereferencing zRef and setting the value to dereferenced xRef, so this operation just Assigns values, not references.

so we can state that **Once a reference is initialized to refer to a specific variable, you cannot change the reference to refer to another variable; you can change only the value of the variable the reference refers to**.

#### Reference Variables; References to a const variable

const applied to references is usually easier than const applied to pointers for two reasons. 
* references are const by default, in that, you can’t change to what they refer. So, there is no need to mark them const explicitly
* you can’t create a reference to a reference, so there is usually only one level of indirection with references. The only way to get multiple levels of indirection is to create a reference to a pointer

Thus reference-to-const in C++, means something like this:
```cpp
int z;
const int& zRef { z };
z = 181 ; 
zRef = 198; // DOES NOT COMPILE
```
By applying const to the int&, the `zRef` became constant not the referenced `z`, hence prevention of assignment to `zRef `not to `z`. 

**reference to an unnamed value**

You cannot create a reference to an unnamed value, such as an integer literal unless the reference is to a const value. since an unnamed value is not a container (i.e. a const value), then reference to the unnamed value should be constant. 

```cpp
int& unnamedRef1 { 5 }; // DOES NOT COMPILE
const int& unnamedRef2 { 5 }; // Works as expected
```

also, you can create a reference to rvalue by adding `&&` after the identifier as follows:
```cpp
int&& xRef {5};
xRef = 6 ;
```

unnamed values can be the values returned by a function as follows:

```cpp
string getString() { return "Hello world!"; }
```

```cpp
string& string1 { getString() }; // DOES NOT COMPILE
const string& string2 { getString() }; // Works as expected
string&& string2 {getString()}; //Works as expected
```

Conceptually, an rvalue expression (unnamed value) creates a temporary object. then it is referenced by the initialized reference. so it creates a reference to unnamed values and creates two objects; the value and the reference.

#### Reference Variables; References to Pointers and Pointers to References

You can create references to any type, including pointer types. Here is an example of a reference to a
pointer to int:

```cpp
int* intP { nullptr };
int*& ptrRef { intP };
ptrRef = new int;
*ptrRef = 5;
delete ptrRef; ptrRef = nullptr;
```

the `int*& ptrRef { intP };` expression may be strange, but it is similar to defining a reference to any data type. `&` references to `int*`.

#### Reference Variables; Structured Bindings and References

```cpp
auto& [theString, theInt] { myPair }; // Decompose into references-to-non-const
const auto& [theString, theInt] { myPair }; // Decompose into references-to-const
```


#### Reference Data Members

as referencing regular variables we can reference data members, however, a reference must be initialized with a value, and data members are usually initialized within the body of the constructor. this issue that prevents the definition of references in a class can be solved by initializing the reference in the constructor initializer.

```cpp
class MyClass
{
public:
    MyClass(int& ref) : m_ref { ref } { /* Body of constructor */ }
private:
    int& m_ref;
};
```

```cpp
class MyClass //error: constructor for 'MyClass' must explicitly initialize the reference member 'm_ref'
{
public:
    MyClass(int& ref) {  m_ref = ref ;  }
private:
    int& m_ref;
};
```

#### Reference Parameters
using stand-alone reference variables or reference data members are not often used. however, The most common use of references is for parameters to functions. The default parameter-passing semantics is pass-by-value: functions receive copies of their arguments. When those parameters are modified, the original arguments remain unchanged. Pointers to stack variables are often used in C to allow functions to modify variables in other stack frames/other local variables. By dereferencing the pointer, the function can change the memory that represents the variable even though that variable isn’t in the current stack frame. The problem with this approach is that it brings the messiness of pointer syntax into
what is really a simple task. the following example shows the potential bugs that may come to action due to the messiness of pointer syntax.

in the following example it is required to increment the passed variable, so passing a pointer approach is used.
```cpp
void addOne(int* i)
{
 (*i) ++; //dereference the variable then increment it
}

int main(){
    int val {0};
    int* i {&val} ;

    addOne(i); 
    std::cout << val << "\n"; //1
    return 0;

}
```

this is a correct syntax, but what if a developer forgets the brackets:

```cpp
void addOne2(int* i)
{
 *(i)++ ;  
 //increment the copy of the pointer then dereference the new place, without doing anything to it, hence the compiler 
 //issues a warning: expression result unused
   
}
int main(){
    int val {0};
    int* i {&val} ;
    addOne1(i); 
    std::cout << val << "\n"; //0
}

```

or the developer put the brackets in the wrong place:

```cpp
void addOne2(int* i)
{
 *(i)++ ;  
 //increment the copy of the pointer then dereference the new place, without doing anything to it, hence the compiler 
 //issues a warning: expression result unused
   
}

int main(){
    int val {0};
    int* i {&val} ;
    addOne2(i); 
    std::cout << val << "\n"; //0
}
```

all of these potential errors make the task of modifying the original variable a complex task, to make it an easier task using the **pass-by-reference** mechanism.

Instead of passing pointers to functions, C++ offers a better mechanism, called pass-by-reference, where parameters are references instead of pointers. The following are implementations of an addOne() function. One is passing by value, passing by reference.

PASS BY VALUE
```cpp
void addOne(int i)
{
 i++; // Has no real effect because this is a copy of the original
}
```

PASS BY REFERENCE
```cpp
void addOne(int& i)
{
 i++; // Actually changes the original variable
}
```

```cpp
int main(){
    int myInt { 7 };
    addOne(myInt); //calls pass by reference
 //myInt = 8
}
```

A potential problem may arise when you have a pointer to something that you need to pass to a function that takes a reference. 
```cpp
int main(){
    int myInt { 7 };
    int* myPtr = &myInt;
    addOne(myPtr); //error, requires a reference to int
    return 0
}
```

You can “convert” a pointer to a reference in this case by dereferencing the pointer. This action gives you the value to which the pointer points, which the compiler then uses to
initialize the reference parameter. 

```cpp
int main(){
    int myInt { 7 };
    int* myPtr = &myInt;
    addOne(*myPtr); //convert pointer to reference
    return 0
}
```

**pass by reference instead of return**
if you have a function that needs to return an object of a class that is expensive to copy, or you want a function to return more than output you’ll often see the function accepting output parameters of type reference-to-non-const to such a class that the function then modifies, instead of directly returning such an object.
```cpp
#include <iostream>

//not recommended to create a function that performs two operations
void sumanddiff(int a, int b, int& sum, int& diff){
 sum = a+b ;
 diff = a-b ;
}


int main(){
    int a = 10, b = 5, sum, diff;
    sumanddiff(a, b, sum, diff);
    std::cout << "Sum: " << sum << "\n"; //15
     std::cout << "Difference: " << diff<< "\n"; //5
    return 0;
}
```

```
Sum: 15
Difference: 5
```
Developers thought that
this was the recommended way to prevent any performance penalties for creating copies when returning objects from functions. However, even back then, compilers were usually smart enough to avoid any redundant copies. So, we have the following rule:

> The recommended way to return objects from a function is to return them by value, instead of using output parameters.


#### Reference Parameters; Pass-by-Reference-to-const

The main purpose of using references is efficiency in passing parameters to function. When you pass a value into a function, an entire copy is made. When you pass a reference, you are really just passing a pointer to the original so the computer doesn’t need to make a copy. By passing a **reference-to-const**, you get the best of both worlds: no copy is made, and the original variable cannot be changed. References-toconst become more important when you are dealing with objects because they can be large and making copies of them can have unwanted side effects. 
The following example shows how to pass an `std::string` to a function as a reference-to-const:
```cpp
include <iostream>

void printString(const std::string& myString) { cout<< myString; }
int main()
{
    std::string someString { "Hello World" };
    printString(someString);
    printString("Hello World"); // Passing literals works.
}
```

**Pass-by-Reference vs. Pass-by-Value**

Pass-by-reference is required when you want to modify the parameter and see those changes reflected in the variable passed to the function. However, you should not limit your use of pass-by-reference to only those cases. Pass-by-reference avoids copying the arguments to the function, providing two additional benefits:
* Efficiency: Large objects could take a long time to copy. Pass-by-reference passes only a reference to the object into the function
* Support: Not all classes allow pass-by-value

If you want to leverage these benefits but do not want to allow the original objects to be modified, **you should mark the parameters const, giving you pass-by-reference-to-const**.

**NOTE** *as passing by reference prevents making a copy of the passed parameter, for simple built-in types such as int and double you don’t need to modify the arguments you can pass it by value instead of creating a new reference*.

#### Reference Return Values

You can return a reference from a function. Of course, you can use this technique only if the variable to which the returned reference refers continues to exist following the function termination. however, never return a reference to a variable that is locally scoped to that function since it will get destroyed when the function ends.

From the main reasons to return a reference from a function are: 
* if you want to be able to assign to the return value
directly as an lvalue (the left-hand side of an assignment statement). Several overloaded operators commonly return references, such as operators =, +=, and so on
* if the return type is expensive to copy. By returning a reference or reference-to-const, the copying is avoided, but keep the earlier warning in mind. This is often used to return objects by reference-to-const from class member functions

#### Deciding Between References and Pointers

References in C++ could be considered redundant: everything you can do with references, you can accomplish with pointers, However, References make your programs cleaner and easier to understand. They are also safer than pointers: it’s impossible to have a null reference, and you don’t explicitly dereference references, so you can’t encounter any of the dereferencing errors associated with pointers.

there are some use cases where pointers can be used instead of references:
* when you need to change the location to which it points. since reference can't change what it references to
* when the pointer is optional, that is when it can be nullptr

in the legacy code, a way to distinguish between appropriate use of pointers and references was to consider who owns the memory. If the code receiving the variable became the owner and thus became responsible for releasing the memory associated with an object, it had to receive a pointer to the object. If the code receiving the variable didn’t have
to free the memory, it received a reference. however, **nowadays** it is advised to Prefer references over pointers; that is, use a pointer only if a reference is not possible.

**Function with pointers vs Function with references**

Consider a function that splits an array of ints into two arrays: one of even numbers and one of odd numbers. The function doesn’t know how many numbers in the source array will be even or odd, so it should dynamically allocate the memory for the destination arrays after examining the source array. It should also return the sizes of the two new arrays. Altogether, there are four items to return: pointers to the two new arrays and the sizes of the two new arrays. recalling that if a function should return more than a value use pass-by-reference so we will use pass-by-reference.



```cpp
void separateOddsAndEvens(const int arr[], size_t size, int** odds, size_t* numOdds, int** evens, size_t* numEvens)
{
```
since passing an array should pass the first element as a pointer so int* odds and int* evens, and since we pass by pointer so we will pass a pointer to pointer to evens and odds  `int** odds` and `int** evens`, same for size instead of returning multiple outputs we will use pointers, hence the arguments of the output will be `int** odds, size_t* numOdds, int** evens, size_t* numEvens`.

```cpp
void separateOddsAndEvens(const int arr[], size_t size, int** odds, size_t* numOdds, int** evens, size_t* numEvens)
{

 // Count the number of odds and evens (dereference).
 *numOdds = *numEvens = 0;
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] % 2 == 1) {
 ++(*numOdds);
 } else {
 ++(*numEvens);
 }
 }
 // Allocate two new arrays of the appropriate size.
 *odds = new int[*numOdds];
 *evens = new int[*numEvens];

 // Copy the odds and evens to the new arrays.
    size_t oddsPos = 0, evensPos = 0;
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] % 2 == 1) {
 (*odds)[oddsPos++] = arr[i];
 } else {
 (*evens)[evensPos++] = arr[i];
 }
 }
}
```

dereference every pointer leads to some ugly syntax in the function body. Additionally, when you want to call separateOddsAndEvens(), you must pass the address of two pointers so that the function can change the actual pointers, and pass the address of two size_ts so that the function can change the actual size_ts. Note **also that the caller is responsible for deleting the two arrays created by separateOddsAndEvens()**!

for using this function:
```cpp
int main(){
    int unSplit[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* oddNums { nullptr };
    int* evenNums { nullptr };
    size_t numOdds { 0 }, numEvens { 0 };
    separateOddsAndEvens(unSplit, std::size(unSplit),
 &oddNums, &numOdds, &evenNums, &numEvens);
 // Use the arrays...
    delete[] oddNums; oddNums = nullptr;
    delete[] evenNums; evenNums = nullptr;
}
```

this syntax of writing the function may introduce some errors in case of being misused, now let's see the same function using references.

```cpp
void separateOddsAndEvens(const int arr[], size_t size, int*& odds,
size_t& numOdds, int*& evens, size_t& numEvens)
{
 numOdds = numEvens = 0;
    for (size_t i { 0 }; i < size; ++i) {
        if (arr[i] % 2 == 1) {
 ++numOdds;
 } else {
 ++numEvens;
 }
 }
 odds = new int[numOdds];
 evens = new int[numEvens];
    size_t oddsPos { 0 }, evensPos { 0 };
    for (size_t i { 0 }; i < size; ++i) {
        if (arr[i] % 2 == 1) {
            odds[oddsPos++] = arr[i];
 } else {
            evens[evensPos++] = arr[i];
 }
 }
}
```

In this case, the odds and evens parameters are references to `int*`s. separateOddsAndEvens() can modify the `int*`s that are used as arguments to the function (through the reference), without any explicit dereferencing. The same logic applies to numOdds and numEvens, which are references to size_ts. With this version of the function, you no longer need to pass the addresses of the pointers or size_ts; the reference parameters handle it for you automatically:

```cpp
separateOddsAndEvens(unSplit, std::size(unSplit),
oddNums, numOdds, evenNums, numEvens);
```

although using reference in dynamic arrays is much cleaner than using pointers, it is recommended to use `vector` where it is much more readable and safer that all memory deallocations occur automatically, hence the version of `separateOddsAndEvens` function with vectors will be:
```cpp
void separateOddsAndEvens(const vector<int>& arr,
vector<int>& odds, vector<int>& evens)
{
    for (int i : arr) {
        if (i % 2 == 1) {
            odds.push_back(i);
 } else {
            evens.push_back(i);
 }
 }
}
```

using it, note there aren't memory allocations and deallocations since it is made automatically by `vector` 
```cpp
vector<int> vecUnSplit { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
vector<int> odds, evens;
separateOddsAndEvens(vecUnSplit, odds, evens);
```

to improve the function it is not advised to pass the output as an input parameter to the function, hence to return two vectors we can encapsulate them in a `struct` as follows:

```cpp
struct OddsAndEvens { vector<int> odds, evens; };
OddsAndEvens separateOddsAndEvens(const vector<int>& arr)
{
 vector<int> odds, evens;
    for (int i : arr) {
        if (i % 2 == 1) {
            odds.push_back(i);
 } else {
            evens.push_back(i);
 }
 }
    return OddsAndEvens { .odds = odds, .evens = evens };
}
```

#### Does Reference take memory?, the Disassembly will answer
How do references work under the hood? Let's use a disassembler to explore their assembly code behavior!

I am using [godbolt](https://godbolt.org/) website, which is an online disassembler tool.

before getting into assembly, some notes should be stated.

1. An instruction in assembly language is a symbolic representation of a single-machine instruction. In its simplest form, an instruction consists of a mnemonic and a list of operands. Additional bytes may affect the action of the instruction or provide information about the data needed by the instruction

2. comments are identified with `;` at its beginning

3. on calling a function in C/C++, it is translated to a **subroutine**, before executing a subroutine some registers values will be pushed onto the stack to save it and free the registers to be used by the subroutine

4. on returning from the subroutine, the stack will be popped and the pushed registers will be loaded with their values before executing the subroutine

5. for getting a value from an address in assembly, this is done in different modes called [Addressing Modes](https://www.tutorialspoint.com/assembly_programming/assembly_addressing_modes.htm) we will be concerned with `Indirect Memory Addressing` in this example

6. Indirect Memory Addressing is similar to pointer in C/C++, where a register is loaded by an address and the operation is to be done on the address in the register, not on a direct given address, hence its name Indirect Memory Addressing

7. in this example, we have two instructions we deal with

    * MOV DEST, SRC <br>
    this command copy data from SRC (register or memory address) to DEST (register or memory address)

    * LEA DEST, SRC <br>
    this macro loads the address not the value of the source to the destination, for example:<br>
 ```armasm
 LEA Ax, [BP-12] ; loads `BP-12` to Ax not the content in the address of [BP-12]
 ```

The following example will show how a simple variable definition in C++ is translated to assembly:
```cpp
int fun(){
    char a {'a'};
    return 0 ;
}
```
using `x86–64 gcc 14.1`, the x86 assembly will do the following:
1. defining a subroutine equivalent to `fun`
2. pushing states of registers to stack before executing the subroutine
3. since we will define a local variable within a function, hence we are dealing with a stack frame, so all variables will take addresses with respect to the stack beginning address, the stack starting address is referenced by the `rbp` base pointer register
4. mov `97` which is the ASCII code of `a` to the address of variable `a`
5. return `0` from the subroutine function
6. pop the registers from the stack and load their previous state
these points are implemented in the following snippet:

```armasm
fun(): ;1 define the subroutine
 ;2. pushing states of registers to stack before executing the subroutine
 push    rbp
 mov     rbp, rsp

 ;3. defining the subroutine of the variable `a` in address rbp-9, where rbp holds the address of the beginning of the stack
 ;4. move 97 to that address
 mov     BYTE PTR [rbp-9], 97
        
        
 ;5. return 0
 mov     eax, 0

 ;6. pop the registers from the stack and load their previous state
 pop     rbp
 ret
```

in the next snippet, I will define a new reference and check whether it will take place from the stack(memory) or not.

```cpp
int fun(){
    char a {'a'};

    char& aRef {a};
    return 0 ;
}
```

```armasm
fun(): ;1
 ;2
 push    rbp
 mov     rbp, rsp
 ;3. 4.
 mov     BYTE PTR [rbp-9], 97

 ; new part
 lea     rax, [rbp-9]
 mov     QWORD PTR [rbp-8], rax
        
 ;5
 mov     eax, 0
 ;6
 pop     rbp
 ret
```

for the new part which corresponds to `char& aRef {a};`, it is noticed that the following points are implemented:
1. load the register `rax` with the value `rbp-9` by using the command `lea`
2. the value of `rbp-9` is the same as the value of variable `a`
3. move the value in `rax` which is `rbp-9` (the address of the variable `a` ) to a new place in the stack which is `rbp-8`

can we consider the reference as a const pointer to `a` or this address (`rbp-8`) is used for something else? To answer this question let's modify the variable `a` using the reference and modifying it directly to see the mechanism of editing `rbp-9` memory location.



```cpp
int fun(){
    char a {'a'};

    char& aRef {a};

 a = 'l'; 

    return 0 ;
}
```

```armasm
fun():
 push    rbp
 mov     rbp, rsp
 mov     BYTE PTR [rbp-9], 97
 lea     rax, [rbp-9]
 mov     QWORD PTR [rbp-8], rax

 ;new part corresponds to a = 'l'; 
 mov     BYTE PTR [rbp-9], 108

 mov     eax, 0
 pop     rbp
 ret
```

as we can see an immediate loading of 108 (l) to the memory address of the variable `a`, now we will do the same using aRef.



```cpp
int fun(){
    char a {'a'};

    char& aRef {a};

 a = 'l'; 
    
 aRef = 'z';

    return 0 ;
}
```

```armasm
fun():
fun():
 push    rbp
 mov     rbp, rsp
 mov     BYTE PTR [rbp-9], 97
 lea     rax, [rbp-9]
 mov     QWORD PTR [rbp-8], rax
 mov     BYTE PTR [rbp-9], 108

 ;new part corresponding to aRef = 'z';
 mov     rax, QWORD PTR [rbp-8]
 mov     BYTE PTR [rax], 122
        
 mov     eax, 0
 pop     rbp
 ret
```

it is clear that the assignment of a through aRef is translated into two instructions, let's see what are these instructions:

1. mov the value in the address ` [rbp-8]` which is the address of aRef and this value is the address of `a` to `rax`. Note this `[]` represents the indirect memory addressing. the following table will visualize the memory and registers after this instruction is executed

| variable | address | value   |
|----------|---------|---------|
| a        | [rbp-9] | l       |
| aRef     | [rbp-8] | rbp-9 |


| Register | value   |
|----------|---------|
| rax      | value in address [rbp-8] which is **rbp-9** | 

2. load the address stored in rax (i.e. that is what mov BYTE PTR [rax] means) with `122` which is the ASCII code of `z`, since the address stored in rax is rbp-9 which is `a`, and since it is loaded via indirect addressing with `z`, then `a = z`

we can conclude that :
* reference takes space in memory
* assigning values to a reference is translated into two instructions at the assembly level which are implicit pointer dereferencing and assignment of the dereferenced pointer 
* any operation on reference at the C/C++ level involves pointer dereferencing and assignment, so we can't get the address of the reference at the C/C++ level.

another prof that reference is a constant pointer, we can define a constant pointer and dereference it in the C++ level and trace its assembly

```cpp
int fun(){
    char a {'a'};
    char& aRef {a};
 a = 'l'; 
 aRef = 'z';

    char* aPtr {&a};

 *aPtr = 'd';

    return 0 ;
}
```
Note: addresses are changed from the previous example this is because of the tool.

```armasm
fun():
 push    rbp
 mov     rbp, rsp
 mov     BYTE PTR [rbp-17], 97
 lea     rax, [rbp-17]
 mov     QWORD PTR [rbp-8], rax
 mov     BYTE PTR [rbp-17], 108
 mov     rax, QWORD PTR [rbp-8]
 mov     BYTE PTR [rax], 122

 ;the new part corresponds to char* aPtr {&a};
 lea     rax, [rbp-17]
 mov     QWORD PTR [rbp-16], rax

 ; corresponds to char*  *aPtr = 'd';
 mov     rax, QWORD PTR [rbp-16]
 mov     BYTE PTR [rax], 100


 mov     eax, 0
 pop     rbp
 ret
```

the logic of defining a pointer and dereference is the same as dealing with a reference.

#### How Does reference to rValue/const ref works on Assembly Level

**for rValues**:
```cpp
int fun(){
    char&& aRef {'b'};
    return 0 ;
}
```
```armasm
fun():
 push    rbp
 mov     rbp, rsp
 ;1. create new variable at [rbp-9] and load it with 'b' = 98
 mov     BYTE PTR [rbp-9], 98

 ; create a new reference at [rbp-8] and load it with the address of the unnamed temp variable
 lea     rax, [rbp-9]
 mov     QWORD PTR [rbp-8], rax

 mov     eax, 0
 pop     rbp
 ret
```
from the previous snippet, the following points are implemented:
1. for creating an rValue reference, a temporary variable should be created in the memory at first

2. creating a reference in memory (as discussed earlier) and reference to the new temporary variable address


**for const unnmaed variables**:

```cpp
int fun(){
    const int& constRef {1};
    return 0 ;
}

```
by using `x86–64 gcc 14.1`
```armasm
fun():
 ; save register state before execution of the subroutine
 push rbp
 mov rbp, rsp
 mov DWORD PTR [rbp-20], 1
 lea rax, [rbp-20]
 mov QWORD PTR [rbp-8], rax
 mov eax, 0 ; return 0
 ; load the register state before calling the subroutine
 pop rbp
 ret
```
the `const int& constRef {1};` is translated to three directives in assembly. these directives are:
* moving `1` to a new address in the current stack frame (create a new local variable)
* `lea` load effective address: `rax ← rbp-20`
* creating a new pointer in the `rbp-8` address that points to the address in the `rax`

so it is similar to creating a new object and a new pointer points to it.

### 23- const_cast()
as previously mentioned in [variables section](#4--variables), Variables can be converted to other types by casting them and introducing static_cast. `static_cast` is one of the 5-types of the cast in C++ which are:
1. const_cast()
2. static_cast()
3. reinterpret_cast()
4. dynamic_cast()
5. std::bit_cast()

in this section, the const_cast will be discussed

const_cast can be used to :

* cast the constant variable to be nonconstant (casting away constness)

* cast the nonconstant variable to be constant (add
const-ness)

* const_cast can be used to change non-const class members inside a const member function

#### casting away constness

Theoretically, of course, there should be no need for a const cast. If a variable is const, it should stay const. In practice, however, you sometimes find yourself in a situation where: 
a function that has a constant parameter that should be passed to a function that receives nonconstant arguments. and you are sure that this function will not modify the passed non-const argument.

The “correct” solution would be to make const consistent in the program, but that is not always an option, especially if you are using third-party libraries. Thus, you sometimes need to cast away the const-ness of a variable, but again you should do this in case you are sure that the function you are calling will not modify the object; otherwise, there is no other option than to restructure your program. 

```cpp
void thirdPartyLibraryFunction(char* non_const_str);
void f(const char* const_str)
{
    thirdPartyLibraryFunction(const_cast<char*>(const_str)); //remove the constness of the function of const_str
}
```
#### change non const class members inside a const member function

const member function is a member function that doesn't modify any member of its object, to modify a non-const member inside a const member function `const_cast` should be used, for example:

```cpp
class Simple 
{ 
private: 
    int nonConstantVal; 
public: 
    void fun() const
 { 
        this->nonConstantVal = 10; //error, a constant member function can't edit member values

 //cannot assign to non-static data member within const member function 'fun'
 } 

}; 
```

use `const_cast` to solve this issue, this adds contents to `this` inside the constant member function.

```cpp

class Simple 
{ 
private: 
    int nonConstantVal; 
public: 
    void fun() const
 { 
 (const_cast<Simple*>( this) )->nonConstantVal = 10; //COMPILE

 } 

}; 

```

**Note**: `const_cast` is considered safer than simple type casting. It’s safer in the sense that the casting won’t happen if the type of cast is not the same as the original object.

### 24- Exceptions

C++ is a flexible language, but it allows doing unsafe things. For example, the compiler will let you write code that scribbles on random memory addresses or tries to divide by zero (computers don’t deal well with infinity). or during the normal flow of the program, an Exceptional condition may occur, such as the following scenarios.
for example: a program that retrieves data from the internet, the following conditions are unexpected in the normal flow and break the normal flow:
* no internet connection
* the source of the data is not available (the server is down)
* the requested data is not available
* and so on
or another program that deals with files, here are some exceptions:
* file not found
* file is opened by another program
* file has no read permissions

All of these conditions and the unsafe instructions cause the normal flow to break, hence these conditions are exceptional, so these types of errors are called Exceptions. An exception is an exceptional situation, that is, a situation that you don’t expect or want in the normal flow of execution of a program.

to handle these errors a function may return nullptr or error code, but C++ provides a better mechanism which is Exception.

for example, consider the following function:
```cpp
double divideNumbers(double numerator, double denominator)
{
    return numerator / denominator;
}
```
```cpp
#include <iostream>
int main(){
    std::cout<< divideNumbers(10, 1) <<std::endl; //1
    int* ptr {nullptr};
    std::cout<< divideNumbers(10, *ptr)  <<std::endl; //crashes
    std::cout<< divideNumbers(10, 2)<<std::endl; //never executed
}
```

**Output**
```
10
```

re-designing the function to handle this input by returning error codes or nullptr, may make the code more complex, instead implementing with `throw` keyword and surrounding the function with the `try-catch` block will make the code simpler. 

**The code with error codes**:


```cpp
#include <iostream>

enum class ErrorCodes {
    NoError = 0,
    DivisionByZero = -1,
    InvalidInput = -2,
};

void handleError(ErrorCodes& error, double value);



double divideNumbers(double numerator, double denominator, ErrorCodes& error)
{   
    if (denominator == 0){
 error = ErrorCodes::DivisionByZero;
        return 0 ;
 }
    return numerator / denominator;
}

int main(){
 ErrorCodes error = ErrorCodes::NoError;
    double value ;
 value =  divideNumbers(10, 1, error) ;
    handleError(error, value);
        
    divideNumbers(10, 0, error);
    handleError(error, value);

}

void handleError(ErrorCodes& error, double value){
    switch(error){
            case ErrorCodes::DivisionByZero:
                std::cout<<"Division by zero is not allowed"<<std::endl;
 error = ErrorCodes::NoError;
                break;
            case ErrorCodes::InvalidInput:
                std::cout<<"Invalid input"<<std::endl;
 error = ErrorCodes::NoError;
                break;
            case ErrorCodes::NoError:
                std::cout<<value<<std::endl;
                break;
 }
}
```

the program is modified by the following:
* Since the function returns a value, we need another variable to handle the error output
* error codes are hard to interpret by developers if they are interpreted as integers so an enum is created to give meaning to the integer values of the error
* We need a handler to output the error based on the error value, instead of repeating the switch statement, a function is created to handle the errors

as shown many modifications are introduced, although there are more efficient ways to handle the errors, these ways are not standardized for all programs (i.e. depending on the experience of the developer), hence we will use a try-catch statement.

```cpp
#include <iostream>
#include <stdexcept>

double divideNumbers(double numerator, double denominator)
{   
    if (denominator == 0){
        throw std::invalid_argument { "Division by zero is not allowed" } ;
 }
    return numerator / denominator;
}

int main(){
    try{
        std::cout << divideNumbers(10, 1) <<std::endl;
        std::cout << divideNumbers(10, 0) <<std::endl;

 }catch(const std::exception& e){
        std::cout << e.what() << std::endl;
 }

}

```

the modifications are less than in the previous snippet, here are the modifications(the syntax of try-catch will be discussed after a few lines):
* surrounding the block that may return an error with a `try { }` block, and follow it by a `catch(){ }` block
* inside the catch block print `e.what()` which returns the error message

as shown no extra enums or arguments are created, no need for a switch case to print the exact error message, also try-catch statement is a standard statement that is implemented in the same way.

#### Syntex of try-catch

in the first snippet (without try-catch), we faced an error of returning two variables (the error and the required variable). the keyword `throw` can be viewed as a special return that returns `errors` only (which are called exceptions). Since throw returns errors it should be received by a catch block, or else the program will terminate.

#### The Flow of the try-catch block
as return keyword, `throw` keyword ends the function (i.e. no lines will be executed after it), consider the following example:
```cpp
#include <iostream>

void a(){
    std::cout<<"1"<<std::endl;
    std::cout<<"2"<<std::endl;
    std::cout<<"3"<<std::endl;
    throw std::invalid_argument {"error message"};
    std::cout<<"4"<<std::endl;
}

void b(){
    try{
        std::cout<<"5"<<std::endl;
        a();
        std::cout<<"6"<<std::endl;
 }catch(const std::exception& e){
        std::cout<<"7"<<std::endl;
        std::cout << e.what() << std::endl;
 }
    std::cout<<"8"<<std::endl;
}

int main(){
    b();
}
```

the execution of the program will be:

```cpp
int main(){
    b()
```
calls `b()`
```cpp
void b(){
    try{
        std::cout<<"5"<<std::endl;
        a();
```

prints:
```
5
```
then calls `a()`


```cpp
void a(){
    std::cout<<"1"<<std::endl; //done
    std::cout<<"2"<<std::endl; //done
    std::cout<<"3"<<std::endl; //done
    throw std::invalid_argument {"error message"}; //(terminate the function and return with an exception)

    std::cout<<"4"<<std::endl; //(not executed)
}
```

prints:
```
5
1
2
3
```

return to `b()` with an exception, not a value

```cpp
void b(){
    try{--→ --→ --→ --→ --→ --→ --→ --→
    ↑    std::cout<<"5"<<std::endl;   ↓ 
    ←- ←-a(); /*exception*/           ↓
 (/*ignore lines */)                  ↓
                                      }catch (
```

since a() returned with an exception to its caller, the caller (`b()`) should **catch** this exception and since the calling of `a()` is surrounded with a `try-catch` block, it will **jump** to the catch block and ignore all other lines under `a()`

```cpp
void b(){
    try{
 //..... (lines are ignored)
 }catch(const std::exception& e){
        std::cout<<"7"<<std::endl; ;
        std::cout << e.what() << std::endl;
 }
    std::cout<<"8"<<std::endl;
}
```
outputs:
```
5
1
2
3
7
```
`b()` will print the `7` and execute ` e.what()` which returns the error message defined in the throw statement (i.e. here `throw std::invalid_argument {"error message"};`)  and finishes the `catch` block, then it will print `8` and  return to `main` function
```
5
1
2
3
7
error message
8
```

**What if calling of a() wasn't surrounded by a try/catch block**
consider the following modification for the previous statement

```cpp
#include <iostream>

void a(){
    std::cout<<"1"<<std::endl;
    std::cout<<"2"<<std::endl;
    std::cout<<"3"<<std::endl;
    throw std::invalid_argument {"error message"};
    std::cout<<"4"<<std::endl;
}

void b(){
 //remove try-catch block
    std::cout<<"5"<<std::endl;
    a();
    std::cout<<"6"<<std::endl;
    std::cout<<"8"<<std::endl;
}

int main(){
    try{ //set the try-catch here
        b();
        std::cout<<"7"<<std::endl;
 }catch(const std::exception& e){
        std::cout<<"8"<<std::endl;
        std::cout << e.what() << std::endl;
 }
    std::cout<<"9"<<std::endl;
}
```
the surronded calling of `a()` within `b()` is moved to the main function, hence b() will not catch the exception from `a()`. what will happen? 

>**If a function doesn't catch an exception it will rethrow it to its caller function, and the caller function will catch it or rethrow it again up to the main function if the main function doesn't catch it, the program will terminate**

the execution will be:

```cpp
int main(){
    try{
        b();
```
calls `b()`
```cpp
void b(){
    std::cout<<"5"<<std::endl;
    a();
```

prints:
```
5
```
then calls `a()`


```cpp
void a(){
    std::cout<<"1"<<std::endl; //done
    std::cout<<"2"<<std::endl; //done
    std::cout<<"3"<<std::endl; //done
    throw std::invalid_argument {"error message"}; //(terminate the function and return with an exception)

    std::cout<<"4"<<std::endl; //(not executed)
}
```

prints:
```
5
1
2
3
```

return to `b()` with an exception, not a value

```cpp
void b(){
 ↑
 ↑   std::cout<<"5"<<std::endl;  
 ←- a(); /*exception*/           
 (/*ignore lines */)          
```

`b()` should catch the exception, but it didn't so it will throw the exception to the caller function which is `main()`, and ignore other lines.


```cpp
int main(){
    try{--→ --→ --→ --→ --→ --→ --→ --→
    ↑                                 ↓
    ← ← ←b();                         ↓
         std::cout<<"7"<<std::endl;   ↓
                                     }catch(const std::exception& e){
                                        std::cout<<"8"<<std::endl;
                                        std::cout << e.what() <<std::endl;
 }
    std::cout<<"9"<<std::endl;
    return 0;
}
```
prints:
```
5
1
2
3
8
error message
9
```

**No catch block in the callers stack**

```cpp
#include <iostream>

void a(){
    std::cout<<"1"<<std::endl;
    std::cout<<"2"<<std::endl;
    std::cout<<"3"<<std::endl;
    throw std::invalid_argument {"error message"};
    std::cout<<"4"<<std::endl;
}

void b(){
    std::cout<<"5"<<std::endl;
    a();
    std::cout<<"6"<<std::endl;
    std::cout<<"8"<<std::endl;
}

int main(){
    b();
    std::cout<<"7"<<std::endl;
}
```

```
5
1
2
3
terminate called after throwing an instance of 'std::invalid_argument'
 what():  error message
```

### 25- Type Aliases
an alias is another name for something, and for type aliases, it provides a new name for an existing type declaration, while you can use the old name.

Type aliases were introduced in C++11. Before C++11, typedefs were being used (discussed in the next section).

for example, for pointers to integers:
```cpp
using IntPtr = int*;
```
the typename is `int*` and the new additional name (type alias) is `IntPtr`.

```cpp
int main(){
    using IntPtr = int*;
    int* p1;
 IntPtr p2;

 //Variables created with the new type name are completely compatible with those created with the original type declaration
 p1 = p2;
 p2 = p1;
}
```

The most common use for type aliases is to provide manageable names when the real type declarations become too indescriptive. This situation commonly arises with templates. An example from the Standard Library itself is std::basic_string<T> to represent strings. It’s a class template where T is the type of each character in the string, for example, char. You have to specify the template type parameter any time you want to refer to such a type.

For declaring a string variables, , you would have to write basic_string<char>:
```cpp
void processVector(const vector<basic_string<char>>& vec) { /* omitted */ }
int main()
{
vector<basic_string<char>> myVector;
processVector(myVector);
}
```
Since basic_string<char> is used that frequently, the Standard Library provides the following type alias as a shorter, more meaningful name:
using string = basic_string<char>;

using this alias:
```cpp
void processVector(const vector<string>& vec) { /* omitted */ }
int main()
{
vector<string> myVector;
processVector(myVector);
}
```

### 26- typedefs

since type aliases were introduced in C++11. legacy code bases still have typedefs, so `typedef` is explained. typedef is the same as type alias except the order of definitions. for example:

```cpp
using IntPtr = int*; //typealias
typedef int* IntPtr; //typedef
```
both are the same thing except the type alias is more readable, but Type aliases and typedefs are not entirely equivalent, though. Compared to typedefs, type aliases are more powerful when used with templates, this topic is covered in the book in chapter 12.


### 27- Type Inference

Type Inference refers to automatic deduction of the data type of an expression in a programming language. introduced in C++11, before that each data type needed to be explicitly declared at compile-time, limiting the values of an expression at runtime but after the new version of C++, introduced two new keywords that support type inference which are `auto` and `decltype` which allows a programmer to leave the type deduction to the compiler itself. 

With type inference capabilities, we can spend less time having to write out things the compiler already knows. As all the types are deduced in the compiler phase only, the time for compilation increases slightly but it does not affect the run time of the program.

#### The auto Keyword
The auto keyword has several different uses:
1. To deduce a function’s return type, as explained earlier
2. To define structured bindings, as explained earlier
3. To deduce the type of an expression, as discussed earlier
4. To deduce the type of non-type template parameters; discussed in Chapter 12
5. To define abbreviated function templates; discussed in Chapter 12
6. To use with decltype(auto); discussed in Chapter 12
7. To write functions using the alternative function syntax; discussed in Chapter 12
8. To write generic lambda expressions; discussed in Chapter 19

auto can be used to let the compiler deduce the type of a variable at compile time without being explicitly defined by the programmer. The following statement shows the simplest use of the auto keyword in that context:

```cpp
auto x { 123 }; // x is of type int.
```
of course, the previous use-case isn't the main advantage of the auto keyword, the following are some of its advantages and use cases:
* if a function has complicated return, If you want to assign the result of calling getFoo() to a variable, you can spell out the complicated type, or you can simply use auto and let the compiler figure it out
 ```cpp
    int**& func(){}
    int main(){
        auto f = func();
    }
 ```
* by using `auto`, a return type of a function can be easily changed without updating all the places in the code where that function is called

#### The auto Keyword; The auto& Syntax
auto keyword is a handy keyword except for one issue that auto does which is *Using auto to deduce the type of an expression removes reference and const qualifiers.*, in other words, auto substitutes the types only without any qualifiers such as `const, &` for example:

```cpp
int main(){
    const int value {3};
    const int& valueRef {value};
    auto valueRefRef {valueRef};

 valueRef = 5 ; //error since it is constant
 valueRefRef  = 5 ; //no errors
}
```

```cpp
valueRef = 5 ; //error since it is constant
valueRefRef  = 5 ; //no errors
```
the `valueRef = 5 ;` issues an error since we modify a constant value, but for `valueRefRef  = 5 ;` the compiler didn't issue an error since the `auto` keyword removed the constant qualifier from the `value` variable, **but does it means that auto made variable inconstant?**, NO, auto makes a new copy from the referenced variable, see the example after modification:
```cpp
#include <iostream>
int main(){
    const int value {3};
    const int& valueRef {value};
    auto valueRefRef {valueRef};

 //valueRef = 5 ; //error since it is constant
 valueRefRef  = 10 ; //no errors

    std::cout<<value<<std::endl;
    std::cout<<valueRefRef<<std::endl;
}
```
```
3
10
```

`valueRefRef` is changed but `value` isn't, hence valueRefRef is not a reference to a value.

to solve this issue use `const auto&` or `auto&` according to the required case.
 
consider the following example:
```cpp
int main(){
    int val{3};
    int& valRef {val};
    auto& valRefRef {valRef};

 valRefRef = 10;
    std::cout<<val<<std::endl;
}
```
```
10
```

using `const auto` :


```cpp
int main(){
    const int const_val{3};
    const auto const_val_ref {val};
 const_val = 12 ; //error
}
```


WARNING Always keep in mind that auto strips away reference and const
qualifiers and thus creates a copy! If you do not want a copy, use auto& or const auto&.

#### The auto Keyword; The auto* Syntax
auto keyword can deduce pointers as the following example:
```cpp
int main(){
    int i { 123 };
    auto p { &i }; //same as int* p {&i}
 *p = 189;
}
```
```
0x57cd5ff714
0x57cd5ff714
189
```
However, when working with pointers, it is recommended to use the `auto*` syntax for the following reasons:
* it is more readable since it clearly states that pointers are involved
 ```cpp
    auto* p { &i };
 ```
* using `auto*` resolves the strange behavior when using `auto`, const, and pointers together. Suppose you write the following:
 ```cpp
    const auto p1 { &i };
 ```
 is it const int* p1 or int* const p1? It is int* const p1 which is a constant pointer to nonconstant int, so most of the time, this syntax is not doing what is expected to do!

 the previous syntax is read as a pointer to constant int, although it is not behaving like this, using `auto*`, solves this issue and increases the readability.

 ```cpp
        const auto* p3 { &i }; // resolves to const int* p3 {&i};
        const auto p4 { &i }; // resolves to  int* const p4 {&i};
        auto* const p5 { &i }; // resolves to  int* const p5 {&i};
 ```

#### The auto Keyword; Copy List vs. Direct List Initialization
using uniform initializer `{}` with `auto` can introduce some bugs that should be avoided, in this section the source of these bugs is introduced.
Two types of initializations use braced initializer `{}` lists:
* Copy list initialization: `T obj = {arg1, arg2, ...};`
* Direct list initialization: `T obj {arg1, arg2, ...};`

In combination with auto-type deduction, there is an important difference between copy- and direct list initialization. Here is an example:
```cpp
int main(){
 // Copy list initialization
    auto a = { 11 }; // initializer_list<int>
    auto b = { 11, 22 }; // initializer_list<int>
    
 // Direct list initialization
    auto c { 11 }; // int
    auto d { 11, 22 }; // Error, too many elements
}
```

#### The decltype Keyword

The decltype keyword which stands for **declared type** takes an expression as an argument and computes the type of that expression, as
shown here:
```cpp
int x { 123 };
decltype(x) y { 456 };
```
In this example, the compiler deduces the type of y to be int because that is the type of x.

The difference between auto and decltype is that **decltype does not remove reference and const qualifiers.** consider the following example:

```cpp
#include <iostream>
int main(){

 //1- using decltype with references

    int val{3};
    int& valRef {val};
    decltype(valRef)  valRefRef {valRef};//returns int&

 valRefRef = 10;
    std::cout<<val<<std::endl;

 //2- using decltype with const references
    const int const_val{3};
    const int& const_val_ref {val};
    decltype(const_val_ref)  const_val_ref_ref {const_val_ref};
 const_val_ref_ref = 12 ; //error constant value

}
```

```
10
```

At first sight, decltype doesn’t seem to add much value. However, it is powerful in the context of templates, discussed in Chapters 12 and 26 of the book.


### 28- The Standard Library
C++ comes with a Standard Library, which contains a lot of useful heavily tested, and optimized classes that can readily be used in your code. you don’t need to waste time on implementing things that have already been implemented for you.

A lot of functionality is provided by the Standard Library. Chapters 16 to 24 in the book provide more details; however, when you start working with C++, it is good to have an idea of what the Standard Library can do for you from the beginning. This is especially important if you are a C programmer. As a C programmer, you might try to solve problems in C++ the same way you would solve them in C, but in C++ there is probably an easier and safer solution to the problem that involves using **Standard Library classes**.

That is the reason why the book already introduces some Standard Library classes, such as `std::string`, `array`, `vector`, `pair`, `optional`, and `tuple`. Many more classes are introduced in Chapters 16 to 24 in the book.