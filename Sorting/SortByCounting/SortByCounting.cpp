#include<iostream>

int a[] = { 10 ,9,9,9,9,99,9,9,9,9,9,9,9,9,0,1,2,1,0,2,1,1 };
int m = sizeof(a) / sizeof(int);

int max()
{
	int r = 0;
	for (int i = 0; i < m; i++)
	{
		if (a[i] > r)
			r = a[i];
	}
	return r + 1;
}

void counting()
{
	int *e = new int[max()];
	int k = 0;

	int *b = new int[m];
	for (int i = 0; i < max(); i++)
	{
		e[i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		e[a[i]]++;
	}


	for (int i = 0; i < max(); i++)
	{
		for (int j = 0; j < e[i]; j++)
		{
			b[k] = i;
			k++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		std::cout << b[i] << std::endl;
	}

}

int main()
{
	counting();
	std::cin.get();
	return 0;
}
