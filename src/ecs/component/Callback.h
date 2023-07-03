/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "Component.h"

class Callback : public Component {

public:
    typedef std::function<void(unsigned long, unsigned long)> CallbackFunction;
    Callback() {
        callback_ = nullptr;
    }

    Callback(const CallbackFunction& callback) {
        callback_ = callback;
    }

    void call(unsigned long id, unsigned long otherId) {
       if (callback_) {
           callback_(id, otherId);
       }
    }

private:
    CallbackFunction callback_;
};
