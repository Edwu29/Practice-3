/********************************************************************
	Rational  Arithmetic I

	A rational number  is a quotient of two integers.  For example,  12/5,  12/�4,  �3/4, and 4/6 are 
	all rational numbers.  A rational number  is said to be in reduced form if its denominator is 
	positive and its numerator and denominator have no common  divisor other  than  1. For example,  
	the reduced  forms  of the rational numbers  given above  are 12/5,  �3/1, �3/4, and 2/3.

	Write  a class called  Rational with  a constructor Rational(int, int) that  takes  two integers,  
	a numerator and a denominator, and stores those two values in reduced  form in corresponding 
	private  members.  The  class should  have a private  member  function  void reduce() that is used 
	to accomplish  the transformation to reduced form.  The class should have an  overloaded insertion  
	operator << that  will be used  for  output of objects  of the class.



	Rational  Arithmetic II

	Modify the class Rational of Programming Challenge 8 to add overloaded operators  +, -, *, and / to
	be used for addition, subtraction, multiplication, and division. Test the class by reading and
	processing from the keyboard (or from a file) a series of rational expressions  such as
	2 / 3 + 2 / 8
	2 / 3 * � 2 / 8
	2 / 3 � 2/ 8
	2 / 3 / 2 / 8
	To facilitate  parsing  of the input,  you may assume that  numbers  and arithmetic operators
	are separated by whitespace.
*********************************************************************/
#include <iostream>
using namespace std;


class Rational
{
	private:
		int numerator;
		int denominator;
		void reduce();

	public:
		Rational(int, int);
		friend ostream& operator<<(ostream&, Rational*);
		Rational* operator+(Rational);
		Rational* operator*(Rational);
		Rational* operator/(Rational);
		Rational* operator=(Rational*);
};


Rational::Rational(int x, int y)
{
	numerator = x;
	denominator = y;
	reduce();
}

// reduce method
void Rational::reduce()
{
	int high;

	if (numerator > denominator)
	{
		high = numerator;
	}
	else
	{
		high = denominator;
	}

	// Finding a common divisor
	int divisor = 2;

	while (divisor <= high)
	{
		if (numerator%divisor == 0 && denominator%divisor == 0)
		{
			numerator /= divisor;
			denominator /= divisor;
			divisor = 2;
		}
		else
		{
			divisor++;
		}
	}

	if (denominator < 0)
	{
		denominator *= -1;
		numerator *= -1;
	}
}

// output operator overload
ostream &operator<<(ostream& out, Rational* obj)
{
	out << obj->numerator << "/" << obj->denominator << endl;
	return out;
}


// Operator Overload for Adding 
// The Subtraction and other would be done the same  but different arithmetic operations
Rational* Rational::operator+(Rational b)
{
	if (denominator > b.denominator)
	{
		// Finding a common denominator
		if (denominator % b.denominator == 0)
		{
			int num = denominator / b.denominator;

			b.denominator *= num;
			b.numerator *= num;
		}
		else
		{
			int num = denominator;

			denominator *= b.denominator;
			numerator *= b.denominator;
			b.numerator *= num;
		}
	}
	else
	{
		// Finding a common denominator
		if (b.denominator % denominator == 0)
		{
			int num = b.denominator / denominator;

			denominator *= num;
			numerator *= num;
		}
		else
		{
			int num = denominator;

			denominator *= b.denominator;
			numerator *= b.denominator;
			b.numerator *= num;
		}
	}
	numerator += b.numerator;
	reduce();
	return this;
}
// Multiplication
Rational* Rational::operator*(Rational b)
{
	numerator *= b.numerator;
	denominator *= b.denominator;
	reduce();
	return this;
}
// Division
Rational* Rational::operator/(Rational b)
{
	numerator *= b.denominator;
	denominator *= b.numerator;
	reduce();
	return this;
}
// Equal
Rational* Rational::operator=(Rational* b)
{
	numerator = b->numerator;
	denominator = b->denominator;
	return this;
}


int main()
{
	Rational* test;


	int x, y;

	for (int i = 0; i < 5; i++)
	{
		cout << "Enter x and y: ";
		cin >> x >> y;
		test = new Rational(x, y);

		Rational test2(1, 2);
		
		*test + test2;
		cout << test;
		
		cout << "Enter x and y: ";
		cin >> x >> y;
		test = new Rational(x, y);
		*test * test2;
		cout << test;

		cout << "Enter x and y: ";
		cin >> x >> y;
		test = new Rational(x, y);
		Rational * test3;
		test3 = *test / test2;
		cout << test3 << endl;
	}


}
