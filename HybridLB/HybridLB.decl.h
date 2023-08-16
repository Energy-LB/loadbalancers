#ifndef _DECL_HybridLB_H_
#define _DECL_HybridLB_H_
#include "charm++.h"
#include <memory>
#include "LBDatabase.decl.h"

#include "HybridBaseLB.decl.h"


/* DECLS: group HybridLB: HybridBaseLB{
HybridLB(CkMigrateMessage* impl_msg);
void HybridLB(const CkLBOptions &impl_noname_0);
};
 */
 class HybridLB;
 class CkIndex_HybridLB;
 class CProxy_HybridLB;
 class CProxyElement_HybridLB;
 class CProxySection_HybridLB;
/* --------------- index object ------------------ */
class CkIndex_HybridLB:public CProxyElement_HybridBaseLB{
  public:
    typedef HybridLB local_t;
    typedef CkIndex_HybridLB index_t;
    typedef CProxy_HybridLB proxy_t;
    typedef CProxyElement_HybridLB element_t;
    typedef CProxySection_HybridLB section_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: HybridLB(CkMigrateMessage* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_HybridLB_CkMigrateMessage();
    // Entry point index lookup
    
    inline static int idx_HybridLB_CkMigrateMessage() {
      static int epidx = reg_HybridLB_CkMigrateMessage();
      return epidx;
    }

    
    static int ckNew(CkMigrateMessage* impl_msg) { return idx_HybridLB_CkMigrateMessage(); }
    
    static void _call_HybridLB_CkMigrateMessage(void* impl_msg, void* impl_obj);
    /* DECLS: void HybridLB(const CkLBOptions &impl_noname_0);
     */
    // Entry point registration at startup
    
    static int reg_HybridLB_marshall1();
    // Entry point index lookup
    
    inline static int idx_HybridLB_marshall1() {
      static int epidx = reg_HybridLB_marshall1();
      return epidx;
    }

    
    static int ckNew(const CkLBOptions &impl_noname_0) { return idx_HybridLB_marshall1(); }
    
    static void _call_HybridLB_marshall1(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_HybridLB_marshall1(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_HybridLB_marshall1(PUP::er &p,void *msg);
};
/* --------------- element proxy ------------------ */
class CProxyElement_HybridLB: public CProxyElement_HybridBaseLB{
  public:
    typedef HybridLB local_t;
    typedef CkIndex_HybridLB index_t;
    typedef CProxy_HybridLB proxy_t;
    typedef CProxyElement_HybridLB element_t;
    typedef CProxySection_HybridLB section_t;

    CProxyElement_HybridLB(void) {}
    CProxyElement_HybridLB(const IrrGroup *g) : CProxyElement_HybridBaseLB(g){  }
    CProxyElement_HybridLB(CkGroupID _gid,int _onPE,CK_DELCTOR_PARAM) : CProxyElement_HybridBaseLB(_gid,_onPE,CK_DELCTOR_ARGS){  }
    CProxyElement_HybridLB(CkGroupID _gid,int _onPE) : CProxyElement_HybridBaseLB(_gid,_onPE){  }

    int ckIsDelegated(void) const
    { return CProxyElement_HybridBaseLB::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxyElement_HybridBaseLB::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxyElement_HybridBaseLB::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxyElement_HybridBaseLB::ckDelegatedIdx(); }
inline void ckCheck(void) const {CProxyElement_HybridBaseLB::ckCheck();}
CkChareID ckGetChareID(void) const
   {return CProxyElement_HybridBaseLB::ckGetChareID();}
CkGroupID ckGetGroupID(void) const
   {return CProxyElement_HybridBaseLB::ckGetGroupID();}
operator CkGroupID () const { return ckGetGroupID(); }

    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_HybridBaseLB::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_HybridBaseLB::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxyElement_HybridBaseLB::ckSetReductionClient(cb); }
int ckGetGroupPe(void) const
{return CProxyElement_HybridBaseLB::ckGetGroupPe();}

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxyElement_HybridBaseLB::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxyElement_HybridBaseLB::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxyElement_HybridBaseLB::pup(p); }
    void ckSetGroupID(CkGroupID g) {
      CProxyElement_HybridBaseLB::ckSetGroupID(g);
    }
    HybridLB* ckLocalBranch(void) const {
      return ckLocalBranch(ckGetGroupID());
    }
    static HybridLB* ckLocalBranch(CkGroupID gID) {
      return (HybridLB*)CkLocalBranch(gID);
    }
/* DECLS: HybridLB(CkMigrateMessage* impl_msg);
 */

/* DECLS: void HybridLB(const CkLBOptions &impl_noname_0);
 */
    

};
PUPmarshall(CProxyElement_HybridLB)
/* ---------------- collective proxy -------------- */
class CProxy_HybridLB: public CProxy_HybridBaseLB{
  public:
    typedef HybridLB local_t;
    typedef CkIndex_HybridLB index_t;
    typedef CProxy_HybridLB proxy_t;
    typedef CProxyElement_HybridLB element_t;
    typedef CProxySection_HybridLB section_t;

