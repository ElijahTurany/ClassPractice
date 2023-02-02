#pragma once
#include <string>
//Make a Fraction class
class Fraction {
	//Fields - "member variables"
private:
	int numerator;
	int denominator;
	//Constuctor
public:
	Fraction() {
		numerator = 5;
		denominator = 2;
	}
	Fraction(int n, int denominator) {
		numerator = n;
		this->denominator = denominator; //use this to disambiguate
	}
	//Method - "member functions"
	//getters "accessors"
	int getNumerator() { return numerator; }
	int getDenominator() { return denominator; }
	//setters "mutators"
	void setNumerator(int newNum) {
		numerator = newNum;
	}
	void setDenominator(int d) {
		if (d > 0) {
			denominator = d;
		}
	}
	//Method to return a string version for display
	std::string print() {
		//NO COUT IN HERE
		std::string s = std::to_string(numerator) + "/"
			+ std::to_string(denominator);
		return s;
	}
	//Method to return a double version of the fraction
	double getValue() {
		// double n = static_cast<double>(numerator);
		// double d = static_cast<double>(denominator);
		// return n / d;
		return 1.0 * numerator / denominator;
	}

	Fraction operator*(const Fraction& other) {
		return Fraction{ this->numerator * other.numerator, this->denominator * other.denominator };
	}

	Fraction operator/(const Fraction& other) {
		return Fraction{ this->numerator * other.denominator, this->denominator * other.numerator };
	}

	Fraction operator+(const Fraction& other) {
		return Fraction{ (this->numerator * other.denominator) + (this->denominator * other.numerator), this->denominator * other.denominator };
	}

	Fraction operator-(const Fraction& other) {
		return Fraction{ (this->numerator * other.denominator) - (this->denominator * other.numerator), this->denominator * other.denominator };
	}
};