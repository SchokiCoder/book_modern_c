# main()

This is where the real game begins or rather your programs logic.  
To start programming create a new file and call it “main.c”.  
  
The following is a "listing" or "snippet". Now make a "main.c" file and type the
following code into it:  
```c
{{ #include ../code/1_main/barebones.c }}
```

This is what pretty much every C program has at minimum.  
  
So lets begin at the top, there you will see “int” which is a type. After that
“main” is the name of the function. The brackets { } show what is in that
function. “return” tells that at this point the program should leave this
function and the zero is what it should take from that function. The semicolon
ends the line.  
  
Every program begins it execution in this main-function and it will execute by
going from the top to the bottom of that function. Once the end of the
main-function is reached, the program ends.  
What exactly types are and what it means to return from a function will be
covered soon but to get started, compile this with gcc, by typing this into a
terminal:  
  
```
gcc main.c -o my_app
```
  
If the compilation succeeded, you have created your first binary file or
executable file called "my_app".  
It does basically nothing but that's good enough for now.  
  
All the code snippets in this book, also come with this book as separate
files.  
Keep that in mind for later, as we can not rely on you typing everything of the
book.  
