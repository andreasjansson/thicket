#ifndef OUTPUTAUDIO_HPP
#define OUTPUTAUDIO_HPP

#include <string>
#include <sndfile.h>

class OutputAudio
{
public:
  OutputAudio(const char *filename, const int channels, const int sampleRate);
  ~OutputAudio(void);
  void putSample(const double *sample);

private:
  SNDFILE *outfile;
  SF_INFO info;
};

#endif
















