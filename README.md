# Project 0x15 - Simple_shell

simple_shell is a basic command interpreter that executes commands from the standard input or from a file.

## File Contents
This repository contains the following files:

|   **File**   |   **Description**   |
| -------------- | --------------------- |
| shell.c | the main function |
| shell.h | header file |
| tokens.c | convert into tokens |
| path.c | checks for the path |
| free.c | frees double pointer |
| _printenv.c | prints the enviroment |
| signal.c | recreates the ctr-c command |
| shell_div.c | functions used |
| man_1_simple_shell | manual |

## Installation
Clone the repository. Compile the ".c" files. Run executable.

```
$ git clone https://github.com/felipemontes/simple_shell.git
```

## Compile and start

To start simple_shell you just need to compile using

```
gcc -Wall -Werror   -Wextra -pedantic *.c -o hsh.
```

### run

```
./hsh
```

## Usage (Interactive mode)

```
hsh$ /bin/ls
hsh$ ls -la
hsh$ pwd
```
## Non - interactive mode

```
hsh$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
hsh$
hsh$ cat test_ls_2
/bin/ls
/bin/ls
hsh$
hsh$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
hsh$
```

## Builtins
```bash
env
```

## Authors
[Brian Omanya](https://github.com/bomanya2)

[Allan Ndonga](https://github.com/alz254)
