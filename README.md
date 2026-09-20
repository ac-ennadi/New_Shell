# Newshell

A small Unix shell written in C++ with a C-based libft dependency. It includes
lexing, parsing, quote handling, environment expansion, redirections, pipes,
heredocs, signals, and builtin commands.

## Requirements

- Linux or another POSIX-compatible system
- `clang++`
- `make`
- GNU Readline development files

On Debian or Ubuntu, install Readline with:

```bash
sudo apt install libreadline-dev
```

## Build

From the project root:

```bash
make
```

The executable is created as `./newshell`.

## Usage

Start an interactive shell:

```bash
./newshell
```

Execute a command line without entering interactive mode:

```bash
./newshell -c "echo hello | wc -c"
```

Supported shell features include:

- Pipes: `|`
- Input and output redirections: `<`, `>`, `>>`
- Heredocs: `<<`
- Single and double quotes
- Environment expansion, including `$?`
- Builtins: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`

## Make Targets

```bash
make        # Build the project
make clean  # Remove object files
make fclean # Remove object files, libft archive, and executable
make re     # Clean and rebuild
```

## Project Layout

```text
include/  C++ project header files
libft/    Static libft library
src/      Shell implementation
objects/  Generated object files
```