    CProxy_HybridLB(void) {}
    CProxy_HybridLB(const IrrGroup *g) : CProxy_HybridBaseLB(g){  }
    CProxy_HybridLB(CkGroupID _gid,CK_DELCTOR_PARAM) : CProxy_HybridBaseLB(_gid,CK_DELCTOR_ARGS){  }
    CProxy_HybridLB(CkGroupID _gid) : CProxy_HybridBaseLB(_gid){  }
    CProxyElement_HybridLB operator[](int onPE) const
      {return CProxyElement_HybridLB(ckGetGroupID(),onPE,CK_DELCTOR_CALL);}

    int ckIsDelegated(void) const
    { return CProxy_HybridBaseLB::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_HybridBaseLB::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_HybridBaseLB::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_HybridBaseLB::ckDelegatedIdx(); }
inline void ckCheck(void) const {CProxy_HybridBaseLB::ckCheck();}
CkChareID ckGetChareID(void) const
   {return CProxy_HybridBaseLB::ckGetChareID();}
CkGroupID ckGetGroupID(void) const
   {return CProxy_HybridBaseLB::ckGetGroupID();}
operator CkGroupID () const { return ckGetGroupID(); }

    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_HybridBaseLB::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_HybridBaseLB::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxy_HybridBaseLB::ckSetReductionClient(cb); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_HybridBaseLB::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_HybridBaseLB::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_HybridBaseLB::pup(p); }
    void ckSetGroupID(CkGroupID g) {
      CProxy_HybridBaseLB::ckSetGroupID(g);
    }
    HybridLB* ckLocalBranch(void) const {
      return ckLocalBranch(ckGetGroupID());
    }
    static HybridLB* ckLocalBranch(CkGroupID gID) {
      return (HybridLB*)CkLocalBranch(gID);
    }
/* DECLS: HybridLB(CkMigrateMessage* impl_msg);
 */

/* DECLS: void HybridLB(const CkLBOptions &impl_noname_0);
 */
    
    static CkGroupID ckNew(const CkLBOptions &impl_noname_0, const CkEntryOptions *impl_e_opts=NULL);
    CProxy_HybridLB(const CkLBOptions &impl_noname_0, const CkEntryOptions *impl_e_opts=NULL);

};
PUPmarshall(CProxy_HybridLB)
/* ---------------- section proxy -------------- */
class CProxySection_HybridLB: public CProxySection_HybridBaseLB{
  public:
    typedef HybridLB local_t;
    typedef CkIndex_HybridLB index_t;
    typedef CProxy_HybridLB proxy_t;
    typedef CProxyElement_HybridLB element_t;
    typedef CProxySection_HybridLB section_t;

