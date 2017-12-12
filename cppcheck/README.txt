hey man just wanted to send you some stuff about cppcheck and i think i figured out how to install it on linux. I thought that might be helpful for our final tomorrow if you hadn't already figured it out.

Anyway here is the commands to install it but first download the source code file and extract and go into the cppcheck-1.81 directory and run these commands:

1) make SRCDIR=build CFGDIR=/usr/share/cppcheck/

2)sudo make install CFGDIR=/usr/share/cppcheck/


then to use it:

cppcheck --enable=all yourprogram.cpp


here is the link to the source code

http://cppcheck.sourceforge.net/



