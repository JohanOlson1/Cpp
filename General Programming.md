# General Programming

Computers are fast, but only understand a limited set of intructions. 

A **computer program or application** is a set of instructions a computer can perform. Creating this program is called **programming**. Which is typically done by producing a **source code**, a list of commands in a text file. 

The physical computer parts that allow execution of a program is called **hardware**. A program is loaded into memory and the hardware sequentially executes each instruction, **executing** the program.

## Machine Language

The CPU can only understand instruction in machine code, which is 1s and 0s. Each individual 1 and 0 is called a binary digit or **bit**. The number of bits making up a command can vary, some computers can only handle for example 32 bits (32 bit computer). While other CPUs can handle variable length (x86 computer, which is common now). CPUs can have different instruction sets, hence the same **machine code** may not work for different CPUs. Meaning it is not **portable**.

## Assembly Language

Describes each instruction by a short abbreviation, instead of 1s and 0s, letters and other numbers. 

The assembly program must be translated into machine language before execution. Which is done using a program called an **assembler**. 

Programming in assembly is used when speed is crucial. However, it requires good understanding as compilers can outperform most programmers. It is also not portable!

## High-Level Languages

To improve readability and portability, high-level languages were developed. Programs must be translated into a format the computer understands before execution. There are two options

### Compiler

A program that reads source code and produces a stand alone executable program that can be run. Need to recompile if source code is changed but otherwise the executable can be used as a stand alone. 

The executable is machine code.

Some compilers also support compiler-specific extensions -- if you use these, your programs won’t be able to be compiled by other compilers that don’t support the same extensions without modification.

![image-20220930090301368](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20220930090301368.png)

### Interpreter

A program that directly executes instructions in the source code without compilation. More flexible but less efficient when running programs since the interpreting process must be done each time the program runs. 

---

Programs can be compiled or interpreted for different systems, so the program doesn't need to change to run on different CPUs. Just compile for a different CPU. 

## Floating Point Operations per Second (FLOPS)

Usual measurement of computation performance. More computationally expensive than other operations. In scientific fields floating point numbers are common and hence this way of measuring speed good. 

## Stack and Heap

The memory that a program uses is typically divided into a few different areas, called segments:

- The code segment (also called a text segment), where the compiled program sits in memory. The code segment is typically read-only.
- The bss segment (also called the uninitialized data segment), where zero-initialized global and static variables are stored.
- The data segment (also called the initialized data segment), where initialized global and static variables are stored.
- The heap, where dynamically allocated variables are allocated from.
- The call stack, where function parameters, local variables, and other function-related information are stored.

The stack has advantages and disadvantages:

- Allocating memory on the stack is comparatively fast.
- Memory allocated on the stack stays in scope as long as it is on the stack. It is destroyed when it is popped off the stack.
- All memory allocated on the stack is known at compile time. Consequently, this memory can be accessed directly through a variable.
- Because the stack is relatively small, it is generally not a good idea to do anything that eats up lots of stack space. This includes passing by value or creating local variables of large arrays or other memory-intensive structures.

### The call stack

The call stack keeps track of all the active functions (those that have been called but have not yet terminated) from the start of the program to the current point of execution, and handles allocation of all function parameters and local variables.

In computer programming, a stack is a container data structure that holds multiple variables (much like an array). However, whereas an array lets you access and modify elements in any order you wish (called **random access**), a stack is more limited. The operations that can be performed on a stack correspond to the three things mentioned above:

1. Look at the top item on the stack (usually done via a function called top(), but sometimes called peek())
2. Take the top item off of the stack (done via a function called pop())
3. Put a new item on top of the stack (done via a function called push())

A stack is a last-in, first-out (LIFO) structure. The last item pushed onto the stack will be the first item popped off. If you put a new plate on top of the stack, the first plate removed from the stack will be the plate you just pushed on last. 

```
Stack: empty
Push 1
Stack: 1
Push 2
Stack: 1 2
Push 3
Stack: 1 2 3
Pop
Stack: 1 2
Pop
Stack: 1
```

#### Call stack segment

The call stack segment holds the memory used for the call stack. When the application starts, the main() function is pushed on the call stack by the operating system. Then the program begins executing.

When a function call is encountered, the function is pushed onto the call stack. When the current function ends, that function is popped off the call stack (this process is sometimes called **unwinding the stack**).

The “items” we’re pushing and popping on the stack are called **stack frames**. A stack frame keeps track of all of the data associated with one function call. We’ll talk more about stack frames in a bit. The “marker” is a register (a small piece of memory in the CPU) known as the stack pointer (sometimes abbreviated “SP”). The stack pointer keeps track of where the top of the call stack currently is.

When we pop an item off the call stack, we only have to move the stack pointer down -- we don’t have to clean up or zero the memory used by the popped stack frame. 

-- This memory is no longer considered to be “on the stack” (the stack pointer will be at or below this address), so it won’t be accessed. If we later push a new stack frame to this same memory, it will overwrite the old value we never cleaned up.

#### The call stack in action

Let’s examine in more detail how the call stack works. Here is the sequence of steps that takes place when a function is called:

1. The program encounters a function call.
2. A stack frame is constructed and pushed on the stack. The stack frame consists of:

- The address of the instruction beyond the function call (called the **return address**). This is how the CPU remembers where to return to after the called function exits.
- All function arguments.
- Memory for any local variables
- Saved copies of any registers modified by the function that need to be restored when the function returns

1. The CPU jumps to the function’s start point.
2. The instructions inside of the function begin executing.

When the function terminates, the following steps happen:

1. Registers are restored from the call stack
2. The stack frame is popped off the stack. This frees the memory for all local variables and arguments.
3. The return value is handled.
4. The CPU resumes execution at the return address.

Return values can be handled in a number of different ways, depending on the computer’s architecture. Some architectures include the return value as part of the stack frame. Others use CPU registers.

A technical note: on some architectures, the call stack grows away from memory address 0. On others, it grows towards memory address 0. As a consequence, newly pushed stack frames may have a higher or a lower memory address than the previous ones.

### Stack overflow

The stack has a limited size, and consequently can only hold a limited amount of information. On Visual Studio for Windows, the default stack size is 1MB. With g++/Clang for Unix variants, it can be as large as 8MB. If the program tries to put too much information on the stack, stack overflow will result. **Stack overflow** happens when all the memory in the stack has been allocated -- in that case, further allocations begin overflowing into other sections of memory.

Stack overflow is generally the result of allocating too many variables on the stack, and/or making too many nested function calls (where function A calls function B calls function C calls function D etc…) 

