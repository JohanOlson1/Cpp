C came first in 1972. C++ came in 1979, developed as an extension to C. Compared to C, C++ is an object-oriented language. C++20 latest version. 

The design philosophy is "trust the programer", allowing high degree of freedom but not stoping you from doing things that don't make sense. Therefore equally important to know what not to do, as what to do. 

# 1. Development

![image-20220930093433078](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20220930093433078.png)

## Step 1 - Define the problem to you would like to solve.

 Can be both the hardest or easiest step. You need a well defined idea!

## Step 2 - Determine how to solve the problem

Many different ways to solve a problem. Some are good and some are bad. Good solutions have the following characteristics:

- They are straighforward (not complicated or confusing)
- They are well documented (especially around any assumptions or limitations)
- They are built modularly, so parts can be reused or changed later without impact on other parts of program
- They are robust, and recover or give useful error messages when unexpected things happen

Studies have shown that only 20% of a programmer’s time is actually spent writing the initial program. The other 80% is spent on maintenance, which can consist of **debugging** (removing bugs), updates to cope with changes in the environment (e.g. to run on a new OS version), enhancements (minor changes to improve usability or capability), or internal improvements (to increase reliability or maintainability).

## Step 3 - Write the program

You need knowledge of programming and a text editor. Specifically a code editor! 

The programs you write will typically be named *something.cpp* or *something.cc*

A program can consist of multiple .cpp files. 

## Step 4 - Compiling your source code

In order to compile a C++ program, we use a C++ compiler. The compiler sequentially goes though each .cpp file and do two things. 

First, it checks so the code follows rules of C++ language. Otherwise it throws an error.

Second, it translates your C++ source code into machine language in an **object file**. Designated *name.o* or *name.obj*.  One object file per .cpp file. 

## Step 5 - Linking object files and libraries

Another program called the linker kicks in next. 

![image-20220930095219788](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20220930095219788.png)

First, it takes all object files and comine them into a single executable program. 

Second, it can also link library files. A **library file** is a collection of precompiled code that has been “packaged up” for reuse in other programs.

Third, the linker makes sure all cross-file dependencies are resolved properly. If the linker is unable to connect a reference to something with its definition, you’ll get a linker error, and the linking process will abort.

You then have a executable file that can be run. 

For more complex projects, a **makefile** that describes how to build a program can be used. 

## Step 6 & 7 - Testing and Debugging

If your program runs but doesn’t work correctly, then it’s time for some debugging to figure out what’s wrong.



# 2. Integrated Development Environment (IDE)

Many (but not all) IDEs include a C++ compiler and a linker, which the IDE will know how to interface with in order to convert your source code into an executable file. And when you need to debug your program, you can use the integrated debugger.

To write a C++ program inside an IDE, we typically start by creating a new project. A **project** is a container that holds all of your source code files, images, data files, etc… that are needed to produce an executable (or library, website, etc…) that you can run or use. 

Each project corresponds to one program. When you’re ready to create a second program, you’ll either need to create a new project, or overwrite the code in an existing project (if you don’t want to keep it).

**Best practice:** Create a new project for each new program you write.

A **console project** means we create programs that can be run from the Windows, Linux, or Mac console.

## Workspaces / solutions

When you create a new project for your program, many IDEs will automatically add your project to a “workspace” or a “solution” (the term varies by IDE). A workspace or solution is a container that can hold one or more related projects. For example, if you were writing a game and wanted to have a separate executable for single player and multiplayer, you’d need to create two projects.

## Solution Explorer

In the Window titled *Solution Explorer*. Inside this window, Visual Studio has created a solution for you (*Solution ‘HelloWorld’*). Within that, with the name in bold, is your new project (*HelloWorld*).

## Running a program

Compile Program using *Ctrl+Shift+B*

Run compiled program using *Ctrl-F5*

When a code file is compiled, your IDE may cache the resulting object file. That way, if the program is compiled again in the future, any code file that hasn’t been modified doesn’t need to be recompiled -- the cached object file from last time can be reused.

With that in mind, here’s what each of the options typically does:

- **Build** compiles all *modified* code files in the project or workspace/solution, and then links the object files into an executable. If no code files have been modified since the last build, this option does nothing.
- **Clean** removes all cached objects and executables so the next time the project is built, all files will be recompiled and a new executable produced.
- **Rebuild** does a “clean”, followed by a “build”.
- **Compile** recompiles a single code file (regardless of whether it has been cached previously). This option does not invoke the linker or produce an executable.
- **Run/start** executes the executable from a prior build. Some IDEs (e.g. Visual Studio) will invoke a “build” before doing a “run” to ensure you are running the latest version of your code. 

Although we talk informally about “compiling” our programs, to actually compile our programs we will typically choose the “build” (or “run”) option in our IDE to do so.

## Build Configurations

A collectrion of project settings that determines how the IDE will build projects. 

The **debug configuration** is designed to help you debug your program, and is generally the one you will use when writing your programs. This configuration turns off all optimizations, and includes debugging information, which makes your programs larger and slower, but much easier to debug. The debug configuration is usually selected as the active configuration by default. We’ll talk more about debugging techniques in a later lesson.

The **release configuration** is designed to be used when releasing your program to the public. This version is typically optimized for size and performance, and doesn’t contain the extra debugging information. Because the release configuration includes all optimizations, this mode is also useful for testing the performance of your code.

**Best practice:** Use the *debug* build configuration when developing your programs. When you’re ready to release your executable to others, or want to test performance, use the *release* build configuration.

![image-20220930105956796](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20220930105956796.png)

## Compiler Configurations

The C++ standard defines rules about how programs should behave in specific circumstances. And in most cases, compilers will follow these rules. However, many compilers implement their own changes to the language, often to enhance compatibility with other versions of the language (e.g. C99), or for historical reasons. These compiler-specific behaviors are called **compiler extensions**.

**Best practice:** Disable compiler extensions to ensure your programs (and coding practices) remain compliant with C++ standards and will work on any system.

### Warning and error Levels: 

When you write your programs, the compiler will check to ensure you’ve followed the rules of the C++ language. 

If you have done something that definitively violates the rules of the language, during compilation the compiler will emit an **error**, providing both line number containing the error, and some text about what was expected vs what was found. The actual error may be on that line, or on a preceding line. Once you’ve identified and fixed the erroneous line(s) of code, you can try compiling again.

In other cases, the compiler may find code that seems like it might be in error, but the compiler can’t be sure (remember the motto: “trust the programmer”). In such cases, the compiler may opt to issue a **warning**. Warnings do not halt compilation, but are notices to the programmer that something seems amiss.

**Best practice:**Don’t let warnings pile up. Resolve them as you encounter them (as if they were errors). Otherwise a warning about a serious issue may be lost amongst warnings about non-serious issues.

The warning level can be increase:

**Best practice:** Turn your warning levels up to the maximum, especially while you are learning. It will help you identify possible issues.

**Best practice:** Enable “Treat warnings as errors”. This will force you to resolve all issues causing warnings. (Just think that way)

## Language Standard

Here’s a mapping of code names to the final names:

- c++1x = C++11
- c++1y = C++14
- c++1z = C++17
- c++2a = C++20
- c++2b = C++23

For example, if you see `c++1z`, this is synonymous with the C++17 language standard.

In professional environments, it’s common to choose a language standard that is one or two versions back from the latest standard (e.g. now that C++20 is out, that means C++14 or C++17). This is typically done to ensure the compiler makers have had a chance to resolve defects, and so that best practices for new features are well understood. Where relevant, this also helps ensure better cross-platform compatibility, as compilers on some platforms may not provide full support for newer language standards immediately.

### Setting a language standard in Visual Studio

As of the time of writing, Visual Studio 2022 defaults to C++14 capabilities, which does not allow for the use of newer features introduced in C++17 and C++20.

To use these newer features, you’ll need to enable a newer language standard. Unfortunately, there is currently no way to do this globally -- you must do so on a project-by-project basis.

**Exporting your configuration**: In Visual Studio, this option is available via Project -> Export Template. Select “Project template”, add a name and optional description (e.g. C++20 console application), and then click “Finish”. Next time you create a new project, you’ll see this template show up in your list of project templates.

# 3. Basics

A **statement** is a type of instruction that causes the program to *perform some action*.

- Each statement ends with a semicolon.

**Rule: **Every C++ program must have a special function named **main** (all lower case letters). When the program is run, the statements inside of *main* are executed in sequential order.

- A function is usually in text given as *name*(), the paranthesis indicating its a function.
- Syntax is the grammar of programming, a syntax error is akin to misspelling.
- C++ is a whitespace-independent language, only inside quoted text do spaces matter.
- The return value from `main` is sometimes called a **status code** (also sometimes called an **exit code**)
  - The C++ standard only defines the meaning of 3 status codes: 0, EXIT_SUCCESS, and EXIT_FAILURE. 0 and EXIT_SUCCESS both mean the program executed successfully. EXIT_FAILURE means the program did not execute successfully.


## Preprocessor Derective

A special type of line. 

```
#include <iostream>
```

This preprocessor directive indicates that we would like to use the contents of the iostream library, which is the part of the C++ standard library that allows us to read and write text from/to the console.

## Comments

- Comments are made using: `//`

- Commenting multi line is done using: `/*` at start and `*/ ` at the end, they cannot be nested.

- A bad statement comment explains *what* the code is doing. If you ever write code that is so complex that needs a comment to explain *what* a statement is doing, you probably need to rewrite your statement, not comment it.

- Programmers often have to make a tough decision between solving a problem one way, or solving it another way. Comments are a great way to remind yourself (or tell somebody else) the reason you made one decision instead of another.

  **Best practice:** Comment your code liberally, and write your comments as if speaking to someone who has no idea what the code does. Don’t assume you’ll remember why you made specific choices.

## Objects and Variables

All computers have memory, called **RAM** (short for random access memory), that is available for your programs to use. 

A single piece of data, stored in memory is called a **value**.

In some older programming languages you could directly access the memory. This is howerver discouraged. Instead we use an object to access memory. 

A named object is called a **variable**. While its name is its **identifier**. 

A varible has to be declared using a **definition**, like:

```
int x; // define a variable named x, of type int
```

**Instantiation** is a fancy word that means the object will be created and assigned a memory address.

Several variables can be defined at the same time, of same type!

```
int a, b;
```

**Best practice:** Although the language allows you to do so, avoid defining multiple variables of the same type in a single statement. Instead, define each variable in a separate statement on its own line (and then use a single-line comment to document what it is used for).

Different ways to initialize

```
int a; // no initializer
int b = 5; // initializer after equals sign, copy initialization
int c( 6 ); // initializer in parenthesis, direct initialization
int d { 7 }; // initializer in braces, brace initialization
```

Brace initialization is the modern way to initialize objects in C++, unlike C!

- It allows initialization with a list of values 
- It disallows "narrowing conversions", trying to initialize with incorrect type. Will throw error. otherwise (int a = 4.5) becomes 4 for example

**Best practice:** Favor initialization using braces whenever possible.

When a variable is initialized with empty braces, **value initialization** takes place. In most cases, **value initialization** will initialize the variable to zero (or empty, if that’s more appropriate for a given type). In such cases where zeroing occurs, this is called **zero initialization**.

**Best practice:** Initialize your variables upon creation.

Unlike some programming languages, C/C++ does not initialize most variables to a given value (such as zero) automatically. Thus when a variable is given a memory address to use to store data, the default value of that variable is whatever (garbage) value happens to already be in that memory address!

**Rule:** Take care to avoid all situations that result in undefined behavior, such as using uninitialized variables.

## iostream - input/output library

Deals with basic input and output. 

Add before use, preferably at the top of code file

```
#include <iostream>

// rest of code that uses iostream functionality here
```

### Functions

**std::cout**

```
std::cout << "Hello world!" // << is the insertion operator

std::cout << "x is equal to: " << x; // Combination of text and object
```

Allows us to send data to the console to be printed. It can also print numbers, and values of objects. 

**std:endl** 

```
std::cout << "Hi!" << std::endl; // std::endl will cause the cursor to move to the next line of the console
std::cout << "My name is Alex." << std::endl;
```

Moves to next line. 

**Best practice**: Output a newline whenever a line of output is complete.

It does another things however; makes sure the output shows up on the screen immediately. Therefore one often use '\n' instead in text. (and only end with it). 

**Best practice:** Prefer ‘\n’ over std::endl when outputting text to the console.

**std:cin** 

Reads input from from keyboard using the extractor operator `>>`. 

```
#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter a number: "; // ask user for a number

    int x{ }; // define variable x to hold user input (and zero-initialize it)
    std::cin >> x; // get number from keyboard and store it in variable x

    std::cout << "You entered " << x << '\n';
    return 0;
}
```

