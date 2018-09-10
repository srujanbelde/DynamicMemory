#include "Command.h"
#include <queue>
#include <iostream>

Saver::Saver(queue<AppliancePtr*> pointers)
:loadedPointers(pointers)
{
}

void Saver::saveFilesInMemory()
{
	while (!loadedPointers.empty())
	{
		Appliance* temp = loadedPointers.front()->operator->();
		memory.saveAppliance(*temp);

		cout << "#Appliance with ID " << temp->getID() << " saved" << endl;

		loadedPointers.pop();
	}
}

void Saver::execute()
{
	saveFilesInMemory();
}