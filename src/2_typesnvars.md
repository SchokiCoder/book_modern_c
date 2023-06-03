# Types and variables

## Variables

To store values, we need variables and to declare them, we have to give them a type and a name.  
```c
{{ #include ../code/2_types-and-variables/variables.c }}
```

Here we declare the two variables “my_id” and "counter" of the type "int".
After that we can save numbers in it.  
In case of “counter” we not just declare the variable but also in the same line
define it, by giving it a value.  
It is very important to choose short yet fitting names, depending on their
purposes.  

## Types

### Integer

The previously mentioned type “int” is the most common type in overall
programming and represents a number. Its full name is “integer”, but don’t use
that in your code.  
There are many similar types like “unsigned int”, “short” and “char”, which are
all numbers.  
  
"But why do we need types in the first place? Wouldn't things be much simpler
without them?"  
Short answer: No.  
Long answer: Hell, no. Types exist so that every developer and the compiler know
what exactly your plan regarding that variable is.  
Numbers are not all equal. Some are bigger or smaller than the average integer.
If you just need to store a number within a range of 0 to 100 then there is
really no issue most of the time with any kind of integer. Now what happens if
you need to store numbers as big as 2147483647?  
```c
int a = 2147483647;
```
I compiled and ran this and "a" was indeed 2147483647, yay.  
However it was -1 on a fictional machine, that i now call "SpecialMachine".  
This is because "SpecialMachine" does not support this code and so it had to
endure an integer overflow. This means i added a value to "a" that is too high
and as a result the variable flipped it's value on the head.  
This is because of the way integers are represented in memory and i will
demonstrate it with an 8-bit value instead of an integer, because it has 32-bit
in the case of "SpecialMachine".  

### Binary shenanigans

When we assign 0 to "num"  
```c
unsigned char num = 0;
```
the binary representation for it looks like this:  
0 0 0 0 0 0 0 0
  
We now add 1 to "num"  
num = num + 1;  
and it changes as follows:  
0 0 0 0 0 0 0 1  
  
Now when we add more  
num = num + 7;  
it changes again:  
0 0 0 0 1 0 0 0  
  
Each bit in this byte sequence represents a specific number. Add the number of
each bit and you get the decimal representation.  

| bit                    | 8th | 7th | 6th | 5th | 4th | 3rd | 2nd | 1st |
|------------------------|-----|-----|-----|-----|-----|-----|-----|-----|
| decimal representation | 128 | 64  | 32  | 16  | 8   | 4   | 2   | 1   |
| binary value           | 0   | 1   | 0   | 1   | 0   | 0   | 0   | 1   |

64 + 16 + 1 = 81  
Make sure to understand this information before proceeding.  
Now you might ask yourself "Alright but where exactly do the negative numbers
come in?"  
Negative numbers are represented in a slightly different way but first of all,
the ability to represent negative numbers is the difference between an "unsigned
int" and an "int" or "signed int". The sign bit is used as an off/on flag for
the question "Is the current value negative?" and it is the leftmost bit in the
sequence.  

| bit                    | 8th | 7th | 6th | 5th | 4th | 3rd | 2nd | 1st |
|------------------------|-----|-----|-----|-----|-----|-----|-----|-----|
| decimal representation | *-1 | 64  | 32  | 16  | 8   | 4   | 2   | 1   |
| binary value of x      | 0   | 0   | 1   | 1   | 0   | 1   | 0   | 1   |
| binary value of y      | 1   | 0   | 1   | 1   | 0   | 1   | 0   | 1   |

x) 32 + 16 + 4 + 1 = 53  
y) -1 * (32 + 16 + 4 + 1) = -53  
  
With that in mind we can now answer the question:  
"Why is  
```c
a = 2147483647;
```
resulting in 'a' being -1 on 'SpecialMachine'?"  
  
Because the bits flip over and represent something they weren't supposed to.  
Now you can see why it is important to know exactly which integer you want. To
store the numbers you need, because each of them can store numbers within a
different range.  

### Float

Floats are used to store fractions.  
There are two types: "float" and "double".  
Double having double the size of a float and with that can store twice the
precision.  
What exactly i mean by precision is covered later.  
  
All you need to know now is that it stores fractions and that you use a point as
a comma:  
```c
float my_float = 22.05;
```

### Char

I kind of lied when i said char is just a number. It technically is but there is
more to it. In C the char is also used to represent textual characters. Char has
a range of 256 different values it can represent and those numbers are used as a
character. That means the following line:  
```c
char an_a = 'a';
```
is valid code and compiles. One important thing to note is that one char is
always surrounded by ' but not ". What " does comes later.  
Also please don't do this:  
```c
char not_like_this = 'invalid';
```
Since char can only hold one of those, this results in unforeseen
consequences.  

### Void

This type tells everyone, that it itself is not a thing.  
One does not simply declare a variable with the type being void.  
"Is that a joke?"  
Well, no. It's going to be important later.  

### Constants

They are like variables but immutable. To declare a constant put "const" at the
beginning.  

```c
{{ #include ../code/2_types-and-variables/constants.c }}
```

As you can see, declaration and usage are quite simple. Please use uppercase
names for constants, so you can tell them apart from a variable later on.  
