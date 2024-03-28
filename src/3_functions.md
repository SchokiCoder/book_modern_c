# Functions

A function is a sequence of code that you can call at any moment. You can
define a function that takes data and or returns data. Data taken by a
function is called arguments or parameters. The parameters are only copies of
the original data. You can give a function as many parameters as you like but a
function can only return one value. To call a function, write it's name and put
parentheses next to it.  
Within the parentheses of the function call are the values for the parameters.  

```c
{{ #include ../code/3/functions.c }}
```

As a side-note, we return a number from main to tell the operating system,
which is practically calling our main function, if our program ran as expected
or if it had some trouble.  
A zero means everything is a-OK.  
  
Now is the time to tell you that the type "void" is not a joke.  
If you need a function, that does not return a value or take parameters you use
"void".  

```c
void my_fun(void) { ... }
```

This also allows you to define the function without having to use the "return"
keyword but you can still use it in case you need to quit from a function
early.  
