#include "dynamicArray.h"
#include <iostream>

void test1()
{
    DynamicArray<int> arr(10);
    assert(arr.getCapacity() == 10);
}

void test2()
{
    DynamicArray<int> arr;
    assert(arr.size() == 0);
    arr.add(5);
    assert(arr.size() == 1);
}

void test3()
{
    DynamicArray<int> arr(1);
    arr.add(5);
    assert(arr.getCapacity() == 1);
    arr.add(10);
    assert(arr.getCapacity() == 2);
    arr.add(20);
    assert(arr.getCapacity() == 4);
}

void test4()
{
    DynamicArray<int> arr;
    arr.add(5);
    int el = arr[0];
    assert(el == 5);
}

int main()
{
    test1();
    test2();
    test3();
    test4();

    // Итерация через foreach
    DynamicArray<int> arr;
    arr.add(1);
    arr.add(2);
    arr.add(3);

    for (const int& element : arr)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
/* 
 Данные (поля, такие как data, capacity и length) инкапсулированы внутри класса DynamicArray. 
 Они являются закрытыми (private) и недоступными извне класса. Таким образом, данные защищены от непосредственного изменения.

Операции (методы, такие как конструкторы, деструктор, add, операторы) предоставляют интерфейс 
для взаимодействия с данными класса. Этот интерфейс определяет, каким образом данные могут быть изменены и использованы. 
Интерфейс является публичным, и он позволяет контролировать доступ к данным и операциям.

Связь между понятием интерфейса и энкапсуляцией заключается в том, что интерфейс определяет, 
какие операции доступны для внешнего кода, и скрывает детали реализации. Это позволяет обеспечивать безопасное и
удобное взаимодействие с данными и операциями класса, не раскрывая их внутренней структуры. Энкапсуляция позволяет
управлять доступом к данным и операциям, обеспечивая абстракцию и скрытие сложности реализации.
*/