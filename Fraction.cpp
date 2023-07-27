#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <exception>
#include "Fraction.hpp"

/***
 * Standard constructor
*/
Fraction::Fraction(void) {
	this->numerator = 0;
	this->denominator = 0;
}

/**
 * Double-convert constructor
*/
Fraction::Fraction(double Number) {
	this->convertDoubleToFraction(Number);
}

/**
 * String-convert constructor
*/
Fraction::Fraction(std::string FractionString) {
	this->convertStringToFraction(FractionString);
}
Fraction::Fraction(int Number) {
	this->numerator = Number;
	this->denominator = 1;
}
Fraction::Fraction(int Number1, int Number2){
    this->convertDoubleToFraction(Number1);
    this->convertDoubleToFraction(Number2);
}
/**
 * Standard destructor
*/
Fraction::~Fraction(void) {}

/**
 * Recursive euclidean function for
 * the greatest common divisor
 */
long Fraction::euclidean(long a, long b){
	return b == 0 ? a : this->euclidean(b, a % b);
}

/**
 * Polychat for the numerator
*/
long Fraction::getNumerator(void) {
	return this->numerator;
}

/**
 * Polychat for the denominator
*/
long  Fraction::getDenominator(void) {
	return abs(this->denominator);
}

/**
 * Setter for the numerator
*/
void Fraction::setNumerator(long Numerator) {
	this->numerator = Numerator;
}

/**
 * Setter for the denominator
*/
void Fraction::setDenominator(long Denominator) {
	this->denominator = abs(Denominator);
}

/**
 * Reduce the fraction as low as possible
*/
bool Fraction::reduce(void) {
	long gcd(this->euclidean(this->numerator, this->denominator));

	if (1 < gcd) {
		this->numerator /= gcd;
		this->denominator /= gcd;

		return true;
	} else {
		return false;
	}
}

/**
 * Convert function for double to fraction
 *
 * Count pre-decimal points, multiply the
 * double number with 10 to move the floating point
 * and also the denominator
*/
void Fraction::convertDoubleToFraction(double Number) {
	this->denominator = 1;

	while(((double)(int)Number) != Number) {
		Number = Number * 10;
		this->denominator = this->denominator * 10;
	}

	this->numerator = (long)Number;

	this->reduce();
}

/**
 * Convert function for fraction to double
*/
double Fraction::convertFractionToDouble(void) {
	return (double)this->numerator / abs((double)this->denominator);
}

/**
 * Convert function for string to fraction
 *
 * cut numerator and denominator out of string
*/
bool Fraction::convertStringToFraction(std::string FractionString) {
	std::size_t pos = FractionString.find("/");

	if (pos != std::string::npos) {
		try {
			this->numerator = atol(FractionString.substr(0, pos).c_str());
			this->denominator = atol(FractionString.substr(pos + 1).c_str());
		} catch(...) {
			return false;
		}

		return (this->denominator == 0) ? false : true;
	}

	return false;
}

/**
 * Smaller than operator overloading/
*/
bool operator<(const Fraction& fraction, const Fraction& fraction1) {
	return (fraction1.numerator * fraction.denominator) < (fraction.numerator * fraction1.denominator);
}

/**
 * Smaller than or equal operator overloading
*/
bool operator<=(const Fraction& fraction, const Fraction& fraction1) {
	return (fraction1.numerator * fraction.denominator) <= (fraction.numerator * fraction1.denominator);
}

/**
 * Bigger than operator overloading
*/
bool operator>(const Fraction& fraction, const Fraction& fraction1){
	return (fraction1.numerator * fraction.denominator) > (fraction.numerator * fraction1.denominator);
}

/**
 * Bigger than or equal operator overloading
*/
bool operator>=(const Fraction& fraction, const Fraction& fraction1) {
	return (fraction1.numerator * fraction.denominator) >= (fraction.numerator * fraction1.denominator);
}

