#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool IsValid(string brackets)
{
	stack<char> stack;

	for (int i = 0; i < brackets.length(); i++)
	{
		if (stack.size() > 0)
		{
			char temp = stack.top();
			// This character is "(".
			if ((int)temp == 40)
			{
				if ((int)brackets[i] == 41)
				{
					stack.pop();
				}
				else
				{
					stack.push(brackets[i]);
				}
			}
			// This character is "["
			else if ((int)temp == 91)
			{
				if ((int)brackets[i] == 93)
				{
					stack.pop();
				}
				else
				{
					stack.push(brackets[i]);
				}
			}
			else if ((int)temp == 123)
			{
				if ((int)brackets[i] == 125)
				{
					stack.pop();
				}
				else
				{
					stack.push(brackets[i]);
				}
			}
		}
		else
		{
			stack.push(brackets[i]);
		}
	}

	if (stack.size() > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	string brackets;
	cin >> brackets;
	cout << IsValid(brackets) << endl;
	return 0;
}