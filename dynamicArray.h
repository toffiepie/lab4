

#pragma once
#include <span>

struct DynamicArray
{
    int* data;
    int capacity;
    int length;
};

DynamicArray createDynamicArrayWithCapacity(int capacity);
DynamicArray createDynamicArray();
void addElementToArray(DynamicArray& arr, int element);
int getElementAtIndex(const DynamicArray& arr, int index);
std::span<int> getCurrentSpan(DynamicArray& arr);
void freeDynamicArray(DynamicArray& arr);
