#pragma once
#include <vector>
#include <iostream>
#include <random>

using namespace std;



void print_vector(const vector<int>& v)
{
    for (int i : v)
        cout << i << " ";
    cout << endl;
}
bool IsSorted(const vector<int>& v)
{
    for (int i = 1; i < v.size(); i++)
        if (v[i] < v[i - 1])
            return false;
    return true;
}
void ReadVecFromFile(const string filename, vector<int>& v)
{
    ifstream f(filename);
    int element;
    while (f >> element)
        v.push_back(element);
}

void PrintVecToFile(const string filename, const vector<int>& v)
{
    ofstream g(filename);
    for (int element : v)
        g << element << " ";
}

void GenerateRandomInput(const string filename, const int sequence_length, const int max_value)
{
    ofstream g(filename);
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(0, max_value);
    for (int i = 0; i < sequence_length; i++)
        g << dist(rng) << " ";
}
int GetMax(const vector<int>& v)
{
    int max = v[0];
    for (auto i : v)
        if (i > max)
            max = i;
    return max;
}
