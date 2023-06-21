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
{{ #include ../code/22_fixsizeint.c }}
```

## goto: chaos >:D

One technique to control the flow i haven't mentioned yet is `goto`. This is
because it's usage is very discouraged by most developers. The ones that do use
it will recommend you to tread lightly.  
  
It allows you to directly jump to certain line in your program, like so:  

```c
{{ #include ../code/22_evil_goto.c }}
```

With larger projects and extensive usage, this will become very hard to keep
track of very quickly.  
General rule is: never use this if it is avoidable somehow and it basically
always avoidable.  

## Floats are scary

Now we talk about the precision. What do you think this cute little program
could spit out?  

```c
{{ #include ../code/22_float.c }}
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
{{ #include ../code/22_cstrings.c }}
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
the stack. This also comes with funny side-effect that you cannot change
anything within "ptr". If you try to change a character within you will be
granted a segfault.  
  
So remember C had it’s 50th anniversary this year, some _rust_ is gonna occur.  
Null-bytes as string terminators are horribly out of date and no new language
should use them anymore.  
One of the reason why they are bad is, in order to process that string you would
have to step through each char of the string and check if it is the null-char
**before** you can actually work with it. Imagine stepping through hundreds of
char’s each time having this check. Say goodbye to performance in that case.  

## Advanced scope rules

So far i have just mentioned that a variable from a function cannot be used in
another function but there is a lot more to scope rules.  
Normally when a variable reaches the end of it's scope, it stops existing.  

```c
{{ #include ../code/22_static.c }}
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
{{ #include ../code/22_extern.c }}
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
