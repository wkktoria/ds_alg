#pragma once

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>

namespace ds {
template <typename T>
class LinkedList {
 public:
  LinkedList() = default;
  ~LinkedList() = default;

  inline void Append(const T &value) {
    auto node{std::make_unique<Node>(value)};

    if (head_ == nullptr) {
      head_ = std::move(node);
    } else {
      auto current_node{head_.get()};

      while (current_node->next != nullptr) {
        current_node = current_node->next.get();
      }

      current_node->next = std::move(node);
    }

    ++size_;
  }

  inline void Delete(const T &value) {
    if (head_->data == value) {
      head_ = std::move(head_->next);
    } else {
      auto current_node{head_.get()};

      while (current_node->next != nullptr) {
        if (current_node->next->data == value) {
          current_node->next = std::move(current_node->next->next);
        }

        current_node = current_node->next.get();
      }
    }

    --size_;
  }

  inline void Print() {
    auto current_node{head_.get()};

    while (current_node != nullptr) {
      std::cout << current_node->data << ' ';
      current_node = current_node->next.get();
    }
  }

  inline std::size_t size() { return size_; }

 private:
  struct Node {
    std::unique_ptr<Node> next{nullptr};
    T data{};

    Node(const T &value) : data(value) {}
  };

  std::unique_ptr<Node> head_{nullptr};
  std::size_t size_{0};
};
}  // namespace ds