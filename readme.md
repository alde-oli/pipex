# Pipex Project Overview

## Project Description

Pipex is a meticulous exploration of process manipulation and inter-process communication through the use of UNIX pipes. This project at 42 School adheres strictly to the 42 Norm and is implemented entirely in C. Mimicking the behavior of the shell command `pipe`, Pipex takes input from a file, processes it through two commands, and directs the output to another file.

Leveraging low-level programming functions (`fork`, `pipe`, `dup`, `dup2`, `execve`, etc.), this program replicates the logic of chaining commands in a shell script. The authorized functions like `malloc`, `free`, and `read` are carefully used to manage memory and input/output operations, ensuring a seamless data flow between processes.

## Enhanced Features

In addition to the mandatory part of the project, I have successfully implemented the bonus feature:

- **Multiple Pipes**: My implementation supports chaining an arbitrary number of commands, just like in a shell. This feature allows for an enhanced command line experience and showcases advanced understanding of process management in a UNIX environment.

## Usage

The program is executed as follows:
```
./pipex file1 cmd1 cmd2 file2
```
Where `file1` and `file2` are the input and output files, respectively, and `cmd1` and `cmd2` are shell commands with their arguments.

For example:
```
./pipex infile "ls -l" "wc -l" outfile
```

## Installation

Clone the repository, compile the program with Makefile, and run it with your desired commands. Here's how to get started:

```bash
git clone https://your-github-repository-link.git
cd pipex
make
./pipex file1 cmd1 cmd2 file2
```

## Prerequisites

- A 42 School student ready to tackle process communication challenges.
- Basic knowledge of C programming and UNIX processes.
- Enthusiasm for low-level system programming!

Explore this project and dive into the intricacies of UNIX pipes on my [GitHub repository](#). Contributions and discussions are always welcome!

```

Remember to replace the placeholder URL with the actual link to your GitHub repository. This README provides a concise overview, usage instructions, a note on the bonus feature, and an invitation for others to engage with your project.