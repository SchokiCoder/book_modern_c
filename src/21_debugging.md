# Debugging

Depending on the quality of your code, this is where the real game begins.  
Everyone has to deal with a debugger sooner or later, no matter how good you are
or what language you use.  
  
A debugger is a program that helps you understand the runtime behavior of your
program, by granting you the infinite power of time.  
Before we can debug a program, we have to help the debugger helping us,
by compiling the targeted program with the compiler-option "-g". This will
compile the program in a way, so that function-names, variables-names, and other
helpful information are stored in the binary.  
  
So let's first get a project with a faulty piece of code, that we have to debug,
and we start with the main file:  

```c
{{ #include ../code/21/faulty.c }}
```

Now here comes the faulty string library:  

```c
{{ #include ../code/21/string.h }}
```

```c
{{ #include ../code/21/faulty_string.c:all }}
```

The debugging will not focus on "string_utils", so just give them a quick
glance:  

```c
{{ #include ../code/21/string_utils.h }}
```

```c
{{ #include ../code/21/string_utils.c }}
```

The goal of our program is to print:  

```
1: hi
2: two + one
quick math
```

and we have a crude library to abstract the string handling away.  
This way the main-file is short and obvious.  
But if we run it, the second line is empty, aside from the number.  
  
To start debugging type in console:  
`gdb my_binary`  
After that a bunch of text appears, and you will be left with this line (or
similiar):  
`(gdb)`  
in which your cursor patiently waits for your command.  
Type `start`, hit enter, so then gdb starts your program, and displays in which
line you currently are. At this point the execution of the program is stopped,
so you can take your sweet time.  
  
So let's first assess what we know from the main-file. We have two strings.
"str_hi" is not a problem, so we don't have to focus on it. "str_twoplusone" is
supposed to carry a string to the printf function call. "str_twoplusone" is
getting initialized with no real value, but that value is appended three lines
later on.  
  
It seems that the function "String_append" is not doing its job correctly. So
let's get bloody goin, by entering the command `n` (short for `next`) in gdb, we
can line by line work our way towards the problematic point.
When gdb displays:  
`String_append(&str_twoplusone, "two");`  
Don't enter `next` anymore.  
  
Now we want to get into that function. Enter the command `s` or `step`. Now
let's have a glance at "String_append":  

```c
{{ #include ../code/21/faulty_string.c:String_append }}
```

First using the utils, we get the length of the string that we want to append.  
Then we update the string's values "len" and "size", and reallocate memory for
the string.  
Finally we copy the appendage onto the end of the string.  
  
"So maybe 'string_len' does not work, giving us the wrong 'len', causing the
'string_copy' function to do nothing?"  
Let's find out!  
First enter `next`, so that "len" gets the result of "string_len".  
Now to display a variable-value, enter the command `print` followed by the
variable-name, and the result is 3. So "string_len" was not the culprit.  
  
Let's see what happens below.  
Enter `adv` or `advance` and then the line-number in which "string_copy" is
called.  
Now let's `print *self` to gain a bit of an overlook over how the new values
look like:  
`{size = 11, len = 3, str = 0x5555555592c0 ""}`  
  
Huh... look closely at the "string_copy" call. The first parameter is a pointer
to string, and we certainly give that to the function.
We take the "str" pointer, go to a certain position within it,
and return a pointer from that position. This
position is supposed to be the end of the string, so that the appendage gets
copied after the string.  
  
However, the position given is not correct though. Our string is still empty,
but "len" is not 0.  
Here is the fixed "String_append". Read the comment within:  

```c
{{ #include ../code/21/correct_string.c:String_append }}
```

To stop gdb just enter `quit`. Technically with extensive code-reading alone,
this could have been caught too, but the debugger helped us through the journey,
without having to read EVERY line in order of expected execution, and mentally
memorizing what every variable should hold at that point.  

## How to not debug

I hope that i could make clear how valuable the debugger is.  
Beginners like to debug in different way. Before they learn how powerful a
debugger is, or that it exists.  
Maybe you also already did that so far. I wouldn't blame you if you did. In that
case, you just used the tools available to you at that time, which is good.
Probably every beginner did it that way at some point. I did it, you did it,
Jacob Sorber did it, and even my unborn children will do it.  
  
The wrong way to debug is misusing the "printf" function to display variables at
runtime.  
This _can_ work at first, but it has quite a few shortcomings:  

- if the program crashes before the "printf", then it didn't help at all (with
  gdb you use `bt` or `backtrace` to find out where it crashed and potentially
  why)
- the output of "printf" is usually buffered, meaning that it can be put out to
  the console later than you actually anticipated
- you may forget to remove a "printf" call before release
- you have to do your own formatting every time or remember the order of
  "printf" calls and what is fed to them
- you can't halt the execution
- you may get a new bug because of the print
- it is slower to do

"Wait that last one is not true, i can add all my 'printf' calls in 10 seconds
flat."  
Yes, you can but when is your debugging really done with just a few print
calls?  
Just imagine debugging our previous example with only "printf".  
Also the other reasons are more than enough to deter every experienced
programmer from that.  
