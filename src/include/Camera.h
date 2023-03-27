/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "Common.h"

/*
 	Camera class  
*/
class Camera final {
public:
	int x, y, w, h;

	Camera() {
		x = 0;
		y = 0;
		w = 0;
		h = 0;
	}

	Camera(int x, int y, int w, int h) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}

	~Camera() = default;
};
