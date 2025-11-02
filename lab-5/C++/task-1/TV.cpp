#include "TV.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

TV::TV() {
    status = false;
    maxVolume = 50;
    channelsCount = 100;
    channel = 1;
    volume = 10;
}

TV::TV(bool status, short channel, short channelsCount, 
    short volume, short maxVolume)
        : status(status)
        , maxVolume(maxVolume)
        , channelsCount(channelsCount)
        , channel(channel)
        , volume(volume) {}
        
bool TV::getStatus() const {
    return status;
}

void TV::toogleStatus(bool status) {
    this->status = status;
}

short TV::getChannel() const {
    return channel;
}

void TV::setChannel(short channel) {
    this->channel = max((short)0, min(channel, channelsCount));
}

short TV::getVolume() const {
    return volume;
}

void TV::setVolume(short volume) {
    this->volume = volume;
}

short TV::getChannelsCount() const {
    return channelsCount;
}

void TV::setChannelsCount(short channelsCount) {
    this->channelsCount = channelsCount;
}

short TV::getMaxVolume() const {
    return maxVolume;
}

void TV::power() {
    status = status ? false : true;
}

void TV::nextChannel() {
    channel = (channel + 1) % (channelsCount + 1);
}

void TV::prevChannel() {
    channel = (channel - 1 + (channelsCount + 1)) % (channelsCount + 1);
}

void TV::incVolume() {
    volume = min((short)(volume + 1), maxVolume);
}

void TV::decVolume() {
    volume = max(volume - 1, 0);
}

void TV::show() {
    cout << "┌─────────────────────────────────┐" << endl;
    cout << "│              TV INFO            │" << endl;
    cout << "├─────────────────────────────────┤" << endl;
    
    if (status == true) {
        cout << "│ Status:     ON                 │" << endl;
        cout << "│ Channel:    " << setw(3) << channel << "               │" << endl;
        cout << "│ Volume:     " << setw(3) << volume << "/" << setw(3) << maxVolume << "            │" << endl;
    } else {
        cout << "│ Status:     OFF                │" << endl;
        cout << "│ Channels:   " << setw(3) << channelsCount << "               │" << endl;
        cout << "│ Max Volume: " << setw(3) << maxVolume << "               │" << endl;
    }
    
    cout << "└─────────────────────────────────┘" << endl;
}