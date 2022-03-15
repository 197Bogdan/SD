#include <iostream>
#include <vector>
#include "utile.cpp"

using namespace std;

void Merge(vector<int> &v, int st, int dr, int mij)
{
    vector<int> v_merge;
    int i = st;
    int j = mij + 1;
    int k = st;
    while (i <= mij && j <= dr)
    {
        if (v[i] <= v[j])
        {
            v_merge.push_back(v[i]);
            i++;
        }
        else
        {
            v_merge.push_back(v[j]);
            j++;
        }
        k++;
    }
    while (i <= mij)
    {
        v_merge.push_back(v[i]);
        i++;
        k++;
    }
    while (j <= dr)
    {
        v_merge.push_back(v[j]);
        j++;
        k++;
    }
    for (i = st; i < k; i++)
        v[i] = v_merge[i-st];
}

void MergeSort(vector<int> &v, int st, int dr)
{
    if (dr - st + 1 > 10000000)
    {
        cout << "Input too large." << endl;
        return;
    }
    if (st < dr)
    {
        long long mij = (st + dr) / 2;
        MergeSort(v, st, mij);
        MergeSort(v, mij + 1, dr);
        Merge(v, st, dr, mij);
    }
}

