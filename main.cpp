
#include "dynamicArray.h"
#include <iostream>
#include <cassert>

void test1()
{
    DynamicArray arr = createDynamicArrayWithCapacity(10);
    assert(arr.capacity == 10);
    freeDynamicArray(arr);
}

void test2()
{
    DynamicArray arr = createDynamicArray();
    assert(arr.length == 0);
    addElementToArray(arr, 5);
    assert(arr.length == 1);
    freeDynamicArray(arr);
}

void test3()
{
    DynamicArray arr = createDynamicArrayWithCapacity(1);
    addElementToArray(arr, 5);
    assert(arr.capacity == 1);
    addElementToArray(arr, 10);
    assert(arr.capacity == 2);
    addElementToArray(arr, 20);
    assert(arr.capacity == 4);
    freeDynamicArray(arr);
}

void test4()
{
    DynamicArray arr = createDynamicArray();
    addElementToArray(arr, 5);
    int el = getElementAtIndex(arr, 0);
    assert(el == 5);
    freeDynamicArray(arr);
}

void test5()
{
    DynamicArray arr{};
    addElementToArray(arr, 5);
    addElementToArray(arr, 6);
    addElementToArray(arr, 7);

    std::span<int> span = getCurrentSpan(arr);

    assert(span.size() == 3);
    assert(span[0] == 5);
    assert(span[1] == 6);
    assert(span[2] == 7);

    freeDynamicArray(arr);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
/* 
В процедурной версии динамического массива данные (поля) и операции (функции)
являются открытыми и доступными извне. Например, данные, такие как data, capacity и length, 
могут быть изменены непосредственно без каких-либо ограничений.

Энкапсуляция отсутствует в процедурной версии, так как данные и функции не инкапсулированы внутри структуры. 
Она просто предоставляет доступ к данным через публичные поля и функции.
*/