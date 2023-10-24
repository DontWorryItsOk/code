

void (*malloc(size_t size))
char *p;
int b;
int *pb;
// p = malloc(1000);
p = (char*)malloc(1000);
pb = (int *)malloc(50*sizeof(int));
