#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int frames = 4;
    int arr[] = {7, 0, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};

    deque<int> q(frames);
    int count = 0;
    int page_faults = 0;
    deque<int>::iterator itr;
    q.clear();
    for (int i : arr)
    {

        // Insert it into set if not present
        // already which represents page fault
        itr = find(q.begin(), q.end(), i);
        if (!(itr != q.end()))
        {

            ++page_faults;

            // Check if the set can hold equal pages
            if (q.size() == frames)
            {
                q.erase(q.begin());
                q.push_back(i);
            }
            else
            {
                q.push_back(i);
            }
        }
        else
        {
            q.erase(itr);   // Removing indexes page
            q.push_back(i); // Inserting current page
        }
    }
    cout << "Page Faults = " << page_faults;
    int size_arr = sizeof(arr) / sizeof(arr[0]);
    cout << "\nHits = " << (size_arr - page_faults);
    float hitr = (page_faults / size_arr) * 100;
    float pgr = ((size_arr - page_faults) / size_arr) * 100;
    cout << "\nPage Fault Ratio = " << hitr << "%\n";
    cout << "Hit Ratio = " << pgr << "%\n";
}