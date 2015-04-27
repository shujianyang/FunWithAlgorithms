#Find the Single Number

##Problem:
Given an array of integers, every element appears twice except for one. Find that single one.

##Algorithm:
Use bitwise XOR operator to find the value in one pass based on the following theorems:

`q xor q = 0`
`q xor 0 = q`
