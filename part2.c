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

	//Create Processes
	pthread_t customerThread[6], barberThread;

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

void *Barber( void *arg ){

	int process_id = *(int *)arg;
		

	//Start
	printf( "---------- Process %d Starts ----------\n", process_id );            		
	fflush( stdout );

	//Take resource
	printf( "---------- Process %d taking resource \n", process_id );            		
	fflush( stdout );

	//Sleeps
	sleep( 5 );

	//Seacher ends
	printf( "---------- Process %d Ends ----------\n" , process_id);     
	fflush( stdout );  

	//Unlocks
	

}

void *Customer( void *arg ){




}
