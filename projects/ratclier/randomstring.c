Notes on the random tester functions
--------------------------------------------------------------


inputChar()
--------------

In an effort to control the runtime of the tester without sacrificing
randomness, I opted to limit the allowed characters to only those that are
checked by testme(). That set looks like this (add a space to complete the
set):

    resetaxRESETAX[({)]}

These (as well as a space) were placed in a character array. A randomly
generated index is pulled from the array and returned by the function.

Even with this limited set of characters, some tests go into millions of
iterations before the "reset" error string is encountered. On the flip
side, I have gotten "reset" in 150k iterations. It's all over the map.


inputString()
--------------

This one was more difficult to figure out. The main reason it was
difficult was the handling of the random string pointer in testme(). My
original idea was to dynamically create a string in inputString() using
malloc() and then return it to testme(), but that presented one major
issue: where do I free the memory?  I could add free() statements to
testme() but that would corrupt the code (if I change the code that I'm
testing, whose code is being tested?). Instead, I opted to go with a
static char array. That works.

The error string contains 5 characters, so the random string was made 5
characters long plus room for a null terminator. Each of the 5 indices is
generated by receiving and assigning a random character from inputChar(),
then a null terminator is added to the end and the random string is
returned to testme().


testme()
--------------

No edits were made to this function, even though there is a typo (a
missing space) in the fourth if-statement that drives me crazy whenever I
see it.

The procedure loops until an error string is received and exit() is
executed. Each iteration of the loop checks a random character and adjusts
a "state" based on character and current-state criteria (i.e. switch to
state 2 when '(' is the random character and the current state is 1).

Until the state reaches 9 the random string test is useless. When state 9
is reached, the individual random characters are no longer an issue and
the state does not change. From that point onward, random strings are
tested until one is received that contains "reset\0", at which time
testme() exits with code 200. 

