#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

int Find_max_element(std::vector <int>& Vec, int low_border, int high_border)
{
	int max_element = Vec[low_border];
	low_border += 1;
	while (low_border != (high_border + 1))
	{
	    if (Vec[low_border] > max_element)
		{
			max_element = Vec[low_border];
		}
		low_border += 1;
	}
	return max_element;
}

int Find_min_element(std::vector <int>& Vec)
{
	int min_element = Vec[0];
	for (int h = 1; h < 10; h++)
	{
		if (Vec[h] < min_element)
		{
			min_element = Vec[h];
		}
	}
	return min_element;
}

int main()
{
	std::srand(std::time(nullptr));
	std::vector <int> Vec;
	for (int h = 0; h < 1000000; h++)
	{
		int m = std::rand();
		Vec.push_back(m);
	}

	std::vector <int> Block_rez; //конечный блок из 10 элементов
	auto start = std::chrono::system_clock::now();
	for (int h = 0; h < 10; h++)
	{
		Block_rez.push_back(Find_max_element(Vec, 100000*h, 99999 + 100000 * h));
	}
	int rezult = Find_min_element(Block_rez);
	auto end = std::chrono::system_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	std::cout << "The result is " << rezult << "\n";
	std::cout << "The working time of the program is " << time.count() << " nanoseconds." << '\n';
}