/**
 * Equal operator overloading
*/
bool operator==(const Fraction& fraction, const Fraction& fraction1){
	return (fraction1.numerator * fraction.denominator) == (fraction.numerator * fraction1.denominator);
}

/**
 * Non-Equal operator overloading
*/
bool operator!=(const Fraction& fraction, const Fraction& fraction1){
	return (fraction1.numerator * fraction.denominator) != (fraction.numerator * fraction1.denominator);
}

/**
 * Modulos operator overloading (a/b % x/y = (a*y % b*x) / (b*y))
*/
long operator%(const Fraction& fraction, const Fraction& fraction1) {
	long result;

	result = ((fraction1.numerator * fraction.denominator) % (fraction1.denominator * fraction.numerator)) / abs(fraction1.denominator * fraction.denominator);

	return result;
}

/**
 * Double typecast operator overloading
*/
Fraction::operator double() {
	return this->convertFractionToDouble();
}

/**
 * Float typecast operator overloading
*/
Fraction::operator float() {
	return (float)this->convertFractionToDouble();
}

/**
 * Long typecast operator overloading
*/
Fraction::operator long() {
	return (long)this->convertFractionToDouble();
}
Fraction::operator int(){
    return (int)this->convertFractionToDouble();
}
/**
 * Std::string typecast operator overloading
*/
Fraction::operator std::string() {
	std::stringstream output;
	output << this->getNumerator() << "/" << abs(this->denominator);

	return output.str();
}

/**
 * Addition operator overloading
*/
Fraction operator+(const Fraction& fraction, const Fraction& fraction1) {
	Fraction resultFraction;

	if (fraction1.denominator == fraction.denominator) {
		resultFraction.setNumerator(fraction1.numerator + fraction.numerator);
		resultFraction.setDenominator(fraction.denominator);
	} else {
		resultFraction.setNumerator((fraction1.numerator * fraction.denominator) + (fraction.numerator * fraction1.denominator));
		resultFraction.setDenominator(fraction1.denominator * fraction.denominator);
	}

    return resultFraction;
    
}
Fraction operator-(const Fraction& fraction, const Fraction& fraction1) {
	Fraction resultFraction;

	if (fraction1.denominator == fraction.denominator) {
		resultFraction.setNumerator(fraction1.numerator - fraction.numerator);
		resultFraction.setDenominator(fraction.denominator);
	} else {
		resultFraction.setNumerator((fraction1.numerator * fraction.denominator) - (fraction.numerator * fraction1.denominator));
		resultFraction.setDenominator(fraction1.denominator * fraction.denominator);
	}

    return resultFraction;
    
}
Fraction operator*(const Fraction& fraction, const Fraction& fraction1) {
	Fraction resultFraction;

	if (fraction1.denominator == fraction.denominator) {
		resultFraction.setNumerator(fraction1.numerator * fraction.numerator);
		resultFraction.setDenominator(fraction.denominator);
	} else {
		resultFraction.setNumerator((fraction1.numerator * fraction.denominator) * (fraction.numerator * fraction1.denominator));
		resultFraction.setDenominator(fraction1.denominator * fraction.denominator);
	}

    return resultFraction;
    
}
Fraction operator/(const Fraction& fraction, const Fraction& fraction1) {
	Fraction resultFraction;

	if (fraction1.denominator == fraction.denominator) {
		resultFraction.setNumerator(fraction1.numerator / fraction.numerator);
		resultFraction.setDenominator(fraction.denominator);
	} else {
		resultFraction.setNumerator((fraction1.numerator * fraction.denominator) / (fraction.numerator * fraction1.denominator));
		resultFraction.setDenominator(fraction1.denominator * fraction.denominator);
	}

    return resultFraction;
    
}
/**
 * Addition operator overloading with int argument
*/

/*Fraction Fraction::operator+(int number) {
    Fraction result;
    result.numerator = this->numerator + this->denominator * number;
    result.denominator = this->denominator;
    return result;
}*/


