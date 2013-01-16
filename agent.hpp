#ifndef AGENT_HPP
#define AGENT_HPP

class Agent
{
public:
  Agent();
  ~Agent();
  Agent &operator=(const Agent &other);
  double step(const double sample);
  const int minFQ;
  const int maxFQ;
  const double damping;

private:
  double vel;
  double pos;
  double fq;
  double sr;
  double time_step;
};

#endif
