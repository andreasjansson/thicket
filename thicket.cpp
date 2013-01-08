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
  InputAudio in(argv[1]);
  int channels = in.getChannels();
  OutputAudio out(argv[2], channels, in.getSampleRate());
  vector<Agent> agents(NAGENTS * channels);
  double outSample[channels];
  double inSample[channels];
  while(in.getSample(inSample)) {

    for(int i = 0; i < channels; i ++)
      outSample[i] = 0;

    int channel = 0;
    for(vector<Agent>::iterator it = agents.begin(); it != agents.end(); it ++) {
      it->step(inSample[channel]);
      outSample[channel] += it->getPos();
      channel = (channel + 1) % channels;      
    }
    out.putSample(outSample);
  }

  return 0;
}
