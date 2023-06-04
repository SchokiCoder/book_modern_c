# Pointers

This is where the real game begins. Pointers are the most feared feature of all
programming except maybe polymorphic inheritance but that's not a topic for
today. Seriously though don't search for that on the internet, you won't sleep
that night.  
Anyways, Pointers are a way to make variables more accessible for the entire
program but unlike global variables in a controlled way. For example we can
change a variable via a function without using a return value.  
This is called return or out parameter.  

```c
{{ #include ../code/14_pointers/return-parameter.c }}
```

A pointer is just a variable. It is a number that is pointing towards a location
in memory. That is why the function can change your variable that it normally
wouldn't have access to. To declare a pointer is similar to a normal variable,
just append a star next to it, like i did in line 03 with that parameter.  
  
"In line 14 we call that function, so it can change that variable but what is
that ampersand for?"  
An ampersand before a variable means that you don't give something the value of
that variable but instead it's location in memory. This is called referencing
the variable and the opposite happens in line 05 where it is dereferenced.
To dereference means to access the memory location given in that pointer. After
that we can actually write to or read the value from that pointer.  
  
"So who needs return values, right?"  
You lad. Just because something is possible doesn't mean you have to use it.  
If you heavily disagree with me, feel free to use all of C++.  
Pointers are the number one reason for runtime errors, so avoid them if
possible.  
  
Anyways remember that pointers don't have the given type as a variable within
themselves, they just are a number pointing to other variables. If you try to
dereference a pointer while there is nothing in it, your program crashes and
burns, leaving you with a "Segmentation fault" in console.  

## Memory, please

Now were gonna make a pointer have it's own variable... kinda.  
So we can kindly ask the operating system if it gives us some more memory.  
  
_But with all great things comes a great responsibility,_  
_that of the programmers being runtime stability._  
_How, you ask, are they up to the task?_  
_To which the answer is a simple library._  

```c
{{ #include ../code/14_pointers/malloc.c }}
```

Now malloc is short for memory allocate and it's parameter is asking how many
bytes you want. This introduces us to the new operator "sizeof". "sizeof"
returns how many bytes are used for a given type or variable. After that we
assign 7 to the int and print it. As we come to the end of "ptr"s life we have
to remember to give it's memory back to the operating system, like a nice
person.  
Just call free on the pointer.  
  
This allocation also works for arrays but a bit more awareness is needed for
that.  

```c
{{ #include ../code/14_pointers/const-size.c }}
```

In the malloc-call we now need to multiplicate the size of an integer with the
amount of elements we want to have. Also with that constant we keep track of how
many elements we have.  
