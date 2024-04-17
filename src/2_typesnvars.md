# Types and variables

## Variables

Computing is all about getting results (of calculations), and to store these
results we need variables. In C these need to be declared. We do that by giving
them a type and a name.  

```c
{{ #include ../code/2/variables.c }}
```

Here we declare the two variables “my_id” and "counter" of the type "int".
After that we can save numbers in it.  
In case of “counter” we not just declare the variable, but also in the same line
define it by giving it a initial value.  
It is very important to choose short yet fitting names, depending on their
purposes.  

## Types

### Integer

The previously mentioned type “int” is the most common type in overall
programming, and represents a number. Its full name is “integer”, but don’t use
that in your code.  
There are many similar types like “unsigned int”, “short”, and “char”, which are
all numbers.  
  
"But why do we need types in the first place? Wouldn't things be much simpler
without them?"  
Short answer: No.  
Long answer: Hell, no. Types exist so that every developer and the compiler know
what exactly your plan regarding that variable is.  
Numbers are not all equal. Some are bigger or smaller than the average integer.
If you just need to store a number within a range of 0 to 100,
using just an `int` is fine, as it is in most cases. Now what happens if
you need to store numbers as big as 2147483648?  

```c
int a = 2147483648;
```

I compiled and ran this, and "a" was actually -2147483648.  
This is because `int` does not support this value, and so it had to endure an
integer overflow. This means I added a value to "a" that is too high,
and as a result the variable flipped its value on the head.  
This is because of the way integers are represented in memory, and I will
demonstrate it with an 8-bit value instead of an integer,
because ints have 32-bit in the case of my machine.  

### Binary shenanigans

#### Basics

When we assign 0 to "num"  

```c
unsigned char num = 0;
```

the binary representation for it looks like this:  
0 0 0 0 0 0 0 0
  
We now add 1 to "num",  
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
Now you might ask yourself "So how did that integer overflow happen?"  

#### Integer overflow

When you continually add one to a number, eventually you need another digit.  
Let's visualize this with a decimal with two digits:  

```
 7
 8
 9
10
```

But what if we are not allowed to actually use another digit...  

```
7
8
9
0
1
```

Oops, looks like this is all we can do here.  
This is what also happens to binary numbers.  
We add to the next digit (that doesn't exist) and set everything before that to
0.  

```
00
01
10
11
00
```

"Alright but what about negative numbers?"

#### Signed integers

Negative numbers are represented in a slightly different way, but first of all,
the ability to represent negative numbers is the difference between an
`unsigned int` and an `int` or `signed int`. The sign bit is used as an off/on
flag for the question "Is the current value negative?", and it is the leftmost
bit in the sequence.  
Unfortunately it's not that easy, and the best way to explain signed binary
values is to use that counting visualization from before plus a representation
of the decimal value (in parentheses next to it).  
To make signed integers efficient, their binary representation from positive to
negative is seamless.  
So imagine a signed binary number with three digits that we count down:  

```
011  ( 3)
010  ( 2)
001  ( 1)
000  ( 0)
111  (-1)
110  (-2)
101  (-3)
100  (-4)
```

In order to remove one from the decimal, we just remove one from the binary.  
Same with adding.  
  
With that in mind, we can now answer the question:  
"Why is  

```c
a = 2147483648;
```

resulting in 'a' being -2147483648 on my machine?"  
  
Because the bits flip over, and accidentally activate the sign flag.  
See 2147483647 + 1:  

```
01111111 11111111 11111111 11111111  ( 2147483647)
10000000 00000000 00000000 00000000  (-2147483648)
```

  
Now you can see why it is sometimes important to know
exactly which integer you want.  
To store the numbers you need, because each of them can store numbers within a
different range.  
Using a plain `int` will suffice, if there is no special need.  

### Float

Floats are used to store fractions.  
There are two types: "float" and "double".  
Double having double the size of a float, and with that it can store twice the
precision.  
What exactly I mean by precision is covered later.  
  
All you need to know now is that it stores fractions,
and that you use a point as the decimal separator:  

```c
float my_float = 22.05;
```

### Char

I kind of lied when I said char is _just_ a number. It technically is, but there
is more to it. In C the char is also used to represent textual characters. Char
has a range of 256 different values it can represent, and those numbers are used
as different characters. That means the following line:  

```c
char an_a = 'a';
```

is valid code that compiles. One important thing to note is that one char is
always surrounded by ' but not ". What " does comes later.  
Also please don't do this:  

```c
char not_like_this = 'invalid';
```

Since char can only hold one of these, this results in unforeseen consequences.  

### Void

This type tells everyone that it itself is not a thing.  
"Is that a joke?"  
Well no. It's going to be important later.  
For now know: one does not simply declare a variable of the void type.  

### Constants

They are like variables, but immutable. To declare a constant put "const" at the
beginning.  

```c
{{ #include ../code/2/constants.c }}
```

As you can see, declaration and usage are quite simple. Please use uppercase
names for constants, so you can tell them apart from a variable later on.  
