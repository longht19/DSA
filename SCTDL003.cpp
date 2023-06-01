/**
 * @file SCTDL003.cpp
 * @author long (longzil193@gmail.com)
 * @brief C++ implementation to find the binary representation of next greater integer
 * @version 0.1
 * @date 2023-02-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>

using namespace std;

void TheNextBinStr(string str) {
	int i = str.length()-1;
	// Decrease until we find the first bit 0 from right to left
	// if all bits are 1 -> i = -1
	while(i>=0 && str[i]=='1') 
	{	
		i--;
	}
	if(i<0)
	{
		// All bits are 1 -> next bin string is 00...00
		for(int j=0;j < str.length();j++) 
			cout << '0';
		cout << endl;
	} else 
	{
		// from i-th to the right is 0
		str[i] = '1';
		for(int j=i+1;j < str.length();j++) 
			str[j] = '0';
		cout << str << endl;
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string str;
		cin >> str;
		TheNextBinStr(str);
	}
}