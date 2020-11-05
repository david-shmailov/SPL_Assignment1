//
#include "Session.h"
class Session;
class Agent{
public:
    Agent(Session& session);// constructor
    Agent(const Agent & copy);// copy constructor
    virtual ~Agent()=default; // destructor
    Agent(Agent&& other); // move constructor
    const Agent& operator =(const Agent& other)=delete;// assignment operator
    const Agent& operator=(Agent&& other)=delete;// move assignment operator
    void  setSession(const Agent& other);
    const Session& getSession();

    virtual void act();
private:
    Session& session;
};

class ContactTracer: public Agent{
public:
    ContactTracer(Session& session);// constructor
    ContactTracer(const ContactTracer & copy);// copy constructor
    virtual ~ContactTracer()=default; // destructor
    ContactTracer(ContactTracer&& other); // move constructor
    const ContactTracer& operator =(const ContactTracer& other)=delete;// assignment operator
    const ContactTracer& operator=(ContactTracer&& other)=delete;// move assignment operator


    virtual void act();
};


class Virus: public Agent{
public:
    Virus(int nodeInd, Session& session);//constructorVVV
    Virus(const Virus & copy);// copy constructor
    virtual ~Virus()=default; // destructor
    Virus(Virus&& other); // move constructor
    const Virus& operator =(const Virus& other);// assignment operator
    const Virus& operator=(Virus&& other);// move assignment operator
    virtual void act();
private:
    const int nodeInd;
};

#endif
