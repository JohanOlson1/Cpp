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

