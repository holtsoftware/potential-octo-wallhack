#include <iostream.h>

class Complex
{
private:
	double real;
	double imaginary;
public:
	Complex();
	Complex(double,double);

	double get_real();
	double get_imaginary();

	void set_real(double);
	void set_imaginary(double);

	void input();
	void output() const;

	friend Complex operator+(const Complex&,const Complex&);
	friend Complex operator-(const Complex&,const Complex&);

	friend istream & operator>>(istream &,Complex&);
	friend ostream & operator<<(ostream &,const Complex&);
};

Complex::Complex()
{
	real=0;
	imaginary=0;
}

Complex::Complex(double r,double i)
{
	real=r;
	imaginary=i;
}

double Complex::get_real()
{
	return real;
}

double Complex::get_imaginary()
{
	return imaginary;
}

void Complex::set_imaginary(double i)
{
	imaginary=i;
}

void Complex::set_real(double r)
{
	real=r;
}

void Complex::input() 
{
	cout<<"Enter real portion:"<<endl;
	cin>>real;
	cout<<"Enter imaginary portion:"<<endl;
	cin>>imaginary;
}

void Complex::output() const
{
	cout<<real<<" + "<<imaginary<<"i";
}

istream & operator>>(istream &ins,Complex &com)
{
	cout<<"Enter real portion:"<<endl;
	ins>>com.real;
	cout<<"Enter imaginary portion:"<<endl;
	ins>>com.imaginary;
	return ins;
}

ostream & operator<<(ostream &outs,const Complex &com)
{
	outs<<com.real<<" + "<<com.imaginary<<"i";
	return outs;
}

Complex operator+(const Complex& num1,const Complex& num2)
{
	Complex result;

	result.real=num1.real+num2.real;
	result.imaginary=num1.imaginary+num2.imaginary;
	return result;
}

Complex operator-(const Complex& num1,const Complex& num2)
{
	Complex result;

	result.real=num1.real-num2.real;
	result.imaginary=num1.imaginary-num2.imaginary;
	return result;
}


void main()
{
	Complex c1,c2(55,-37);

	cout<<"At instantiation c1: "<<c1<<" C2:"<<c2<<endl;
	c1.set_real(10);
	c1.set_imaginary(-22);

	cout<<"After seting C1 to 10 - 22i, c1 contains: "<<c1<<endl;
	cout<<"The Real Part of c2 is: "<<c2.get_real()<<endl
		<<"The imaginary part of c2 is: "<<c2.get_imaginary()<<endl;

	c2.input();

	cout<<"\nThe new values for c2 are"<<endl;
	c2.output();

	cout<<"The Sum of "<<c1<<" and "<<c2<<" is "<<c1+c2<<endl;

	cout<<"The Difference "<<c1<<" - "<<c2<<" is " <<c1-c2<<endl;
}