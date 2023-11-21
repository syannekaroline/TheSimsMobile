#include "FriendshipActions.h"
#include "Sims.h"
#include <iostream>
#include <vector>
using std::vector;

FriendshipActions::FriendshipActions()
: StoriesRelationship(), MAXPONTOSEVENTOS(100), currentPontos(0)
{
    // Adicionando algumas actions ao vector
    actions.push_back({"Ação 1", 10, 20});
    actions.push_back({"Ação 2", 15, 25});
    actions.push_back({"Ação 3", 12, 18});

}

FriendshipActions::FriendshipActions(const StoriesRelationship& storiesRelationship,const vector <Action> & actionsList)
:StoriesRelationship(storiesRelationship), currentPontos(0), actions(actionsList)
{

}

FriendshipActions::FriendshipActions(const FriendshipActions& other)
: StoriesRelationship(other), MAXPONTOSEVENTOS(other.MAXPONTOSEVENTOS), currentPontos(other.currentPontos), actions(other.actions) {}

FriendshipActions::~FriendshipActions() {}

FriendshipActions& FriendshipActions::operator=(const FriendshipActions& other) {
    if (this != &other) {
        *static_cast< StoriesRelationship * >( this ) = static_cast< StoriesRelationship >( other );
        currentPontos = other.currentPontos;
        actions = other.actions;
    }
    return *this;
}
// Se comentar os operadores == e != o programa é compilado sem erros -> ainda em análise
// Operador de comparação de igualdade
bool FriendshipActions::operator==(const FriendshipActions& other) const {
    return (static_cast< StoriesRelationship >( *this ) == static_cast< StoriesRelationship >( other )&&
    currentPontos == other.currentPontos &&
    actions == other.actions);
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
        cout << "\nCusta: ⚡ " << actions[i].custo;
        cout<<"\n+-------------------------------+\n";
    }
}

void FriendshipActions::executeAction( Sims *sim, int index) {

    cout<<"Executando: "<<actions[index-1].actionName<<"\n";
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
    out << static_cast<StoriesRelationship>(actions);
    out << "| Pontos de evento: " << actions.getCurrentPontos() << "\n";
    return out;
}
