/** 
 *  Authors: Edson L Padoin 
 *  Date: April 2nd, 2014
 **/

#ifndef HYBRIDLB_H
#define HYBRIDLB_H

#include "CentralLB.h"
#include "HybridBaseLB.h"
#include "HybridLB.decl.h"

#include "topology.h"

void CreateHybridLB();

class HybridLB : public HybridBaseLB
{
public:
  HybridLB(const CkLBOptions &);
  HybridLB(CkMigrateMessage *m): HybridBaseLB(m) {}
  ~HybridLB();

protected:
  CentralLB *greedy;
  CentralLB *refine;
  CentralLB *energy;

  virtual CmiBool QueryBalanceNow(int) { return CmiTrue; };  
  virtual CmiBool QueryMigrateStep(int) { return CmiTrue; };  
  virtual void work(LDStats* stats);

};

#endif /* NBORBASELB_H */

/*@}*/
