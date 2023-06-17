# Structures

...to build an empire that lasts forever.  
Structures help us organizing data that belongs together. This also allows us to
technically receive more from a function via it's return value.  
Though this is not the structures main purpose.  
The following example shows a very simplified simulated messaging app.  

```c
{{ #include ../code/15_messenger.c }}
```

So we define the struct "Message" with three variables in it.  
These variables within are also commonly referred to as "members".  
We then use it with `struct Message`.  
  
That can be tedious.  
Using the keyword `typedef` in the struct's definition, we can eliminate the
need for `struct` everywhere.  
With `typedef` you can basically create an alias for a type.  
We could also create our own type for user-id's.  
Applying those changes, makes our code look like this:  

```c
{{ #include ../code/15_typedef.c }}
```

Wether these changes are good and wanted depends on... opinions, YAY.  
Some people like to keep the `struct` keyword everywhere for the transparency.  
They can read `struct Message` and immediately tell that it's indeed a struct.  
So please, respect the environment you are working in.  
