#include <iostream>
#include "Sims.h"
#include "SimsHouse.h"
#include "SimsAppearance.h"
#include "SimsGame.h"
#include "util.h"
#include <string>
using std::string;
using std::getline;

#include <fstream>
using std::fstream;
using std::ifstream;
using std::ofstream;

#include <sstream>
using std::istringstream;
using std::cout;
using std::cin;
using std::make_tuple;
using std::cerr;

#include <map>
using std::map;

const string VERDECOLOR = "\033[1;32m";  // VERDE
const string RESET = "\033[0m";  // Reset para a cor padrão
enum aparencia{CABECA, OLHOS,NARIZ,BOCA,ORELHA,CABELO,SOBRANCELHA};
enum cores{VERMELHO=1,LARANJA,AMARELO,VERDE,AZUL,ROXO,MARROM,PRETO,BRANCO};
int main()
{

  map<string, long int> infosGame;

  if(!loadConfig(infosGame, "infosGame.txt" ))
    return 0;

  cout <<VERDECOLOR;
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

  SimsGame *gamePtr= new SimsGame(22,10,2010);
  SimsGame game(infosGame);
  cout<<"\n-=-=-=-= Usando sobrecarga de operadores da classe SimsGame-=-=-=-=\n";

  if (*gamePtr!=game) // operador diferença
    cout<<" jogos diferentes\n";
  if(*gamePtr==*gamePtr) // operador igualdade
    cout<<" jogos iguais\n";
  sleep (3);  // Pausa de 3 segundo
  cout<<game; //operador da classe simsGame e for_each e alocação de memória da composição com vector na classe

  //construtor com parâmetros classe SimsGame

  //construtor com parâmetros
  sleep (3);  // Pausa de 3 segundo

  cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
  cout << "Sim com atributos personalizados.\n";
  Sims meuSim("Syanne", "Karoline",  'F' , 7, 7 ,225000);

  //criando ponteiros pra manipular objeto
  Sims *meuSimPtr = &meuSim;
  meuSimPtr->descansar();
  cout << "Usando metodo get para obter nova energia com ponteiro: " << meuSimPtr->getEnergia() << "\n";

  //Utilizando parâmetro default do construtor mostrando a limitação de string
  sleep (3);  // Pausa de 3 segundo
  cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
  cout << "Sim com atributos personalizados utilizando parâmetro de energia default.\n";

  cout<<"Criando um objeto Sim e armazenando seu endereço em um ponteiro comm alocação de memória:\n";
  Sims *simCiclanoPtr = new Sims;

  meuSimPtr->fazerApresentacaoAgradavel(*simCiclanoPtr);
  meuSimPtr->verContatos();
  meuSimPtr->fazerApresentacaoAgradavel(*simCiclanoPtr);

  sleep (3);  // Pausa de 3 segundo
  cout<<"\n-=-=-=-= Usando sobrecarga de operadores da classe Sims-=-=-=-=\n";

  //sobrecarga de operadores classe sims
  sleep (3);  // Pausa de 3 segundo
  cout<< *meuSimPtr; //(friend)
  sleep (3);  // Pausa de 3 segundo
  cout<<*simCiclanoPtr;
  
  if (*meuSimPtr!=*simCiclanoPtr) // operador diferença
    cout<<" Sims diferentes\n";
  *simCiclanoPtr = *meuSimPtr; // operador de atribuição
  if(*meuSimPtr==*meuSimPtr) // operador igualdade
    cout<<" Sims gêmeos\n";
  if(!*meuSimPtr)
    cout<<"Sim não ativo no jogo -> sem composição\n";

  cout<<"< Deletando objeto simCiclano pois não será mais utilizado > \n";
  delete simCiclanoPtr;
  simCiclanoPtr=0;

  ////////////////////////////// Sims Appearance 
  sleep (3);  // Pausa de 3 segundo
  cout<<"\n-=-=-=-= Usando métodos estáticos da classe SimsAppearance-=-=-=-=\n";

  // usando método estático da classe SimsAppearance
  SimsAppearance::exibirMenuConfiguracoes();

  // pegar apenas configuração dos cabelos
  sleep (3);  // Pausa de 3 segundo
  cout << "\n\nBuscando apenas configurações de cabelo: \n";
  SimsAppearance::exibirMenuConfiguracoes(CABELO);

  sleep (3);  // Pausa de 3 segundo
  cout<< "\n-=-=-=-= Usando Classe SimsAppearance com alocação de memória -=-=-=-=\n";
  SimsAppearance *aparenciaSimsPtr = new SimsAppearance;

  sleep (3);  // Pausa de 3 segundo
  cout << "Usando composição com operador de atribuição de aparência para classe Sim\n";
  *meuSimPtr = *aparenciaSimsPtr;
  meuSim.verAparencia();

  sleep (3);  // Pausa de 3 segundo
  cout<<"\n-=-=-=-= Usando operadores da classe SimsAppearance-=-=-=-= \n";
  cout<< *aparenciaSimsPtr;

  SimsAppearance aparenciaNova("Cabeça 3","Olhos 2","Nariz 1","Boca 3","Orelha 2","Divisão Central Suave","Naturalmente Arqueadas");
  aparenciaNova.setColor("olhos",VERDE); //utilização struct

  sleep (3);  // Pausa de 3 segundo
  cout<< aparenciaNova;

  sleep (3);  // Pausa de 3 segundo
  if (aparenciaNova!=*aparenciaSimsPtr ) //operador diferença
    cout<<"Aparências diferentes\n";
  *aparenciaSimsPtr=aparenciaNova;//operador atribuição
  if(aparenciaNova==*aparenciaSimsPtr) //operador igualdade
    cout<<"Aparências iguais\n";
  !aparenciaNova;//operador negação -> pra limpar configurações e utilização do auto

  sleep (3);  // Pausa de 3 segundo
  cout<<aparenciaNova;

  sleep (3);  // Pausa de 3 segundo

  //////////////////// Composição
  sleep (3);  // Pausa de 3 segundo
  cout<<"Realizando composição entre classe Sims e classe SimGame e usando sobrecarga de operadores\n";

  if(!game)//verifica se não há sims ativos no jogo
    game.addSim(meuSim);
  *gamePtr = game; //copia lista de sims
  cout<<game;
  cout<<*gamePtr;
  if(game==game)
    cout<<"mesmo jogo\n";
  if(game!=*gamePtr)
    cout<<"jogos diferentes\n";

  sleep (3);  // Pausa de 3 segundo
  gamePtr->printSimsList();
  gamePtr->deleteLastSim();
  gamePtr->printSimsList();
  cout<<"< Deletando objeto gamePtr pois não será mais utilizado > \n";
  delete gamePtr;
  gamePtr=0;

  // construindo objeto da classe SimsHouse
  sleep (3);  // Pausa de 3 segundo
  cout<< "\n\n-=-=-=-= Criando objeto da classe SimsHouse com alocação de memória e vector de ponteiros: -=-=-=-=\n";

  //usando vector de ponteiros de Sims
  vector<SimsHouse*> bairroSim; // Criando um vector de ponteiros para objetos SimsHouse
  // Alocação de memória para as casas e adição ao vector
  bairroSim.push_back(new SimsHouse(make_tuple(10, 15), 220000,"Lagoa do verão 74"));
  bairroSim.push_back(new SimsHouse(make_tuple(40, 40), 150000,"Alameda Esmeralda, 326"));
  bairroSim.push_back(new SimsHouse(make_tuple(10, 15), 200000,"Alameda Esmeralda, 327"));

  SimsHouse *casaMeuSimPtr = new SimsHouse;
  cout<<*casaMeuSimPtr;
  sleep (3);  // Pausa de 3 segundo

  cout<< "\n\nDeletando objeto da classe SimsHouse padrão para realocar uma premium...\n";
  delete casaMeuSimPtr;
  casaMeuSimPtr =0;

  sleep (3);  // Pausa de 3 segundo
  cout<<"\nCriando SimsHouse Premium com realocação de memória...\n";
  cout <<"\n ATENÇÃO! O valor mínimo de uma casa SimsHouse premium é de " << SimsHouse::getMinValorPremiumHouse() <<" SimsCash\n";
  casaMeuSimPtr= new SimsHouse(make_tuple(30, 30),224000,"Pôr do sol Plantão 90");
  cout<< *casaMeuSimPtr;
  bairroSim.push_back(casaMeuSimPtr);

  sleep (3);  // Pausa de 3 segundo
  cout<<"\n-=-=-=-= Usando operadores da classe SimsHouse -=-=-=-= \n";
  if (*bairroSim[0]!=*casaMeuSimPtr ) //operador diferença
    cout<<"Casas diferentes\n";
  *bairroSim[0]=*casaMeuSimPtr;//operador atribuição
  if(*casaMeuSimPtr==*casaMeuSimPtr) //operador igualdade
    cout<<"Casas iguais\n";
  
  if(!*casaMeuSimPtr) //operador negação -> verifica se a casa não tem poprietário;
  {
    cout<<"Casa sem proprietário\n";
    cout<< "\nEfetuando venda da SimsHouse: \n";
    casaMeuSimPtr->efetuarVenda(meuSim);
  }

  sleep (3);  // Pausa de 3 segundo
  cout<<*meuSimPtr;
  sleep (3);  // Pausa de 3 segundo
  cout<<*casaMeuSimPtr;

  meuSimPtr->verConquistas();

  sleep (3);  // Pausa de 3 segundo
  cout<< "\n\nCriando objetos const usando construtor de cópia: \n";

  const Sims SYANNE(meuSim);
  //objetos const só podem chamar métodos const
  cout<<SYANNE;
  SYANNE.verConquistas();

  //mostrando a quantidade de casas já criadas com atributo static
  sleep (3);  // Pausa de 3 segundo
  cout<< "\n\nJá foram criadas "<< SimsHouse::getNumSimsHouses() << " SimsHouses \n" ;
  // usando método estatico
  SimsHouse::mostrarVizinhanca();

  // usando a ação de limparSimshouse
  meuSimPtr->limparSimsHouse();
  meuSimPtr->registrarConquista("Dedicação na faxina.");
  meuSimPtr->verConquistas();
  sleep (3);  // Pausa de 3 segundo
  cout<<*meuSimPtr;

  sleep (3);  // Pausa de 3 segundo
  cout<<"\n-=-=-= Usando struct da classe simsHouse-=-=-=\n";

  vector<string> comodos = {"quarto","sala de estar","banheiro","cozinha"};

  casaMeuSimPtr->setFeatures(comodos,2,true,"moderno");
  casaMeuSimPtr->addComodo("quarto suíte");

  casaMeuSimPtr->verFeatures();
  casaMeuSimPtr->removeComodo("quarto");
  casaMeuSimPtr->verFeatures();

  sleep (3);  // Pausa de 3 segundo
  cout<<"\n-=-=-=-Deletes-=-=-=-\n";
  delete aparenciaSimsPtr;

  // Liberação de memória do vector de simsHouse
  for (SimsHouse* casa : bairroSim) {
    delete casa;
  }

  return 0;
}