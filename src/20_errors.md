# Errors are friends, not food

The compiler will provide you with mostly helpful information. The more the
compiler tells you what is wrong, the better. If you disagree with me on that,
talk to a Rustacean (a Rust programmer).  
The Rust programming language and its compiler are designed to make you feel
less confident in yourself.  
Providing you with tons of errors and warnings, as soon as even the smallest
thing is out of place.  
This enables you to catch a lot of unexpected runtime behavior.  
  
So... errors good.  
If you don't agree with me and the Rustaceans, then feel free to try vanilla
Python with just a basic text editor and **no linter**.  
The Python interpreter will basically accept anything that it can process. It
never gives you any warnings, letting your program run into all kinds of runtime
issues.  
  
If you do agree, then activate the compiler's options to print more warnings.  
  
In `gcc` and `clang` these options are `-Wall -Wextra`.  
  
By the way the difference between an error and a warning is:  

- error = the source code cannot be compiled into a working binary file
- warning = the code can be compiled, but unintended behavior might arise at
  runtime

You can even go a step further and promote all warnings to be errors with
`-Werror`.  
