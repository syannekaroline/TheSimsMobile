#include <iostream>
#include "Sims.h"
#include "SimsHouse.h"
using std::cout;
using std::make_tuple;

int main() {
  cout << "Usando Sims no main\n";

  //usando diferentes construtores

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

  //criando SimsHouse Premium
  SimsHouse HousePremium(make_tuple(30, 30),true,224000,"Sem proprietário","Pôr do sol Plantão 90");
  HousePremium.overview();

  return 0;
}
