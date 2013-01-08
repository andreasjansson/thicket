#ifndef AGENT_HPP
#define AGENT_HPP

class Agent
{
public:
  Agent();
  ~Agent();
  double step(const double sample);

private:
  double vel;
  double pos;
};

#endif
