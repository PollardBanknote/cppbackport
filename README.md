This is a backport of the current C++11 standard library to C++03/11/14.

Some random details thatI need to elaborate on:
 - Obviously not everything can be backported, but quite a bit can
 - headers are named after official headers (ex., #include "filesystem.h")
 - types and functions are available via the cpp namespace (ex., cpp::create_directory("/home/jlee975/derp"))
 - will #include the standard header if it's available
 - mostly POSIX, no real Windows support yet
 - not header only because reasons
