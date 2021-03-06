

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <thread>
#include <Windows.h>

std::ofstream ofs;
int countedPrimes = 0;
int count = 1;
int number;




void forLoopThread() {
	for (int a = 1; a <= number; a++)
	{
		if (number%a == 0)
		{
			count++;
		}
	}
}

int main()
{

	std::cout << "Enter an integer:";
	std::cin >> number;


	ofs.open("numbers.txt", std::ofstream::out | std::ofstream::app);


	while (true) {
		Retry:
		number = number + 1;
		
		std::thread t1(forLoopThread);

		if(t1.joinable())
			t1.join();

		if (count == 2) {
			countedPrimes = countedPrimes + 1;
			std::cout << number << std::endl;
			ofs << number << " " <<countedPrimes << std::endl;
			count = 0;
			goto Retry;
		}
			
		else {
			count = 0;

			goto Retry;
		}
	}

	system("PAUSE");
	return (0);
}
