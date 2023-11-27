
#ifndef LEISUREPLACE_H
#define LEISUREPLACE_H

#include "FriendshipActions.h"
#include "RomanticActions.h"
#include "Building.h"

#include <vector>
using std::vector;

class LeisurePlace : public Building
{
        friend ostream &operator<<(ostream &, const LeisurePlace &);

    public:
    
        LeisurePlace();
        LeisurePlace(const tuple<int, int> &,const string &, const string &,const FriendshipActions&,const RomanticActions&);
        LeisurePlace(const LeisurePlace &other);
        ~LeisurePlace();

        // Métodos get e set
        void setSimsList(const vector<Sims> &);
        vector<Sims> getSimsList() const;
        void setFriendshipActions(const FriendshipActions& );
        void setRomanticActions(const RomanticActions&);
        FriendshipActions getFriendshipActions() const{return friendshipActions;};
        // Método específico
        void socialize(Sims*);

        // Operadores
        const LeisurePlace &operator=(const LeisurePlace &);
        bool operator==(const LeisurePlace &) const;
        bool operator!=(const LeisurePlace &) const;
        bool operator!() const;

    private:
        vector<Sims> simsList;
        FriendshipActions friendshipActions;
        RomanticActions romanticActions;
};

#endif // LEISUREPLACE_H