
/**
 *  \addtogroup CkLdb
 */

/*@{*/


#include "SmartLB.h"
#include "ckgraph.h"
#include "stdio.h"

#define THRESHOLD 0.95
#define DEBUG 1

// double normalTolerance=0.20, diference;
int taskCount=0, migrationCount=0, *highestLessProcessor;

CreateLBFunc_Def(SmartLB, "My first load balancer")

SmartLB::SmartLB(const CkLBOptions &opt) : CentralLB(opt) {
  lbname = "SmartLB";
  if(CkMyPe() == 0)
    CkPrintf("SmartLB created on processor %d\n",CkMyPe());
}

CmiBool SmartLB::QueryBalanceNow(int _step) {
  return CmiTrue;
}

int SmartLB::getLessLoadProc(int n_pes, double *pe_loads) {
	int less = 0;
	for (int i = 0; i < n_pes; i++){
		if (pe_loads[less] > pe_loads[i]) {
			less = i;
		}
	}

	return less;
}

int * SmartLB::getMoreAndLessThanAverage(int n_pes, double *pe_loads) {
	int more = 0, less = 0;
	static int array[2];
	for (int i = 0; i < n_pes; i++){
		if (pe_loads[more] < pe_loads[i]) {
			more = i;
		}

		if (pe_loads[less] > pe_loads[i]) {
			less = i;
		}
	}

	array[0] = less;
	array[1] = more;

	return array;
}


double SmartLB::getAverageLoad(LDStats *stats) {
	int n_pes = stats->nprocs();
	double load=0.0;

	for (int i=0; i<n_pes; i++) {
		load += (stats->procs[i].total_walltime - stats->procs[i].idletime - stats->procs[i].bg_walltime);
	}

	return load/n_pes;
}


void SmartLB::procuraProc(LDStats *stats, double *pe_loads, int highestProcessor, int lessProcessor, int n_pes) {
	double walltime = 0, averageLoad = getAverageLoad(stats);

	if (pe_loads[lessProcessor] <= (pe_loads[highestProcessor]*THRESHOLD)) {
		for (int j=0; j<stats->n_objs; j++) {
			if (pe_loads[stats->from_proc[j]] >= averageLoad) {

				LDObjData &oData = stats->objData[j];
				walltime = oData.wallTime;

				if (oData.wallTime <= (pe_loads[stats->from_proc[j]]-pe_loads[lessProcessor])) {
					stats->to_proc[j] = lessProcessor;
					pe_loads[lessProcessor] += walltime;
					pe_loads[stats->from_proc[j]] -= walltime;
					lessProcessor = getLessLoadProc(n_pes, pe_loads);
				}
			}
		}
	}
}

void SmartLB::work(LDStats *stats) {
	/** ========================== INITIALIZATION ============================= */
	int n_pes = stats->nprocs();
	double pe_loads[n_pes];

	for (int i=0; i<n_pes; i++) {
		pe_loads[i] = (stats->procs[i].total_walltime - stats->procs[i].idletime - stats->procs[i].bg_walltime);
	}

	/** ============================= STRATEGY ================================ */
	highestLessProcessor = getMoreAndLessThanAverage(n_pes, pe_loads);
	procuraProc(stats, pe_loads, highestLessProcessor[1], highestLessProcessor[0], n_pes);

	if (DEBUG >= 1) {
		highestLessProcessor = getMoreAndLessThanAverage(n_pes, pe_loads);
		CkPrintf("maior[%d] = %f\n", highestLessProcessor[0], pe_loads[highestLessProcessor[0]]);
		CkPrintf("menor[%d] = %f\n", highestLessProcessor[1], pe_loads[highestLessProcessor[1]]);
	}
	/** ============================== CLEANUP ================================ */
	migrationCount++;
}
#include "SmartLB.def.h"
/*@}*/
