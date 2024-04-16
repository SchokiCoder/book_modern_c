# File io

So far our io has been limited to only the terminal, but interacting with files
is crucial for a lot of programs.  
It isn't even that hard. In fact it's very similar to what we did before, just
with some extra steps.  
All we have to do is approach the operating system, kindly ask for access to the
file in question, and then work with it.  

```c
{{ #include ../code/16/fileio.c }}
```

First of, "fopen" takes the two arguments filename, and access mode.  
The mode can be one of these:

- "r" for read
- "w" for write
- "a" for append

There are technically more modes (by adding a plus after the letter), but those
rarely matter anyways, so explore them later... or not.  
If the file doesn't already exist when you try to write or append to it, it gets
created at that moment.  
  
"fopen" then returns a pointer to a file or NULL in case of an error. That's why
we check for it as well.  
There is also one small space character in "fprintf" and "fscanf", and it's
actually crucial. It is used as a separator.  
  
The operating system giveth and the operating system taketh.  
It applies to memory, and it is the same for files.  
Remember to close them, and brush your teeth.  
