#include <iostream>
#include <string>

using namespace std;

int longestValidParentheses(string s);

int main()
{
	//cout << "Enter a string containing only '(' and ')'" << endl;
	string input;
	cin >> input;

	cout << longestValidParentheses(input) << endl;

	return 0;
}

int longestValidParentheses(string s)
{
	int longestLeft = 0;
	int leftCnt = 0;
	int current = 0;
	for(int i=0; i<s.length(); ++i){
		if(s[i] == '(')
			leftCnt++;
		else if(s[i] == ')' && leftCnt > 0){
			leftCnt--;
			current += 2;
			if(leftCnt == 0 && current > longestLeft)
				longestLeft = current;
		}
		else
			current = 0;
	}

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
	return longestLeft > longestRight ? longestLeft : longestRight;
}
