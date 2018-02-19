#include <sched.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <errno.h>
#include <stdio.h>


void delayMicroseconds (unsigned int howLong){
	struct timespec sleeper ;
	unsigned int uSecs = howLong % 1000000 ;
	unsigned int wSecs = howLong / 1000000 ;

	if (howLong ==   0)
		return ;
	else
		{
			sleeper.tv_sec  = wSecs ;
			sleeper.tv_nsec = (long)(uSecs * 1000L) ;
			nanosleep (&sleeper, NULL) ;
		}
}

void set_max_priority(void) {

  struct sched_param sched;
  memset(&sched, 0, sizeof(sched));
  // Use FIFO scheduler with highest priority for the lowest chance of the kernel context switching.
  sched.sched_priority = sched_get_priority_max(SCHED_FIFO);
  sched_setscheduler(0, SCHED_FIFO, &sched);

}

void set_default_priority(void) {
  struct sched_param sched;
  memset(&sched, 0, sizeof(sched));
  // Go back to default scheduler with default 0 priority.
  sched.sched_priority = 0;
  sched_setscheduler(0, SCHED_OTHER, &sched);
}
