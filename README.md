# ![bf.ico](https://raw.githubusercontent.com/dfx81/Brainfuck/master/bf.ico) Brainfuck
Author  : Danial (dfx)  
Version : 2.0  

A Brainfuck interpreter written in C.  
The provided Hello.bf Brainfuck code is taken from [Wikipedia](#Reference).  

## Specifications

- 64kb memory limit (compared to the base 30kb)
- 64kb program size limit
- 64kb stack size limit

## Downloads

- [Windows](https://github.com/dfx81/brainfuck/releases/tag/v2.0/bf.exe)
- [Linux](https://github.com/dfx81/brainfuck/releases/tag/v2.0/bf)

## Usage

Run the program on the command line with the Brainfuck filename as argument.

> Example to run the provided hello.bf file with debug mode:  
  ```Linux   $ ./bf hello.bf```  
  ```Windows > bf.exe hello.bf```

## Build Instructions

Simply run ```make build```.

Requirements: [mingw32-w64](https://www.mingw-w64.org/) must be installed for
Windows build. Other compilers aside from ```gcc``` have not been tested.

## Instructions

This is a simplified tutorial on Brainfuck. For more info, check the article
on [Wikipedia](#Reference).

```
+ : Increment the value on current memory cell by 1.  
- : Decrement the value on current memory cell by 1.  
> : Move the memory pointer 1 cell to the right.  
< : Move the memory pointer 1 cell to the left.  
, : Accept one byte of memory and store it in current memory cell.  
. : Output the byte at current memory cell as ASCII.  
[ : If current memory cell value is 0, proceed to matching ']'.  
] : If current memory cell value is not 0, return to matching '['.  
```

## Reference

[Wikipedia](https://en.m.wikipedia.org/wiki/Brainfuck)
