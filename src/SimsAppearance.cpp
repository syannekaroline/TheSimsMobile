#include <iostream>
#include <algorithm>  // Inclua esta biblioteca para utilizar find
#include <iomanip> // Para controlar largura da coluna

#include "SimsAppearance.h"

using std::cout;
using std::find;
using std::begin;
using std::end;
using std::left;
using std::setw;
using std::setfill;

// Sequências de escape ANSI para cores
const string AMARELO = "\033[1;33m";  // Amarelo brilhante
const string VERDE = "\033[1;32m";  // Amarelo brilhante
const string MAGENTA = "\033[35m";  // Magenta para o emoji
const string RESET = "\033[0m";  // Reset para a cor padrão

//inicializando atributos statics
const string SimsAppearance::listCabeca[NUMAXCONFIGURACOES] = {"Cabeça 1", "Cabeça 2", "Cabeça 3"};
const string SimsAppearance::listOlho[NUMAXCONFIGURACOES] = {"Olhos 1", "Olhos 2", "Olhos 3"};
const string SimsAppearance::listNariz[NUMAXCONFIGURACOES] = {"Nariz 1", "Nariz 2", "Nariz 3"};
const string SimsAppearance::listBoca[NUMAXCONFIGURACOES] = {"Boca 1", "Boca 2","Boca 3"};
const string SimsAppearance::listOrelhas[NUMAXCONFIGURACOES] = {"Orelha 1", "Orelha 2", "Orelha 3"};
const string SimsAppearance::listCabelo[NUMAXCONFIGURACOES] = {"Divisão Sentral Suave", "Bob Curto Desfiado", "Ondas da praia"};
const string SimsAppearance::listSobrancelha[NUMAXCONFIGURACOES] = {"Delicadamente Arqueada", "Naturalmente Arqueadas", "Sobrancelha3"};

// construtores
SimsAppearance::SimsAppearance()
:cabeca(listCabeca[0]), olhos(listOlho[0]), nariz(listNariz[0]), boca(listBoca[0]), orelha(listOrelhas[0]), cabelo(listCabelo[2]),sobrancelha(listSobrancelha[1])
{
    cout << "Criando aparência do Sims com construtor padrão";
}

SimsAppearance::SimsAppearance(const string &cabeca, const string &olhos, const string &nariz, const string &boca,const string & orelha, const string &cabelo, const string &sobrancelha) 
{
    setCabeca(cabeca);
    setOlhos(olhos);
    setNariz(nariz);
    setBoca(boca);
    setOrelha(orelha);
    setCabelo(cabelo);
    setSobrancelha(sobrancelha);
    cout << "Criando aparência do Sim...";
}

SimsAppearance::SimsAppearance(const SimsAppearance &other)
    :cabeca(other.cabeca), olhos(other.olhos), nariz(other.nariz),boca(other.boca),
    orelha(other.orelha),cabelo(other.cabelo), sobrancelha(other.sobrancelha)
{
    cout << "Criando aparência do Sim...";
}

// destrutor 
SimsAppearance::~SimsAppearance()
{

}

// métodos set e get

void SimsAppearance::setCabeca(const string &cabeca)
{
    if (find(begin(listCabeca), end(listCabeca), cabeca) != end(listCabeca))
    {
        this->cabeca = cabeca;
        return;
    }

    cout << "Configuracao de cabeça invalida!\n";
    this->cabeca = "";

}
void SimsAppearance::setOlhos(const string &olhos)
{
    if (find(begin(listOlho), end(listOlho), olhos) != end(listOlho))
    {
        this->olhos = olhos;
        return;
    }
    cout << "Configuracao de olhos invalida!\n";
    this->olhos = "";
    
}

void SimsAppearance::setNariz(const string &nariz)
{
    if (find(begin(listNariz), end(listNariz), nariz) != end(listNariz)) {
        this->nariz = nariz;
        return;
    }
    cout << "Configuracao de nariz invalida!\n";
    this->nariz = "";
}

void SimsAppearance::setBoca(const string &boca)
{
    if (find(begin(listBoca), end(listBoca), boca) != end(listBoca))
    {
        this->boca = boca;
        return;
    }
    cout << "Configuracao de boca invalida!\n";
    this->boca = "";
}

void SimsAppearance::setOrelha(const string &orelha) {
    if (find(begin(listOrelhas), end(listOrelhas), orelha) != end(listOrelhas))
    {
        this->orelha = orelha;
        return;
    }
    cout << "Configuracao de orelha invalida!\n";
    this->orelha = "";

}

