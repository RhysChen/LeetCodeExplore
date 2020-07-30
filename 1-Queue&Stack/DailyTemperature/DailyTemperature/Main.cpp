#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> DailyTemperature(vector<int>& temperatures)
{
	if (temperatures.empty())
	{
		return temperatures;
	}

	int size = temperatures.size();
	vector<int> result(size, 0);
	stack<int> index;

	for (int i = 0; i < size; i++)
	{
		while (!index.empty() && temperatures[i] > temperatures[index.top()])
		{
			result[index.top()] = i - index.top();
			index.pop();
		}
		index.push(i);
	}
	return result;
}

int main()
{
	vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> days = DailyTemperature(temperatures);
	for (int i = 0; i < days.size(); i++)
	{
		if (i == days.size() - 1)
		{
			cout << days[i] << endl;
		}
		else
		{
			cout << days[i] << ", ";
		}
	}
	return 0;
}