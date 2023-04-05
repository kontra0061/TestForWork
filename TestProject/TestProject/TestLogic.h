#pragma once
#include "Simulation.h"

#define ERROR 10e-2
#define MAX_TIME 1800

namespace testLogic
{
	template <typename E>
	class EngineTest
	{
		int numMV;
		double Temperature;
		double engineTemperature;;;
		E* engine;

	public:
		int EngineStart();
		EngineTest(E& engine, const double Temperature);
	};

	template<typename E>
	EngineTest<E>::EngineTest(E& engine, const double Temperature)
	{
		numMV = 0;
		this->engine = &engine;
		this->engine->M = engine.startM[numMV];
		this->engine->V = engine.startV[numMV];
		engineTemperature = Temperature;
		this->Temperature = Temperature;
	}

	template<typename E>
	int EngineTest<E>::EngineStart()
	{
		double a = engine->M * engine->I;
		double eps = engine->Tper - engineTemperature;
		int time = 0;
		while (eps > ERROR && time < MAX_TIME)
		{
			time++;
			engine->V += a;
			if (numMV < engine->startM.size() - 2)
				numMV += engine->V < engine->startV[numMV + 1] ? 0 : 1;
			double up = (engine->V - engine->startV[numMV]);
			double down = (engine->startV[numMV + 1] - engine->startV[numMV]);
			double factor = (engine->startM[numMV + 1] - engine->startM[numMV]);
			engine->M = up / down * factor + engine->startM[numMV];

			engineTemperature += engine->Vc(Temperature, engineTemperature) + engine->Vh();
			a = engine->M * engine->I;

			eps = engine->Tper - engineTemperature;
		}
		return time;
	}

}