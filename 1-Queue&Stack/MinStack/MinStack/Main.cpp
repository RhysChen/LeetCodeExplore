#include<iostream>

using namespace std;

struct Node
{
	int val;
	Node* next;
	Node* prev;

	Node(int value)
	{
		val = value;
		next = NULL;
		prev = NULL;
	}
};

class MinStack
{
public:
	// Constructor for initialization.
	MinStack()
	{
		top = NULL;
		bottom = NULL;
	}

	// Push an element into the stack at the top.
	void Push(int x)
	{
		if (IsEmpty())
		{
			top = new Node(x);
			bottom = top;
		}
		else
		{
			Node* node = new Node(x);
			top->next = node;
			node->prev = top;
			top = node;
		}
	}

	// Remove the element at the top of the stack.
	void Pop()
	{
		if (!IsEmpty())
		{
			if (top == bottom)
			{
				Node* node = top;
				top = NULL;
				bottom = NULL;
				delete node;
			}
			else
			{
				Node* node = top;
				top = node->prev;
				top->next = NULL;
				delete node;
			}
		}
	}

	// Return the top element value without removing it.
	int Top()
	{
		if (!IsEmpty())
		{
			return top->val;
		}
		return -1;
	}

	// Retrieve the minimum value in the stack.
	int GetMin()
	{
		if (!IsEmpty())
		{
			int min = top->val;
			Node* node = top->prev;
			while (node != NULL)
			{
				int temp = node->val;
				if (temp < min)
				{
					min = temp;
				}
				node = node->prev;
			}
			return min;
		}
		return -1;
	}

	// Check if the stack is empty.
	bool IsEmpty()
	{
		if (top == NULL && bottom == NULL)
		{
			return true;
		}
		return false;
	}

private:
	Node* top;
	Node* bottom;
};

int main()
{
	MinStack minStack;
	minStack.Push(-2);
	minStack.Push(0);
	minStack.Push(-3);

	cout << minStack.GetMin() << endl;
	
	minStack.Pop();

	cout << minStack.Top() << endl;
	cout << minStack.GetMin() << endl;

	return 0;
}