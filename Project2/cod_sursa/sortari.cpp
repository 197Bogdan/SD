#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include "utile.cpp"
#include "merge_sort.cpp"
#include "counting_sort.cpp"
#include "radix_sort.cpp"
#include "shell_sort.cpp"
#include "quick_sort.cpp"



using namespace std;


void SortTimers(const vector<int> sizes, const vector<int> maxes)
{
    if (sizes.size() != maxes.size())
    {
        cout << "Dimensiune inegala pentru sizes/maxes." << endl;
        exit(1);
    }
    for (int i = 0; i < sizes.size(); i++)
    {
        cout << "Numar elemente: " << sizes[i] << "  Valoare maxima: " << maxes[i] << endl;
        vector<int> v;

        auto start = chrono::high_resolution_clock::now();
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<mt19937::result_type> dist(0, maxes[i]);
        for (int j = 0; j < sizes[i]; j++)
            v.push_back(dist(rng));
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

        cout << "Timp generare random: " << float(duration.count())/1000000 << endl;
        vector<int> v_copy(v);

        start = chrono::high_resolution_clock::now();
        sort(v.begin(), v.begin()+v.size());
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);

        cout << "Timp STD sort: " << float(duration.count())/1000000 << endl;
        cout << "Este sortat? " << IsSorted(v) << endl;

        start = chrono::high_resolution_clock::now();
        CountingSort(v);
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);

        cout << "Timp CountingSort: " << float(duration.count())/1000000 << endl;
        cout << "Este sortat? " << IsSorted(v) << endl;

        v = v_copy;
        start = chrono::high_resolution_clock::now();
        MergeSort(v, 0, v.size() - 1);
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);

        cout << "Timp MergeSort: " << float(duration.count())/1000000 << endl;
        cout << "Este sortat? " << IsSorted(v) << endl;

        v = v_copy;
        start = chrono::high_resolution_clock::now();
        ShellSort(v);
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);

        cout << "Timp ShellSort: " << float(duration.count())/1000000 << endl;
        cout << "Este sortat? " << IsSorted(v) << endl; 

        v = v_copy;
        start = chrono::high_resolution_clock::now();
        RadixSort(v);
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);

        cout << "Timp RadixSort 2^16: " << float(duration.count())/1000000 << endl;
        cout << "Este sortat? " << IsSorted(v) << endl;

        v = v_copy;
        start = chrono::high_resolution_clock::now();
        RadixSort(v, 10);
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);

        cout << "Timp RadixSort 10: " << float(duration.count())/1000000 << endl;
        cout << "Este sortat? " << IsSorted(v) << endl;

        v = v_copy;
        start = chrono::high_resolution_clock::now();
        RadixSort(v, 256);
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);

        cout << "Timp RadixSort 2^8: " << float(duration.count()) / 1000000 << endl;
        cout << "Este sortat? " << IsSorted(v) << endl;

        v = v_copy;
        start = chrono::high_resolution_clock::now();
        ShellSort(v, 'k');
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);

        cout << "Timp ShellSort k sequence: " << float(duration.count())/1000000 << endl;
        cout << "Este sortat? " << IsSorted(v) << endl;

        v = v_copy;
        start = chrono::high_resolution_clock::now();
        QuickSort(v, 0, v.size() - 1);
        stop = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::microseconds>(stop - start);

        cout << "Timp QuickSort: " << float(duration.count())/1000000 << endl;
        cout << "Este sortat? " << IsSorted(v) << endl;
        cout << endl << endl << endl;
    }
}


int main()
{
    
    vector<int> sizes = {1000, 1000, 1000, 1000000, 1000000 , 1000000, 10000000, 10000000,10000000, 100000000, 100000000, 100000000 };
    vector<int> maxes = {1000, 1000000, 100000000, 1000, 1000000, 100000000, 1000, 1000000, 100000000, 1000, 1000000, 100000000};
    SortTimers(sizes, maxes);
    
    return 0;
}