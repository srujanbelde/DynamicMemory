#include "Memory.h"
#include <fstream>

void Memory::loadAppliance(int id, Appliance*& appliance)
{
	string line;
	ifstream inputFile(to_string(id));

	if (!inputFile.good())
	{
		appliance = NULL;
		return;
	}

	MachineType type = (MachineType)(3);
	string manufacturer = "NA";
	float price = -1.0;
	vector<string> pictures;

	// get type
	getline(inputFile, line);
	type = (MachineType)(stoi(line));

	// get manufacturer
	getline(inputFile, manufacturer);

	// get price
	getline(inputFile, line);
	price = stof(line);

	// get pictures
	while (getline(inputFile, line))
	{
		pictures.push_back(line);
	}

	appliance = new Appliance(id, type, manufacturer, price, pictures);
}

void Memory::saveAppliance(Appliance& appliance)
{
	ofstream outputFile(to_string(appliance.getID()));

	outputFile << appliance.getType() << endl;
	outputFile << appliance.getManufacturer() << endl;
	outputFile << appliance.getPrice() << endl;
	
	for (string& picture : appliance.getPictures())
	{
		outputFile << picture << endl;
	}
}