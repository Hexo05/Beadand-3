#include "textedit.hpp"
#include "graphics.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace genv;
using namespace std;

Textedit::Textedit(Aplication* parent,int x,int y,int sx,int sy,string text):Widget(parent,x,y,sx,sy)
{
    _text = text;



    _cuoursorloc = _x+gout.twidth(_text);
    _hol = _text.size();  //(szöveg i edik eleme ahol a kurzor áll)
}

/*void Textedit::coursorflash(int ertek)
{
    _villan =ertek;
}*/


void Textedit::draw()
{
    gout << move_to(_x, _y) << color(25,25,25) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(255,255,255) << box(_size_x-4, _size_y-4);
    gout << color(0,0,0);
    gout << move_to(_x+4, _y+(_size_y/2));
    gout << text(_text);


        gout << move_to(_cuoursorloc+5,_y+(_size_y/2)-15);
        gout << line_to(_cuoursorloc+5,_y+(_size_y/2)+10);

}

string Textedit::getertek() const
{
    return _text;
}


void Textedit::movecoursor()
{
    string newstring = "";

    for(int i = 0; i < _hol; i++)
    {
        newstring += _text[i];
    }

    _cuoursorloc = _x+gout.twidth(newstring);
}


void Textedit::handle(event ev)
{
    if (ev.type == ev_key and ev.keycode >= 0) {
        if(ev.keycode != key_left and ev.keycode != key_right and ev.keycode != key_backspace)
        {
                 cout << "ir";
                 char c =  (*ev.keyutf8.c_str());
                 _text.insert(_hol, 1, c);

                  _hol = _hol+1;
                    movecoursor();
        }
        else
        {
                if (ev.keycode == key_left)
                {
                     cout << "left";

                    if(_hol-1 >= 0)
                     {
                         _hol = _hol -1;
                         movecoursor();
                     }

                }

                if (ev.keycode == key_right)
                {
                    cout << "right";
                    if(_hol+1 <= _text.size())
                    {
                        _hol++;
                        movecoursor();
                    }

                }

                if (ev.keycode == key_backspace)
                {
                    //_text = utf8_remove_last(_text);
                    if(_hol-1 >= 0)
                    {
                        _text.erase(_hol-1,1);

                        _hol = _hol-1;
                        movecoursor();
                    }

                }
        }


    }

}
