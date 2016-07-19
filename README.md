This is a backport of the current C++11 standard library to C++03/11/14. Obviously not everything
can be backported, but quite a bit can.

Quick Start
===========

There are a couple of small examples to give you an idea of usage. If you have make and g++
you can build things quickly enough:
 - clone the repo to /some/place/cppbackport
 - make a temp dir /wherever/you/wanna/build
 - cd /wherever/you/wanna/build
 - make -f /some/place/cppbackport/examples/Makefile

The examples are all setup to compile the cppbackport files as a static library (libcppbackport.a),
and then link it with one of the main example files (ex., gibberish.cpp).

Installation
============

I recommend copying the lib directory into your project, and calling the included Makefile
to create libcppbackport.a. Link that into your project, and add the appropriate include
flags (ex., -iquotecppbackport).

Usage
=====

Basically, #include "filesystem.h" or similar. Then use cpp namespace in place of std namespace.
The headers are all named after their official counterparts, with the addition of the .h
extension.

FAQ
===
Q: Will this use C++11/14/17 if available?

A: Yes. Based on the value of the __cplusplus define, the files will simply #include the
system header (as appropriate).

Q: Why not header-only?

A: I actually like the interface/implementation distinction. Header-only implementations (IMO)
get way too large and the files are difficult to navigate. Also, save the compiler some work.
Also, installing a lib isn't really that hard.

Q: Does it work on Windows?

A: Sorry, POSIX mostly. Would love for some Windows devs to help.

Q: Why not use Boost?

A: There's some overlap, but there are differences, too. And none of these things, *individually*
are that big. 
