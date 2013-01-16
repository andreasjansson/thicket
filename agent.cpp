#include <cstdlib>
#include <cmath>
#include "agent.hpp"
#include <cstdio>

Agent::Agent() : vel(0), pos(0), minFQ(20), maxFQ(100), damping(0.00095), sr(44100)
{
  fq = minFQ + rand() % (maxFQ - minFQ);
  printf("%f\n", fq);
  time_step = 1.0 / sr;
}

Agent::~Agent()
{

}

Agent &Agent::operator=(const Agent &other)
{
  if(this != &other) {
    fq = other.fq;
    vel = other.vel;
    pos = other.pos;
  }
  return *this;
}

double Agent::step(const double sample)
{
  double rnd = ((rand() % 100) / 99.0 - .5) * 3;
  fq += rnd;

  double norm = pow(fq, 3);
  double prev_pos = pos;
  double prev_vel = vel;

  pos = prev_pos + time_step * prev_vel;
  double normpos = pos * norm;
  vel = sample + prev_vel - pow(fq, 2) / (double)sr *
    (pow(2.0 * M_PI, 2.0) * prev_pos + damping * prev_vel);

  return normpos / 1000000000;
}
