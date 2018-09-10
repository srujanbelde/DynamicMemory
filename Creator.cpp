#include "Command.h"
#include <iostream>

string cr;

Creator::Creator(List& list)
: memory(), id(-1), type(NA), manufacturer("NA"), price(-1.0), pictures(), appliances(list)
{
}

void Creator::getID()
{
	while (id < 0 || id > 9)
	{
		cout << endl << "\tAppliance ID (0 - 9): ";
		cin >> id;
		getline(cin, cr);
	}
}

void Creator::getType()
{
	int type = -1;

	cout << endl << "\tAppliance Types:";
	cout << endl << "\t\tLaundry Machine		: 0";
	cout << endl << "\t\tDish Washer		: 1";
	cout << endl << "\t\tDryer			: 2";

	while (type < 0 || type > 2)
	{
		cout << endl << "\tAppliance Type (0 - 2): ";
		cin >> type;
		getline(cin, cr);
	}

	this->type = (MachineType)(type);
}

void Creator::getManufacturer()
{
	cout << endl << "\tManufacturer name: ";
	getline(cin, manufacturer);
}

void Creator::getPrice()
{
	cout << endl << "\tPrice: ";
	cin >> price;
	getline(cin, cr);
}

void Creator::getPictures()
{
	string temp = "/";
	cout << endl << "\tLocation of pictures (enter '//' to end input): " << endl << "\t\t";

	getline(cin, temp);

	while (temp.compare("//") != 0)
	{
		pictures.push_back(temp);
		cout << "\t\t";
		getline(cin, temp);
	}

}

void Creator::appliancePrompt()
{
	getID();
	getType();
	getManufacturer();
	getPrice();
	getPictures();
}

void Creator::saveToPointer(Appliance& appliance)
{
	for (Iterator iter = appliances.begin(); iter != appliances.end(); iter++)
	{
		if (iter->getData()->getID() == id)
		{
			*(iter->getData()) = appliance;
			return;
		}
	}
}

void Creator::execute()
{
	appliancePrompt();

	Appliance appliance(id, type, manufacturer, price, pictures);

	memory.saveAppliance(appliance);

	saveToPointer(appliance);
}
