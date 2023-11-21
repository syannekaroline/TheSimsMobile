#ifndef ROMANTIC_ACTIONS_H
#define ROMANTIC_ACTIONS_H
#include "StoriesRelationship.h"
#include "Sims.h"
#include <vector>
using std::vector;

enum Actions {PIADA=1,CANTADA,CONVERSA,BEIJO};

class RomanticActions : public StoriesRelationship {
    
    friend ostream& operator<<(ostream& out, const RomanticActions& );

    public:

        RomanticActions();
        RomanticActions(const StoriesRelationship&, const string& );
        RomanticActions(const RomanticActions& other);
        ~RomanticActions();

        RomanticActions& operator=(const RomanticActions& other);
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

