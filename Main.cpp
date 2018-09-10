// Kareem Yacoub
// kyacou2
// CS 474
// Prof. Buy

#include <iostream>
#include "Command.h"
using namespace std;

char cmd = '0';
List applianceList(10);

Command* commandFactory()
{
	if (cmd == 'l')
	{
		return new Listor(applianceList);
	}
	else if ((cmd - '0') >= 0 && (cmd - '0') <= 9)
	{
		return new Editor((cmd - '0'), applianceList);
	}
	else if (cmd == 'c')
	{
		return new Creator(applianceList);
	}
	else if (cmd == 'p')
	{
		return new PriceChanger(applianceList.getCurrentNode());
	}
	else if (cmd == 's')
	{
		return new Saver(AppliancePtr::loadedPointers);
	}
	else if (cmd != 'q')
	{
		cout << "# Invalid command" << endl;
	}

	return NULL;
}

int main()
{
    cout << "Welcome!" << endl;

	while (cmd != 'q')
	{
		cout << endl << "Input a command: ";
		cin >> cmd;
		
		Command* command = commandFactory();
		if (command != NULL)
		{
			command->execute();
		}
	}
}