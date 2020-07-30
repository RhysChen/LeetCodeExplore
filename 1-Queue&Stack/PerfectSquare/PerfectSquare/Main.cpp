#include <iostream>
#include <string>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int NumSquares(int n)
{
    unordered_set<int> visited;
    queue<int> queue;

    queue.push(n);
    int count = 0;

    while (!queue.empty())
    {
        int size = queue.size();
        count++;

        for (int i = 0; i < size; i++)
        {
            int temp = queue.front();
            queue.pop();
            visited.insert(temp);

            for (int j = 1; j * j <= n; j++)
            {
                if (temp - j * j == 0)
                {
                    return count;
                }
                else if (temp - j * j < 0)
                {
                    break;
                }
                else
                {
                    if (!visited.count(temp - j * j))
                    {
                        queue.push(temp - j * j);
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << NumSquares(n) << endl;
    return 0;
}