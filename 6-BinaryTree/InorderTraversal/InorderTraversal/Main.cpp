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

// Inorder traversal using recursion.
void RecursiveInorderTraversal(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}

	RecursiveInorderTraversal(root->left);
	cout << root->val << " ";
	RecursiveInorderTraversal(root->right);
}

// Inorder traversal using iteration.
void IterativeInorderTraversal(TreeNode* root)
{
	stack<TreeNode*> stack;
	TreeNode* node = root;
	while (!stack.empty() || node != NULL)
	{
		while (node != NULL)
		{
			stack.push(node);
			node = node->left;
		}

		if (!stack.empty())
		{
			node = stack.top();
			stack.pop();
			cout << node->val << " ";
			node = node->right;
		}
	}
}

int main()
{
	TreeNode* root = BuildBinaryTree();
	RecursiveInorderTraversal(root);
	cout << endl;
	IterativeInorderTraversal(root);
	return 0;
}