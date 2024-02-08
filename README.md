# Homework 1: Shell-Command-Systems-

When running hw1.cpp, please choose a number between (1-6). No letters or special letters!

I ran the source code by installing MINGW and GCC. The guide I used is online and in the official Visual Studio Code website. However, the code should run whichever way works.

hw1.cpp runs a menu of which the user must decide on 5 options. Each of these options utilize shell commands by using the system() function. This code presents new shell commands to learn from

There are 5 commands used in this source file:

"dir" is a command to help nagivate the system's operating system

"cd" is a command that prints the system's working directory

"mkdir" is a command that creates a new directory in your system's files. 
Side note: I used rmdir to test out its function and see how it deletes a folder. "rmdir" is a command that deletes an existing folder located in the operating system's local folders

"echo" is a command that displays a message to the user. For example, "echo x" prints out x in the terminal

"type" command pulls a file from your system's files and displays it's contents to the terminal.

When deciding to end the loop, choose input 6 to close the loop.

It is important to create exceptions on each case (1-6), because the user may input an incorrect value and have a random output. The exception handle will clarify an error happened.
