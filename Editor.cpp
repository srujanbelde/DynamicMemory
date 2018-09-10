#include "Command.h"
#include <iostream>

Editor::Editor(int newID, List& newList)
	:id(newID), appliances(newList)
{
}

void Editor::execute()
{
	for (Iterator iter = appliances.begin(); iter != appliances.end(); iter++)
	{
		if (iter->getData()->getID() == id)
		{
			appliances.setCurrentNode(iter);

			cout << "# Current appliance was set to " << id << endl;

			break;
		}
	}
}
