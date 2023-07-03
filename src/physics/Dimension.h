/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "../include/Common.h"

struct Dimension {
    short w = 0;
    short h = 0;

    Dimension() {}
    Dimension(short w, short h) {
        this->w = w;
        this->h = h;
    }
    ~Dimension() = default;
};