void SimsAppearance::setCabelo(const string &cabelo) {
    if (find(begin(listCabelo), end(listCabelo), cabelo) != end(listCabelo)) {
        this->cabelo = cabelo;
        return;
    }
    cout << "Configuracao de cabelo invalida!\n";
    this->cabelo = "";

}

void SimsAppearance::setSobrancelha(const string &sobrancelha) {
    if (find(begin(listSobrancelha), end(listSobrancelha), sobrancelha) != end(listSobrancelha))
    {
        this->sobrancelha = sobrancelha;
        return;
    }
    cout << "Configuracao de sobrancelha invalida!\n";
    this->sobrancelha = "";
    
}

string SimsAppearance::getCabeca() const
{
    return cabeca;
}

string SimsAppearance::getOlhos() const
{
    return olhos;
}

string SimsAppearance::getNariz() const
{
    return nariz;
}

string SimsAppearance::getBoca() const
{
    return boca;
}

string SimsAppearance::getCabelo() const
{
    return cabelo;
}
string SimsAppearance::getOrelha() const
{
    return orelha;
}
string SimsAppearance::getSobrancelha() const
{
    return sobrancelha;
}

// demais métodos

void SimsAppearance::mostrarOpcoes(const string listaOpcoes[], const string &titulo)
{

    // Mostrar título em amarelo
    cout << VERDE << titulo << RESET<< "\n";

    // Mostrar opções
    for (int i = 0; i < NUMAXCONFIGURACOES; i++) {
        // Ajustar largura da coluna para o emoji e o número
        cout << left << setw(10) << setfill(' ') << MAGENTA << "❇️ " << i + 1 << "." << RESET;

        // Mostrar a opção
        cout << listaOpcoes[i] << "\n";
    }

    cout << "\n";
}


void SimsAppearance::exibirMenuConfiguracoes(int opcao)
{
    cout <<R"(
    ____         _                     //\            _       
   / /\ \       / \   _ __   __ _ _ __|/_\|_ __   ___(_) __ _ 
  / /  \ \     / _ \ | '_ \ / _` | '__/ _ \ '_ \ / __| |/ _` |
 / /    \ \   / ___ \| |_) | (_| | | |  __/ | | | (__| | (_| |
/_/__ ___\_\ /_/   \_\ .__/ \__,_|_|  \___|_| |_|\___|_|\__,_|
/ ___|_ _|_ __ ___  _|_|                                      
\___ \| || '_ ` _ \/ __|                                      
 ___) | || | | | | \__ \                                      
|____/___|_| |_| |_|___/                                      
\ \      / /                                                  
 \ \    / /                                                   
  \ \  / /                                                    
   \_\/_/                                                     )";

    cout << "\n==========================================\n";
    
    switch (opcao)
    {
    case 0 :
        mostrarOpcoes(listCabeca,"CABEÇA");
        break;
    case 1 :
        mostrarOpcoes(listOlho,"OLHO");
        break;
    case 2 :
        mostrarOpcoes(listNariz,"NARIZ");
        break;
    case 3 :
        mostrarOpcoes(listBoca,"BOCA");
        break;
    case 4 :
        mostrarOpcoes(listOrelhas,"ORELHAS");
        break;
    case 5 :
        mostrarOpcoes(listCabelo,"CABELO");
        break;
    case 6 :
        mostrarOpcoes(listSobrancelha,"SOBRANCELHA");
        break;
    default:
        mostrarOpcoes(listCabeca,"CABEÇA");
        mostrarOpcoes(listOlho,"OLHO");
        mostrarOpcoes(listNariz,"NARIZ");
        mostrarOpcoes(listCabelo,"CABELO");
        mostrarOpcoes(listBoca,"BOCA");
        mostrarOpcoes(listOrelhas,"ORELHAS");
        mostrarOpcoes(listSobrancelha,"SOBRANCELHA");

        break;
    }

}

void SimsAppearance::visualizarAppearance() const {

  cout << "\n==========================\n";
  cout << "\033[1;32m ❇️ Visualizar configurações de aparência ❇️ \033[0m\n";
  cout << "\n==========================\n";
  cout << "\033[1;32m 👤 Cabeca: \033[0m" << cabeca << "\n";
  cout << "\033[1;32m 👀 Olhos: \033[0m" << olhos << "\n";
  cout << "\033[1;32m 👃 Nariz: \033[0m" << nariz << "\n";
  cout << "\033[1;32m 👄 Boca: \033[0m" << boca << "\n";
  cout << "\033[1;32m 👂 Cabelo: \033[0m" << cabelo << "\n";
  cout << "\033[1;32m 💇 Orelha: \033[0m" << orelha << "\n";
  cout << "\033[1;32m 🤨 Sobrancelha: \033[0m" << sobrancelha << "\n";
  cout << "==========================\n";
}