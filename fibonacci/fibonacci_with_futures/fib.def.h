
/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::run_2_closure : public SDAG::Closure {
            int n;


      run_2_closure() {
        init();
      }
      run_2_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return n;}
      void pup(PUP::er& __p) {
        __p | n;
        packClosure(__p);
      }
      virtual ~run_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(run_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Fib::run_2_closure : public SDAG::Closure {
            int n;
            CkFuture f;


      run_2_closure() {
        init();
      }
      run_2_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return n;}
            CkFuture & getP1() { return f;}
      void pup(PUP::er& __p) {
        __p | n;
        __p | f;
        packClosure(__p);
      }
      virtual ~run_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(run_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: message ValueMsg;
 */
#ifndef CK_TEMPLATES_ONLY
void *CMessage_ValueMsg::operator new(size_t s){
  return ValueMsg::alloc(__idx, s, 0, 0, GroupDepNum{});
}
void *CMessage_ValueMsg::operator new(size_t s, int* sz){
  return ValueMsg::alloc(__idx, s, sz, 0, GroupDepNum{});
}
void *CMessage_ValueMsg::operator new(size_t s, int* sz,const int pb){
  return ValueMsg::alloc(__idx, s, sz, pb, GroupDepNum{});
}
void *CMessage_ValueMsg::operator new(size_t s, int* sz,const int pb, const GroupDepNum groupDepNum){
  return ValueMsg::alloc(__idx, s, sz, pb, groupDepNum);
}
void *CMessage_ValueMsg::operator new(size_t s, const int p) {
  return ValueMsg::alloc(__idx, s, 0, p, GroupDepNum{});
}
void *CMessage_ValueMsg::operator new(size_t s, const int p, const GroupDepNum groupDepNum) {
  return ValueMsg::alloc(__idx, s, 0, p, groupDepNum);
}
void* CMessage_ValueMsg::alloc(int msgnum, size_t sz, int *sizes, int pb, GroupDepNum groupDepNum) {
  CkpvAccess(_offsets)[0] = ALIGN_DEFAULT(sz);
  return CkAllocMsg(msgnum, CkpvAccess(_offsets)[0], pb, groupDepNum);
}
CMessage_ValueMsg::CMessage_ValueMsg() {
ValueMsg *newmsg = (ValueMsg *)this;
}
void CMessage_ValueMsg::dealloc(void *p) {
  CkFreeMsg(p);
}
void* CMessage_ValueMsg::pack(ValueMsg *msg) {
  return (void *) msg;
}
ValueMsg* CMessage_ValueMsg::unpack(void* buf) {
  ValueMsg *msg = (ValueMsg *) buf;
  return msg;
}
int CMessage_ValueMsg::__idx=0;
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void run(int n);
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
/* DEFS: void run(int n);
 */
void CProxy_Main::run(int n, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int n
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|n;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|n;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_run_marshall2(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_run_marshall2(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_run_marshall2(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_run_marshall2() {
  int epidx = CkRegisterEp("run(int n)",
      reinterpret_cast<CkCallFnPtr>(_call_run_marshall2), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_run_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_run_marshall2);

  return epidx;
}

void CkIndex_Main::_call_run_marshall2(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int n*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> n;
  implP|n;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->run(std::move(n.t));
}
int CkIndex_Main::_callmarshall_run_marshall2(char* impl_buf, void* impl_obj_void) {
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: int n*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> n;
  implP|n;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->run(std::move(n.t));
  return implP.size();
}
void CkIndex_Main::_marshallmessagepup_run_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int n*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> n;
  implP|n;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("n");
  implDestP|n;
}
PUPable_def(SINGLE_ARG(Closure_Main::run_2_closure))
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

  // REG: void run(int n);
  idx_run_marshall2();

}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: chare Fib: Chare{
Fib(int n, const CkFuture &f);
void run(int n, const CkFuture &f);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Fib::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Fib(int n, const CkFuture &f);
 */
CkChareID CProxy_Fib::ckNew(int n, const CkFuture &f, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int n, const CkFuture &f
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|n;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<CkFuture>::type>::type &)f;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|n;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<CkFuture>::type>::type &)f;
  }
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Fib::__idx, CkIndex_Fib::idx_Fib_marshall1(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}
void CProxy_Fib::ckNew(int n, const CkFuture &f, CkChareID* pcid, int impl_onPE, const CkEntryOptions *impl_e_opts)
{
  //Marshall: int n, const CkFuture &f
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|n;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<CkFuture>::type>::type &)f;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|n;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<CkFuture>::type>::type &)f;
  }
  CkCreateChare(CkIndex_Fib::__idx, CkIndex_Fib::idx_Fib_marshall1(), impl_msg, pcid, impl_onPE);
}

