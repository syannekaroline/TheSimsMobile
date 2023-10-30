#include <iostream>
#include <algorithm>  // Inclua esta biblioteca para utilizar find
#include <iomanip> // Para controlar largura da coluna
#include <iterator>

#include "SimsAppearance.h"
#include "Sims.h"

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
const string SimsAppearance::LIST_CABECA[NUMAXCONFIGURACOES] = {"Cabeça 1", "Cabeça 2", "Cabeça 3"};
const string SimsAppearance::LIST_OLHOS[NUMAXCONFIGURACOES] = {"Olhos 1", "Olhos 2", "Olhos 3"};
const string SimsAppearance::LIST_NARIZ[NUMAXCONFIGURACOES] = {"Nariz 1", "Nariz 2", "Nariz 3"};
const string SimsAppearance::LIST_BOCA[NUMAXCONFIGURACOES] = {"Boca 1", "Boca 2","Boca 3"};
const string SimsAppearance::LIST_ORELHA[NUMAXCONFIGURACOES] = {"Orelha 1", "Orelha 2", "Orelha 3"};
const string SimsAppearance::LIST_CABELO[NUMAXCONFIGURACOES] = {"Divisão Central Suave", "Bob Curto Desfiado", "Ondas da praia"};
const string SimsAppearance::LIST_SOBRANCELHA[NUMAXCONFIGURACOES] = {"Delicadamente Arqueada", "Naturalmente Arqueadas", "Sobrancelha3"};

// construtores
SimsAppearance::SimsAppearance()
: config{LIST_CABECA[0], LIST_OLHOS[0], LIST_NARIZ[0], LIST_BOCA[0], LIST_ORELHA[0], LIST_CABELO[2], LIST_SOBRANCELHA[1]}
{
    cout << "Criando aparência do Sims com construtor padrão\n";
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
:config{other.config}
{
    cout << "Criando aparência do Sim...";
}

// destrutor 
SimsAppearance::~SimsAppearance()
{
    cout<<"Deletando objeto SimsAppearance\n";
}

// métodos set e get

void SimsAppearance::setCabeca(const string &cabeca)
{
    if (find(begin(LIST_CABECA), end(LIST_CABECA), cabeca) != end(LIST_CABECA))
    {
        this->config.cabeca = cabeca;
        return;
    }

    cout << "Configuracao de cabeça invalida!\n";
    this->config.cabeca = "";

}
void SimsAppearance::setOlhos(const string &olhos)
{
    if (find(begin(LIST_OLHOS), end(LIST_OLHOS), olhos) != end(LIST_OLHOS))
    {
        this->config.olhos = olhos;
        return;
    }
    cout << "Configuracao de olhos invalida!\n";
    this->config.olhos = "";
    
}

void SimsAppearance::setNariz(const string &nariz)
{
    if (find(begin(LIST_NARIZ), end(LIST_NARIZ), nariz) != end(LIST_NARIZ)) {
        this->config.nariz = nariz;
        return;
    }
    cout << "Configuracao de nariz invalida!\n";
    this->config.nariz = "";
}

void SimsAppearance::setBoca(const string &boca)
{
    if (find(begin(LIST_BOCA), end(LIST_BOCA), boca) != end(LIST_BOCA))
    {
        this->config.boca = boca;
        return;
    }
    cout << "Configuracao de boca invalida!\n";
    this->config.boca = "";
}

void SimsAppearance::setOrelha(const string &orelha) {
    if (find(begin(LIST_ORELHA), end(LIST_ORELHA), orelha) != end(LIST_ORELHA))
    {
        this->config.orelha = orelha;
        return;
    }
    cout << "Configuracao de orelha invalida!\n";
    this->config.orelha = "";

}

void SimsAppearance::setCabelo(const string &cabelo) {
    if (find(begin(LIST_CABELO), end(LIST_CABELO), cabelo) != end(LIST_CABELO)) {
        this->config.cabelo = cabelo;
        return;
    }
    cout << "Configuracao de cabelo invalida!\n";
    this->config.cabelo = "";

}

void SimsAppearance::setSobrancelha(const string &sobrancelha) {
    if (find(begin(LIST_SOBRANCELHA), end(LIST_SOBRANCELHA), sobrancelha) != end(LIST_SOBRANCELHA))
    {
        this->config.sobrancelha = sobrancelha;
        return;
    }
    cout << "Configuracao de sobrancelha invalida!\n";
    this->config.sobrancelha = "";
    
}

string SimsAppearance::getCabeca() const
{
    return config.cabeca;
}

string SimsAppearance::getOlhos() const
{
    return config.olhos;
}

string SimsAppearance::getNariz() const
{
    return config.nariz;
}

string SimsAppearance::getBoca() const
{
    return config.boca;
}

string SimsAppearance::getCabelo() const
{
    return config.cabelo;
}
string SimsAppearance::getOrelha() const
{
    return config.orelha;
}
string SimsAppearance::getSobrancelha() const
{
    return config.sobrancelha;
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
        mostrarOpcoes(LIST_CABECA,"CABEÇA");
        break;
    case 1 :
        mostrarOpcoes(LIST_OLHOS,"OLHO");
        break;
    case 2 :
        mostrarOpcoes(LIST_NARIZ,"NARIZ");
        break;
    case 3 :
        mostrarOpcoes(LIST_BOCA,"BOCA");
        break;
    case 4 :
        mostrarOpcoes(LIST_ORELHA,"ORELHAS");
        break;
    case 5 :
        mostrarOpcoes(LIST_CABELO,"CABELO");
        break;
    case 6 :
        mostrarOpcoes(LIST_SOBRANCELHA,"SOBRANCELHA");
        break;
    default:
        mostrarOpcoes(LIST_CABECA,"CABEÇA");
        mostrarOpcoes(LIST_OLHOS,"OLHO");
        mostrarOpcoes(LIST_NARIZ,"NARIZ");
        mostrarOpcoes(LIST_CABELO,"CABELO");
        mostrarOpcoes(LIST_BOCA,"BOCA");
        mostrarOpcoes(LIST_ORELHA,"ORELHAS");
        mostrarOpcoes(LIST_SOBRANCELHA,"SOBRANCELHA");

        break;
    }

}

