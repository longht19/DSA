/**
 * @file test011.cpp
 * @author LONG (you@domain.com)
 * @brief Generate all binary strings of length n 
 *        with sub-string “01” appearing exactly twice
 * @version 0.1
 * @date 2023-04-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int bin[30], n, i=0;

int check() {
    int cnt = 0;
    for (int j = 0; j < n-1; j++) {
        if (bin[j] == bin[j+1] - 1) {
            cnt++;
        }
        if (cnt > 2) {
            return 0;
        }
    }
    if (cnt == 2) {
        return 1; 
    }
    
    return 0;
}

void print() {
	i=0;
    if (check ()) {
        for (int j=0; j<n; j++) {
            cout << bin[j];
        }
        cout << " ";
    }
}

void Try(int i) {
	for (int j=0; j<=1; j++) {
		bin[i]=j;
		if (i==n-1) { 
            print();
        } 
		else {
            Try(i+1);
        }
	}
}

int main () {
	int t;
	cin >>t;
	while (t--) {
		cin >> n;
        if (n < 4) cout << -1;
        else {
            if (n == 4) {
                cout << "0101 " << endl;
            }
            else {
                Try(0);
                cout << endl;
            }
        }
	}
	return 0;
}