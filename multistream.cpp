#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex mu;

void Find_max_element(std::vector <int>& Vec, int low_border, int high_border, std::vector <int>& Block)
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
	mu.lock();
    std::cout << "Thread id = " <<std::this_thread::get_id() << " max element: " << max_element << "\n";
    mu.unlock();
    Block.push_back(max_element);
	
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
	for (int h = 0; h < 1000000; h++)
	{
		int m = std::rand();
		Vec.push_back(m);
	}
	std::vector <int> Block_rez;
	std::cout << "Enter the number of the threads: ";
	unsigned int n;
	std::cin >> n;
	int elements_in_thread = 1000000/n;
	auto start = std::chrono::system_clock::now();
	std::vector <std::thread> Thread(n);
	for (int h = 0; h < n; h++)
	{
		Thread[h] = std::thread (Find_max_element, std::ref(Vec), elements_in_thread*h, (elements_in_thread - 1) + elements_in_thread * h, std::ref(Block_rez));
	}
	for (int h = 0; h < n; h++)
	{
		Thread[h].join();
	}
	int rezult = Find_min_element(Block_rez);
	auto end = std::chrono::system_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	std::cout << "The result is " << rezult << "\n";
	std::cout << "The working time of the program is " << time.count() << " nanoseconds." << '\n';
	return 0;
}
