# Algorithms

## Tasks:

<details><summary>Block 1: Introduction to Algorithms</summary>
  
<details><summary>Task A: Amateur agronomist</summary>
  
#### Description:
  
The city schoolboy Lyosha went to the village for the summer and started growing flowers. He planted n flowers along one long straight garden bed and they grew successfully. Lyosha planted many different types of flowers, the i-th flower from the beginning of the garden has the form ai, where ai "is an integer, the number of the corresponding species in the "Catalogue of a young agronomist".

Now Lyosha wants to take a photo of the flowers he has grown and post it in the "my garden beds" section of the VKompost social network for agronomists. The photo will show a segment of one or more flowers planted in a row.

However, he noticed that the photo does not look very interesting if it has a lot of the same flowers in a row. Lyosha decided that if three flowers of the same species planted in a row are visible in the photo, then his friends - experts in the aesthetics of flower photographs - will give few likes.

Help him choose the longest section of his garden for photography, which does not have three flowers of the same kind in a row.

#### Input:

The first line contains an integer n (1 ≤ n ≤ 200000) — the number of flowers in the garden.

The second line contains n integers ai (1 ≤ ai ≤ 10^9) denoting the type of the next flower. Identical flowers are indicated by the same numbers, different - by different numbers.

#### Output:

Print the number of the first and last flower on the longest section you are looking for. Flowers are numbered from 1 to n.

If there are several longest segments, print the segment that starts earlier.

</details>

<details><summary>Task B: Gleb's Zoo</summary>
  
#### Description:

Gleb recently opened a zoo. He decided to build it in the shape of a circle and, of course, surrounded it with a fence. Gleb took you there as head of security. It would seem that everything started so well, but it was on your first shift that all the animals fled. There are n animals of different species in the zoo, and each species has its own traps.

Unfortunately, some animals are at enmity with each other in nature (they are designated by different letters), and the zoo is surrounded by a fence and has the shape of a circle. With the help of cameras, it was possible to find out where all the animals are. The zoo's smart life support system has already scanned the zoo and outputs the id of all animals and traps in the order they are seen from the center of the zoo. It so happened that all the animals and all the traps are on the edge of the zoo. You want to see if the animals can get into their trap without crossing paths with others. If yes, also show any of the schemes for capturing animals.

#### Input:

The input is a string of 2n Latin characters, where the small letter is an animal, and the large letter is a trap. The string size is no more than 100000.

#### Output:

It is required to print "Impossible" if there is no solution, or "Possible" if it is possible to return all animals to the cages. If it is possible, then for each trap, in the order of traversal, it is required to print the index of the animal in it.

</details>

<details><summary>Task C: Configuration file</summary>
  
#### Description:

Vadim is developing a configuration file parser for his project. The file consists of blocks, which are distinguished using the characters "{" - the beginning of the block, and "}" - the end of the block. Blocks can be nested within each other. One block can contain several other blocks.

There are variables in the configuration file. Each variable has a name that consists of no more than ten lowercase Latin letters. Variables can be assigned numeric values. Initially, all variables have a value of 0.

Assigning a new value is written as 'variable'='number', where 'variable' is the name of the variable, and 'number' is an integer whose module does not exceed 10^9. The parser reads the configuration file line by line. As soon as it encounters an assignment expression, it assigns a new value to the variable. This value is retained until the end of the current block, and then the old value of the variable is restored. If other blocks are nested in the block, then inside those blocks that come after the assignment, the value of the variable will also be new.

In addition, in the configuration file, you can assign the value of another variable to a variable. This action is written as 'variable1'='variable2'. After reading such a line, the parser assigns the current value of variable2 to variable1. As with a constant value assignment, the new value is retained only until the end of the current block. After the end of the block, the variable returns the value that was before the start of the block.

For debugging, Vadim wants to print the assigned value for each line of the form 'variable1'='variable2'. Help him debug the parser.
  
#### Input:

