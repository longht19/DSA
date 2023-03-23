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
#include <iostream>
using namespace std;

void nextBinStr(string &num)
{
	int l = num.size();

	// loop from the right to the left
	for (int i=l-1; i>=0; i--)
	{
		// if '0' is encountered, convert
		// it to '1' and then break
		if (num[i] == '0') {
			num[i] = '1';
			break;
		}
		// else convert '1' to '0'
		else {
			num[i] = '0';
		}			
	}
	cout << num << endl;
}

int main()
{
	int t;
	string num;
	cin >> t;
    while (t--)
    {
        cin >> num;
        nextBinStr(num);
		num.clear();
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void TheNextBinStr(string str) {
	int i = str.length()-1;
	while(i>=0 && str[i]=='1') i--;
	if(i<0){
		for(int j=0;j < str.length();j++) 
			cout << '0';
		cout << endl;
	}
	else {
		str[i] = '1';
		for(int j=i+1;j < str.length();j++) 
			str[j] = '0';
		cout << str << endl;
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		TheNextBinStr(str);
	}
}