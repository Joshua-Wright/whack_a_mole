//
// Created by j0sh on 11/10/15.
//

#include "game.h"
#include <iostream>
#include <FL/Fl.H>

using std::cout;
using std::endl;

void button_callback(Fl_Widget *w, void *b) {
    mole_button *button = static_cast<mole_button *>(w);
    game *g = static_cast<game *>(b);
    g->set_random_mole(button);
    Fl::redraw();
}

void game::initialize_buttons() {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            board(i, j) = new mole_button(i * button_size, j * button_size + statusbar_size, button_size, image_1,
                                          image_2);
            board(i, j)->callback(button_callback, this);
            board(i, j)->set_has_mole(false);
        }
    }
    current_mole = nullptr;
    set_random_mole(nullptr);

}

void game::set_random_mole(mole_button *clicked) {
    if (current_mole != nullptr) {
        if (clicked == current_mole) {
            increment_hits();
        } else {
            increment_misses();
        }
        current_mole->set_has_mole(false);
    }
    unsigned idx = (unsigned int) dis(gen);
    current_mole = board(idx);
    current_mole->set_has_mole(true);
}

void game::initialize_statusbar() {
    *statusbar_buffer = 0; // null character = empty string
    statusbar_box = new Fl_Box(0, 0, board.size() * button_size, statusbar_size, statusbar_buffer);
    redraw_statusbar();
}

void game::redraw_statusbar() {
    sprintf(statusbar_buffer, "Hits: %i, Misses: %i", hits, misses);
    statusbar_box->label(statusbar_buffer);
    Fl::redraw();
}

void game::increment_hits() {
    hits++;
    redraw_statusbar();
}

void game::increment_misses() {
    misses++;
    redraw_statusbar();
}


game::game(unsigned grid_size, unsigned btn_size, unsigned sbar_size,
           Fl_Image *img1, Fl_Image *img2) : board(grid_size), button_size(btn_size),
                                             current_mole(nullptr),
                                             statusbar_size(sbar_size),
                                             image_1(img1), image_2(img2),
                                             hits(0), misses(0),
                                             gen(rd()), dis(0, board.n_elements() - 1) {
    initialize_buttons();
    initialize_statusbar();
}