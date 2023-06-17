# Conditions

## Basic checks

"Do you know the way?" -your Compiler  
One of the most common concerns for programmers is to control the operation of
the program and to react to different states and cases. This is also called
"control flow" because we will now manipulate the way our program runs or flows.
Remember normally it goes from top to bottom but we can manually change that
here.  
This is a simple example, in which we have a number and want to set it to 1 if
it is not already, otherwise it should become zero:  

```c
{{ #include ../code/5_if.c }}
```

"num" is set to zero, then with `!=` we check if "num" is **not** equal to
one.  
Since zero and one are not equal, this will execute and "num" is now 1  
but we have a problem.  
With `num == 1` it is checked to be equal to 1 and as a result set back to 0.  
  
"So how can we check these two cases, without setting 'num' to 1 and back to
0?"  

```c
{{ #include ../code/5_else.c }}
```

This makes much more sense to write. Not only do we not need to explicitly check
against the opposite case but now we also don't accidentally play value
ping-pong with poor "num".  
So we check for "num" to be not 1 and react accordingly. Now what if we also
need to check a special case in which "num" is 43?  

```c
{{ #include ../code/5_else_if.c }}
```

Yup, you can chain an if onto an else and you can do that as often as you like.
Keep in mind, that in such a chain there is only one beginning "if" and only one
or none ending "else" branches.  
  
By the way the brackets for if are optional as long as you have just one
statement.  

```c
{{ #include ../code/5_no_brackets.c }}
```

Some discourage that format, i do not.  

## Switch

Now you may have already seen the running scheme of ergonomics baked into C and
conditions are no exception for that. If we now have to check if "num" is 68,
43, 101 or 7 we instead use switches.  

```c
{{ #include ../code/5_switch.c }}
```

Much better to write and read. Use switches when appropriate and with care.
Every case must be ended with "break" if you want to do just one thing. If the
break is not set, then the next case will run as well. So forgetting the break
statement in one case, you can prepare for the fallout of unintended variable
manipulations down the line. The "default" branch works like the "else" branch
in an if-chain.  

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

The boolean type i so far have not brought up, because it did not always exist
in the C language and even now it just exists as a band-aid-patch. It is not
usable just like that. You have to import it, as seen below.  

```c
{{ #include ../code/5_boolean.c }}
```

What exactly "include" does will be explained later so don't worry. All that you
need to know now is that you can import functionality from somewhere else via
"include".  
In this case we include "stdbool.h" which is a file from the C standard library,
that brings us the boolean type and it's values "true" and "false".  
This way we don't have to evaluate cases every time and instead remember the
result as long as needed.  

## Multiple conditions and more operators

Sometimes multiple cases shall lead to the same outcome and for that case we
have special operators.  

```c
{{ #include ../code/5_logical.c }}
```

With the second `if` we check if "num" is 23 AND check if "num_even" is true.
With the third `if` we check if that boolean is false.  

| Operator with Example | Effect           |
|-----------------------|------------------|
| a && b                | is a and b true? |
| a \|\| b              | is a or b true?  |
| !a                    | is a not true?   |
