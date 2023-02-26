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

// function to find the required
// binary representation
string nextGreater(string num)
{
	int l = num.size();

	// examine bits from the right
	for (int i=l-1; i>=0; i--)
	{
		// if '0' is encountered, convert
		// it to '1' and then break
		if (num.at(i) == '0')
		{
			num.at(i) = '1';
			break;
		}
		// else convert '1' to '0'
		else
			num.at(i) = '0';


		// if the binary representation
		// contains only the set bits
		if (i < 0)
			num = "1" + num;
			
	}
	// final binary representation
	// of the required integer
	return num;
}

int main()
{
	int t;
	string num;
	cin >> t;
    while (t--)
    {
        cin >> num;
        cout << nextGreater(num) << endl;
		num.clear();
    }
    return 0;
}
