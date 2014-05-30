Genetic Algorithm
=================

This repo is something I wrote for fun that is based on a project we had to do in our first year of university. Basically you input a string and through randomization, the program eventually gets to your string.

How it works
------------

We start by creating 100 Children. Each one is completely randomized. We check the "strenth" of each child against the user input and assign it to the child.
We sort the list of children according to their strengths. The "fittest" children should be first.

We take children 6 to 100 and assign one of the other 5 childrens words to them. This is done by randomization. So child 6 might end up with child 2s word.

Next we mutate a random character of children 6 to 100 and recalculate their strengths. Sort the list and repeat the process.

We know we can stop when the "fittest" childs strength is equal to the user inputs length.
