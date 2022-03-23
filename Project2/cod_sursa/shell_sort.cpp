#include "utile.cpp"
#include <vector>

using namespace std;


void ShellSort(vector<int>& v, const char sequence = 'd')
{
	int size = v.size();
	int interval;
	if (sequence == 'd')		// default shell sequence
		for (interval = size / 2; interval >= 1; interval /= 2)
		{
			int index;
			for (index = interval; index < size; index++)
			{
				int index_copy = index;
				while (v[index_copy] < v[index_copy - interval])
				{
					swap(v[index_copy], v[index_copy - interval]);
					index_copy -= interval;
					if (index_copy - interval < 0)
						break;
				}
			}
		}
	else if (sequence == 'k')		//knuth's increments: (3^k-1)/2
	{
		int starting_interval = 1;
		while (starting_interval < size)
			starting_interval = starting_interval * 3 + 1;
		starting_interval /= 3;
		for (interval = starting_interval; interval >= 1; interval /= 3)
		{
			int index;
			for (index = interval; index < size; index++)
			{
				int index_copy = index;
				while (v[index_copy] < v[index_copy - interval])
				{
					swap(v[index_copy], v[index_copy - interval]);
					index_copy -= interval;
					if (index_copy - interval < 0)
						break;
				}
			}

		}
	}
}

