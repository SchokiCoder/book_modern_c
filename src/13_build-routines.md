# Build routines

Build routines make a (at first) _subtle_ difference in compiling your
program, by changing your call from  
`gcc myfirst.c mysecond.c -o myapp -std=c99 -pedantic -Wall -Wextra -g`  
to just:  
`make`  
  
At first you might say: "No problem, i just have to type it once,
and then get it back with my arrow keys."  
That statement will be proven wrong in this chapter,
unless you write some small source file, and work with it for just one session.  
  
Once in a bigger project that you revisit the next day, that statement is
wrong. You will need to retype it, and all sort of shenanigans can happen
because of that.  

- like forgetting the standard or which standard
- like forgetting -g or other important compiler options
- like forgetting to list some files

Also, in a real project there will be eventually at least two ways of compiling
your project. Resulting in a debug-build and a release-build.  
At this point, you have to remember not only that first call for your
debug-build, but also the one for the release-build.  
  
So that is where `make`'s Makefiles come in:  
_Disclaimer: We unpack this all in a second. Feel free to skip to the part
where i explain it to you immediately._

```Makefile
{{ #include ../code/13/Makefile }}
```

## The part where i explain it to you

This is the part where i explain it to you.  
  
Let's unpack this from top to bottom.  
This Makefile creates two binaries from the code files "main.c", "lib.h", and
"lib.c".  
Our app is "lib_math_test". That's what we call the binary. The debug
binary will be the same, but with a "D_" in front.  
  
Makefiles describe how files relate to each other, and what needs to be
recompiled if one changes.  
Practically speaking, it says:
```Makefile
my_file: (files it depends on as space separated list)
        command_to_create_that_file --with-args
```
  
Now let's focus on the first branch `lib_math_test`:  

- it depends on "main.o" and "lib.o", and compiles via the command $(CC)
- $(CC) is the variable from the top (`CC = whatever content`)
- ".o" files are object files, and are a in-between product of compilation
- in the call `$(CC) ${R_COPTS} -o $@ $^` they get linked into the binary
- $@ refers to the branch or file name
- $^ refers to the dependencies of that branch
- $< refers to the first dependency of that branch

\*Huff\* _breathe_...  
So... in the end, this call looks like this:  
`cc -std=c99 -pedantic -Wall -Wextra -Werror -Os -o lib_math_test main.o
lib.o`  
  
_Feel free to have a tea break._  
  
Now, off to the dependencies.  
"main.o" depends on "main.c", for which there is no branch since this file
comes from the authors hand... **my hand**.  
The only new thing to explain is the compiler option `-c`.  
It causes the linker **not** to run. Otherwise it would try to look for a "main"
function and all other symbols needed to make this file actually executable,
which would just get in our way at this point.  
  
## Why in-between files

In large projects, compiling takes a long time.  
`make` compiles only the files that have changed.  
This is based on the "last changed" timestamps of the files.  
If we compile via `make` and then change something in "lib.c", the timestamp
changes. `make` knows that "lib_math_test" depends on it, so these two
files will be rebuilt as described in the Makefile.  

## Insert killer transition for other minor stuff here

Makefiles have to be named "Makefile" or "makefile" to be used by the bare
`make` call. Otherwise you have to use `make -f MAKEFILE_NAME_HERE`.  
Then it builds the first target, unless you specify which target, by just
dumping its name after the `make` command.  
  
"... Oh, hang on... jeez, that was so much i almost forgot to ask:  
 What is with that 'clean' branch you presented at the bottom of the file?"  
  
Oh yeah. The clean branch never really creates a file called "clean"...  
so we hacked the system, and created a on demand function to quickly remove all
object files and binaries.  
  
Also remember that `make` is not restricted to the programming domain.  
You could technically use it for any other workflow too.  
