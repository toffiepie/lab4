#pragma once
#include <cassert>
#include <cstddef>
#include <algorithm>

template <typename T>
class DynamicArray
{
private:
    T* data;
    size_t capacity;
    size_t length;

public:
    DynamicArray() : data(nullptr), capacity(0), length(0) {}

    DynamicArray(size_t capacity) : data(new T[capacity]), capacity(capacity), length(0) {}

    // Конструктор копирования
    DynamicArray(const DynamicArray& other) : data(new T[other.capacity]), capacity(other.capacity), length(other.length)
    {
        std::copy(other.data, other.data + other.length, data);
    }

    // Оператор присваивания
    DynamicArray& operator=(const DynamicArray& other)
    {
        if (this != &other)
        {
            delete[] data;
            data = new T[other.capacity];
            capacity = other.capacity;
            length = other.length;
            std::copy(other.data, other.data + other.length, data);
        }
        return *this;
    }

    // Move-конструктор
    DynamicArray(DynamicArray&& other) noexcept : data(nullptr), capacity(0), length(0)
    {
        std::swap(data, other.data);
        std::swap(capacity, other.capacity);
        std::swap(length, other.length);
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    // Метод для добавления элемента
    void add(const T& element)
    {
        if (length == capacity)
        {
            size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
            T* newData = new T[newCapacity];
            std::copy(data, data + capacity, newData);
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[length] = element;
        length++;
    }

    // Индексатор
    T& operator[](size_t index)
    {
        assert(index < length);
        return data[index];
    }

    // Read-only свойство size
    size_t size() const
    {
        return length;
    }

    // Read-only свойство capacity
    size_t getCapacity() const
    {
        return capacity;
    }

    // Итераторы (дополнительно)
    T* begin() { return data; }
    const T* begin() const { return data; }
    T* end() { return data + length; }
    const T* end() const { return data + length; }
};
