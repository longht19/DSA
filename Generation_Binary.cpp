#include <bits/stdc++.h>

using namespace std;

int bin[100], n;
bool OK = true;

void Init()
{
    for(int i = 0 ; i < n; i++)
    {
        bin[i] = 0;
    }
}
void Result()
{
    for(int i = 0 ; i < n; i++)
    {
        cout << bin[i];
    }
    cout << endl;
}
void Next_Bin()
{
    int i = n-1;
    while(i >=0 && bin[i] != 0)
    {
        i--;
    }
    if(i >= 0)
    {
        bin[i] = 1;
        for(int j = i+1; j < n; j++)
        {
            bin[j] = 0;
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
        Next_Bin();
    }
}