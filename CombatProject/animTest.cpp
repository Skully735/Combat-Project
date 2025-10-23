#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int animTest()
{
	cout << ".";

	this_thread::sleep_for(chrono::seconds(2));

	cout << " .";

	return 0;
}