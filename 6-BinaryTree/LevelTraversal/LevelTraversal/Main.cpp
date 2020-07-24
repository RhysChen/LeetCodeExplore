#include <iostream>
#include <Queue>
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

void LevelTraversal(TreeNode* root)
{
	queue<TreeNode*> queue;

	if (root != NULL)
	{
		queue.push(root);
	}

	while (!queue.empty())
	{
		TreeNode* node = queue.front();
		queue.pop();
		cout << node->val << " ";

		if (node->left != NULL)
		{
			queue.push(node->left);
		}

		if (node->right != NULL)
		{
			queue.push(node->right);
		}
		
	}
}

int main()
{
	TreeNode* root = BuildBinaryTree();
	LevelTraversal(root);
	return 0;
}
