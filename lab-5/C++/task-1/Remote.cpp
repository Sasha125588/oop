#include "Remote.hpp"
#include "TV.hpp"

Remote::Remote(TV* tv): tv(tv) {}

Remote::~Remote() {
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

void Remote::goToChannel(int channel) {
    tv->setChannel(channel);
}