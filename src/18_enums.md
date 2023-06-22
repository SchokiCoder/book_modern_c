# Enumerators

...allow for a neat organization of names that represent values from the same
type.  
For example, our program may need to handle colors for drawing a certain thing:

```c
{{ #include ../code/18/enum.c }}
```

An enum at it's core is a numerical type. You can assign any constant number to
a member of an enum.  
Let's imagine we have to handle a players interactions in a multiplayer game we
have made:  

```c
{{ #include ../code/18/enum_vals.c }}
```

"There are some gaps in the enum."  
Yes, because we planned only so many different signals so far.  
In case we need to add one or two more "combat signals", we don't need to worry
about shoving all the other signals after that back.  
