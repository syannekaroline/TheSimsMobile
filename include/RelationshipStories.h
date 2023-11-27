#ifndef RELATIONSHIPSTORIES_H
#define RELATIONSHIPSTORIES_H
#include "Stories.h"

class RelationshipStories : public Stories {
    friend ostream& operator<<(ostream& out, const RelationshipStories& story);

public:
    RelationshipStories();
    RelationshipStories(const string&, const string&, const string&, const map<int, string>&,const string&);
    RelationshipStories(const RelationshipStories& other);
    ~RelationshipStories();

    const RelationshipStories& operator=(const RelationshipStories& other);
    bool operator==(const RelationshipStories& other) const;
    bool operator!=(const RelationshipStories& other) const;
    bool operator!() const;

    string getSimInvolved() const {return simInvolved;};
    void setSimInvolved(string simInvolved) {this->simInvolved = simInvolved ; } ;
 
private:
    string simInvolved;

};

#endif // RELATIONSHIPSTORIES_H

