#include <iostream>
#include "Sims.h"
#include "SimsHouse.h"
#include "SimsAppearance.h"

using std::cout;
using std::make_tuple;

const string VERDE = "\033[1;32m";  // VERDE
const string RESET = "\033[0m";  // Reset para a cor padrão
enum caracteristicas {CABECA, OLHOS,NARIZ,BOCA,ORELHA,CABELO,SOBRANCELHA};

int main() {
    cout <<VERDE;
    cout<< R"(
        ____  _____ _            ____  _               
       / /\ \|_   _| |__   ___  / ___|(_)_ __ ___  ___ 
      / /  \ \ | | | '_ \ / _ \ \___ \| | '_ ` _ \/ __|
     / /    \ \| | | | | |  __/  ___) | | | | | | \__ \
    /_/  __  \_\_|_|_| |_|\___| |____/|_|_| |_| |_|___/
    |  \/  | ___ | |__ (_) | ___                       
    | |\/| |/ _ \| '_ \| | |/ _ |                      
    | |  | | (_) | |_) | | |  __/                      
    |_|  |_|\___/|_.__/|_|_|\___|                      
    \ \      / /                                       
     \ \    / /                                        
      \ \  / /                                         
       \_\/_/                                          
       )"<< RESET<<"\n";

  //construtor com parâmetros
  cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
  cout << "Sim com atributos personalizados.\n";
  Sims meuSim("Syanne", "Karoline",  'F' , 7, 7.0,100000);
  meuSim.simVisaoGeral();
  meuSim.descansar();
  cout << "Usando metodo get para obter nova energia: " << meuSim.getEnergia() << "\n";

  //Utilizando parâmetro default do construtor mostrando a limitação de string
  cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
  cout << "Sim com atributos personalizados utilizando parâmetro de energia default.\n";

  Sims SimCiclano("Ciclanojncjcnkdjfnsdkcjscdscsdfcdfcdsc", "da silva",  'M' , 7);
  SimCiclano.simVisaoGeral();

  //construindo objeto da classe SimsHouse
  cout<< "\n\nCriando objeto da classe SimsHouse: \n";

  SimsHouse casaMeuSim;
  casaMeuSim.overview();
  cout<< "\nEfetuando venda da SimsHouse: \n";
  casaMeuSim.efetuarVenda(meuSim);
  meuSim.simVisaoGeral();
  casaMeuSim.overview();

  cout<< "\n\nCriando objetos const usando construtor de cópia: \n";

  const Sims SYANNE(meuSim);
  //objetos const só podem chamar métodos const
  SYANNE.simVisaoGeral();

  cout<<"criando SimsHouse Premium\n";
  cout <<"\n ATENÇÃO! O valor mínimo de uma casa SimsHouse premium é de " << SimsHouse::getMinValorPremiumHouse <<" SimsCash\n";
  SimsHouse HousePremium(make_tuple(30, 30),224000,"Sem proprietário","Pôr do sol Plantão 90");
  HousePremium.overview();
  
  //mostrando a quantidade de casas já criadas com atributo static
  cout<< "\n\nJá foram criadas "<< SimsHouse::getNumSimsHouses() << " SimsHouses \n" ;

  // usando método estatico
  SimsHouse::mostrarVizinhanca();

  // usando a ação de limparSimshouse
  meuSim.limparSimsHouse();
  
  //usando array static
  cout<< "\nUsando Classe SimsAppearance\n";
  SimsAppearance teste;
  teste.visualizarAppearance();

  // usando método estático da classe SimsAppearance
  SimsAppearance::exibirMenuConfiguracoes();

  // pegar apenas consiguração dos cabelos
  cout << "\n\nBuscando apenas configurações de cabelo: \n";
  SimsAppearance::exibirMenuConfiguracoes(CABELO);

  return 0;
}