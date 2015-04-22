#include <iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode *root, int sum)
{
	if(root==NULL) return false;

	if(root->left == NULL && root->right == NULL)
		return sum == root->val;

	bool result = false;
	if(root->left != NULL)
		result = hasPathSum(root->left, sum - root->val);
	if(!result && root->right != NULL)
		result = hasPathSum(root->right, sum - root->val);
	return result;
}

int main()
{
	int in;
	cin >> in;

	TreeNode *tn4 = new TreeNode(4);
	TreeNode *tn8 = new TreeNode(8);
	TreeNode *tn5 = new TreeNode(5);
	tn5->left = tn4;
	tn5->right = tn8;

	bool res = hasPathSum(tn5, in);

	cout << res << endl;
	return 0;
}
