#include <iostream>
#include <Stack>
#include <vector>
#include <algorithm>

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

// Postorder traversal using recursion.
void RecursivePostorderTraversal(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}

	RecursivePostorderTraversal(root->left);
	RecursivePostorderTraversal(root->right);
	cout << root->val << " ";
}

// Postorder traversal using iteration.
vector<int> IterativePostorderTraversal(TreeNode* root)
{
	vector<int> result;
	stack<TreeNode*> stack;
	
	if (root != NULL)
	{
		stack.push(root);
	}

	while (!stack.empty())
	{
		TreeNode* node = stack.top();
		stack.pop();
		result.push_back(node->val);

		if (node->left != NULL)
		{
			stack.push(node->left);
		}

		if (node->right != NULL)
		{
			stack.push(node->right);
		}
	}

	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	TreeNode* root = BuildBinaryTree();
	vector<int> result = IterativePostorderTraversal(root);
	RecursivePostorderTraversal(root);
	cout << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}