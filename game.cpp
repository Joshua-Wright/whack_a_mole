//
// Created by j0sh on 11/10/15.
//

#include "game.h"
#include <iostream>
#include <FL/Fl.H>

using std::cout;
using std::endl;

void button_callback(Fl_Widget *w, void *b) {
    mole_button *button = reinterpret_cast<mole_button *>(w);
//    game *g = reinterpret_cast<game *>(b);
    game *g = static_cast<game *>(b);
    g->set_random_mole();
    Fl::redraw();
}

void game::initialize_buttons() {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            board(i, j) = new mole_button(i * button_size, j * button_size, button_size);
            board(i, j)->callback(button_callback, this);
        }
    }
}

void game::set_random_mole() {
    unsigned idx = (unsigned int) dis(gen);
    current_mole = board(idx);
    current_mole->set_has_mole(true);
}
