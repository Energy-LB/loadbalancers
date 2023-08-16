/** 
 *  Authors: Edson L Padoin 
 *  Date: April 2nd, 2014
 **/

#include "ckgraph.h"

#include "HybridLB.h"
#include "LBDBManager.h"

#include "GreedyLB.h"
#include "GreedyCommLB.h"
#include "RefineCommLB.h"
#include "RefineLB.h"
#include "MetisLB.h"
#include "EnergyLB.h"

#define  DEBUGF(x)      // CmiPrintf x;

#define DEBUG   1 

//------------------------------------------------------------------------------------------------//
CreateLBFunc_Def(HybridLB, "Hybrid load balancer")




//------------------------------------------------------------------------------------------------//
HybridLB::HybridLB(const CkLBOptions &opt): HybridBaseLB(opt)
{
#if CMK_LBDB_ON
  lbname = (char *)"HybridLB";

  // defines topology in base class
  tree = new ThreeLevelTree(8);

  // decide which load balancer to call
  // IMPORTANT: currently, the greedy LB must allow objects that
  // are not from existing processors.
//  greedy = (CentralLB *)AllocateMetisLB();
  refine = (CentralLB *)AllocateRefineLB();
//  greedy = (CentralLB *)AllocateGreedyLB();
  energy = (CentralLB *)AllocateEnergyLB();

  initTree();
#endif
}



//------------------------------------------------------------------------------------------------//
HybridLB::~HybridLB()
{
  delete greedy;
  delete refine;
  delete energy;
}




//------------------------------------------------------------------------------------------------//
void HybridLB::work(LDStats* stats)
{
#if CMK_LBDB_ON
	theLbdb->ResetAdaptive();
  LevelData *lData = levelData[currentLevel];

  // TODO: let's generate LBMigrateMsg ourself
  //  take into account the outObjs
  //if (currentLevel == tree->numLevels()-1) 
  if (currentLevel == 1){
/*
	//------------------------------------------------------
	//define var charm
	ObjGraph *ogr = new ObjGraph(stats);
	

	//------------------------------------------------------	
	//numero of cpus --- 
	int n_core=stats->nprocs();
        #if DEBUG
                CkPrintf("\n===Qtde de cores: %d", n_core);
        #endif

	
	  
        //------------------------------------------------------
        //quantidade de objetos
        int qtde_obj = ogr->vertices.size();
        #if DEBUG
                CkPrintf("\n===Qtde de obj: %d", qtde_obj);
        #endif


	
	//------------------------------------------------------
	//verifica se todos os obj estao alocadas a um core
	unsigned int current_proc;
	int i;
	for(i = 0; i<qtde_obj; i++) {
		current_proc = ogr->vertices[i].getCurrentPe();
		if (current_proc < n_core){
			ogr->vertices[i].setNewPe(0);
	                CkPrintf("\n===Obj: %d atribuido para 0", i);
		}
	}
 */ 
    refine->work(stats);
  }else{
    energy->work(stats);
  }
#endif
}
  
#include "HybridLB.def.h"

/*@{*/

