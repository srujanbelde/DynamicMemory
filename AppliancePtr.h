#include "Memory.h"
#include <queue>

class AppliancePtr
{
    private:
        static const int maxAppliancesLoaded = 3;
		static int numPtrs;
		int id;
        Appliance* appliance;
        Memory memory;
    protected:
        AppliancePtr(const AppliancePtr& appliancePtr);
        AppliancePtr& operator=(const AppliancePtr& appliancePtr);
    public:
		static queue<AppliancePtr*> loadedPointers;

        AppliancePtr();
        ~AppliancePtr();
        Appliance* operator->();
        Appliance& operator*();
		int getID();
};
