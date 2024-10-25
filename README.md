# Avoid using this for now. A full Library for NetPBM is coming soon.
# PPM-Writer
This is a C "Library" to easily write Images into Netpbm Files.

It's in Development, and is not particularly active.
I dont promise that it will work flawlessly, nor that i will continue it.

It also assumes that you give it Clean and Correct Inputs, the Checks are needed to be done by you, if you give it Chances that it could go outside of this, thats on you.

With that out of the way:

# What is Implemented?
- P6 (Color up to 255 per Channel), Binary Mode

# What could change with later Updates
- Addition of more Netpbm Formats
- Better Code
- Better Stability
- Better Portability

# What is this Projects Code-Goals
- Ease of use
- Portablility
- Not using external Libraries
- Being Hopefully Fast

# How to build?
You dont need to build this "Library", all you need to do is to include "writer.c" and use its functions accordingly.
An example is provided at "main.c".

Its tested to compile with GCC-13 on ArchLinux.

# Documentation
P6 Binary:
- <a href="doc/writeToPPM.md">writeToPPM Function</a>

# License and Stuff
You can do whatever you want with this Code.
I would appreciate to be given Credit, but its not necessary.