The input contains at least one and no more than 10^5 lines. Each line has one of four types:

1. { - the beginning of the block;
2. } — end of the block;
3. variable=number - assigning a value to a variable given by a number;
4. variable1=variable2 - Assigning one variable the value of another variable. Variables 'variable1' and 'variable2' can be the same.

It is guaranteed that the input is correct and matches the description from the condition. The input does not contain spaces.

#### Output:

For each line of type 'variable1'='variable2' print the value that was assigned.

</details>

<details><summary>Task D: Professor Chaos</summary>
  
#### Description:

In the secret laboratory of Professor Chaos, an experiment is underway to grow especially dangerous bacteria. At the beginning of the first day of the experiment, Chaos has a particularly dangerous bacteria.

Each day of the experiment is arranged as follows. Early in the morning, the professor takes all his bacteria out of the container and places them in an incubator, where the bacteria begin to divide. Instead of each bacterium, b new bacteria are formed.

After removing the bacteria from the incubator, c of them are used for various experiments and then destroyed. If there are less than c bacteria after removal from the incubator, all available bacteria are used for the experiments and the experiment ends.

The remaining bacteria at the end of the day must be placed in a container and continue to be used in the experiment. However, no more than d bacteria can be placed in the container, so if the number of remaining bacteria is greater than d, then d bacteria are placed in the container, and the rest are destroyed.

Now Professor Chaos wants to find out how many especially dangerous bacteria he will have in the container after the k-th day of the experiment. Help him find the answer to this question.
  
#### Input:

The single line of the input file contains five integers a, b, c, d and k (1 ≤ a, b ≤ 1000, 0 ≤ c ≤ 1000, 1 ≤ d ≤ 1000, a ≤ d, 1 ≤ k ≤ 10^18).
  
#### Output:

Print a single number — the number of bacteria Chaos has by the end of the k-th day. If the experiment ends on the k-th day or earlier, print the number 0.
  
</details>
</details>

<details><summary>Block 2: Data structures</summary>
  
<details><summary>Task E: Cows in a stall</summary>
  
#### Description:
  
Stalls are located on the straight line, in which it is necessary to place the cows so that the minimum distance between the cows is as large as possible.
  
#### Input:
  
The first line contains the numbers N (2 < N ≤ 10^5) - the number of stalls and K (1 < K < N) - the number of cows. The second line contains N natural numbers in ascending order - the coordinates of the stalls (the coordinates do not exceed 10^9).

#### Output:
                                                                                             
Print a single number, the largest possible allowed distance.

</details>

<details><summary>Task F: Number</summary>

#### Description:  

Vasya wrote a large number on a long strip of paper and decided to show off this achievement to his older brother Petya. But as soon as he left the room to call his brother, his sister Katya ran into the room and cut a strip of paper into several pieces. As a result, each part contained one or more successive numbers.

Now Vasya cannot remember exactly what number he wrote. Just remember that it was very big. To console his younger brother, Petya decided to find out what the maximum number could be written on a strip of paper before cutting. Help him!
  
#### Input:
  
The input file contains one or more lines, each containing a sequence of digits. The number of lines in the input file does not exceed 100, each line contains from 1 to 100 digits. It is guaranteed that the first digit in at least one line is different from zero.

#### Output:
  
Output one line to the output file — the maximum number that could be written on the strip before cutting.
  
</details>

<details><summary>Task G: Nightmare in the castle</summary>
  
#### Description:
  
There are legends that while Aurora was sleeping, she dreamed that she was walking in different places: forests, fields, cities and villages. And then one day she stumbled upon a cave in which a sage was sitting. When the sage raised his eyes to Aurora, he said: “Dear Aurora! You have been wandering these lands for years. I want to offer you a challenge. Here's the string s. Each letter from the alphabet has its own weight ci. The weight of the string that you can get from s by repeatedly exchanging any two letters is calculated as follows: for each letter of the alphabet, calculate the maximum distance between the positions in which this letter stands and multiply it with the weight of this letter. Bring me a string of the maximum possible weight, and I will tell you what the meaning of life is.

