/** \file ScotchLB.h
 *  Authors: Edson L Padoin 
 *  Date Created: October 10th, 2013
 */

/**
 *  \addtogroup CkLdb
 */

/*@{*/

#ifndef _FIRSTLB_H_
#define _FIRSTLB_H_

#include "CentralLB.h"
#include "FirstLB.decl.h"

void CreateFirstLB();

class FirstLB : public CentralLB {
  public:
    FirstLB(const CkLBOptions &opt);
    FirstLB(CkMigrateMessage *m) : CentralLB (m) { };

    void work(LDStats *stats);
    void pup(PUP::er &p) { CentralLB::pup(p); }

protected:
  CentralLB *greedy;

  private:
    bool QueryBalanceNow(int _step);
    	int step;
    	int other;
	int nprocs;
	double auxtimesLoad;
};

#endif /* _GRAPHPARTLB_H_ */

/*@}*/
