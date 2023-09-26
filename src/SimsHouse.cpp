#include <iomanip>
#include <iostream>
#include <string>
#include <tuple>
#include <unistd.h>

using std::cout;
using std::make_tuple;

#include "SimsHouse.h"

// CONSTRUTORES

// Construtor padrão -> inicializar objetos com valores padrão pré-definidos.
SimsHouse::SimsHouse()
:ENDERECO("Alameda Esmeralda, 324"),proporcaoTerreno(make_tuple(30, 30)),premium(false), valor(0.0)
{
  cout << "Construindo SimHouse padrão.\n";
}

// Construtor com com parâmetros -> permite a personalização dos atributos
SimsHouse::SimsHouse(tuple<int, int> proporcaoTerreno, bool premium,double valor,string proprietario,const string ENDERECO)
:ENDERECO(ENDERECO)
{
    cout << "Inicializando SimHouse.\n";
    setProporcaoTerreno(proporcaoTerreno);
    setPremium(premium);
    setValor(valor);
    setProprietario(proprietario);
}
// Construtor de cópia
SimsHouse::SimsHouse(const SimsHouse &houseCopia)
:ENDERECO(houseCopia.ENDERECO)
{
    cout << "Inicializando SimHouse.\n";
    this->proporcaoTerreno = houseCopia.proporcaoTerreno;
    this->premium = houseCopia.premium;
    this->valor = houseCopia.valor;
    this->proprietario = houseCopia.proprietario;
}

// Destrutor -> ainda será implementado
SimsHouse::~SimsHouse() 
{

}

// Métodos Get -> obter o valor de um atributo privado de uma classe sem
void SimsHouse::setProporcaoTerreno(tuple<int, int> proporcaoTerreno) 
{
    this->proporcaoTerreno = proporcaoTerreno;
}

void SimsHouse::setPremium(bool premium)
{
    this->premium = premium;
}

void SimsHouse::setValor(double valor)
{ 
    this->valor = valor; 
}

void SimsHouse::setProprietario(string proprietario)
{   
    if(proprietario.length() > MAXTAMSTRINGS)
    {
        this->proprietario = proprietario.substr(0, MAXTAMSTRINGS);
        cout << "\033[1;31m Nome do proprietário alterado. Excedeu o valor máximo de " <<MAXTAMSTRINGS<<" caracteres. \033[0m \n";
        return;
    }
    this->proprietario = proprietario;
}

//métodos get
string SimsHouse::getEndereco() const 
{ 
    return ENDERECO; 
}

tuple<int, int> SimsHouse::getProporcaoTerreno() const 
{
    return proporcaoTerreno; 
}

bool SimsHouse::isPremium() const 
{
    return premium;
}

double SimsHouse::getValor() const 
{ 
    return valor; 
}

string SimsHouse::getProprietario() const 
{ 
    return proprietario; 
}

//demais métodos
void SimsHouse::overview() const 
{
  cout << "==========================================\n";
  cout << "\033[1;32m ❇️ Overview SimsHouse❇️ \033[0m\n";
  cout << (premium ? "Premium💎" : "")<< "\n";
  cout << "==========================================\n";
  cout << "\033[1;32m ❇️ Endereço: \033[0m" << ENDERECO<< "\n";
  cout << "\033[1;32m ❇️ valor: \033[0m" << valor << " SimsCash\n";
  cout << "\033[1;32m ❇️ proprietario: \033[0m" << proprietario <<"\n";
  cout << "============================================\n";
}

void SimsHouse::efetuarVenda(Sims &novoProprietario) 
{
    if (novoProprietario.getSimCash() < valor) 
    {
        std::cout << "\033[1;31m Saldo insuficiente 😢 a venda foi recusada!\033[0m\n";
        return;
    }
    novoProprietario.setSimCash(novoProprietario.getSimCash() - valor);
    novoProprietario.setEndereco(ENDERECO);
    setProprietario(novoProprietario.getSobrenome());
    cout << "💸\033[1;32m Venda realizada com sucesso!\033[0m💸\n";
}
