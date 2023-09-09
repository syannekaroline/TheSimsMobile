#include <iostream>
#include "Sims.h"
using std::cout;

int main() {
  cout << "Usando Sims no main\n";

  //usando diferentes construtores
  //contrutor padrão
  cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
  Sims simPadrao;
  cout << "Sim com atributos padrao\n";
   //usando set
  cout << "Usando metodo set para configurar tonalidadeDaPele pra cor azul \n";
  simPadrao.setTonalidadeDaPele(5);   
  simPadrao.simVisaoGeral();

  //construtor com parâmetros
  cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
  cout << "Sim com atributos personalizados.\n";
  Sims meuSim("Syanne", "Karoline",  'F' , 7, 7.0);
  meuSim.simVisaoGeral();
  meuSim.descansar();
  cout << "Usando metodo get para obter nova energia: " << meuSim.getEnergia() << "\n";

  return 0;

}
