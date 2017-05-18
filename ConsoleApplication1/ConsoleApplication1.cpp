// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>		// for std::cout
#include <list>			// for std::list
#include <chrono>		// for std::choro and keeping the time

auto start = std::chrono::system_clock::now();		// start the clock to keep the time

void CollatzCount(long long &num, int &count);		// Forward declaration of CollatzCount function

int main()
{
	long long num;
	int cnt = 0;
	std::cout << "Please Enter an Integer value" << "\n";
	std::cin >> num;								// get the number from user

	/*while (num != 1)
	{		
		if (num % 2 == 0)
		{
			num = num / 2;
		}
		else
		{
			num = num * 3 + 1;
		}
		cnt++;
	}*/// Not recursive way 

	CollatzCount(num,cnt);
	
	std::cout << cnt << "\n";
	auto end = std::chrono::system_clock::now();	// get time to reach this code segment
	auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);	// calculate the elapsed time

	std::cout << "Duration: " << elapsed.count() <<"\n";

    return 0;
}

// Finds the total number of iteration to calculate Collatz Numbers
void CollatzCount(long long &num, int &count)
{
	if (num == 1)
	{
		return ;
	}
	else
	{
		if (num % 2 == 0)
		{
			num /= 2;
		}
		else
		{
			num = num * 3 + 1;
		}
		count++;
		CollatzCount(num,count);
	}	
	
}

