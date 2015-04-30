#Subsets

###Problem
Given a set of distinct integers, nums, return all possible subsets. 

###Solution
Use recursive algorithm:

1. If the set is empty. Return a set conaining an empty set. 

2. Split the set into two parts: the first element and the rest of list.

3. Find the subset of the rest of list.

4. Return the union of first element and result of step 3.