Note that you don’t need to use ‘\n’ when accepting input, as the user will need to press the *enter* key to have their input accepted, and this will move the cursor to the next line. 

We can override the default precision that std::cout shows by using an: 

```
std::cout << std::setprecision(16); // show 16 digits of precision
```

## Keywords

C++ reserves a set of 92 words (as of C++20) for its own use. These words are called **keywords** (or reserved words), and each of these keywords has a special meaning within the C++ language. Can be seen here: https://www.learncpp.com/cpp-tutorial/keywords-and-naming-identifiers/

- The identifier can not be a keyword. Keywords are reserved.
- The identifier can only be composed of letters (lower or upper case), numbers, and the underscore character. That means the name can not contain symbols (except the underscore) nor whitespace (spaces or tabs).
- The identifier must begin with a letter (lower or upper case) or an underscore. It can not start with a number.
- C++ is case sensitive, and thus distinguishes between lower and upper case letters. `nvalue` is different than `nValue` is different than `NVALUE`.

Naming convention:

- Variable names should be only lowercase letter. 

- Instead of underscore one can use a uppercase letter (camelCase)

- Identifiers should make clear what they hold

- Make the length of the identifier proportional to its use, if it is used often have a more descriptive and longer name

  **Best practice:** When working in an existing program, use the conventions of that program (even if they don’t conform to modern best practices). Use modern best practices when you’re writing new programs.

![image-20220930143409693](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20220930143409693.png)

## Formatting

- There are two acceptable styles for function braces. Recommended is

  ```
  int main()
  {
  }
  ```

- Each statement within curly braces should start one tab in from the opening brace of the function it belongs to. For example:

```
int main()
{
    std::cout << "Hello world!\n"; // tabbed in one tab (4 spaces)
    std::cout << "Nice to meet you.\n"; // tabbed in one tab (4 spaces)
}
```

- Lines should not be too long. Typically, 80 characters is the maximum length a line should be. If a line is going to be longer, it should be split (at a reasonable spot) into multiple lines. This can be done by indenting each subsequent line with an extra tab, or if the lines are similar, by aligning it with the line above (whichever is easier to read).

- If a long line is split with an operator (eg. << or +), the operator should be placed at the beginning of the next line, not the end of the current line
- Use whitespace to make your code easier to read by aligning values or comments or adding spacing between blocks of code.

```
cost = 57;
pricePerItem = 24;
value = 5;
numberOfItems = 17;

vs 

cost          = 57;
pricePerItem  = 24;
value         = 5;
numberOfItems = 17;
```

**For Visual Studio users:** In Visual Studio, the automatic formatting options can be found under *Tools > Options> Text Editor

## Operators and literals

A **literal** is a fixed value that has been inserted directly into the source code. The value is fixed and cannot be changed. 

In mathematics, an **operation** is a mathematical calculation involving zero or more input values (called **operands**) that produces a new value (called an output value).

Example of common nomenclature:bthe plus operator would be written *operator+*, and the extraction operator would be written *operator>>*.

Some operatorts are words (eg. delete). 

The number of operands that an operator takes as input is called the operator’s *arity*: 

Operators in C++ come in four different *arities*:

- **Unary** operators act on one operand. An example of a unary operator is the *- operator*. For example, given `-5`, *operator-* takes literal operand *5* and flips its sign to produce new output value *-5*.

- **Binary** operators act on two operands (known as *left* and *right*). An example of a binary operator is the *+ operator*. For example, given `3 + 4`, *operator+* takes the left operand (3) and the right operand (4) and applies mathematical addition to produce new output value *7*. The insertion (<<) and extraction (>>) operators are binary operators, taking std::cout or std::cin on the left side, and the value to output or variable to input to on the right side.

- **Ternary** operators act on three operands. There is only one of these in C++ (the conditional operator), which we’ll cover later.

- **Nullary** operators act on zero operands. There is also only one of these in C++ (the throw operator), which we’ll also cover later.

An **expression** is a combination of literals, variables, operators, and function calls that calculates a single value. 

An **expression statement** is a statement that consists of an expression followed by a semicolon. When the statement is executed, the expression will be evaluated. 

### Operators:

Precedence level 1 is the highest precedence level, and level 17 is the lowest. Operators with a higher precedence level get evaluated first.

![image-20221004132746217](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221004132746217.png)

![image-20221004132800383](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221004132800383.png)

In order to reduce mistakes and make your code easier to understand without referencing a precedence table, it’s a good idea to parenthesize any non-trivial compound expression, so it’s clear what your intent is.

**Best practice**: Outside of the operator precedence and associativity rules, assume that the parts of an expression could evaluate in any order. Ensure that the expressions you write are not dependent on the order of evaluation of those parts.

### Arithmetics:

![image-20221004133744235](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221004133744235.png)

C++ does not include an exponent operator!

To do exponents in C++, #include the <cmath> header, and use the pow() function.

If you want to do integer exponentiation, you’re best off using your own function to do so. See example:

```cpp
#include <iostream>
#include <cstdint> // for std::int64_t
#include <cassert> // for assert

// note: exp must be non-negative
std::int64_t powint(std::int64_t base, int exp)
{
	assert(exp >= 0 && "powint: exp parameter has negative value");

	std::int64_t result{ 1 };
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}

int main()
{
	std::cout << powint(7, 12); // 7 to the 12th power

	return 0;
}
```

**Warning:** In the vast majority of cases, integer exponentiation will overflow the integral type. This is likely why such a function wasn’t included in the standard library in the first place.

Increment/Decrement operators:

![image-20221004134215510](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221004134215510.png)

**Best practice**: Strongly favor the prefix version of the increment and decrement operators, as they are generally more performant, and you’re less likely to run into strange issues with them.

**Warning**: C++ does not define the order of evaluation for function arguments or operator operands.

**Warning:** Don’t use a variable that has a side effect applied to it more than once in a given statement. If you do, the result may be undefined.

### Comma operator and conditional operators: 

![image-20221004134448759](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221004134448759.png)

The **comma operator (,)** allows you to evaluate multiple expressions wherever a single expression is allowed. The comma operator evaluates the left operand, then the right operand, and then returns the result of the right operand. 

**Best practice:** Avoid using the comma operator, except within *for loops*.

### Ternary operator:

![image-20221004134647791](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221004134647791.png)

**Best practice**: Always parenthesize the conditional part of the conditional operator, and consider parenthesizing the whole thing as well.

**Best practice:** Only use the conditional operator for simple conditionals where you use the result and where it enhances readability.

## Declarations and derectives

A **qualified name** is a name that includes an associated scope.

```cpp
class C; // some class

C::s_member; // s_member is qualified by class C
obj.x; // x is qualified by class object obj
ptr->y; // y is qualified by pointer to class object ptr
```

If a `using declaration` or `using directive` is used within a block, the names are applicable to just that block. 

**Best practice**: Prefer explicit namespaces over `using statements`. Avoid `using directives` whenever possible. `Using declarations` are okay to use inside blocks. Eg. don't bother with this!

### Declarations:

```cpp
#include <iostream>

int main()
{
   using std::cout; // this using declaration tells the compiler that cout should resolve to std::cout
   cout << "Hello world!\n"; // so no std:: prefix is needed here!

   return 0;
} // the using declaration expires here
```

If there’s a naming conflict between `std::cout` and some other use of `cout`, `std::cout` will be preferred.

### Derectives:

```cpp
#include <iostream>

int main()
{
   using namespace std; // this using directive tells the compiler to import all names from namespace std into the current namespace without qualification
   cout << "Hello world!\n"; // so no std:: prefix is needed here
   return 0;
}
```

In modern C++, `using directives` generally offer little benefit (saving some typing) compared to the risk.

Greater risk of naming conflict.

# 4. Functions

A **function** is a reusable sequence of statements designed to do a particular job.

Functions that you write yourself are called **user-defined functions**. 

A **function call** is an expression that tells the CPU to interrupt the current function and execute another function.

The compiler compiles the contents of code files sequentially. Hence functions must be defined before their use on a latter line. (Unless: A **forward declaration** allows us to tell the compiler about the existence of an identifier *before* actually defining the identifier.)

- Just like variables have names, so do user-defined functions. The *identifier* is the name of your user-defined function.

