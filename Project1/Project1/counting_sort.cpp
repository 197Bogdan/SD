#include <iostream>
#include <vector>
#include "utile.cpp"

using namespace std;


void CountingSort(vector<int>& v)
{
    if (v.size() > INT_MAX)
    {
        cout << "Numarul de elemente este prea mare pentru CountingSort." << endl;
        return;
    }
    int freq_size = GetMax(v) + 1;
    int* freq = new int[freq_size]();
    for (int i : v)
        freq[i]++;
    v.clear();
    for (int i = 0; i <= freq_size - 1; ++i)
        for (int j = 0; j < freq[i]; ++j)
            v.push_back(i);
}