#include "Simulation.h"

namespace simulation
{
	double initialData::Vc(double Temperature, double engineTemperature) 
	{
		return C * (Temperature - engineTemperature);
	}

	double  initialData::Vh()
	{
		return M * Hm + V * V * Hv;
	}
}