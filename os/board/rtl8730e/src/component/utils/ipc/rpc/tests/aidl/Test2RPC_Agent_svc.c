/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <Test2RPC_Agent.h>
#include <string.h>
#include <rpc_server.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <RPCBaseDS.h>
#include <Test2RPCBaseDS.h>

static void
TEST2_AGENT_0(RPC_STRUCT *rpc, int32_t opt, RPC_Mutex *pMutex, char *buf)
{
	union {
		TEST2_RPC_STREAMING_RESULT TEST2_RPC_ToSystem_Streaming_Callback_0_arg;
		TEST2_RPC_RECOGNIZER_RESULT TEST2_RPC_ToSystem_Recognizer_Callback_0_arg;
		TEST2_RPC_ERROR_STATE TEST2_RPC_ToSystem_Error_0_arg;
	} argument;

	union {
		HRESULT TEST2_RPC_ToSystem_Streaming_Callback_0_ret;
		HRESULT TEST2_RPC_ToSystem_Recognizer_Callback_0_ret;
		HRESULT TEST2_RPC_ToSystem_Error_0_ret;
	} retval;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct RPC_STRUCT *, char *);
	int ReplyParaSize;


	switch (rpc->procedure_id) {
	case TEST2_RPC_ToSystem_Streaming_Callback:
		_xdr_argument = (xdrproc_t) xdr_TEST2_RPC_STREAMING_RESULT;
		_xdr_result = (xdrproc_t) xdr_HRESULT;
		ReplyParaSize = sizeof(HRESULT);
		local = (char *(*)(char *, struct RPC_STRUCT *, char *)) TEST2_RPC_ToSystem_Streaming_Callback_0_svc;
		break;

	case TEST2_RPC_ToSystem_Recognizer_Callback:
		_xdr_argument = (xdrproc_t) xdr_TEST2_RPC_RECOGNIZER_RESULT;
		_xdr_result = (xdrproc_t) xdr_HRESULT;
		ReplyParaSize = sizeof(HRESULT);
		local = (char *(*)(char *, struct RPC_STRUCT *, char *)) TEST2_RPC_ToSystem_Recognizer_Callback_0_svc;
		break;

	case TEST2_RPC_ToSystem_Error:
		_xdr_argument = (xdrproc_t) xdr_TEST2_RPC_ERROR_STATE;
		_xdr_result = (xdrproc_t) xdr_HRESULT;
		ReplyParaSize = sizeof(HRESULT);
		local = (char *(*)(char *, struct RPC_STRUCT *, char *)) TEST2_RPC_ToSystem_Error_0_svc;
		break;

	default:
		return;
	}


	memset((char *)&argument, 0, sizeof(argument));


	if (!RPC_GetArgs(rpc, (xdrproc_t) _xdr_argument, (caddr_t) &argument, opt, buf)) {
		printf("get args error\n");
		RPC_MutexUnlock(pMutex);
		return;
	}

	RPC_MutexUnlock(pMutex);

	(*local)((char *)&argument, rpc, (char *)&retval);


	// When source msg is BLOCK_MODE,
	// we must help it reply
	// ps: reply mode is NON_BLOCK and use request's ringbuf type
	if (rpc->task_id != 0) {
		RPC_SendReply(rpc->task_id, rpc->context, (char *)&retval, ReplyParaSize,
					  (xdrproc_t) _xdr_result, opt);
	}

	return;
}
HRESULT   *(*p_TEST2_RPC_ToSystem_Streaming_Callback_0_svc)(TEST2_RPC_STREAMING_RESULT *pParam, RPC_STRUCT *pRpcStruct, HRESULT *pRes) = 0;

HRESULT *TEST2_RPC_ToSystem_Streaming_Callback_0_svc(TEST2_RPC_STREAMING_RESULT *pParam, RPC_STRUCT *pRpcStruct, HRESULT *pRes)
{
	if (p_TEST2_RPC_ToSystem_Streaming_Callback_0_svc) {
		p_TEST2_RPC_ToSystem_Streaming_Callback_0_svc(pParam, pRpcStruct, pRes);
		return pRes;
	} else {
		return pRes;
	}
}

HRESULT   *(*p_TEST2_RPC_ToSystem_Recognizer_Callback_0_svc)(TEST2_RPC_RECOGNIZER_RESULT *pParam, RPC_STRUCT *pRpcStruct, HRESULT *pRes) = 0;

HRESULT *TEST2_RPC_ToSystem_Recognizer_Callback_0_svc(TEST2_RPC_RECOGNIZER_RESULT *pParam, RPC_STRUCT *pRpcStruct, HRESULT *pRes)
{
	if (p_TEST2_RPC_ToSystem_Recognizer_Callback_0_svc) {
		p_TEST2_RPC_ToSystem_Recognizer_Callback_0_svc(pParam, pRpcStruct, pRes);
		return pRes;
	} else {
		return pRes;
	}
}

HRESULT   *(*p_TEST2_RPC_ToSystem_Error_0_svc)(TEST2_RPC_ERROR_STATE *pParam, RPC_STRUCT *pRpcStruct, HRESULT *pRes) = 0;

HRESULT *TEST2_RPC_ToSystem_Error_0_svc(TEST2_RPC_ERROR_STATE *pParam, RPC_STRUCT *pRpcStruct, HRESULT *pRes)
{
	if (p_TEST2_RPC_ToSystem_Error_0_svc) {
		p_TEST2_RPC_ToSystem_Error_0_svc(pParam, pRpcStruct, pRes);
		return pRes;
	} else {
		return pRes;
	}
}



struct REG_STRUCT *TEST2_AGENT_0_register(struct REG_STRUCT *rnode)
{

	REG_STRUCT *pReg = (struct REG_STRUCT *)RPC_Register(rnode, TEST2_AGENT, 0,
					   (void (*)(struct RPC_STRUCT *, int32_t, RPC_Mutex *, char *))TEST2_AGENT_0);
	return pReg;
}