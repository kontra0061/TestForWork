#include "TestLogic.h"
#include "InOut.h"

int main()
{
	double Temperature = console::Read();
	simulation::initialData engine;
	testLogic::EngineTest<simulation::initialData> stand(engine, Temperature);
	console::Write(stand.EngineStart());
	return 0;

}