#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

int Find_max_element(std::vector <int> Vec)
{
	int max_element = Vec[0];
	for (int h = 1; h < Vec.size(); h++)
	{
		if (Vec[h] > max_element)
		{
			max_element = Vec[h];
		}
	}
	return max_element;
}

int Find_min_element(std::vector <int> Vec)
{
	int min_element = Vec[0];
	for (int h = 1; h < Vec.size(); h++)
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
	for (int h = 0; h < 100000; h++)
	{
		int m = std::rand();
		Vec.push_back(m);
	}
	std::vector <int> Block1(5000); //всего будет 20 блоков по 5000 элементов
	std::vector <int> Block2; //конечный блок из 20 элементов
	auto start = std::chrono::system_clock::now();
	for (int h = 0; h < 100000; h++)
	{
		if (h % 5000 == 4999)
		{
			Block1[h % 5000] = Vec[h];
			Block2.push_back(Find_max_element(Block1));
		}
		else
		{
			Block1[h % 5000] = Vec[h];
		}
	}
	int rezult = Find_min_element(Block2);
	auto end = std::chrono::system_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	std::cout << "The result is " << rezult << "\n";
	std::cout << "The working time of the program is " << time.count() << " nanoseconds." << '\n';
	
}
