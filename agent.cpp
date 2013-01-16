#include <cstdlib>
#include <cmath>
#include "agent.hpp"

Agent::Agent() : vel(0), pos(0), minFQ(20), maxFQ(20000), damping(0.001), sr(44100)
{
  fq = minFQ + rand() % (maxFQ - minFQ);
  time_step = 1 / sr;
}

Agent::~Agent()
{

}

double Agent::step(const double sample)
{
  double norm = pow(fq, 3);
  double prev_pos = pos;
  double prev_vel = vel;

  pos = prev_pos + time_step * prev_vel;
  double normpos = pos * norm;
  vel = sample + prev_vel - pow(fq, 2) / (double)sr *
    (pow(2.0 * M_PI, 2.0) * prev_pos + damping * prev_vel);
  
  return normpos;
}
