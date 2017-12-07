#include<iostream>
#include<fstream>
#include<string>


struct Tree
{
	int field;
	std::string name;
	int thief;
	struct Tree *left;
	struct Tree *right;
};

Tree *tree = NULL;

void push(int i, std::string ne, int tf, Tree **t)
{
	if ((*t) == NULL)
	{
		(*t) = new Tree;
		(*t)->field = i;
		(*t)->name = ne; //name
		(*t)->thief = tf; //thief
		(*t)->left = (*t)->right = NULL;
		return;
	}
	if (i > (*t)->field && i!=(*t)->field) push(i, ne, tf, &(*t)->right);
	else
	{
		if (i < (*t)->field && i != (*t)->field)
			push(i, ne, tf, &(*t)->left);
	}
}


void print(Tree *t, int q)
{
	if (t == NULL)
		return;
	else 
	{
		print(t->left, ++q);
		for (int i = 0; i < q; ++i)
		{
			std::cout << "|";
		}
		std::cout << t->field << " " << t->name <<" " << t->thief << std::endl;
		q--;
	}
	print(t->right, ++q);
}

void find(int i, Tree *t)
{
	if (t == NULL)
		std::cout << "Your tree is NULL" << std::endl;
	if (t->field == i)
	{
		std::cout << i << " " << t->name << " " << t->thief<< std::endl;
		if (t->thief == 0)
			std::cout << "It isn't a thief!" << std::endl;
		else
			std::cout << "It is a thief! Look out!" << std::endl;
	}
	if (i <= t->field)
	{
		if (t->left != NULL)
			return find(i, t->left);
	}
	else {
		if (t->right)
		{
			return find(i, t->right);
		}
	}

}

void findThief(int id, std::string s)
{
	std::ifstream file(s, std::ios::in);
	int number;
	std::string name;
	int thief;
	find(id, tree);
}

int main()
{
	std::string str;
	std::ifstream file("indus.txt", std::ios::in);
	int number;
	std::string name;
	int thief;
	while (!file.eof())
	{
		file >> number;
		file >> name;
		file >> thief;
		push(number, name, thief, &tree);
	}
	file.close();
	std::cout << "Do you want to find a chief?" << std::endl;
	std::cout << "Y or N" << std::endl;
	char ans;
	std::cin >> ans;
	switch (ans)
	{
		case 'Y': 
		{
			std::cout << "Write your id: ";
			int choise;
			std::cin >> choise;
			findThief(choise, "indus.txt");
			break;
		}
		case 'N':
			break;
	}
	std::cin.get();
    return 0;
}

