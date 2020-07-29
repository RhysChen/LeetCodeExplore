#include <iostream>
#include <string>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

// Create a list of deadend combinations.
vector<string> CreateDeadends()
{
    vector<string> result;
    string str1 = "0201";
    string str2 = "0101";
    string str3 = "0102";
    string str4 = "1212";
    string str5 = "2002";

    result.push_back(str1);
    result.push_back(str2);
    result.push_back(str3);
    result.push_back(str4);
    result.push_back(str5);

    return result;
}

// Get all possible combinations after turning on slot up or down.
// Turning one slot up or down creates 2 possible combinations.
// There will be 8 possibilities for all 4 slots in total.
vector<string> GetNextComb(string slots)
{
	vector<string> result;
	for (int i = 0; i < 4; i++)
	{
		char slot = slots[i];
		char last;
		char next;

        // If the slot is 0, the slot before it would be 9.
        // If the slot is 9, the slot after it would be 0.
        if (slot == '0')
        {
            last = '9';
            next = (char)(slot + 1);
        }
        else if (slot == '9')
        {
            last = (char)(slot - 1);
            next = '0';
        }
        else
        {
            last = (char)(slot - 1);
            next = (char)(slot + 1);
        }
        result.push_back(slots.substr(0, i) + last + slots.substr(i + 1));
        result.push_back(slots.substr(0, i) + next + slots.substr(i + 1));
	}
    return result;
}

// Calculate the least steps needed to open the clock.
int OpenClock(vector<string>& deadends, string target)
{
    queue<string> queue;
    unordered_set<string> deadendSet(deadends.begin(), deadends.end());
    unordered_set<string> visited;
    int count = 0;

    // If 0000 is in deadend list, the clock cannot be opened.
    if (deadendSet.count("0000"))
    {
        return -1;
    }

    queue.push("0000");
    visited.insert("0000");
    while (!queue.empty())
    {
        int size = queue.size();
        for (int i = 0; i < size; i++)
        {
            string temp = queue.front();
            if (temp == target)
            {
                return count;
            }

            vector<string> neighbor = GetNextComb(temp);
            for (int j = 0; j < neighbor.size(); j++)
            {
                if (!deadendSet.count(neighbor[j]) && !visited.count(neighbor[j]))
                {
                    visited.insert(neighbor[j]);
                    queue.push(neighbor[j]);
                }
            }
            queue.pop();
        }
        count++;
    }
    return -1;
}

int main()
{
    vector<string> deadends = CreateDeadends();
    cout << OpenClock(deadends, "0202") << endl;
    return 0;
}