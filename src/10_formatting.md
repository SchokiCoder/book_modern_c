# Formatting

The little brother of comments, here to help all programmers and the author of
the code himself reading said code.  
  
Formatting and comments are the most important things in the realm of
programming. If nobody is able to read your code, no one will want to work with
you. Given enough time, not even you yourself.  
  
I hope i can make my point clear, when quickly demonstrating that:  

```c
{{ #include ../code/10/sane.c }}
```

This is normal code, aside from being obviously fictitious. It has consistent,
sane formatting and comments where needed.  
So let's look at the same code but obfuscated.  

```c
{{ #include ../code/10/insane.c }}
```

That the readability is making a nosedive here is hopefully not up to debate.
Just to name a _few_ issues, the case order is a mess, variable names are...
there, unlike comments.  
Well at least it decreased the line-count, too bad this is not worth the
price.  
  
Of course there is also no one right way to do it. For example this:  

```c
{{ #include ../code/10/gnu.c }}
```

is a small example of the GNU code format.  
  
Aside from it, this book uses the Linux code format with a maximal line length
of 80.  
I prefer that because it forces you to keep the amount of indentations low,
which keeps code complexity mostly low as well.  
  
Which format is used depends on your preference or the preference of your
project leader. Please don't ignore him when he is giving you formatting rules
for your project. The most beautiful formatting doesn't do anything if it is
inconsistent with the rest of the project.  
