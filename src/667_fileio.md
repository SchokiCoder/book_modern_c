# File io

So far our io has been limited to the terminal.  
Interacting with files is crucial for a lot of programs.  
It isn't even that hard, infact it's very similar to what we did before but with
some extra steps.  
All we have to do is approach the operating system, kindly ask for access to the
file in question and then work with it.  

```c
{{ #include ../code/667_fileio.c }}
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
  
The operating system giveth and the operating system taketh, same for files.  
Remember to close them and brush your teeth.  
