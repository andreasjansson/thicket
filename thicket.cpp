#include <string>
#include <vector>
#include "agent.hpp"
#include "inputaudio.hpp"
#include "outputaudio.hpp"

using std::vector;
using std::string;

int main(int argc, char *argv[])
{
  const int NAGENTS = 2;
  const int BUFFER_SIZE = 4096;

  InputAudio in(argv[1], BUFFER_SIZE);
  int channels = in.getChannels();
  OutputAudio out(argv[2], channels, in.getSampleRate(), BUFFER_SIZE);
  vector<Agent> agents(NAGENTS * channels);

  double outSamples[channels * BUFFER_SIZE];
  double inSamples[channels * BUFFER_SIZE];

  while(in.getSamples(inSamples)) {

    for(int i = 0; i < BUFFER_SIZE; i ++) {

      for(int c = 0; c < channels; c ++)
        outSamples[c + channels * i] = 0;

      int channel = 0;
      for(vector<Agent>::iterator it = agents.begin(); it != agents.end(); it ++) {
        outSamples[channel + channels * i] += it->step(inSamples[channel + channel * i]);
        channel = (channel + 1) % channels;      
      }
    }

    out.putSamples(outSamples);
  }

  return 0;
}










