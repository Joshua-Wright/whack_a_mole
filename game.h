//
// Created by j0sh on 11/10/15.
//

#ifndef WHACK_A_MOLE_GAME_H
#define WHACK_A_MOLE_GAME_H

#include <iostream>
#include <random>
#include "mole_button.h"
#include "square_matrix.h"

using std::cout;
using std::endl;

class game {
    int button_size;
    int statusbar_size;
    square_matrix<mole_button *> board;
    mole_button *current_mole;

    std::random_device rd;
    std::mt19937_64 gen;
    std::uniform_int_distribution<> dis;

    void initialize_buttons();

    void reset_timer();

    friend void button_callback(Fl_Widget *w, void *b);

    void set_random_mole();

public:

    game(unsigned grid_size, unsigned btn_size, unsigned sbar_size) : board(grid_size), button_size(btn_size),
                                                                      current_mole(nullptr),
                                                                      statusbar_size(sbar_size), gen(rd()),
                                                                      dis(0, board.n_elements()-1) {
        initialize_buttons();
//        cout << "test 1234 " << board.n_elements() << endl;
//        cout << board(1,1)->get_has_mole() << " ";
//        board(1,1)->set_has_mole(true);
//        cout << board(1,1)->get_has_mole() << endl;

    }
};


#endif //WHACK_A_MOLE_GAME_H
