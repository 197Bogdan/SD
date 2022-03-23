#include "utile.cpp"
#include <vector>

using namespace std;




int Partition(vector<int>& v, int left, int right)
{
	long long middle = (left + right) / 2;
	if (v[left] > v[middle])
		swap(v[left], v[middle]);
	if (v[left] > v[right])
		swap(v[left] , v[right]);
	if (v[middle] > v[right])
		swap(v[middle], v[right]);
	int pivot = v[middle];
	swap(v[middle], v[right - 1]);	// save pivot on (right-1) position
	int left_index = left;
	int right_index = right-2;
	while (1)
	{
		while (v[left_index] < pivot)
			left_index++;
		while (v[right_index] > pivot)
			right_index--;
		if (left_index < right_index)
		{
			swap(v[left_index], v[right_index]);		// find unpartitioned elements and swap them
			left_index++;
			right_index--;
		}
		else break;
		
	}
	swap(v[right - 1], v[left_index]);	// put pivot to the right of all elements smaller than it
	return left_index; 
}

void ManualSort(vector<int>& v, int left, int right)
{
	if (left == right)
		return;
	else if (right - left == 1)
	{
		if (v[left] > v[right])
			swap(v[left], v[right]);
	}
	else
	{
		long long middle = (left + right) / 2;
		if (v[left] > v[middle])
			swap(v[left], v[middle]);
		if (v[left] > v[right])
			swap(v[left], v[right]);
		if (v[middle] > v[right])
			swap(v[middle], v[right]);
	}

}

void QuickSort(vector<int>& v, int left, int right)
{
	if (left < right)
	{
		int size = right - left + 1;
		if (size > 3)
		{
			int index = Partition(v, left, right);
			QuickSort(v, left, index - 1);
			QuickSort(v, index + 1, right);

		}
		else ManualSort(v, left, right);
	}
}