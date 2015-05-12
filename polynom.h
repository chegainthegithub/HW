#include <iostream>

using namespace std;

template <typename Type>
class polynom
{
public:
	Type* polynomCoefficients;
	int polynomDegree;
	polynom()
	{
		
	}
	polynom(unsigned int degree)
	{
		polynomDegree = degree;
		/*delete polynomCoefficients;*/
		Type *polynomCoefficients = new Type [degree];
		for (int i = 0 ; i < polynomDegree; i++)
			cin >> polynomCoefficients[i];
	}
	void sum(Type *incomePoly)
	{
		if (incomePoly->PolynomDegree > PolynomDegree)
		{
			for (int i = 0 ; i < incomePoly->PolynomDegree;i++)	
			{
				incomePoly->polynomCoefficients[i]+= polynomCoefficients[i];
     		}
			delete polynomCoefficients;
			Type *polynomCoefficients = new Type [incomePoly->PolynomDegree];
			polynomCoefficients = incomePoly->polynomCoefficients;
		}
		else
			for (int i = 0 ; i < PolynomDegree;i++)	
			{
				polynomCoefficients[i] += incomePoly->polynomCoefficients[i];
     		}
	}
	void show()
	{
		for (int i = 0; i < polynomDegree;i++)
			cout << polynomCoefficients[i] << "x^" << i << endl;
	}
	void minus(Type incomePoly);
	void prod(Type IncomePoly);
	void mod(Type incomePoly);

};
