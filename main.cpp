#include <iostream>
#include "Fraction.hpp"
using namespace std;

int main() {
    // Test constructors
    Fraction frac1;
    Fraction frac2(0.5);
    Fraction frac3("1/2");

    // Test getters and setters
    frac1.setNumerator(1);
    frac1.setDenominator(2);
    std::cout << "Fraction 1: " << frac1.getNumerator() << "/" << frac1.getDenominator() << std::endl;

    // Test reduce
    //frac1.reduce();
    std::cout << "Reduced Fraction 1: " << frac1.getNumerator() << "/" << frac1.getDenominator() << std::endl;

    // Test comparison operators
    std::cout << "Fraction 1 < Fraction 2: " << (frac1 < frac2) << std::endl;
    std::cout << "Fraction 1 <= Fraction 2: " << (frac1 <= frac2) << std::endl;
    std::cout << "Fraction 1 > Fraction 2: " << (frac1 > frac2) << std::endl;
    std::cout << "Fraction 1 >= Fraction 2: " << (frac1 >= frac2) << std::endl;
    std::cout << "Fraction 1 == Fraction 2: " << (frac1 == frac2) << std::endl;
    std::cout << "Fraction 1 != Fraction 2: " << (frac1 != frac2) << std::endl;

    // Test arithmetic operators
    Fraction frac4 = frac1 + frac2;
    std::cout<<frac4<<std::endl;
    std::cout << "Fraction 1 + Fraction 2: " << frac4.getNumerator() << "/" << frac4.getDenominator() << std::endl;
    Fraction frac5 = frac1 - frac2;
    std::cout << "Fraction 1 - Fraction 2: " << frac5.getNumerator() << "/" << frac5.getDenominator() << std::endl;
    Fraction frac6 = frac1 * frac2;
    std::cout << "Fraction 1 * Fraction 2: " << frac6.getNumerator() << "/" << frac6.getDenominator() << std::endl;
    Fraction frac7 = frac1 / frac2;
    std::cout << "Fraction 1 / Fraction 2: " << frac7.getNumerator() << "/" << frac7.getDenominator() << std::endl;

    // Test assignment operators
    frac1 += frac2;
    frac1 -= frac2;
    frac1 *= frac2;
    frac1 /= frac2;

    std::cout << "After addition with assignment: " << frac1 << std::endl;
    std::cout << "After subtraction with assignment: " << frac1 << std::endl;
    std::cout << "After multiplication with assignment: " << frac1 << std::endl;
    std::cout << "After division with assignment: " << frac1 << std::endl;

    // Test comparison operators
    std::cout << "Less than: " << (frac1 < frac2) << std::endl;
    std::cout << "Less than or equal: " << (frac1 <= frac2) << std::endl;
    std::cout << "Greater than: " << (frac1 > frac2) << std::endl;
    std::cout << "Greater than or equal: " << (frac1 >= frac2) << std::endl;
    std::cout << "Equal: " << (frac1 == frac2) << std::endl;
    std::cout << "Not equal: " << (frac1 != frac2) << std::endl;

    // Test conversion functions
    Fraction frac8("5/-3");
    double doubleValue = static_cast<double>(frac8);
    std::string stringValue = static_cast<std::string>(frac8);

    std::cout << "Double value: " << doubleValue << std::endl;
    std::cout << "String value: " << stringValue << std::endl;
    
    Fraction a("2/3");
    Fraction b("2/-3");
    Fraction c = a+b;
    std::cout << (c) << "\n";
     c = a-b;
    std::cout << (c) << "\n";
     c = a*b;
    std::cout << (c) << "\n";
     c = a/b;
    std::cout << (c) << "\n";
     c = a+1;
    std::cout << (c) << "\n";
     c = a-1;
    std::cout << (c) << "\n";
     c = a*1;
    std::cout << (c) << "\n";
     c = a/1;
    std::cout << (c) << "\n";

    const Fraction cb(1,3);
    std::cout << "4/1 = " << 1+cb << "\n";
    std::cout << std::boolalpha;
    std::cout << "false " << (1<cb) << "\n";
    c = 1+b;
    std::cout << (c) << "\n";
     c = 1-b;
    std::cout << (c) << "\n";
     c = 1*b;
    std::cout << (c) << "\n";
     c = 1/b;
    std::cout << (c) << "\n";
    
    
return 0;
}