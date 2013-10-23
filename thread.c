#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define ADDER 2
int adder=0;
int a = 0;
pthread_mutex_t mt;
pthread_cond_t condadder;
pthread_cond_t conddeler;
void *func(){
	printf("adder:%d is running\n",pthread_self());
	int n=100;
	while(1){
		n=100;
		while(n--){
			pthread_mutex_lock(&mt);
			a++;
			pthread_mutex_unlock(&mt);
		}
		pthread_mutex_lock(&mt);
		printf("adder:%d is waiting. a=%d\n",pthread_self(),a);
		adder++;
		if(adder == 2)
			pthread_cond_signal(&conddeler);
		pthread_cond_wait(&condadder,&mt);
		pthread_mutex_unlock(&mt);
	}
}
void *del(){

	while(1){
		printf("deler:%d is waiting. a=%d\n",pthread_self(),a);
		pthread_mutex_lock(&mt);
		if(adder <2){
			pthread_cond_wait(&conddeler,&mt);
			pthread_mutex_unlock(&mt);
		}else{
			adder = 0;
			pthread_mutex_unlock(&mt);
		}
		printf("deler:%d is deling. a=%d\n",pthread_self(),a);
		pthread_mutex_lock(&mt);
		while(a){
			a--;
		}
		pthread_cond_broadcast(&condadder);
		pthread_mutex_unlock(&mt);
		sleep(1);
	}

}
int main(){
	pthread_t t1,t2,t3;
	pthread_mutex_init(&mt,NULL);
	pthread_cond_init(&condadder,NULL);
	pthread_cond_init(&conddeler,NULL);
	pthread_create(&t1,NULL,func,NULL);

	pthread_create(&t2,NULL,func,NULL);

	pthread_create(&t3,NULL,del,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);

	printf("%d\n",a);
	return 0;
}
