# Toolbox
A set of software tools about source code quality such as testing 
environment, static code analyzers, code beautifiers, among others.

## Contents

- [Uncrustify](#uncrustify)
- [Static Code Analyzers](#static-code-analyzers)
- [Ceedling](#ceedling)
- [Deploy and release](#deploy-and-release)
- [Doxygen](#doxygen)
- [Git](#git)
- [Vim](#vim)
- [Docker](#docker)
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
Documentation and license info exists in the [Ceedling's repository](https://github.com/ThrowTheSwitch/Ceedling/blob/master/docs/CeedlingPacket.md)

### Testeable module templates
The ceedling directory contains several templates to create testable 
modules using [Ceedling](https://github.com/ThrowTheSwitch/Ceedling.git). Each template has its own YAML file which indicates 
how to invoke Ceedling from a shell. 
The [ceedling/template](https://github.com/vortexmakes/toolbox/tree/master/ceedling/template) directory includes the templates listed below:
- [moduleUnderTest](https://github.com/vortexmakes/toolbox/tree/master/ceedling/template/moduleUnderTest): it might be applied to a regular C module
- [rkh-sm-template](https://github.com/vortexmakes/toolbox/tree/master/ceedling/template/rkh-sm-template): it might be applied to a RKH framework's active object. In this case the active object's state machine has been implemented through Sm.h, SmAct.h, Sm.c and SmAct.c files which are properly located in inc/ and src/ directories.
- [rkh-sm-unified-template](https://github.com/vortexmakes/toolbox/tree/master/ceedling/template/rkh-sm-unified-template): it might be applied to a RKH framework's active object. In this case the active object's state machine has been implemented through Sm.h and Sm.c files which are located in inc/ and src/ directories respectively.
- [sm-template](https://github.com/vortexmakes/toolbox/tree/master/ceedling/template/sm-template): it might be applied to a state machine module

## Deploy and release

## Doxygen
A [Doxygen](https://github.com/doxygen/doxygen) configuration file ([Doxyfile](https://github.com/vortexmakes/toolbox/blob/master/doxygen/Doxyfile)) for developing C/C++ code is available in [doxygen/](https://github.com/vortexmakes/toolbox/tree/master/doxygen) directory.
#### Usage
```bash
$ doxygen Doxygen # Execute it from a directory to generate source code documentation
```

## Git
The file [git-cheapsheet.md](https://github.com/vortexmakes/toolbox/blob/master/git/git-cheatsheet.md) provides a simple Git cheap sheet. This file is located in [git/](https://github.com/vortexmakes/toolbox/tree/master/git) directory. Aditionally, this directory contains a couple of useful files to using Git in a C/C++ project such as .gitignore

## Vim
A [Vim](https://www.vim.org/) configuration file ([.vimrc](https://github.com/vortexmakes/toolbox/blob/master/vim/.vimrc)) for developing C/C++ code is available in [vim/](https://github.com/vortexmakes/toolbox/tree/master/vim) directory.

## Docker
If you want to use a Docker container to develop your own code using [Ceedling](https://github.com/ThrowTheSwitch/Ceedling.git), 
you can clone [codequality](https://github.com/vortexmakes/codequality.git) repository.
This [guide](https://github.com/vortexmakes/codequality/blob/master/README.md) explains how to use this container from shell.
