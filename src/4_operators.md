# Operators 101

Now that we have landed on the C planet, we can truly explore the caves.  
So far you have only seen the very basic usage of + and =  
but there is much more to these operators.  
  
Previously i have shown you something like this:  

```c
a = a + 5;
```

but writing it like this can get very tedious.  
That's why we can write it this way:  

```c
a += 5;
```

This is much more quick and very common and in fact works with every arithmetic
operator.  
  
Here are all common arithmetic operators:  

| Operator with Example | Effect                          | Name        |
|-----------------------|---------------------------------|-------------|
| a + b                 | adds two values                 | addition    |
| a - b                 | subtracts b from a              | subtraction |
| a * b                 | multiplicate two values         | product     |
| a / b                 | divide a by b                   | division    |
| a % b                 | the remainder of a divided by b | modulo      |

It is also common that a variable needs to be reduced or increased by 1.  
This is called decrementing and incrementing respectively and comes with it's
own operators.  
++ for incrementing and  
-- for decrementing.  
Theoretically it is important where this operator is relative to its variable
but in practice this rarely comes up.  

```c
{{ #include ../code/4_increment_basic.c }}
```

Postfix (`a++`) and prefix (`++a`) are both valid and do something slightly
different.  
Every time you do increment "num" you also get the result returned. The
difference is, that the result is returned either before or after incrementing
or decrementing.  

```c
{{ #include ../code/4_increment_return.c }}
```

When the increment operator is on the right side (postfix), then we first
assign the value of "num" to "before" and then increment "num". If the operator
is on the left side (prefix) it's done the other way around.  
So after this, this is how all variables look like:  
num : 2  
before : 0  
after : 2  
  
As mentioned though, this will rarely come up but keep it in mind just in
case.  
  
Now for the next wave of operators, i think it is fitting to move to the next
topic.  
