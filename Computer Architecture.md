# 1. Introduction

**Architecture**: The view of a computer presented to software designers.

## What is a computer?

A computer is a general purpose device that can be programmed to process information, and yield meaningful results.

![image-20221030091524768](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221030091524768.png)

The CPU (processor) is the main part of the computer that takes aprogram as input, and executes it. 

Main memory is used to store data that a program might need during its execution. 

The CPU is the only active unit in our entire system. The others components are passive and only respond to requests. They do not have any computational capability of their own.

## Instruction Set Architecture

Each program needs to contain a set of basic instructions that a computer can process. Henceforth, a computer can produce the desired output. An instruction is defined as a basic command that can be given to a computer.

Programmers typically write programs in a high level language such as C or JavaTM. These languages contain complex constructs such as structures, unions, switch-case statements, classes and inheritance. These concepts are too complicated for a computer to handle. Hence, it is necessary to pass a C or C++ program through a dedicated program called a compiler that can convert it into a sequence of basic instructions. This program is typically called an executable or binary. 

The number of basic instructions that a processor can support is finite. The semantics of all the instructions supported by a processor is known as the instruction set architecture (ISA). This includes the semantics of the instructions themselves, along with their operands, and interfaces with peripheral devices.

For example, Intel and AMD CPUs use the x86 instruction set, IBM processors use the PowerPC R instruction set, HP processors use the PA-RISC instruction set, and the ARM processors use the ARM R instruction set (or variants of it such as Thumb-1 and Thumb-2). It is thus not possible to run a binary compiled for an Intel system on an ARM based system. The instruction sets are not compatible.

However, in most cases it is possible to reuse the C program. 

## Turing Complete

Note that different processors are designed to do different things, and hence their ISAs can be different. However, the bottom line is that any ISA should be complete in the sense that it should be able to express all the programs in machine code that a user intends to write for it.

Implementing a lot of instructions will unnecessarily increase the number of transistors in the processor and increase its complexity. Consequently, most instruction sets have somewhere between 64 to 1000 instructions.

**Definition:** A reduced instruction set computer (RISC) implements simple instructions that have a simple and regular structure. The number of instructions is typically a small number (64 to 128). Examples: ARM, IBM PowerPC, HP PA-RISC.

**Definition:** A complex instruction set computer (CISC) implements complex instructions that are highly irregular, take multiple operands, and implement complex functionalities. Secondly, the number of instructions is large (typically 500+). Examples: Intel x86, VAX.

The big question we ask ourselves is: Given an ISA, can it represent all possible programs?

TODO: Mer om turing completeness

## Von Neumann Architecture

The path breaking innovation in this machine was that the instruction table was stored in memory. It was possible to do so by encoding every instruction with the same set of symbols that are normally stored in memory. 

A Von Neumann CPU needs to decode every instruction. The crux of this idea is that instructions are treated as regular data(memory values).

**Definition:**  Stored-program concept: A program is stored in memory and instructions are treated as regular memory values.

The stored program concept tremendously simplifies the design of a computer. Since memory data and instructions are conceptually treated the same way, we can have one unified processing system and memory system that treats instructions and data the same way

Notice that a Von Neumann machine or a Harvard machine do not have an infinite amount of memory like a Turing machine. Hence, strictly speaking they are not exactly equivalent to a Turing machine. 



![image-20221030093115798](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221030093115798.png)

### With registers

There is a general rule of thumb in hardware, “large is slow, and small is fast.” Consequently, to enable fast operation, every processor has a small set of registers that can be quickly accessed. The number of registers is typically between 8 and 64.

![image-20221030093555133](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221030093555133.png)

### And with stack

A stack is a standard data structure that obeys the semantics – last in, first out.

It is clearly visible that scheduling a computation to work on a stack is difficult. There will be many redundant loads and stores. Nonetheless, for machines that are meant to evaluate long mathematical expressions, and machines for which program size is an issue, typically opt for stacks.

### Accumulators

Accumulator based machines use a single register called an accumulator. Each instruction takes a single memory location as an input operand.

For example, an add operation adds the value in the accumulator to the value in the memory address and then stores the result back in the accumulator.

Some aspects of accumulators have crept into the Intel x86 set of processors that are the most commonly used processors for desktops and laptops as of 2012.

# 2. Language of Bits

Existing technologies to implement computers using silicon transistors are very compatible with the notion of processing 0s and 1s. A basic silicon transistor is a switch that can set the output to a logical 0 or 1, based on the input.

## Boolean Algebra

An algebraic system consisting of Boolean variables and some special operators defined on them.

Boolean algebra is a field of study by itself. Boolean formulae, logic, and operations form the basis of modern computer science.

### Operators: TODO

NOT

OR

AND

NAND

NOR

XOR

## Logic Gates

**Definition:** A logic gate is a device that implements a Boolean function.

![image-20221030094350175](C:\Users\Johan\AppData\Roaming\Typora\typora-user-images\image-20221030094350175.png)



# 3. Assembly

Assembly language is a textual representation of an ISA. It is specific to the ISA. Since an instruction is a sequence of 0s and 1s, it is very difficult to study it in its bare form. Assembly language gives us a good handle to study the semantics of instructions in an ISA.

ARM and x86, 

## SimpleRisc Machine

16 register: r0, r1,...

#### Registers Transfer Instruction - mov 1

#### Arithmetic Instructions

##### add 2

##### sub 3

##### mul 4

##### div 5

##### mod 6

###### cmp 7

#### Logical Instructions

##### and 8

##### or 9

##### not 10

#### Shift Instructions

##### lsl 11

##### lsr 12

##### asr 13

#### Data Transfer Instructions

##### ls 14

##### st 15

#### Unconditional Branch Instruction - b 16

#### Conditional Branch Instructions 

##### beq 17

##### bgt 18

#### Function Call/Return Intructions

##### call 19

##### ret 20

#### nop Instruction 21

Does nothing.

It is important to have an instruction that does not do anything to ensure correctness in execution



#### 
