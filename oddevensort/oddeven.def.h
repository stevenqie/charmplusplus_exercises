


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::done_2_closure : public SDAG::Closure {
      

      done_2_closure() {
        init();
      }
      done_2_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~done_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(done_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::secondDone_3_closure : public SDAG::Closure {
      

      secondDone_3_closure() {
        init();
      }
      secondDone_3_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~secondDone_3_closure() {
      }
      PUPable_decl(SINGLE_ARG(secondDone_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_sortchare::run_2_closure : public SDAG::Closure {
      

      run_2_closure() {
        init();
      }
      run_2_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~run_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(run_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_sortchare::receiveValue_3_closure : public SDAG::Closure {
            int idx;
            double value;
            CkFuture future;


      receiveValue_3_closure() {
        init();
      }
      receiveValue_3_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return idx;}
            double & getP1() { return value;}
            CkFuture & getP2() { return future;}
      void pup(PUP::er& __p) {
        __p | idx;
        __p | value;
        __p | future;
        packClosure(__p);
      }
      virtual ~receiveValue_3_closure() {
      }
      PUPable_decl(SINGLE_ARG(receiveValue_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_sortchare::print_startmynum_4_closure : public SDAG::Closure {
      

      print_startmynum_4_closure() {
        init();
      }
      print_startmynum_4_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~print_startmynum_4_closure() {
      }
      PUPable_decl(SINGLE_ARG(print_startmynum_4_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_sortchare::print_endmynum_5_closure : public SDAG::Closure {
      

      print_endmynum_5_closure() {
        init();
      }
      print_endmynum_5_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~print_endmynum_5_closure() {
      }
      PUPable_decl(SINGLE_ARG(print_endmynum_5_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: readonly CProxy_Main mainProxy;
 */
extern CProxy_Main mainProxy;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_mainProxy(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|mainProxy;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int numElements;
 */
extern int numElements;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_numElements(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|numElements;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: message MsgData;
 */
#ifndef CK_TEMPLATES_ONLY
void *CMessage_MsgData::operator new(size_t s){
  return MsgData::alloc(__idx, s, 0, 0, GroupDepNum{});
}
void *CMessage_MsgData::operator new(size_t s, int* sz){
  return MsgData::alloc(__idx, s, sz, 0, GroupDepNum{});
}
void *CMessage_MsgData::operator new(size_t s, int* sz,const int pb){
  return MsgData::alloc(__idx, s, sz, pb, GroupDepNum{});
}
void *CMessage_MsgData::operator new(size_t s, int* sz,const int pb, const GroupDepNum groupDepNum){
  return MsgData::alloc(__idx, s, sz, pb, groupDepNum);
}
void *CMessage_MsgData::operator new(size_t s, const int p) {
  return MsgData::alloc(__idx, s, 0, p, GroupDepNum{});
}
void *CMessage_MsgData::operator new(size_t s, const int p, const GroupDepNum groupDepNum) {
  return MsgData::alloc(__idx, s, 0, p, groupDepNum);
}
void* CMessage_MsgData::alloc(int msgnum, size_t sz, int *sizes, int pb, GroupDepNum groupDepNum) {
  CkpvAccess(_offsets)[0] = ALIGN_DEFAULT(sz);
  return CkAllocMsg(msgnum, CkpvAccess(_offsets)[0], pb, groupDepNum);
}
CMessage_MsgData::CMessage_MsgData() {
MsgData *newmsg = (MsgData *)this;
}
void CMessage_MsgData::dealloc(void *p) {
  CkFreeMsg(p);
}
void* CMessage_MsgData::pack(MsgData *msg) {
  return (void *) msg;
}
MsgData* CMessage_MsgData::unpack(void* buf) {
  MsgData *msg = (MsgData *) buf;
  return msg;
}
int CMessage_MsgData::__idx=0;
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void done();
void secondDone();
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Main::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Main(CkArgMsg* impl_msg);
 */
CkChareID CProxy_Main::ckNew(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}
void CProxy_Main::ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int impl_onPE)
{
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, pcid, impl_onPE);
}

// Entry point registration function
int CkIndex_Main::reg_Main_CkArgMsg() {
  int epidx = CkRegisterEp("Main(CkArgMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_Main_CkArgMsg), CMessage_CkArgMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkArgMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Main::_call_Main_CkArgMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  new (impl_obj_void) Main((CkArgMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void done();
 */
void CProxy_Main::done(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_done_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_done_void(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_done_void(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_done_void() {
  int epidx = CkRegisterEp("done()",
      reinterpret_cast<CkCallFnPtr>(_call_done_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_Main::_call_done_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->done();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
PUPable_def(SINGLE_ARG(Closure_Main::done_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void secondDone();
 */
void CProxy_Main::secondDone(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_secondDone_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_secondDone_void(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_secondDone_void(), impl_msg, &ckGetChareID(),0);
  }
}
void CkIndex_Main::_call_redn_wrapper_secondDone_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  impl_obj->secondDone();
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function
int CkIndex_Main::reg_secondDone_void() {
  int epidx = CkRegisterEp("secondDone()",
      reinterpret_cast<CkCallFnPtr>(_call_secondDone_void), 0, __idx, 0);
  return epidx;
}


// Redn wrapper registration function
int CkIndex_Main::reg_redn_wrapper_secondDone_void() {
  return CkRegisterEp("redn_wrapper_secondDone(CkReductionMsg *impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_redn_wrapper_secondDone_void), CMessage_CkReductionMsg::__idx, __idx, 0);
}

void CkIndex_Main::_call_secondDone_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->secondDone();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
PUPable_def(SINGLE_ARG(Closure_Main::secondDone_3_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Main::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Main(CkArgMsg* impl_msg);
  idx_Main_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Main_CkArgMsg());

  // REG: void done();
  idx_done_void();

  // REG: void secondDone();
  idx_secondDone_void();
  idx_redn_wrapper_secondDone_void();

}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: array sortchare: ArrayElement{
sortchare();
threaded void run();
void receiveValue(int idx, double value, const CkFuture &future);
void print_startmynum();
void print_endmynum();
sortchare(CkMigrateMessage* impl_msg);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_sortchare::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CProxySection_sortchare::contribute(CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(sid, userData, fragSize);
}

void CProxySection_sortchare::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, userData, fragSize);
}

template <typename T>
void CProxySection_sortchare::contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(data, type, sid, userData, fragSize);
}

void CProxySection_sortchare::contribute(CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(sid, cb, userData, fragSize);
}

void CProxySection_sortchare::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, cb, userData, fragSize);
}

template <typename T>
void CProxySection_sortchare::contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(data, type, sid, cb, userData, fragSize);
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: sortchare();
 */
void CProxyElement_sortchare::insert(int onPE, const CkEntryOptions *impl_e_opts)
{ 
   void *impl_msg = CkAllocSysMsg(impl_e_opts);
   UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_sortchare::idx_sortchare_void(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: threaded void run();
 */
void CProxyElement_sortchare::run(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_sortchare::idx_run_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void receiveValue(int idx, double value, const CkFuture &future);
 */
void CProxyElement_sortchare::receiveValue(int idx, double value, const CkFuture &future, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int idx, double value, const CkFuture &future
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|idx;
    implP|value;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<CkFuture>::type>::type &)future;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|idx;
    implP|value;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<CkFuture>::type>::type &)future;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_sortchare::idx_receiveValue_marshall3(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void print_startmynum();
 */
void CProxyElement_sortchare::print_startmynum(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_sortchare::idx_print_startmynum_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void print_endmynum();
 */
void CProxyElement_sortchare::print_endmynum(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_sortchare::idx_print_endmynum_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: sortchare(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: sortchare();
 */
CkArrayID CProxy_sortchare::ckNew(const CkArrayOptions &opts, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_sortchare::idx_sortchare_void(), opts);
  return gId;
}
void CProxy_sortchare::ckNew(const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_sortchare::idx_sortchare_void(), _ck_array_creation_cb, opts, impl_msg);
}
CkArrayID CProxy_sortchare::ckNew(const int s1, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_sortchare::idx_sortchare_void(), opts);
  return gId;
}
void CProxy_sortchare::ckNew(const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_sortchare::idx_sortchare_void(), _ck_array_creation_cb, opts, impl_msg);
}

// Entry point registration function
int CkIndex_sortchare::reg_sortchare_void() {
  int epidx = CkRegisterEp("sortchare()",
      reinterpret_cast<CkCallFnPtr>(_call_sortchare_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_sortchare::_call_sortchare_void(void* impl_msg, void* impl_obj_void)
{
  sortchare* impl_obj = static_cast<sortchare*>(impl_obj_void);
  new (impl_obj_void) sortchare();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: threaded void run();
 */
void CProxy_sortchare::run(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_sortchare::idx_run_void(),0);
}

// Entry point registration function
int CkIndex_sortchare::reg_run_void() {
  int epidx = CkRegisterEp("run()",
      reinterpret_cast<CkCallFnPtr>(_call_run_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_sortchare::_call_run_void(void* impl_msg, void* impl_obj_void)
{
  sortchare* impl_obj = static_cast<sortchare*>(impl_obj_void);
  CthThread tid = CthCreate((CthVoidFn)_callthr_run_void, new CkThrCallArg(impl_msg,impl_obj), 0);
  ((Chare *)impl_obj)->CkAddThreadListeners(tid,impl_msg);
  CthTraceResume(tid);
  CthResume(tid);
}
void CkIndex_sortchare::_callthr_run_void(CkThrCallArg *impl_arg)
{
  void *impl_msg = impl_arg->msg;
  void *impl_obj_void = impl_arg->obj;
  sortchare *impl_obj = static_cast<sortchare *>(impl_obj_void);
  delete impl_arg;
  impl_obj->run();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
PUPable_def(SINGLE_ARG(Closure_sortchare::run_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void receiveValue(int idx, double value, const CkFuture &future);
 */
void CProxy_sortchare::receiveValue(int idx, double value, const CkFuture &future, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int idx, double value, const CkFuture &future
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|idx;
    implP|value;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<CkFuture>::type>::type &)future;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|idx;
    implP|value;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<CkFuture>::type>::type &)future;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_sortchare::idx_receiveValue_marshall3(),0);
}

// Entry point registration function
int CkIndex_sortchare::reg_receiveValue_marshall3() {
  int epidx = CkRegisterEp("receiveValue(int idx, double value, const CkFuture &future)",
      reinterpret_cast<CkCallFnPtr>(_call_receiveValue_marshall3), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_receiveValue_marshall3);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_receiveValue_marshall3);

  return epidx;
}

void CkIndex_sortchare::_call_receiveValue_marshall3(void* impl_msg, void* impl_obj_void)
{
  sortchare* impl_obj = static_cast<sortchare*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int idx, double value, const CkFuture &future*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> idx;
  implP|idx;
  PUP::detail::TemporaryObjectHolder<double> value;
  implP|value;
  PUP::detail::TemporaryObjectHolder<CkFuture> future;
  implP|future;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->receiveValue(std::move(idx.t), std::move(value.t), std::move(future.t));
}
int CkIndex_sortchare::_callmarshall_receiveValue_marshall3(char* impl_buf, void* impl_obj_void) {
  sortchare* impl_obj = static_cast<sortchare*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: int idx, double value, const CkFuture &future*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> idx;
  implP|idx;
  PUP::detail::TemporaryObjectHolder<double> value;
  implP|value;
  PUP::detail::TemporaryObjectHolder<CkFuture> future;
  implP|future;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->receiveValue(std::move(idx.t), std::move(value.t), std::move(future.t));
  return implP.size();
}
void CkIndex_sortchare::_marshallmessagepup_receiveValue_marshall3(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int idx, double value, const CkFuture &future*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> idx;
  implP|idx;
  PUP::detail::TemporaryObjectHolder<double> value;
  implP|value;
  PUP::detail::TemporaryObjectHolder<CkFuture> future;
  implP|future;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("idx");
  implDestP|idx;
  if (implDestP.hasComments()) implDestP.comment("value");
  implDestP|value;
  if (implDestP.hasComments()) implDestP.comment("future");
  implDestP|future;
}
PUPable_def(SINGLE_ARG(Closure_sortchare::receiveValue_3_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void print_startmynum();
 */
void CProxy_sortchare::print_startmynum(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_sortchare::idx_print_startmynum_void(),0);
}

// Entry point registration function
int CkIndex_sortchare::reg_print_startmynum_void() {
  int epidx = CkRegisterEp("print_startmynum()",
      reinterpret_cast<CkCallFnPtr>(_call_print_startmynum_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_sortchare::_call_print_startmynum_void(void* impl_msg, void* impl_obj_void)
{
  sortchare* impl_obj = static_cast<sortchare*>(impl_obj_void);
  impl_obj->print_startmynum();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
PUPable_def(SINGLE_ARG(Closure_sortchare::print_startmynum_4_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void print_endmynum();
 */
void CProxy_sortchare::print_endmynum(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_sortchare::idx_print_endmynum_void(),0);
}

// Entry point registration function
int CkIndex_sortchare::reg_print_endmynum_void() {
  int epidx = CkRegisterEp("print_endmynum()",
      reinterpret_cast<CkCallFnPtr>(_call_print_endmynum_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_sortchare::_call_print_endmynum_void(void* impl_msg, void* impl_obj_void)
{
  sortchare* impl_obj = static_cast<sortchare*>(impl_obj_void);
  impl_obj->print_endmynum();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
PUPable_def(SINGLE_ARG(Closure_sortchare::print_endmynum_5_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: sortchare(CkMigrateMessage* impl_msg);
 */

// Entry point registration function
int CkIndex_sortchare::reg_sortchare_CkMigrateMessage() {
  int epidx = CkRegisterEp("sortchare(CkMigrateMessage* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_sortchare_CkMigrateMessage), 0, __idx, 0);
  return epidx;
}

void CkIndex_sortchare::_call_sortchare_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  call_migration_constructor<sortchare> c = impl_obj_void;
  c((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: sortchare();
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: threaded void run();
 */
void CProxySection_sortchare::run(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_sortchare::idx_run_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void receiveValue(int idx, double value, const CkFuture &future);
 */
void CProxySection_sortchare::receiveValue(int idx, double value, const CkFuture &future, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int idx, double value, const CkFuture &future
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|idx;
    implP|value;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<CkFuture>::type>::type &)future;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|idx;
    implP|value;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<CkFuture>::type>::type &)future;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_sortchare::idx_receiveValue_marshall3(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void print_startmynum();
 */
void CProxySection_sortchare::print_startmynum(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_sortchare::idx_print_startmynum_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void print_endmynum();
 */
void CProxySection_sortchare::print_endmynum(const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_sortchare::idx_print_endmynum_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: sortchare(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_sortchare::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterArrayDimensions(__idx, 1);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: sortchare();
  idx_sortchare_void();
  CkRegisterDefaultCtor(__idx, idx_sortchare_void());

  // REG: threaded void run();
  idx_run_void();

  // REG: void receiveValue(int idx, double value, const CkFuture &future);
  idx_receiveValue_marshall3();

  // REG: void print_startmynum();
  idx_print_startmynum_void();

  // REG: void print_endmynum();
  idx_print_endmynum_void();

  // REG: sortchare(CkMigrateMessage* impl_msg);
  idx_sortchare_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_sortchare_CkMigrateMessage());

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registeroddeven(void)
{
  static int _done = 0; if(_done) return; _done = 1;
  CkRegisterReadonly("mainProxy","CProxy_Main",sizeof(mainProxy),(void *) &mainProxy,__xlater_roPup_mainProxy);

  CkRegisterReadonly("numElements","int",sizeof(numElements),(void *) &numElements,__xlater_roPup_numElements);

/* REG: message MsgData;
*/
CMessage_MsgData::__register("MsgData", sizeof(MsgData),(CkPackFnPtr) MsgData::pack,(CkUnpackFnPtr) MsgData::unpack);

/* REG: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void done();
void secondDone();
};
*/
  CkIndex_Main::__register("Main", sizeof(Main));

/* REG: array sortchare: ArrayElement{
sortchare();
threaded void run();
void receiveValue(int idx, double value, const CkFuture &future);
void print_startmynum();
void print_endmynum();
sortchare(CkMigrateMessage* impl_msg);
};
*/
  CkIndex_sortchare::__register("sortchare", sizeof(sortchare));

}
extern "C" void CkRegisterMainModule(void) {
  _registeroddeven();
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Main::virtual_pup(PUP::er &p) {
    recursive_pup<Main>(dynamic_cast<Main*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_sortchare::virtual_pup(PUP::er &p) {
    recursive_pup<sortchare>(dynamic_cast<sortchare*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
