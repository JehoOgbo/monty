# Monty Interpreter
This repository is an interpreter for the monty 0.98 programming language with bytecodes such as push, pall, etc. This interpreter uses the concepts of FIFO and LIFO in queues and stacks respectively to make this interpreter and is easily interconverted from a queue to a stack and vice versa.

The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

`julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$ `
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

`julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$`

## Brainf*ck
Brainfuck is an esoteric programming language created in 1993 by Swiss student Urban Müller. Designed to be extremely minimalistic, the language consists of only eight simple commands, a data pointer, and an instruction pointer.

Brainfuck is an example of a so-called Turing tarpit: it can be used to write any program, but it is not practical to do so because it provides so little abstraction that the programs get very long or complicated. While Brainfuck is fully Turing-complete, it is not intended for practical use but to challenge and amuse programmers. Brainfuck requires one to break down commands into small and simple instructions.

The language takes its name from the slang term brainfuck, which refers to things so complicated or unusual that they exceed the limits of one's understanding, as it was not meant or made for designing actual software but to challenge the boundaries of computer programming.

Because the language's name contains profanity, many substitutes are used, such as brainfsck, branflakes, brainoof, brainfrick, BrainF, and BF.

### Functionalities of this interpreter
* Push information u

## Table of Content
* [Environment](#environment)
* [Installation/Compilation](#installation/compilation)
* [Usage](#usage)
* [Data Structures](#data-structures)
* [File Descriptions](#file-descriptions)
* [Bugs](#bugs)
* [Authors](#authors)
* [License](#license)

## Environment
This project is compiled/tested on Ubuntu 20.04 LTS using gcc compiler

## Installation/Compilation
* clone this repository: `git clone "https://github.com/JehoOgbo/monty.git"`
* Access monty directory: `cd monty`
* Compile the interpreter: `gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`
* Install the brainf*ck interpreter to test *.bf files: `sudo apt-get install bf`

## Usage
* Usage: monty file
  * where file is the path to the file containing Monty byte code
* If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
* If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
  * where <file> is the name of the file
* If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
  * where is the line number where the instruction appears.
* Line numbers always start at 1
* The monty program runs the bytecodes line by line and stop if either:
  * it executed properly every line of the file
  * it finds an error in the file
  * an error occured
* If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
* Any output must be printed on stdout
* Any error message must be printed on stderr

## Data structures
The following data structures are used for this project and are included in the header file


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;`

## File Descriptions
[0-operations.c](0-operations.c) - Implement the push, pall, pint, pop and swap opcodes.

The push opcode

* The opcode push pushes an element to the stack.

* Usage: push <int>
  * where <int> is an integer
* if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
  * where <line_number> is the line number in the file

The pall opcode

* The opcode pall prints all the values on the stack, starting from the top of the stack.

* Usage pall
* Format: see example
* If the stack is empty, don’t print anything
`julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$`

The pint opcode

* The opcode pint prints the value at the top of the stack, followed by a new line.

* Usage: pint
* If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE
`julien@ubuntu:~/monty$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/monty$ ./monty bytecodes/06.m 
1
2
3
julien@ubuntu:~/monty$ `

The pop opcode

* The opcode pop removes the top element of the stack.

* Usage: pop
* If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE
`julien@ubuntu:~/monty$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/monty$ ./monty bytecodes/07.m 
3
2
1
2
1
1
julien@ubuntu:~/monty$ `

The swap opcode

* The opcode swap swaps the top two elements of the stack.

* Usage: swap
* If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
`julien@ubuntu:~/monty$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/monty$ ./monty bytecodes/09.m 
3
2
1
2
3
1
julien@ubuntu:~/monty$ `

[1-get_operations.c](1-get_operations.c)
Contains function to select operation based on the user input

[2-string_is_numeric.c](2-string_is_numeric.c)
Contains function to ensure the arguments passed in for the interpreter are numeric based on the user input

[3-operations.c](3-operations.c) - Implement the add, nop, sub, divide, mul functions
The add opcode
* The opcode add adds the top two elements of the stack.

* Usage: add
* If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  * The top element of the stack contains the result
* The stack is one element shorter
`julien@ubuntu:~/monty$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall
julien@ubuntu:~/monty$ ./monty bytecodes/12.m 
3
2
1
5
1
julien@ubuntu:~/monty$ `

The nop opcode
* The opcode nop doesn’t do anything.
* Usage: nop
The sub opcode

* The opcode sub subtracts the top element of the stack from the second top element of the stack.

* Usage: sub
* If the stack contains less than two elements, print the error message L<line_number>: can't sub, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
* The top element of the stack contains the result
* The stack is one element shorter
`julien@ubuntu:~/monty$ cat bytecodes/19.m 
push 1
push 2
push 10
push 3
sub
pall
julien@ubuntu:~/monty$ ./monty bytecodes/19.m 
7
2
1
julien@ubuntu:~/monty$  `
  
The div opcode

* The opcode div divides the second top element of the stack by the top element of the stack.

* Usage: div
* If the stack contains less than two elements, print the error message L<line_number>: can't div, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
* The top element of the stack contains the result
* The stack is one element shorter
* If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

The mul opcode

* The opcode mul multiplies the second top element of the stack with the top element of the stack.

* Usage: mul
* If the stack contains less than two elements, print the error message L<line_number>: can't mul, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
* The top element of the stack contains the result
* The stack is one element shorter

[5-operations.c](5-operations.c) - Implement the following opcodes: mod, pchar, pstr, rotl, rotr

The mod opcode
The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack.
* Usage: mod
* If the stack contains less than two elements, print the error message L<line_number>: can't mod, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
* The top element of the stack contains the result
* The stack is one element shorter
* If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

The pchar opcode
* The opcode pchar prints the char at the top of the stack, followed by a new line.
* Usage: pchar
* The integer stored at the top of the stack is treated as the ascii value of the character to be printed
* If the value is not in the ascii table (man ascii) print the error message L<line_number>: can't pchar, value out of range, followed by a new line, and exit with the status EXIT_FAILURE
* If the stack is empty, print the error message L<line_number>: can't pchar, stack empty, followed by a new line, and exit with the status EXIT_FAILURE
`julien@ubuntu:~/monty$ cat bytecodes/28.m 
push 72
pchar
julien@ubuntu:~/monty$ ./monty bytecodes/28.m 
H
julien@ubuntu:~/monty$`
  
The pstr opcode
* The opcode pstr prints the string starting at the top of the stack, followed by a new line.
* Usage: pstr
* The integer stored in each element of the stack is treated as the ascii value of * the character to be printed
* The string stops when either:
  * the stack is over
  * the value of the element is 0
  * the value of the element is not in the ascii table
* If the stack is empty, print only a new line
`julien@ubuntu:~/monty$ cat bytecodes/31.m 
push 1
push 2
push 3
push 4
push 0
push 110
push 0
push 108
push 111
push 111
push 104
push 99
push 83
pstr
julien@ubuntu:~/monty$ ./monty bytecodes/31.m 
School
julien@ubuntu:~/monty$ `

The rotl opcode
* The opcode rotl rotates the stack to the top.
* Usage: rotl
* The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
* rotl never fails
`julien@ubuntu:~/monty$ cat bytecodes/35.m 
push 1
push 2
push 3
push 4
push 5
push 6
push 7
push 8
push 9
push 0
pall
rotl
pall
julien@ubuntu:~/monty$ ./monty bytecodes/35.m 
0
9
8
7
6
5
4
3
2
1
9
8
7
6
5
4
3
2
1
0
julien@ubuntu:~/monty$ `

The rotr opcode
* The opcode rotr rotates the stack to the bottom.
* Usage: rotr
* The last element of the stack becomes the top element of the stack
* rotr never fails
  
15. stack, queue
#advanced
Score: 100.0% (Checks completed: 100.0%)
Implement the stack and queue opcodes.

[6-operations.c](#6-operations.c) - Implements the stack and queue opcodes
The stack opcode
* The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program.
* Usage: stack
The queue opcode
* The opcode queue sets the format of the data to a queue (FIFO).
* Usage: queue
* When switching mode:
  * The top of the stack becomes the front of the queue
  * The front of the queue becomes the top of the stack
`julien@ubuntu:~/monty$ cat bytecodes/47.m
queue
push 1
push 2
push 3
pall
stack
push 4
push 5
push 6
pall
add
pall
queue
push 11111
add
pall
julien@ubuntu:~/monty$ ./monty bytecodes/47.m
1
2
3
6
5
4
1
2
3
11
4
1
2
3
15
1
2
3
11111
julien@ubuntu:~/monty$ `
  
[bf/1000-school.bf](bf/1000-school.bf)
Brainf*ck script that prints School, followed by a new line.
`julien@ubuntu:~/monty/bf$ bf 1000-school.bf 
School
julien@ubuntu:~/monty/bf$ `

[bf/1001-add.bf](bf/1001-add.bf)
Brainf*ck script that adds two digits given by the user.
* Read the two digits from stdin, add them, and print the result
* The total of the two digits with be one digit-long (<10)
`julien@ubuntu:~/monty/bf$ bf ./1001-add.bf
81
9julien@ubuntu:~/monty/bf$`

[bf/1002-mul.bf](bf/1002-mul.bf)
Multiply two digits given by the user.
* Read the two digits from stdin, multiply them, and print the result
* The result of the multiplication will be one digit-long (<10)
`julien@ubuntu:~/monty/bf$ bf 1002-mul.bf
24
8julien@ubuntu:~/monty/bf$`

[bf/1003-mul.bf](bf/1003-mul.bf)
Multiply two digits given by the user.
* Read the two digits from stdin, multiply them, and print the result, followed by a new line
`julien@ubuntu:~/monty/bf$ bf 1003-mul.bf 
77
49
julien@ubuntu:~/monty/bf$ `

comments
Every good language comes with the capability of commenting. When the first non-space character of a line is #, treat this line as a comment (don’t do anything)

## Bugs
No Known Bugs at this time.

## Author
Urom Jehoshaphat Ogbonnia - [Github](https://github.com/JehoOgbo) / [LinkedIn](https://www.linkedin.com/in/jehoshaphat-urom-06780a254/)

## Licence
Public Domain. No copy write protection
