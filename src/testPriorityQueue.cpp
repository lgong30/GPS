#include <vector>
#include "priorityQueue.hpp"

int main()
{

	std::vector<int> myData = {8,71,41,31,10,11,16,46,51,31,21,13};

	PriorityQueue<int> pq;

    for (auto d: myData)
    	pq.Enqueue(d);

	pq.Enqueue(55);

	pq.Print();

	int n = pq.Size();
	while (n >= 1)
	{
		std::cout << pq.PeekMin() << std::endl;
		pq.PopMin();
		-- n;
	}	
}