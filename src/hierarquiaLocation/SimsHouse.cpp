#include <iomanip>
#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>
#include <iterator>

using std::cout;
using std::make_tuple;
using std::left;
using std::setw;
using std::setfill;
using std::find;
using std::begin;
using std::end;

#include "SimsHouse.h"
const string VERDE = "\033[1;32m";  // VERDE

//Instanciação de variáveis statics
const double SimsHouse::MINVALORPREMIUM = 100000;
int SimsHouse::numEnderecos = 0;
int SimsHouse::numLotesPossuidos= 0;
string SimsHouse::enderecosList[ MAXNUMENDERECOS ];

// CONSTRUTORES
// Construtor padrão -> inicializar objetos com valores padrão pré-definidos.
SimsHouse::SimsHouse()
:ENDERECO("Alameda Esmeralda, 324"),Location(make_tuple(30, 30),HOUSES),premium(false), valor(0.0),housefeatures{}
{
  cout << "Construindo SimHouse padrão.\n";
  enderecosList[numEnderecos] = ENDERECO;
  numEnderecos++;
}

// Construtor com com parâmetros -> permite a personalização dos atributos
SimsHouse::SimsHouse(const tuple<int, int> & proporcaoTerreno,double valor,const string & ENDERECO,const string &  proprietario )
:ENDERECO(ENDERECO),Location(proporcaoTerreno,HOUSES,proprietario)
{
    cout << "Inicializando SimHouse.\n";
    setValor(valor);
    enderecosList[numEnderecos] = ENDERECO;
    numEnderecos++;
}
// Construtor de cópia
SimsHouse::SimsHouse(const SimsHouse &houseCopia)
:ENDERECO(houseCopia.ENDERECO),Location(static_cast<Location> (houseCopia))
{
    cout << "Inicializando SimHouse.\n";
    this->premium = houseCopia.premium;
    this->valor = houseCopia.valor;
    enderecosList[numEnderecos] = ENDERECO;
    numEnderecos++;
}

// Destrutor
SimsHouse::~SimsHouse() 
{
    cout<<"Deletando objeto SimsHouse: "<<ENDERECO<<"\n";
}

// Métodos Get -> obter o valor de um atributo privado de uma classe sem

void SimsHouse::setValor(double valor)
{ 
    this->valor = valor;
    premium =  (valor >= MINVALORPREMIUM) ? true : false; 
}

//métodos get
string SimsHouse::getEndereco() const 
{ 
    return ENDERECO; 
}

bool SimsHouse::isPremium() const 
{
    return premium;
}

double SimsHouse::getValor() const 
{ 
    return valor; 
}

//demais métodos

void SimsHouse::efetuarVenda(Sims &novoProprietario) 
{
    if (novoProprietario.getSimCash() < valor) 
    {
        std::cout << "\033[1;31m Saldo insuficiente 😢 a venda foi recusada!\033[0m\n";
        return;
    }
    novoProprietario.setSimCash(novoProprietario.getSimCash() - valor);
    novoProprietario.setEndereco(ENDERECO);
    novoProprietario.registrarConquista("Lar, doce lar.");
    static_cast< Location &>(*this).setProprietario(novoProprietario.getSobrenome());
    cout << "💸\033[1;32m Venda realizada com sucesso!\033[0m💸\n";
    numLotesPossuidos++;
}

void SimsHouse::mostrarVizinhanca()
{
    cout <<
    R"(
  ____          _     _       _                                 _               
 / /\ \  __   _(_)___(_)_ __ | |__   __ _ _ __   ___ __ _   ___(_)_ __ ___  ___ 
/ /  \ \ \ \ / / |_  / | '_ \| '_ \ / _` | '_ \ / __/ _` | / __| | '_ ` _ \/ __|
\ \  / /  \ V /| |/ /| | | | | | | | (_| | | | | (_| (_| | \__ \ | | | | | \__ \
 \_\/_/    \_/ |_/___|_|_| |_|_| |_|\__,_|_| |_|\___\__,_| |___/_|_| |_| |_|___/
                                                 )_)                            )";

    cout << "\n==========================================\n";
    cout << "\033[1m Monte Salgado\033[0m\n" ;
    cout << numLotesPossuidos << " de " << MAXNUMENDERECOS << " lotes Possuídos"; 
    cout << "\n==========================================\n";
    for ( int i = 0; i < numEnderecos;i++){
        cout << "\033[1;32m ❇️ \033[0m" << enderecosList[i]<< "\n";
    }
    cout << "\n==========================================\n";
}