/*Fraction Fraction::operator-(int number) {
    Fraction result;
    result.numerator = this->numerator - this->denominator * number;
    result.denominator = this->denominator;
    return result;
}


Fraction Fraction::operator*(int number) {
    Fraction result;
    result.numerator = this->numerator * this->denominator * number;
    result.denominator = this->denominator;
    return result;
}

Fraction Fraction::operator/(int number) {
    Fraction result;
    result.numerator = this->numerator / this->denominator * number;
    result.denominator = this->denominator;
    return result;
}

/**
 * Assignment by Sum operator overloading
*/
Fraction Fraction::operator+=(Fraction fraction) {
	if (this->denominator == fraction.getDenominator()) {
		this->numerator += fraction.getNumerator();
	} else {
		this->numerator = (this->numerator * fraction.getDenominator()) + (fraction.getNumerator() * this->denominator);
		this->denominator *= fraction.getDenominator();
	}

	return *this;
}

/**
 * Subtraction operator overloading
*/
/*Fraction Fraction::operator-(Fraction fraction) {
	Fraction resultFraction;

	if (this->denominator == fraction.denominator) {
		resultFraction.setNumerator(this->numerator - fraction.numerator);
		resultFraction.setDenominator(this->denominator);
	} else {
		resultFraction.setNumerator((this->numerator * fraction.denominator) - (fraction.numerator * this->denominator));
		resultFraction.setDenominator(this->denominator * fraction.denominator);
	}

	return resultFraction;
}

/**
 * Assignment by difference operator overloading
*/
Fraction Fraction::operator-=(Fraction fraction) {
	if (this->denominator == fraction.getDenominator()) {
		this->numerator -= fraction.numerator;
	} else {
		this->numerator = (this->numerator * fraction.getDenominator()) - (fraction.numerator * this->denominator);
		this->denominator *= fraction.getDenominator();
	}

	return *this;
}

/**
 * Multiply operator overloading
*/
/*Fraction Fraction::operator*(Fraction fraction) {
	Fraction resultFraction;

	resultFraction.setNumerator(this->numerator * fraction.getNumerator());
	resultFraction.setDenominator(this->denominator * fraction.getDenominator());

	return resultFraction;
}

/**
 * Multiply Set operator overloading
*/
Fraction Fraction::operator*=(Fraction fraction) {
	this->denominator *= fraction.getDenominator();
	this->numerator *= fraction.getNumerator();

	return *this;
}

/**
 * Division operator overloading
*/
/*Fraction Fraction::operator/(Fraction fraction) {
	Fraction resultFraction;

	resultFraction.setDenominator(this->denominator * fraction.getNumerator());
	resultFraction.setNumerator(this->numerator * fraction.getDenominator());

	return resultFraction;
}

/**
 * Division Set operator overloading
*/
Fraction Fraction::operator/=(Fraction fraction) {
	this->denominator *= fraction.getNumerator();
	this->numerator *= fraction.getDenominator();

	return *this;
}

/**
 * Complement operator overloading
*/
Fraction Fraction::operator~(void) {
	Fraction resultFraction;

	if(this->numerator > this->denominator) {
		return *this;
	} else {
		resultFraction.setNumerator(this->denominator - this->numerator);
		resultFraction.setDenominator(this->denominator);

		return resultFraction;
	}
}

/**
 * Increment operator overloading
*/
Fraction Fraction::operator++(void) {
	this->numerator += 1;

	return *this;
}

/**
 * Decrement operator overloading
*/
Fraction Fraction::operator--(void) {
	this->numerator -= 1;

	return *this;
}

/**
 * Left sdvig operator overloading
*/
std::ostream& operator<<(std::ostream &out, const Fraction &Fraction) {
	out << Fraction.numerator << "/" << Fraction.denominator;

	return out;
}

/**
 * Right sdvig operator overloading
*/
std::istream& operator>>(std::istream &in, const Fraction &Fraction) {
	std::string input;

	in >> input;

	//if (false == Fraction.convertStringToFraction(input)) {
		// Throw own exception object
		//throw FractionInputFailException();
	//}

	return in;
}