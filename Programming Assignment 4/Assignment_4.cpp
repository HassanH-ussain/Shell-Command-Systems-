//Assignment 4 (Operating Systems)
//Name: Hassan Hussain
//WSU ID: N472N982

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;



// Function to get the page reference string from the user
vector<int> getPageReferenceString() {
    cout << "Enter the page reference string (separated by commas, press Enter when done): ";
    string input;
    getline(cin, input);

    vector<int> referenceString;
    stringstream ss(input);
    int num;
    while (ss >> num) {
        referenceString.push_back(num);
        if (ss.peek() == ',')
            ss.ignore();
    }
    return referenceString;
}

// LRU Algorithm
void lruAlgorithm(const vector<int> &referenceString, int numFrames) {
    vector<int> frames; //creating a vector array for integers values
    int faults = 0; //defining faults
    int hits = 0; //defining hits

    for (int ref_page : referenceString) { //iterates through the reference page string given from the user
        auto it = find(frames.begin(), frames.end(), ref_page); //search for page in memory 

        if (it != frames.end()) { //if page is not found in memory, move it from its current position to last 
            frames.erase(it);
            frames.push_back(ref_page);
            hits++; //increment hit counter
        } else {
            faults++; //increment fault counter
            if (frames.size() < numFrames) { //if there is space in the memory, add the new page to the memory
                frames.push_back(ref_page);
            } else {
                frames.erase(frames.begin()); //if the memory is full, remove the first element and add the new page to the memory
                frames.push_back(ref_page);
            }
        }

        cout << "• Step " << (faults + hits) << ": "; //printing out the step number, page hit, fault count, total page faults, and prints page table as well as its contents currently in it iteratively
        if (hits > 0)
            cout << "Page hit (" << ref_page << ")";
        else
            cout << "Page fault (" << ref_page << ")";
        cout << " - Page Table: {";
        for (int i = 0; i < frames.size(); ++i) {
            cout << frames[i];
            if (i < frames.size() - 1)
                cout << ", ";
        }
        cout << "}, Frames: [";
        for (int i = 0; i < frames.size(); ++i) {
            cout << frames[i];
            if (i < frames.size() - 1)
                cout << ", ";
        }
        cout << "], Faults: " << faults << endl;
    }

    cout << "• Total Page Faults: " << faults << endl;
}

// Optimal Algorithm
void optimalAlgorithm(const vector<int> &referenceString, int numFrames) {
    vector<int> frames; //Vector to store the pages in memory
    int faults = 0; //Define faults
    int hits = 0; //Define hits

    for (int i = 0; i < referenceString.size(); ++i) {  //Iterate through the page reference string
        auto it = find(frames.begin(), frames.end(), referenceString[i]); //Search the page in the memory 

        if (it != frames.end()) { //If the page is found in the memory, then increment the page hit counter
            hits++;
        } else {
            faults++; //If the page is not found in the memory, increment the page fault counter
            if (frames.size() < numFrames) { //If there is space in the memory, add the page to the memory
                frames.push_back(referenceString[i]);
            } else { //However, if the page is full 
                int farthestIndex = -1, farthestPage = -1; 
                for (int j = 0; j < frames.size(); ++j) { //Find the page that will be used farthest in the future
                    int nextOccurrence = -1;
                    for (int k = i + 1; k < referenceString.size(); ++k) { //Continue iterating through the rest of the page reference string and if the page is found in the future, store its index
                        if (frames[j] == referenceString[k]) {
                            nextOccurrence = k;
                            break; //stop searching
                        }
                    }
                    if (nextOccurrence == -1) { //If the page is not found in the future, the page will be replaced
                        farthestIndex = j;
                        break;
                    } else {
                        if (nextOccurrence > farthestPage) { //If this is used farthest in the future, update the farthest page index
                            farthestPage = nextOccurrence;
                            farthestIndex = j;
                        }
                    }
                }
                frames[farthestIndex] = referenceString[i]; //Replace the farthest page with the new page
            }
        }

        cout << "• Step " << (faults + hits) << ": "; //printing out the step number, page hit, fault count, total page faults, and prints page table as well as its contents currently in it iteratively
        if (hits > 0)
            cout << "Page hit (" << referenceString[i] << ")";
        else
            cout << "Page fault (" << referenceString[i] << ")";
        cout << " - Page Table: {";
        for (int j = 0; j < frames.size(); ++j) {
            cout << frames[j];
            if (j < frames.size() - 1)
                cout << ", ";
        }
        cout << "}, Frames: [";
        for (int j = 0; j < frames.size(); ++j) {
            cout << frames[j];
            if (j < frames.size() - 1)
                cout << ", ";
        }
        cout << "], Faults: " << faults << endl;
    }

    cout << "• Total Page Faults: " << faults << endl;
}

// FIFO Algorithm
void fifoAlgorithm(const vector<int> &referenceString, int numFrames) {
    queue<int> fifoQueue; //Queue to store the pages in memory
    unordered_set<int> pageSet; //Set to store unique pages in memory
    int faults = 0; //Define faults counter

    for (int ref_page : referenceString) { //Iterate through the reference string
        if (pageSet.find(ref_page) != pageSet.end()) { //If the page is found in the memory then page hit

        } else { //If the page is not found in the memory, increment the fault coutner
            faults++;
            if (fifoQueue.size() == numFrames) { //If the memory is full then get the page in the front of the queue and remove the oldest page from the set and queue
                int front = fifoQueue.front();
                fifoQueue.pop();
                pageSet.erase(front);
            }
            fifoQueue.push(ref_page); //Add the new page to the memory 
            pageSet.insert(ref_page); //Add the new page to the set
        }

        cout << "• Step " << faults << ": "; //Printing out the step number, page hit, fault count, total page faults, and prints page table as well as its contents currently in it iteratively
        if (pageSet.find(ref_page) != pageSet.end())
            cout << "Page hit (" << ref_page << ")";
        else
            cout << "Page fault (" << ref_page << ")";
        cout << " - Page Table: {";
        queue<int> temp = fifoQueue;
        while (!temp.empty()) {
            cout << temp.front();
            temp.pop();
            if (!temp.empty())
                cout << ", ";
        }
        cout << "}, Frames: [";
        temp = fifoQueue;
        while (!temp.empty()) {
            cout << temp.front();
            temp.pop();
            if (!temp.empty())
                cout << ", ";
        }
        cout << "], Faults: " << faults << endl;
    }

    cout << "• Total Page Faults: " << faults << endl;
}

int main() {
    vector<int> referenceString = getPageReferenceString(); //Call function that takes the input of the user's page reference string
    int numFrames = 4; //Set the constant number of frames as four 

    cout << endl;
    cout << "For LRU Algorithm:" << endl; //Print out the LRU algorithm's page fault, page table, page hit, and total page faults
    lruAlgorithm(referenceString, numFrames);
    cout << endl;

    cout << "For Optimal Algorithm:" << endl; //Print out the Optimal algorithm's page fault, page table, page hit, and total page faults
    optimalAlgorithm(referenceString, numFrames);
    cout << endl;

    cout << "For FIFO Algorithm:" << endl; //Print out the FIFO algorithm's page fault, page table, page hit, and total page faults
    fifoAlgorithm(referenceString, numFrames);

    return 0;
}
