//
#ifndef AGENT_H_
#define AGENT_H_
#include "Session.h"
#include "Tree.h"

class Agent{
public:
    ///rule of 5
    Agent();// constructor
    Agent(const Agent & copy);// copy constructor
    virtual ~Agent()=default; // destructor
    Agent(Agent&& other); // move constructor
    const Agent& operator =(const Agent& other);// assignment operator
    const Agent& operator=(Agent&& other);// move assignment operator

    ///virtual functions:
    virtual void act(Session& session)=0;
    virtual Agent* clone() const =0;

};

class ContactTracer: public Agent{
public:
    ContactTracer();// constructor
    ContactTracer(const ContactTracer & copy);// copy constructor
    virtual ~ContactTracer()=default; // destructor
    ContactTracer(ContactTracer&& other); // move constructor
    const ContactTracer& operator =(const ContactTracer& other)=delete;// assignment operator
    const ContactTracer& operator=(ContactTracer&& other)=delete;// move assignment operator


    virtual void act(Session& session);
    virtual Agent* clone() const;
};


class Virus: public Agent{
public:
    Virus(int nodeInd);//constructorVVV
    Virus(const Virus & copy);// copy constructor
    virtual ~Virus()=default; // destructor
    Virus(Virus&& other); // move constructor
    const Virus& operator =(const Virus& other)=delete;// assignment operator
    const Virus& operator=(Virus&& other)=delete;// move assignment operator


    virtual void act(Session& session);
    virtual Agent* clone() const;
private:
    const int nodeInd;
};

#endif