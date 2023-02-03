#include <gtest/gtest.h>
#include "LinkedList.cpp"

TEST(LinkedListTest, insertAtPosTest) {
    LinkedList<int> list;

    // Insert element at position 0 (front of list)
    list.insertAtPos(1, 0);
    EXPECT_EQ(list.getElementAtPos(0), 1);

    // Insert element at position 1 (middle of list)
    list.insertAtPos(2, 1);
    EXPECT_EQ(list.getElementAtPos(1), 2);

    // Insert element at position 2 (end of list)
    list.insertAtPos(3, 2);
    EXPECT_EQ(list.getElementAtPos(2), 3);

    // Insert element at default position 0 (front of list)
    list.insertAtPos(0);
    EXPECT_EQ(list.getElementAtPos(0), 0);
}
TEST(LinkedListTest, testInsertAtPos) {
    LinkedList<int> ll;
    ll.insertAtPos(10);
    ll.insertAtPos(20, 1);
    ll.insertAtPos(30, 1);

    ASSERT_EQ(ll.getElementAtPos(0), 10);
    ASSERT_EQ(ll.getElementAtPos(1), 30);
    ASSERT_EQ(ll.getElementAtPos(2), 20);
}

TEST(LinkedListTest, testRemoveAtPos) {
    LinkedList<int> ll;
    ll.insertAtPos(10);
    ll.insertAtPos(20, 1);
    ll.insertAtPos(30, 1);
    ll.removeAtPos(1);

    ASSERT_EQ(ll.getElementAtPos(0), 10);
    ASSERT_EQ(ll.getElementAtPos(1), 20);
}

TEST(LinkedListTest, testGetElementAtPos) {
    LinkedList<int> ll;
    ll.insertAtPos(10);
    ll.insertAtPos(20, 1);
    ll.insertAtPos(30, 1);

    ASSERT_EQ(ll.getElementAtPos(0), 10);
    ASSERT_EQ(ll.getElementAtPos(1), 30);
    ASSERT_EQ(ll.getElementAtPos(2), 20);
}

TEST(LinkedListTest, testTop) {
    LinkedList<int> ll;
    ll.insertAtPos(10);
    ll.insertAtPos(20, 1);
    ll.insertAtPos(30, 1);

    ASSERT_EQ(ll.top(), 10);
}

TEST(LinkedListTest, testGetSize) {
    LinkedList<int> ll;
    ll.insertAtPos(10);
    ll.insertAtPos(20, 1);
    ll.insertAtPos(30, 1);

    ASSERT_EQ(ll.getSize(), 3);
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

