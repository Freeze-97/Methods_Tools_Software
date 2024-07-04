/*
 * Autor       : Mikael Nilsson
 * Filename    : MathExpression.h
 * Description : Klass för lagring och beräkning av enkla matematiska uttryck.
 *
*/

#ifndef MATHEXPRESSION_H
#define MATHEXPRESSION_H

#include <string>

/**
 * @class MathExpression
 * @details Klass för lagring och beräkning av enkla matematiska uttryck.
 */
class MathExpression
{
public:
    /**
     * Skapar ett MathExpression från en sträng.
     * @test Den ska skapa en MathExpression objekt med string som argument
     */
    MathExpression(const std::string &expression);

    /**
     * Returnerar en sträng som är identisk med den som gavs till konstruktorn.
     * @test Kontrollerar om det blir samma output som input
     */
    std::string infixNotation() const;

    /**
     * @details Returnerar en uttrycket på postfix-from.
     * @test ska returnera postfix på korrekt sätt
     */
    std::string postfixNotation() const;

    /**
     * Beräknar uttrycket och returnerar svaret.
     * @test Ska räkna ut resultatet av uttrycket
     */
    double calculate() const;

    /**
     * Returnerar falskt om uttrycket är ogiltigt.
     * @test Kontrollera om uttrycket är korrekt (matematiskt)
     * @bug Didn't return false for m2 despite having the string "12 5"
     */
    bool isValid() const;

    /**
     * Returnerar ett felmeddelande om uttrycket är ogiltigt.
     * @test Om det är ogiltigt skrivs felmeddelande ut
     * @bug Should return NOT empty() but does not for invalid input "12 5"
     */
    std::string errorMessage() const;

    /**
     * Ersätter befintligt uttryck med expression (nollställer objektet).
     * @test Den ska ersätta ett redan skapat MathExpression objekt
     */
    MathExpression& operator=(const std::string& expression);
private:
    void parseInfix();
    void validate();
    std::string m_infix;
    std::string m_postfix;
    std::string m_errorMsg;
    bool m_valid;
};

#endif // MATHEXPRESSION_H
