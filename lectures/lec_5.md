## Lecture 5 - Scheduling Today's main topic was scheduling in linux

### Goals

Started out with standard set of goals for linux, for example
- CPU utilization: Number of useful user process instructions executed within the processor
- Throughput: Number of tasks executed per unit time
- Minimize response time : Time to produce the first response based on the input
- Min turnaround time : Time to termination of the process 
- Min Waiting time : Time spent in the waiting queue

### Undergrad scheduling algorithms + Transition to what linux actually does

- FCFS
- Shortest job first
- Earliest deadline first
- Round robin 
- Priority scheduling
- Shortest time to completion first

Some of these algorithms require the information that is hard to obtain for example the deadline of the process, or how long the process will run. Also there are tradeoffs in terms of the goals achieved for each of the scheduling algorithm.

Therefore, what actually is done is some sort of hybrid of all these scheduling algorithms. 



## Linux O(N) schedules

NICE: In linux, the nice is an inversion of priority. The more nice the process is to other processes, the lower the priority is. 
Nice values range from -20(Highest priority) to 19(Lowest priority)

Task 0 is the task that cannot be killed, nor can it be slept, its task information is not used much

`NICE_TO_TICKS` is the actual timeslice that is determined based on the nice value, its calculation is something like
`TICK_SCALE(20-nice)+1`

Real time priorities are from 0-99,

Goodness values are calculated based on architectural parameters as well. These values range from -1000, to 1000. A small example is that suppose a process ran on the same processor, then high goodness is given to it in order to exploit temporal/spacial locality. For real time processes, goodness is given really high in order to schedule them first.

If it has some timeslice left, then approximate the goodness to that value, otherwise go to out.

For sleeping processs in the epoch, if it was not scheduled, we add half of its ticks to its timeslice so that the next time it gets more time to work


`do_timer` is the code to switch based on the timer values

kernel is non-preemptible in 1st version of linux

When kernel becomes preemptible maintanining the structures of kernel becomes harder.                    


Scheduling classes:
- SCHED_FIFO
- SCHED_RR
- SCHED_OTHER

In each epoch task may run only once.

Global runqueue
select with highest value of goodness, if did not find, then recalculate -> this also marks the end of the epoch
determine timeslice based on nice values
recalculate goodness at the end of epoch for each process.


In O(1) schedules, there are 2 arrays, one for active set of tasks and another for expired.
Each epoch is basically defines as all tasks going from active to expired.

140 priority levels.
hardware instructions to see the highest value of priority                       
