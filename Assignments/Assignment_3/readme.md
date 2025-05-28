# 🧠 Assignment 3: Math Expression Parser & Evaluator

This assignment implements a MathExpression class that supports parsing and evaluating mathematical expressions provided in infix notation.

## Features
- Converts infix expressions to postfix.

- Validates input expressions.

- Evaluates expressions using a stack-based algorithm.

- Returns detailed error messages for invalid expressions.

## Example Usage
```cpp
MathExpression expr("3 + 4 * (2 - 1)");
if (expr.isValid()) {
    std::cout << expr.calculate(); // Outputs 7
}
```

## Compile & Run (Example using g++)
```bash
g++ -std=c++17 src/MathExpression.cpp -o math_expression
```

## 🛠 Requirements
- C++17 or later

- A C++ compiler (e.g. g++)
