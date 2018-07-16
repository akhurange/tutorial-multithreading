#ifndef _THREAD_H_
#define _THREAD_H_

typedef void* ThreadArg;
// Thread function has been defined as:
// void (*) (void *)
typedef void (*ThreadFunction) (void *);

class Runner {
public:

    // Force derived class to implement threadRoutine.
    virtual void 
    threadRoutine(
        void *arg
        ) = 0;        

    virtual
    ~Runner() { }
};

struct ThreadData {
    ThreadFunction startRoutine;
    Runner *threadClass;
    void *arg;
};

class Thread : public NotCopyable
{
public:

    // Constructor for stand alone function.
    Thread(
        ThreadFunction startRoutine,
        void *arg
        )
    {
        m_threadData = (ThreadData){startRoutine, NULL, arg};
        m_threadJoined = false;
        startThread();
    }

    // Constructor for class member function.
    Thread(
        Runner *threadClass,
        ThreadArg arg
        )
    {
        m_threadData = (ThreadData){NULL, threadClass, arg};
        m_threadJoined = false;
        startThread();
    }

    ~Thread() 
    {
        if (!m_threadJoined) {
            // If thread was not joined detach it.
            // Allow it to run in background even after the object is destructed.
            detachThread();
        }
    }

    void
    joinThread();

private:

    void
    startThread();

    void
    detachThread();

    ThreadData m_threadData;
    bool m_threadJoined;
    THREAD m_thread;
};

#endif // _THREAD_H_

