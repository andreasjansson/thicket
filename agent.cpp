#include <cstdlib>
#include "agent.hpp"

Agent::Agent() : vel(0), pos(0), minFQ(20), maxFQ(20000), damping(0.001)
{
  fq = minFQ + rand() % (maxFQ - minFQ);
}

Agent::~Agent()
{

}

double Agent::step(const double sample)
{
  pos = sample;
  return pos;
}
