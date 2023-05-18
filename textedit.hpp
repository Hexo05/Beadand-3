#ifndef TEXTEDIT_HPP
#define TEXTEDIT_HPP
#include "widgets.hpp"
using namespace std;
using namespace genv;

class Textedit : public Widget
{
protected:
       string _text;
    int _cuoursorloc;
       int _hol;
    int _villan;

public:
    Textedit(Aplication*,int,int,int,int,string);

    virtual ~Textedit()
    {}
    virtual void draw() ;
    virtual void handle(genv::event ev);
    void movecoursor();
    string getertek() const;
   // void coursorflash(int);
};

#endif // TEXTEDIT_HPP
