Page Replacement Algorithms Simulation

This program simulates three different page replacement algorithms: Least Recently Used (LRU), Optimal, and First In First Out (FIFO). It takes a page reference string and the number of frames (4) as input and analyzes the performance of each algorithm in terms of the number of page faults.

Follow the on-screen prompts to input the page reference string (separated by commas) and the number of frames is in a constant value of 4 according to the assingment's requirement.

Please do not input negative values or demicals as they will crash the program. Input positive whole numbers.

The program will output each algorithm, displaying the number of page faults at each step of the simulation.

Sample Input:

Page reference string: 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5

Sample Output:

For LRU Algorithm:
• Step 1: Page fault (1) - Page Table: {1}, Frames: [1], Faults: 1
• Step 2: Page fault (2) - Page Table: {1, 2}, Frames: [1, 2], Faults: 2
• Step 3: Page fault (3) - Page Table: {1, 2, 3}, Frames: [1, 2, 3], Faults: 3
• Step 4: Page fault (4) - Page Table: {1, 2, 3, 4}, Frames: [1, 2, 3, 4], Faults: 4
• Step 5: Page hit (1) - Page Table: {2, 3, 4, 1}, Frames: [2, 3, 4, 1], Faults: 4
• Step 6: Page hit (2) - Page Table: {3, 4, 1, 2}, Frames: [3, 4, 1, 2], Faults: 4
• Step 7: Page hit (5) - Page Table: {4, 1, 2, 5}, Frames: [4, 1, 2, 5], Faults: 5
• Step 8: Page hit (1) - Page Table: {4, 2, 5, 1}, Frames: [4, 2, 5, 1], Faults: 5
• Step 9: Page hit (2) - Page Table: {4, 5, 1, 2}, Frames: [4, 5, 1, 2], Faults: 5
• Step 10: Page hit (3) - Page Table: {5, 1, 2, 3}, Frames: [5, 1, 2, 3], Faults: 6
• Step 11: Page hit (4) - Page Table: {1, 2, 3, 4}, Frames: [1, 2, 3, 4], Faults: 7
• Step 12: Page hit (5) - Page Table: {2, 3, 4, 5}, Frames: [2, 3, 4, 5], Faults: 8
• Total Page Faults: 8

For Optimal Algorithm:
• Step 1: Page fault (1) - Page Table: {1}, Frames: [1], Faults: 1
• Step 2: Page fault (2) - Page Table: {1, 2}, Frames: [1, 2], Faults: 2
• Step 3: Page fault (3) - Page Table: {1, 2, 3}, Frames: [1, 2, 3], Faults: 3
• Step 4: Page fault (4) - Page Table: {1, 2, 3, 4}, Frames: [1, 2, 3, 4], Faults: 4
• Step 5: Page hit (1) - Page Table: {1, 2, 3, 4}, Frames: [1, 2, 3, 4], Faults: 4
• Step 6: Page hit (2) - Page Table: {1, 2, 3, 4}, Frames: [1, 2, 3, 4], Faults: 4
• Step 7: Page hit (5) - Page Table: {1, 2, 3, 5}, Frames: [1, 2, 3, 5], Faults: 5
• Step 8: Page hit (1) - Page Table: {1, 2, 3, 5}, Frames: [1, 2, 3, 5], Faults: 5
• Step 9: Page hit (2) - Page Table: {1, 2, 3, 5}, Frames: [1, 2, 3, 5], Faults: 5
• Step 10: Page hit (3) - Page Table: {1, 2, 3, 5}, Frames: [1, 2, 3, 5], Faults: 5
• Step 11: Page hit (4) - Page Table: {4, 2, 3, 5}, Frames: [4, 2, 3, 5], Faults: 6
• Step 12: Page hit (5) - Page Table: {4, 2, 3, 5}, Frames: [4, 2, 3, 5], Faults: 6
• Total Page Faults: 6

For FIFO Algorithm:
• Step 1: Page hit (1) - Page Table: {1}, Frames: [1], Faults: 1
• Step 2: Page hit (2) - Page Table: {1, 2}, Frames: [1, 2], Faults: 2
• Step 3: Page hit (3) - Page Table: {1, 2, 3}, Frames: [1, 2, 3], Faults: 3
• Step 4: Page hit (4) - Page Table: {1, 2, 3, 4}, Frames: [1, 2, 3, 4], Faults: 4
• Step 4: Page hit (1) - Page Table: {1, 2, 3, 4}, Frames: [1, 2, 3, 4], Faults: 4
• Step 4: Page hit (2) - Page Table: {1, 2, 3, 4}, Frames: [1, 2, 3, 4], Faults: 4
• Step 5: Page hit (5) - Page Table: {2, 3, 4, 5}, Frames: [2, 3, 4, 5], Faults: 5
• Step 6: Page hit (1) - Page Table: {3, 4, 5, 1}, Frames: [3, 4, 5, 1], Faults: 6
• Step 7: Page hit (2) - Page Table: {4, 5, 1, 2}, Frames: [4, 5, 1, 2], Faults: 7
• Step 8: Page hit (3) - Page Table: {5, 1, 2, 3}, Frames: [5, 1, 2, 3], Faults: 8
• Step 9: Page hit (4) - Page Table: {1, 2, 3, 4}, Frames: [1, 2, 3, 4], Faults: 9
• Step 10: Page hit (5) - Page Table: {2, 3, 4, 5}, Frames: [2, 3, 4, 5], Faults: 10
• Total Page Faults: 10