#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<pthread.h>
#include<sys/wait.h>
#include<string.h>

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cd;
char*words[]={"word1","word2","word3","word4","word5","word6"};
int flag=0;
void* t1(void* arg){
	while(1){
		pthread_mutex_lock(&lock);
        while(flag%2!=0){
			pthread_cond_wait(&cd,&lock);
		}
		if(flag>=6){
			pthread_mutex_unlock(&lock);
			pthread_cond_signal(&cd);
			break;
		}
		printf("t1 handle:%s\n",words[flag]);
		flag++;
		pthread_mutex_unlock(&lock);
		pthread_cond_signal(&cd);
		usleep(20000);
	}
	pthread_exit(NULL);
}

void* t2(void* arg){
	while(1){
		pthread_mutex_lock(&lock);
        while(flag%2==0){
			pthread_cond_wait(&cd,&lock);
		}
		if(flag>=6){
			pthread_mutex_unlock(&lock);
		    pthread_cond_signal(&cd);
			break;
		}
		printf("t2 handle:%s\n",words[flag]);
		flag++;
		pthread_mutex_unlock(&lock);
		pthread_cond_signal(&cd);
		usleep(20000);
	}
	pthread_exit(NULL);
}

int main(void){
	pthread_cond_init(&cd,NULL);
	pthread_t tid1,tid2;
	int err;
	if((err=pthread_create(&tid1,NULL,t1,NULL))>0){
		printf("t1 create fail:%s\n",strerror(err));
		exit(0);
	}
	if((err=pthread_create(&tid2,NULL,t2,NULL))>0){
		printf("t2 create fail:%s\n",strerror(err));
		exit(0);
	}
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_cond_destroy(&cd);
	pthread_mutex_destroy(&lock);
	printf("pthread recyle sucess");
	return 0;
}

