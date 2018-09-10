#include "Command.h"
#include <iostream>

Listor::Listor(List& applianceList)
: appliances(applianceList)
{ 
}

void Listor::execute()
{
	for (Iterator iter = appliances.begin(); iter != appliances.end(); iter++)
	{
		if (iter->getData().operator->() != NULL)
		{
			cout << "\tApplliance ID: " << iter->getData()->getID() << endl;

			cout << "\tMachine Type: ";
			MachineType type = iter->getData()->getType();
 			switch (type)
			{
			case LAUNDRY_MACHINE:
				cout << "Laundry Machine" << endl;
				break;
			case  DRYER:
				cout << "Dryer" << endl;
				break;
			case DISH_WASHER:
				cout << "Dish Washer" << endl;
				break;
			};

			cout << "\tManufacturer: " << iter->getData()->getManufacturer() << endl;

			cout << "\tPrice: $" << iter->getData()->getPrice() << endl;

			cout << "\tPictures:" << endl;
			for (string& picture : iter->getData()->getPictures())
			{
				cout << "\t\t" << picture << endl;
			}

			cout << endl;
		}
	}
}
