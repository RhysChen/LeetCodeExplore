#include <iostream>
#include <Stack>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value)
	{
		val = value;
		left = NULL;
		right = NULL;
	}
};

// Build a binary tree.
//         5
//        / \
//       6  13
//      / \   \
//     21  2  15
TreeNode* BuildBinaryTree()
{
	TreeNode* root = new TreeNode(5);
	TreeNode* firstLeft = root->left = new TreeNode(6);
	TreeNode* firstRight = root->right = new TreeNode(13);
	firstLeft->left = new TreeNode(21);
	firstLeft->right = new TreeNode(2);
	firstRight->right = new TreeNode(15);

	return root;
}

void MaxDepth(TreeNode* root, int depth, int& result)
{
	if (root == NULL)
	{
		return;
	}
	depth++;
	
	if (root->left == NULL && root->right == NULL)
	{
		if (depth > result)
		{
			result = depth;
		}
	}

	MaxDepth(root->left, depth, result);
	MaxDepth(root->right, depth, result);
}

int main()
{
	int result = 0;
	TreeNode* root = BuildBinaryTree();
	MaxDepth(root, 0, result);
	cout << result << endl;
	return 0;
}