#include "pch.h"

#include <gtest/gtest.h>
#include "stack.h"

// 1. Проверка начального состояния нового стека
TEST(StaticStackTest, InitiallyEmpty) {
    StaticStack stack;
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_FALSE(stack.isFull());
    EXPECT_EQ(stack.size(), 0);
    EXPECT_EQ(stack.capacity(), 5);
}

// 2. Проверка добавления элемента и просмотра вершины
TEST(StaticStackTest, PushAndTop) {
    StaticStack stack;
    stack.push(42);
    EXPECT_FALSE(stack.isEmpty());
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.top(), 42);
}

// 3. Проверка принципа LIFO (Последним пришел — первым ушел)
TEST(StaticStackTest, LifoOrder) {
    StaticStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    EXPECT_EQ(stack.top(), 30);
    stack.pop();
    EXPECT_EQ(stack.top(), 20);
    stack.pop();
    EXPECT_EQ(stack.top(), 10);
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());
}

// 4. Проверка заполнения стека до предела (5 элементов)
TEST(StaticStackTest, BecomesFull) {
    StaticStack stack;
    for (int i = 1; i <= 4; ++i) {
        stack.push(i);
    }
    EXPECT_FALSE(stack.isFull());

    stack.push(5);
    EXPECT_TRUE(stack.isFull());
    EXPECT_EQ(stack.size(), 5);
}

// 5. Проверка исключения при переполнении (6-й элемент)
TEST(StaticStackTest, ThrowOnOverflow) {
    StaticStack stack;
    for (int i = 0; i < 5; ++i) {
        stack.push(i);
    }
    EXPECT_THROW(stack.push(999), std::overflow_error);
}

// 6. Проверка исключения при удалении из пустого стека
TEST(StaticStackTest, ThrowOnUnderflowPop) {
    StaticStack stack;
    EXPECT_THROW(stack.pop(), std::underflow_error);
}

// 7. Проверка исключения при чтении вершины пустого стека
TEST(StaticStackTest, ThrowOnEmptyTop) {
    StaticStack stack;
    EXPECT_THROW(stack.top(), std::out_of_range);
}

// 8. Проверка изменения верхнего элемента через неконстантный top()
TEST(StaticStackTest, ModifyTopElement) {
    StaticStack stack;
    stack.push(5);
    stack.top() = 99;
    EXPECT_EQ(stack.top(), 99);
    EXPECT_EQ(stack.size(), 1);
}

// 9. Проверка очистки стека методом clear()
TEST(StaticStackTest, ClearStack) {
    StaticStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.clear();
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_EQ(stack.size(), 0);
    EXPECT_THROW(stack.top(), std::out_of_range);
}

// 10. Проверка работы константного объекта стека
TEST(StaticStackTest, ConstStackAccess) {
    StaticStack stack;
    stack.push(100);
    stack.push(200);

    const StaticStack& const_ref = stack;
    EXPECT_EQ(const_ref.top(), 200);
    EXPECT_EQ(const_ref.size(), 2);
    EXPECT_FALSE(const_ref.isEmpty());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
