// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

bool isOperation(char x) {
  return (x > 41 && x < 48);
}

bool isDigit(char x) {
  return (x >= '0' && x <= '9');
}

void separate(std::string& str) {
  if (str[str.length() - 1] != ' ' && str.length() > 0) str += ' ';
}

int ch2i(char x) {
  return x - '0';
}

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 100> stack;
  char el;
  std::string result = "";
  for (int i = 0; i < inf.length(); i++) {
    el = inf[i];

    if (el == '(') {
      separate(result);
      stack.push(el);
    }

    else if (isOperation(el)) {
      separate(result);
      if (((el == '-' || el == '+') && (stack.peek() == '-' || stack.peek() == '+')) || ((el == '/' || el == '*') && (stack.peek() == '/' || stack.peek() == '*')) || ((el == '-' || el == '+') && (stack.peek() == '*' || stack.peek() == '/'))) {
        result += stack.peek();
        stack.pop();
      }
      stack.push(el);
      separate(result);
    }

    else if (isDigit(el)) result += el;

    else if (el == ')') {
      while (stack.peek() != '(') {
        separate(result);
        result += stack.peek();
        stack.pop();
      }
      stack.pop();
    }
  }
  while (!stack.isEmpty()) {
    separate(result);
    result += stack.peek();
    stack.pop();
  }
  return result;
}


int eval(const std::string& post) {
  TStack<int, 100> stack;
  char el;
  int a, b, temp;
  for (int i = 0; i < post.length(); i++) {
    el = post[i];
    
    if (isDigit(el)) {
      if (i > 0 && isDigit(post[i-1])) {
        temp = stack.peek() * 10 + ch2i(el);
        stack.pop();
        stack.push(temp);
      } else {
        stack.push(ch2i(el));
      }
    } else if (isOperation(el)) {
      b = stack.peek();
      stack.pop();
      a = stack.peek();
      stack.pop();
      switch (el) {
        case '+':
          stack.push(a + b);
          break;
        case '-':
          stack.push(a - b);
          break;
        case '*':
          stack.push(a * b);
          break;
        case '/':
          stack.push(a / b);
          break;
      }
    }
  }
  return stack.peek();
}
