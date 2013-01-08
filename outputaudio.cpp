#include "outputaudio.hpp"
#include <cstdio>
#include <cstdlib>

using std::exception;

OutputAudio::OutputAudio(const char *filename, const int channels, const int sampleRate)
{
  info.channels = channels;
  info.samplerate = sampleRate;
  info.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
  outfile = sf_open(filename, SFM_WRITE, &info);
  if(!outfile) {
    fprintf(stderr, sf_strerror(outfile));
    exit(1);
  }
}

void OutputAudio::putSample(const double *sample)
{
  sf_write_double(outfile, sample, info.channels);
}

OutputAudio::~OutputAudio(void)
{
  sf_close(outfile);
}









