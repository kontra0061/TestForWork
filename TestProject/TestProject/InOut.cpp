#include "InOut.h"
#include "TestLogic.h"
#include <iostream>

using namespace std;

int console::Read()
{
	double Temperature;
	cout << "Enter temperature" << endl;
	cin >> Temperature;
	return Temperature;
}

void console::Write(const int time)
{
	if (time == MAX_TIME)
		cout << endl << "At this temperatue engine work fine" << endl;
	else
		cout << endl << "Overheating time: " << time << " sec" << endl;
}