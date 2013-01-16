#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "agent.hpp"
#include "inputaudio.hpp"
#include "outputaudio.hpp"

using std::vector;
using std::string;

int main(int argc, char *argv[])
{
  const int NAGENTS = 5;
  const int BUFFER_SIZE = 4096;

  if(argc < 2) {
    fprintf(stderr, "2 arguments required\n");
    return 1;
  }

  srand(time(NULL));

  InputAudio in(argv[1], BUFFER_SIZE);
  int channels = in.getChannels();
  OutputAudio out(argv[2], channels, in.getSampleRate(), BUFFER_SIZE);
  vector<Agent> agents;
  agents.reserve(NAGENTS * channels);
  for(int i = 0; i < agents.capacity(); i ++) {
    agents.push_back(Agent());
  }

  double outSamples[channels * BUFFER_SIZE];
  double inSamples[channels * BUFFER_SIZE];

  while(in.getSamples(inSamples)) {

    for(int i = 0; i < BUFFER_SIZE; i ++) {

      int channel;
      for(channel = 0; channel < channels; channel ++)
        outSamples[channel + channels * i] = 0;

      channel = 0;
      for(vector<Agent>::iterator it = agents.begin(); it != agents.end(); it ++) {
        outSamples[channel + channels * i] += it->step(inSamples[channel + channels * i]);
        channel = (channel + 1) % channels;      
      }
    }

    out.putSamples(outSamples);
  }

  return 0;
}
