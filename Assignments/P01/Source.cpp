/*****************************************************************************
*
*  Author:           Ronald Cooper Ricketts
*  Email:            rcricketts1222@my.msutexas.edu
*  Label:            P01
*  Title:            Fraction Class
*  Course:           CMPS 2143
*  Semester:         2024 Fall I
*
*  Description:
*        This program reads fraction operations from a file and performs
*        arithmetic operations such as addition, subtraction, multiplication,
*        and division on the fractions. It then prints the results to the console.
*
*  Usage:
*        Compile and run the program. The input is read from "data.txt", which
*        contains fraction operations in the format "1/2 + 3/4". The program
*        outputs the result of the operation for each line.
*
*  Files:            main.cpp, data.txt
*****************************************************************************/

/**
 * Class Fraction
 *
 * Description:
 *      The Fraction class represents a fraction with a numerator and denominator.
 *      It includes operations such as addition, subtraction, multiplication,
 *      and division of fractions using overloaded operators.
 *
 * Public Methods:
 *      - Fraction(int num, int den)
 *      - Fraction operator+(const Fraction& other)
 *      - Fraction operator-(const Fraction& other)
 *      - Fraction operator*(const Fraction& other)
 *      - Fraction operator/(const Fraction& other)
 *      - bool operator==(const Fraction& other) const
 *      - friend std::ostream& operator<<(std::ostream& os, const Fraction& frac)
 *      - int lcd(int a, int b)
 *      - int lcm(int a, int b)
 *
 * Private Methods:
 *      - None
 *
 * Usage:
 *      Fraction frac1(1, 2);
 *      Fraction frac2(3, 4);
 *      Fraction result = frac1 + frac2;
 *      std::cout << result << std::endl;
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    /**
     * Public : Fraction
     *
     * Description:
     *      Constructor to initialize a fraction with a given numerator and
     *      denominator. If the denominator is zero, it sets it to 1.
     *
     * Params:
     *      - int num : numerator of the fraction
     *      - int den : denominator of the fraction
     *
     * Returns:
     *      None
     */
    Fraction(int num, int den) {
        numerator = num;
        if (den == 0) {
            cout << "Denominator cannot be zero. Setting denominator to 1." << endl;
            denominator = 1;
        }
        else {
            denominator = den;
        }
    }

    /**
     * Public : operator+
     *
     * Description:
     *      Overloads the addition operator to add two fractions.
     *
     * Params:
     *      - const Fraction& other : fraction to be added
     *
     * Returns:
     *      Fraction : result of the addition
     */
    Fraction operator+(const Fraction& other) {
        int commondenominator = lcd(denominator, other.denominator);

        int new_num1 = numerator * (commondenominator / denominator);
        int new_num2 = other.numerator * (commondenominator / other.denominator);

        int result_num = new_num1 + new_num2;

        return Fraction(result_num, commondenominator);
    }

    /**
     * Public : operator-
     *
     * Description:
     *      Overloads the subtraction operator to subtract two fractions.
     *
     * Params:
     *      - const Fraction& other : fraction to be subtracted
     *
     * Returns:
     *      Fraction : result of the subtraction
     */
    Fraction operator-(const Fraction& other) {
        int commondenominator = lcd(denominator, other.denominator);

        int new_num1 = numerator * (commondenominator / denominator);
        int new_num2 = other.numerator * (commondenominator / other.denominator);

        int result_num = new_num1 - new_num2;

        return Fraction(result_num, commondenominator);
    }

    /**
     * Public : operator*
     *
     * Description:
     *      Overloads the multiplication operator to multiply two fractions.
     *
     * Params:
     *      - const Fraction& other : fraction to be multiplied
     *
     * Returns:
     *      Fraction : result of the multiplication
     */
    Fraction operator*(const Fraction& other) {
        int new_num = numerator * other.numerator;

        int new_den = denominator * other.denominator;

        return Fraction(new_num, new_den);
    }

    /**
     * Public : operator/
     *
     * Description:
     *      Overloads the division operator to divide two fractions.
     *
     * Params:
     *      - const Fraction& other : fraction to divide by
     *
     * Returns:
     *      Fraction : result of the division
     */
    Fraction operator/(const Fraction& other) {
        int new_num = numerator * other.denominator;

        int new_den = denominator * other.numerator;

        return Fraction(new_num, new_den);
    }

    /**
     * Public : operator==
     *
     * Description:
     *      Overloads the equality operator to compare two fractions.
     *
     * Params:
     *      - const Fraction& other : fraction to compare with
     *
     * Returns:
     *      bool : true if the fractions are equal, otherwise false
     */
    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    /**
     * Public : operator<<
     *
     * Description:
     *      Overloads the stream insertion operator to output a fraction.
     *
     * Params:
     *      - std::ostream& os : output stream
     *      - const Fraction& frac : fraction to output
     *
     * Returns:
     *      std::ostream& : output stream with fraction
     */
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;

        return os;
    }

    /**
     * Public : lcd
     *
     * Description:
     *      Calculates the least common denominator (LCD) between two integers.
     *
     * Params:
     *      - int a : first integer
     *      - int b : second integer
     *
     * Returns:
     *      int : the LCD of the two integers
     */
    int lcd(int a, int b) {
        return lcm(a, b);
    }

    /**
     * Public : lcm
     *
     * Description:
     *      Calculates the least common multiple (LCM) between two integers.
     *
     * Params:
     *      - int a : first integer
     *      - int b : second integer
     *
     * Returns:
     *      int : the LCM of the two integers
     */
    int lcm(int a, int b) {
        int max = (a > b) ? a : b;
        while (max % a != 0 || max % b != 0) {
            ++max;
        }
        return max;
    }
};

/**
 * Function parseFraction
 *
 * Description:
 *      Parses a string representation of a fraction in the format "x/y"
 *      and returns a Fraction object.
 *
 * Params:
 *      - const string& str : string representing the fraction
 *
 * Returns:
 *      Fraction : the parsed fraction
 */
Fraction parseFraction(const string& str) {
    stringstream ss(str);
    int numerator, denominator;
    char slash;

    ss >> numerator >> slash >> denominator;

    return Fraction(numerator, denominator);
}

/**
 * Function main
 *
 * Description:
 *      Reads fraction operations from a file and performs the corresponding
 *      arithmetic operations (addition, subtraction, multiplication, division).
 *      The results are printed to the console.
 *
 * Params:
 *      None
 *
 * Returns:
 *      int : exit status of the program
 */
int main() {
    ifstream file("data.txt");

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (std::getline(file, line)) {
        stringstream ss(line);
        string frac1_str, frac2_str, op;
        ss >> frac1_str >> op >> frac2_str;

        Fraction frac1 = parseFraction(frac1_str);
        Fraction frac2 = parseFraction(frac2_str);
        Fraction result(0, 1);

        if (op == "+") {
            result = frac1 + frac2;
        }
        else if (op == "-") {
            result = frac1 - frac2;
        }
        else if (op == "*") {
            result = frac1 * frac2;
        }
        else if (op == "/") {
            result = frac1 / frac2;
        }
        else {
            cout << "Unknown operator: " << op << endl;
            continue;
        }

        cout << frac1_str << " " << op << " " << frac2_str << " = " << result << endl;
    }

    file.close();
    return 0;
}
