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
                                                                 ,-,-.
                                                       _(    _)
                                                      (__,`-'
                                            ,'`.   .-----,
                             __           ,','`.`.  |   |
                  _____    ,'  `.       ,','    `.`.|---|
              _,-'     \  /      \    ,',' _____  `.`.  |
           ,-'          \ \      /  ,','  |  |  |   `.`.|
         ,'           ___\ `.__.' ,','__  |--|--|   __'.`.         _
        /         _,-'     .----. \|    \ |__|__|  /    |/      ,-' \ TM
       |        ,'         |    |  |     \        /     |    ,-'    _\
       |        |          |    |  |      \      /      |  ,'    ,-'
        \       \          |    |  |       \    /       | /     /
         \       \         |    |  |        \  /        | |    ( 
          \       `.       |    |  |         \/         |  \    \
 ____ _    `.       `.     |    |  |    \          /    |   `.   `.
'-..-'||     `.       `.   |    |  |    |\        /|    |     `.   `.
  ||  ||__   __`.       \  |    |  |    | \      / |    |       \    \
  ||  |.-.\ /__\ \       \ |    |  |    |  \    /  |    |      ,'    /
  ||  || || \__, /       | |    |  |    |   \__/   |    | __,-'    ,'
               ,'        / |    |  |    |          |    | \     ,-'
        ____,-'        ,'  |____|  |    |          |    |  \_,-'
        \            ,'            |____|          |____|
         \       _,-'
          \___,-'

       )"<< RESET<<"\n";

  //construtor com parâmetros
  cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
  cout << "Sim com atributos personalizados.\n";
  Sims meuSim("Syanne", "Karoline",  'F' , 7, 7.0,225000);

  //criando ponteiros pra manipular objeto
  Sims *meuSimPtr = &meuSim;
  meuSimPtr->descansar();
  cout << "Usando metodo get para obter nova energia com ponteiro: " << meuSimPtr->getEnergia() << "\n";

  //Utilizando parâmetro default do construtor mostrando a limitação de string
  cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
  cout << "Sim com atributos personalizados utilizando parâmetro de energia default.\n";

  cout<<"Criando um objeto Sim e armazenando seu endereço em um ponteiro comm alocação de memória:\n";
  Sims *simCiclanoPtr = new Sims("Ciclanojncjcnkdjfnsdkcjscdscsdfcdfcdsc", "da silva",  'M' , 7);
  simCiclanoPtr->simVisaoGeral();

  meuSimPtr->fazerApresentacaoAgradavel(*simCiclanoPtr);
  meuSimPtr->verContatos();
  meuSimPtr->fazerApresentacaoAgradavel(*simCiclanoPtr);
  cout<<" < Deletando objeto simCiclano pois não será mais utilizado > ";
  delete simCiclanoPtr;
  simCiclanoPtr=0;

  // construindo objeto da classe SimsHouse
  cout<< "\n\nCriando objeto da classe SimsHouse com alocação de memória: \n";

  SimsHouse *casaMeuSimPtr = new SimsHouse;
  casaMeuSimPtr->overview();

  cout<< "\n\nDeletando objeto da classe SimsHouse padrão para realocar uma premium...\n";
  delete casaMeuSimPtr;
  casaMeuSimPtr =0;

  cout<<"\nCriando SimsHouse Premium com realocação de memória...\n";
  cout <<"\n ATENÇÃO! O valor mínimo de uma casa SimsHouse premium é de " << SimsHouse::getMinValorPremiumHouse() <<" SimsCash\n";
  casaMeuSimPtr= new SimsHouse(make_tuple(30, 30),224000,"Sem proprietário","Pôr do sol Plantão 90");
  casaMeuSimPtr->overview();
  
  cout<< "\nEfetuando venda da SimsHouse: \n";
  casaMeuSimPtr->efetuarVenda(meuSim);
  meuSimPtr->simVisaoGeral();
  casaMeuSimPtr->overview();
  meuSimPtr->verConquistas();

  cout<< "\n\nCriando objetos const usando construtor de cópia: \n";

  const Sims SYANNE(meuSim);
  //objetos const só podem chamar métodos const
  SYANNE.simVisaoGeral();
  SYANNE.verConquistas();

  //mostrando a quantidade de casas já criadas com atributo static
  // cout<< "\n\nJá foram criadas "<< SimsHouse::getNumSimsHouses() << " SimsHouses \n" ;
  // // usando método estatico
  // SimsHouse::mostrarVizinhanca();

  // usando a ação de limparSimshouse
  meuSimPtr->limparSimsHouse();
  meuSimPtr->registrarConquista("Dedicação na faxina.");
  meuSimPtr->verConquistas();
  meuSimPtr->simVisaoGeral();
  //usando array static
  cout<< "\nUsando Classe SimsAppearance com alocação de memória\n";
  SimsAppearance *aparenciaSimsPtr = new SimsAppearance;
  aparenciaSimsPtr->visualizarAppearance();

  // usando método estático da classe SimsAppearance
  SimsAppearance::exibirMenuConfiguracoes();

  // pegar apenas consiguração dos cabelos
  cout << "\n\nBuscando apenas configurações de cabelo: \n";
  SimsAppearance::exibirMenuConfiguracoes(CABELO);

  //Deletes
  delete casaMeuSimPtr;
  delete aparenciaSimsPtr;

  return 0;
}