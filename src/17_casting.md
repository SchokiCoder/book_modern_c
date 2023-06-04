# Casting

...dark spells to create the illusion of type-safety.  
To cast means to change a variables type. Effectively forcing the program to
interpret the values bytes differently. Remember that second sentence.  

```c
{{ #include ../code/17_casting/flip.c }}
```

Here we cast to the same sized integer but from unsigned to signed. Thanks to
that the printed number "flipped to" will be -294967296, at least on my
machine.  

## implicit conversion

I am not a fan of it but this language will come with implicit casts as well.
You should not rely on it though because it can be hard to see sometimes and as
such obfuscates your code.  

```c
{{ #include ../code/17_casting/implicit.c }}
```

To explicitly present a float do not forget to type the comma: 10.0 (and
technically a 'f' afterwards): `10.0f`  
Implicit casts can also come with data loss, in a very sneaky way:  

```c
{{ #include ../code/17_casting/data-loss.c }}
```

When a float is cast to an integer, everything after the comma will just be
dropped. This results in `20` as an output of this program.  
