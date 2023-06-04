# Optional end topics

## Undefined behavior and co

Can you remember the part in the chapter about types, in which i was talking
about a "SpecialMachine"?  
This part exists because of undefined behavior within the C language.  
Undefined behavior means that the C standard itself does not define what happens
in every case. One such case is the exact size of an "int".  
The C standard defines an "int" being at least 16 bits long and at maximum 32
bits.  
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

## goto: chaos >:D

One technique to control the flow i haven't mentioned yet is `goto`. This is
because it's usage is very discouraged by most developers. The ones that do use
it will recommend you to tread lightly.  
  
It allows you to directly jump to certain line in you program, like so:  

```c
{{ #include ../code/22_optional-end-topics/evil-goto.c }}
```

With larger projects and extensive usage, this will become very hard to read
very quickly.  
General rule is: never use this if it is avoidable somehow and it basically
always avoidable.  

## Floats are scary

Now we talk about the precision. What do you think this cute little program
could spit out?  

```c
{{ #include ../code/22_optional-end-topics/float.c }}
```

Did you think it's a flat `0.3`?  
  
Nope. Floats are not at all precise like integers are. That is because fractions
would otherwise end up eating a lot of bytes. How exactly the bits are getting
shuffled around during the calculation, i do not want to demonstrate.  
  
I rather just want to raise your awareness about the fact, that floats cannot be
entirely trusted. Always use their results with a grain of salt and extra
care... or avoid using them altogether when possible.  

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
to run this, because i have included the results below.  

```c
{{ #include ../code/22_optional-end-topics/c-strings.c }}
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
BEFORE you can actually work with it. Imagine stepping through hundreds of
char’s each time having this check. Say goodbye to performance in that case.  
