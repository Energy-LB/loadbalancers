/**
 *  \addtogroup CkLdb
 */

/*@{*/

#ifndef _SMARTLB_H_
#define _SMARTLB_H_

#include "CentralLB.h"
#include "SmartLB.decl.h"

void CreateSmartLB();

class SmartLB : public CentralLB {
	public:

		SmartLB(const CkLBOptions &opt);
		SmartLB(CkMigrateMessage *m) : CentralLB (m) { };
		void procuraProc(LDStats *stats, double *pe_loads, int highestProcessor, int lessProcessorcd, int n_pes);
		int * getMoreAndLessThanAverage(int n_pes, double *pe_loads);
		double getAverageLoad(LDStats *stats);
		void work(LDStats *stats);
		int getLessLoadProc(int n_pes, double *pe_loads);
		void pup(PUP::er &p) {
			CentralLB::pup(p);
		}

	private:
		CmiBool QueryBalanceNow(int _step);
};

#endif /* _GRAPHPARTLB_H_ */

/*@}*/
