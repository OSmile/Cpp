#include"Header.h"

Head::Head()
{
	std::cout << "Default constr" << std::endl;
	a = 0;
}

Head::Head(const Head& num)
{
	std::cout << "Head(const Head& num) //Copy constr by using lvalue" << std::endl;
	a = num.a;
}

Head::Head(Head&& num)
{
	std::cout << "Head(Head&& num) //By using rvalue" << std::endl;
	a = std::move(num.a);
}

const Head & Head::operator=(const Head& num)
{
	std::cout << "Assignment by lvalue" << std::endl;
	if (this != &num)
	{
		a = num.a;
	}
	return *this;
}

Head & Head::operator=(Head && num)
{
	std::cout << "Assignment by rvalue" << std::endl;

	if (this != &num)
	{
		a = std::move(num.a);
	}
	return *this;
}

Head::~Head()
{
	std::cout << "Destructor" << std::endl;
}