#include <gtest/gtest.h>
#include "LinkedList.cpp"

TEST(LinkedListTest, TestOperatorEqual) {
    LinkedList<int> list1;
    list1.insertAtPos(1);
    list1.insertAtPos(2);
    list1.insertAtPos(3);

    LinkedList<int> list2;
    list2.insertAtPos(1);
    list2.insertAtPos(2);
    list2.insertAtPos(3);

    ASSERT_TRUE(list1 == list2);
}

TEST(LinkedListTest, TestOperatorNotEqual) {
    LinkedList<int> list1;
    list1.insertAtPos(1);
    list1.insertAtPos(2);
    list1.insertAtPos(3);

    LinkedList<int> list2;
    list2.insertAtPos(1);
    list2.insertAtPos(2);
    list2.insertAtPos(4);

    ASSERT_FALSE(list1 == list2);
}

TEST(LinkedListTest, AssignmentOperatorTest) {
    LinkedList<int> list1;
    list1.insertAtPos(1);
    list1.insertAtPos(2);
    list1.insertAtPos(3);
    list1.insertAtPos(4);
    list1.insertAtPos(5);

    LinkedList<int> list2;
    list2 = list1;

    EXPECT_TRUE(list1 == list2);
    EXPECT_EQ(list1.getElementAtPos(0), 5);
    EXPECT_EQ(list1.getElementAtPos(1), 4);
    EXPECT_EQ(list1.getElementAtPos(2), 3);
    EXPECT_EQ(list1.getElementAtPos(3), 2);
    EXPECT_EQ(list1.getElementAtPos(4), 1);

    list2.reverse();

    EXPECT_EQ(list2.getElementAtPos(0), 1);
    EXPECT_EQ(list2.getElementAtPos(1), 2);
    EXPECT_EQ(list2.getElementAtPos(2), 3);
    EXPECT_EQ(list2.getElementAtPos(3), 4);
    EXPECT_EQ(list2.getElementAtPos(4), 5);
}

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

TEST(LinkedListTest, testGetElementAtPos) {
    LinkedList<int> ll;
    ll.insertAtPos(10);
    ll.insertAtPos(20, 1);
    ll.insertAtPos(30, 1);

    ASSERT_EQ(ll.getElementAtPos(0), 10);
    ASSERT_EQ(ll.getElementAtPos(1), 30);
    ASSERT_EQ(ll.getElementAtPos(2), 20);
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

TEST(LinkedListTest, testTop) {
    LinkedList<int> ll;
    ll.insertAtPos(10);
    ll.insertAtPos(20, 1);
    ll.insertAtPos(30, 1);

    ASSERT_EQ(ll.top(), 10);
}

TEST(LinkedListTest, GetSize) {
    LinkedList<int> list;
    list.insertAtPos(3);
    list.insertAtPos(2);
    list.insertAtPos(1);
    EXPECT_EQ(list.getSize(), 3);
}

TEST(LinkedListTest, sortTest) {
   	LinkedList<int> list;
	list.insertAtPos(3);
	list.insertAtPos(2);
	list.insertAtPos(1);
	
	list.sort();

	LinkedList<int> sortedList;
	sortedList.insertAtPos(1);
	sortedList.insertAtPos(2);
	sortedList.insertAtPos(3);

EXPECT_TRUE(list == sortedList);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

