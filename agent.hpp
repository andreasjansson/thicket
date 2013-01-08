#ifndef AGENT_HPP
#define AGENT_HPP

class Agent
{
public:
  Agent();
  ~Agent();
  void step(const double sample);
  double getPos(void) const;

private:
  double vel;
  double pos;
};

#endif
