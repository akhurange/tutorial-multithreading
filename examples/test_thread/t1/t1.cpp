#include "base.h"
#include "interface.h"

void *
table(
    void *arg
    )
{
    int i = *((int *)arg);
    for (int j=1; j<=10; j++) {
        printf("%d ", i*j);
    }
    printf("\n");
    int *k = new int;
    *k = i*i;
    return k;
}

int
main(
	int argc,
	char **argv
	)
{
    int i=2;
    void *k;

    Thread t1 = Thread(table, &i);
    k = t1.joinThread();
    printf("%d\n", *((int *)k));
    delete ((int *)k);
    return 0;
}
