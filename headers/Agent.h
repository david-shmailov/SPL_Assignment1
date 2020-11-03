//
// Created by David on 31/10/2020.
//

#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include "Session.h"
class Session;
class Agent{
public:
    Agent(Session& session);
    Agent(const Agent & a);

    virtual void act();
private:
    Session& session;
};

class ContactTracer: public Agent{
public:
    ContactTracer(Session& session);
    ContactTracer(const ContactTracer &a);

    virtual void act();
};


class Virus: public Agent{
public:
    Virus(int nodeInd, Session& session);
    Virus(const Virus &v);
    virtual void act();
private:
    const int nodeInd;
};

#endif
