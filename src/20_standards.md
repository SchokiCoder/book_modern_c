# Professionals have standards

_Be polite._ (on StackOverflow)  
_Be efficient._ (by not writing code multiple times, unless with good reason)  
_Have a plan to debug every file you write._
Wait hang on, this is not about you or me but rather about the language.  
Oh well... still true, though.  
  
The C programming language was created in the 1970's and it didn't just sit
there rusting away. The language exists within standards, which have been
released over the years.  
  
The changes can affect the standard library and the language design itself.  
For example:  

```c
// one-line comment
/* original comment */
```

The one-line comment didn't exist officially until the C99 standard.  
A more radical and very useful change would be in C11. The support for
generics... kind of:  

```c
{{ #include ../code/20_professionals-have-standards/generics.c }}
```

This macro basically reroutes your "add" call to the according "addi" and "addf"
functions based on the type of your first parameter.  
  
When compiling with gcc you pick a standard with the "-std=cXX" compiler option.
XX being the standard's version like "c99".  
Use the "-pedantic" compiler option too, to be notified by the compiler when you
don't conform the standard. Why this needs to explicitly added for gcc to
actually take action, i don't know.  
