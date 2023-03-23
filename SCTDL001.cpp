#include <bits/stdc++.h>
using namespace std;

	int t, n;

	int arr[30];
void printTheArray(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void generateAllBinaryStrings(int n, int arr[], int i)
{
	if (i == n) {
		printTheArray(arr, n);
		return;
	}

	// First assign "0" at ith position
	// and try for all other permutations
	// for remaining positions
	arr[i] = 0;
	generateAllBinaryStrings(n, arr, i + 1);

	// And then assign "1" at ith position
	// and try for all other permutations
	// for remaining positions
	arr[i] = 1;
	generateAllBinaryStrings(n, arr, i + 1);
}

int main()
{
	cin >> t;
    while(t--)
    {
        cin >> n;
        generateAllBinaryStrings(n, arr, 0);
        
        for(int i=0; i < n; i++)
        {
            arr[i] = 0;
        }
	}

	return 0;
}