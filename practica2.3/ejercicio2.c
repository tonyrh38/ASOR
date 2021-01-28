// Politica de planificacion y prioridad proceso actual
// Maximo y minimo valor de prioridad para politica planificacion

#include <sched.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	
	struct sched_param *p;
	int policy = sched_getscheduler(0);
	printf("Politica de planificacion: %i\n", policy);
	sched_getparam(0, p);
	printf("Prioridad del proceso actual: %i\n",p->sched_priority);
	int range[2] = {sched_get_priority_min(policy), sched_get_priority_max(policy)};
	printf("Rango de prioridad: [%i,%i]", range[0], range[1]);
	return 0;
}
