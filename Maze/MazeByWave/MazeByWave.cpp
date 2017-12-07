#include<iostream>

char s[6][8] = 
{ 
	"..x...x",
	"x.....x",
	"..xxx.x",
	"xxx...x",
	".....xx",
	"xxx...." };


int main() {
	int p[6][7];
	for (int i = 0; i < 6; i++) 
	{
		for (int j = 0; j < 7; j++) 
		{
			p[i][j] = -1;
		}
	}
	int len = 0;
	p[0][0] = 0;
	while (p[5][6] == -1) 
	{
		for (int i = 0; i < 6; i++) 
		{
			for (int j = 0; j < 7; j++) 
			{
				if (p[i][j] == len) 
				{
					if (s[i + 1][j] != 'x' && p[i + 1][j] == -1 && i != 5) 
					{
						p[i + 1][j] = len + 1;
					}
					if (s[i][j + 1] != 'x' && p[i][j + 1] == -1 && j != 6) 
					{
						p[i][j + 1] = len + 1;
					}
					if (s[i - 1][j] != 'x' && p[i - 1][j] == -1 && i != 0) 
					{
						p[i - 1][j] = len + 1;
					}
					if (s[i][j - 1] != 'x' && p[i][j - 1] == -1 && j != 0) 
					{
						p[i][j - 1] = len + 1;
					}
				}
			}
		}
		len++;
	}
	std::cout<<"The min way is "<< len<<std::endl;

	int x = 5;
	int y = 6;
	s[5][6] = '*';
	for (int i = len; i > 0; i--) 
	{
		if (p[y - 1][x] == len - 1) 
		{
			s[y - 1][x] = '*';
			y = y - 1;
			len--;
			continue;
		}
		if (p[y][x - 1] == len - 1) 
		{
			s[y][x - 1] = '*';
			x = x - 1;
			len--;
			continue;
		}
		if (p[y + 1][x] == len - 1) 
		{
			s[y + 1][x] = '*';
			y = y + 1;
			len--;
			continue;
		}
		if (p[y][x + 1] == len - 1) 
		{
			s[y][x + 1] = '*';
			x = x + 1;
			len--;
			continue;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++) 
		{
			std::cout << s[i][j];
		}
		std::cout << std::endl;
	}
	
	std::cin.get();
	return 0;
}