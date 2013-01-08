#include "inputaudio.hpp"

InputAudio::InputAudio(char *filename)
{
  infile = sf_open(filename, SFM_READ, &info);
}

bool InputAudio::getSample(double *sample)
{
  int nread = sf_read_double(infile, sample, info.channels);
  return nread == info.channels;
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
