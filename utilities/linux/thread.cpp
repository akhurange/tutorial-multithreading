#include "base.h"
#include "interface.h"

static void *
PvtRun(
    void *
    );

void
Thread::startThread()
{
    // Create thread and execute jumper function PvtRun.
    int ret = pthread_create(&m_thread, NULL, PvtRun, (void*)(&m_threadData));
    if (ret != 0) {
        throw BaseException(errno, "Error in thread creation.");
    }
}

void
Thread::joinThread()
{
    m_threadJoined = true;
    // Block till the thread exit.
    int stat = pthread_join(m_thread, NULL);
    if (stat != 0) {
        throw BaseException(errno, "Error joining thread.");
    }
}

void
Thread::detachThread()
{
    int stat = pthread_detach(m_thread);
    if (stat != 0) {
        throw BaseException(errno, "Error detaching thread.");
    }
}

void *
PvtRun(
    void *arg
    )
{
    // Get the input thread data.
    ThreadData *th = (ThreadData*)arg;

    if (th->startRoutine != NULL) {
        // Run the stand alone function.
        th->startRoutine(th->arg);
    } else if (th->threadClass != NULL) {
        // Run the class member function.
        th->threadClass->threadRoutine(th->arg);
    }

    return NULL;
}

