#include "Remote.hpp"
#include "TV.hpp"

Remote::Remote(TV* tv): tv(tv) {}

Remote::~Remote() {
    if(tv != nullptr)
        delete tv;
}

void Remote::power() {
    tv->power();
}

void Remote::nextChannel() {
    tv->nextChannel();
}

void Remote::prevChannel() {
    tv->prevChannel();
}

void Remote::incVolume() {
    tv->incVolume();
}

void Remote::decVolume() {
    tv->decVolume();
}

void Remote::goToChannel(short channel) {
    tv->setChannel(channel); // TODO: private method, friend
}