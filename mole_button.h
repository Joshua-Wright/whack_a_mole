//
// Created by j0sh on 11/10/15.
//

#ifndef WHACK_A_MOLE_MOLE_BUTTON_H
#define WHACK_A_MOLE_MOLE_BUTTON_H

#include <FL/Fl_Button.H>
#include <iostream>

using std::cout;
using std::endl;

class mole_button : public Fl_Button {
    bool has_mole;

public:
    mole_button(int x, int y, int w) : Fl_Button(x, y, w, w), has_mole(false) { }

    void set_has_mole(bool g) {
        has_mole = g;
//        image()
        label("M");
    };

    bool get_has_mole() { return has_mole; };
};


#endif //WHACK_A_MOLE_MOLE_BUTTON_H
