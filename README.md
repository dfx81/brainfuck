# Brainfuck
Author  : Danial (dfx)  
Version : 1  

A Brainfuck interpreter written in C.  
The provided Hello.bf Brainfuck code is taken from [Wikipedia](##Reference).

## Usage

1. Recompile the program using make (BF file provided was compiled for Linux).
2. Run the program on the command line with the Brainfuck filename as argument.
3. OPTIONAL: Provide the debug flag (-d) to display the final memory state.  

> Example to run the provided Hello.bf file with debug mode:  
  ```./BF Hello.bf -d```

## Instructions

This is a simplified tutorial on Brainfuck. For more info, check the article
on [Wikipedia](##Reference).

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