// Entry point registration function
int CkIndex_Fib::reg_Fib_marshall1() {
  int epidx = CkRegisterEp("Fib(int n, const CkFuture &f)",
      reinterpret_cast<CkCallFnPtr>(_call_Fib_marshall1), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_Fib_marshall1);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_Fib_marshall1);

  return epidx;
}

void CkIndex_Fib::_call_Fib_marshall1(void* impl_msg, void* impl_obj_void)
{
  Fib* impl_obj = static_cast<Fib*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int n, const CkFuture &f*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> n;
  implP|n;
  PUP::detail::TemporaryObjectHolder<CkFuture> f;
  implP|f;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj_void) Fib(std::move(n.t), std::move(f.t));
}
int CkIndex_Fib::_callmarshall_Fib_marshall1(char* impl_buf, void* impl_obj_void) {
  Fib* impl_obj = static_cast<Fib*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: int n, const CkFuture &f*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> n;
  implP|n;
  PUP::detail::TemporaryObjectHolder<CkFuture> f;
  implP|f;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj_void) Fib(std::move(n.t), std::move(f.t));
  return implP.size();
}
void CkIndex_Fib::_marshallmessagepup_Fib_marshall1(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int n, const CkFuture &f*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> n;
  implP|n;
  PUP::detail::TemporaryObjectHolder<CkFuture> f;
  implP|f;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("n");
  implDestP|n;
  if (implDestP.hasComments()) implDestP.comment("f");
  implDestP|f;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void run(int n, const CkFuture &f);
 */
void CProxy_Fib::run(int n, const CkFuture &f, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int n, const CkFuture &f
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|n;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<CkFuture>::type>::type &)f;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|n;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<CkFuture>::type>::type &)f;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Fib::idx_run_marshall2(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Fib::idx_run_marshall2(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Fib::idx_run_marshall2(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Fib::reg_run_marshall2() {
  int epidx = CkRegisterEp("run(int n, const CkFuture &f)",
      reinterpret_cast<CkCallFnPtr>(_call_run_marshall2), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_run_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_run_marshall2);

  return epidx;
}

void CkIndex_Fib::_call_run_marshall2(void* impl_msg, void* impl_obj_void)
{
  Fib* impl_obj = static_cast<Fib*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int n, const CkFuture &f*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> n;
  implP|n;
  PUP::detail::TemporaryObjectHolder<CkFuture> f;
  implP|f;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->run(std::move(n.t), std::move(f.t));
}
int CkIndex_Fib::_callmarshall_run_marshall2(char* impl_buf, void* impl_obj_void) {
  Fib* impl_obj = static_cast<Fib*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: int n, const CkFuture &f*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> n;
  implP|n;
  PUP::detail::TemporaryObjectHolder<CkFuture> f;
  implP|f;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->run(std::move(n.t), std::move(f.t));
  return implP.size();
}
void CkIndex_Fib::_marshallmessagepup_run_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int n, const CkFuture &f*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> n;
  implP|n;
  PUP::detail::TemporaryObjectHolder<CkFuture> f;
  implP|f;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("n");
  implDestP|n;
  if (implDestP.hasComments()) implDestP.comment("f");
  implDestP|f;
}
PUPable_def(SINGLE_ARG(Closure_Fib::run_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Fib::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Fib(int n, const CkFuture &f);
  idx_Fib_marshall1();

  // REG: void run(int n, const CkFuture &f);
  idx_run_marshall2();

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registerfib(void)
{
  static int _done = 0; if(_done) return; _done = 1;
/* REG: message ValueMsg;
*/
CMessage_ValueMsg::__register("ValueMsg", sizeof(ValueMsg),(CkPackFnPtr) ValueMsg::pack,(CkUnpackFnPtr) ValueMsg::unpack);

/* REG: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void run(int n);
};
*/
  CkIndex_Main::__register("Main", sizeof(Main));

/* REG: chare Fib: Chare{
Fib(int n, const CkFuture &f);
void run(int n, const CkFuture &f);
};
*/
  CkIndex_Fib::__register("Fib", sizeof(Fib));

}
extern "C" void CkRegisterMainModule(void) {
  _registerfib();
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
void CBase_Fib::virtual_pup(PUP::er &p) {
    recursive_pup<Fib>(dynamic_cast<Fib*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
