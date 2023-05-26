# Chapter 16: C - Simple Shell
###### Write a simple UNIX command interpreter.

## How to approach this project.

1. Read the task or challenge.
2. Rephrase it in your own words.
3. Verify expected behavior by getting example inputs and outputs.
4. Whiteboard your solution with words.
5. Walk through your solution with an example as if you were a machine. Do only what is written down. Correct your solution if needed.
6. Whiteboard your solution with pseudocode.
7. Walk through your solution with an example as if you were a machine. Do only what is written down. Correct your solution if needed.
8. Whiteboard your solution with code.
9. Walk through your solution with an example as if you were a machine. Do only what is written down. Correct your solution if needed.
10. Write your code on your computer. [Note: This is this first time you are using your computer! Only when you know exactly what to code.]
11. Test your code on your computer.
12. Debug if necessary.
13. You complete the task or challenge!
> Be sure to break your task or project into smaller and smaller pieces, until you are comfortable solving each piece with the above steps.

## General ideas

### Who designed and implemented the original Unix operating system
The original `Unix` operating system was designed and implemented by a team of computer scientists at Bell Labs in the late 1960s and early 1970s. The team was led by `Ken Thompson` and `Dennis Ritchie`, with contributions from other members of the team including Rudd Canaday, Joe Ossanna, and Brian Kernighan.
### Who wrote the first version of the UNIX shell
The first version of the `Unix` shell, known as the `Thompson shell` or `sh`, was written by `Ken Thompson` himself in the mid-1970s. The shell is a command-line interface that allows users to interact with the `Unix` operating system by entering commands and receiving output.
### Who invented the B programming language (the direct predecessor to the C programming language)
The `B` programming language was developed by `Ken Thompson `in the early 1970s while working at Bell Labs. `B` was developed as a successor to the `BCPL` programming language, which was itself a precursor to the `C` programming language.
### Who is Ken Thompson
![Ken Thompson](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f8/Ken-Thompson-2019.png/220px-Ken-Thompson-2019.png)

`Ken Thompson` is a computer scientist and one of the pioneers of the field of computer science. He was born on February 4, 1943, in New Orleans, Louisiana, USA. Thompson is best known for his work on the development of the `UNIX` operating system, He also co-invented the programming languages `B` and later, with `Ritchie`, the widely used `C` language.
### How does a shell work
A shell is a command-line interface that allows users to interact with an operating system by typing in commands and receiving output. When a user enters a command in a shell, the shell interprets the command and carries out the requested operation.

The shell works by reading input from the user, parsing the input into individual commands and arguments, and then executing those commands by calling the appropriate system utilities or programs. The shell also manages input/output redirection and piping, which allow the output of one command to be used as input for another command.
### What is a pid and a ppid

A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with and manipulate processes. In order to retrieve the current process’ ID, you can use the system call `getpid`

Each process has a parent: the process that created it. It is possible to get the PID of a parent process by using the `getppid` system call, from within the child process.
### How to manipulate the environment of the current process
The environment of the current process can be manipulated using shell commands and shell scripts. ex:
*   Setting environment variables:
```$ export MY_VAR="Hello World"```
*   Modifying the PATH:
```$ export PATH=$PATH:/path/to/new/directory```
### What is the difference between a function and a system call
In brief, system calls are associated with kernel mode while function calls are associated with user mode. The main difference between system call and function call is that a **system call** is a request for the kernel to access a resource while a **function call** is a request made by a program to perform a specific task. System calls are used when a program needs to communicate with the kernel while function calls are used to call a specific function within the program.
### How to create processes
Fork system call is used for creating a new process, which is called a child process, and runs concurrently with the process that makes the `fork()` call (parent process). After a new child process is created, both processes will execute the next instruction following the `fork()` system call. A child process uses the same pc(program counter), same CPU registers, same open files which use in the parent process. It takes no parameters and returns an integer value. Below are different values returned by fork().
  * **Negative Value**: creation of a child process was unsuccessful.
  * **Zero**: Returned to the newly created child process.
  * **Positive value**: Returned to parent or caller. The value contains process ID of newly created child process.

 ```
#include <stdio.h>
#include <sys/types.h>;
#include <unistd.h>;
int main()
{

    // make two process which run same
    // program after this instruction
    fork();

    printf("Hello world!\n");
    return 0;
}
 ```
 **Output**

 ```
Hello world!
Hello world!
 ```
### What are the three prototypes of main

*   `int main(void);`
*   `int main(int ac, char **av);`
*   `int main(int ac, char **av, char **env);`
where:

`av` is a `NULL` terminated array of strings.
`ac` is the number of items in `av`.
`env` is a `NULL` terminated array of strings.
### How does the shell use the PATH to find the programs
Find out [here](https://shazaali.substack.com/p/creating-your-own-command-interpreter-5c7)
### How to execute another program with the execve system call
Find out [here](https://shazaali.substack.com/p/creating-your-own-command-interpreter-84f)
### How to suspend the execution of a process until one of its children terminates
A call to `wait()` blocks the calling process until one of its child processes exits or a signal is received. After child process terminates, parent continues its execution after wait system call instruction.
Child process may terminate due to any of these:
 * It calls `exit()`;
 * It returns (an `int`) from `main`
 * It receives a signal (from the OS or another process) whose default action is to terminate.
![image](https://user-images.githubusercontent.com/69873039/232314992-3f06e4e6-c2a3-48d8-9226-2463d183e328.png)

If any process has more than one child process then after calling `wait()`, parent process has to be in wait state if no child terminates.
If only one child process is terminated, `wait()` returns process ID of the terminated child process.
If more than one child process is terminated, then `wait()` returns process IDs of those processes.
When `wait()` returns, it also defines exit status (which tells us why a process was terminated) via a pointer, if the status in not NULL.
If any process has no child process then `wait()` immediately returns `-1`.

**NOTE: This codes does not run in simple IDE because of environmental problem so use terminal for run the code**

```

// C program to demonstrate working of wait()
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
    pid_t cpid;
    if (fork()== 0)
        exit(0);           /* terminate child */
    else
        cpid = wait(NULL); /* reaping parent */
    printf("Parent pid = %d\n", getpid());
    printf("Child pid = %d\n", cpid);

    return 0;
}
```
**Output**
```
Parent pid = 12345678
Child pid = 89546848
```

### What is EOF / “end-of-file”?
In computing, end-of-file (`EOF`) is a condition in a computer operating system where no more data can be read from a data source.

In UNIX the translation of the keystroke to `EOF` is performed by the terminal driver, so a program does not need to distinguish terminals from other input files. By default, the driver converts a `Ctrl-D` character at the start of a line into an end-of-file indicator. To insert an actual `Ctrl-D` (ASCII `04`) character into the input stream, the user precedes it with a "quote" command character (usually `Ctrl-V`).
