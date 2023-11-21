#include "QuickShift.h"
using std::cin;

// Construtor padrão
QuickShift::QuickShift()
: StoriesCareer(), actions()
{

}

// Construtor com parâmetros
QuickShift::QuickShift(const StoriesCareer& carreiraHistoria,const vector<string>& actions)
    : StoriesCareer(carreiraHistoria), actions(actions) {}

// Construtor de cópia
QuickShift::QuickShift(const QuickShift& other)
: StoriesCareer(other), actions(other.actions) {}

// Destrutor
QuickShift::~QuickShift()

{}

// Operador de atribuição
QuickShift& QuickShift::operator=(const QuickShift& other) {
    if (this != &other) {
        *static_cast<StoriesCareer*>(this) = static_cast<StoriesCareer>(other);
        actions = other.actions;
    }
    return *this;
}

// Operador de comparação de igualdade
bool QuickShift::operator==(const QuickShift& other) const {
    return (static_cast<StoriesCareer>(*this) == static_cast<const StoriesCareer>(other)
           && actions == other.actions);
}

// Operador de comparação de desigualdade
bool QuickShift::operator!=(const QuickShift& other) const {
    return !(*this == other);
}

// Operador lógico de negação
bool QuickShift::operator!() const {
    return actions.empty();
}

// Operador de saída
ostream& operator<<(ostream& out, const QuickShift& story) {
    out << static_cast<const StoriesCareer&>(story);  // Chamando o operador de saída da classe base
    out << "Actions:\n";
    for (const auto& action : story.actions) {
        out << "- " << action << "\n";
    }
    return out;
}

// Método para iniciar um evento padrão
void QuickShift::iniciarEvento(Sims* sim) {

    int points = 0;
    int pointsMaxEvent = 15;

    if (sim->getNome() != getSimWorker()) {
        cout << "Erro: O Sim não corresponde ao trabalhador associado a este evento.\n";
        return;
    }
    
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

        if (choice == -1) {
            cout << "Evento interrompido\n";
            break;  // Finalizar o evento
        }

        // Executar ação escolhida
        if (choice >= 1 && static_cast<size_t>(choice - 1) < actions.size()) {
            // Simular ação entre sims e subtrair energia
            // Adicionar pontos de carreira
            points += 5;
            sim->diminuirEnergia(1);

            cout << "Ação executada: " << actions[choice - 1] << "\n";
            cout << "Pontos de evento: ⭐ " << points << "\n";

            // Verificar se os pontos atingiram o limite
            if (getPontosCarreira() >= getMaxPointsCareer())
            {
                //Incrementar a parte da classe base StoriesCareer
                StoriesCareer::operator++();
                // Zerar pontos para o próximo evento
                resetPontosDeCarreira();
                // ...
            }
        } else {
            cout << "Escolha inválida. Tente novamente.\n";
        }
    }

    addPontosDeCarreira(RECOMPENSA_PC);
    sim->addSimCash(RECOMPENSA_SIMCASH);
    sim->addXp(10);

    cout<< "\n+--------------------+\n";
    cout<< "Bom trabalho!!✅\n";
    cout<< "Trabalhar em um turno rápido - recompensas:\n";
    cout<< "❇️ "<<DURACAO<<"h\n";
    cout<< "❇️ 10 xp\n";
    cout<< "❇️ "<< RECOMPENSA_SIMCASH <<" SimCashs\n";
    cout<< "❇️ "<< RECOMPENSA_PC<<" pontos de carreira.\n";
}
