// TOmmy Yasi/toya1800
// File for tests

#include "catch.hpp"
#include "../src/MathExpression.cpp"

using namespace std;

// Valid scenario
SCENARIO("Using valid strings") {
    GIVEN("Valid strings testing the main 4 operands") {
        string expression_1 = "3+7";
        string expression_2 = "15-4";
        string expression_3 = "(3*6)*7";
        string expression_4 = "(6*2)/(3+6)";
        WHEN("4 objects are given correct expressions") {
            MathExpression m_1(expression_1);
            MathExpression m_2(expression_2);
            MathExpression m_3(expression_3);
            MathExpression m_4(expression_4);

            // Valid
            THEN("m_1 should return valid"){
                REQUIRE(m_1.isValid());
            }
            THEN("m_2 should return valid"){
                REQUIRE(m_2.isValid());
            }
            THEN("m_3 should return valid"){
                REQUIRE(m_3.isValid());
            }
            THEN("m_4 should return valid"){
                REQUIRE(m_4.isValid());
            }

            // Infix
            THEN("m_1 should show the same output"){
                REQUIRE(m_1.infixNotation() == "3+7");
            }
            THEN("m_2 should show the same output"){
                REQUIRE(m_2.infixNotation() == "15-4");
            }
            THEN("m_3 should show the same output"){
                REQUIRE(m_3.infixNotation() == "(3*6)*7");
            }
            THEN("m_4 should show the same output"){
                REQUIRE(m_4.infixNotation() == "(6*2)/(3+6)");
            }

            // Postfix
            THEN("m_1 should show correct postfix"){
                REQUIRE(m_1.postfixNotation() == "3 7 +");
            }
            THEN("m_2 should show correct postfix"){
                REQUIRE(m_2.postfixNotation() == "15 4 -");
            }
            THEN("m_3 should show correct postfix"){
                REQUIRE(m_3.postfixNotation() == "3 6 * 7 *");
            }
            THEN("m_4 should show correct postfix"){
                REQUIRE(m_4.postfixNotation() == "6 2 * 3 6 + /");
            }

            // Calculate
            THEN("m_1 should show correct calculation"){
                REQUIRE(m_1.calculate() == 10.0);
            }
            THEN("m_2 should show correct calculation"){
                REQUIRE(m_2.calculate() == 11.0);
            }
            THEN("m_3 should show correct calculation"){
                REQUIRE(m_3.calculate() == 126.0);
            }
            THEN("m_4 should show correct calculation"){
                REQUIRE(m_4.calculate() == 12.0/9);
            }
            AND_WHEN("Changing the expression") {
                m_1 = "1+1";

                THEN("It should show the new expression"){
                    REQUIRE(m_1.infixNotation() == "1+1");
                }
            }
        }
    }
}

// Invalid scenario
SCENARIO("Using invalid strings") {
    GIVEN("Invalid strings for the 4 operands") {
        string expression1 = "1++4";
        string expression2 = "12 5";
        string expression3 = "5??3";
        string expression4 = "Hello";
        WHEN("4 objects are given incorrect values"){
            MathExpression m1(expression1);
            MathExpression m2(expression2);
            MathExpression m3(expression3);
            MathExpression m4(expression4);

            // Valid or not
            THEN("m1 should be invalid"){
                REQUIRE(!m1.isValid());
            }
            THEN("m2 should be invalid"){
                REQUIRE(!m2.isValid());
            }
            THEN("m3 should be invalid"){
                REQUIRE(!m3.isValid());
            }
            THEN("m4 should be invalid"){
                REQUIRE(!m4.isValid());
            }

            // Show error message since it can't calculate anything or postfix it
            THEN("Error message should be written"){
                REQUIRE(!m1.errorMessage().empty());
            }
            THEN("Error message should be written"){
                REQUIRE(!m2.errorMessage().empty());
            }
            THEN("Error message should be written"){
                REQUIRE(!m3.errorMessage().empty());
            }
            THEN("Error message should be written"){
                REQUIRE(!m4.errorMessage().empty());
            }
        }
    }
}
