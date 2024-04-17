# Input

Usually you can design your cli-apps to not need any form of runtime
interaction, but that would be a foul excuse for me not to show it anyway.  
Plus what if you do actually need it?  

```c
{{ #include ../code/11/input.c }}
```

"scanf" easily allows you to not just get a string, but also a valid number from
a user, because it also handles the conversion for you.  
There are other functions that allow you to take input, like "gets" and "getc".  
I encourage you to find them, and play around for a bit.  

## No running in the hallways

One thing I want to mention is that input is like... a very dangerous pair of
scissors... and you shouldn't run with scissors.  
For as much fun they can bring into an application, it can also make you your
own worst enemy.  
User provided strings are a security relevant potential of bugs.  
Why that is comes later when we will talk about strings again.  
