# ![BF.ico](https://raw.githubusercontent.com/dfx81/Brainfuck/master/BF.ico) Brainfuck
Author  : Danial (dfx)  
Version : 1.1  

A Brainfuck interpreter written in C.  
The provided Hello.bf Brainfuck code is taken from [Wikipedia](#Reference).  

## Downloads

- [Windows](https://github.com/dfx81/Brainfuck/blob/master/BF.exe)
- [Linux](https://github.com/dfx81/Brainfuck/blob/master/BF)

## Usage

### GUI

1. Find the file to run and set its default program to the Brainfuck program downloaded.
2. Save and apply the settings.
3. Double click any .bf file to run the program.

### Command Line

1. Run the program on the command line with the Brainfuck filename as argument.
2. OPTIONAL: Provide the debug flag (-d) to display the final memory state.  

> Example to run the provided Hello.bf file with debug mode:  
  ```Linux$./BF Hello.bf -d```  
  ```Windows>BF.exe Hello.bf -d```

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
