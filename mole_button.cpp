//
// Created by j0sh on 11/10/15.
//

#include <FL/Fl.H>
#include "mole_button.h"

void mole_button::set_has_mole(bool g) {
    has_mole = g;
    if (g) {
        image(image_1);
    } else {
        image(image_2);
    }
}

int mole_button::handle(int i) {
    if (i == FL_RELEASE) {
        do_callback();
    }
    return Fl_Box::handle(i);
}
