<!-- YoRHa archive -->
```
▸ YoRHa // ARCHIVE — PIPEX
```

A C re-implementation of shell pipelines with fork, pipe, dup2 and execve.

| UNIT DATA | |
|---|---|
| Type | 42 Lausanne common-core project · solo |
| Stack | C · UNIX processes · pipes |
| Status | ■ COMPLETE |

## ▸ Overview
Reads an input file, runs a chain of commands connected by pipes, and writes the result to an output file, like `< file1 cmd1 | cmd2 > file2`. The bonus is supported: more than two commands, and a `here_doc` mode (appends to the output file).

## ▸ Usage
```bash
make
./pipex infile "ls -l" "wc -l" outfile
./pipex here_doc LIMITER "cmd1" "cmd2" outfile
```

---
<sub>▸ Archived by UNIT ALDE-OLI · [profile](https://github.com/alde-oli)</sub>
