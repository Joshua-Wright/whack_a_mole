#include <iostream>
#include <random>
#include <ctime>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_PNG_Image.H>
#include "game.h"


using namespace std;

int main(int argc, char **argv) {
//    cout << "Hello, World!" << endl;
    unsigned grid_size = 10;
    unsigned button_size = 32;
    unsigned statusbar_size = 30;

    Fl_PNG_Image *img_normal = new Fl_PNG_Image("bg.png");
    Fl_PNG_Image *img_mole = new Fl_PNG_Image("mole.png");

    std::srand((unsigned int) std::time(nullptr));
    Fl_Window window(grid_size * button_size, grid_size * button_size + statusbar_size, "Whack a mole!");
    game g(grid_size, button_size, statusbar_size, img_mole, img_normal);

    window.end();
    window.show(argc, argv);
    return Fl::run();
}