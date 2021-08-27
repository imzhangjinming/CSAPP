#include<stdio.h>
#include<string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start,size_t len){
	int i;
	for(i=0;i<len;i++){
		printf("%.2x",start[i]);
	}
	printf("\n");
}

void show_int(int x){
	show_bytes((byte_pointer)&x,sizeof(x));
}

void show_float(float x){
	show_bytes((byte_pointer)&x,sizeof(x));
}

void show_pointer(void *x){
	show_bytes((byte_pointer)&x,sizeof(x));
}

int main(void){
	int x=5;
	float y=5.5;
	int *ip=&x;

	show_int(x);
	show_float(y);
	show_pointer((void*)ip);

	int a = 0x12345678;
	byte_pointer ap=(byte_pointer)&a;
	show_bytes(ap,1);
	show_bytes(ap,2);
	show_bytes(ap,3);

	const char *m="mnopqr";
	show_bytes((byte_pointer)m,strlen(m));

	return 0;
}
