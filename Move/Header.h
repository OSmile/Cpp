#ifndef HEADER_H
#define HEADER_H
#include<iostream>

class Head
{
private:
	int a;
public:
	Head();
	Head(const Head& num);
	Head(Head&& num);
	const Head& operator=(const Head& num);
	Head& operator=(Head&& num);
	~Head();

};

#endif // !HEADER_H
