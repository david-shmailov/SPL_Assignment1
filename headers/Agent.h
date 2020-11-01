//
// Created by David on 31/10/2020.
//

#ifndef AGENT_H_
#define AGENT_H_

#include <vector>

class Agent{
public:
    Agent(Session& session);

    virtual void act();
private:
    Session& session;
};

class ContactTracer: public Agent{
public:
    ContactTracer(Session& session);

    virtual void act();
};


class Virus: public Agent{
public:
    Virus(int nodeInd, Session& session);

    virtual void act();
private:
    const int nodeInd;
};

#endif
