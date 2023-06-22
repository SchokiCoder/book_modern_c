# File io

So far our io has been limited to only the terminal but interacting with files
is crucial for a lot of programs.  
It isn't even that hard, in fact it's very similar to what we did before but
with some extra steps.  
All we have to do is approach the operating system, kindly ask for access to the
file in question and then work with it.  

```c
{{ #include ../code/16/fileio.c }}
```

First of "fopen" takes the two arguments filename and access mode.  
The mode can be one of these:

- "r" for read
- "w" for write
- "a" for append

There are technically more modes (by adding a plus after the letter) but those
rarely come up anyways so whatever.  
If the file doesn't already exist while you try to write or append it gets
created in that moment.  
  
"fopen" then returns a pointer to a file or NULL in case of an error, that's why
we check for it as well.  
There is also one small space character in "printf" and "scanf" and it's
actually crucial. It is used as a separator.  
  
The operating system giveth and the operating system taketh, it applies to
memory and it is the same for files.  
Remember to close them and brush your teeth.  
