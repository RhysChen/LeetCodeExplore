#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

int EvalRPN(vector<string>& tokens) 
{
    stack<string> stack;
    int size = tokens.size();
    stringstream sstream;
    for (int i = 0; i <= size; i++)
    {
        if(!stack.empty())
        {
            string token = stack.top();
            if (token == "+")
            {
                stack.pop();
                sstream << stack.top();
                int x;
                sstream >> x;
                sstream.clear();
                stack.pop();
                sstream << stack.top();
                int y;
                sstream >> y;
                sstream.clear();
                stack.pop();
                int result = x + y;
                stack.push(to_string(result));
            }
            else if (token == "-")
            {
                stack.pop();
                sstream << stack.top();
                int x;
                sstream >> x;
                sstream.clear();
                stack.pop();
                sstream << stack.top();
                int y;
                sstream >> y;
                sstream.clear();
                stack.pop();
                int result = y - x;
                stack.push(to_string(result));
            }
            else if (token == "*")
            {
                stack.pop();
                sstream << stack.top();
                int x;
                sstream >> x;
                sstream.clear();
                stack.pop();
                sstream << stack.top();
                int y;
                sstream >> y;
                sstream.clear();
                stack.pop();
                int result = x * y;
                stack.push(to_string(result));
            }
            else if (token == "/")
            {
                stack.pop();
                sstream << stack.top();
                int x;
                sstream >> x;
                sstream.clear();
                stack.pop();
                sstream << stack.top();
                int y;
                sstream >> y;
                sstream.clear();
                stack.pop();
                int result = y / x;
                stack.push(to_string(result));
            }
        }
        if (i < size)
        {
            stack.push(tokens[i]);
        }
    }
    sstream << stack.top();
    int answer;
    sstream >> answer;
    return answer;
}

int main()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << EvalRPN(tokens) << endl;
    return 0;
}