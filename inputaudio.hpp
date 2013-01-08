#ifndef INPUTAUDIO_HPP
#define INPUTAUDIO_HPP

#include <sndfile.h>

class InputAudio
{
public:
  InputAudio(char *filename);
  ~InputAudio();
  bool getSample(double *sample);
  const int getChannels(void);
  const int getSampleRate(void);

private:
  SNDFILE *infile;
  SF_INFO info;
};

#endif










