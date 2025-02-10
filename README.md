# Portland State University (PSU) Project Portfolio

## Various Projects
Within each folder is a specific project I had to do for a PSU course I took in my senior year of high school. The majority of these
projects have to do with data structures and learning to work with C++. This README will choose to focus on specific projects, notably the ones
that took longer to make.

## Running/Application:
All projects were created using the terminal, specifically through a linux emulator (Emacs). For most data structure projects (though not all), there is an 
included text file that can be pre-loaded into the structure.


## Notable Projects:

### Red-Black Tree:

A data sorting algorithm that uses a tree of nodes that are either red or black. The algorithm itself consists of a series of cases that can involve specific "rotations" of nodes to balance the tree. This project took me the longest to complete, but is also the one I'm most proud of. If you have time, try opening the project and loading the text file into the tree; it looks super cool.

### Graph Creator:

Created an adjacency matrix (20 x 20 maximum) that connected different "nodes" together by a certain weight. Allowed users to add and deleted both nodes and edges (connector line) as they saw fit. Additionally, the program taught me how to implement Dijkstra's Algorithm to find the shortest path between given two nodes.

### Hash
Creates my own rendition of a hash table, using linked lists to deal with collisions. Specifically designed for taking in student objects and storing them, emphasizing retrieval time above all else. Able to return with O(1) time complexity at best or w/ collisions O(n), where n is the number of nodes in the linked list. Though I implemented a list, rehashing would create a new list that was double the size of the previous, resorting the previous data values accordingly and asserting that the hashmap was never "full". 

### Dungeon Crawler:
Not as advanced as the other projects, but deserves an honorable mention. Based off of the text-based adventureg game Zork, the project produces a rudimentary dungeon for the user to explore, picking up items before eventually reaching the end.

## Miscellaneous:
Note that some projects were just for practice with C++, such as Tic-Tac-Toe, ljHeap, and practiceFiles. Others are very common projects that I didn't think were worth mentioning (Binary Search Tree, Shunting Yard Algorithm).
