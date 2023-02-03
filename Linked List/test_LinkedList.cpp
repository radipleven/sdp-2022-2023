#include <gtest/gtest.h>
#include "LinkedList.cpp"



TEST(LinkedListTest, InsertAtPos) {
    LinkedList<int> list;
    list.insertAtPos(3);
    list.insertAtPos(2, 0);
    list.insertAtPos(1, 0);
    EXPECT_EQ(list.getElementAtPos(0), 1);
    EXPECT_EQ(list.getElementAtPos(1), 2);
    EXPECT_EQ(list.getElementAtPos(2), 3);
}

TEST(LinkedListTest, RemoveAtPos) {
    LinkedList<int> list;
    list.insertAtPos(3);
    list.insertAtPos(2);
    list.insertAtPos(1);
    list.removeAtPos(1);
    EXPECT_EQ(list.getElementAtPos(0), 1);
    EXPECT_EQ(list.getElementAtPos(1), 3);
}

TEST(LinkedListTest, Reverse) {
    LinkedList<int> list;
    list.insertAtPos(3);
    list.insertAtPos(2);
    list.insertAtPos(1);
    list.reverse();
    EXPECT_EQ(list.getElementAtPos(0), 3);
    EXPECT_EQ(list.getElementAtPos(1), 2);
    EXPECT_EQ(list.getElementAtPos(2), 1);
}

TEST(LinkedListTest, GetSize) {
    LinkedList<int> list;
    list.insertAtPos(3);
    list.insertAtPos(2);
    list.insertAtPos(1);
    EXPECT_EQ(list.getSize(), 3);
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

TEST(LinkedListTest, EqualityOperatorTest) {
  LinkedList<int> list1, list2;
  
  // Test 1: Check equality of empty lists
  EXPECT_TRUE(list1 == list2);

  // Test 2: Check equality of non-empty lists with same values
  list1.insertAtPos(0, 1);
  list1.insertAtPos(1, 2);
  list1.insertAtPos(2, 3);

  list2.insertAtPos(0, 1);
  list2.insertAtPos(1, 2);
  list2.insertAtPos(2, 3);

  EXPECT_TRUE(list1 == list2);

  // Test 3: Check inequality of non-empty lists with different values
  list2.insertAtPos(2, 4);
  EXPECT_FALSE(list1 == list2);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

