/** 
 *  Authors: Padoin 
 *  Date: April 2nd, 2014
 **/


#ifndef _ENERGYLB_H_
#define _ENERGYLB_H_

#include "CentralLB.h"
#include "EnergyLB.decl.h"

void CreateEnergyLB();
BaseLB * AllocateEnergyLB();

class EnergyLB : public CentralLB {
  public:
    EnergyLB(const CkLBOptions &opt);
    EnergyLB(CkMigrateMessage *m);

    void work(LDStats *stats);
    void pup(PUP::er &p) { CentralLB::pup(p); }


protected:
	CentralLB *refine;
    void init ();


  private:
    bool QueryBalanceNow(int _step);
    	int step;
    	int other;
	int nprocs;
	double auxtimesLoad;
};

#endif /* _GRAPHPARTLB_H_ */

/*@}*/
