#include "Location.h"
using std::get;

Location::Location()
: OPTIONMENU(HOUSES) // Inicialização do OPTIONMENU para HOUSES por padrão
{}

Location::Location(const tuple<int, int> &proporcao, const emojiRepresentation &optionMenu, const string &proprietario)
: proporcaoTerreno(proporcao), OPTIONMENU(optionMenu), proprietario(proprietario)
{

}

Location::Location(const Location &other)
: proporcaoTerreno(other.proporcaoTerreno), OPTIONMENU(other.OPTIONMENU), proprietario(other.proprietario) {}


Location::~Location()
{

}

void Location::setProporcaoTerreno(const tuple<int, int> &proporcao)
{
    proporcaoTerreno = proporcao;
}

tuple<int, int> Location::getProporcaoTerreno() const
{
    return proporcaoTerreno;
}

emojiRepresentation Location::getOptionMenu() const
{
    return OPTIONMENU;
}

void Location::setProprietario(const string &proprietario)
{
    this->proprietario = proprietario;
}

string Location::getProprietario() const
{
    return proprietario;
}

const Location &Location::operator=(const Location &other)
{
    if (this != &other)
    {
        proporcaoTerreno = other.proporcaoTerreno;
        proprietario = other.proprietario;
    }
    return *this;
}

bool Location::operator==(const Location &other) const
{
    return (proporcaoTerreno == other.proporcaoTerreno &&
            OPTIONMENU == other.OPTIONMENU &&
            proprietario == other.proprietario);
}

bool Location::operator!=(const Location &other) const
{
    return !(*this == other);
}

bool Location::operator!() const
{
    // Implementação baseada na ausência de proprietário
    return proprietario=="Sem proprietário";
}

ostream &operator<<(ostream &out, const Location &location)
{
    out<<R"(  
    ____    ____       _        _ _                     _       
   / /\ \  |  _ \  ___| |_ __ _| | |__   ___  ___    __| | ___  
  / /  \ \ | | | |/ _ \ __/ _` | | '_ \ / _ \/ __|  / _` |/ _ \ 
 / /    \ \| |_| |  __/ || (_| | | | | |  __/\__ \ | (_| | (_) |
/_/      \_\____/ \___|\__\__,_|_|_| |_|\___||___/  \__,_|\___/ 
| | ___   ___ __ _| |                                           
| |/ _ \ / __/ _` | |                                           
| | (_) | (_| (_| | |                                           
|_|\___/ \___\__,_|_|                                           
\ \      / /                                                    
 \ \    / /                                                     
  \ \  / /                                                      
   \_\/_/                                                       
   
   )"<<"\n";

    out<<"==========================\n";
    out << "Proporção de Terreno: " << "(" << std::get<0>(location.proporcaoTerreno) << ", " << std::get<1>(location.proporcaoTerreno) << ")\n"
        << "Representação Emoji: ";
    switch (location.OPTIONMENU)
    {
    case HOUSES:
        out << "🏡";
        break;
    case BUILDINGS:
        out << "🏢";
        break;
    default:
        out << "Desconhecido";
    }

    out << "\nProprietário: " << location.proprietario << "\n";

    return out;
}