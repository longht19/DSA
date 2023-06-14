#include <bits/stdc++.h>

using namespace std;
int n, arr[100];
bool ending = false;

void Next_Permutation()
{
    int j = n-2, k, s, r;
    while(j >= 0 && arr[j] > arr[j+1]) 
    {
        j--;
    }
    if(j >= 0)
    {
        k = n-1;
        while(arr[j] > arr[k])
        {
            k--;
        }
        swap(arr[j], arr[k]);
        r = j+1;
        s = n-1;
        while(r < s)
        {
            swap(arr[r], arr[s]);
            r++;
            s--;
        }
    } else ending = true;
}

int main() 
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Next_Permutation();
    if(!ending)
    {
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    } else 
    {
        for(int i = n-1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
    }
}