
Locking techniques

#1
-Disable interrupts when lock happens. 
-Implemented in early single processors
-This reqeuires too much trust in user application.
-Easy for a program to monopolize its execution
-Does not work in multiprocessors.
-Major problem is that the interrupts are lost.


