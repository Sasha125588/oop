#pragma once

#include "TV.hpp"

class Remote {
    private:
    TV* tv;

    public:
    Remote(TV* tv);

    ~Remote();

    void power();
    void nextChannel();
    void prevChannel();
    void incVolume();
    void decVolume();
    void goToChannel(short channel);

    
};