#include<iostream>

int a[] = { 10 ,9,9,9,9,99,9,9,9,9,9,9,9,9,0,1,2,1,0,2,1,1 };


void chooseMax() {
	int r = 0;
	int m = sizeof(a) / sizeof(int);
	for (int i = 0; i < m - 1; i++) {
		for (int i = 0; i < m - 1 - r; i++) {
			if (a[i] > a[i + 1]) {
				int k = a[i + 1];
				a[i + 1] = a[i];
				a[i] = k;
			}
		}
		r++;
	}
	for (int i = 0; i < m; i++) {
		std::cout << a[i] << std::endl;
	}

}

int main() {
	chooseMax();
	std::cin.get();
	return 0;
}