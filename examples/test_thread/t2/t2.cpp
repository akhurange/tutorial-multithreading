#include "base.h"
#include "interface.h"

class MyClass : public Runner
{
    void 
    threadRoutine (
        void *arg
        )
    {
        printf("Hello world!\n");
    }
};

int
main(
	int argc,
	char **argv
	)
{
    MyClass obj = MyClass();
    Thread *t1 = new Thread(&obj, NULL);
    t1->joinThread();
    delete t1;

    return 0;
}
