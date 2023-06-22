# Loops

Important for a lot of things. In the upcoming example we have 3 integers, all
set to 1. With `while (condition)` we start a loop. This loop runs as long as
"a" is smaller than 100. Within every run of that loop we store the value of "b"
in "c", then "a" in "b" and then we calculate a new "a" from adding "b" and "c".
Thanks to the starting values of those 3 variables we can ensure that the "a"
will increase over time and the loop eventually exits.  

```c
{{ #include ../code/6/while.c }}
```

A loop has a head `while ()` and a body `{ ... }`.  
There are 3 kinds of loops in C:  

- while
- do while
- for

"do while" loops are similar to "while". The difference is, that the loop first
runs it's body and then it checks the condition in the head or in this case
foot.  

```c
{{ #include ../code/6/do_while.c }}
```

In my experience, this is the least used loop but definitely not useless. You
will know when you need it.  
"for" loops on the other hand are the most used loop, at least for me. A for
loop has bit more complex header, in which you have one statement that runs
before the loop starts, the condition and a statement that runs after each time
the loop body ran.  

```c
{{ #include ../code/6/for.c }}
```

Before this for loop runs we set the integer i to 0. Separate that statement
with a semicolon to put the condition and after that comes the statement that
runs after every loop run.  
So we practically just made a counter variable for this very loop.  
The name "i" is absolutely the standard for a counter in a for loop. No one will
complain about it because "i" stands for iterator and is common practice.  

## controlling the loop

You can control how the loop behaves in more complex situations with two nice
keywords "continue" and "break".  
"continue" will end the current run of a loop, to skip to the next one.  
"break" will completely stop the loop overall.  
This could look like so:  

```c
{{ #include ../code/6/loop_control.c }}
```

It's kind of a nonsensical example but it's good enough for demonstration.  
¯\\\_( ツ )\_/¯
