# Setup

First you want to make sure to install Linux… no?  
Look mate, you don't have to commit to it in a way of permanently replacing your
current OS.  
You can use VirtualBox, or WSL if you are on MS Windows, which would also take
care of the next step of choosing a distro.  
  
If you go out and look for the Linux install software, I gotta tell you that's
not how it works. There is not just the one Linux install-disk or
something like that. Rather, there are hundreds,
which is what we call distributions or distros,
but don't fret over which one to pick,
because I recommend you just use Linux Mint.
It is good for beginners, definitively enough for the purposes of this book,
and it's DEBIAN-BASED:  
<https://linuxmint.com/download.php>  

Ubuntu could also be used:  
<https://ubuntu.com/desktop>  
  
Still not? Alright okay. If you are interested in programming, I can only
recommend it though.  
Keep in mind, this book is written mainly for Linux and the "gcc" compiler.  
So the setup phase can be difficult, and the reading experience can be
hampered, if you diverge.  
Seriously, at least use a virtual machine.  

## Compiler

What you need at the very least is a compiler.  

### Linux

On Linux that would be gcc for example, available via your package manager. In
most cases it should already be installed. Try `gcc` in terminal, if the
output is something like:  
`gcc: fatal error: no input files`  
then you have it. If not try the following commands (depending on your operating
system):  

| operating system         | command                |
|--------------------------|------------------------|
| Debian and Debian-based  | `sudo apt install gcc` |
| Arch and Arch-based:     | `sudo pacman -S gcc`   |
| Fedora and Fedora-based: | `sudo dnf install gcc` |

### Windows

On Windows, I recommend you to get "Cygwin".  
It will provide a Linux like environment, for you to use:  
<https://www.cygwin.com>  
It will also come with the needed compiler or give you the option to patch it
into later.  
  
If not, at least get the compiler "mingw":  
- <https://www.mingw-w64.org>
- <https://nuwen.net/mingw.html>
- <https://www.msys2.org>

## Editor

A **good** editor is the next thing on the list.  

### Linux

Linux Mint comes with a very basic editor already.
Just look for "Text Editor" in the application menu.
You may also find it as "xed", "mousepad" or "pluma",
depending on the chosen edition.  
They all come with "syntax highlighting". Make sure it is enabled.
Other helpful visual aids such as "Highlight matching brackets",
"Highlight the current line", "Display line numbers",
and many more should be kept in mind.  
If you don't have any editor with syntax highlighting,
install one of the aforementioned ones via your package manager, or find one on
your own.  

### Windows

On Windows, ditch notepad.exe and get "Notepad++" or "Visual Studio Code", i
guess. I would go with Notepad++ though, if I were glued to a Windows-only PC.  

## Debugger

### Linux

Use "gdb". If you have "gcc" installed out of the box, chances are "gdb" is
already in your party. If not, you know the package-manager-drill.  

### Windows

There is a good chance "gdb" comes packed with "mingw" / "Cygwin" already. If
that is not the case, then get it from the internet. Since you are a grown
adult that committed to a path, you can also do the heavy lifting.  

## Make

Not to be confused with cmake, that is something else.  

### Linux

Get "make" via package manager, if not already there.  

### Windows

Get "make" via the "Cygwin" packages, if not already there. If you don't use
"Cygwin", then go find it on the internet.  
