/**
 * @file bucketSort.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
#include <algorithm>

static int n, arr[1000];

void Initialization();
void BucketSort();
void Display();

int main() {
    Initialization();
    BucketSort();
    Display();
}

void Initialization()
{
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
}

void BucketSort() {
    int max{INT_MIN}, min{INT_MAX};
    float range;

    for(int i = 0; i < n; i++) {
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    range = (max - min) / n;

    std::vector<std::vector<int> > temp;
    // create empty buckets
    for (int i = 0; i < n; i++) {
        temp.push_back(std::vector<int>());
    }
    
    // scatter the array elements into the correct bucket
    for (int i = 0; i < n; i++) {
        double diff = (arr[i] - min) / range - int((arr[i] - min) / range);
    
        // append the boundary elements to the lower array
        if (diff == 0 && arr[i] != min) {
            temp[int((arr[i] - min) / range) - 1].push_back(arr[i]);
        }
        else {
            temp[int((arr[i] - min) / range)].push_back(arr[i]);
        }
    }
    
    // Sort each bucket individually
    for (int i = 0; i < n; i++) {
        if (!temp[i].empty()) {
            sort(temp[i].begin(), temp[i].end());
        }
    }
    
    // Gather sorted elements to the original array
    int k = 0;
    for (int i=0; i < n; i++) {
        if (!temp[i].empty()) {
            for (int j = 0; j < temp[i].size(); j++) {
                arr[k] = temp[i][j];
                k++;
            }
        }
    }
}

void Display() {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}