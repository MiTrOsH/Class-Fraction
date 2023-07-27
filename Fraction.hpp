#ifndef FRACTION_HPP
#define FRACTION_HPP

/**
 * Fraction class
 */
class Fraction {
	private:
		// Fraction parts
		long numerator, denominator;
		// Euclidean algorithm for greatest common divisor
		long euclidean(long a, long b);
				
		bool reduce();
		void convertDoubleToFraction(double Number);
		double convertFractionToDouble(void);
		bool convertStringToFraction(std::string FractionString);
	public:
		// Constructors
		Fraction();
		explicit Fraction(double Number);
		explicit Fraction(std::string FractionString);
		Fraction(int);
		Fraction(int, int);
		// Destructur
		~Fraction();
		
		// Fraction functions
		
		
		//void convertIntToFraction(int Number);

		// Getter and Setter //?
		long getNumerator();
		long getDenominator();
		void setNumerator(long Numerator);
		void setDenominator(long Denominator);



		// Operator overloading functions
		friend bool operator<(const Fraction& fraction, const Fraction& fraction1);
		friend bool operator<=(const Fraction& fraction, const Fraction& fraction1);
		friend bool operator>(const Fraction& fraction, const Fraction& fraction1);
		friend bool operator>=(const Fraction& fraction, const Fraction& fraction1);
		friend bool operator==(const Fraction& fraction, const Fraction& fraction1);
		friend bool operator!=(const Fraction& fraction, const Fraction& fraction1);
		friend long operator%(const Fraction& fraction, const Fraction& fraction1);
		explicit operator double();
		explicit operator float();
		explicit operator long();
		explicit operator std::string();
        explicit operator int();
		friend Fraction operator+(const Fraction& fraction, const Fraction& fraction1);
		friend Fraction operator-(const Fraction& fraction, const Fraction& fraction1);
		friend Fraction operator*(const Fraction& fraction, const Fraction& fraction1);
		friend Fraction operator/(const Fraction& fraction, const Fraction& fraction1);
		//Fraction& operator+(int number);
        //Fraction& operator-(int number);
        //Fraction& operator*(int number);
        //Fraction& operator/(int number);
		//Fraction operator+(Fraction int);
		//Fraction operator+(int, fraction);
		Fraction operator+=(Fraction fraction);
		Fraction operator-=(Fraction fraction);
		//Fraction operator-();
		//Fraction operator-(int fraction);
		//Fraction& operator*(const Fraction fraction);
		//Fraction operator*();
		//Fraction operator*(int fraction);
		Fraction operator*=(Fraction fraction);
		//Fraction& operator/(const Fraction fraction);
		//Fraction operator/(int fraction);
		//Fraction operator/();
		Fraction operator/=(Fraction fraction);
		Fraction operator~(void);
		Fraction operator++(void);
		Fraction operator--(void);
	//	friend std::ostream &operator<<(std::ostream &os, const Fraction &Fraction);
		/** Left Shift Operator overloading functions (need to be declared global) */
//std::ostream& operator<<(std::ostream &out, Fraction &Fraction);
/** Right Shift Operator overloading functions (need to be declared global) */
//std::istream& operator>>(std::istream &in, Fraction &Fraction);

    /** Left Shift Operator overloading functions (need to be declared global) */
friend std::ostream& operator<<(std::ostream &out, const Fraction &Fraction);
/** Right Shift Operator overloading functions (need to be declared global) */
friend std::istream& operator>>(std::istream &in, const Fraction &Fraction);
};


/**
 * FractionInputFailException class
 *
 * Exception object extending the c++ standard exceptions
 * Thrown exception can be handled like standard exceptions
*/
class FractionInputFailException: public std::exception {
	public: virtual const char* what() const throw() { return "Incorrect Input"; }
};



#endif