//operadores
ostream &operator<<(ostream &out, const SimsHouse &house)
{
    out << static_cast<const Location &>(house);// Chama o operador << da classe base Location

    out << "==========================================\n";
    out <<R"(
  ____     ___                       _               
 / /\ \   / _ \__   _____ _ ____   _(_) _____      __
/ /  \ \ | | | \ \ / / _ \ '__\ \ / / |/ _ \ \ /\ / /
\ \  / / | |_| |\ V /  __/ |   \ V /| |  __/\ V  V / 
 \_\/_/_  \___/  \_/ \___|_|    \_/ |_|\___| \_/\_/  
/ ___|(_)_ __ ___  ___| | | | ___  _   _ ___  ___    
\___ \| | '_ ` _ \/ __| |_| |/ _ \| | | / __|/ _ |   
 ___) | | | | | | \__ \  _  | (_) | |_| \__ \  __/   
|____/|_|_| |_| |_|___/_| |_|\___/ \__,_|___/\___|  

    )";
  out << (house.premium ? "Premium💎" : "")<< "\n";
  out << "==========================================\n";
  out << "\033[1;32m ❇️ Endereço: \033[0m" << house.ENDERECO<< "\n";
  out << "\033[1;32m ❇️ valor: \033[0m" << house.valor << " housesCash\n";
  out << "============================================\n";

  return out;
}

void SimsHouse::setFeatures(const vector<string>& comodos, int numAndares, bool temPiscina, string estilo) {
    housefeatures.comodos = comodos;
    housefeatures.numAndares = numAndares;
    housefeatures.temPiscina = temPiscina;
    housefeatures.estilo = estilo;
}

void SimsHouse::addComodo(const string& comodo) {
    housefeatures.comodos.push_back(comodo);
}

void SimsHouse::removeComodo(const string& comodo)
{
    auto it = find(housefeatures.comodos.begin(), housefeatures.comodos.end(), comodo);
    if (it != housefeatures.comodos.end()) {
        housefeatures.comodos.erase(it);
        cout << "Cômodo '" << comodo << "' removido com sucesso." << "\n";
    } else {
        cout << "Cômodo '" << comodo << "' não encontrado na lista." << "\n";
    }
}

void SimsHouse::verFeatures() const {
    cout << "Características da casa em " << ENDERECO << ":" << "\n";
    cout << "Número de andares: " << housefeatures.numAndares << "\n";
    cout << "Estilo: " << housefeatures.estilo << "\n";
    cout << "Possui piscina: " << (housefeatures.temPiscina ? "Sim" : "Não") << "\n";

    cout << housefeatures.comodos.size()<<" Cômodos:" << "\n";
    for (const string& comodo : housefeatures.comodos) {
        cout << " ❇️ " << comodo << "\n";
    }
}

//operadores
// Assignment operator
const SimsHouse &SimsHouse::operator=(const SimsHouse &house) {
    if (this != &house) {
        static_cast<Location &>(*this) = static_cast<const Location &>(house);
        this->premium = house.premium;
        this->valor = house.valor;
    }
    return *this;
}

// Comparison operators
int SimsHouse::operator==(const SimsHouse &house) const {
    return ( static_cast<const Location &>(*this) == static_cast<const Location &>(house) &&
            this->ENDERECO == house.ENDERECO);
}

int SimsHouse::operator!=(const SimsHouse &house) const {
    return !(*this == house);
}

bool SimsHouse::operator!() const { // verifica se a casa já tem proprietário 
    return premium;
}