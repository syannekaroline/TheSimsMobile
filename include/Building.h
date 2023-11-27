#ifndef BUILDING_H
#define BUILDING_H

#include "Location.h"
#include <string>
using std::string;

#include <iostream>
using std::ostream;

class Building : public Location
{
        friend ostream &operator<<(ostream &, const Building &);

    public:
        Building();
        Building(const tuple<int, int> &, const string & ,const string & = "", const string & = "");
        Building(const Building &other);
        ~Building();

        // Métodos get e set
        void setDistrictName(const string &);
        string getDistrictName() const;
        void setName(const string &);
        string getName() const;
        void setModel(const string &);
        string getModel() const;

        // Método específico
        void chooseBuildingModel();
        void displayFloorPlan() const;
        
        // Operadores
        const Building &operator=(const Building &);
        bool operator==(const Building &) const;
        bool operator!=(const Building &) const;
        bool operator!() const;
    private:
        string districtName;
        string name;
        string model;

};

#endif // BUILDING_H