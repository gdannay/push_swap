# push_swap

Push_swap is a sorting algorithm. The aim is to sort a stack A with the help of a second stack B and with the following
operations allowed:

push - takes the first element of a stack and pushes it on the top of the other stack. Does nothing if the first stack is empty.
swap - switch the 2 first elements at the top of the stack. Does nothing if the stack contains one element or is empty.
rotate - shifts all the element of the stack upwards. The first element becomes the last one.
reverse rotate - shifts all the element of the stack downwards. The last element becomes the first one.

Usage

./push swap "1 5 4 7 8"
