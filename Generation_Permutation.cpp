#include <bits/stdc++.h>

using namespace std;

int a[100], n;
bool OK = true;

void Init()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
}
void Result()
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void Next_Permutation()
{
    int j = n-1;
    while(j > 0 && a[j] > a[j+1])
    {
        j--;
    }
    if(j > 0)
    {
        int k = n;
        while(a[j] > a[k])
        {
            k--;
        }
        swap(a[j], a[k]);
        int r = j + 1, s = n;
        while(r < s)
        {
            swap(a[r], a[s]);
            r++;
            s--;
        }
    } else OK = false;
}
int main()
{
    cin >> n;
    Init();
    while(OK)
    {
        Result();
        Next_Permutation();
    }
}