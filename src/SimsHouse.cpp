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
:ENDERECO("Alameda Esmeralda, 324"),proporcaoTerreno(make_tuple(30, 30)),premium(false), valor(0.0),housefeatures{}
{
  cout << "Construindo SimHouse padrão.\n";
  enderecosList[numEnderecos] = ENDERECO;
  numEnderecos++;
}

// Construtor com com parâmetros -> permite a personalização dos atributos
SimsHouse::SimsHouse(const tuple<int, int> & proporcaoTerreno,double valor,const string & ENDERECO,const string &  proprietario )
:ENDERECO(ENDERECO)
{
    cout << "Inicializando SimHouse.\n";
    setProporcaoTerreno(proporcaoTerreno);
    setValor(valor);
    setProprietario(proprietario);
    enderecosList[numEnderecos] = ENDERECO;
    numEnderecos++;
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
    enderecosList[numEnderecos] = ENDERECO;
    numEnderecos++;
}

// Destrutor
SimsHouse::~SimsHouse() 
{
    cout<<"Deletando objeto SimsHouse: "<<ENDERECO<<"\n";
}

// Métodos Get -> obter o valor de um atributo privado de uma classe sem
void SimsHouse::setProporcaoTerreno(const tuple<int, int> & proporcaoTerreno) 
{
    this->proporcaoTerreno = proporcaoTerreno;
}

void SimsHouse::setValor(double valor)
{ 
    this->valor = valor;
    premium =  (valor >= MINVALORPREMIUM) ? true : false; 
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
    return (proprietario=="")? "Sem proprietário" : proprietario; 
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
    setProprietario(novoProprietario.getSobrenome());
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
    cout << "==========================================\n";
    cout <<R"(
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
  cout << (house.premium ? "Premium💎" : "")<< "\n";
  cout << "==========================================\n";
  cout << "\033[1;32m ❇️ Endereço: \033[0m" << house.ENDERECO<< "\n";
  cout << "\033[1;32m ❇️ valor: \033[0m" << house.valor << " housesCash\n";
  cout << "\033[1;32m ❇️ proprietario: \033[0m" << house.getProprietario() <<"\n";
  cout << "============================================\n";

  return cout;
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

        this->proporcaoTerreno = house.proporcaoTerreno;
        this->premium = house.premium;
        this->valor = house.valor;
        this->proprietario = house.proprietario;
    }
    return *this;
}

// Comparison operators
int SimsHouse::operator==(const SimsHouse &house) const {
    return (this->ENDERECO == house.ENDERECO);
}

int SimsHouse::operator!=(const SimsHouse &house) const {
    return !(*this == house);
}

bool SimsHouse::operator!() const { // verifica se a casa já tem proprietário 
    return (proprietario == "")? true: false;
}