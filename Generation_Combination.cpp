#include <bits/stdc++.h>

using namespace std;
#define MAX 100
int a[MAX], n, k;
bool OK = true;

void Init()
{
    for(int i = 1; i <= k; i++)
    {
        a[i] = i;
    }
}

void Result()
{
    for(int i = 1; i <= k; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Next_combination()
{
    int i = k;
    while(i > 0 && a[i] == n-k+i)
    {
        i--;
    }
    if(i > 0)
    {
        a[i]++;
        for(int j=i+1; j <= k; j++)
        {
            a[j] = a[i] + j - i;
        }
    } else OK = false;
}

int main()
{
    cin >> n >> k;
    Init();
    while(OK)
    {
        Result();
        Next_combination();
    }
}