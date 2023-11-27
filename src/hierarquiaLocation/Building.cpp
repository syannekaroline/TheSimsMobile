#include "Building.h"
using std::cin;
using std::cout;


using std::make_tuple;

Building::Building() : Location(make_tuple(40, 60),BUILDINGS)
{
}

Building::Building(const tuple<int, int> &proporcao,const string & proprietario,const string &districtName, const string &name)
: Location(proporcao, BUILDINGS,proprietario), districtName(districtName),name(name), model("")
{
}

Building::Building(const Building &other)
    : Location(static_cast<Location>(other)), districtName(other.districtName), name(other.name), model(other.model) 
{

}

Building::~Building(){}

void Building::setDistrictName(const string &districtName)
{
    this->districtName = districtName;
}

string Building::getDistrictName() const
{
    return districtName;
}

void Building::setName(const string &name)
{
    this->name = name;
}

string Building::getName() const
{
    return name;
}

void Building::setModel(const string &model)
{
    this->model = model;
}

string Building::getModel() const
{
    return model;
}

#include <iostream>
#include "Building.h"

void Building::chooseBuildingModel()
{

    string simples = R"(
       _
     _|=|__________
    /              \
   /                \
  /__________________\
   ||  || /--\ ||  ||
   ||[]|| | .| ||[]||
 ()||__||_|__|_||__||()
( )|-|-|-|====|-|-|-|( ) 
^^^^^^^^^^====^^^^^^^^^^^

    )";

    string classico =  R"(

       _._._._       _._._._       _._._._ 
       | ___ |_._._._| ___ |_._._._| ___ |
       | |_| |  ___  | |_| |  ___  | |_| |
       |_III_|  |_|  |_III_|  |_|  |_III_| ^!^
 ^     | ___ |__III__| ___ |__III__| ___ |
    ^  | |_| |  ___  | |_| |  ___  | |_| |   ^!^
       |_III_|  |_|  |_III_|  |_|  |_III_|
       | ___ |__III__| ___ |__III__| ___ | _)o(_
       | |_| |  ___  | |_| |  ___  | |_| | /(|)\
   /)  |_III_|  |_|  |_III_|  |_|  |_III_|   H
 _/ )  | ___ |__III__|_____|__III__| ___ |   H
 ~^~^~ | |_| |"""""""||~|~||"""""""| |_| |   H
    ^~'|_III_|@@@@@@@||_|_||@@@@@@@|_III_|^~^H '
 @@@@@@@@@@@@@@     @/=====\@     @@@@@@@@@@@@@@

    )";

    string moderno =R"(
  __                   ___      
 |""|  ___    _   __  |"""|  __ 
 |""| |"""|  |"| |""| |"""| |""| 
 |""| |"""|  |"| |""| |"""| |""| 
 |""| |"""|  |"| |""| |"""| |""| 
 "'''"''"'""'"""''"''''"""'""'""'
    )";

    cout << "Escolha um modelo para o prédio '" << getName() << "':\n";

    // ASCII Art para os modelos
    cout << "1. Modelo Simples\n";

    cout<< simples <<"\n";

    cout << "2. Modelo Clássico\n";
    cout<<classico<<"\n";

    cout << "3. Modelo Moderno\n";
    cout<<moderno <<"\n";

    int escolha;
    cout << "Digite o número do modelo desejado: ";
    cin >> escolha;

    switch (escolha)
    {
    case 1:
        setModel(simples);
        break;
    case 2:
        setModel(classico);
        break;
    case 3:
        setModel(moderno);
        break;
    default:
        cout << "Escolha inválida. Modelo padrão (Simples) será definido.\n";
        setModel("Simples");
        break;
    }

    cout << "Modelo selecionado: " << getModel() << "\n";
}


const Building &Building::operator=(const Building &other)
{
    if (this != &other)
    {
        static_cast<Location &>(*this) = static_cast<const Location &>(other);
        districtName = other.districtName;
        name = other.name;
        model = other.model;
    }
    return *this;
}

bool Building::operator==(const Building &other) const
{
    return (static_cast<const Location &>(*this) == static_cast<const Location &>(other) &&
            districtName == other.districtName &&
            name == other.name &&
            model == other.model);
}

bool Building::operator!=(const Building &other) const
{
    return !(*this == other);
}

bool Building::operator!() const
{
    // Implementação baseada na ausência de nome
    return name.empty();
}

ostream &operator<<(ostream &out, const Building &building)
{
    out << static_cast<const Location &>(building) // Chama o operador << da classe base Location
       << "\n🌆 District Name: " << building.districtName
       << "\n🏢 Name: " << building.name
       <<"\n" <<building.model;
       
    return out;
}


void Building::displayFloorPlan() const
{
    int width, height;
    std::tie(width, height) = getProporcaoTerreno();

    // Exemplo básico de representação ASCII art da planta baixa
    std::cout << "Planta Baixa para " << getName() << " (Proporção de Terreno: " << width << "x" << height << "):\n";

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                // Bordas do prédio
                std::cout << "#";
            }
            else
            {
                // Espaço interno do prédio
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}
