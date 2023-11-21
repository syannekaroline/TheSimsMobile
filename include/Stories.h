#ifndef STORIES_H
#define STORIES_H
#include <string>
#include <iostream>
#include <map>

using std::map;
using std::string;
using std::ostream;

class Stories {
    friend ostream& operator<<(ostream& out, const Stories& story);
public:
    Stories();
    Stories(const string&, const string&, const string&,const map<int,string>);
    Stories(const Stories& other);
    ~Stories();

    string getTitle() const;
    string getSubtitle() const;
    string getDescription() const;
    inline int getParte() const{ return parte;};
    int getRecompensaCap(int index) const;
    void resetParte(){ parte = 1; };

    Stories& operator=(const Stories& other);
    bool operator==(const Stories& other) const;
    bool operator!=(const Stories& other) const;
    bool operator!() const;
    void operator++();//acrescenta 1 a parte


private:
    string title;
    string subtitle;
    string description;
    map<int,string> capitulos; //recompensa por capítulo
    int parte;
};

#endif // STORIES_H
