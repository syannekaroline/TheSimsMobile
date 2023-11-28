#include "LeisurePlace.h"
using std::cin;
// Códigos de cores ANSI para o terminal
const string RESET = "\033[0m";
const string VERDE = "\033[1;32m";  // Texto verde brilhante
const string VERMELHO = "\033[1;31m";  // Texto vermelho brilhante

LeisurePlace::LeisurePlace() : Building(){

    simsList.emplace_back("Claudomiro", "Sales", 'M', 9,30,20000 );
    simsList.emplace_back("Jake", "Sully", 'M', 5);
    simsList.emplace_back("Ana", "Caetano", 'F',7,30,1000000);
    simsList.emplace_back("Vitória", "Falcão", 'F',30,1000000);
    simsList.emplace_back("Mike", "Tulio", 'F',30,1000000);
    simsList.emplace_back("Lucas", "Mamede", 'F',30,1000000);

}

LeisurePlace::LeisurePlace(const tuple<int, int>& proporcao, const string& districtName, const string& name, const FriendshipActions& friendshipActions, const RomanticActions& romanticActions)
:Building(proporcao,districtName, name), friendshipActions(friendshipActions), romanticActions(romanticActions)
{
    // Adicionando objetos Sims à lista
    simsList.emplace_back("Claudomiro", "Sales", 'M', 9,30,20000 );
    simsList.emplace_back("Jake", "Sully", 'M', 5);
    simsList.emplace_back("Ana", "Caetano", 'F',7,30,1000000);
    simsList.emplace_back("Vitória", "Falcão", 'F',9,30,1000000);
    simsList.emplace_back("Mike", "Tulio", 'M',7,30,1000000);
    simsList.emplace_back("Lucas", "Mamede", 'M',7,30,1000000);

}

LeisurePlace::LeisurePlace(const LeisurePlace &other)
    : Building(static_cast<Building>(other)), simsList(other.simsList), friendshipActions(other.friendshipActions), romanticActions(other.romanticActions) {}

LeisurePlace::~LeisurePlace()
{
}

void LeisurePlace::setSimsList(const vector<Sims> &simsList)
{
    this->simsList = simsList;
}

vector<Sims> LeisurePlace::getSimsList() const
{
    return simsList;
}

void LeisurePlace::setFriendshipActions(const FriendshipActions& friendshipActions)
{
    this->friendshipActions = friendshipActions;
}

void LeisurePlace::setRomanticActions(const RomanticActions& romanticActions)
{
    this->romanticActions = romanticActions;
}

void LeisurePlace::socialize(Sims *sim)
{
   // Mostrar lista de Sims disponíveis para socialização
    cout << "Escolha um sim para socializar:\n";
    for (size_t i = 0; i < simsList.size(); ++i)
    {
        cout << i + 1 << ". " << simsList[i].getNomeCompleto() << "\n";
    }

    // Receber a opção escolhida pelo usuário
    int escolha;
    cout << "Opção: ";
    cin >> escolha;

    // Verificar se a escolha está dentro dos limites
    if (escolha < 1 || escolha > static_cast<int>(simsList.size()))
    {
        cout << VERMELHO<<"Opção inválida.\n"<<RESET;
        return;
    }

    // Obter o Sim escolhido
    Sims &simEscolhido = simsList[escolha - 1];
    system("clear"); // Comando para limpar o terminal em sistemas Unix-like (Linux, macOS)
    cout<<VERDE<<"sim Escolhido: "<<simEscolhido.getNomeCompleto()<<RESET<<"\n";
    // Mostrar opções de ação
    cout<<"+--------------------------------------------------------+\n";
    cout << "Escolha uma ação:\n";
    cout << "1. Ações de amizade\n";
    cout << "2. Ações românticas\n";

    // Receber a opção de ação
    int opcaoAcao;
    cout << "Opção: ";
    cin >> opcaoAcao;
    system("clear"); // Comando para limpar o terminal em sistemas Unix-like (Linux, macOS)
    // Executar a ação correspondente
    if(opcaoAcao == 1)
    {
        sim->fazerApresentacaoAgradavel(simEscolhido);


        for (int i = 1; i <= friendshipActions.getTamSimsList();i++)
        {
            friendshipActions.executeAction(sim,i);
        }
    
    }
    else if (opcaoAcao == 2)
    {
        romanticActions.startEvent(&simEscolhido);
    }
    else
    {
        cout << "Opção inválida.\n";
    }
}

const LeisurePlace &LeisurePlace::operator=(const LeisurePlace &other)
{
    if (this != &other)
    {
        static_cast<Building &>(*this) == static_cast<const Building &>(other);
        simsList = other.simsList;
        friendshipActions = other.friendshipActions;
        romanticActions = other.romanticActions;
    }
    return *this;
}

bool LeisurePlace::operator==(const LeisurePlace &other) const
{
    return (static_cast<const Building &>(*this) == static_cast<const Building &>(other) &&
            simsList == other.simsList &&
            friendshipActions == other.friendshipActions &&
            romanticActions == other.romanticActions
            &&
            ( //para comparar os elementos dos vetores actions dos dois 
            equal(simsList.begin(), simsList.end(), other.simsList.begin(), other.simsList.end(), 
            [](const Sims& simA, const Sims& simB)
            {
                return ( simA == simB  ); 
            }
            )
        ));
}

bool LeisurePlace::operator!=(const LeisurePlace &other) const
{
    return !(*this == other);
}

bool LeisurePlace::operator!() const
{
    // Implementação baseada na ausência da lista de Sims
    return simsList.empty();
}

ostream &operator<<(ostream &out, const LeisurePlace &leisurePlace)
{
    out << static_cast<const Building &>(leisurePlace) // Chama o operador << da classe base Building
       << "\nSims List: ";
        for (size_t i = 0; i < leisurePlace.getSimsList().size(); ++i) {
            out << i + 1 << ". " << leisurePlace.getSimsList()[i] << "\n";
        }
       out<< "\n Ações de amizade: " << leisurePlace.friendshipActions
       << "\n Ações românticas: " << leisurePlace.romanticActions;
    return out;
}