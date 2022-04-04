// CPP program to find the length of the
// longest decreasing subsequence
#include <bits/stdc++.h>
using namespace std;

// Function that returns the length
// of the longest decreasing subsequence
int lds(int arr[], int n)
{
	int lds[n];
	int i, j, max = 0;
	for (i = 0; i < n; i++)
		lds[i] = 1;
	for (i = 1; i < n; i++)
		for (j = 0; j < i; j++)
			if (arr[i] < arr[j] && lds[i] < lds[j] + 1)
				lds[i] = lds[j] + 1;
	for (i = 0; i < n; i++)
		if (max < lds[i])
			max = lds[i];

	// returns the length of the LDS
	return max;
}
// Driver Code
int main()
{
	int arr[] = {3, 2, 5, 6, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Length of LDS is " << lds(arr, n);
	return 0;
}
