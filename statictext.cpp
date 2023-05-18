#include "statictext.hpp"
#include "graphics.hpp"
using namespace genv;


Statictext::Statictext(Aplication* parent,int x, int y, int sx, int sy, string text):Widget(parent,x,y,sx,sy)
{
    _text = text;
}

Statictext::~Statictext()
{}


void Statictext::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
     gout << color(255,255,255);
     gout << move_to(_x+4, _y+(_size_y/2));
     gout << text(_text);

}

void Statictext::handle(event ev)
{

}
