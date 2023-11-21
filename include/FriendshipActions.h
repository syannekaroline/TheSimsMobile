#ifndef FRIENDSHIP_ACTIONS_H
#define FRIENDSHIP_ACTIONS_H
#include <vector>
#include "StoriesRelationship.h"
#include "Sims.h"
using std::vector;

struct Action
{
    string actionName;
    int custo; //energia
    int pontosDeEvento;
}; 

class FriendshipActions : public StoriesRelationship {
    friend ostream& operator<<(ostream& out, const FriendshipActions& );

    public:
        FriendshipActions();
        FriendshipActions(const StoriesRelationship&, const vector <Action> &);
        FriendshipActions(const FriendshipActions& other);
        ~FriendshipActions();

        FriendshipActions& operator=(const FriendshipActions& other);
        bool operator==(const FriendshipActions& other) const;
        bool operator!=(const FriendshipActions& other) const;
        bool operator!() const;

        void showActions()const ;
        void executeAction (Sims*,int);
        int getCurrentPontos() const { return currentPontos; };

    private:

        const int MAXPONTOSEVENTOS=10;
        int currentPontos;
        vector <Action> actions;
};

#endif // FRIENDSHIP_ACTIONS_H
