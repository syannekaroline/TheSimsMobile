// RomanticActions.cpp
#include "RomanticActions.h"
#include <iostream>
using std::cin;
const string RESET = "\033[0m";
const string VERDE = "\033[1;32m";  // Texto verde brilhante
const string VERMELHO = "\033[1;31m";  // Texto vermelho brilhante

// Defina os emojis correspondentes às ações
const string EMOJI_PIADA = "😄";
const string EMOJI_CANTADA = "😍";
const string EMOJI_CONVERSA = "💬";
const string EMOJI_BEIJO = "😘";

// Construtor padrão
RomanticActions::RomanticActions() 
: RelationshipStories(), relationshipStatus("Não definido"),pair("")
{

}

// Construtor parametrizado
RomanticActions::RomanticActions(const RelationshipStories& relationshipStories, const string& pair)
: RelationshipStories(relationshipStories), pair(pair), relationshipStatus("Não definido"), UPCAP(50)
{

}
RomanticActions::RomanticActions(const string& titulo, const string& subtitulo, const string& descricao, const map<int, string>& capitulos,const string& sim,const string& pair)
:RelationshipStories(titulo,subtitulo,descricao,capitulos,sim), pair(pair), relationshipStatus("Não definido"), UPCAP(50)
{
}

// Construtor de cópia
RomanticActions::RomanticActions(const RomanticActions& other)
: RelationshipStories(other), pair(other.pair), relationshipStatus(other.relationshipStatus), UPCAP(other.UPCAP) {}

// Destrutor
RomanticActions::~RomanticActions() {}

// Operador de atribuição
const RomanticActions& RomanticActions::operator=(const RomanticActions& other) {
    if (this != &other) {
        *static_cast< RelationshipStories * >( this ) = static_cast< RelationshipStories >( other );	
        pair = other.pair;
        relationshipStatus = other.relationshipStatus;
    }
    return *this;
}

// Operador de comparação de igualdade
bool RomanticActions::operator==(const RomanticActions& other) const {
    return (static_cast< RelationshipStories >( *this ) == static_cast< RelationshipStories >( other )&&
           pair == other.pair &&
           relationshipStatus == other.relationshipStatus);
}

// Operador de comparação de desigualdade
bool RomanticActions::operator!=(const RomanticActions& other) const {
    return !(*this == other);
}

// Operador lógico de negação
bool RomanticActions::operator!() const {
    return pair=="";
}

// Método para iniciar um evento romântico
void RomanticActions::startEvent(Sims* sim) {
    int points = 0;
    if (sim->getNomeCompleto() != pair){
        resetParte();// reinicia os capítulos caso necessário; 
        pair = sim->getNomeCompleto();
    }
    cout<<getSimInvolved()<<" ❤️ "<< pair <<"\n";
    while (true) {
        // Exibir menu de ações
        cout<<"\n+----------------------------------------+\n";
        cout << "Menu de Ações:\n";
        cout << "1. Contar piada paqueradora " << EMOJI_PIADA << "\n";
        cout << "2. Dar cantada em " << EMOJI_CANTADA << "\n";
        cout << "3. Ficar de conversa fiada " << EMOJI_CONVERSA << "\n";
        cout << "4. Beijar " << EMOJI_BEIJO << "\n";
        cout << "-1. Finalizar o evento\n";

        int choice;
        cout << "Insira a ação que deseja executar:";
        cin >> choice;

        if (choice == -1) {
            break; // Finalizar o evento
        }
        system("clear");
        cout<<VERDE;
        // Executar ação escolhida
        switch (choice) {
            case PIADA:
                // Simular ação entre sims e subtrair energia
                // Adicionar pontos de evento
                points += 10;
                cout << "Executando ação: Contar piada paqueradora " << EMOJI_PIADA << "\n";
                break;
            case CANTADA:
                // Simular ação entre sims e subtrair energia
                // Adicionar pontos de evento
                points += 10;
                cout << "Executando ação: Dar cantada em " << EMOJI_CANTADA << "\n";
                break;
            case CONVERSA:
                // Simular ação entre sims e subtrair energia
                // Adicionar pontos de evento
                points += 10;
                cout << "Executando ação: Ficar de conversa fiada " << EMOJI_CONVERSA << "\n";
                break;
            case BEIJO:
                // Simular ação entre sims e subtrair energia
                // Adicionar pontos de evento
                points += 10;
                cout << "Executando ação: Beijar " << EMOJI_BEIJO << "\n";
                break;
            default:
                cout <<VERMELHO<< "Escolha inválida. Tente novamente.\n";
        }
        cout<<RESET;
        cout<<"\nPontos de evento:  ⭐ "<<points<<"\n";
        // Verificar se os pontos atingiram o limite
        if (points >= UPCAP) {
            // Incrementar a parte da classe base Stories
            Stories::operator++();
            // Zerar pontos para o próximo evento
            points = 0;
            break; // Finalizar o evento
        }
    }
}

// Método para definir o status do relacionamento
void RomanticActions::setRelationshipStatus(const string& status) {
    relationshipStatus = status;
}

// Operador de inserção para facilitar a exibição
ostream& operator<<(ostream& out, const RomanticActions& romanticActions) {
    // Chama o operador << da classe base
    out << static_cast<const RelationshipStories&>(romanticActions);

    // Adiciona informações específicas de RomanticActions
    out << "| pair: "<<romanticActions.pair;
    out << "\n| Relationship Status: " <<romanticActions.relationshipStatus<< "\n";

    return out;
}
