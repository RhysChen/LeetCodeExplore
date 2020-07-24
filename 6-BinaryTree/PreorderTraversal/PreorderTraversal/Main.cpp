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

// Preorder traversal using recursion.
void RecursivePreorderTraversal(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}

	cout << root->val << " ";
	RecursivePreorderTraversal(root->left);
	RecursivePreorderTraversal(root->right);
}

// Preorder traversal using iteration.
void IterativePreorderTraversal(TreeNode* root)
{
	stack<TreeNode*> stack;

	if (root != NULL)
	{
		stack.push(root);
	}

	while (!stack.empty())
	{
		TreeNode* node = stack.top();
		cout << node->val << " ";
		stack.pop();

		if (node->right != NULL)
		{
			stack.push(node->right);
		}

		if (node->left != NULL)
		{
			stack.push(node->left);
		}
	}
}

int main()
{
	TreeNode* root = BuildBinaryTree();
	RecursivePreorderTraversal(root);
	cout << endl;
	IterativePreorderTraversal(root);
	return 0;
}