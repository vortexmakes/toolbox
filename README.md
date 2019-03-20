# Tools
Files related to development tools 

------------------------------------------------------------------------------

## Uncrustify
- Running the program
  https://github.com/uncrustify/uncrustify/blob/master/README.md#running-the-program

  Here are ways to run it:
  ```
  $ uncrustify -c mystyle.cfg -f somefile.c -o somefile.c.unc
  $ uncrustify -c mystyle.cfg -f somefile.c > somefile.c.unc
  $ uncrustify -c mystyle.cfg somefile.c
  $ uncrustify -c mystyle.cfg --no-backup somefile.c
  $ uncrustify -c mystyle.cfg *.c
  $ uncrustify -c mystyle.cfg --no-backup *.c
  ```
  The `-c` flag selects the configuration file.
  The `-f` flag specifies the input file.
  The `-o` flag specifies the output file.
  If flag `-f` is used without flag `-o` the output will be send to `stdout`.

  Alternatively multiple or single files that should be processed can be
  specified at the command end without flags.
  If the flag `--no-backup` is missing, every file saved with the initial
  name and an additional suffix (can be changed with --suffix).

  For more options descriptions call:
  ```bash
  $ uncrustify -h
  ```
- Some 3rd party tools
  To ease the process a bit:
  - [Universal Indent GUI](http://universalindent.sourceforge.net/) - A
    cross-platform graphical configuration file editor for many code
    beautifiers, including Uncrustify.
  - [uncrustify_config](https://github.com/CDanU/uncrustify_config) - A web
    configuration tool based on Uncrustifys emscripten interface.
  - [UncrustifyX](https://github.com/ryanmaxwell/UncrustifyX) - Uncrustify
    utility and documentation browser for Mac OS X

------------------------------------------------------------------------------
