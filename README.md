# push_swap

## push_swap

Push_swap is a sorting algorithm. The aim is to sort a stack A with the help of a second stack B and with the following
operations allowed:

push - takes the first element of a stack and pushes it on the top of the other stack. Does nothing if the first stack is empty.

swap - switch the 2 first elements at the top of the stack. Does nothing if the stack contains one element or is empty.

rotate - shifts all the element of the stack upwards. The first element becomes the last one.

reverse rotate - shifts all the element of the stack downwards. The last element becomes the first one.


## checker
Checker enables to verify that the stack is sorted after operations are done. It takes numbers as arguments and reads the standard input for operations until CTRL + D is pressed. Operations are
pa - push a
pb - push b
ra - rotate a
rb - rotate b
rr - rotate both
rra - reverse rotate a
rrb - reverse rotate b
rrr - reverse rotate both
sa - swap a
sb - swap b
ss - swap both

It displays OK if the stack is sorted and KO otherwise.

Note: the -v flag enables to see both stack after each operation.

## Usage

./push swap "1 5 4 7 8"
./checker "1 5 4 7 8"
sa
pb
rra
pa
KO