    CProxySection_HybridLB(void) {}
    CProxySection_HybridLB(const IrrGroup *g) : CProxySection_HybridBaseLB(g){  }
    CProxySection_HybridLB(const CkGroupID &_gid,const int *_pelist,int _npes,CK_DELCTOR_PARAM) : CProxySection_HybridBaseLB(_gid,_pelist,_npes,CK_DELCTOR_ARGS){  }
    CProxySection_HybridLB(const CkGroupID &_gid,const int *_pelist,int _npes) : CProxySection_HybridBaseLB(_gid,_pelist,_npes){  }
    CProxySection_HybridLB(int n,const CkGroupID *_gid, int const * const *_pelist,const int *_npes) : CProxySection_HybridBaseLB(n,_gid,_pelist,_npes){  }
    CProxySection_HybridLB(int n,const CkGroupID *_gid, int const * const *_pelist,const int *_npes,CK_DELCTOR_PARAM) : CProxySection_HybridBaseLB(n,_gid,_pelist,_npes,CK_DELCTOR_ARGS){  }

    int ckIsDelegated(void) const
    { return CProxySection_HybridBaseLB::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxySection_HybridBaseLB::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxySection_HybridBaseLB::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxySection_HybridBaseLB::ckDelegatedIdx(); }
inline void ckCheck(void) const {CProxySection_HybridBaseLB::ckCheck();}
CkChareID ckGetChareID(void) const
   {return CProxySection_HybridBaseLB::ckGetChareID();}
CkGroupID ckGetGroupID(void) const
   {return CProxySection_HybridBaseLB::ckGetGroupID();}
operator CkGroupID () const { return ckGetGroupID(); }

    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_HybridBaseLB::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_HybridBaseLB::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxySection_HybridBaseLB::ckSetReductionClient(cb); }
inline int ckGetNumSections() const
{ return CProxySection_HybridBaseLB::ckGetNumSections(); }
inline CkSectionInfo &ckGetSectionInfo()
{ return CProxySection_HybridBaseLB::ckGetSectionInfo(); }
inline CkSectionID *ckGetSectionIDs()
{ return CProxySection_HybridBaseLB::ckGetSectionIDs(); }
inline CkSectionID &ckGetSectionID()
{ return CProxySection_HybridBaseLB::ckGetSectionID(); }
inline CkSectionID &ckGetSectionID(int i)
{ return CProxySection_HybridBaseLB::ckGetSectionID(i); }
inline CkGroupID ckGetGroupIDn(int i) const
{ return CProxySection_HybridBaseLB::ckGetGroupIDn(i); }
inline int *ckGetElements() const
{ return CProxySection_HybridBaseLB::ckGetElements(); }
inline int *ckGetElements(int i) const
{ return CProxySection_HybridBaseLB::ckGetElements(i); }
inline int ckGetNumElements() const
{ return CProxySection_HybridBaseLB::ckGetNumElements(); } 
inline int ckGetNumElements(int i) const
{ return CProxySection_HybridBaseLB::ckGetNumElements(i); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxySection_HybridBaseLB::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxySection_HybridBaseLB::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxySection_HybridBaseLB::pup(p); }
    void ckSetGroupID(CkGroupID g) {
      CProxySection_HybridBaseLB::ckSetGroupID(g);
    }
    HybridLB* ckLocalBranch(void) const {
      return ckLocalBranch(ckGetGroupID());
    }
    static HybridLB* ckLocalBranch(CkGroupID gID) {
      return (HybridLB*)CkLocalBranch(gID);
    }
/* DECLS: HybridLB(CkMigrateMessage* impl_msg);
 */

/* DECLS: void HybridLB(const CkLBOptions &impl_noname_0);
 */
    

};
PUPmarshall(CProxySection_HybridLB)
typedef CBaseT1<HybridBaseLB, CProxy_HybridLB> CBase_HybridLB;

extern void _registerHybridLB(void);
#endif
