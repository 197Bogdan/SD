#include <vector>
#include <iostream>
#include "utile.cpp"
using namespace std;


void CountSort_digit(vector<int>& v, int digit, int base)
{
    
    vector<int> freq(base);
    for (int element : v)
        freq[(element / digit) % base]++;
    for (int i = 1; i < base; i++)
        freq[i] += freq[i - 1];
    vector<int> sorted(v.size());
   
    for (int i = v.size()-1; i >= 0; i--) {
        sorted[freq[(v[i] / digit) % base] - 1] = v[i];
        freq[(v[i] / digit) % base]--;
    }
    v.swap(sorted);
}
void RadixSort(vector<int>& v, const int base = 65536)
{
    int max = GetMax(v);
    for (long long digit = 1; digit <= max; digit *= base)
    {
        CountSort_digit(v, digit, base);
    }

}