// StackLib.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include "stack.h"
#include <stdexcept>

// Конструктор: обнуляем счетчик элементов
StaticStack::StaticStack() : count(0) {}

// Добавление элемента на вершину
void StaticStack::push(int value) {
    if (isFull()) {
        throw std::overflow_error("Ошибка: стек переполнен!");
    }
    data[count] = value;
    count++;
}

// Удаление верхнего элемента
void StaticStack::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Ошибка: невозможно удалить элемент из пустого стека!");
    }
    count--;
}

// Получение ссылки на верхний элемент (с возможностью изменения)
int& StaticStack::top() {
    if (isEmpty()) {
        throw std::out_of_range("Ошибка: стек пуст, вершины нет!");
    }
    return data[count - 1];
}

// Константный доступ к верхнему элементу (только для чтения)
const int& StaticStack::top() const {
    if (isEmpty()) {
        throw std::out_of_range("Ошибка: стек пуст, вершины нет!");
    }
    return data[count - 1];
}

// Проверка на пустоту
bool StaticStack::isEmpty() const {
    return count == 0;
}

// Проверка на заполненность
bool StaticStack::isFull() const {
    return count == CAPACITY;
}

// Текущее количество элементов
std::size_t StaticStack::size() const {
    return count;
}

// Максимальная вместимость стека
std::size_t StaticStack::capacity() const {
    return CAPACITY;
}

// Очистка стека
void StaticStack::clear() {
    count = 0;
}
