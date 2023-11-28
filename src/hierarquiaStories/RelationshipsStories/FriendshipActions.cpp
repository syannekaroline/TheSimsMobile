#include "FriendshipActions.h"
#include "Sims.h"
#include <iostream>
#include <vector>
using std::vector;

const string RESET = "\033[0m";
const string VERDE = "\033[1;32m";  // Texto verde brilhante
const string VERMELHO = "\033[1;31m";  // Texto vermelho brilhante

FriendshipActions::FriendshipActions()
: RelationshipStories(), MAXPONTOSEVENTOS(100), currentPontos(0)
{
    // Adicionando algumas actions ao vector
    actions.push_back({"Ação 1", 10, 20});
    actions.push_back({"Ação 2", 15, 25});
    actions.push_back({"Ação 3", 12, 18});

}

FriendshipActions::FriendshipActions(const RelationshipStories& relationshipStories,const vector <Action> & actionsList)
:RelationshipStories(relationshipStories), currentPontos(0), actions(actionsList)
{

}

FriendshipActions::FriendshipActions(const FriendshipActions& other)
: RelationshipStories(static_cast< RelationshipStories >( other )), MAXPONTOSEVENTOS(other.MAXPONTOSEVENTOS), currentPontos(other.currentPontos), actions(other.actions) {}

FriendshipActions::~FriendshipActions() {}

const FriendshipActions& FriendshipActions::operator=(const FriendshipActions& other) {
    if (this != &other) {
        *static_cast< RelationshipStories * >( this ) = static_cast< RelationshipStories >( other );
        currentPontos = other.currentPontos;
        actions = other.actions;
    }
    return *this;
}

// Operador de comparação de igualdade
bool FriendshipActions::operator==(const FriendshipActions& other) const {
    return 
    (    
        static_cast<RelationshipStories>(*this) == static_cast<RelationshipStories>(other) &&
        currentPontos == other.currentPontos &&

        ( //para comparar os elementos dos vetores actions dos dois 
            std::equal(actions.begin(), actions.end(), other.actions.begin(), other.actions.end(), 
            [](const Action& a, const Action& b)
            {
                return (   
                            a.actionName == b.actionName && 
                            a.custo == b.custo &&
                            a.pontosDeEvento == b.pontosDeEvento
                        ); 
            }
            )
        )
    );
}
bool FriendshipActions::operator!=(const FriendshipActions& other) const {
    return !(*this == other);
}

bool FriendshipActions::operator!() const {
    return actions.empty();
}

void FriendshipActions::showActions() const {
    cout << "\n| Friendship Actions:\n";
    for (int i = 0; i < actions.size(); ++i) {
        
        cout << i + 1 << ". " << actions[i].actionName;
        cout<< "\nGanha: ⭐ " << actions[i].pontosDeEvento;
        cout <<"\nCusta: ⚡ " << actions[i].custo;
        cout<<"\n+-------------------------------+\n";
    }
}

void FriendshipActions::executeAction( Sims *sim, int index) {

    
    cout<<VERDE<<"Executando: "<<actions[index-1].actionName<<"\n"<<RESET;
    if (index-1 >= 0 && static_cast<size_t>(index-1) < actions.size()) {
        currentPontos += actions[index-1].pontosDeEvento;
        sim->setEnergia(sim->getEnergia() - actions[index-1].custo);
        if (currentPontos >= MAXPONTOSEVENTOS) {
            int recompensa = getRecompensaCap(getParte());
            //Sims ganha a recompensa por capítulo    
            sim->setSimCash(sim->getSimCash() + recompensa );
            sim->addXp(recompensa);
            // Incrementa a parte da classe base Stories
            Stories::operator++();
            // Zera a pontuação pro pŕoxima parte da história
            currentPontos = 0;
        } 
    }
}

ostream& operator<<(ostream& out, const FriendshipActions& actions) {
    // Chama o operador << da classe base
    out << static_cast<RelationshipStories>(actions);
    out << "| Pontos de evento: " << actions.getCurrentPontos() << "\n";
    return out;
}
