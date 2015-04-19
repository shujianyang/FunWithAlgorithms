#include <iostream>
#include <string>

using namespace std;

int longestValidParentheses(string s);

int main()
{
	string input;
	cin >> input;

	cout << longestValidParentheses(input) << endl;

	return 0;
}

int longestValidParentheses(string s)
{
	//First scan, from left to right.

	int longestLeft = 0;
	int leftCnt = 0;
	int current = 0;
	for(int i=0; i<s.length(); ++i){
		if(s[i] == '(')
			leftCnt++;
		else if(s[i] == ')' && leftCnt > 0){ //If a valid ')' is read
			leftCnt--;
			current += 2;
			if(leftCnt == 0 && current > longestLeft) //If there is no unmatched '('
				longestLeft = current;
		}
		else
			current = 0;
	}

	//Second scan, from right to left

	int longestRight = 0;
	int rightCnt = 0;
	current = 0;
	for(int i=s.length()-1; i>=0;--i)
	{
		if(s[i] == ')')
			rightCnt++;
		else if(s[i] == '(' && rightCnt > 0){
			rightCnt--;
			current += 2;
			if(rightCnt == 0 && current > longestRight)
				longestRight = current;	
		}
		else
			current = 0;
	}

	//Combine the two results and return the larger one
	return longestLeft > longestRight ? longestLeft : longestRight;
}
