#ifndef _DECL_fib_H_
#define _DECL_fib_H_
#include "charm++.h"
#include "envelope.h"
#include <memory>
#include "sdag.h"
#ifndef GROUPDEPNUM_DECLARED
# define GROUPDEPNUM_DECLARED
struct GroupDepNum
{
  int groupDepNum;
  explicit GroupDepNum(int g = 0) : groupDepNum{g} { }
  operator int() const { return groupDepNum; }
};
#endif
/* DECLS: message ValueMsg;
 */
class ValueMsg;
class CMessage_ValueMsg:public CkMessage{
  public:
    static int __idx;
    void* operator new(size_t, void*p) { return p; }
    void* operator new(size_t);
    void* operator new(size_t, int*, const int);
    void* operator new(size_t, int*, const int, const GroupDepNum);
    void* operator new(size_t, int*);
#if CMK_MULTIPLE_DELETE
    void operator delete(void*p, void*){dealloc(p);}
    void operator delete(void*p){dealloc(p);}
    void operator delete(void*p, int*, const int){dealloc(p);}
    void operator delete(void*p, int*, const int, const GroupDepNum){dealloc(p);}
    void operator delete(void*p, int*){dealloc(p);}
#endif
    void operator delete(void*p, size_t){dealloc(p);}
    static void* alloc(int,size_t, int*, int, GroupDepNum);
    static void dealloc(void *p);
    CMessage_ValueMsg();
    static void *pack(ValueMsg *p);
    static ValueMsg* unpack(void* p);
    void *operator new(size_t, const int);
    void *operator new(size_t, const int, const GroupDepNum);
#if CMK_MULTIPLE_DELETE
    void operator delete(void *p, const int){dealloc(p);}
    void operator delete(void *p, const int, const GroupDepNum){dealloc(p);}
#endif
    static void __register(const char *s, size_t size, CkPackFnPtr pack, CkUnpackFnPtr unpack) {
      __idx = CkRegisterMsg(s, pack, unpack, dealloc, size);
    }
};

/* DECLS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void run(int n);
};
 */
 class Main;
 class CkIndex_Main;
 class CProxy_Main;
