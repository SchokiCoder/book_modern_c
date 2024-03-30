# Arrays

An array is way to hold a lot of variables in one name.  

```c
{{ #include ../code/8/array.c }}
```

When brackets follow the variable name in the declaration, you get an array.  
Place a number within the brackets, the array will hold that many elements.  
Since the first element is addressed by 0, the last element will be addressed
with a 3 in this case.  
When accessing a value of an array, see the number in brackets as an offset
from a starting point.  
  
Since the C99 standard, there is another (better) way to create arrays.  

```c
{{ #include ../code/8/array_c99.c }}
```

Here the size of the array is automatically derived.  
Huh... if only there is a way to also get the array size at runtime,
thus eliminating the need to just hardcode it in the loop condition...  
;)  
(We'll get there soon.)  