Fortunately, when Aurora was already walking with a line to the sage, Philip kissed her, and Aurora came out of this nightmare. Now you are invited to plunge into this nightmare yourself and solve the problem.

#### Input:
  
Given a string consisting of lowercase Latin letters (1 ≤ |s| ≤ 10^5). The next input line contains 26 numbers — the weights of the letters of the Latin alphabet from "a" to "z", the weights are non-negative and do not exceed 2^31 - 1.

#### Output:
  
Output the string s, in which the letters are rearranged so that the resulting weight is the maximum possible. If there are several search options, output any of them.

</details>

<details><summary>Task H: Shop</summary>
  
### Description:

Bill has a large family: three sons, nine grandchildren. And everyone needs to be fed. So Bill goes to the store once a week.

One day, Bill came to the store and saw that the store was running a promotion called "every k-th item is free." Having studied the rules of the action, Bill found out the following. Having broken through the goods at the checkout, the buyer receives a check. Let there be n goods in the check, then n/k rounded down the cheapest of them are given free of charge.

For example, if there are five goods in the check for 200, 100, 1000, 400 and 100 rubles, respectively, and k = 2, then both goods are free of charge for 100 rubles, the buyer must pay 1600 rubles in total.

Bill had already selected the items and was heading to the checkout when he realized that the items he wanted to buy could be broken up into multiple receipts and thus spend less money.

Help Bill figure out what the minimum amount he will be able to pay for the selected items may be by splitting them into multiple receipts.
  
#### Input:
  
The first line of the input file contains two integers n, k (1 ≤ n ≤ 100000, 2 ≤ k ≤ 100) — the number of items that Bill wants to buy and the promotion parameter "every kth item is free".

The next line contains n integers ai (1 ≤ ai ≤ 10000) — the prices of the goods that Bill buys.

#### Output:
  
Minimum amount.

</details>
</details>

<details><summary>Block 3: Sorting</summary>
  
<details><summary>Task I: Cars</summary>
  
#### Description:
  
Petya, who is three years old, loves to play with cars. In total, Petya has N different cars, which are stored on the cabinet shelf so high that he himself cannot reach them. At the same time, no more than K cars can be on the floor of the room. Petya plays with one of the cars on the floor, and if he wants to play with another car, which is also on the floor, he reaches for it himself. If the machine is on the shelf, then he turns to his mother for help. Mom can get a typewriter for Petya from the shelf and at the same time put any typewriter from the floor on the shelf. Mom knows her child very well and can predict the sequence in which Petya wants to play with cars. At the same time, in order not to interfere with Petya's game, she wants to perform as few operations as possible to lift the car from the floor, each time choosing the right car that should be put on the shelf. Your task is to determine the minimum number of operations. Before Petya starts playing, all the cars are on the shelf.
  
#### Input:
  
The first line contains three numbers N, K and P (1≤ K, N ≤ 100000, 1≤ P ≤ 500000). The next P lines contain the numbers of cars in the order that Petya wants to play with them.
  
#### Output:
  
Print a single number: the minimum number of operations Petya's mother needs to perform.
      
</details>

<details><summary>Task J: Goblins and queues</summary>

#### Description:
  
Goblins of the Misty Mountains are very fond of going to their shamans. Since there are a lot of goblins, very long lines often form at the shamans. And since many goblins in one place quickly form a noisy crowd that prevents the shamans from performing complex medical manipulations, the latter decided to establish some rules regarding the order in the queue.

Ordinary goblins when visiting shamans must stand at the end of the queue. Privileged goblins, who know a special password, stand exactly in its middle, and with an odd queue length, they stand immediately behind the center.

Since goblins are also notoriously disrespectful of rules and regulations, the shamans have asked you to write a program that keeps track of the goblins' order in line.

#### Input:
  
