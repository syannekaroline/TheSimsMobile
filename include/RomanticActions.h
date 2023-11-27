#ifndef ROMANTIC_ACTIONS_H
#define ROMANTIC_ACTIONS_H
#include "RelationshipStories.h"
#include "Sims.h"
#include <vector>
using std::vector;

enum Actions {PIADA=1,CANTADA,CONVERSA,BEIJO};

class RomanticActions : public RelationshipStories {
    
    friend ostream& operator<<(ostream& out, const RomanticActions& );

    public:

        RomanticActions();
        RomanticActions(const RelationshipStories&, const string& );
        RomanticActions(const string&, const string&, const string&, const map<int, string>&,const string&, const string& );
        RomanticActions(const RomanticActions& other);
        ~RomanticActions();

        const RomanticActions& operator=(const RomanticActions& other);
        bool operator==(const RomanticActions& other) const;
        bool operator!=(const RomanticActions& other) const;
        bool operator!() const;

        void startEvent(Sims*);
        void setRelationshipStatus(const string &);
        inline string getRelationshipStatus() const { return relationshipStatus; };
        inline string getPair() const { return pair; };

    private:
        string pair;
        string relationshipStatus;
        const int UPCAP=10; // limite pra subir de cap
};

#endif // ROMANTIC_ACTIONS_H

