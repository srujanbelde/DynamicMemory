#include "AppliancePtr.h"

int AppliancePtr::numPtrs = 0;
queue<AppliancePtr*> AppliancePtr::loadedPointers;

AppliancePtr::AppliancePtr()
: id(numPtrs), appliance(), memory()
{
	numPtrs++;
}

AppliancePtr::~AppliancePtr()
{
	if (appliance != NULL)
	{
		memory.saveAppliance(*appliance);

		delete appliance;

		appliance = NULL;

		numPtrs--;
	}
}

Appliance* AppliancePtr::operator->()
{
	if (appliance == NULL)
	{
		if (loadedPointers.size() >= 3)
		{
			loadedPointers.front()->~AppliancePtr();
			loadedPointers.pop();
		}
		loadedPointers.push(this);
		memory.loadAppliance(id, appliance);
	}
	return appliance;
}

Appliance& AppliancePtr::operator*()
{
	if (appliance == NULL)
	{
		if (loadedPointers.size() >= 3)
		{
			loadedPointers.front()->~AppliancePtr();
			loadedPointers.pop();
		}
		loadedPointers.push(this);
		memory.loadAppliance(id, appliance);
	}
	return *appliance;
}

int AppliancePtr::getID()
{
	return id;
}