/* --------------- index object ------------------ */
class CkIndex_Main:public CkIndex_Chare{
  public:
    typedef Main local_t;
    typedef CkIndex_Main index_t;
    typedef CProxy_Main proxy_t;
    typedef CProxy_Main element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Main(CkArgMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Main_CkArgMsg();
    // Entry point index lookup
    
    inline static int idx_Main_CkArgMsg() {
      static int epidx = reg_Main_CkArgMsg();
      return epidx;
    }

    
    static int ckNew(CkArgMsg* impl_msg) { return idx_Main_CkArgMsg(); }
    
    static void _call_Main_CkArgMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Main_CkArgMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void run(int n);
     */
    // Entry point registration at startup
    
    static int reg_run_marshall2();
    // Entry point index lookup
    
    inline static int idx_run_marshall2() {
      static int epidx = reg_run_marshall2();
      return epidx;
    }

    
    inline static int idx_run(void (Main::*)(int n) ) {
      return idx_run_marshall2();
    }


    
    static int run(int n) { return idx_run_marshall2(); }
    
    static void _call_run_marshall2(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_run_marshall2(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_run_marshall2(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_run_marshall2(PUP::er &p,void *msg);
};
/* --------------- element proxy ------------------ */
class CProxy_Main:public CProxy_Chare{
  public:
    typedef Main local_t;
    typedef CkIndex_Main index_t;
    typedef CProxy_Main proxy_t;
    typedef CProxy_Main element_t;

    CProxy_Main(void) {};
    CProxy_Main(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_Main(const Chare *c) : CProxy_Chare(c){  }

    int ckIsDelegated(void) const
    { return CProxy_Chare::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_Chare::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_Chare::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_Chare::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_Chare::ckCheck(); }
    const CkChareID &ckGetChareID(void) const
    { return CProxy_Chare::ckGetChareID(); }
    operator const CkChareID &(void) const
    { return ckGetChareID(); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_Chare::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_Chare::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_Chare::pup(p);
    }

    void ckSetChareID(const CkChareID &c)
    {      CProxy_Chare::ckSetChareID(c); }
    Main *ckLocal(void) const
    { return (Main *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Main(CkArgMsg* impl_msg);
 */
    static CkChareID ckNew(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);
    static void ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int onPE=CK_PE_ANY);

/* DECLS: void run(int n);
 */
    
    void run(int n, const CkEntryOptions *impl_e_opts=NULL);

};
#define Main_SDAG_CODE 
typedef CBaseT1<Chare, CProxy_Main>CBase_Main;

/* DECLS: chare Fib: Chare{
Fib(int n, const CkFuture &f);
void run(int n, const CkFuture &f);
};
 */
 class Fib;
 class CkIndex_Fib;
 class CProxy_Fib;
/* --------------- index object ------------------ */
class CkIndex_Fib:public CkIndex_Chare{
  public:
    typedef Fib local_t;
    typedef CkIndex_Fib index_t;
    typedef CProxy_Fib proxy_t;
    typedef CProxy_Fib element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Fib(int n, const CkFuture &f);
     */
    // Entry point registration at startup
    
    static int reg_Fib_marshall1();
    // Entry point index lookup
    
    inline static int idx_Fib_marshall1() {
      static int epidx = reg_Fib_marshall1();
      return epidx;
    }

    
    static int ckNew(int n, const CkFuture &f) { return idx_Fib_marshall1(); }
    
    static void _call_Fib_marshall1(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Fib_marshall1(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_Fib_marshall1(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_Fib_marshall1(PUP::er &p,void *msg);
    /* DECLS: void run(int n, const CkFuture &f);
     */
    // Entry point registration at startup
    
    static int reg_run_marshall2();
    // Entry point index lookup
    
    inline static int idx_run_marshall2() {
      static int epidx = reg_run_marshall2();
      return epidx;
    }

    
    inline static int idx_run(void (Fib::*)(int n, const CkFuture &f) ) {
      return idx_run_marshall2();
    }


    
    static int run(int n, const CkFuture &f) { return idx_run_marshall2(); }
    
    static void _call_run_marshall2(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_run_marshall2(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_run_marshall2(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_run_marshall2(PUP::er &p,void *msg);
};
/* --------------- element proxy ------------------ */
class CProxy_Fib:public CProxy_Chare{
  public:
    typedef Fib local_t;
    typedef CkIndex_Fib index_t;
    typedef CProxy_Fib proxy_t;
    typedef CProxy_Fib element_t;

    CProxy_Fib(void) {};
    CProxy_Fib(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_Fib(const Chare *c) : CProxy_Chare(c){  }

    int ckIsDelegated(void) const
    { return CProxy_Chare::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_Chare::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_Chare::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_Chare::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_Chare::ckCheck(); }
    const CkChareID &ckGetChareID(void) const
    { return CProxy_Chare::ckGetChareID(); }
    operator const CkChareID &(void) const
    { return ckGetChareID(); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_Chare::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_Chare::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_Chare::pup(p);
    }

    void ckSetChareID(const CkChareID &c)
    {      CProxy_Chare::ckSetChareID(c); }
    Fib *ckLocal(void) const
    { return (Fib *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Fib(int n, const CkFuture &f);
 */
    static CkChareID ckNew(int n, const CkFuture &f, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(int n, const CkFuture &f, CkChareID* pcid, int onPE=CK_PE_ANY, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void run(int n, const CkFuture &f);
 */
    
    void run(int n, const CkFuture &f, const CkEntryOptions *impl_e_opts=NULL);

};
#define Fib_SDAG_CODE 
typedef CBaseT1<Chare, CProxy_Fib>CBase_Fib;


/* ---------------- method closures -------------- */
class Closure_Main {
  public:


    struct run_2_closure;

};

/* ---------------- method closures -------------- */
class Closure_Fib {
  public:


    struct run_2_closure;

};

extern void _registerfib(void);
extern "C" void CkRegisterMainModule(void);
#endif
