#include "List.h"

class Command
{
public:
    virtual void execute() = 0;
};

class Creator : public Command
{
private:
	Memory memory;
	int id;
	MachineType type;
	string manufacturer;
	float price;
	vector<string> pictures;
	List& appliances;

	void getID();
	void getType();
	void getManufacturer();
	void getPrice();
	void getPictures();
	void appliancePrompt();
	void saveToPointer(Appliance&);
public:
	Creator(List&);
	void execute();
};

class Editor : public Command
{
private:
	int id;
	List& appliances;
public:
	Editor(int, List&);
	void execute();
};

class Listor : public Command
{
private:
	List& appliances;
public:
	Listor(List&);
	void execute();
};

class PriceChanger : public Command
{
private:
	Iterator& currentAppliance;
	float newPrice;

	void promptPrice();
public:
	PriceChanger(Iterator&);
	void execute();
};

class Saver : public Command
{
private:
	Memory memory;
	queue<AppliancePtr*> loadedPointers;
	void saveFilesInMemory();
public:
	Saver(queue<AppliancePtr*>);
	void execute();
};