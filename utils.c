#include <stdio.h>
#include <stdlib.h>

#include <net/if.h>
#include <time.h>
#include <asm/types.h>
#include <limits.h>
//打印数组
void printArray(int *a,int len){
	if(a== NULL || len<=0)
		return;
	int i=0;
	while(i<len){
		printf("%d ",a[i++]);
	}
	puts("");
}
//逆序对
int guibing(int *a,int start,int end){
	if(start==end)
		return 0;
	int cy[end-start+1];
	int count=0;
	int mid=(start+end)/2;
	int p1=mid;
	int p2=end;
	int p3=end-start;
	count += guibing(a,start,mid);
	count += guibing(a,mid+1,end);
	while(p1>=start && p2 >=mid){
		if(a[p2]<a[p1]){
			count += p2-mid;
			cy[p3]=a[p1];
			p3--;
			p1--;
		}else{
			cy[p3]=a[p2];
			p3--;
			p2--;
		}
	}
	while(p1>=start)
		cy[p3--]=a[p1--];
	while(p2>=mid)
		cy[p3--]=a[p2--];
	for(p3=0;p3<=end-start;p3++){
		a[p3+start]=cy[p3];
	}
	printf("%d %d\n",start,count);
	return count;
}

int inversPairs(int *a,int len){
	if(a==NULL || len <=1)
		return 0;
	int count = guibing(a,0,len-1);
	printf("inverPairs = %d\n",count);
	return count;
}



//LIS 最长递增子序列
//1，-1,2，-3,4，-5,6，-7 最长递增子序列长度为4 1,2,4,6
int lis(int a[],int n){
	if(a==NULL || n<=0)
		return 0;
	int lis[n];
	int maxv[n+1];
	maxv[1]=a[0];
	maxv[0]=1<<31;
	int i=0;
	int j=0;
	int maxlen=1;
	for(;i<n;i++){
		lis[i]=1;
	}
	for(i=1;i<n;i++){
		j=maxlen;
		for(;j>0;j--){
			if(a[i]>maxv[j]){
				//lis[i]=j+1;
				break;
			}
		}
		if(j+1>maxlen){
			maxlen=j+1;
			maxv[j+1]=a[i];
		}else if(a[i]>maxv[j] && a[i]<maxv[j+1]){
			maxv[j+1]=a[i];
		}

	}
	printf("%d\n",maxlen);
	return maxlen;
}
//连续子数组和的最大值
int Maxsum(int a[],int n){
	if(a==NULL || n <=0)
		return 0;
	int maxall=a[0];
	int maxtemp=a[0];
	int i=0;
	for(i=1;i<n;i++){
		if(maxtemp + a[i]>a[i]){
			maxtemp=maxtemp+a[i];
		}else{
			maxtemp=a[i];
		}
		if(maxtemp>maxall){
			maxall=maxtemp;
		}
	}
	printf("%d\n",maxall);
	return maxall;
}
//fibonacci
int fibonacci(int a){
	if(a==0)
		return 0;
	if(a==1)
		return 1;
	int l1=0;
	int l2=1;
	int temp;
	while(a>1){
		l1=l1 + l2;
		temp=l1;
		l1=l2;
		l2=temp;
		a--;
	}
	printf("%d fibonacci is %d\n",a, l2);
	return l2;
}
//GCD Greatest Common Divisor 最大公约数
//1.如果x y都是偶数则f(x,y)=2*f(x/2,y/2)
//2.如果x y只有一个是偶数则 f(x,y)=f(x/2,y) 或 f（x,y/2)
//3.如果x y都不是偶数 则f（x,y)=f(y,x-y) x>y
int gcd(int x, int y){
	if(x < y)
		return gcd(y,x);
	if(y==0)
		return x;
	if( (x&1) == 0 && (y&1) == 0){
		return gcd(x>>1,y>>1)<<1;
	}
	if((x&1) == 0 && (y&1) !=0 ){
		return gcd(x>>1,y);
	}
	if((x&1) != 0 && (y&1) == 0){
		return gcd(x, y>>1);
	}
	else{
		return gcd(y, x-y);
	}
}

//求N！二进制中最低位1的位置，例如3！=6 1010 最低位1在第二位
int lowestOne(int N)
{
	int ret=0;
	while(N){
		N>>=1;
		ret += N;
	}
	printf("%d\n",ret);
	return ret;
}
//求一个二进制数中1的个数
//将a与a-1相与 循环去掉一个1
int getNumOfOne(int a){
	int count=0;
	int b=a;
	while(b){
		count++;
		b= b&b-1;
	}
	printf("0x%x has %d 个1\n",a,count);
}

void lpz(char *buff){
	memcpy( buff, "123", 3 );
}
int lplus(int a , int b ,int *c , int *d){
	*c = a+b;
	*d = a-b;
	return 1;
}
int fb(int *b){
	*b = 12;
	return 1;
}
int fa(int *a){
	fb(a);
	return 1;
}

int fastsort(int start, int end, int *a){
	if(end - start < 1) {
		return 0;
	}
	int key = a[start];

	int i = start;
	int j = end;
//	int flag = 0;
//	while (start < end) {
//		if (flag == 0) {
//			if (a[end] < key) {
//				a[start] = a[end];
//				start++;
//				flag = 1;
//			} else {
//				end--;
//			}
//		} else {
//			if (a[start] > key) {
//				a[end] = a[start];
//				end--;
//				flag = 0;
//			} else {
//				start++;
//			}
//		}
//	}
	while(i < j){
		while( i<j && a[j] >= key)
			j--;
		a[i]=a[j];
		while( i<j && a[i] <= key)
			i++;
		a[j]=a[i];
	}
	a[j]=key;
	fastsort(start,j-1,a);
	fastsort(j+1,end,a);
	return 0;
}

int guibingsort(int *a, int s, int m, int e){
	int all = e-s+1;
//	if(all =)
}
int get_unsigned(unsigned *val, const char *arg, int base)
{
	unsigned long res;
	char *ptr;

	if (!arg || !*arg)
		return -1;
	res = strtoul(arg, &ptr, base);
	if (!ptr || ptr == arg || *ptr || res > UINT_MAX)
		return -1;
	*val = res;
	return 0;
}
