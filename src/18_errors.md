# Errors are friends, not food

The compiler will provide you with mostly helpful information. The more the
compiler tells you what is wrong, the better. If you disagree with me on that,
talk to a Rustacean (Rust programmer). The Rust programming language has a very
good compiler that will provide the user with not just tons of errors but
warnings alike. Enabling you to catch a lot of unexpected runtime behavior.
If you still not agree with me and the Rustaceans, then feel free to try vanilla
Python with a basic text editor. The Python parser will basically accept
anything that it can process. It never gives you any warnings letting your
program run into all kinds of runtime issues.  
  
If you do agree, then activate the compilers options to print more warnings.  
  
In `gcc` and `clang` these options are `-Wall -Wextra`.
  
By the way the difference between an error and a warning is:  

- error = the source code cannot be compiled into a working binary filename
- warning = the code can be compiled but unintended behavior might arise at
  runtime
