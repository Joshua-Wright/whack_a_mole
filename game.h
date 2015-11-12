//
// Created by j0sh on 11/10/15.
//

#ifndef WHACK_A_MOLE_GAME_H
#define WHACK_A_MOLE_GAME_H

#include <iostream>
#include <random>
#include <FL/Fl_Box.H>
#include <FL/Fl_Image.H>
#include "mole_button.h"
#include "square_matrix.h"
#include <FL/Fl_PNG_Image.H>

using std::cout;
using std::endl;

class game {
    int button_size;
    int statusbar_size;
    square_matrix<mole_button *> board;
    mole_button *current_mole;
    Fl_Image *image_1;
    Fl_Image *image_2;

    std::random_device rd;
    std::mt19937_64 gen;
    std::uniform_int_distribution<> dis;

    Fl_Box *statusbar_box;
    char statusbar_buffer[128];
    int hits, misses;

    void initialize_buttons();
    
    friend void button_callback(Fl_Widget *w, void *b);

    void set_random_mole(mole_button *clicked);

    void initialize_statusbar();

    void redraw_statusbar();

    void increment_hits();

    void increment_misses();


public:

    game(unsigned grid_size, unsigned btn_size, unsigned sbar_size,
         Fl_Image *img1, Fl_Image *img2);
};


#endif //WHACK_A_MOLE_GAME_H
