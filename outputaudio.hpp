#ifndef OUTPUTAUDIO_HPP
#define OUTPUTAUDIO_HPP

#include <string>
#include <sndfile.h>

class OutputAudio
{
public:
  OutputAudio(const char *filename, const int channels,
              const int sampleRate, const int bufferSize);
  ~OutputAudio(void);
  void putSamples(const double *samples);

private:
  SNDFILE *outfile;
  SF_INFO info;
  const int bufferSize;
};

#endif
















