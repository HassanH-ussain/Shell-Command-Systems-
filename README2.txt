Assignment 2

To run the following code, please look over lines 55-57. The arguments have the process number and the number of "tickets" it has (Process id, tickets).

The code runs from two classes: Process and Scheduler.

Process generates the process id and number of tickets from each process given from lines 55-57.

Scheduler actively generates a random number for the lucky process's ticket to match with

I looked up functions I could use from <random> and <vector> libraries and found the following:

random_device from <random> is a source of non-deterministic random numbers

gen from <random> generates the random number 

emplace_back from <vector> adds a new element to the vector as the newest element

uniform_int_distribution from <random> produeces a random value from 1 to chosen value. "dis" is the new rename

The code outputs the winning Process after the random generator matches with the process' ticket id.

PLEASE do not add a ridiculous number for the # of tickets. This can lead to a crash or false output by the program

Thank you,

Hassan Hussain