//operadores

ostream &operator<<(ostream &out, const SimsAppearance &sim)
{
  cout << "\n==========================\n";
  cout << "\033[1;32m ❇️ Visualizar configurações de aparência ❇️ \033[0m\n";
  cout << "\n==========================\n";
  cout << "\033[1;32m 👤 Cabeca: \033[0m" << sim.config.cabeca <<" | "<< sim.getColor("cabeça")<<"\n";
  cout << "\033[1;32m 👀 Olhos: \033[0m" << sim.config.olhos <<" | "<< sim.getColor("olhos")<<"\n";
  cout << "\033[1;32m 👃 Nariz: \033[0m" << sim.config.nariz <<" | "<< sim.getColor("nariz")<<"\n";
  cout << "\033[1;32m 👄 Boca: \033[0m" << sim.config.boca <<" | "<< sim.getColor("boca")<<"\n";
  cout << "\033[1;32m 👂 Cabelo: \033[0m" << sim.config.cabelo <<" | "<< sim.getColor("cabelo")<<"\n";
  cout << "\033[1;32m 💇 Orelha: \033[0m" << sim.config.orelha <<" | "<< sim.getColor("orelha")<<"\n";
  cout << "\033[1;32m 🤨 Sobrancelha: \033[0m" << sim.config.sobrancelha <<" | "<< sim.getColor("sobrancelha")<<"\n";
  cout << "==========================\n";

  return out;
}

void SimsAppearance::setColor(string opcao,int color)
{
    config.color[opcao] = Sims::getColor(color);
}

string SimsAppearance::getColor( string opcao) const
{
    try {
        return config.color.at(opcao); //Lança uma exceção std::out_of_range se a chave não for encontrada no mapa. Portanto, é uma maneira mais segura de acessar elementos quando você deseja ter certeza de que a chave existe. Diferente de [] que não gera exeção
    }catch (const std::out_of_range&) {
        // Trate a situação em que a opção não existe no mapa
        return ""; // Retorna uma string vazia como valor padrão.
    }
}


const SimsAppearance &SimsAppearance::operator=(const SimsAppearance &other) {
    if (this == &other) {
        return *this; // Verificação para autopr atribuição
    }
    config = other.config;
    return *this;
}

int SimsAppearance::operator==(const SimsAppearance &other) const {
    return config.cabeca == other.config.cabeca &&
           config.olhos == other.config.olhos &&
           config.nariz == other.config.nariz &&
           config.boca == other.config.boca &&
           config.orelha == other.config.orelha &&
           config.cabelo == other.config.cabelo &&
           config.sobrancelha == other.config.sobrancelha;
}

int SimsAppearance::operator!=(const SimsAppearance &other) const {
    return !(*this == other);
}

// Função  para atribuir "" a uma string
void SimsAppearance::limpaCaracteristica(  string &caracteristica ) {
    caracteristica = ""; 
};

void SimsAppearance::operator!() // "zera"/"esvazia" aparência;
{
    limpaCaracteristica(config.cabeca);
    limpaCaracteristica(config.olhos);
    limpaCaracteristica(config.nariz);
    limpaCaracteristica(config.boca);
    limpaCaracteristica(config.orelha);
    limpaCaracteristica(config.cabelo);
    limpaCaracteristica(config.sobrancelha);

    for (auto& item : config.color) {
        limpaCaracteristica(item.second);
    }
};