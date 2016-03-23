#include <vector>
#include "minHeap.hpp"

int main()
{

	std::vector<int> myData = {8,71,41,31,10,11,16,46,51,31,21,13};

	MinHeap<int> minH(myData);

	minH.Print();

	minH.Insert(55);

	minH.Print();

	int n = minH.Size();
	while (n >= 1)
	{
		std::cout << minH.ExtractMin() << std::endl;
		-- n;
	}	
}