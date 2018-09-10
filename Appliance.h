#include <string>
#include <vector>
using namespace std;

enum MachineType
{
    LAUNDRY_MACHINE,
    DISH_WASHER,
    DRYER,
    NA
};

class Appliance
{
    private:
        int id;
        MachineType type;
        string manufacturer;
        float price;
        vector<string> pictures;
    public:
        Appliance();
		Appliance(const Appliance&);
		Appliance(int, MachineType, string, float, vector<string>);
        int getID();
        void setID(int);
        MachineType getType();
        void setType(MachineType);
        string getManufacturer();
        void setManufacturer(string);
        float getPrice();
        void setPrice(float);
        vector<string> getPictures();
};