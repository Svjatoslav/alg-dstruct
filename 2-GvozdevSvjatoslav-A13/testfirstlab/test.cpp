#include "pch.h"
#include "../lab_1.h"
#include "lab_int_1.h"
elem_t* CreateHeadforTests() {
    elem_t* head;
    head = (elem_t*)malloc(sizeof(elem_t));
    if (head) {
        head->numElements = 2;
        head->arr[0] = { 1 };
        head->arr[1] = { 2 };
        head->next = NULL;
        return head;
    }
    else {
        return NULL;
    }
}

elem_t* CreateNewNodeforTests(elem_t* prev) {
    elem_t* node = (elem_t*)malloc(sizeof(elem_t));
    if (node) {
        node->numElements = 0;
        node->next = NULL;
        prev->next = node;
        return node;
    }
    else {
        return NULL;
    }
}
TEST(TestGetCurrentNode, TestFirst) {
    elem_t* head = CreateHeadforTests();
    ASSERT_EQ(head, GetCurrentNode(head));
}
TEST(TestGetCurrentNode, TestSecond) {
    elem_t* head = CreateHeadforTests();
    elem_t* current = (elem_t*)malloc(sizeof(elem_t));
    elem_t* sec = (elem_t*)malloc(sizeof(elem_t));
    if (current) {
        current->numElements = 0;
        current->next = NULL;
    }
    head->next = current;
    if (sec) {
        sec->numElements = 0;
        sec->next = NULL;
       }
    assert(current->next = sec);
    ASSERT_EQ(sec, GetCurrentNode(head));
}
TEST(TestAddElement, TestFirst) {
    elem_t* head = CreateHeadforTests();
    AddElement(head, 2);
    ASSERT_EQ(2, head->arr[2]);
}
TEST(TestAddElement, TestSecond) {
    elem_t* head = CreateHeadforTests();
    int i;
    for (i = 1; i <= SIZE + 2; i++) {
        AddElement(head, i);
    }
    ASSERT_EQ(4, head->next->arr[1]);
}
TEST(TestGetElementNum, TestFirst) {
    elem_t* head = CreateHeadforTests();
    ASSERT_EQ(2, GetElementNum(head, 1));
}
TEST(TestGetElementNum, TestSecond) {
    elem_t* head = CreateHeadforTests();
    ASSERT_EQ(ERROR, GetElementNum(head, 3));
}
TEST(TestGetNumKey, TestFirst) {
    elem_t* head = CreateHeadforTests();
    ASSERT_EQ(0, GetNumKey(head, 1));
}
TEST(TestGetNumKey, TestSecond) {
    elem_t* head = CreateHeadforTests();
    ASSERT_EQ(ERROR, GetNumKey(head, 4));
}
TEST(TestGetNextElementKey, TestFirst) {
    elem_t* head = CreateHeadforTests();
    head->numElements = 4;
    head->arr[2] = 4;
    head->arr[3] = 7;
    ASSERT_EQ(7, GetNextElementKey(head, 4));
}

TEST(TestGetNextElementKey, TestThird) {
    elem_t* head = CreateHeadforTests();
    elem_t* node = (elem_t*)malloc(sizeof(elem_t));
    
    head->numElements = 4;
    head->arr[2] = 4;
    head->arr[3] = 7;
    node->next = NULL;
    head->next = node;
    node->arr[0] = 6;
    node->numElements = 1;
    ASSERT_EQ(6, GetNextElementKey(head, 7));
}
TEST(TestGetNextElementKey, TestSecond) {
    elem_t* head = CreateHeadforTests();
    int i;
    for (i = 1; i < 3; i++) {
        head->arr[i]=i+1;
    }
    ASSERT_EQ(ERROR, GetNextElementKey(head, 3));
}
TEST(TestGetCountElements, TestFirst) {
    elem_t* head = CreateHeadforTests();
    ASSERT_EQ(2, GetCountElements(head));
}
TEST(TestGetCountElements, TestSecond) {
    elem_t* head = CreateHeadforTests();
    elem_t* node;
    int i;
    node = (elem_t*)malloc(sizeof(elem_t));
    node->next = NULL;
    head->next = node;
    node->numElements = 0;
    for (i = 0; i < 3; i++) {
        
        node->arr[i] = i;
        node->numElements ++;
    }
    ASSERT_EQ(i+2, GetCountElements(head));
}
TEST(TestDeleteElement, TestFirst) {
    elem_t* head = CreateHeadforTests();
    DeleteElement(head, 1);
    ASSERT_EQ(1, head->numElements);
}
TEST(TestDeleteElement, TestSecond) {
    elem_t* head = CreateHeadforTests();
    DeleteElement(head, 1);
    ASSERT_EQ(ERROR, GetElementNum(head, 1));
}
