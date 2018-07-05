#include "base.h"
#include "interface.h"

class MyClass : public Runner
{
    void *
    threadRoutine (
        void *arg
        )
    {
        printf("Hello world!\n");
        return NULL;
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
    delete t1;

    return 0;
}
