# Comments

Comments are very important.  
The difference between readable code and obfuscated nonsense can be the usage of
comments.  
A beginner might falsely assume that his exercise programs are very simplistic
and can be understood instantly whenever needed. He is right, because his
programs are a single file with 30 lines of code.  
  
In actual programs you will end up with multiple files or maybe even multiple
directories with multiple files each, allowing the summarized line-count to
climb into the millions.  
Everyone who knows the Linux kernel will know, that I am not hyperbolic about
this.  
Introducing a new member into the team and making him read this, is good way to
make him run for his sanity.  
  
Comments are little notes that you put into your code. Optimally you use them in
a way to describe what the upcoming section of code will do.  

```c
{{ #include ../code/9/comments.c }}
```

See above we have a "//" and then one quick statement on what the developer
did there.  
If you put a "//" in your line everything after that will be a comment. The
compiler will not care what you type there.  
You can also use "/\*" to declare a whole section as a comment. Everything after
that, even spanning over multiple lines, is a comment. Just remember to close
this comment with the complimentary "\*/".  
Anyway, thanks to that comment we don't have to read the code and figure out
what could happen there.  
This saves a lot of time and should be used where necessary.  
That means, please keep yourself from explaining literally EVERYTHING to a
potential reader.  

```c
{{ #include ../code/9/genius.c }}
```

No one needs a refresher lesson in C every time they work with it. Everyone
knows that + is used for adding two numbers or that the printf function actually
prints text and where it comes from.  
  
As with many things in life, balance is the key. In this case, to keep your code
free and sane and by extent the minds of your entire team.  

## Where are comments

They are commonly found…  

- at the beginning of a file, describing what this file is responsible for.
- at the beginning of a function, describing what this function takes and
  returns and side-effects.
- at nifty code segments, that need a bit of explanation.

## Comments LIE

"WHAT!? What are you talking about?"  
That's right, comments can be actually wrong. This is perhaps one of the worst
scenarios a developer can find themselves in. Imagine discovering a bug, tracing
it down to a function that according to the comment, does something completely
different from what it actually does.  
Many brave souls probably have been lost this way.  
Of course one could just say: “JuSt UpDaTe YoUr CoMmEnTs!”, but humans are not
perfect and some stuff slips through the cracks.  
There is another solution for this...  

## How to not write comments (without it backfiring)

Yes, you can just delete 90% of your comments, assuming you write your program
in a specific way.  
If your symbols explain themselves, then no comments are needed.  

```c
{{ #include ../code/9/self_explanatory.c }}
```

This is a simple example with just one extra function but shows what is
important for the comment-less style.  
  
Keep your functions short and make them do just one thing.  
Shorten variable names as much as possible but make them still reasonable.  
At last, one comment is still left for the fall-through of the switch. This one
needs to stay, to tell everyone that these fallthroughs are intentional.  
