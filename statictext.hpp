#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "graphics.hpp"
#include "widgets.hpp"
using namespace std;
using namespace genv;


class Statictext : public Widget
{
protected:
    string _text;
public:
    Statictext(Aplication*,int,int,int,int,string);
    virtual ~Statictext();
    virtual void draw() ;
    virtual void handle(genv::event ev);
};

#endif // STATICTEXT_HPP
