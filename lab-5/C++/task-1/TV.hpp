#pragma once

// enum class TVStatus {
//     ON,
//     OFF
// };

class TV {
private:
  bool status;
  short channel;
  short channelsCount;
  short volume;
  short maxVolume;

  void setChannel(short channel);

public:
  TV();
  TV(bool status, short channel, short channelsCount
    , short volume
    , short maxVolume);

  bool getStatus() const;
  void toogleStatus(bool status);

  short getChannel() const;

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