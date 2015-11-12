//
// Created by j0sh on 11/10/15.
//

#ifndef WHACK_A_MOLE_MOLE_BUTTON_H
#define WHACK_A_MOLE_MOLE_BUTTON_H

#include <iostream>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_PNG_Image.H>

using std::cout;
using std::endl;

class mole_button : public Fl_Box {
    bool has_mole;
    Fl_Image *image_1;
    Fl_Image *image_2;

public:
    mole_button(int x, int y, int w, Fl_Image *img1, Fl_Image *img2) : Fl_Box(x, y, w, w), has_mole(false),
                                                                       image_1(img1), image_2(img2) {
    }

    void set_has_mole(bool g);;

    bool get_has_mole() { return has_mole; };


    virtual int handle(int i) override;
};


#endif //WHACK_A_MOLE_MOLE_BUTTON_H
