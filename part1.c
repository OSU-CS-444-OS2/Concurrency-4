#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <signal.h>
#include <stdbool.h>

//Global Varibles
sem_t resource;
int running_processes;
int neededAmount;
int go;

//Functions
void *takeResource( void *arg );

int main(int argc, char *argv[]){

	//Semaphore init
	sem_init( &resource, 0, 3 );

	//Create Processes
	pthread_t processes[6];

	//Number of running processes
	running_processes = 0;
	neededAmount = 0;
	go = 0;

	int i, id[2];
	for( i = 0; i < 6; i++){

		//Gives id numbers
		id[i]=i;

		//Creating thread
		pthread_create( &processes[i], NULL, takeResource, (void*)( &id[i] ) );

	}

	while(1){

	}

	return 0;
}

void *takeResource( void *arg ){

	int process_id = *(int *)arg;

	while(1){

		

		//Check the number of running processes
			while( go != 0 ){
				printf( "Too many processes running - Process %d waiting\n", process_id );
				sleep( 7 );
			}
		

		//Wait to see if resource is being taken
		sem_wait( &resource );

		//incr processes running
		running_processes += 1;

		if(running_processes == 3){
			go = 1;
		}

		//Start
		printf( "---------- Process %d Starts ----------\n", process_id );            		
		fflush( stdout );

		//Take resource
		printf( "---------- Process %d taking resource \n", process_id );            		
		fflush( stdout );

		//Sleeps
		sleep( 5 );
		neededAmount += 1;

		//Seacher ends
		printf( "---------- Process %d Ends ----------\n" , process_id);     
		fflush( stdout );  

		//Unlocks
		sem_post( &resource );
		neededAmount -= 1;

		while(neededAmount != 0){
			sleep(1);
		}

		//decr processes running
		running_processes -= 1;
		
		if(running_processes == 0){
			go = 0;
		}

		printf( "RunningProcesses: %d\n", running_processes);
		fflush( stdout );  
		//Sleeps
		sleep( 10 );

	}

}
