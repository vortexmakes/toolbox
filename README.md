# Tools
A set of software tools about source code quality such as testing 
environment, static code analyzers, beautifiers, among others.

## Contents

- [Uncrustify](#uncrustify)
- [Static Code Analyzers](#static-code-analyzers)
- [Ceedling](#ceedling)
- [Deploy](#deploy)
- [Doxygen](#doxygen)
- [Git](#git)
------------------------------------------------------------------------------
## Uncrustify
### Running the program
Here are ways to run it:
```bash
# simple
$ uncrustify -c uncrustify.cfg module/*.h -l c

# with backup
$ uncrustify -c uncrustify.cfg module/*.h -l c --replace

# without backup
$ uncrustify -c uncrustify.cfg module/*.h -l c --no-backup
```
The `-c` flag selects the configuration file.

Alternatively multiple or single files that should be processed can be
specified at the command end without flags.
If the flag `--no-backup` is missing, every file saved with the initial
name and an additional suffix (can be changed with --suffix).

For more options descriptions call:
```bash
$ uncrustify -h
```
Or [Uncrustify official](https://github.com/uncrustify/uncrustify/blob/master/README.md#running-the-program)
### Some 3rd party tools
To ease the process a bit:
- [Universal Indent GUI](http://universalindent.sourceforge.net/) - A
  cross-platform graphical configuration file editor for many code
  beautifiers, including Uncrustify.
- [uncrustify_config](https://github.com/CDanU/uncrustify_config) - A web
  configuration tool based on Uncrustifys emscripten interface.
- [UncrustifyX](https://github.com/ryanmaxwell/UncrustifyX) - Uncrustify
  utility and documentation browser for Mac OS X

## Static code analyzers

## Ceedling
### Usage
```bash
$ cd module
$ ceedling ...
```

## Deploy

## Doxygen
### Usage
```bash
$ cd docs
$ doxygen Doxyfile
```

## Git
