/**
 * @input EXAM001.cpp
 * @author long (you@domain.com)
 * @brief C++ program to count all characters in a c++ input.
 * @version 0.1
 * @date 2023-03-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
#include <fstream>
#include <string>

void removeSpaces(std::string &str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

int main() {
    std::fstream input, output;
    input.open("main.cpp", std::ios::in);
    output.open("output.txt", std::ios::out);
    std::string line;
    int count = 0;
    while (!input.eof()) {
        getline(input, line);
        removeSpaces(line);
        count += line.length();
    }
    getline(input, line);
    removeSpaces(line);
    count += line.length();
    output << count;
    input.close();
    output.close();
}