/*
	SchumakerTeam
	Hudson Schumaker
*/

#pragma once
#include "../include/Common.h"

class CallbackFunction final {
public:
    Scene* owner;
    CallbackFunction();
    

    template<typename O>
    void addOnclickCallback(O* o, void(O::*f)()) {
        owner = o;
        onClick = f;
    }

    void onClickEvevnt() {
        if(onClick) {
            owner->onClick();
        }
    }
};
