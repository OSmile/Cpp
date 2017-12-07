#include"Header.h"

int main()
{

	Head a1;
	std::cout << std::endl;

	Head a2(a1);
	std::cout << std::endl;

	Head a3(std::move(Head()));
	std::cout << std::endl;

	a1 = a3;
	std::cout << std::endl;

	a1 = Head();
	std::cout << std::endl;

	a1 = std::move(a3);

	std::cin.get();
	return 0;
}