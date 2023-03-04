/**
 * @file SCTDL002.cpp
 * @author long (you@domain.com)
 * @brief C++ program generates valid binary strings
 * Input:    1??0?101
 * Output:
 *          10000101
 *          10001101
 *          10100101
 *          10101101
 *          11000101
 *          11001101
 *          11100101
 *          11101101
 * @version 0.1
 * @date 2023-03-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
int arr[10000];

void generateBinString(std::string bin, int len, int index);
void printBinString(std::string bin, int len);

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        std::string bin;
        std::cin >> bin;
        int countQM{0};
        for(int i = 0; i < bin.length(); i++)
            if (bin[i] == '?')
                countQM++;
        
        generateBinString(bin, countQM, 0);
    }
}

// Function to print the output
void printBinString(std::string bin, int len)
{
    int index = 0;
    for (int i = 0; i < bin.size(); i++)
        if(bin[i] != '?')
            std::cout << bin[i];
        else    
            std::cout << arr[index++];
    
    std::cout << std::endl;
}

// Function to generate all binary strings
void generateBinString(std::string bin, int len, int index)
{
	if (index == len) {
		printBinString(bin, len);
		return;
	}

	// First assign "0" at ith position
	// and try for all other permutations
	// for remaining positions
	arr[index] = 0;
    generateBinString(bin, len, index+1);

	// And then assign "1" at ith position
	// and try for all other permutations
	// for remaining positions
	arr[index] = 1;
	generateBinString(bin, len, index+1);
}