The first line of the input contains the number N (1 ≤ N ≤ 105) the number of requests. The next N lines contain the description of requests in the format:

1. + i Goblin with number i (1 ≤ i ≤ N) goes to the end of the queue.
2. * i privileged goblin number i stands in the middle of the queue.
3. - the first goblin from the queue goes to the shamans. It is guaranteed that the queue is not empty at the time of such a request.
  
#### Output:
  
For each query like - the program should display the number of the goblin who should visit the shamans.
 
</details>

<details><summary>Task K: Memory manager-1</summary>
  
#### Description:
  
Petya was assigned to write a memory manager for the new phi++ language standard library. The manager has an array of N consecutive memory cells, numbered from 1 to N. The manager's task is to process requests from applications to allocate and free memory. A request for memory allocation has one parameter K. Such a request means that the application asks for K consecutive memory cells to be allocated to it. If the manager has at least one free block out of K consecutive cells, then he must allocate such a block in response to a request. In this case, immediately before the very first memory cell of the allocated block, there should not be a free memory cell. After that, the allocated cells become occupied and cannot be used for memory allocation until they are freed. If there is no block of K consecutive free cells, then the request is rejected. A request to free memory has one parameter T. Such a request means that the manager must free the memory allocated earlier when processing a request with a sequence number T. Requests are numbered starting from one. It is guaranteed that the request with number T is an allocation request and has not yet been deallocated. The freed cells can again be used to allocate memory. If the request with number T was rejected, then the current request to free the memory is ignored. It is required to write a memory manager that satisfies the above criteria.

#### Input:
  
The first line of the input file contains numbers N and M – the number of memory cells and the number of queries, respectively (1 ≤ N ≤ 2^31 - 1; 1 ≤ M ≤ 10^5). Each of the following M lines contains one number: (i+1)-th line of the input file (1 ≤ i ≤ M) contains either a positive integer K, if the i-th request is a selection request with parameter K (1 ≤ K ≤ N), or a negative number -T, if the i-th request is a release request with the parameter T (1 ≤ T < i).
  
#### Output:

For each memory allocation request, output the result of processing this request to the output file: for successful requests, print the number of the first memory cell in the allocated block; for rejected requests, print the number -1. The results must be output in the order of the requests in the input file.
  
</details>

<details><summary>Task L: Minimum on the segment</summary>
  
### Description:
  
Consider a sequence of integers of length N. A “window” of length K moves along it with a step of 1, that is, first, the first K numbers are visible in the “window”, at the next step, there will already be K numbers in the “window”, starting from the second, and so continue to the end of the sequence. It is required for each position of the "window" to determine the minimum in it.

#### Input:
  
The first line of the input contains two integers N and K (1 ≤ N ≤ 150000, 1 ≤ K ≤ 10000, K ≤ N) – the lengths of the sequence and the "window", respectively. The next line contains N numbers - the sequence itself. The numbers in the sequence do not exceed 105 in absolute value.

#### Output:
  
The output should contain N - K + 1 lines - the minimum for each position of the "window".

</details>
</details>

<details><summary>Block 4: Graph</summary>
  
<details><summary>Task M: Civilization</summary>
  
#### Description:
  
The world map in the computer game "Civilization" version 1 is a rectangle divided into squares. Each square can have one of several possible reliefs, for simplicity we will limit ourselves to three types of reliefs - field, forest and water. The settler moves around the map, while moving to a cell occupied by a field takes one unit of time, moving to a forest takes two units of time, and moving to a cell with water is impossible.

You have one settler, you have determined the place where you need to build a city in order to take over the whole world as soon as possible. Find the route of the settler, which leads him to the place of construction of the city, requiring a minimum of time. On each move, a migrant can move to a cell that has a common side with the cell where he is currently located.
  
#### Input:
  
