#include <iostream>
#include <string>

using namespace std;

void displayMenu() {    //displayMenu() prints out a menu for the user to choose a decision
    cout << "Example Menu:" << endl;
    cout << "1. List directory contents" << endl;
    cout << "2. Print working directory" << endl;
    cout << "3. Create a new directory" << endl;
    cout << "4. Display a message" << endl;
    cout << "5. Concatenate and display content of a file" << endl;
    cout << "6. Exit" << endl;
}


int main() {
    int choice; //integer variable for user to input to decide what to choose in the menu
    do {    //do while() loop continues the menu and switch case for the user to decide until they exit ("6")
        displayMenu();  //calls displayMenu() function to print out the menu in terminal
        cout << "Enter your choice (1-6): ";    //asks the user to enter a decision from 1-6
        cin >> choice;  //take users input and use it on the next line of code

        switch (choice) {   //a switch case enabled by the user's inputs
            case 1: //each of these cases are enabled by the user's integer input (int choice)
                system("dir");  //we use the system() function "dir". "dir" is a command to help nagivate the system's operating system
                break; //break out of the switch case after the command. This will return to the do while() loop
            case 2: //each of these cases are enabled by the user's integer input (int choice)
                system("cd");   //"cd" is a command that prints the system's working directory
                break;  //break out of the switch case after the command. This will return to the do while() loop
            case 3: //each of these cases are enabled by the user's integer input (int choice)
                system("mkdir new_folder"); //"mkdir" is a command that creates a new directory in your system's files
                break;  //break out of the switch case after the command. This will return to the do while() loop
            case 4: //each of these cases are enabled by the user's integer input (int choice)
                system("echo Hello people");    //"echo" is a command that displays a message to the user. For example, "echo x" prints out x in the terminal
                break;  //break out of the switch case after the command. This will return to the do while() loop
            case 5: //each of these cases are enabled by the user's integer input (int choice)
                system("type Program.txt"); //"type" command pulls a file from your system's files and displays it's contents to the terminal. For example, a text file in your hardrive will have it's words and content printed out to the terminal
                break;  //break out of the switch case after the command. This will return to the do while() loop
            case 6: //each of these cases are enabled by the user's integer input (int choice)
                cout << "Exiting the program." << endl; //displays a message to the terminal stating that the program is exiting
                break;  //break out of the switch case after the command. This will return to the do while() loop
            default: //default is similar to an exception handler. If the user's input is not between 1-6 or is not a number, it will print out the message from this case. It is also like an else() on a if() statement. 
                cout << "Invalid choice. Please enter a number from 1 to 6." << endl; //displays a warning that the user did not print out a correct number
                break;  //break out of the switch case after the command. This will return to the do while() loop
        }
    } while (choice != 6); //if the user does not choose 6, then the loop will continue infinitely. If 6 is chosen, then the do while() will end.

    return 0;
}

