#include "inputaudio.hpp"

InputAudio::InputAudio(char *filename, const int bufferSize)
  : bufferSize(bufferSize)
{
  infile = sf_open(filename, SFM_READ, &info);
}

bool InputAudio::getSamples(double *sample)
{
  int nread = sf_read_double(infile, sample, info.channels * bufferSize);
  return nread == info.channels * bufferSize;
}

const int InputAudio::getChannels(void)
{
  return info.channels;
}

const int InputAudio::getSampleRate(void)
{
  return info.samplerate;
}

InputAudio::~InputAudio(void)
{
  sf_close(infile);
}
