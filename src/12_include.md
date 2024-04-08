# Include

...someone else's work, so we can have a drink for once. Inclusions allow us to
split our project into multiple files when needed. The way `include` works in
the compiler is really simple. It basically just copies the entire content of
the target file into our file. The part of the compiler that takes care of
that is called the preprocessor. Usually we include header files, with the
ending ".h". They are specifically written to be included, which you'll see in a
second.  
  
Includes can look like this:  

```c
{{ #include ../code/12/include.c }}
```

The difference between < and " is where the preprocessor first looks for the
target file.  

- \<\> first looks for system files (such as "stdio.h")
- "" first looks in your local directory (for example "my_file.h", which sits
  next to "main.c")

Unfortunately the simplistic include implementation for the preprocessor came
with a rather interesting necessity for the programmer.  

## Header madness

Let's just imagine having a project with the following files:  

- main.c
- intstuff.h
- floatstuff.h

Within "main.c" we include the two headers, but "intstuff.h" also includes
"floatstuff.h". So we end up with the content of "floatstuff.h" being in
"main.c" twice.  
This is not good and will not be accepted by the compiler, because the content
will be redefined. If "floatstuff.h" also had to include "intstuff.h", so the
headers include each other, then the compiler would end up in an inclusion
loop.  
  
To bypass all of the madness, you practically must obey a certain way to write
header files.  
The following technique is called header guards.  

```c
{{ #include ../code/12/small_floatstuff.h }}
```

Here we have instructions for the preprocessor. These begin with a '#'
character. First we check if the symbol "_12_FLOATSTUFF_H" exists, and if it
doesn't exist, the preprocessor is free to actually include the next lines,
until the `#endif`. The symbol "_12_FLOATSTUFF_H" represents the filename.
That means the next time we include this file and the content is already
defined, the preprocessor just ignores it.  

## Definition vs Declaration

Imagine having a header file: "floatstuff.h":  

```c
{{ #include ../code/12/faulty_floatstuff.h }}
```

Here we have the function "floatadd", which is declared and defined. This can
cause some problems, because the compiler doesn't like it when a function is
defined multiple times. It can be declared as often as you like but not defined.
So we need another way to do this.  
By moving the implementation of the function into a respective "floatstuff.c"
file:  

```c
{{ #include ../code/12/floatstuff.c }}
```

After that the header looks like so:

```c
{{ #include ../code/12/correct_floatstuff.h }}
```

We don't need the function body (aka. the implementation) anymore,
and we don't even need the parameter names anymore.  
Please, consider keeping them for documentation purposes.  
  
Now to make use of this in "main.c", we have to include "floatstuff.h",
and then compile both "main.c" and "floatstuff.c".  
In gcc, this is how we do it:  

```
gcc main.c floatstuff.c -o my_app
```

"What is going on? Why is this so complicated?"  
Well, we basically have to do some work for the compiler. First, the function
is declared in the header-file. This way, every file that includes this header
can now "see" the function and use it. Since multiple files might include our
header, and function declarations can be done as often as you like, this is not
an issue. So now that other files can access the function, we need to actually
make something available under this function name.  
So we compile the "floatstuff.c", in which the function is defined, by just
listing it along with the main file:  

```
gcc main.c intstuff.c floatstuff.c -o my_app
```

We also include the header itself in that "floatstuff.c" file, because very
often the c-file needs something from its own header. In this case, we could
have stripped it out, but it's not bad to have it there.  
So practically, templates for those two files could look like...  
header:  

```c
{{ #include ../code/12/template.h }}
```

c-file:  

```c
{{ #include ../code/12/template.c }}
```
