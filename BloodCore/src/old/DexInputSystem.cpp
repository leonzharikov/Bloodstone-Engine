#include "DexInputSystem.h"

namespace DEX
{
	InputSystem::InputSystem(const string& c_name, ofstream* logger, const SystemsType st, bool fw)
		: ISystem(c_name, logger, st, fw)
	{
	}

	InputSystem::~InputSystem(void)
	{
	}
}