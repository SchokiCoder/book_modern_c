# Conditions

## Basic checks

"Do you know the way?" -your Compiler.  
One of the most common concerns for programmers is to control the operation of
the program, and to react to different states and cases. This is also called
"control flow", because we will now manipulate the way our program runs or
"flows".
Remember, normally it goes from top to bottom but we can manually change that
here.  
This is a simple example, in which we have a number and want to set it to 1 if
it is not already, otherwise it should become zero:  

```c
{{ #include ../code/5/if.c }}
```

"num" is set to zero, then with `!=` we check if "num" is **not** equal to
one.  
Since zero and one are not equal, this will execute and "num" is now 1,  
but we have a problem.  
With `num == 1` it is checked to be equal to 1 and as a result set back to 0.  
  
"So how can we check these two cases without setting 'num' to 1 and back to
0?"  

```c
{{ #include ../code/5/else.c }}
```

This makes much more sense to write. Not only do we not need to explicitly check
against the opposite case, we also don't accidentally play value ping-pong with
poor "num".  
So we check for "num" to be not 1 and react accordingly. Now what if we also
need to check a special case in which "num" is 43?  

```c
{{ #include ../code/5/else_if.c }}
```

Yup, you can chain an if onto an else and you can do that as often as you like.
Keep in mind, that in such a chain there is only one beginning "if" and only one
or none ending "else" branches.  
  
By the way, the brackets for if are optional as long as you have just one
statement.  

```c
{{ #include ../code/5/no_brackets.c }}
```

Some discourage that format. I mostly don't, but more on formatting later.  

## Switch

Now you may have already seen the running scheme of ergonomics baked into C, and
conditions are no exception for that. If we now have to check if "num" is 68,
43, 101 or 7 we instead use switches.  

```c
{{ #include ../code/5/switch.c }}
```

Much better to write and read. Use switches when appropriate and with care.
Every case must be ended with "break" if you want to do just one thing. If the
break is not set, the next case will run as well. So forget the break
statement in one case, and you can prepare for the fallout of unintended
variable manipulations down the line. The "default" branch works like the "else"
branch in an if-chain.  
  
Don't forget that C is a low level language, basically a thin
abstraction over assembly, the language of the machine.  
That means you can't just toss a string into a switch or anything that isn't a
number.  

## Operators

Now as promised, finally all the operators:  

| Operator with Example | Effect                  |
|-----------------------|-------------------------|
| a == b                | a equal to b            |
| a != b                | a not equal to b        |
| a < b                 | a smaller than b        |
| a > b                 | a bigger than b         |
| a <= b                | a smaller or equal to b |
| a >= b                | a bigger or equal to b  |

## Boolean

I have not brought up the boolean type so far, because it did not always exist
in the C language, and even now it just exists as a band-aid-patch. It is not
usable out of the box. You have to import it, as seen below.  

```c
{{ #include ../code/5/boolean.c }}
```

What exactly "include" does will be explained later, so don't worry. All that
you need to know now is that you can import functionality from somewhere else
via "include".  
In this case we include "stdbool.h", which is a file from the C standard
library, which brings us the boolean type, and its values "true" and "false".  
This way we don't have to question truth every time, and can instead remember
the result as long as needed.  
  
At its heart, boolean is eyecandy. The same work could be achieved by just using
an integer, and using 0 as false and 1 as true, but this _could_ be ambigous for
the reader in some cases.  
A variable called "success" as a bool clearly conveys that there is either
success or not. If it instead were an integer, this could also be interpreted to
count the amount of successes.  
In that case, the name "succesful" would be more appropriate.  

## Multiple conditions and more operators

Sometimes multiple cases shall lead to the same outcome, and for that case we
have special operators.  

```c
{{ #include ../code/5/logical.c }}
```

With the second `if`, we check if "num" is 23 AND check if "num_even" is true.
With the third `if`, we check if that boolean is false.  

| Operator with Example | Effect           |
|-----------------------|------------------|
| a && b                | is a and b true? |
| a \|\| b              | is a or b true?  |
| !a                    | is a not true?   |
