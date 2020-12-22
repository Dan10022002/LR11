#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>

void Find_max_element(std::vector <int> Vec, std::vector <int> Block)
{
	int max_element = Vec[0];
	for (int h = 1; h < 5000; h++)
	{
		if (Vec[h] > max_element)
		{
			max_element = Vec[h];
		}
	}
	Block.push_back(max_element);
}

int Find_min_element(std::vector <int> Vec)
{
	int min_element = Vec[0];
	for (int h = 1; h < 5000; h++)
	{
		if (Vec[h] < min_element)
		{
			min_element = Vec[h];
		}
	}
	return min_element;
}

void Initialization(std::vector <int> Vec, std::vector <int> Block, int n)
{
	int low_border = 5000 * n;
	int high_border = 4999 + 5000 * n;
	int counter = 0;
	do
	{
		Block[counter] = Vec[low_border];
		low_border += 1;
		counter += 1;
	} while (low_border != high_border);
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
	std::vector<std::vector<int>> Block(20, std::vector<int>(5000)); //вектор 20 интовых блоков размером 5000
	std::vector <int> Block_rez;
	auto start = std::chrono::system_clock::now();
	for (int h = 0; h < 20; h++)
	{
		std::vector <int> Block_time;
		Initialization(Vec, Block_time, h);
		Block.push_back(Block_time);
	}
	std::vector <std::thread> Thread(20); //вектор 20 потоков
	for (int h = 0; h < 20; h++)
	{
		std::thread Thread_time(Find_max_element, Block[h], Block_rez);
	}
	for (int h = 0; h < 20; h++)
	{
		Thread[h].join();
	}
	int rezult = Find_min_element(Block_rez);
	auto end = std::chrono::system_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	std::cout << "The result is " << rezult << "\n";
	std::cout << "The working time of the program is " << time.count() << " nanoseconds." << '\n';
}
