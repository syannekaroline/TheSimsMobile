#include "CareerStories.h"
#include <climits>
using std::cin;
const string RESET = "\033[0m";
const string VERDE = "\033[1;32m";  // Texto verde brilhante
const string VERMELHO = "\033[1;31m";  // Texto vermelho brilhante

const map<string,int> CareerStories::STANDARD_SHIFT = {{"duracao",4},{"recompensaSimCash",135},{"recompensaPC",90}};
const map<string,int> CareerStories::QUICK_SHIFT = {{"duracao",1},{"recompensaSimCash",45},{"recompensaPC",10}};

// Construtor padrão
CareerStories::CareerStories(): Stories(), worker(""), workplace(""),actions()
{

}

// Construtor com parâmetros
CareerStories::CareerStories(const string& title, const string& subtitle, const string& content, const map<int, string>& chapters, const string& worker, const string& workplace, const vector<string>& actions)
: Stories(title, subtitle, content, chapters), worker(worker), workplace(workplace),actions(actions)
{

}

// Construtor de cópia
CareerStories::CareerStories(const CareerStories& other)
: Stories(static_cast< Stories>( other )), worker(other.worker), workplace(other.workplace), actions(other.actions) 
{

}

// Destrutor
CareerStories::~CareerStories()
{

}

// Método para iniciar um evento padrão
void CareerStories::iniciarEvento(Sims* sim, const eventType& type) {
    
    map<string, int> typeEvent;
    int points = 0;
    int pointsMaxEvent = (type == QUICKSHIFT)? 15: 60;
    if (sim->getNome() != getSimWorker()) {
        cout << VERMELHO<<"Erro: O Sim não corresponde ao trabalhador associado a este evento.\n"<<RESET;
        return;
    }

    typeEvent = (type == STANDARDSHIFT) ? STANDARD_SHIFT : QUICK_SHIFT;

    while (points< pointsMaxEvent) {
        // Exibir menu de ações
        cout<<"\n+----------------------------------------+\n";
        cout << "Menu de Ações:\n";
        for (size_t i = 0; i < actions.size(); ++i) {
            cout << i + 1 << ". " << actions[i] << "\n";
        }
        cout << "-1. Finalizar o evento\n";

        int choice;
        cout << "Insira a ação que deseja executar:";
        cin >> choice;

        // Verificar se a entrada é um número
        if (cin.fail()) {
            cin.clear(); // Limpar o sinal de falha
            cin.ignore(INT_MAX, '\n'); // Descartar a entrada inválida
            cout << VERMELHO << "Entrada inválida. Insira um número. Tente novamente.\n" << RESET;
            continue; // Pular para a próxima iteração do loop
        }

        // Restaurar o buffer do teclado no caso de uma entrada válida
        cin.ignore(INT_MAX, '\n');

        if (choice == -1) {
            cout << "Evento interrompido\n";
            break;  // Finalizar o evento
        }

        // Executar ação escolhida
        if (choice >= 1 && static_cast<size_t>(choice - 1) < actions.size()) {
            // Simular ação entre sims e subtrair energia
            // Adicionar pontos de evento
            points += 5;
            sim->diminuirEnergia(1);

            system("clear");
            cout <<VERDE<<"Ação executada: " << actions[choice - 1] << "\n"<<RESET;
            cout << "Pontos de evento: ⭐ " << points << "\n";

        } else {
            cout << "Escolha inválida. Tente novamente.\n";
        }
    }

    pontosDeCarreira+=typeEvent["recompensaPC"];
    sim->addSimCash(typeEvent["recompensaSimCash"]);
    sim->addXp(10);

    cout<< "\n+--------------------+\n";
    cout<< VERDE<<"Bom trabalho!!✅\n"<<RESET;
    cout<< "Trabalhar em um turno"<<((type == STANDARDSHIFT)? " normal":" rápido")<<" "<<typeEvent["duracao"]<<"h - recompensas:\n";
    cout<< "❇️ 10 xp\n";
    cout<< "❇️ "<< typeEvent["recompensaSimCash"] <<" SimCash\n";
    cout<< "❇️ "<< typeEvent["recompensaPC"]<<" pontos de carreira.\n";

    // Verificar se os pontos atingiram o limite
    if (getPontosCarreira() >= getMaxPointsCareer())
    {
        //Incrementar a parte da classe base CareerStories
        CareerStories::operator++();
        // Zerar pontos para o próximo evento
        pontosDeCarreira = 0;
    }
}

// Operador de atribuição
const CareerStories& CareerStories::operator=(const CareerStories& other) {
    if (this != &other)
    {
        *static_cast<Stories*>(this) = static_cast<Stories>(other);
        worker = other.worker;
        workplace = other.workplace;
        actions = other.actions;
    }
    return *this;
}

// Operador de comparação de igualdade
bool CareerStories::operator==(const CareerStories& other) const {
    return static_cast< Stories >( *this ) == static_cast< Stories >( other ) &&
    worker == other.worker && workplace == other.workplace;
}

// Operador de comparação de desigualdade
bool CareerStories::operator!=(const CareerStories& other) const {
    return !(*this == other);
}

// Operador lógico de negação
bool CareerStories::operator!() const {
    return worker.empty() && workplace.empty();
}

// Operador de saída
ostream& operator<<(ostream& out, const CareerStories& story) {
    out << static_cast<const Stories&>(story);  // Chamando o operador de saída da classe base
    out << "| Current Pontos de Carreira no capítulo: " << story.pontosDeCarreira << "\n";
    out << "| Sim: " << story.worker << "\n";
    out << "| local: " << story.workplace << "\n";

    out << "Actions:\n";
    for (const auto& action : story.actions) {
        out << "- " << action << "\n";
    }
    return out;
}