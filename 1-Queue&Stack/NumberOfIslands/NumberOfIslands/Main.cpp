#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// Process a land block's neighbor.
void Neighbor(vector<vector<char>>& grid, queue<vector<int>>& queue, vector<int> pair, int ofX, int ofY)
{
	int x = pair[0] + ofX;
	int y = pair[1] + ofY;

	if (x < 0 || x > grid.size() - 1 || y < 0 || y > grid[0].size() - 1)
	{
		return;
	}
	else
	{
		/** If the neighbor is also a land blcok, set it to water,
		 *  prevent it from being counted as a island again.
		 */
		if (grid[x][y] == '1')
		{
			grid[x][y] = '0';
			vector<int> temp;
			temp.push_back(x);
			temp.push_back(y);
			queue.push(temp);
		}
	}
}

int Islands(vector<vector<char>>& grid, queue<vector<int>>& queue)
{
	int count = 0;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (grid[i][j] == '1')
			{
				vector<int> pair;
				pair.push_back(i);
				pair.push_back(j);
				queue.push(pair);

				grid[i][j] = '0';
				count++;

				while (!queue.empty())
				{
					vector<int> temp = queue.front();
					queue.pop();
					Neighbor(grid, queue, temp, -1, 0);
					Neighbor(grid, queue, temp, 0, 1);
					Neighbor(grid, queue, temp, 1, 0);
					Neighbor(grid, queue, temp, 0, -1);
				}
			}
		}
	}
	return count;
}

int main()
{
	vector<char> row1;
	row1.push_back('1');
	row1.push_back('1');
	row1.push_back('0');
	row1.push_back('0');
	row1.push_back('0');

	vector<char> row2;
	row2.push_back('1');
	row2.push_back('1');
	row2.push_back('0');
	row2.push_back('0');
	row2.push_back('0');

	vector<char> row3;
	row3.push_back('0');
	row3.push_back('0');
	row3.push_back('1');
	row3.push_back('0');
	row3.push_back('0');

	vector<char> row4;
	row4.push_back('0');
	row4.push_back('0');
	row4.push_back('0');
	row4.push_back('1');
	row4.push_back('1');

	vector<vector<char>> grid;
	grid.push_back(row1);
	grid.push_back(row2);
	grid.push_back(row3);
	grid.push_back(row4);

	queue<vector<int>> queue;

	int numIslands = Islands(grid, queue);
	cout << numIslands << endl;

	return 0;
}