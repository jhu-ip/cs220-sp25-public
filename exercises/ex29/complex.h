#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

/**
 * Operator overloading
 *
 * This exercise practises operator overloading by implementing
 * a Complex number class. You will be writting all the necessary
 * operator overloading to make the class works perfectly.
 *
 * Look at the files provided:
 * complex.h
 * complex.cpp
 * main.cpp
 *
 * Real all the comments and implement the missing parts
 * highlighted with "TODO"
 *
 * Also provided is a Makefile to make it easier to
 * build the driving function. The target is called main
 */

class Complex {
  public:
    // A default constructor set both real and imaginary part to 0
    Complex() : rel(0), img(0) {}

    // A non-default constructor that accept values as input for initial values
    Complex(float r, float i) : rel(r), img(i) {}

    // Part 2
    // TODO: Implement and overload operator<< with friend to print out a complex number
    // For example std::cout << c << std::endl; should print out something like a + bi

    // Part 3
    // TODO: write a copy constructor
    Complex(const Complex& rhs);

    // TODO: overload assignment operator
    Complex& operator=(const Complex& rhs);

    // TODO: overload the add operator
    Complex operator+(const Complex& rhs) const;

    // TODO: overload the minus operator
    Complex operator-(const Complex& rhs) const;

    // TODO: overload the times operator
    Complex operator*(const Complex& rhs) const;

    // TODO: overload the times operator for float
    Complex operator*(const float& rhs) const;

    // TODO: overload the divide operator
    Complex operator/(const Complex& rhs) const;

    // Part 4
    // TODO: non-member function operator overload for float times complex using friend

  private:
    float rel, img; // real and imaginary part of a complex number
};

#endif // COMPLEX_H
