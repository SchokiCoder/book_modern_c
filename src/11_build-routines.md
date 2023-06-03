# Build routines

Build routines make the (at first) subtle difference in compiling your program,
changing your call from  
`gcc myfirst.c mysecond.c -o myapp -std=c99 -pedantic -Wall -Wextra -g`  
to just:  
`make`  
  
At first you might say: "No problem, i just have to type it once."  
That statement will be proven wrong in this chapter.  
When you write your code files and compile every now and then. For just a simple
example, in just one day then yes it is true. Once in a bigger project, that you
revisit the next day, that statement is wrong. You will need to retype it and
all sort of shenanigans can happen because of it.  

- like forgetting the standard or which standard
- like forgetting -g or other important compiler options
- like forgetting some c-files to list

Also in a real project there will be eventually at least two ways of compiling
your project. Resulting in a debug-build and a release-build.  
At this point, you have to remember not only that first gcc call, for your
debug-build but also the one for the release-build.  
So that is where we get to Makefiles:  

```Makefile
{{ #include ../code/11_build-routines/Makefile }}
```

Makefiles have to be named "Makefile". When you call make, it will look for the
first given routine, in this case "debug" and execute it. To use the release
routine call `make release`.  
Makefiles also have a bit syntax going on, as you can see with the variables at
the top.  
More on the make syntax later.  
