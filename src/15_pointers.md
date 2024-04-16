# Pointers

This is where the real game begins. Pointers are the most feared feature of all
programming, except maybe polymorphic inheritance, but that's not a topic for
today. Seriously though don't search for that on the internet, you won't sleep
that night.  
Anyways, pointers are a way to make variables more accessible for the entire
program, but unlike global variables in a controlled way. For example, we can
change a variable via a function without using a return value.  
This is called return- or out-parameter.  

```c
{{ #include ../code/15/return_parameter.c }}
```

A pointer is just a variable. It is a number that is _pointing_ towards a
location in memory. That is why the function can change your variable, which it
normally wouldn't have access to. Declaring a pointer is similar to a normal
variable. Just append a star next to it, like I did in the function with its
parameter.  
  
"In the function call, what is that ampersand for?"  
An ampersand before a variable means that you don't give something the value of
that variable but instead its location in memory. This is called referencing
the variable, and the opposite happens within the function, where it is
dereferenced. To dereference means to access the memory location given in that
pointer. After that, we can actually write to or read the value from that
pointer.  
  
"So who needs return values, right?"  
You lad. Just because something is possible doesn't mean you have to use it.  
If you heavily disagree with me, feel free to use all of C++'s features.  
Pointers are the number one reason for runtime errors, so avoid them if
possible.  
  
Anyways, remember that pointers don't have the given type as a variable within
themselves. They just are a number pointing to other variables. If you try to
dereference a pointer while there is nothing in it, your program crashes and
burns, leaving you with a `Segmentation fault` in console.  

## Memory, please

Now were gonna make a pointer have it's own variable... kinda.  
Normally the operating system gives us plenty of memory to work with, in the
stack.  
Sometimes programs need to do some heavier tasks.  
So if that won't work... use more memory.  

```c
{{ #include ../code/15/malloc.c }}
```

_But with all great things comes a great responsibility,_  
_that of the programmers being runtime stability._  
_How, you ask, are they up to the task?_  
_To which the answer is a disciplined mentality._  
  
`malloc` is short for memory allocate, and its parameter is asking how many
bytes you want. This introduces us to the new operator "sizeof". "sizeof"
returns how many bytes are used for a given type or variable. After that, we
assign 7 to the int and print it. As we come to the end of "ptr"'s life, we have
to remember to give its memory back to the operating system, like a nice
person.  
Just call free on the pointer.  
  
This allocation also works for arrays, but a bit more awareness is needed for
that.  

```c
{{ #include ../code/15/const_size.c }}
```

In the malloc-call we now need to multiply the size of an integer with the
amount of elements we want to have. Plus, with that constant we keep track of
how many elements we have.  

## Skill issues

Happens to everyone.  
Allocating memory, or working with pointers at all is a huge can of worms.  
Using memory after it's freed, using uninitialized pointers... and listing
everything that could go wrong with pointers would allow me to add 2 full pages.  
How to mitigate a lot of headaches?  
Add the compiler option `-fsanitize=address,undefined`.  
This doesn't magically compile your skill issues away, but it will tell you what
you did wrong. Sadly only at runtime of the compiled program, but better than
nothing.  
  
If we alter the above malloc example to instead have no actual memory under the
pointer:

```c
{{ #include ../code/15/fsanitized.c }}
```

Running the program will instead cause a giant error message:

```
15/fsanitized.c:9:14: runtime error: store to null pointer of type 'int'
AddressSanitizer:DEADLYSIGNAL
=================================================================
==9038==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000 (pc 0x000000401204 bp 0x7ffc37c1f570 sp 0x7ffc37c1f560 T0)
==9038==The signal is caused by a WRITE memory access.
==9038==Hint: address points to the zero page.
    #0 0x401204 in main 15/fsanitized.c:9
    #1 0x7fbd3f446149 in __libc_start_call_main (/lib64/libc.so.6+0x28149) (BuildId: 7ea8d85df0e89b90c63ac7ed2b3578b2e7728756)
    #2 0x7fbd3f44620a in __libc_start_main_impl (/lib64/libc.so.6+0x2820a) (BuildId: 7ea8d85df0e89b90c63ac7ed2b3578b2e7728756)
    #3 0x4010d4 in _start (/home/andy/projects/c_50_years_old_foundation/code/15/fsanitized+0x4010d4) (BuildId: 7461208b2d8e3cacb382b1febc77b6d6526bf2a8)

AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV 15/fsanitized.c:9 in main
==9038==ABORTING
```

This is very appealing, because it tells us what went wrong
(`store to null pointer`), and where it went wrong with a backtrace
(`in main 15/fsanitized.c:9`).  
