#pragma once
#include <vector>

namespace simulation
{
	struct initialData

	{
		double I = 0.1;
		std::vector<int> startM = { 20, 75, 100, 105, 75, 0 };
		std::vector<int> startV = { 0, 75, 150, 200, 250, 300 };
		double Tper = 110;
		double Hm = 0.01;
		double Hv = 0.0001;
		double C = 0.1;

		double M;
		double V;

		double Vc(double Temperature, double engineTemperature);
		double Vh();
	};
}