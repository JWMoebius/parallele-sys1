#include <stdio.h>
#include <omp.h>

int main (int argc, char* argv[])
{
    int numThreads;      // Gannzzahl, die Anzahl der Threads speichert
	int threadID;        // Gannzzahl, die Identität eines Threads speichert
	float start, end;    // Float-Fließkommazahlen start und end, die Zeitpunkt bei Berechnung festhalten
	
	start = omp_get_wtime();      //start speicher momentanen Zeitpunkt ab
	
	/*  Paralleler Abschnitt mit Threadanzahl n [hier 1], der die jeweilige Thread-NR und Anzahl ausgibt  */
	#pragma omp parallel num_threads(1)
	{
	    threadID = omp_get_thread_num();                  //speichert ID-Nummer des berechnenden Threads
		printf("Hello from thread %d\n", threadID);
		
		/*  Dieser Teil sollte nur vom Masterthread [ID=0] ausgeführt werden und soll 1x Threadanzahl ausgeben*/
		if  (threadID == 0)
		{
		    numThreads = omp_get_num_threads();                //numThreads speichert die Gesamtanzahl der Threads in diesem Abschnitt
			printf("Number of threads : %d\n", numThreads);
        }
    }
    
    end = omp_get_wtime();                                //end speichert den Zeitpunkt nach dem Ausführen des parallelen  Abschnitts
    printf("This task took %f seconds\n", end-start);	
	
	return 0;
}