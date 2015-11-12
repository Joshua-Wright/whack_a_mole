#include <iostream>
#include <random>
#include <ctime>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include "game.h"


using namespace std;

int main(int argc, char **argv) {
//    cout << "Hello, World!" << endl;
    unsigned grid_size = 10;
    unsigned button_size = 30;

    std::srand((unsigned int) std::time(nullptr));
    Fl_Window window(grid_size*button_size, grid_size*button_size+5, "Whack a mole!");
    game g(grid_size, button_size, 5);

    window.end();
    window.show(argc, argv);
    return Fl::run();
}