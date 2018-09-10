#include "Command.h"
#include <iostream>

PriceChanger::PriceChanger(Iterator& iter)
	: currentAppliance(iter), newPrice(0.0)
{
}

void PriceChanger::promptPrice()
{
	cout << "\tNew price: ";
	cin >> newPrice;

	string cr;
	getline(cin, cr);

	cout << endl << "# Price changed for Appliance with ID " << currentAppliance->getData()->getID() << endl;
}

void PriceChanger::execute()
{
	promptPrice();

	currentAppliance->getData()->setPrice(newPrice);
}
