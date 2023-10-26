#include "dynamicArray.h"
#include <cassert>
#include <algorithm>

DynamicArray createDynamicArrayWithCapacity(int capacity)
{
    DynamicArray arr;
    arr.data = new int[capacity];
    arr.capacity = capacity;
    arr.length = 0;
    return arr;
}

DynamicArray createDynamicArray()
{
    return createDynamicArrayWithCapacity(4); //По умолчанию вместительность равна 4
}

void addElementToArray(DynamicArray& arr, int element)
{
    if (arr.length == arr.capacity)
    {
        int newCapacity = arr.capacity * 2;
        int* newData = new int[newCapacity];
        std::copy(arr.data, arr.data + arr.capacity, newData);
        delete[] arr.data;
        arr.data = newData;
        arr.capacity = newCapacity;
    }
    arr.data[arr.length] = element;
    arr.length++;
}

int getElementAtIndex(const DynamicArray& arr, int index)
{
    assert(index >= 0 && index < arr.length);
    return arr.data[index];
}

std::span<int> getCurrentSpan(DynamicArray& arr)
{
    return std::span<int>(arr.data, arr.length);
}

void freeDynamicArray(DynamicArray& arr)
{
    delete[] arr.data;
    arr.data = nullptr;
    arr.capacity = 0;
    arr.length = 0;
}
