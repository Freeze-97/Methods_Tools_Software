# 🧮 Assignment 2: Templated Stack (LIFO) with Unit Tests

This assignment implements a templated `Stack<T>` class using a singly linked list. Unit tests are written using the **Catch2** framework.

## Features

- Stack implementation using a linked list.
- Template-based, works with any data type.
- Basic stack operations: `push`, `pop`, `empty`, `size`.
- Unit tests verifying empty stack behavior, LIFO logic, and size correctness.

## Files

- `include/stack.h` – Templated `Stack<T>` class definition and implementation.
- `test/test-main.cpp` – Catch2 entry point.
- `test/test-stack.cpp` – Comprehensive unit tests using Catch2.

## Compile & Run (Example using g++)

```bash
g++ -std=c++17 test/test-main.cpp test/test-stack.cpp -o stack_tests
./stack_tests
```

## 🛠 Requirements
- C++17 or later

- A C++ compiler (e.g. g++)

- Catch2 for Assignment 2 unit tests
