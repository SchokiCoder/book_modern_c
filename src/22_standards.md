# Professionals have standards

_Be polite._ (on StackOverflow)  
_Be efficient._ (by not writing code multiple times, unless with good reason)  
_Have a plan to debug every file you write._  
  
Wait hang on, this is not about personal procedure but rather about the
language.  
Oh well... still true though.  
  
The C programming language was created in the 1970s, and it didn't just sit
there rusting away. The language exists within standards, which have been
released over the years.  
  
The changes can affect the standard library and the language design itself.  
For example:  

```c
// one-line comment
/* original comment */
```

The one-line comment didn't exist officially until the C99 standard.  
A more impactful change would be in C11. The support for
generics... kind of:  

```c
{{ #include ../code/22/generics.c }}
```

This macro basically reroutes your "add" call to the according "addi" or "addf"
functions, depending on the type of your first parameter.  
  
When compiling with gcc you pick a standard with the "-std=cXX" compiler option.
XX being the standard's version like "c99".  
  
Additionally you need gcc's "-pedantic" compiler option too, to be notified by
the compiler when you don't strictly conform the given standard.  
In gcc using only the "-std" option turns off GNU extensions that contradict the
standard.  
