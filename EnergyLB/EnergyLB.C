/** 
 *  Author: Padoin 
 *  Date: April 2nd, 2014
 **/

#include "EnergyLB.h"
#include "ckgraph.h"

#include "RefineLB.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "/home/padoin/libLB/coreInfo.h"
#include "/home/padoin/libLB/files.h"


#define DEBUG	0	
#define DEBUG2	1	
#define DEBUGjob   0 

//struct of energy LB
//struct eLB_t *energyLB;
int *processor_model;
int *availableFreq;





//------------------------------------------------------------------------------------------------//
CreateLBFunc_Def(EnergyLB, "Load balancing using the EnergyLB library")


//------------------------------------------------------------------------------------------------//
void EnergyLB::init () {
  lbname = "EnergyLB";

//	if (_lb_args.debug()>=1) {
//	    	CkPrintf("_[%d] In EnergyLB strategy\n",CkMyPe());
//	}

	if (CkMyPe()%CORE_X_CPU == 0){   //Only one LB per compute node
		CkPrintf("[%d] EnergyLB starting...........\n",CkMyPe());

		//processor name
		processor_model = (int *) malloc (1* sizeof(int));
		*processor_model = get_processor_name(); 
		//#if DEBUG
		//	print_processor_name(*processor_model);
		//#endif

		step = 0;
		other = 0;
		auxtimesLoad = 0.0;

		//get avaliable frequency
		availableFreq = (int *) malloc (20* sizeof(int));
		
		get_all_available_frequencies(availableFreq);
		print_all_available_frequencies(availableFreq);
	
	
	}


	if (CkMyPe() == 0){ 	
		cout << endl << "version 08.04.14" << endl;
	}
		
}






//------------------------------------------------------------------------------------------------//
EnergyLB::EnergyLB(const CkLBOptions &opt) : CentralLB(opt) {
    init();

  if(CkMyPe() == 0) {
	CkPrintf("[%d] EnergyLB created\n",CkMyPe());
  }
}



//------------------------------------------------------------------------------------------------//
EnergyLB::EnergyLB(CkMigrateMessage *m) : CentralLB(m) {
    init();
}




//------------------------------------------------------------------------------------------------//
bool EnergyLB::QueryBalanceNow(int _step) {
  return true;
}










