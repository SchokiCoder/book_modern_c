# Optional topics for the end

Now there will be some topics that i think are optional to know but i highly
recommend reading them if you are interested in _actual_ C programming.  
If not and you'd rather begin your real programming in another language, skip to
the chapter "What happens now?".  

## Undefined behavior and co

Can you remember all the times when said something like "... at least on my
machine"?  
These additions exist because of undefined behavior within the C language.  
Undefined behavior means that the C standard itself does not define what happens
in every case. One such case is the exact size of an "int".  
The C standard requires an "int" to be **at least** 16 bits long.  
"Then who is defining the exact size at the end of the day?"  
  
The compiler, even if it results in demons flying out of your nose... don't
ask.  
Now before you ask why the C standard allows such horrific images to be rendered
in your head, remember that C is old. In it's early versions the primary
advantage of this was to allow the creation of performant compilers for all
kinds of machines. This way code can be compiled differently to be much more
fitting for a specific machine, without a heavy workaround. So knowing the
compiler and the targeted machine was a lot more important back then.  
  
In current year however standardization of the platforms turned this into less
of an advantage and more of a... nasal demon spawn-hole.  
  
Luckily we nowadays have fixed size integers that you can get from "stdint.h".  

```C
{{ #include ../code/24/fixsizeint.c }}
```

## goto: chaos >:D

One technique to control the flow i haven't mentioned yet is `goto`. This is
because it's usage is very discouraged by most developers. The ones that do use
it will recommend you to tread lightly.  
  
It allows you to directly jump to certain line in your program, like so:  

```c
{{ #include ../code/24/evil_goto.c }}
```

With larger projects and extensive usage, this will become very hard to keep
track of very quickly.  
General rule is: never use this if it is avoidable somehow and it basically
always avoidable.  

## Floats are scary

Now we talk about the precision. What do you think this cute little program
could spit out?  

```c
{{ #include ../code/24/float.c }}
```

Did you think it's a flat `0.3`?  
  
Nope. Floats are not at all precise like integers are. That is because fractions
would otherwise end up eating a lot of bytes. How exactly the bits are getting
shuffled around during the calculation, i do not want to demonstrate.  
  
I rather just want to raise your awareness about the fact, that floats cannot be
entirely trusted. Always use their results with a grain of salt and extra
care... or avoid using them altogether when possible.  
  
You take this instead:  
`printf("%1.20f\n", f);`  
and you will see how deep the rabbit hole goes.  

## In C const's are bonkers

By "const's" i mean variables with the `const` keyword.  
They are not fully protected by the compiler against change so that this:

```c
{{ #include ../code/24/const_fraud.c }}
```

actually compiles **without any warning despite -Wall and -Wextra!**  
The compiler **may** place the value in read-only memory or not.  
So this **may** fail at runtime... or not.  
  
This wouldn't be possible with the **true** constants of C... values.
You can use the preprocessor to practically give a constant value a name.  

```c
#define CONSTI 10
```

If you replace the `const int` from before with that, it doesn't compile.  
Same would technically also work for an anonymous enum:  

```c
enum {
    CONSTI = 10
};
```

With that you cannot control the type of your value however.  
With a preprocessor definition you could stuff like that:  

```c
#define CONSTI 10ul
#define CONSTF 10.5f
```

## C and strings

Originally text output was supposed to just happen at the end of this book. As
the book grew i noticed that it becomes very hard to demonstrate things without
it, so i decided against it.  
  
"Now why were you so afraid of this, it's not like..." it **sucks**, that's
why.  
Not text output by itself but the way it worked all the way back then when C was
made.  
  
"I am quite anxious about strings in C." _-some user on StackOverflow_  
...rightfully so, i think.  
  
Strings are not exactly as straight forward as you might have assumed.  
How does C store some text like “Hello World”?  
There is no built-in string type in C, so how?  
  
It depends on how it got declared / defined. In the following code we print out
a table with 4 columns. In the first column we see characters that are the same
for each string. Those are also the characters that we would see from a normal
printf call with these strings. Every column after that is dedicated to one
string. For every character we print the actual value in memory. You don't need
to run this, because i have included the results below the snippet.  

```c
{{ #include ../code/24/cstrings.c }}
```

Here are the results:  

```
char | arrfit | arrmore | ptr
 'H' |     72 |      72 |   72
 'e' |    101 |     101 |  101
 'l' |    108 |     108 |  108
 'l' |    108 |     108 |  108
 'o' |    111 |     111 |  111
 ' ' |     32 |      32 |   32
 'W' |     87 |      87 |   87
 'o' |    111 |     111 |  111
 'r' |    114 |     114 |  114
 'l' |    108 |     108 |  108
 'd' |    100 |     100 |  100
  NA |     78 |       0 |    0
  NA |     65 |       0 |   99
  NA |      0 |      72 |  104
  NA |      0 |     101 |   97
```

