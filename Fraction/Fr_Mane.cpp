#include"Fraction.h"

int main()
{
	Fraction fr1(1, 4);
	std::cout << "Fr1 = " << fr1.printFract() << std::endl;
	Fraction fr2(5, 6);
	std::cout << "Fr2 = " << fr2.printFract() << std::endl;

	Fraction answer(1,1);
	answer = fr1 + fr2;
	std::cout << "Fr1 + Fr2 = " << answer.printFract() << std::endl;
	answer = fr1 - fr2;
	std::cout << "Fr1 - Fr2 = " << answer.printFract() << std::endl;
	answer = fr1 * fr2;
	std::cout << "Fr1 * Fr2 = " << answer.printFract() << std::endl;
	answer = fr1 / fr2;
	std::cout << "Fr1 / Fr2 = " << answer.printFract() << std::endl;

	bool isTrue = fr1 < fr2;
	std::cout << "Fr1 < Fr2 : ";
	if(isTrue)
	{
		std::cout << "True";
	}
	else
	{
		std::cout << "False";
	}

	isTrue = fr1 > fr2;
	std::cout << std::endl;
	std::cout<< "Fr1 > Fr2 : ";
	if (isTrue)
	{
		std::cout << "True";
	}
	else
	{
		std::cout << "False";
	}

	std::cin.get();
	return 0;
}