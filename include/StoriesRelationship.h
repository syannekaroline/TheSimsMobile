#ifndef STORIESRELATIONSHIP_H
#define STORIESRELATIONSHIP_H
#include "Stories.h"

class StoriesRelationship : public Stories {
    friend ostream& operator<<(ostream& out, const StoriesRelationship& story);

public:
    StoriesRelationship();
    StoriesRelationship(const string&, const string&, const string&, const map<int, string>&,const string&);
    StoriesRelationship(const StoriesRelationship& other);
    ~StoriesRelationship();

    StoriesRelationship& operator=(const StoriesRelationship& other);
    bool operator==(const StoriesRelationship& other) const;
    bool operator!=(const StoriesRelationship& other) const;
    bool operator!() const;

    string getSimInvolved() const {return simInvolved;};

private:
    string simInvolved;
};

#endif // STORIESRELATIONSHIP_H

