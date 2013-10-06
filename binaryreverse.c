#include <stdio.h>
typedef unsigned int __u32;
__u32 binaryreverse(__u32 num){
	__u32 ret=0;
	int i = 0;
	for(;i<32;i++){

		ret <<= 1;
		ret |= num&1;
		num >>= 1;

	}
	return ret;
}
