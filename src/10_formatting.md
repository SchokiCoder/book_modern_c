# Formatting

The little brother of comments, here to help all programmers or the author of
the code himself reading said code.  
Formatting and comments are the most important things in the realm of
programming. If nobody is able to read your code, no one will want to work with
you. Given enough time, not even you yourself.  
I hope i can make my point clear, when quickly demonstrating that:  

```c
{{ #include ../code/10_formatting/sane.c }}
```

This is normal code, aside from being obviously fictitious. It has consistent,
sane formatting and comments where needed.  
So let's look at the same code but obfuscated.  

```c
{{ #include ../code/10_formatting/insane.c }}
```

That the readability is making a nosedive here is hopefully not up to debate.
The formatting is a violation against the geneva-convention, variable names
are... there, unlike comments. Well at least it decreased the line-count, too
bad this is worthless.  
Of course there is also no one right way to do it. For example this:  

```c
{{ #include ../code/10_formatting/opinion.h }}
```

is also a very common way to put curly brackets.  
It is up to your preference or the preference of your team leader. Please don't
ignore him when he is giving you formatting rules for your project.
The most beautiful formatting doesn't do anything if it is inconsistent with the
rest of the project.  
