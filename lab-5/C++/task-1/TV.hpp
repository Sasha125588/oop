#pragma once

enum TVStatus {
    ON,
    OFF
};

class TV {
    private:
    TVStatus status;
    short channel;
    short channelsCount;
    short volume;
    short maxVolume;

    public:
    TV();
    TV(TVStatus status, short channel, short channelsCount, short volume, short maxVolume);

    TVStatus getStatus() const;
    void setStatus(TVStatus status);
    
    short getChannel() const;
    void setChannel(short channel);
    
    short getVolume() const;
    void setVolume(short volume);

    short getChannelsCount() const;
        void setChannelsCount(short channelsCount);

    short getMaxVolume() const;
    void setMaxVolume(short maxVolume);

    void power();
    void nextChannel();
    void prevChannel();
    void incVolume();
    void decVolume();
    void show();

    friend class Remote;
};