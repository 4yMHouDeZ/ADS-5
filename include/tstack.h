// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#define SIZE_MIN 100
#define SIZE_MAX 500

template<typename T, int size>
class TStack {
 private:
  int top;
  T data;

 public:
  TStack(): top(-1) {
    if (size <= 100) {
      T data[SIZE_MIN];
    } else {
      T data[SIZE_MAX];
    }
  }

  bool isEmpty() {
    return top == -1;
  }

  bool isFull() {
    return (top >= size);
  }

  void push(T el) {
    if (!this->isFull()) {
      top++;
      data[top] = el;
    }
  }

  void pop() {
    if (!this->isEmpty()) {
      data[top] = 0;
      top--;
    }
  }

  T peek() {
    return data[top];
  }
};

#endif  // INCLUDE_TSTACK_H_
