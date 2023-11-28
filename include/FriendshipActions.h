#ifndef FRIENDSHIP_ACTIONS_H
#define FRIENDSHIP_ACTIONS_H
#include <vector>
#include "RelationshipStories.h"
#include "Sims.h"
using std::vector;

struct Action
{
    string actionName;
    int custo; //energia
    int pontosDeEvento;
}; 

class FriendshipActions : public RelationshipStories {
    friend ostream& operator<<(ostream& out, const FriendshipActions& );

    public:
        FriendshipActions();
        FriendshipActions(const RelationshipStories&, const vector <Action> &);
        FriendshipActions(const FriendshipActions& other);
        ~FriendshipActions();

        const FriendshipActions& operator=(const FriendshipActions& other);
        bool operator==(const FriendshipActions& other) const;
        bool operator!=(const FriendshipActions& other) const;
        bool operator!() const;

        void showActions()const ;
        void executeAction (Sims*,int);
        int getCurrentPontos() const { return currentPontos; };
        inline int getTamActions() const { return actions.size(); } ;

    private:

        const int MAXPONTOSEVENTOS=10;
        int currentPontos;
        vector <Action> actions;
};

#endif // FRIENDSHIP_ACTIONS_H
