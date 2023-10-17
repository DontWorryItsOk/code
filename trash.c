void(*malloc(site_t size))
char *p;
// p=malloc(1000); в современных компиляторах так нельзя
p= (char*)malloc(1000);