- The parentheses after the identifier tell the compiler that we’re defining a function.

  Example of fucntion use:

  ```
  #include <iostream> // for std::cout
  
  // Definition of user-defined function doPrint()
  void doPrint() // doPrint() is the called function in this example
  {
      std::cout << "In doPrint()\n";
  }
  
  // Definition of function main()
  int main()
  {
      std::cout << "Starting main()\n";
      doPrint(); // Interrupt main() by making a function call to doPrint().  main() is the caller.
      std::cout << "Ending main()\n"; // this statement is executed after doPrint() ends
  
      return 0;
  }
  ```

  Unlike some other programming languages, in C++, functions cannot be defined inside other functions.

  ## Return values

  When you write a user-defined function, you get to determine whether your function will return a value back to the caller or not. To return a value back to the caller, two things are needed.

  1. Your function has to indicate what type of value will be returned. This is done by setting the function’s **return type**, which is the type that is defined before the function’s name.

  2. A return statement is needed, return the **return value**.

     **Tip:** When a called function returns a value, the caller may decide to use that value in an expression or statement (e.g. by assigning it to a variable, or sending it to `std::cout`) or ignore it (by doing nothing else).

     Return types

  - void
  - value returning function

  **Best practice:** Make sure your functions with non-void return types return a value in all cases. Failure to return a value from a value-returning function will cause undefined behavior.

  **Best practice:** Follow the DRY best practice: “don’t repeat yourself”. If you need to do something more than once, consider how to modify your code to remove as much redundancy as possible. Variables can be used to store the results of calculations that need to be used more than once (so we don’t have to repeat the calculation).

  ### Void functions:

  A function that does not return a value is called a **non-value returning function** (or a **void function**).

  **Void functions can’t be used in expression that require a value**

  A return statement that is not the last statement in a function is called an **early return**. Such a statement will cause the function to return to the caller when the return statement is executed (before the function would otherwise return to the caller, hence, “early”). It is okay to use return in void functions, but only to go back, not return a value!

  ## Function arguments:
  
  When a function is called, all of the parameters of the function are created as variables, and the value of each of the arguments is *copied* into the matching parameter. This process is called **pass by value**. 
  
  ```
  // This function has two integer parameters, one named x, and one named y
  // The values of x and y are passed in by the caller
  void printValues(int x, int y)
  {
      std::cout << x << '\n';
      std::cout << y << '\n';
  }
  
  int main()
  {
      printValues(6, 7); // This function call has two arguments, 6 and 7
  
      return 0;
  }
  ```
  
  Note that the number of arguments must generally match the number of function parameters, or the compiler will throw an error.
  
  Function arguments can be a another functions return value (direct).
  
  Function parameters and return values are the key mechanisms by which functions can be written in a reusable way, as it allows us to write functions that can perform tasks and return retrieved or calculated results back to the caller without knowing what the specific inputs or outputs are ahead of time.
  
  ## Local scope:
  
  Variables defined inside a function are local variables. 
  
  Local variables are destroyed in the opposite order of creation at the end of the set of curly braces in which it is defined (or for a function parameter, at the end of the function). 
  
  Objects must be created and initialized no later than the point of definition, and destroyed no earlier than the end of the set of the curly braces in which they are defined (or, for function parameters, at the end of the function).
  
  An identifier’s **scope** determines where the identifier can be accessed within the source code. When an identifier can be accessed, we say it is **in scope**. When an identifier can not be accessed, we say it is **out of scope**.
  
  **Key Insight:** Names used for function parameters or variables declared in a function body are only visible within the function that declares them. This means local variables within a function can be named without regard for the names of variables in other functions. This helps keep functions independent. 
  
  **Best practice:** Define your local variables as close to their first use as reasonable.
  
  ### Static local variables:
  
  Local variables have `automatic duration` by default, which means they are created at the point of definition, and destroyed when the block is exited.
  
  Using the `static` keyword on a local variable changes its duration from `automatic duration` to `static duration`. 
  
  This means the variable is now created at the start of the program, and destroyed at the end of the program (just like a global variable). 
  
  Just like we use “g_” to prefix global variables, it’s common to use “s_” to prefix static (static duration) local variables.
  
  One of the most common uses for static duration local variables is for unique ID generators.
  
  They cannot be tampered with by functions outside of their scope, making them safer than global variables. 
  
  **Best practice**: Initialize your static local variables. Static local variables are only initialized the first time the code is executed, not on subsequent calls.
  
  **Best practice**: Avoid `static` local variables unless the variable never needs to be reset.
  
  ## Reasons to use functions:
  
  - Organization -- As programs grow in complexity, having all the code live inside the main() function becomes increasingly complicated. A function is almost like a mini-program that we can write separately from the main program, without having to think about the rest of the program while we write it. This allows us to reduce a complicated program into smaller, more manageable chunks, which reduces the overall complexity of our program.
  - Reusability -- Once a function is written, it can be called multiple times from within the program. This avoids duplicated code (“Don’t Repeat Yourself”) and minimizes the probability of copy/paste errors. Functions can also be shared with other programs, reducing the amount of code that has to be written from scratch (and retested) each time.
  - Testing -- Because functions reduce code redundancy, there’s less code to test in the first place. Also because functions are self-contained, once we’ve tested a function to ensure it works, we don’t need to test it again unless we change it. This reduces the amount of code we have to test at one time, making it much easier to find bugs (or avoid them in the first place).
  - Extensibility -- When we need to extend our program to handle a case it didn’t handle before, functions allow us to make the change in one place and have that change take effect every time the function is called.
  - Abstraction -- In order to use a function, you only need to know its name, inputs, outputs, and where it lives. You don’t need to know how it works, or what other code it’s dependent upon to use it. This lowers the amount of knowledge required to use other people’s code (including everything in the standard library).
  
  
  
  ### Forward Declaration:
  
  ```cpp
  #include <iostream>
  
  int add(int x, int y); // forward declaration of add() (using a function declaration)
  
  int main()
  {
      std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // this works because we forward declared add() above
      return 0;
  }
  
  int add(int x, int y) // even though the body of add() isn't defined until here
  {
      return x + y;
  }
  ```
  
  ### Definition and declaration:
  
  - A **definition** actually implements (for functions or types) or instantiates (for variables) the identifier. 
  
    In C++, all definitions also serve as declarations. 
  
  A definition is needed to satisfy the *linker*. If you use an identifier without providing a definition, the linker will error.
  
  The **one definition rule** (or ODR for short) is a well-known rule in C++. The ODR has three parts:
  
  1. Within a given *file*, a function, variable, type, or template can only have one definition.
  2. Within a given *program*, a variable or normal function can only have one definition. This distinction is made because programs can have more than one file (we’ll cover this in the next lesson).
  3. Types, templates, inline functions, and inline variables are allowed to have identical definitions in different files. We haven’t covered what most of these things are yet, so don’t worry about this for now -- we’ll bring it back up when it’s relevant.
  
  - A **declaration** is a statement that tells the *compiler* about the existence of an identifier and its type information. (satisfy *compiler*)
  
  ### Multiple files:
  
  **Best practice:** When you add new code files to your project, give them a .cpp extension.
  
  The compiler compiles each file individually. It does not know about the contents of other code files, or remember anything it has seen from previously compiled code files.
  
  This limited visibility and short memory is intentional, so that files may have functions or variables that have the same names without conflicting with each other.
  
  Hence, we need to place a forward declaration before the main function. 
  
  Using this method, we can give files access to functions that live in another file.
  
  **Reminder:** Whenever you create a new code (.cpp) file, you will need to add it to your project so that it gets compiled.
  
  ##### Header Files:
  
  **Key insight:** Header files allow us to put declarations in one location and then import them wherever we need them. This can save a lot of typing in multi-file programs. 
  
  **Best practice:** Header files should generally not contain function and variable definitions, so as not to violate the one definition rule. An exception is made for symbolic constants.
  
  ![image-20221003110345197](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221003110345197.png)
  
  **Best practice:** Use a .h suffix when naming your header files. If a header file is paired with a code file (e.g. add.h with add.cpp), they should both have the same base name (add). 
  
  add.h:
  
  ```cpp
  // 1) We really should have a header guard here, but will omit it for simplicity (we'll cover header guards in the next lesson)
  
  // 2) This is the content of the .h file, which is where the declarations go
  int add(int x, int y); // function prototype for add.h -- don't forget the semicolon!
  ```
  
  add.cpp:
  
  ```cpp
  #include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.
  
  int add(int x, int y)
  {
      return x + y;
  }
  ```
  
  main.cpp:
  
  ```cpp
  #include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.
  #include <iostream>
  
  int main()
  {
      std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
      return 0;
  }
  ```
  
  **Best practice:** Source files should #include their paired header file (if one exists).
  
  **Rule:** Use double quotes to include header files that you’ve written or are expected to be found in the current directory. Use angled brackets to include headers that come with your compiler, OS, or third-party libraries you’ve installed elsewhere on your system.
  
  **Best practice:** When including a header file from the standard library, use the version without the .h extension if it exists. User-defined headers should still use a .h extension.
  
  **Best practice:** Each file should explicitly #include all of the header files it needs to compile. Do not rely on headers included transitively from other headers.
  
  **Best practice:** To maximize the chance that missing includes will be flagged by compiler, order your #includes as follows:
  
  1. The paired header file
  2. Other headers from your project
  3. 3rd party library headers
  4. Standard library headers
  
  The headers for each grouping should be sorted alphabetically.
  
  ###### Header guards: (Good practice to use and learn)
  
  Header guards are conditional compilation directives that take the following form: 
  
  ```cpp
  #ifndef SOME_UNIQUE_NAME_HERE
  #define SOME_UNIQUE_NAME_HERE
  
  // your declarations (and certain types of definitions) here
  
  #endif
  ```
  
  All of your header files should have header guards on them. 
  
  **Best practice:** Favor header guards over `#pragma once` for maximum portability.
  
  ## Namespaces
  
  C++ allows us to define our own namespaces via the `namespace` keyword. Note the use of blocks inside the namespace for defining functions belonging to it.
  
  ```cpp
  #include <iostream>
  
  namespace foo // define a namespace named foo
  {
      // This doSomething() belongs to namespace foo
      int doSomething(int x, int y)
      {
          return x + y;
      }
  }
  
  namespace goo // define a namespace named goo
  {
      // This doSomething() belongs to namespace goo
      int doSomething(int x, int y)
      {
          return x - y;
      }
  }
  
  int main()
  {
      std::cout << foo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace foo
      return 0;
  }
  ```
  
  It’s legal to declare namespace blocks in multiple locations (either across multiple files, or multiple places within the same file). All declarations within the namespace are considered part of the namespace.
  
  Namespaces can be nested inside other namespaces. For example:
  
  ```cpp
  #include <iostream>
  
  namespace foo
  {
      namespace goo // goo is a namespace inside the foo namespace
      {
          int add(int x, int y)
          {
              return x + y;
          }
      }
  }
  
  int main()
  {
      std::cout << foo::goo::add(1, 2) << '\n';
      return 0;
  }
  ```
  
  In applications, namespaces can be used to separate application-specific code from code that might be reusable later (e.g. math functions). For example, physical and math functions could go into one namespace (e.g. `math::`). Language and localization functions in another (e.g. `lang::`).
  
  ### Unnamed and inline namespaces:
  
  An **inline namespace** is a namespace that is typically used to version content.
  
  ```cpp
  #include <iostream>
  
  inline namespace v1 // declare an inline namespace named v1
  {
      void doSomething()
      {
          std::cout << "v1\n";
      }
  }
  
  namespace v2 // declare a normal namespace named v2
  {
      void doSomething()
      {
          std::cout << "v2\n";
      }
  }
  
  int main()
  {
      v1::doSomething(); // calls the v1 version of doSomething()
      v2::doSomething(); // calls the v2 version of doSomething()
  
      doSomething(); // calls the inline version of doSomething() (which is v1)
  
      return 0;
  }
  ```
  
  
  
  ## Inlining
  
  Write the code as part of an existing function. Called writing code “in-place” or “inline. 
  
  Writing functions provides many potential benefits. 
  
  However, one downside of using a function is that every time a function is called, there is a certain amount of performance overhead that occurs.
  
  For functions that are large and/or perform complex tasks, the overhead of the function call is typically insignificant compared to the amount of time the function takes to run.
  
  ### Inline expansion:
  
  **Inline expansion** is a process where a function call is replaced by the code from the called function’s definition.
  
  Beyond removing the cost of function call overhead, inline expansion can also allow the compiler to optimize the resulting code more efficiently.
  
  However, inline expansion has its own potential cost: if the body of the function being expanded takes more instructions than the function call being replaced, then each inline expansion will cause the executable to grow larger. Larger executables tend to be slower (due to not fitting as well in caches). 
  
  **Tip**: Modern optimizing compilers make the decision about when functions should be expanded inline.
  
  **Best practice**: Do not use the `inline` keyword to request inline expansion for your functions.
  
  **Best practice**: Avoid the use of the `inline` keyword for functions unless you have a specific, compelling reason to do so.
  
  ## Constexpr and Consteval functions
  
  **Constexpr functions can be evaluated at compile-time**
  
  To make a function a constexpr function, we simply use the `constexpr` keyword in front of the return type.
  
  **Best practice**: Use a `constexpr` return type for functions that need to return a compile-time constant.
  
  Constexpr functions are implicitly inline. 
  
  **Key insight: **Allowing functions with a constexpr return type to be evaluated at either compile-time or runtime was allowed so that a single function can serve both cases. Otherwise, you’d need to have separate functions (a function with a constexpr return type, and a function with a non-constexpr return type). This would not only require duplicate code, the two functions would also need to have different names!
  
  Check if compiled: (C++20)
  
  ```cpp
  #include <type_traits> // for std::is_constant_evaluated
  constexpr int someFunction()
  {
      if (std::is_constant_evaluated()) // if compile-time evaluation
          // do something
      else // runtime evaluation
          // do something else
  }
  ```
  
  ### Consteval:
  
  C++20 introduces the keyword **consteval**, which is used to indicate that a function *must* evaluate at compile-time, otherwise a compile error will result. Such functions are called **immediate functions**. 
  
  **Best practice**: Use `consteval` if you have a function that must run at compile-time for some reason (e.g. performance).
  
  ```cpp
  #include <iostream>
  
  consteval int greater(int x, int y) // function is now consteval
  {
      return (x > y ? x : y);
  }
  
  int main()
  {
      constexpr int g { greater(5, 6) };            // ok: will evaluate at compile-time
      std::cout << greater(5, 6) << " is greater!\n"; // ok: will evaluate at compile-time
  
      int x{ 5 }; // not constexpr
      std::cout << greater(x, 6) << " is greater!\n"; // error: consteval functions must evaluate at compile-time
  
      return 0;
  }
  ```
  
  
  
  # 5. Debugging
  
  Errors generally fall into one of two categories: syntax errors, and semantic errors (logic errors).
  
  A **syntax error** occurs when you write a statement that is not valid according to the grammar of the C++ language. This includes errors such as missing semicolons, using undeclared variables, mismatched parentheses or braces, etc… For example, the following program contains quite a few syntax errors:
  
  A **semantic error** occurs when a statement is syntactically valid, but does not do what the programmer intended.
  
  ### A general approach to debugging
  
  Once a problem has been identified, debugging the problem generally consists of five steps:
  
  1. Find the root cause of the problem (usually the line of code that’s not working)
  2. Ensure you understand why the issue is occurring
  3. Determine how you’ll fix the issue
  4. Repair the issue causing the problem
  5. Retest to ensure the problem has been fixed and no new problems have emerged
  
  When debugging a program, in most cases the vast majority of your time will be spent trying to find where the error actually is. Once the issue is found, the remaining steps (fixing the issue and validating that the issue was fixed) are often trivial in comparison.
  
  It’s almost impossible to visually spot a bug caused by a bad assumption, because you’re likely to make the same bad assumption when inspecting the code, and not notice the error.
  
  The first and most important step in finding a problem is to be able to *reproduce the problem*. Reproducing the problem means making the problem appear in a consistent manner.
  
  #### Basic Debuggning tactics:
  
  1. Commenting out code
  2. Validating your code flow
     - Print to find function calls, when printing information for debugging purposes, use std::cerr instead of std::cout. (not buffered)
  3. Printing values
  
  Printing is not great though
  
  1. Debug statements clutter your code.
  2. Debug statements clutter the output of your program.
  3. Debug statements must be removed after you’re done with them, which makes them non-reusable.
  4. Debug statements require modification of your code to both add and to remove, which can introduce new bugs.
  
  #### **Conditionalizing your debugging code:**
  
  One way to make it easier to disable and enable debugging throughout your program is to make your debugging statements conditional using preprocessor directives.
  
  If this were a multi-file program, the #define ENABLE_DEBUG would go in a header file that’s included into all code files so we can comment / uncomment the #define in a single location and have it propagate to all code files.
  
  This addresses the issue with having to remove debug statements and the risk in doing so, but at the cost of even more code clutter.
  
  #### Using a logger:
  
  A **log file** is a file (normally stored on disk) that records events that occur in software. 
  
  ### Integrated Debugger
  
  When you run your program, execution begins at the top of the *main* function, and then proceeds sequentially statement by statement, until the program ends. At any point in time while your program is running, the program is keeping track of a lot of things: the value of the variables you’re using, which functions have been called (so that when those functions return, the program will know where to go back to), and the current point of execution within the program (so it knows which statement to execute next). All of this tracked information is called your **program state** (or just *state*, for short).
  
  The power behind the debugger is twofold: the ability to precisely control execution of the program, and the ability to view (and modify, if desired) the program’s state.
  
  Early debuggers, such as [gdb](https://en.wikipedia.org/wiki/Gdb), were separate programs that had command-line interfaces, where the programmer had to type arcane commands to make them work. 
  
  While integrated debuggers are highly convenient and recommended for beginners, command line debuggers are well supported and commonly used in environments that do not support graphical interfaces (e.g. embedded systems).
  
  **Tip:** Don’t neglect learning to use a debugger. As your programs get more complicated, the amount of time you spend learning to use the integrated debugger effectively will pale in comparison to amount of time you save finding and fixing issues.
  
  #### Stepping:
  
  **Stepping** is the name for a set of related debugger features that let us execute (step through) our code statement by statement. 
  
  ##### **Step into:** 
  
  Execute the next statement. (the *step into* command can be accessed via *Debug menu > Step Into*, or by pressing the F11 shortcut key.)
  
  - The program will recompile if needed.
  - The program will begin to run. Because our application is a console program, a console output window should open. It will be empty because we haven’t output anything yet.
  - Your IDE may open some diagnostic windows, which may have names such as “Diagnostic Tools”, “Call Stack”, and “Watch”.
  
  This arrow marker indicates that the line being pointed to will be executed next.
  
  ##### Step over: 
  
  Like *step into*, The **step over** command executes the next statement in the normal execution path of the program. However, whereas *step into* will enter function calls and execute them line by line, *step over* will execute an entire function without stopping and return control to you after the function has been executed.
  
  (In Visual Studio, the *step over* command can be accessed via *Debug menu > Step Over*, or by pressing the F10 shortcut key.)
  
  ##### Step out: 
  
  Unlike the other two stepping commands, **Step out** does not just execute the next line of code. Instead, it executes all remaining code in the function currently being executed, and then returns control to you when the function has returned.
  
  (In Visual Studio, the *step out* command can be accessed via *Debug menu > Step Out*, or by pressing the Shift-F11 shortcut combo.)
  
  ##### Step back:
  
  When stepping through a program, you can normally only step forward. It’s very easy to accidentally step past (overstep) the place you wanted to examine.
  
  If you step past your intended destination, the usual thing to do is stop debugging and restart debugging again, being a little more careful not to pass your target this time.
  
  Some debuggers (such as Visual Studio Enterprise Edition and GDB 7.0) have introduced a stepping capability generally referred to as *step back* or *reverse debugging*.
  
  #### Running and Breakpoints:
  
  ##### Run to cursor:
  
  Executes the program until it reaches the selected statement.
  
  (In Visual Studio, the *run to cursor* command can be accessed by right clicking a statement in your code and choosing *Run to Cursor* from the context menu) 
  
  If you *run to cursor* to a location that doesn’t execute, *run to cursor* will simply run your program until termination.
  
  ##### Continue:
  
  The **continue** debug command simply continues running the program as per normal, either until the program terminates, or until something triggers control to return back to you again (such as a breakpoint). 
  
  (In Visual Studio, the *continue* command can be accessed while already debugging a program via *Debug menu > Continue*)
  
  ##### Start:
  
  The *continue* command has a twin brother named *start*. The *start* command performs the same action as *continue*, just starting from the beginning of the program. It can only be invoked when not already in a debug session.
  
  ##### Breakpoints:
  
  A **breakpoint** is a special marker that tells the debugger to stop execution of the program at the breakpoint when running in debug mode. 
  
  (In Visual Studio, you can set or remove a breakpoint via *Debug menu > Toggle Breakpoint*, or by right clicking on a statement and choosing *Toggle Breakpoint* from the context menu, or by pressing the F9 shortcut key, or by clicking to the left of the line number (in the light grey area).)
  
  Breakpoints have a couple of advantages over *run to cursor*. First, a breakpoint will cause the debugger to return control to you every time they are encountered (unlike *run to cursor*, which only runs when it is invoked). Second, you can set a breakpoint and it will persist until you remove it, whereas with *run to cursor* you have to locate the spot you want to run to each time you invoke the command.
  
  ##### Set next statement: 
  
  The **set next statement** command allows us to change the point of execution to some other statement (sometimes informally called *jumping*). This can be used to jump the point of execution forwards and skip some code that would otherwise execute, or backwards and have something that already executed run again.
  
  (In Visual Studio, you can jump the point of execution by right clicking on a statement and choosing *Set next statement* from the context menu, or by pressing the Ctrl-Shift-F10 shortcut combination. This option is contextual and only occurs while already debugging a program.)
  
  #### Watching variables
  
  Run to a specific line, then you can see the value of initialized variables.
  
  The easiest way to examine the value of a simple variable like x is to hover your mouse over the variable x. Some modern debuggers support this method of inspecting simple variables, and it is the most straightforward way to do so.
  
  Note that you can hover over any variable x, not just the one on the current line. Each displaying the value of x at the current line.
  
  If you’re using Visual Studio, you can also use QuickWatch. Highlight the variable name x with your mouse, and then choose “QuickWatch” from the right-click menu.
  
  ##### **The watch window:**
  
  The **watch window** is a window where you can add variables you would like to continually inspect, and these variables will be updated as you step through your program.
  
  (In Visual Studio, the watch menu can be found at *Debug menu > Windows > Watch > Watch 1*. Do note that you have to be in debug mode for this option to be enabled, so *step into* your program first.)
  
  Variables that go out of scope (e.g. a local variable inside a function that has already returned to the caller) will stay in your watch window, but will generally either be marked as “not available”, or may show the last known value but grayed out. 
  
  ##### Local watches: 
  
  Because inspecting the value of local variables inside a function is common while debugging, many debuggers will offer some way to quickly watch the value of *all* local variables in scope.
  
  (In Visual Studio, you can see the value of all local variables in the *Locals* window, which can be found at *Debug menu > Windows > Locals*. Note that you have to be in a debug session to activate this window)
  
  #### The call stack
  
  The **call stack** is a list of all the active functions that have been called to get to the current point of execution. The call stack includes an entry for each function called, as well as which line of code will be returned to when the function returns. 
  
  Whenever a new function is called, that function is added to the top of the call stack. When the current function returns to the caller, it is removed from the top of the call stack, and control returns to the function just below it.
  
  (In Visual Studio, the call stack window can be found via *Debug menu > Windows > Call Stack*. Note that you have to be in a debug session to activate this window.)
  
  ![image-20221004091553034](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221004091553034.png)
  
  The *line 5* next to function *a* shows us where the current point of execution is (which matches the execution marker in the code window). The *line 17* on the second line indicates the line that will be returned to when control returns to function *main*.
  
  ### Don’t make errors
  
  Well, the best thing is to not make errors in the first place. Here’s an incomplete list of things that can help avoid making errors:
  
  - Follow best practices
  - Don’t program when tired
  - Understand where the common pitfalls are in a language (all those things we warn you not to do)
  - Keep your programs simple
  - Don’t let your functions get too long
  - Prefer using the standard library to writing your own code, when possible
  - Comment your code liberally
  
  **Key insight:** When making changes to your code, make behavioral changes OR structural changes, and then retest for correctness. Making behavioral and structural changes at the same time tends to lead to more errors as well as errors that are harder to find.
  
  **Defensive programming** is a practice whereby the programmer tries to anticipate all of the ways the software could be misused, either by end-users, or by other developers (including the programmer themselves) using the code. These misuses can often be detected and then mitigated (e.g. by asking a user who entered bad input to try again).
  
  ##### Static Analysis Tools: 
  
  Programmers tend to make certain kinds of common mistakes, and some of those mistakes can be discovered by programs trained to look for them. These programs, generally known as **static analysis tools** (sometimes informally called *linters*) are programs that analyze your code to identify specific semantic issues.
  
  On larger non-academic programs, use of a static analysis tool is highly recommended.
  
  **Best practice:** Use a static analysis tool on your programs to help find areas where your code is non-compliant with best practices.
  
  (Visual Studio 2019 comes with a built-in static analysis tool. You can access it via *Build > Run Code Analysis on Solution (Alt+F11)*)
  
  # 6. Data types
  
  One byte is 8 bits!
  
  **Key insight:** In C++, we typically work with “byte-sized” chunks of data.
  
  The data type declares a piece of memory to be interpreted as a specific type. 
  
  #### Object sizes:
  
  Most objects actually take up more than 1 byte of memory. A single object may use 2, 4, 8, or even more consecutive memory addresses. The amount of memory that an object uses is based on its data type. 
  
  To generalize, an object with *n* bits (where n is an integer) can hold $2^n$ unique values.
  
  **Key insight**: New programmers often focus too much on optimizing their code to use as little memory as possible. In most cases, this makes a negligible difference. Focus on writing maintainable code, and optimize only when and where the benefit will be substantive.
  
   You may be surprised to find that the size of a given data type is dependent on the compiler and/or the computer architecture! These are the minimum size in C++:
  
  ![image-20221004100702051](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221004100702051.png)
  
  ##### Sizeof operator:
  
  ```cpp
  sizeof();
  ```
  
  Unary operator. 
  
  Input is either type or variable.
  
  Output is is its size in bytes.
  
  Note that you can not use the *sizeof* operator on the *void* type, since it has no size.
  
  #### Scienfitic Notation:
  
  Written as:
  
  1.2e4 or 1.2e-5
  
  ### Fundamental Data types:
  
  C++ comes with built-in support for many different data types. These are called **fundamental data types**.
  
  ![image-20221004095912020](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221004095912020.png)
  
  
  
  #### Void:
  
  *Void* basically means "no type". 
  
  Used to indicate a function not returning a value. 
  
  **Best practice:** Use an empty parameter list instead of *void* to indicate that a function has no parameters. 
  
  #### Signed integers:
  
  An **integer** is an integral type that can represent positive and negative whole numbers. 4 types in C++:
  
  ![image-20221004101248251](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221004101248251.png)
  
  Defined the following way:
  
  ```cpp
  short s;      // prefer "short" instead of "short int" 			127
  int i;														32 767	
  long l;       // prefer "long" instead of "long int"			2 147 483 647 
  long long ll; // prefer "long long" instead of "long long int"	 loooong
  ```
  
  **Best practice:** Prefer the shorthand types that do not use the *int* suffix or signed prefix.
  
  The range of the types are $2^{n-1}-1$. 
  
  **Warning:** Signed integer overflow will result in undefined behavior.
  
  ###### Integer division:
  
  When doing division with two integers (called **integer division**), C++ always produces an integer result. Since integers can’t hold fractional values, any fractional portion is simply dropped (not rounded!).
  
  ##### Unsigned integers:
  
  **Unsigned integers** are integers that can only hold non-negative whole numbers.
  
  ```cpp
  unsigned short us;
  unsigned int ui;
  unsigned long ul;
  unsigned long long ull;
  ```
  
  When no negative numbers are required, unsigned integers are well-suited for networking and systems with little memory, because unsigned integers can store more positive numbers without taking up extra memory.
  
  Many developers (and some large development houses, such as Google) believe that developers should generally avoid unsigned integers.
  
  Unexpected behavior can result when you mix signed and unsigned integers.
  
  **Best practice**: Favor signed numbers over unsigned numbers for holding quantities (even quantities that should be non-negative) and mathematical operations. Avoid mixing signed and unsigned numbers.
  
  ##### Why isn’t the size of the integer variables fixed?
  
  The short answer is that this goes back to C, when computers were slow and performance was of the utmost concern. C opted to intentionally leave the size of an integer open so that the compiler implementers could pick a size for int that performs best on the target computer architecture.
  
  **Fixed-width integers**: To address the above issues, C99 defined a set of **fixed-width integers** (in the stdint.h header) that are guaranteed to be the same size on any architecture.
  
  ![image-20221004102627960](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221004102627960.png)
  
  Need to include: <cstdint>
  
  Just because your CPU can process a given type faster doesn’t mean your program will be faster overall -- modern programs are often constrained by memory usage rather than CPU, and the larger memory footprint may slow your program more than the faster CPU processing accelerates it. It’s hard to know without actually measuring. 
  
  **Best practice:**
  
  - Prefer `int` when the size of the integer doesn’t matter (e.g. the number will always fit within the range of a 2-byte signed integer). For example, if you’re asking the user to enter their age, or counting from 1 to 10, it doesn’t matter whether int is 16 or 32 bits (the numbers will fit either way). This will cover the vast majority of the cases you’re likely to run across.
  - Prefer `std::int#_t` when storing a quantity that needs a guaranteed range.
  - Prefer `std::uint#_t` when doing bit manipulation or where well-defined wrap-around behavior is required.
  
  Avoid the following when possible:
  
  - Unsigned types for holding quantities
  - The 8-bit fixed-width integer types
  - The fast and least fixed-width types
  - Any compiler-specific fixed-width integers -- for example, Visual Studio defines __int8, __int16, etc…
  
  ##### **What is std::size_t?**
  
  The answer is that sizeof (and many functions that return a size or length value) return a value of type *std::size_t*. **std::size_t** is defined as an unsigned integral type, and it is typically used to represent the size or length of objects.
  
  #### Floating Point Numbers
  
  The *floating* part of the name *floating point* refers to the fact that the decimal point can “float”; that is, it can support a variable number of digits before and after the decimal point. 
  
  Floating point data types are always signed (can hold positive and negative values).
  
  **Best practice:** Favor double over float unless space is at a premium, as the lack of precision in a float will often lead to inaccuracies.
  
  ![image-20221004103554863](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221004103554863.png)
  
  ```cpp
  float fValue;
  double dValue;
  long double ldValue;
  ```
  
  When using floating point literals, always include at least one decimal place (even if the decimal is 0). This helps the compiler understand that the number is a floating point number and not an integer.
  
  **Best practice:** Always make sure the type of your literals match the type of the variables they’re being assigned to or used to initialize. Otherwise an unnecessary conversion will result, possibly with a loss of precision.
  
  ##### Range:
  
  ![image-20221004103811619](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221004103811619.png)
  
  The **precision** of a floating point number defines how many *significant digits* it can represent without information loss.
  
  ##### NaN and Inf:
  
  There are two special categories of floating point numbers. The first is **Inf**, which represents infinity. Inf can be positive or negative. The second is **NaN**, which stands for “Not a Number”. 
  
  #### Booleans
  
  Boolean variables are variables that can have only two possible values: *true*, and *false*.
  
  ```cpp
  bool b1 { true };
  bool b2 { false };
  b1 = false;
  bool b3 {}; // default initialize to false
  ```
  
  When we print Boolean values, std::cout prints *0* for *false*, and *1* for *true*. 
  
  To get *true* and *false* use: std::cout << std::boolalpha;
  
  #### Characters
  
  The char data type is an integral type, meaning the underlying value is stored as an integer. The integer stored by a `char` variable are intepreted as an `ASCII character`.
  
  You can initialize char variables using character literals:
  
  ```cpp
  char ch2{ 'a' }; // initialize with code point for 'a' (stored as integer 97) (preferred)
  char ch1{ 97 }; // initialize with integer 97 ('a') (not preferred)
  ```
  
  When using std::cout to print a char, std::cout outputs the char variable as an ASCII character, eg. 97 becomes 'a'. 
  
  If you want to read in more than one char at a time (e.g. to read in a name, word, or sentence), you’ll want to use a string instead of a char. A **string** is a collection of sequential characters (and thus, a string can hold multiple symbols).
  
  Single chars are always put in single quotes
  
  Text put between double quotes (e.g. “Hello, world!”) is treated as a string.
  
  **Best practice:** Put stand-alone chars in single quotes (e.g. ‘t’ or ‘\n’, not “t” or “\n”). This helps the compiler optimize more effectively.
  
  ##### Escape Sequences: (TODO:)
  
  ![image-20221004110704612](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221004110704612.png)
  
  #### Constant variables
  
  In programming, a **constant** is a value that may not be changed. 
  
  ```cpp
  const double gravity { 9.8 };  // preferred use of const before type
  int const sidesInSquare { 4 }; // "east const" style, okay but not preferred
  ```
  
  **Best practice:** Place `const` before the type (because it is more idiomatic to do so).
  
  **Best practice:** Don’t use `const` when passing by value. (such as function arguments)
  
  **Best practice**: Prefer constant variables over object-like macros with substitution text.
  
  ##### Constant expressions:
  
  A **constant expression** is an expression that can be evaluated by the compiler at compile-time. 
  
  **Key insight:** Evaluating constant expressions at compile-time makes our compilation take longer (because the compiler has to do more work), but such expressions only need to be evaluated once (rather than every time the program is run). The resulting executables are faster and use less memory.
  
  A const variable is a compile-time constant if its initializer is a constant expression. (eg, const int etc...)
  
  Compile-time constants enable the compiler to perform optimizations that aren’t available with non-compile-time constants. For example, for example whenever the constant `gravity` is used, the compiler can simply substitute the identifier `gravity` with the literal double `9.8`, which avoids having to fetch the value from somewhere in memory.
  
  **Runtime constants** are constants whose initialization values aren’t known until runtime.
  
  When using `const`, our variables could end up as either a compile-time const or a runtime const, depending on whether the initializer is a compile-time expression or not.
  
  A **constexpr** (which is short for “constant expression”) variable can only be a compile-time constant. If the initialization value of a constexpr variable is not a constant expression, the compiler will error.
  
  **Best practice:**
  
  1. Any variable that should not be modifiable after initialization and whose initializer is known at compile-time should be declared as `constexpr`.
  2. Any variable that should not be modifiable after initialization and whose initializer is not known at compile-time should be declared as `const`.
  
  Keep in mind the compiler can optimize in more ways!
  
  #### Literals
  
  **Literals** are unnamed values inserted directly into the code. For example:
  
  ```cpp
  return 5;                   // 5 is an integer literal
  bool myNameIsAlex { true }; // true is a boolean literal
  std::cout << 3.4;           // 3.4 is a double literal
  ```
  
  Literals are sometimes called **literal constants** because their values cannot be reassigned.
  
  Just like objects have a type, all literals have a type. The type of a literal is deduced from the literal’s value. For example, a literal that is a whole number (e.g. `5`) is deduced to be of type `int`.
  
  **Best practice**: Prefer literal suffix L (upper case) over l (lower case).
  
  ![image-20221004113428423](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221004113428423.png)
  
  ##### Magic numbers:
  
  A **magic number** is a literal (usually a number) that either has an unclear meaning or may need to be changed later.
  
  In complex programs, it can be very difficult to infer what a literal represents, unless there’s a comment to explain it.
  
  **Best practice:** Avoid magic numbers in your code (use constexpr variables instead).
  
  ## Type Conversions:
  
  The value of an object is stored as a sequence of bits, and the data type of the object tells the compiler how to interpret those bits into meaningful values. Different data types may represent the “same” number differently.
  
  For example, the integer value 3 might be stored as binary `0000 0000 0000 0000 0000 0000 0000 0011`, whereas floating point value 3.0 might be stored as binary `0100 0000 0100 0000 0000 0000 0000 0000`.
  
  In most cases, C++ will allow us convert values of one fundamental type to another fundamental type. The process of converting a value from one type to another type is called **type conversion**.
  
  When the compiler does type conversion on our behalf without us explicitly asking, we call this **implicit type conversion**. Eg. double 5.0 become int 5.
  
  **Key insight:** Type conversion produces a new value of the target type from a value of a different type.
  
  **Key insight:** Some type conversions are always safe to make (such as `int` to `double`), whereas others may result in the value being changed during conversion (such as `double` to `int`). Unsafe implicit conversions will typically either generate a compiler warning, or (in the case of brace initialization) an error.
  
  ### Explicit type conversion
  
  ```cpp
  static_cast<new_type>(expression)
  ```
  
  **Key insight:** Whenever you see C++ syntax (excluding the preprocessor) that makes use of angled brackets (<>), the thing between the angled brackets will most likely be a type. This is typically how C++ deals with code that need a parameterized type.
  
  **Warning:** The static_cast operator will produce undefined behavior if the value being converted doesn’t fit in range of the new type.
  
  
  
  TODO: more later
  
  Example:
  
  ```cpp
  char ch{ 97 }; // 97 is ASCII code for 'a'
  std::cout << ch << " has value " << static_cast<int>(ch) << '\n'; // print value of variable ch as an int
  ```
  
  ### Implicit type conversion
  
  Performed automatically by the compiler when one data type is required, but a different data type is supplied.
  
  When a type conversion is invoked (whether implicitly or explicitly), the compiler will determine whether it can convert the value from the current type to the desired type. If a valid conversion can be found, then the compiler will produce a new value of the desired type.
  
  If the compiler can’t find an acceptable conversion, then the compilation will fail with a compile error.
  
  **As an aside:** How do you have a type conversion with zero conversions? As an example, on architectures where `int` and `long` both have the same size and range, the same sequence of bits is used to represent values of both types. Therefore, no actual conversion is needed to convert a value between those types -- the value can simply be copied.
  
  The C++ language standard defines how different fundamental types (and in some cases, compound types) can be converted to other types. These conversion rules are called the **standard conversions**.
  
  ### Numeric Promotions
  
  **A reminder:** The number of bits a data type uses is called its width. A wider data type is one that uses more bits, and a narrower data type is one that uses less bits.
  
  Because C++ is designed to be portable and performant across a wide range of architectures, the language designers did not want to assume a given CPU would be able to efficiently manipulate values that were narrower than the natural data size for that CPU. 
  
  A **numeric promotion** is the type conversion of a narrower numeric type (such as a `char`) to a wider numeric type (typically `int` or `double`) that can be processed efficiently and is less likely to have a result that overflows. 
  
  All numeric promotions are **value-preserving**, which means that all values in the original type are representable without loss of data or precision in the new type. Because such promotions are safe, the compiler will freely use numeric promotion as needed, and will not issue a warning when doing so.
  
  Create a function that only has int as input argument. Numeric promotion can allow us to called with types tha can be **numerically promoted** to match the function parameters.
  
  #### Floating Point Promotion
  
  Using the **floating point promotion** rules, a value of type `float` can be converted to a value of type `double`. 
  
  #### Integral promotion
  
  More complicated than previous category.
  
  - signed char or signed short can be converted to int.
  - unsigned char, char8_t, and unsigned short can be converted to int if int can hold the entire range of the type, or unsigned int otherwise.
  - If char is signed by default, it follows the signed char conversion rules above. If it is unsigned by default, it follows the unsigned char conversion rules above.
  - bool can be converted to int, with false becoming 0 and true becoming 1.
  
  ### Numeric Conversions
  
  C++ supports another category of numeric type conversions, called **numeric conversions**, that cover additional type conversions not covered by the numeric promotion rules. 
  
  #### Narrowing conversions
  
  Unlike a numeric promotion (which is always safe), a numeric conversion may (or may not) result in the loss of data or precision.
  
  **Warning**: Compilers will often *not* warn when converting a signed int to an unsigned int, or vice-versa, even though these are narrowing conversions. Be extra careful of inadvertent conversions between these types (particularly when passing an argument to a function taking a parameter of the opposite sign).
  
  **Best practice**: Avoid narrowing conversions whenever possible. If you do need to perform one, use `static_cast` to make it an explicit conversion.
  
  ### Arithmetic Conversions
  
  ### Other Conversions
  
  
  
  
  
  ## Extra:
  
  ##### Outputting values in decimal, octal, or hexadecimal:
  
  By default, C++ outputs values in decimal. However, you can change the output format via use of the `std::dec`, `std::oct`, and `std::hex` I/O manipulators.
  
  ## 7. Blocks
  
  A **compound statement** (also called a **block**, or **block statement**) is a group of *zero or more statements* that is treated by the compiler as if it were a single statement.
  
  Blocks begin with a `{` symbol, end with a `}` symbol, with the statements to be executed being placed in between.
  
  Although functions can’t be nested inside other functions, blocks *can be* nested inside other blocks.
  
  **Best practice:** Keep the nesting level of your functions to 3 or less. If your function has a need for more nested levels, consider refactoring your function into sub-functions.
  
  Local variables have **block scope**, which means they are *in scope* from their point of definition to the end of the block they are defined within.
  
  Identifiers have another property named `linkage`. An identifier’s **linkage** determines whether other declarations of that name refer to the same object or not.
  
  Local variables have `no linkage`, which means that each declaration refers to a unique object. Eg. we use x in main and in a block inside main, no problem if first x is not used inside block!
  
  The nested variable “hides” the outer variable in areas where they are both in scope. This is called **name hiding** or **shadowing**.
  
  **Best practice:** Define variables in the most limited existing scope. Avoid creating new blocks whose only purpose is to limit the scope of variables.
  
  Local variables with the same name as a global variable will shadow the global variable wherever the local variable is in scope.
  
  **Best practice:** Avoid variable shadowing.
  
  ![image-20221005103545718](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221005103545718.png)
  
  ### Global Variables
  
  In C++, variables can also be declared *outside* of a function. Such variables are called **global variables**.
  
  By convention, global variables are declared at the top of a file, below the includes, but above any code. Here’s an example of a global variable being defined.
  
  **Best practice:** Consider using a “g” or “g_” prefix for global variables to help differentiate them from local variables.
  
  **Advice:** Prefix all non-namespaced global variables with “g” or “g_”, or better yet, put them in a namespace (constants namespace say)
  
  Global variables have **file scope** (also informally called **global scope** or **global namespace scope**), which means they are visible from the point of declaration until the end of the *file* in which they are declared.
  
  Because global variables are part of the global namespace, we can use the scope operator (::) with no prefix to tell the compiler we mean the global variable instead of the local variable.
  
  #### Linkage
  
  Global variable and functions identifiers can have either `internal linkage` or external linkage.
  
  ##### Internal linkage: 
  
  An identifier with **internal linkage** can be seen and used within a single file, but it is not accessible from other files (that is, it is not exposed to the linker).
  
  Global variables with internal linkage are sometimes called **internal variables**.
  
  To make a non-constant global variable internal, we use the `static` keyword.
  
  Const and constexpr global variables have internal linkage by default.
  
  However, it’s worth noting that internal objects (and functions) that are defined in different files are considered to be independent entities (even if their names and types are identical), so there is no violation of the one-definition rule. Each internal object only has one definition.
  
  Functions default to external linkage (which we’ll cover in the next lesson), but can be set to internal linkage via the `static` keyword.
  
  ##### External Linkage: 
  
  An identifier with **external linkage** can be seen and used both from the file in which it is defined, and from other code files (via a forward declaration). In this sense, identifiers with external linkage are truly “global” in that they can be used anywhere in your program!
  
  **Functions have external linkage by default**
  
  But in order to call a function defined in another file, you must place a `forward declaration` for the function in any other files wishing to use the function.
  
  To make a global variable external (and thus accessible by other files), we can use the `extern` keyword to do so.
  
  To actually use an external global variable that has been defined in another file, you also must place a `forward declaration` for the global variable in any other files wishing to use the variable.
  
  **Warning**: If you want to define an uninitialized non-const global variable, do not use the extern keyword, otherwise C++ will think you’re trying to make a forward declaration for the variable. (Declare and initialize at the same time)
  
  
  
  The term “file scope” is more often applied to global variables with internal linkage, and “global scope” to global variables with external linkage (since they can be used across the whole program, with the appropriate forward declarations).
  
  #### Why to avoid global avariables:
  
  Although they may seem harmless in small academic programs, they are often problematic in larger ones.
  
  Mostly about **non-const global** variables.
  
  In short, global variables make the program’s state unpredictable. They could be changed easily! But constants prevent it.
  
  **Best practice**: Use local variables instead of global variables whenever possible.
  
  **If used:** There should only ever be one of the thing the variable represents in your program, and its use should be ubiquitous throughout your program.
  
  ##### Static Initialization:
  
  In the static initialization phase, global variables with constexpr initializers (including literals) are initialized to those values. Also, global variables without initializers are zero-initialized. 
  
  ##### Dynamic Initialiation: 
  
  This phase is more complex and nuanced, but the gist of it is that global variables with non-constexpr initializers are initialized. 
  
  Forward declarations do not initialize, which can cause errors. 
  
  But more of a problem, the order of initialization across different files is not defined.
  
  **Warning**: Dynamic initialization of global variables causes a lot of problems in C++. Avoid dynamic initialization whenever possible.
  
  #### Sharing global constants across files: 
  
  1. Create a header file to hold these constants
  2. Inside this header file, define a namespace (discussed in lesson [6.2 -- User-defined namespaces and the scope resolution operator](https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/))
  3. Add all your constants inside the namespace (make sure they’re *constexpr*)
  4. \#include the header file wherever you need it
  
  Example file: constants.h
  
  ```cpp
  #ifndef CONSTANTS_H
  #define CONSTANTS_H
  
  // define your own namespace to hold constants
  namespace constants
  {
      // constants have internal linkage by default
      constexpr double pi { 3.14159 };
      constexpr double avogadro { 6.0221413e23 };
      constexpr double myGravity { 9.2 }; // m/s^2 -- gravity is light on this planet
      // ... other related constants
  }
  #endif
  ```
  
  Then use the scope resolution operator (::) with the namespace name to the left, and your variable name to the right in order to access your constants in .cpp files. 
  
  A downside is the need to include in potentially many files, which is expensive memory vise. 
  
  ##### External global variables:
  
  The downsides can be solved by turning the global variables into external variables. 
  
  Define constants in cpp file:
  
  ```cpp
  #include "constants.h"
  
  namespace constants
  {
      // actual global variables
      extern const double pi { 3.14159 };
      extern const double avogadro { 6.0221413e23 };
      extern const double myGravity { 9.2 }; // m/s^2 -- gravity is light on this planet
  }
  ```
  
  Then put forward declarations in header file:
  
  ```cpp
  #ifndef CONSTANTS_H
  #define CONSTANTS_H
  
  namespace constants
  {
      // since the actual variables are inside a namespace, the forward declarations need to be inside a namespace as well
      extern const double pi;
      extern const double avogadro;
      extern const double myGravity;
  }
  
  #endif
  ```
  
  The usage in the code files stay the same.
  
  However, there are a couple of downsides to this method. First, these constants are now considered compile-time constants only within the file they are actually defined in. 
  
  In other files, the compiler will only see the forward declaration, which doesn’t define a constant value (and must be resolved by the linker). This means in other files, these are treated as runtime constant values.
  
  **Key insight:** In order for variables to be usable in compile-time contexts, such as array sizes, the compiler has to see the variable’s definition (not just a forward declaration).
  
  Given the above downsides, prefer defining your constants in the header file, previous method!
  
  #### Inline: 
  
  Only from C++17 and forward.
  
   Let’s say you have a normal constant that you’re #including into 10 code files. Without inline, you get 10 definitions. With inline, the compiler picks 1 definition to be the canonical definition, so you only get 1 definition. This means you save 9 constants worth of memory.
  
  Inline variables have two primary restrictions that must be obeyed:
  
  1. All definitions of the inline variable must be identical (otherwise, undefined behavior will result).
  2. The inline variable definition (not a forward declaration) must be present in any file that uses the variable.
  
  Header file: 
  
  ```cpp
  #ifndef CONSTANTS_H
  #define CONSTANTS_H
  
  // define your own namespace to hold constants
  namespace constants
  {
      inline constexpr double pi { 3.14159 }; // note: now inline constexpr
      inline constexpr double avogadro { 6.0221413e23 };
      inline constexpr double myGravity { 9.2 }; // m/s^2 -- gravity is light on this planet
      // ... other related constants
  }
  #endif
  ```
  
  Cpp file: 
  
  ```cpp
  #include "constants.h"
  
  #include <iostream>
  
  int main()
  {
      std::cout << "Enter a radius: ";
      int radius{};
      std::cin >> radius;
  
      std::cout << "The circumference is: " << 2.0 * radius * constants::pi << '\n';
  
      return 0;
  }
  ```
  
  This method does retain the downside of requiring every file that includes the constants header to be recompiled if any constant value is changed. Otherwise superior to previous.
  
  **Best practice**: If you need global constants and your compiler is C++17 capable, prefer defining inline constexpr global variables in a header file.
  
  
  
  ## 8. Control Flow
  
  **Control flow statements** (also called **flow control statements**), are statements that allow the programmer to change the normal path of execution through the program. 
  
  When a `control flow statement` causes point of execution to change to a non-sequential statement, this is called **branching**.
  
  ![image-20221005133542999](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221005133542999.png)
  
  ### If statements 
  
  Use blocks for each statement. Not needed if only one statement though. 
  
  **Best practice**: Consider putting single statements associated with an `if` or `else` in blocks (particularly while you are learning). More experienced C++ developers sometimes disregard this practice in favor of tighter vertical spacing.
  
  **Warning:** Initialization of variables inside a block will be local, and destroyed at the end of block. 
  
  A **null statement** is an expression statement that consists of just a semicolon. Don't put them at the end of the condition! 
  
  **Warning**: Be careful not to “terminate” your `if statement` with a semicolon, otherwise your conditional statement(s) will execute unconditionally (even if they are inside a block).
  
  ```cpp
  if (x > 0)
  {
      std::cout << "The value is positive\n";
  }
  else if (x < 0)
  {
  	std::cout << "The value is negative\n";
  }
  else 
  {
      std::cout << "The value is zero\n";    
  }
  
  ```
  
  To properly comply with C++’s type checking, either the type of both expressions in a conditional statement must match, or the both expressions must be convertible to a common type.
  
  The conversion rules used when the types don’t match are rather complicated. You can find them [here](https://en.cppreference.com/w/cpp/language/operator_other).
  
  The condition in paranthesis return either 0 "false" or 1 "true". So if(0) is false, while if(1) is true. 
  
  #### Logicals:
  
  **Warning:** Avoid using operator== and operator!= to compare floating point values if there is any chance those values have been calculated.
  
  **Best practice:** Don’t add unnecessary == or != to conditions. It makes them harder to read without offering any additional value.
  
  ![image-20221004135320333](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221004135320333.png)
  
  **Best practice**: If *logical NOT* is intended to operate on the result of other operators, the other operators and their operands need to be enclosed in parentheses.
  
  **Key insight**: The Logical OR and logical AND operators are an exception to the rule that the operands may evaluate in any order, as the standard explicitly states that the left operand must evaluate first.
  
  **Best practice**: When mixing *logical AND* and *logical OR* in a single expression, explicitly parenthesize each operation to ensure they evaluate how you intend.
  
  ### Switch Statement
  
  Because testing a variable or expression for equality against a set of different values is common, C++ provides an alternative conditional statement called a **switch statement** that is specialized for this purpose.
  
  The idea behind a **switch statement** is simple: an expression (sometimes called the `condition`) is evaluated to produce a value. If the expression’s value is equal to the value after any of the `case labels`, the statements after the matching `case label` are executed. If no matching value can be found and a `default label` exists, the statements after the `default label` are executed instead.
  
  ```cpp
  #include <iostream>
  
  void printDigitName(int x)
  {
      switch (x)
      {
          case 1:
              std::cout << "One";
              return;
          case 2:
              std::cout << "Two";
              return;
          case 3:
              std::cout << "Three";
              return;
          default:
              std::cout << "Unknown";
              return;
      }
  }
  
  int main()
  {
      printDigitName(2);
      std::cout << '\n';
  
      return 0;
  }
  ```
  
  **Best practice**: Prefer `switch statements` over if-else chains when there is a choice.
  
  The one restriction is that the condition must evaluate to an integral type. 
  
  Why does the switch type only allow for integral (or enumerated) types? The answer is because switch statements are designed to be highly optimized. 
  
  There is no practical limit to the number of case labels you can have, but all case labels in a switch must be unique.
  
  **Best practice**: Place the default case last in the switch block.
  
  A **break statement** (declared using the `break` keyword) tells the compiler that we are done executing statements within the switch, and that execution should continue with the statement after the end of the switch block. This allows us to exit a `switch statement` without exiting the entire function.
  
  **Best practice**: Each set of statements underneath a label should end in a `break statement` or a `return statement`. This includes the statements underneath the last label in the switch. 
  
  **Warning**: Once the statements underneath a case or default label have started executing, they will overflow (fallthrough) into subsequent cases. `Break` or `return` statements are typically used to prevent this.
  
  **Attributes** are a modern C++ feature that allows the programmer to provide the compiler with some additional data about the code. To specify an attribute, the attribute name is placed between double hard braces. Attributes are not statements -- rather, they can be used almost anywhere where they are contextually relevant.
  
  The `[[fallthrough]]` attribute modifies a `null statement` to indicate that fallthrough is intentional (and no warnings should be triggered). 
  
  **Best practice**: Use the `[[fallthrough]]` attribute (along with a null statement) to indicate intentional fallthrough.
  
  Unlike *if statements* the statements after labels are all scoped to the the switch block. No implicit blocks are created.
  
  **Best practice**: If defining variables used in a case statement, do so in a block inside the case.
  
  ### Goto statement
  
  Goto is an unconditional jump. An unconditional jump causes execution to jump to another spot in the code. The term “unconditional” means the jump always happens. 
  
  ```cpp
  #include <iostream>
  #include <cmath> // for sqrt() function
  
  int main()
  {
      double x{};
  tryAgain: // this is a statement label
      std::cout << "Enter a non-negative number: ";
      std::cin >> x;
  
      if (x < 0.0)
          goto tryAgain; // this is the goto statement
  
      std::cout << "The square root of " << x << " is " << std::sqrt(x) << '\n';
      return 0;
  }
  ```
  
  In this program, the user is asked to enter a non-negative number. However, if a negative number is entered, the program utilizes a `goto statement` to jump back to the tryAgain label. The user is then asked again to enter a new number. In this way, we can continually ask the user for input until he or she enters something valid.
  
  The `goto statement` and its corresponding `statement label` must appear in the same function.
  
  Can be used to jump forward as well:
  
  ```cpp
  #include <iostream>
  
  void printCats(bool skip)
  {
      if (skip)
          goto end; // jump forward; statement label 'end' is visible here due to it having function scope
  
      std::cout << "cats\n";
  end:
      ; // statement labels must be associated with a statement
  }
  
  int main()
  {
      printCats(true);  // jumps over the print statement and doesn't print anything
      printCats(false); // prints "cats"
  
      return 0;
  }
  ```
  
  There are two primary limitations to jumping: You can jump only within the bounds of a single function (you can’t jump out of one function and into another), and if you jump forward, you can’t jump forward over the initialization of any variable that is still in scope at the location being jumped to. For example:
  
  **Best practice**: Avoid `goto statements` (unless the alternatives are significantly worse for code readability).
  
  Almost any code written using a `goto statement` can be more clearly written using other constructs in C++, such as `if statements` and loops. One notable exception is when you need to exit a nested loop but not the entire function -- in such a case, a `goto` to just beyond the loops is probably the cleanest solution.
  
  ### While Loop
  
  A `while statement` is declared using the **while** keyword. When a `while statement` is executed, the `condition` is evaluated. If the condition evaluates to `true`, the associated statement executes.
  
  ```cpp
  #include <iostream>
  
  int main()
  {
      int count{ 1 };
      while (count <= 10)
      {
          std::cout << count << ' ';
          ++count;
      }
  
      std::cout << "done!\n";
  
      return 0;
  }
  ```
  
  Infinte loop:
  
  ```cpp
  #include <iostream>
  
  int main()
  {
  
      while (true) // infinite loop
      {
          std::cout << "Loop again (y/n)? ";
          char c{};
          std::cin >> c;
  
          if (c == 'n')
              return 0;
      }
  
      return 0;
  }
  ```
  
  **Best practice**: Favor `while(true)` for intentional infinite loops.
  
  **Best practice**: Loop variables should be of type (signed) int.
  
  ### Do While Loop
  
  A **do while statement** is a looping construct that works just like a while loop, except the statement always executes at least once. After the statement has been executed, the do-while loop checks the condition. If the condition evaluates to `true`, the path of execution jumps back to the top of the do-while loop and executes it again.
  
  ```cpp
  #include <iostream>
  
  int main()
  {
      // selection must be declared outside of the do-while so we can use it later
      int selection{};
  
      do
      {
          std::cout << "Please make a selection: \n";
          std::cout << "1) Addition\n";
          std::cout << "2) Subtraction\n";
          std::cout << "3) Multiplication\n";
          std::cout << "4) Division\n";
          std::cin >> selection;
      }
      while (selection != 1 && selection != 2 &&
          selection != 3 && selection != 4);
  
      // do something with selection here
      // such as a switch statement
  
      std::cout << "You selected option #" << selection << '\n';
  
      return 0;
  }
  ```
  
  One thing worth discussing in the above example is that the `selection` variable must be declared outside of the do block. If the `selection` variable were to be declared inside the do block, it would be destroyed when the do block terminates, which happens before the conditional is evaluated. 
  
  **Best practice**: Favor while loops over do-while when given an equal choice.
  
  ### For Loop
  
  **Best practice**:
  
  - Prefer `for loops` over `while loops` when there is an obvious loop variable.
  - Prefer `while loops` over `for loops` when there is no obvious loop variable.
  
  
  
  As of C++11, there are two different kinds of `for loops`. The classic `for statement`, and the newer `range-based for statement`. 
  
  A `for statement` is evaluated in 3 parts:
  
  First, the init-statement is executed. This only happens once when the loop is initiated. The init-statement is typically used for variable definition and initialization. These variables have “loop scope”, which really just is a form of block scope where these variables exist from the point of definition through the end of the loop statement.
  
  Second, for each loop iteration, the condition is evaluated. If this evaluates to true, the statement is executed. 
  
  Finally, after the statement is executed, the end-expression is evaluated. Typically, this expression is used to increment or decrement the loop variables defined in the init-statement.
  
  Example:
  
  ```cpp
  #include <iostream>
  
  int main()
  {
      for (int count{ 9 }; count >= 0; --count) \\ Initial, Condition and end-expression
      {
           std::cout << count << ' ';
      }
  
      std::cout << '\n';
  
      return 0;
  }
  ```
  
  When writing a loop condition involving a value, we can often write the condition in many different ways.
  
  **Best practice**: Avoid `operator!=` when doing numeric comparisons in the for-loop condition.
  
  #### Omit statements:
  
  It is possible to write *for loops* that omit any or all of the statements or expressions. For example, in the following example, we’ll omit the init-statement and end-expression, leaving only the condition. 
  
  ```cpp
  #include <iostream>
  
  int main()
  {
      int count{ 0 };
      for ( ; count < 10; ) // no init-statement or end-expression
      {
          std::cout << count << ' ';
          ++count;
      }
  
      std::cout << '\n';
  
      return 0;
  }
  ```
  
  You’d probably expect an omitted condition-expression to be treated as `false`. However, the C++ standard explicitly (and inconsistently) defines that an omitted condition-expression in a for loop should be treated as `true`.
  
  Recommend avoiding this form of the for loop altogether and using `while(true)` instead.
  
  #### Multiple variables:
  
  Although `for loops` typically iterate over only one variable, sometimes `for loops` need to work with multiple variables. To assist with this, the programmer can define multiple variables in the init-statement, and can make use of the comma operator to change the value of multiple variables in the end-expression:
  
  ```cpp
  #include <iostream>
  
  int main()
  {
      for (int x{ 0 }, y{ 9 }; x < 10; ++x, --y)
          std::cout << x << ' ' << y << '\n';
  
      return 0;
  }
  ```
  
  **Best practice**: Defining multiple variables (in the init-statement) and using the comma operator (in the end-expression) is acceptable inside a `for statement`.
  
  ### Break and Continue
  
  Many textbooks caution readers not to use `break` and `continue` in loops, both because it causes the execution flow to jump around, and because it can make the flow of logic harder to follow. 
  
  However, used judiciously, `break` and `continue` can help make loops more readable by keeping the number of nested blocks down and reducing the need for complicated looping logic.
  
  **Best practice**: Use break and continue when they simplify your loop logic.
  
  **Best practice**: Use early returns when they simplify your function’s logic.
  
  #### Break: 
  
  In the context of a loop, a break statement can be used to end the loop early. Execution continues with the next statement after the end of the loop.
  
  Break is also a common way to get out of an intentional infinite loop.
  
  A `return statement` terminates the entire function that the loop is within, and execution continues at point where the function was called. The break terminates the loop only.
  
  #### Continue:
  
  The **continue statement** provides a convenient way to end the current iteration of a loop without terminating the entire loop.
  
  In the case of a for loop, the end-statement of the for loop still executes after a continue (since this happens after the end of the loop body).
  
  Be careful when using a `continue statement` with while or do-while loops. These loops typically change the value of variables used in the condition inside the loop body. If use of a `continue statement` causes these lines to be skipped, then the loop can become infinite!
  
  ### Halts
  
  A **halt** is a flow control statement that terminates the program.
  
   In C++, halts are implemented as functions (rather than keywords), so our halt statements will be function calls.
  
  When a program exits normally. The `main()` function returns (either by reaching the end of the function, or via a `return statement`), a number of different things happen. 
  
  **First**, because we’re leaving the function, all local variables and function parameters are destroyed (as per usual).
  
  **Next**, a special function called `std::exit()` is called, with the return value from `main()` (the `status code`) passed in as an argument.
  
  Although `std::exit()` is called implicitly when function `main()` ends, `std::exit()` can also be called explicitly to halt the program before it would normally terminate.
  
  Example:
  
  ```cpp
  #include <cstdlib> // for std::exit()
  #include <iostream>
  
  void cleanup()
  {
      // code here to do any kind of cleanup required
      std::cout << "cleanup!\n";
  }
  
  int main()
  {
      std::cout << 1 << '\n';
      cleanup();
  
      std::exit(0); // terminate and return status code 0 to operating system
  
      // The following statements never execute
      std::cout << 2 << '\n';
  
      return 0;
  }
  ```
  
  **Warning**: The `std::exit()` function does not clean up local variables in the current function or up the call stack.
  
  Because `std::exit()` terminates the program immediately, you may want to manually do some cleanup before terminating. Tje cleanup can be done manually but also using **std::atexit**.
  
  Allows you to specify a function that will automatically be called on program termination via `std:exit()`.
  
  ```cpp
      std::atexit(cleanup); // note: we use cleanup rather than cleanup() since we're not making a function call to cleanup() right now
  ```
  
  **Best practice**: Only use a halt if there is no safe way to return normally from the main function. If you haven’t disabled exceptions, prefer using exceptions for handling errors safely.
  
  ## 9. Software Testing
  
  **Software verification** (a.k.a. **software testing**) is the process of determining whether or not the software works as expected in all cases.
  
  ##### Test your programs in small pieces
  
  Testing a small part of your code in isolation to ensure that “unit” of code is correct is called **unit testing**. Each **unit test** is designed to ensure that a particular behavior of the unit is correct.
  
  **Best practice**:  Write your program in small, well defined units (functions or classes), compile often, and test your code as you go.
  
  ##### Informal testing
  
  One way you can test code is to do informal testing as you write the program. After writing a unit of code (a function, a class, or some other discrete “package” of code), you can write some code to test the unit that was just added, and then erase the test once the test passes.
  
  ##### Preserving your tests
  
  Although writing temporary tests is a quick and easy way to test some code, it doesn’t account for the fact that at some point, you may want to test that same code again later. 
  
  Create a test function, 
  
  ### Automate test functions
  
  Writing a test function that contains both the tests AND the expected answers and compares them so we don’t have to.
  
  #### **Unit testing frameworks**
  
  Because writing functions to exercise other functions is so common and useful, there are entire frameworks (called **unit testing frameworks**) that are designed to help simplify the process of writing, maintaining, and executing unit tests.
  
  #### Integration testing
  
  Once each of your units has been tested in isolation, they can be integrated into your program and retested to make sure they were integrated properly.
  
  ### Code Coverage
  
  The term **code coverage** is used to describe how much of the source code of a program is executed while testing. 
  
  #### Statement coverage
  
  The term **statement coverage** refers to the percentage of statements in your code that have been exercised by your testing routines.
  
  While aiming for 100% statement coverage is good, it’s not enough to ensure correctness.
  
  #### **Branch coverage**
  
  **Branch coverage** refers to the percentage of branches that have been executed, each possible branch counted separately.
  
  **Best practice**: Aim for 100% branch coverage of your code.
  
  #### **Loop coverage**
  
  **Loop coverage** (informally called **the 0, 1, 2 test**) says that if you have a loop in your code, you should ensure it works properly when it iterates 0 times, 1 time, and 2 times. If it works correctly for the 2-iteration case, it should work correctly for all iterations greater than 2.
  
  **Best practice**: Use the `0, 1, 2 test` to ensure your loops work correctly with different number of iterations.
  
  #### **Testing different categories of input**
  
  For integers, make sure you’ve considered how your function handles negative values, zero, and positive values. You should also check for overflow if that’s relevant.
  
  For floating point numbers, make sure you’ve considered how your function handles values that have precision issues (values that are slightly larger or smaller than expected). Good `double` type values to test with are `0.1` and `-0.1` (to test numbers that are slightly larger than expected) and `0.6` and `-0.6` (to test numbers that are slightly smaller than expected).
  
  For strings, make sure you’ve considered how your function handles an empty string (just a null terminator), normal valid strings, strings that have whitespace, and strings that are all whitespace.
  
  If your function takes a pointer, don’t forget to test `nullptr` as well (don’t worry if this doesn’t make sense, we haven’t covered it yet).
  
  **Best practice:** Test different categories of input values to make sure your unit handles them properly.
  
  ## m. Random Number Generation
  
  Computers are generally incapable of generating truly random numbers (at least through software). Instead, modern programs typically *simulate* randomness using an algorithm.
  
  To simulate randomness, programs typically use a pseudo-random number generator. A **pseudo-random number generator (PRNG)** is an algorithm that generates a sequence of numbers whose properties simulate a sequence of random numbers.
  
  **Key insight:** All of the values that a PRNG will produce are deterministically calculated from the seed value(s).
  
  #### Algrithms:
  
  An **algorithm** is a finite sequence of instructions that can be followed to solve some problem or produce some useful result.
  
  An algorithm is considered to be **stateful** if it retains some information across calls. Conversely, a **stateless** algorithm does not store any information (and must be given all the information it needs to work with when it is called).
  
  #### What makes a good PRNG?
  
  - The PRNG should generate each number with approximately the same probability.
  - The method by which the next number in the sequence is generated shouldn’t be predictable.
  - The PRNG should have a good dimensional distribution of numbers. (This means the PRNG should return numbers across the entire range of possible results at random.)
  - The PRNG should have a high period for all seeds
  
  All PRNGs are periodic, which means that at some point the sequence of numbers generated will begin to repeat itself. The length of the sequence before a PRNG begins to repeat itself is known as the **period**.
  
  - The PRNG should be efficient
  
  Every PRNG algorithm has strengths and weaknesses that might make it more or less suitable for a particular applications, so selecting the right algorithm for your application is important.
  
  ### Randomization in C++
  
  The randomization capabilities in C++ are accessible via the `<random>` header of the standard library. Within the random library, there are 6 PRNG families available for use (as of C++20):
  
  ![image-20221006125257107](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221006125257107.png)
  
  **So we should use Mersenne Twister, right?** Probably. For most applications, Mersenne Twister is fine, both in terms of performance and quality.
  
  If you are developing an application that requires the highest quality random results (e.g. a statistical simulation), the fastest results, or one where non-predictability is important (e.g. cryptography), you’ll need to use a 3rd party library.
  
  #### Marsenne Twister:
  
  Probably the most popular PRNG across all programming languages. Although it is a bit old by today’s standards, it generally produces quality results and has decent performance.  
  
  Two types:
  
  - `mt19937` is a Mersenne Twister that generates 32-bit unsigned integers
  - `mt19937_64` is a Mersenne Twister that generates 64-bit unsigned integers
  
  Example:
  
  ```cpp
  #include <iostream>
  #include <random> // for std::mt19937
  
  int main()
  {
  	std::mt19937 mt; // Instantiate a 32-bit Mersenne Twister
  
  	// Print a bunch of random numbers
  	for (int count{ 1 }; count <= 40; ++count)
  	{
  		std::cout << mt() << '\t'; // generate a random number
  
  		// If we've printed 5 numbers, start a new row
  		if (count % 5 == 0)
  			std::cout << '\n';
  	}
  
  	return 0;
  }
  ```
  
  **Tip:** `mt()` is a concise syntax for calling the function `mt.operator()`, which for these PRNG types has been defined to return the next random result in the sequence. The advantage of using `operator()` instead of a named function is that we don’t need to remember the function’s name, and the concise syntax is less typing.
  
  **As an aside:** For the stats geeks: a random number distribution is just a probability distribution designed to take PRNG values as input.
  
  ##### Uniform Distribution:
  
  ```cpp
  #include <iostream>
  #include <random> // for std::mt19937 and std::uniform_int_distribution
  
  int main()
  {
  	std::mt19937 mt;
  
  	// Create a reusable random number generator that generates uniform numbers between 1 and 6
  	std::uniform_int_distribution die6{ 1, 6 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };
  
  	// Print a bunch of random numbers
  	for (int count{ 1 }; count <= 40; ++count)
  	{
  		std::cout << die6(mt) << '\t'; // generate a roll of the die here
  
  		// If we've printed 10 numbers, start a new row
  		if (count % 10 == 0)
  			std::cout << '\n';
  	}
  
  	return 0;
  }
  ```
  
  If you run the program multiple times, you will note that it prints the same numbers every time! While each number in the sequence is random with regards to the previous one, the entire sequence is not random at all! Each run of our program produces the exact same result.
  
  Given any starting seed number, PRNGs will always generate the same sequence of numbers from that seed as a result.
  
  We really don’t need our seed to be a random number -- we just need to pick something that changes each time the program is run
  
  There are two methods that are commonly used to do this:
  
  
  
  1. Use the system clock
  
  C++ have a long history of PRNGs being seeded using the current time (using the `std::time()` function). 
  
  ```cpp
  static_cast<unsigned int>( std::chrono::steady_clock::now().time_since_epoch().count() )
  ```
  
  The downside of this approach is that if the program is run several times in quick succession, the seeds generated for each run won’t be that different, which can impact the quality of the random results from a statistical standpoint. For normal programs, this doesn’t matter, but for programs that require high quality, independent results, this method of seeding may be insufficient.
  
  
  
  2. Use the system’s random device
  
  ```cpp
  std::random_device{}()
  ```
  
  One potential problem with `std::random_device`: it isn’t required to be non-deterministic, meaning it *could*, on some systems, produce the same sequence every time the program is run, which is exactly what we’re trying to avoid. There was a [bug in MinGW](https://gcc.gnu.org/bugzilla/show_bug.cgi?id=85494) (fixed in GCC 9.2) that would do exactly this, making `std::random_device` useless.
  
  **Best practice**: Use `std::random_device` to seed your PRNGs (unless it’s not implemented properly for your target compiler/architecture).
  
  ##### Q: If std::random_device is random itself, why don’t we just use that instead of Mersenne Twister?
  
  Because std::random_device is implementation defined, we can’t assume much about it. It may be expensive to access or it may cause our program to pause while waiting for more random numbers to become available. The pool of numbers that it draws from may also be depleted quickly, which would impact the random results for other applications requesting random numbers via the same method. For this reason, std::random_device is better used to seed other PRNGs rather than as a PRNG itself.
  
  ##### Only seed a PRNG once
  
  **Best practice**: Only seed a given pseudo-random number generator once, and do not reseed it.
  
  Common mistake:
  
  ```cpp
  #include <iostream>
  #include <random>
  
  int getCard()
  {
      std::mt19937 mt{ std::random_device{}() }; // this gets created and seeded every time the function is called
      std::uniform_int_distribution card{ 1, 52 };
      return card(mt);
  }
  
  int main()
  {
      std::cout << getCard();
  
      return 0;
  }
  ```
  
  ##### Random numbers across multiple files:
  
  The better option in most cases is to create a global random number generator (inside a namespace!). Remember how we told you to avoid non-const global variables? This is an exception.
  
  ```cpp
  #include <iostream>
  #include <random> // for std::mt19937 and std::random_device
  
  namespace Random // capital R to avoid conflicts with functions named random()
  {
  	std::mt19937 mt{ std::random_device{}() };
  
  	int get(int min, int max)
  	{
  		std::uniform_int_distribution<> die{ min, max }; // we can create a distribution in any function that needs it
  		return die(mt); // and then generate a random number from our global generator
  	}
  }
  
  int main()
  {
  	std::cout << Random::get(1, 6) << '\n';
  	std::cout << Random::get(1, 10) << '\n';
  	std::cout << Random::get(1, 20) << '\n';
  
  	return 0;
  }
  ```
  
  ##### **Debugging programs that use random numbers**
  
  Programs that use random numbers can be difficult to debug because the program may exhibit different behaviors each time it is run. Sometimes it may work, and sometimes it may not. When debugging, it’s helpful to ensure your program executes the same (incorrect) way each time. That way, you can run the program as many times as needed to isolate where the error is.
  
  For this reason, when debugging, it’s a useful technique to seed your PRNG with a specific value (e.g. `5`) that causes the erroneous behavior to occur. This will ensure your program generates the same results each time, making debugging easier. Once you’ve found the error, you can use your normal seeding method to start generating randomized results again.
  
  ## x. Error Handling (see 7.14-7.17 TODO:)
  
  Most errors in a program don’t occur as the result of inadvertently misusing language features -- rather, most errors occur due to faulty assumptions made by the programmer and/or a lack of proper error detection/handling.
  
  Many new programmers write code and then only test the **happy path**: only the cases where there are no errors. But you should also be planning for and testing your **sad paths**, where things can and will go wrong.
  
  #### **Fatal errors**
  
  If the error is so bad that the program can not continue to operate properly, this is called a **non-recoverable** error (also called a **fatal error**)
  
  #### Exceptions
  
  Because returning an error from a function back to the caller is complicated (and the many different ways to do so leads to inconsistency, and inconsistency leads to mistakes), C++ offers an entirely separate way to pass errors back to the caller: `exceptions`.
  
  #### Input validation
  
  **Author’s note**: Input validation is important and useful, but it also tends to make examples more complicated and harder to follow. Accordingly, in future lessons, we will generally not do any kind of input validation unless it’s relevant to something we’re trying to teach.
  
  #### Assert and static_assert
  
  Todo:
  
  **Best practice**: Use assertions to document cases that should be logically impossible.
  
  ## v. Libraries
  
  #### **std::string**
  
  The easiest way to work with strings and string objects in C++ is via the `std::string` type, which lives in the <string> header. Example:
  
  ```cpp
  #include <string>
  
  int main()
  {
      std::string name { "Alex" }; // initialize name with string literal "Alex"
      name = "John";              // change name to "John"
  
      return 0;
  }
  ```
  
  **Use std::getline() to input text**
  
  ```cpp
      std::getline(std::cin >> std::ws, name); // read a full line of text into name
  ```
  
  **Best practice**: If using `std::getline()` to read strings, use `std::cin >> std::ws` input manipulator to ignore leading whitespace.
  
  Get length of a string in identifier name:
  
  ```cpp
  std::cout << name << " has " << name.length() << " characters\n";
  ```
  
  Returns an unsigned integral value (most likely of type `size_t`). If you want to assign the length to an `int` variable, you should `static_cast` it to avoid compiler warnings about signed/unsigned conversions: 
  
  ```cpp
  int length { static_cast<int>(name.length()) };
  ```
  
  #### std::string_view
  
  Lives in the <string_view> header)
  
  Unlike fundamental types, initializing (or copying) a `std::string` is slow. 
  
  **Best practice:** Do not pass `std::string` by value, as making copies of `std::string` is expensive. Prefer `std::string_view` parameters. 
  
  **Best practice:** Prefer `std::string_view` over `std::string` when you need a read-only string, especially for function parameters.
  
  
  
  ## k. High performance
  
  **As an aside:** You might assume that types that use less memory would be faster than types that use more memory. This is not always true. CPUs are often optimized to process data of a certain size (e.g. 32 bits), and types that match that size may be processed quicker. On such a machine, a 32-bit *int* could be faster than a 16-bit *short* or an 8-bit *char*.
  
  ## b. Bit Manipulation
  
  Chapter O
  
  ## z. Preprocessor
  
  When you compile your code, you might expect that the compiler compiles the code exactly as you’ve written it. This actually isn’t the case.
  
  Prior to compilation, the code file goes through a phase known as **translation**. 
  
  #### Includes:
  
  When you *#include* a file, the preprocessor replaces the #include directive with the contents of the included file. The included contents are then preprocessed (along with the rest of the file), and then compiled.
  
  #### Conditional compilation:
  
  The *conditional compilation* preprocessor directives allow you to specify under what conditions something will or won’t compile. There are quite a few different conditional compilation directives, but we’ll only cover the three that are used by far the most here: *#ifdef*, *#ifndef*, and *#endif*.
  
  ```cpp
  #include <iostream>
  
  #define PRINT_JOE
  
  int main()
  {
  #ifdef PRINT_JOE
      std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
  #endif
  
  #ifdef PRINT_BOB
      std::cout << "Bob\n"; // will be ignored since PRINT_BOB is not defined
  #endif
  
      return 0;
  }
  ```
  
  Once the preprocessor has finished, all defined identifiers from that file are discarded. This means that directives are only valid from the point of definition to the end of the file in which they are defined. Directives defined in one code file do not have impact on other code files in the same project.
  
  ## y. Extras
  
  1. Naming collisions occur in two cases:
  
     1. Two (or more) identically named functions (or global variables) are introduced into separate files belonging to the same program. This will result in a linker error, as shown above.
  
     2. Two (or more) identically named functions (or global variables) are introduced into the same file. This will result in a compiler error.
  
  2. In C++, any name that is not defined inside a class, function, or a namespace is considered to be part of an implicitly defined namespace called the **global namespace** (sometimes also called **the global scope**).
  
     **Key insight:** When you use an identifier that is defined inside a namespace (such as the *std* namespace), you have to tell the compiler that the identifier lives inside the namespace.
  
     The :: symbol is an operator called the **scope resolution operator**.
  
     **Best practice:** Use explicit namespace prefixes to access identifiers defined in a namespace.
  
     ```cpp
     using namespace std; // this is a using directive that allows us to access names in the std namespace with no namespace prefix
     ```

**Warning:** Avoid using-directives (such as *using namespace std;*) at the top of your program or in header files. They violate the reason why namespaces were added in the first place.

## x. General Tips

- A preferred solution. Save input values, do not overwrite them. Avoid creating new variables when possible. Output answer directly.

  