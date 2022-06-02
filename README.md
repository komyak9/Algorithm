# Algorithm

## Tasks:

<details><summary>Block 1: Introduction to Algorithms</summary>
<details><summary>Task A</summary>
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

<details><summary>Task B</summary>

Gleb recently opened a zoo. He decided to build it in the shape of a circle and, of course, surrounded it with a fence. Gleb took you there as head of security. It would seem that everything started so well, but it was on your first shift that all the animals fled. There are n animals of different species in the zoo, and each species has its own traps.

Unfortunately, some animals are at enmity with each other in nature (they are designated by different letters), and the zoo is surrounded by a fence and has the shape of a circle. With the help of cameras, it was possible to find out where all the animals are. The zoo's smart life support system has already scanned the zoo and outputs the id of all animals and traps in the order they are seen from the center of the zoo. It so happened that all the animals and all the traps are on the edge of the zoo. You want to see if the animals can get into their trap without crossing paths with others. If yes, also show any of the schemes for capturing animals.

#### Input:

The input is a string of 2n Latin characters, where the small letter is an animal, and the large letter is a trap. The string size is no more than 100000.

#### Output:

It is required to print "Impossible" if there is no solution, or "Possible" if it is possible to return all animals to the cages. If it is possible, then for each trap, in the order of traversal, it is required to print the index of the animal in it.

</details>

<details><summary>Task C</summary>

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

<details><summary>Task D</summary>

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



