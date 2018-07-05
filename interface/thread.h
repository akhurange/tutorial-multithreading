#ifndef _THREAD_H_
#define _THREAD_H_

typedef void* ThreadReturn;
typedef void* ThreadArg;
// Thread function has been defined as:
// void* (*) (void *)
// One can change definition of ThreadReturn or ThreadArg to change ThreadFunction definition.
typedef ThreadReturn (*ThreadFunction) (ThreadArg);

class Runner {
public:

    // Force derived class to implement threadRoutine.
    virtual ThreadReturn
    threadRoutine(
        ThreadArg arg
        ) = 0;        

    virtual
    ~Runner() { }
};

struct ThreadData {
    ThreadFunction startRoutine;
    Runner *threadClass;
    ThreadArg arg;
    ThreadReturn result;
};

class Thread
{
public:

    // Constructor for stand alone function.
    Thread(
        ThreadFunction startRoutine,
        ThreadArg arg
        )
    {
        m_threadData = new ThreadData;
        *m_threadData = (ThreadData){startRoutine, NULL, arg, (ThreadReturn)0};
        m_threadJoined = false;
        startThread();
    }

    // Constructor for class member function.
    Thread(
        Runner *threadClass,
        ThreadArg arg
        )
    {
        m_threadData = new ThreadData;
        *m_threadData = (ThreadData){NULL, threadClass, arg, (ThreadReturn)0};
        m_threadJoined = false;
        startThread();
    }

    ~Thread() 
    {
        if (!m_threadJoined) {
            // Wait till the thread execution completes.
            joinThread();
        }
        delete m_threadData;
    }

    ThreadReturn 
    joinThread();

private:

    void
    startThread();

    ThreadData *m_threadData;
    bool m_threadJoined;
    THREAD m_thread;
};

#endif // _THREAD_H_
