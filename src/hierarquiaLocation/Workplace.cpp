#include "Workplace.h"
using std::cin;
// Códigos de cores ANSI para o terminal
const string RESET = "\033[0m";
const string VERDE = "\033[1;32m";  // Texto verde brilhante
const string VERMELHO = "\033[1;31m";  // Texto vermelho brilhante

Workplace::Workplace() : Building()
{
}

Workplace::Workplace(const tuple<int, int> &proporcao, const CareerStories &careerStorie,const string & proprietario, const string &districtName, const string &name)
:Building(proporcao,proprietario,districtName,name), careerStorie(careerStorie)
{
}

Workplace::~Workplace()
{
}
Workplace::Workplace(const Workplace &other)
    : Building(static_cast<Building>(other)), careerStorie(other.careerStorie) {}


void Workplace::setCareerStories(const CareerStories &careerStorie)
{
    this->careerStorie = careerStorie;
    this->careerStorie.setWorkplace(static_cast<const Building*>(this)->getName());
}

CareerStories Workplace::getCareerStories() const
{
    return careerStorie;
}

const Workplace &Workplace::operator=(const Workplace &other)
{
    if (this != &other)
    {
        static_cast< Building &>(*this)=static_cast<const Building &>(other);
        careerStorie = other.careerStorie;
    }
    return *this;
}

bool Workplace::operator==(const Workplace &other) const
{
    return (static_cast<const Building &>(*this)==static_cast<const Building &>(other) &&
            careerStorie == other.careerStorie);
}

bool Workplace::operator!=(const Workplace &other) const
{
    return !(*this == other);
}

bool Workplace::operator!() const
{
    // Implementação baseada na ausência de carreira
    return !static_cast<const Building &>(*this);
}

ostream &operator<<(ostream &out, const Workplace &workplace)
{
    out << static_cast<const Building &>(workplace) // Chama o operador << da classe base Building
       << "\nStories Career: " << workplace.careerStorie;
    return out;
}

void Workplace::goToWork(Sims *sim){
    system("clear");
    cout<<"+------------+------------+--------------+--------------+\n";
    cout << "Bem-vindo ao seu local de trabalho!\n";
    cout << "Escolha uma opção:\n";
    cout <<VERDE<< "1. "<<RESET<<"🚀 Trabalhar em um turno rápido - iniciar evento\n";
    cout <<VERDE<< "2. "<<RESET<<"🕒 Trabalhar em um turno normal - iniciar evento\n";

    int escolha;
    cout << "Opção: ";
    cin >> escolha;

    if (escolha == 1)
    {
        system("clear");
        // Trabalhar em um turno rápido - iniciar evento
        careerStorie.iniciarEvento(sim, QUICKSHIFT);
    }
    else if (escolha == 2)
    {
        // Trabalhar em um turno normal - iniciar evento
        system("clear");
        careerStorie.iniciarEvento(sim, STANDARDSHIFT);
    }
    else
    {
        cout << "Opção inválida.\n";
    }
}