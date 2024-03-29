/**
 * @file SCTDL023.cpp
 * @author long (you@domain.com)
 * @brief C++ program counting ways to place Queen in chessboard
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
#define MAX 100
#define TRUE 1
#define FALSE 0

using namespace std;

int X[MAX], toFront[MAX], toBack[MAX], notVisited[MAX];
int n, counter{0};

void Init (void ) {
    counter = 0;
    cin >> n;
    for (int i=1; i<=n; i++) 
    {
        notVisited[i] = TRUE;
    }
    for (int i=1; i<=(2*n-1); i++) 
    {
        toFront[i] = TRUE; 
        toBack[i]=TRUE;
    }
}
void Try(int i){
    for (int j =1; j<=n; j++){
        if (notVisited[j] && toFront[i-j+n] && toBack[i+j-1]){
            X[i] = j;
            notVisited[j]=FALSE;
            toFront[i-j+n]=FALSE;
            toBack[i+j-1]=FALSE;
            if (i==n) { 
                counter++;
            } else {
                Try(i+1);
            }
            notVisited[j]=TRUE;
            toFront[i-j+n]=TRUE;
            toBack[i+j-1]=TRUE;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--) {
        Init(); 
        Try(1);
        cout << counter << endl;
        counter = 0;
    }
    return 0;
}