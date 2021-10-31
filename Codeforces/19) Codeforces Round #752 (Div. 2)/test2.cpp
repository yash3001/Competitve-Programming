#include <bits/stdc++.h>
#include <string.h>

using namespace std;
int fact(int n)
{
	return (n <= 1) ? 1 : n * fact(n - 1);
}

int findSmallerInRight(string str, int low, int high)
{
	int countRight = 0, i;

	for (i = low + 1; i <= high; ++i)
		if (str[i] < str[low])
			++countRight;

	return countRight;
}

int findRank(string str)
{
	int len = str.size();
	int mul = fact(len);
	int rank = 1;
	int countRight;

	int i;
	for (i = 0; i < len; ++i) {
		mul /= len - i;

		countRight = findSmallerInRight(str, i, len - 1);

		rank += countRight * mul;
	}

	return rank;
}

int main()
{
	string s; cin>>s;
    cout<<findRank(s);
	return 0;
}