//------------------------------------------------------------------------------------------------//
void EnergyLB::work(LDStats *stats) {


	//------------------------------------------------------
	//define var charm
	ProcArray *parr = new ProcArray(stats);
	ObjGraph *ogr = new ObjGraph(stats);
	//double start_time = CmiWallTimer();



	//------------------------------------------------------
	//define var LB
	int changed =0;
	int i;



	//------------------------------------------------------	
	//numero of cpus --- +p[cpu]
	int n_core=stats->nprocs();
	//	int numPes = parr->procs.size();
	#if DEBUG2
		CkPrintf("\n__Qtde de cores: %d", n_core);
	//	CkPrintf("\n_[%d] - cores %d \n", CkMyPe(), numPes);
	#endif




	//------------------------------------------------------
	//quantidade de objetos
	int qtde_obj = ogr->vertices.size();
	#if DEBUG2
		cout << endl << "__Qtde de obj: " << qtde_obj;
	#endif




	//------------------------------------------------------
	//quantidade de obj por core
	int vObj[n_core];  
	double carga_do_core[n_core];	
	double carga_real_do_core[n_core];	
	
	for(i = 0; i < n_core; i++) {
		vObj[i] = 0;
		carga_do_core [i] = 0.0;		
		carga_real_do_core [i] = 0.0;
	}

	for(i = 0; i<qtde_obj; i++) {
		vObj[ogr->vertices[i].getCurrentPe()]++;		
		//#if DEBUG
		//   std::cout 	<< "getVertexId " << std::setw(2) << ogr->vertices[i].getVertexId()  
		//				<< "| " << "getVertexLoad "  << std::setw(10) << ogr->vertices[i].getVertexLoad() 
		//				<< "| " << "getCurrentPe " << std::setw(10) << ogr->vertices[i].getCurrentPe() << endl;

		//if (ogr->vertices[i].getCurrentPe() != ogr->vertices[i-1].getCurrentPe())
		//	cout << endl;
		//cout << ":" << ogr->vertices[i].getCurrentPe();
		//#endif	
	}

	#if DEBUG
		//cout << endl << "__Qtde de obj por core:" << endl;
		for(i = 0; i < n_core; i++) 
			cout << ".....core: " << i << " obj: " << vObj[i] << endl;
	#endif
	
	#if DEBUG2	
		CkPrintf("\n__core : ");		
		for(i = 0; i < n_core; i++) {
			CkPrintf("%4d ", i);			
		}
		CkPrintf("\n__Objet: ");				
		for(i = 0; i < n_core; i++) {
			CkPrintf("%4d ", vObj[i]);			
		}
	#endif


	//------------------------------------------------------
	//get current frequency
	int *currentFreq, *posFreq, minFreq=3000000, maxFreq=0;
	int imaxFreq, iminFreq;

	currentFreq = (int *) malloc (n_core* sizeof(int));
	posFreq     = (int *) malloc (n_core* sizeof(int));

	imaxFreq = iminFreq = 0;
	for (i=0; i<n_core; i++){  
		currentFreq[i] = get_frequency_max(i*CORE_X_CPU);							//(i);//  check i*8


		//------------------------------------------------------
		//set relative frequency
		stats->procs[i].pe_speed = (double) currentFreq[i] / 2400000;
		//cout << "core: " << i << " pe_speed: " << stats->procs[i].pe_speed << endl;



		//------------------------------------------------------
		//set posicao da freq
		for (int f=0; f < 14; f++) {												//check f=1
			if (currentFreq[i] == availableFreq[f])
				posFreq[i] = f;
				//cout << "core: " << i << " currentFreq: " << currentFreq[i] << endl;
		}

	#if DEBUG
		CkPrintf(".....core: %d - freq: %d pos: %d ------ pe_speed: %g \n", i, currentFreq[i], posFreq[i], stats->procs[i].pe_speed); 
	#endif
		if (maxFreq < currentFreq[i]) {
			maxFreq = currentFreq[i];
			imaxFreq = i;			
		}
		if (minFreq > currentFreq[i]){
			minFreq = currentFreq[i];
			iminFreq = i;			
		}
	}


	#if DEBUG2
		CkPrintf("\n__curfr: ");		
		for(i = 0; i < n_core; i++) {
			CkPrintf("%4d ", currentFreq[i]/1000);			
		}
		CkPrintf("\n__posfr: ");				
		for(i = 0; i < n_core; i++) {
			CkPrintf("%4d ", posFreq[i]);			
		}
		CkPrintf("\n__speed: ");		
		for(i = 0; i < n_core; i++) {
			CkPrintf("%.2f ", stats->procs[i].pe_speed);			
		}
	#endif
	


  




	//------------------------------------------------------
	//calcula a carga de acordo com a frequencia = carga * freq do core
	double carga_real[qtde_obj];

	for(i = 0; i<qtde_obj; i++) {
		
		carga_real[i] = ogr->vertices[i].getVertexLoad()  * currentFreq[ogr->vertices[i].getCurrentPe()];	
		
		carga_real_do_core [ogr->vertices[i].getCurrentPe()] += carga_real[i];
		
		#if DEBUGjob
		   std::cout 	<< "VId " << std::setw(2) << ogr->vertices[i].getVertexId()  
						<< " | " << "VLoad "  << std::setw(10) << ogr->vertices[i].getVertexLoad() 
						<< " | " << "CurrentPe " << std::setw(2) << ogr->vertices[i].getCurrentPe() 
						<< " | " << "Real load " << std::setw(10) << carga_real[i] << endl;

		#endif	
	}




	//------------------------------------------------------
	//calcula a carga real de cada core
	int imaxLoad, iminLoad;
	double maxLoad =  carga_real_do_core[0];
	double minLoad =  carga_real_do_core[0];
	imaxLoad = 0;
	iminLoad = 0;
	
	for(int i=0; i<n_core; i++){

		//CkPrintf("core [%d] - carga_real_do_core: [%g] \n", i, carga_real_do_core[i]); 

		if (maxLoad < carga_real_do_core[i]) {
			maxLoad = carga_real_do_core[i];
			imaxLoad = i;			
		} else
		if (minLoad > carga_real_do_core[i]){
			minLoad = carga_real_do_core[i];
			iminLoad = i;			
		}
	}




	//------------------------------------------------------
	//calcula qtde de vezes de carga maior
	double timesLoad[n_core];

	for(int i=0; i<n_core; i++){
		timesLoad[i] = maxLoad / carga_real_do_core[i];
		#if DEBUG
			CkPrintf(".....core: %d - real load: %g - timesLoad: %g \n", i, carga_real_do_core[i], timesLoad[i]); 
		#endif	
	}
 
		#if DEBUG2
		CkPrintf("\n__load : ");		
		for(i = 0; i < n_core; i++) {
			CkPrintf("%1.2f  ", carga_real_do_core[i]);			
		}
		CkPrintf("\n__rload: ");				
		for(i = 0; i < n_core; i++) {
			CkPrintf("%.2f  ", timesLoad[i]);			
		}
		#endif	
 


	//------------------------------------------------------
	//max e min freq of the PEs load of the core
	#if DEBUG2
		CkPrintf("\n__Minimum Freq - core: %d - Freq: %d", iminFreq, minFreq);
		CkPrintf("\n__Maximum Freq - core: %d - Freq: %d", imaxFreq, maxFreq);
		CkPrintf("\n__Minimum Load - core: %d - load: %g", iminLoad, minLoad);   //(parr->getAverageLoad()/minLoad)
		CkPrintf("\n__Maxinum Load - core: %d - load: %g", imaxLoad, maxLoad);   //(parr->getAverageLoad()/maxLoad)
	#endif	






	//------------------------------------------------------
	//calcula clock frequ
	double tmp = 0.0;
	int f, newpos=1;
	#if DEBUG2
		cout << endl << "...timesLoad[max/min]: " << timesLoad[iminLoad] << " lasttimesLoad " << auxtimesLoad << endl;
	#endif		

//	if ((timesLoad[iminLoad] > 2) && (other < 3)) {  //porque < 2 podemos resolver com DVFS   - 3 limite de chamadas do other
	if (timesLoad[iminLoad] > 1) {  ///auxtimesLoad ) {
///		refine->work(stats);
///		other++;	    
///	    	auxtimesLoad = timesLoad[iminLoad];	
///	} else
///	{
		step++;
		auxtimesLoad = timesLoad[iminLoad];

		for(int i=0; i<n_core; i++){

				//------------------------------------------------------
				//calcula em tmp a proporcao
				//tmp = parr->procs[i].getTotalLoad() /maxLoad * availableFreq[0];
				tmp = carga_real_do_core[i] / maxLoad * availableFreq[1];

                                // maior q o maximo
                                if (tmp >= availableFreq[1])  {
                                        newpos = 1;
                                        cout << endl << ":::core: " << i << " MAIOR tmp > maximo tmp= " << tmp << " newpos " << newpos << endl;
                                } else 
                                // menor q o minimo 
                                if (tmp <= availableFreq[13])  {
                                        newpos = 13;
					cout << endl << ":::core: " << i << " MENOR tmp < minimo tmp= " << tmp << " newpos " << newpos << endl;
                                }

				//------------------------------------------------------
				// entre freq - calcula nova freq - apartir do 2 porque em 0 tem overclock
				for (f=2; f < 14; f++) {
					if ((tmp > availableFreq[f]) && (tmp < availableFreq[f-1])) {
						cout << endl  << ":::core: " << i  << " ENTRE tmp  " << availableFreq[f-1] << " ~ " << tmp << " - " << availableFreq[f] << endl;
						newpos=f-1;  //agressive = f    //moderate = f-1 
						//break;
					} 
				}


				//------------------------------------------------------
				//change frequency
				if (posFreq[i] != newpos) { //&& (imaxLoad != i)) {  

					int core0, core1;
					core0 = (i * CORE_X_CPU);
					core1 = (core0 + CORE_X_CPU-1);

					set_frequency(core0,core1,availableFreq[newpos]);
					CkPrintf("\nchange core %d  - currentFreq %d - newfreq %d\n\n", i, currentFreq[i], availableFreq[newpos]);
					changed++;

					if (newpos > posFreq[i]) 
               	        	        CkPrintf("DYNAMIC LOAD... \n");	
				}




              				//------------------------------------------------------
	                        //check dynamic load
 //       	                if  ((imaxLoad == i) && (posFreq[i] != availableFreq[1])) {  
               	                //	set_frequency(core0,core1,availableFreq[1]);
 //              	        	        CkPrintf("\n DYNAMIC LOAD... core %d  - currentFreq %d - newfreq %d\n\n", i, currentFreq[i], availableFreq[1]);
               		        //        changed++;
//                        	}


			     	//------------------------------------------------------
			        //set relative frequency

				//stats->procs[i].pe_speed = (double) availableFreq[newpos] / 2400000;
				//cout << "core: " << i << " currentfreq: " << availableFreq[newpos] << " pe_speed: " << stats->procs[i].pe_speed << endl;

		}//do for
	}//do else






	//------------------------------------------------------
	//atualizacao
	for(i = 0; i < ogr->vertices.size(); i++) {
		ogr->vertices[i].setNewPe(ogr->vertices[i].getCurrentPe());
	}

	#if DEBUG2
		CkPrintf("EnergyLB: %d  otherLB: %d\n", step, other);
		CkPrintf("===========================================\n");
	#endif

	//------------------------------------------------------
    //CLEANUP
	ogr->convertDecisions(stats);
	delete parr;
	delete ogr;
}

#include "EnergyLB.def.h"

/*@}*/




//////////////////////////////////////////////////////////////////////////////
//estrategia 5
//Load do PE / maxLoad * max freq
//atribui frequencias de acordo com o Load de cada core 
//nao permite mais aumentar a freq

//////////////////////////////////////////////////////////////////////////////
//estrategia 6
//primeiro migra alguns processos (Greedy) para deixar a dif < 2
//depois muda a freq

//////////////////////////////////////////////////////////////////////////////
//estrategia 7
//atualiza stats->procs[i].pe_speed de acordo com a relacao 
