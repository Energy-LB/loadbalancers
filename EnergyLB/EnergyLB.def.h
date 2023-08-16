

/* DEFS: group EnergyLB: CentralLB{
EnergyLB(CkMigrateMessage* impl_msg);
void EnergyLB(const CkLBOptions &impl_noname_0);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_EnergyLB::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: EnergyLB(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void EnergyLB(const CkLBOptions &impl_noname_0);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: EnergyLB(CkMigrateMessage* impl_msg);
 */

// Entry point registration function

int CkIndex_EnergyLB::reg_EnergyLB_CkMigrateMessage() {
  int epidx = CkRegisterEp("EnergyLB(CkMigrateMessage* impl_msg)",
      _call_EnergyLB_CkMigrateMessage, 0, __idx, 0+CK_EP_INTRINSIC);
  return epidx;
}


void CkIndex_EnergyLB::_call_EnergyLB_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  EnergyLB* impl_obj = static_cast<EnergyLB *>(impl_obj_void);
  new (impl_obj) EnergyLB((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void EnergyLB(const CkLBOptions &impl_noname_0);
 */

CkGroupID CProxy_EnergyLB::ckNew(const CkLBOptions &impl_noname_0, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CkLBOptions &impl_noname_0
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CkLBOptions &)impl_noname_0;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CkLBOptions &)impl_noname_0;
  }
  return CkCreateGroup(CkIndex_EnergyLB::__idx, CkIndex_EnergyLB::idx_EnergyLB_marshall1(), impl_msg);
}

  CProxy_EnergyLB::CProxy_EnergyLB(const CkLBOptions &impl_noname_0, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const CkLBOptions &impl_noname_0
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CkLBOptions &)impl_noname_0;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CkLBOptions &)impl_noname_0;
  }
  ckSetGroupID(CkCreateGroup(CkIndex_EnergyLB::__idx, CkIndex_EnergyLB::idx_EnergyLB_marshall1(), impl_msg));
}

// Entry point registration function

int CkIndex_EnergyLB::reg_EnergyLB_marshall1() {
  int epidx = CkRegisterEp("EnergyLB(const CkLBOptions &impl_noname_0)",
      _call_EnergyLB_marshall1, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP+CK_EP_INTRINSIC);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_EnergyLB_marshall1);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_EnergyLB_marshall1);

  return epidx;
}


void CkIndex_EnergyLB::_call_EnergyLB_marshall1(void* impl_msg, void* impl_obj_void)
{
  EnergyLB* impl_obj = static_cast<EnergyLB *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CkLBOptions &impl_noname_0*/
  PUP::fromMem implP(impl_buf);
  CkLBOptions impl_noname_0; implP|impl_noname_0;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) EnergyLB(impl_noname_0);
}

int CkIndex_EnergyLB::_callmarshall_EnergyLB_marshall1(char* impl_buf, void* impl_obj_void) {
  EnergyLB* impl_obj = static_cast< EnergyLB *>(impl_obj_void);
  /*Unmarshall pup'd fields: const CkLBOptions &impl_noname_0*/
  PUP::fromMem implP(impl_buf);
  CkLBOptions impl_noname_0; implP|impl_noname_0;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj) EnergyLB(impl_noname_0);
  return implP.size();
}

void CkIndex_EnergyLB::_marshallmessagepup_EnergyLB_marshall1(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CkLBOptions &impl_noname_0*/
  PUP::fromMem implP(impl_buf);
  CkLBOptions impl_noname_0; implP|impl_noname_0;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("impl_noname_0");
  implDestP|impl_noname_0;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: EnergyLB(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void EnergyLB(const CkLBOptions &impl_noname_0);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_EnergyLB::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeGroup);
  CkRegisterChareInCharm(__idx);
  CkRegisterBase(__idx, CkIndex_CentralLB::__idx);
   CkRegisterGroupIrr(__idx,EnergyLB::isIrreducible());
  // REG: EnergyLB(CkMigrateMessage* impl_msg);
  idx_EnergyLB_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_EnergyLB_CkMigrateMessage());

  // REG: void EnergyLB(const CkLBOptions &impl_noname_0);
  idx_EnergyLB_marshall1();

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registerEnergyLB(void)
{
  static int _done = 0; if(_done) return; _done = 1;
  _registerCentralLB();

  _registerInitCall(lbinit,1);

/* REG: group EnergyLB: CentralLB{
EnergyLB(CkMigrateMessage* impl_msg);
void EnergyLB(const CkLBOptions &impl_noname_0);
};
*/
  CkIndex_EnergyLB::__register("EnergyLB", sizeof(EnergyLB));

}
#endif /* CK_TEMPLATES_ONLY */
