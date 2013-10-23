/*
 ============================================================================
 Name        : helloworld.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <net/if.h>
#include <time.h>
#include <asm/types.h>
#include <limits.h>
//void lpz(char **buff);

int main(void) {
//	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
//	char *buff = (char *)malloc(sizeof(char)*10);
//	lpz(buff);
//	printf("%d %s\n",sizeof(buff),buff);
//
//	int ret = 1;
//	ret = system("ls | grep 123 -q");
//	printf("%d\n", ret);
//
//	int idx = if_nametoindex("eth1");
//	printf("idx = %d\n", idx);
//
//	char ifname[IF_NAMESIZE];
//	if_indextoname(1,ifname);
//
//	puts(ifname);
//	struct timeval first,second;
//	long difftime = 0;
//	gettimeofday(&first, NULL);
//	int n = 10000;
//	while(n--){
//		printf("%d\n",n);
//	}
//	gettimeofday(&second, NULL);
//
//
//	printf("time = %ld\n", second.tv_sec*1000+second.tv_usec/1000 -first.tv_sec*1000-first.tv_usec/1000);
	int a = 10 ;
	__u32 key = 0x10;
	int b[10] = {3,5,4,2,2,3,6,7,1,2};
	fastsort(0,9,b);
	for(a = 0 ; a<10 ; a++){
		printf("%d ", b[a]);
	}
	struct timeval first, second, t3, t4, t5;
	gettimeofday(&first, NULL);
	printf("sec= %d , usec= %d", first.tv_sec,first.tv_usec);
	__u32 k;
	char *skey = "100";
	get_unsigned(&k,skey,0);
	printf("key = %d\n",k);
	__u32 num = 45;
	__u32 ret = binaryreverse(num);
	printf("%u\n", ret);
	a = 10;
	getNumOfOne(a);
	lowestOne(5);
	printf("%d\n",gcd(28,14));
	fibonacci(5);
	int c[6]={1,-2,3,5,-3,2};
	Maxsum(c,6);
	int d[8]={1,-1,2,-3,4,-5,6,-7};
	lis(d,8);
	printArray(d,8);
	inversPairs(d,8);
	printArray(d,8);
	int e[9]={1,2,5,6,9,7,8,4,3};
	nextState(e,9);
	printf("max int %d\n", INT_MAX);
	printf("max long %ld\n", LONG_MAX);
	int f[2][3]={1,2,3,4,5,6};
	int *g = f[0];
	int (*h)[3]=f;
	printf("%d\n",*(g+3));
	printf("%d\n",*(*(h+1)+1));
}
