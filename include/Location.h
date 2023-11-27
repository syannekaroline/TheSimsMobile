#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <tuple>
#include <string>
using std::string;
using std::tuple;
#include <iostream>
using std::ostream;

enum emojiRepresentation {
    HOUSES,
    BUILDINGS
};

class Location
{
    friend ostream &operator<<(ostream &, const Location &);

    public:
        Location();
        Location(const tuple<int, int> &, const emojiRepresentation &, const string & = "Sem proprietário");
        Location(const Location &other);
        ~Location();

        // Métodos get e set
        void setProporcaoTerreno(const tuple<int, int> &);
        tuple<int, int> getProporcaoTerreno() const;
        emojiRepresentation getOptionMenu() const;
        void setProprietario(const string &);
        string getProprietario() const;

        // Operadores
        const Location &operator=(const Location &);
        bool operator==(const Location &) const;
        bool operator!=(const Location &) const;
        bool operator!() const;
        
    private:
        tuple<int, int> proporcaoTerreno;
        const emojiRepresentation OPTIONMENU;
        string proprietario;
};

#endif // LOCATION_H