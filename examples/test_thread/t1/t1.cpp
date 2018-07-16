#include "base.h"
#include "interface.h"

void 
table(
    void *arg
    )
{
    int i = *((int *)arg);
    for (int j=1; j<=10; j++) {
        printf("%d ", i*j);
    }
    printf("\n");
}

int
main(
	int argc,
	char **argv
	)
{
    int i=2;

    Thread t1(table, &i);
    t1.joinThread();
    return 0;
}
