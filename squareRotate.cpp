/**
 * @file squareRotate.cpp
 * @author Long (you@domain.com)
 * @brief Given a rectangle table with 6 square pieces. Each square piece is 
 * numbered from 1 to 6. 
 * At each step, we choose a square (left or right), then rotate it clockwise.
 * 
 * | 4 | 1 | 3 |            | 1 | 2 | 3 |               | 1 | 5 | 2 |
 * |   |   |   |     <=     |   |   |   |       =>      |   |   |   |
 * | 5 | 2 | 6 |            |4  | 5 | 6 |               | 4 | 6 | 3 |
 * 
 * From starting state of table, fine the minimum number of steps to transform into 
 * ending state of table.
 * @version 0.1
 * @date 2023-04-13
 * @copyright Copyright (c) 2023
 */
#include <iostream>
#include <queue>

using namespace std;
#define LEN 6

int left_pos[6] = {3, 0, 2, 4, 1, 5};
int right_pos[6] = {0, 4, 1, 3, 5, 2};

string Rotate_Left(string a)
{
    string b = "";
    for (int i = 0; i < LEN; i++)
        b += a[left_pos[i]];
    return b;
}
string Rotate_Right(string a)
{
    string b = "";
    for (int i = 0; i < LEN; i++)
        b += a[right_pos[i]];
    return b;
}
int main()
{
    string a, b;
    int x;
    a = "123456";
    b = "412653";
    // for (int i = 0; i < LEN; i++)
    // {
    //     cin >> x;
    //     a += to_string(x);
    // }
    // for (int i = 0; i < LEN; i++)
    // {
    //     cin >> x;
    //     b += to_string(x);
    // }
    pair<string, int> d, k, e;
    d.first = a;
    d.second = 0;
    queue<pair<string, int>> c;
    c.push(d);
    while (c.size())
    {
        k = c.front();
        c.pop();
        if (k.first == b)
        {
            cout << k.second;
            return 0;
        }
        e.second = k.second + 1;
        e.first = Rotate_Left(k.first);
        c.push(e);
        e.first = Rotate_Right(k.first);
        c.push(e);
    }
}