The input file contains two natural numbers N and M, not exceeding 1000 — the dimensions of the world map (N is the number of rows in the map, M is the number of columns). Then the coordinates of the initial position of the settler x and y are given, where x is the row number, y is the column number on the map (1 ≤ x ≤ N, 1 ≤ y ≤ M), rows are numbered from top to bottom, columns are numbered from left to right. Then, the coordinates of the cell where you want to bring the settler are set in the same way.

Next comes the description of the world map in the form of N lines, each of which contains M characters. Each character can be either "." (dot) to represent a field, or "W" to represent forest, or "#" to represent water. It is guaranteed that the start and end cells of the migrant's path are not water.
  
#### Output:
  
In the first line of the output file print the number of time units needed to move the settler (moving to a cell with a field takes 1 time unit, moving to a cell with a forest takes 2 time units). In the second line of the output file print a sequence of characters that define the migrant's route. Each character must be one of the following four: "N" (move up), "E" (move right), "S" (move down), "W" (move left). If there are several such routes, print any of them.

If it is impossible to get from the initial cell to the final one, print the number -1.
      
</details>

<details><summary>Task N: Piggy banks</summary>

#### Description:
  
Vasya has n piggy banks, the pigs are numbered from 1 to n. Each piggy bank can be opened with a single matching key or broken.

Vasya put the keys in some of the piggy banks (he remembers which key is in which of the piggy banks). Now Vasya is going to buy a car, and for this he needs to get money from all piggy banks. At the same time, he wants to break as few piggy banks as possible (after all, he still needs to save money for an apartment, a summer house, a helicopter ...). Help Vasya determine the minimum number of piggy banks to break.

#### Input:

The first line contains the number n — the number of piggy banks (1 ≤ n ≤ 100). Then there are n lines describing where the key to which piggy bank is located: the i-th of these lines contains the number of the piggy bank containing the key to the i-th piggy bank.
  
#### Output:
  
Print a single number: the minimum number of piggy banks you need to split.
 
</details>

<details><summary>Task O: Down with cheating!</summary>
  
#### Description:
  
During the test, Mikhail Dmitrievich noticed that some lkshats were exchanging notes. At first, he wanted to give them all twos, but that day Mikhail Dmitrievich was kind, and therefore he decided to divide the lkshat into two groups: those who cheat and those who give to write off, and give two only to the first.

Mikhail Dmitrievich has recorded all the pairs of lkshats who exchanged notes. It is required to determine whether he can divide the lkshat into two groups so that any exchange of notes is carried out from the lkshon of one group to the lkshon of the other group.

#### Input:
  
The first line contains two numbers N and M — the number of lkshats and the number of pairs of lkshats exchanging notes (1 <= N <= 100, 0 <= M <= N(N-1)/2). Further in M lines there are descriptions of pairs of lkshats: two different numbers corresponding to the numbers of lkshats exchanging notes (numbering of lkshats starts from 1). Each pair of lkshats is listed at most once.
  
#### Output:

It is necessary to derive the answer to Pavel Olegovich's problem. If it is possible to divide lkshat into two groups, print "YES"; otherwise print "NO".
  
</details>

<details><summary>Task P: Flights</summary>
  
### Description:
  
Chief designer Petya was asked to develop a new aircraft model for Air Bubundia. It turned out that the most difficult part lies in the selection of the optimal size of the fuel tank.

The chief cartographer of Air Bubundia, Vasya, made a detailed map of Bubundia. On this map, he noted the fuel consumption for a flight between each pair of cities.

Petya wants to make the tank size as small as possible, for which the plane can fly from any city to any other (perhaps with refueling on the way).

#### Input:
  
The first line of the input file contains a natural number n (0 <= N <= 1000) — the number of cities in Bubundia. Then there are n lines of n numbers each. The j-th number in the i-th line is equal to the fuel consumption for the flight from the i-th city to the j-th one. All numbers are not less than zero and less than 10^9. It is guaranteed that for any i in the i-th row, the i-th number is equal to zero.

#### Output:
  
The first line of the output file must contain a single number — the optimal tank size.

</details>
</details>
  
  
