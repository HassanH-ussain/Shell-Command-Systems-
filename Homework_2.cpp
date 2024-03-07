//Name: Hassan Hussain
//WSU ID: N472N982
//Assignment 2: Creating a process lottery by designing classes that create processes and manage the loterry scheduling algorithm. The algorithm determines the process winner based on a random number geenrated by the random library
#include <iostream> //input & outputs to program
#include <vector> //vector library to provide a dynamic-array structure
#include <random> //library to generate random numbers

using namespace std; //replace std::

class Process { //Process class 
public:
    int id;
    int tickets; //id and tickets are public members of class Process

    Process(int _id, int _tickets) : id(_id), tickets(_tickets) {} //constructors that initialize the members
};

class Scheduler { //Scheduler class
private:
    vector<Process> processes; //a vector array that holds the processes
    random_device rd; //rd, random device is a source of non-deterministic random numbers
    mt19937 gen; //this is essentially the random number generator which is part of the <random> library

public:
    Scheduler() : gen(rd()) {} //Constructor of process Scheduler and initializes the random number  "gen" obtained by a seed from "rd"

    void addProcess(int id, int tickets) { //the void functions take tickets and id from Process class as arguments
        processes.emplace_back(id, tickets); //from CPlusPlus.com, emplace_back inserts a new element to the end of the vector, right after the current last element. Reference: https://cplusplus.com/reference/vector/vector/emplace_back/ 
    }

    Process selectWinner() { //SelectWinner is a public member function of Scheduler class and returns a Process object. The function determines the winner of the three processes and generates a random number of which the ticket from one of the processes are labeled as
        int totalTickets = 0; //total tickets
        for (const Process& process : processes) { 
            totalTickets += process.tickets; //counts total tickets of all acumulated processes
        }

        uniform_int_distribution<> dis(1, totalTickets); //From the <random> library, "dis" generates integers uniformly distributed from 1 to the total number of tickets accumulated
        int winningTicket = dis(gen); //the winning ticket is determined and picked by the random number generated from "gen"

        int cumulativeTickets = 0; //This integers will store the sum of all tickets from all processes
        for (const Process& process : processes) {
            cumulativeTickets += process.tickets;
            if (winningTicket <= cumulativeTickets) { //if the winning ticket is less than or equal to the total cumulative tickets, then current process has enough tickets to win the lottery
                return process; //return the process that won the lottery!
            }
        }
        return processes.front(); //End the function
    }
};

int main() {
    Scheduler scheduler;

    // Example processes with tickets
    scheduler.addProcess(1, 8); //process 1 has 8 total tickets (highest chance to win)
    scheduler.addProcess(2, 1); //process 2 has 3 total tickets 
    scheduler.addProcess(3, 1); //process 3 has 1 ticket 

    // Print the winner of the lottery
    Process winner = scheduler.selectWinner();
    cout << "Process " << winner.id << " wins the lottery!" << endl;

    return 0;
}
