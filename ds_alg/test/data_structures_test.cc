#include "linked_list.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>

namespace {
using ds::LinkedList;
}

TEST(LinkedListTest, ReturnValidSizeOfList) {
  LinkedList<int> linked_list{};
  const int expected_size{5};

  for (auto i{1}; i <= expected_size; ++i) {
    linked_list.Append(i);
  }
  EXPECT_EQ(linked_list.size(), expected_size);
}

TEST(LinkedListTest, AppendElementToList) {
  LinkedList<int> linked_list{};
  const int expected_size{1};

  linked_list.Append(1);
  EXPECT_EQ(linked_list.size(), expected_size);

  testing::internal::CaptureStdout();
  linked_list.Print();
  EXPECT_EQ(testing::internal::GetCapturedStdout(), "1 ");
}

TEST(LinkedListTest, AppendFewElementsToList) {
  LinkedList<int> linked_list{};
  const int expected_size{10};

  for (auto i{1}; i <= expected_size; ++i) {
    linked_list.Append(i);
  }
  EXPECT_EQ(linked_list.size(), expected_size);

  testing::internal::CaptureStdout();
  linked_list.Print();
  EXPECT_EQ(testing::internal::GetCapturedStdout(), "1 2 3 4 5 6 7 8 9 10 ");
}

TEST(LinkedListTest, DeleteElementFromList) {
  LinkedList<int> linked_list{};
  const int initial_size{2};

  for (auto i{1}; i <= initial_size; ++i) {
    linked_list.Append(i);
  }

  linked_list.Delete(1);
  EXPECT_EQ(linked_list.size(), initial_size - 1);

  testing::internal::CaptureStdout();
  linked_list.Print();
  EXPECT_EQ(testing::internal::GetCapturedStdout(), "2 ");
}

TEST(LinkedListTest, DeleteFewElementsFromList) {
  LinkedList<int> linked_list{};
  const int initial_size{4};

  for (auto i{1}; i <= initial_size; ++i) {
    linked_list.Append(i);
  }

  linked_list.Delete(1);
  EXPECT_EQ(linked_list.size(), initial_size - 1);

  linked_list.Delete(2);
  EXPECT_EQ(linked_list.size(), initial_size - 2);

  testing::internal::CaptureStdout();
  linked_list.Print();
  EXPECT_EQ(testing::internal::GetCapturedStdout(), "3 4 ");
}