See how after the 'd' "arrmore" and "ptr" both have a zero while "arrfit" has a
random number?  
"arrmore" and "ptr" have null-bytes there signaling that the strings ends.
"arrfit" doesn't have that because we could barely fit the string itself into
the array. C sneakily just throws the responsibility onto you. You now have to
remember how long this string is, for as long as it exists.  
  
Also there is a difference in where this data is saved. The actual string of
"ptr" has been baked into the binary file. While the array-based strings are in
the stack. This also comes with the funny side-effect that you cannot change
anything within "ptr". If you try to change a character within you will be
granted a segfault.  
  
So remember C had it’s 50th anniversary this year, some _rust_ is gonna occur.  
Null-bytes as string terminators are horribly out of date and no new language
should use them anymore.  
One of the reason why they are bad is, in order to process that string you would
have to step through each char of the string and check if it is the null-char
**before** you can actually work with it. Imagine stepping through hundreds of
char’s each time having this check. Say goodbye to performance in that case.  
  
If the length available in a string is not checked while working with the
consequences can be fatal for your users.  
Strings are a very common attack vector.  
For example if you copy one string to another but the destination string doesn't
have enough space **and** the length of the copy operation is not limited, you
end up overwriting other data.  

## Advanced scope rules

So far i have just mentioned that a variable from a function cannot be used in
another function but there is a lot more to scope rules.  
Normally when a variable reaches the end of it's scope, it stops existing.  

```c
{{ #include ../code/24/static.c }}
```

This new little keyword in "func" makes "i" preserve it's value between the
individual calls of the function.  
  
_Now the surgery is complete_  
_And mortality is defeated_  
  
But don't worry it's **not** a global variable it's still just accessible from
within "func".  
To continue it's best to split the previously vaguely used term "scope" into
"storage duration" and "linkage".  

### storage duration

"i" has a so called "static storage duration", which means it exists for as long
as our program runs. This also means it is initialized just once.  
  
On the other side we have the default: "automatic storage duration".  
It get's created at the start of the block it was declared in and dies with the
end of the block.  

### linkage

There are three kinds of linkage: external, internal and no linkage.  

# TODO
Example for extern!

```c
{{ #include ../code/24/extern.c }}
```

### Sum up

Here are all the keywords that manipulate the scope of objects and functions:  

Keyword  | storage duration | linkage
---------|------------------|---------
static   | static           | internal
extern   | static           | external
register | automatic        | none
auto     | automatic        | none

All objects have some linking and storage duration by default:  

Object                  | storage duration | linkage
------------------------|------------------|---------
variable at block scope | automatic        | none
variable at file scope  | static           | internal
function                | nothing to store | external

## Linking files

This is the process of stitching the application together from multiple
pieces.  
The reason why we can use things like "printf" is because we include "stdio.h"
from the standard library. This library is automatically linked to our program
out of convenience.  
  
For other external libraries or our own c-files in case we have multiple for one
project we need to explicitly link these parts together.  
This has already been demonstrated in the build routines chapter.  
Multiple c-files are compiled into their respective o-file and they then get
linked into the actual executable binary by just listing them in the compile
command.  
Example: `clang main.o lib.o -o executable`  
  
There are two kinds of library objects: "statically" and "dynamically" linked
libraries.  
In order to link a library a path must be given. Most operating systems have a
path environment variable already set up which allows you to just drop the
library in that predestined directory.
After that you must (in the case of gcc and clang) give the -l option with the
library name.  
Example: `clang main.o -l SDL2 -o executable`  
  
If you path environment variable can't be set or you can't add your library into
that directory you can also explicitly tell the compiler where to find libraries
with for example `-L ../mylibs/`.  
This is sometimes also necessary for the header includes like:  

```C
#include <SDL.h>
```

This is also based on that path environment variable.  
The compiler option "-I" lets you give a path for includes.  

## Single header libraries (SHL's)

Do you think that the linking business from before is bonkers?  
Boy, do i have something to sell you.  
  
Single header libraries are what the name says. The **entire library** is in one
header file. You include it and then it's there.  
Well okay it's not that easy after all.  

Remember recursive file inclusion, yeah you do.  
_(If not, it's mentioned in the include chapter)_  
  
SHL's do combat this issue by utilizing the preprocessor.  

```c
{{ #include ../code/24/shl.h }}
```

So to actually use this, you must define the IMPL symbol **before** you include
the header.  
You must also then keep track of just define this symbol once where it is needed
or else you will be plagued by multiple function definitions etc.  

```c
{{ #include ../code/24/shl_use.c }}
```
