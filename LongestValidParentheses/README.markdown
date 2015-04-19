#Longest Valid Parentheses

###Question
Given a string containing only '(' and ')', find the length of the longest nicely matched parentheses substring.

###Example
"(()(()()" prints 4. 

"()())((()()))" prints 8.

###Analysis
This problem can be solved by scanning the string once with a stack tracing parentheses matching.

The solution given here uses a different approach. It scan the string twice but without using a stack.

The first scan is from left to right. It does the following job:

1. A variable `leftCnt` is used to record the number of unmatched left parentheses.

2. Once a ')' is read, the algorithm lock for the number of unmatched '(' stored in `leftCnt`. If `leftCnt` is greater than 0, it means the ')' being read can be matched to a previous '('. However, it is only considered as a **currently matched**. The length of currently matched substring is stored in variable `current`. Value of `leftCnt` will be decreased by 1.

3. If, after the decrease, `leftCnt` becomes 0, the substring will be treated as a **perfectly matched**. The longest length of all perfectly matched strings is stored in `longestLeft`.

4. In a nutshell, a currently matched strings is a valid string. However, its length may keep growing by reading ')' since there are still unmatched '(' to its left. On contrary, a perfectly matched string is a valid string whose length is fixed.

5. If an invalid ')' is encountered, currently matched substring will be reset.

After this scan, the length of longest perfectly matched substring is recorded in `longestLeft`. However, this may cause false negative result, that is missing a valid substring. For example, a scan of "()(()()" prints the result as 2, because the length of the leftmost perfectly matched substring "()" is considered as the largest one. However, the rightmost currently matched substring "()()" is actually longer than "()" and should be the correct result.

The cause of the problem is as the first scan ends, the currently matched "()()" does not have a chance to be converted to a perfectly matched substring.Since no stack is used in this algorithm, the number and positions of unmatched '(' are unknown, making it difficult to convert them into perfectly matched substrings.

To overcome the problem, a reverse scan from right to left is performed with same algorithm except switching the process of '(' and ')'. With this approach, a false negative substring in one scan will be correctly treated in the reverse scan. By combining the results of two scans the correct answer will be given successfully.

###Running
Add strings to SampleInput.txt. Use `cat SampleInput.txt | ./par` to run and see results.
