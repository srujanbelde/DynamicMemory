#include "Appliance.h"

Appliance::Appliance()
: id(0), type(NA), manufacturer("N/A"), price(-1.0)
{
}

Appliance::Appliance(int newID, MachineType newType, string newManufacturer, float newPrice, vector<string> newPictures)
: id(newID), type(newType), manufacturer(newManufacturer), price(newPrice), pictures(newPictures)
{
}

Appliance::Appliance(const Appliance& newAppliance)
: id(newAppliance.id), type(newAppliance.type), manufacturer(newAppliance.manufacturer), price(newAppliance.price), pictures(newAppliance.pictures)
{
}

int Appliance::getID()
{
    return id;
}
void Appliance::setID(int id)
{
    this->id = id;
}
MachineType Appliance::getType()
{
    return type;
}
void Appliance::setType(MachineType type)
{
    this->type = type;
}
string Appliance::getManufacturer()
{
    return manufacturer;
}
void Appliance::setManufacturer(string manufacturer)
{
    this->manufacturer = manufacturer;
}
float Appliance::getPrice()
{
    return price;
}
void Appliance::setPrice(float price)
{
    this->price = price;
}
vector<string> Appliance::getPictures()
{
    return pictures;
}
