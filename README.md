# Algorithms

This repository contains many algorithms that I have implemented in my course CS403 Algorithm Design and Analysis. Given below are the problem statement and input patterns. Feel free to contribute to improve the code.

=======================================================

## Stable Matching Problem
Used the Gale-Shapley algorithm to solve this problem
### Problem Statement
Given an equal number of men and women to be paired for marriage, each man ranks all the women in order of his preference and each woman ranks all the
men in order of her preference. A stable set of engagements for marriage is one where no man prefers a woman over the one he is engaged to, where that other woman also prefers that man over the one she is engaged to. i.e. with consulting marriages, there would be no reason for the engagements between the people to change. Use the stable matching algorithm to find a stable set of engagements.

- **Input Format**
    1st line of the input mentions the number of men or women, **n**, for which the stable marriage problem is going to be solved.
    The next *n* lines will denote the priority list of the men. Each *i^th^* line will contain *n* entries corresponding to the priority of the women, where the leftmost women will be given the highest priority.
    The next *n* lines after this will contain the women priority list in the same format.
    All indexes of men and women are 0-based.
    *Example Input*:
    This input corresponds to the input data which is given in the assignment.
    ```
    5
    0 1 4 2 3
    0 2 3 1 4
    3 1 4 0 2
    4 3 2 1 0
    2 3 0 1 4
    0 1 2 4 3
    2 1 4 3 0
    3 4 0 2 1
    4 2 3 0 1
    0 3 4 2 1
    ```
- **Output Format**
    The output will contain *n* lines of matched pairs between the men and women.
    *Example Output*:
    This output is corresponding to the input above.
    ```
    (0, 0)
    (1, 1)
    (2, 3)
    (3, 4)
    (4, 2)
    ```
=========================================================

## Cycle Detection in an Undirected Graph
### Problem Statement
Give an algorithm to detect whether a given undirected graph contains a cycle. If the graph contains a cycle, then your algorithm should output one. (It should not output all cycles in the graph, just one of them.) The running time of your algorithm should be `O(m+n)` for a graph with `n` nodes and `m` edges.

- **Input Format**
    The first line of the input contains two integers N and M. N is the number of vertices in the graph, assuming that vertices are 1-based. M is the number of edges in the graph. Each of the next M lines, lines 2,...,M+1, contains a pair of integers representing an edge between the pair of vertices.
    *Example Input*:
    ```
    5 5
    1 3
    2 3
    1 2
    3 5
    4 5
    ```
- **Output Format**
    If the graph contains a cycle then the output is of the format -
    ```
    Cycle Exists
    <Path of the cycle>
    ```
    Otherwise, the output is `No cycle`.

==========================================================

## The Great Escape
The problem has been taken from IARCS OPC Archive and written by K Narayan Kumar, CMI
### Problem Statement
Heroes in Indian movies are capable of superhuman feats. For example, they can jump between buildings, jump onto and from running trains, catch bullets with their hands and teeth and so on. A perceptive follower of such movies would have noticed that there are limits to what even the superheroes can do. For example, if the hero could directly jump to his ultimate destination, that would reduce the action sequence to nothing and thus make the movie quite boring. So he typically labours through a series of superhuman steps to reach his ultimate destination.
In this problem, our hero has to save his wife/mother/child/dog/... held captive by the nasty villain on the top floor of a tall building in the centre of Bombay/Bangkok/Kuala Lumpur/.... Our hero is on top of a (different) building. In order to make the action "interesting" the director has decided that the hero can only jump between buildings that are "close" to each other. The director decides which pairs of buildings are close enough and which are not.
Given the list of buildings, the identity of the building where the hero begins his search, the identity of the building where the captive (wife/mother/child/dog...) is held, and the set of pairs of buildings that the hero can jump across, your aim is determine whether it is possible for the hero to reach the captive. And, if he can reach the captive he would like to do so with minimum number of jumps.
Here is an example. There are 5 buildings, numbered 1,2,...,5, the hero stands on building 1 and the captive is on building 4. The director has decided that buildings 1 and 3, 2 and 3, 1 and 2, 3 and 5 and 4 and 5 are close enough for the hero to jump across. The hero can save the captive by jumping from 1 to 3 and then from 3 to 5 and finally from 5 to 4. (Note that if i and j are close then the hero can jump from i to j as well as from j to i.). In this example, the hero could have also reached 4 by jumping from 1 to 2, 2 to 3, 3to 5 and finally from 5 to 4. The first route uses 3 jumps while the second one uses 4 jumps. You can verify that 3 jumps is the best possible.
If the director decides that the only pairs of buildings that are close enough are 1 and 3, 1 and 2 and 4 and 5, then the hero would not be able to reach building 4 to save the captive.

- **Input Format**
   The first line of the input contains two integers N and M. N is the number of buildings: we assume that our buildings are numbered1,2,...,N. M is the number of pairs of buildings that the director lists as being close enough to jump from one to the other. Each of the next M lines, lines 2,...,M+1, contains a pair of integers representing a pair of buildings that are close. Line i+1 contains integers Ai and Bi, 1 ≤ Ai ≤ N and 1 ≤ Bi ≤ N, indicating that buildings Ai and Bi are close enough. The last line, line M+2 contains a pair of integers S and T, where S is the building from which the Hero starts his search and T is the building where the captive is held. 
   *Example Input*:
   ```
   5 5
   1 3
   2 3
   1 2
   3 5
   4 5
   1 4
   ```
- **Output Format**
   If the hero cannot reach the captive, print 0. If the hero can reach the captive, print out a single integer indicating the number of jumps in the shortest route (in terms of the number of jumps) to reach the captive.
