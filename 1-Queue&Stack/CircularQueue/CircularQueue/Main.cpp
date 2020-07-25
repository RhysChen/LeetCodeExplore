#include <iostream>

using namespace std;

// Definition for circular queue.
class CircularQueue
{
public:
	CircularQueue(int k)
	{
		qSize = k;
		qStart = -1;
		qEnd = -1;
		queue = new int[qSize];
	}

	// Insert an element into the queue. Return true if the operation is successful.
	bool Enqueue(int value)
	{
		if (IsFull())
		{
			return false;
		}
		else
		{
			if (IsEmpty())
			{
				qStart = 0;
				qEnd = 0;
				queue[qEnd] = value;
			}
			else
			{
				if (qEnd == qSize - 1)
				{
					qEnd = 0;
					queue[qEnd] = value;
				}
				else
				{
					queue[++qEnd] = value;
				}
			}
			return true;
		}
	}

	// Remove an element from the head of the queue. Return true if the operation is successful.
	bool Dequeue()
	{
		if (IsEmpty())
		{
			return false;
		}
		else
		{
			if (qStart == qEnd)
			{
				qStart = -1;
				qEnd = -1;
			}
			else
			{
				if (qStart == qSize - 1)
				{
					qStart = 0;
				}
				else
				{
					qStart++;
				}
			}
			return true;
		}
	}

	// Return true if the queue is full.
	bool IsFull()
	{
		if (qStart == 0)
		{
			if (qEnd == qSize - 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (qStart - 1 == qEnd)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	// Return true if the queue is empty.
	bool IsEmpty()
	{
		if (qStart == -1 && qEnd == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// Return the front element value.
	int Front()
	{
		if (IsEmpty())
		{
			return -1;
		}
		else
		{
			return queue[qStart];
		}
	}

	// Return the last element value.
	int Rear()
	{
		if (IsEmpty())
		{
			return -1;
		}
		else
		{
			return queue[qEnd];
		}
	}

private:
	int* queue;
	int qSize;
	int qStart;
	int qEnd;
};

int main()
{
	CircularQueue* queue = new CircularQueue(3);
	queue->Enqueue(1);
	queue->Enqueue(2);
	queue->Enqueue(3);
	cout << queue->Front() << " ";
	queue->Dequeue();
	cout << queue->Front() << " ";
	queue->Dequeue();
	cout << queue->Front() << " ";
	queue->Dequeue();
	return 0;
}