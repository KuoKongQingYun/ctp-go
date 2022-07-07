#include <iostream>
#include "ThostFtdcMdApi.h"
#include "ThostFtdcTraderApi.h"
#include "wrap.h"
// =================== ����ӿ� ===================

CThostFtdcMdApi* CThostFtdcMdApi_CreateFtdcMdApi(const char* pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast) {
	return CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath, bIsUsingUdp, bIsMulticast);
}

///��ȡAPI�İ汾��Ϣ
///@retrun ��ȡ���İ汾��
const char* CThostFtdcMdApi_GetApiVersion() {
	return CThostFtdcMdApi::GetApiVersion();
}

///ɾ���ӿڶ�����
///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
void CThostFtdcMdApi_Release(CThostFtdcMdApi* pCThostFtdcMdApi) {
	pCThostFtdcMdApi->Release();
}

///��ʼ��
///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
void CThostFtdcMdApi_Init(CThostFtdcMdApi* pCThostFtdcMdApi) {
	pCThostFtdcMdApi->Init();
}

///�ȴ��ӿ��߳̽�������
///@return �߳��˳�����
int CThostFtdcMdApi_Join(CThostFtdcMdApi* pCThostFtdcMdApi) {
	return pCThostFtdcMdApi->Join();
}

///��ȡ��ǰ������
///@retrun ��ȡ���Ľ�����
///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
const char* CThostFtdcMdApi_GetTradingDay(CThostFtdcMdApi* pCThostFtdcMdApi) {
	return pCThostFtdcMdApi->GetTradingDay();
}

///ע��ǰ�û������ַ
///@param pszFrontAddress��ǰ�û������ַ��
///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
void CThostFtdcMdApi_RegisterFront(CThostFtdcMdApi* pCThostFtdcMdApi, char* pszFrontAddress) {
	return pCThostFtdcMdApi->RegisterFront(pszFrontAddress);
}

///ע�����ַ����������ַ
///@param pszNsAddress�����ַ����������ַ��
///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:12001���� 
///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����12001������������˿ںš�
///@remark RegisterNameServer������RegisterFront
void CThostFtdcMdApi_RegisterNameServer(CThostFtdcMdApi* pCThostFtdcMdApi, char* pszNsAddress) {
	return pCThostFtdcMdApi->RegisterNameServer(pszNsAddress);
}

///ע�����ַ������û���Ϣ
///@param pFensUserInfo���û���Ϣ��
void CThostFtdcMdApi_RegisterFensUserInfo(CThostFtdcMdApi* pCThostFtdcMdApi, CThostFtdcFensUserInfoField* pFensUserInfo) {
	return pCThostFtdcMdApi->RegisterFensUserInfo(pFensUserInfo);
}

///ע��ص��ӿ�
///@param pSpi �����Իص��ӿ����ʵ��
void CThostFtdcMdApi_RegisterSpi(CThostFtdcMdApi* pCThostFtdcMdApi, CThostFtdcMdSpi* pSpi) {
	return pCThostFtdcMdApi->RegisterSpi(pSpi);
}

///�������顣
///@param ppInstrumentID ��ԼID  
///@param nCount Ҫ����/�˶�����ĺ�Լ����
///@remark 
int CThostFtdcMdApi_SubscribeMarketData(CThostFtdcMdApi* pCThostFtdcMdApi, char** ppInstrumentID, int nCount) {
	return pCThostFtdcMdApi->SubscribeMarketData(ppInstrumentID, nCount);
}

///�˶����顣
///@param ppInstrumentID ��ԼID  
///@param nCount Ҫ����/�˶�����ĺ�Լ����
///@remark 
int CThostFtdcMdApi_UnSubscribeMarketData(CThostFtdcMdApi* pCThostFtdcMdApi, char** ppInstrumentID, int nCount) {
	return pCThostFtdcMdApi->UnSubscribeMarketData(ppInstrumentID, nCount);
}

///����ѯ�ۡ�
///@param ppInstrumentID ��ԼID  
///@param nCount Ҫ����/�˶�����ĺ�Լ����
///@remark 
int CThostFtdcMdApi_SubscribeForQuoteRsp(CThostFtdcMdApi* pCThostFtdcMdApi, char** ppInstrumentID, int nCount) {
	return pCThostFtdcMdApi->SubscribeForQuoteRsp(ppInstrumentID, nCount);
}

///�˶�ѯ�ۡ�
///@param ppInstrumentID ��ԼID  
///@param nCount Ҫ����/�˶�����ĺ�Լ����
///@remark 
int CThostFtdcMdApi_UnSubscribeForQuoteRsp(CThostFtdcMdApi* pCThostFtdcMdApi, char** ppInstrumentID, int nCount) {
	return pCThostFtdcMdApi->UnSubscribeForQuoteRsp(ppInstrumentID, nCount);
}

///�û���¼����
int CThostFtdcMdApi_ReqUserLogin(CThostFtdcMdApi* pCThostFtdcMdApi, CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID) {
	return pCThostFtdcMdApi->ReqUserLogin(pReqUserLoginField, nRequestID);
}

///�ǳ�����
int CThostFtdcMdApi_ReqUserLogout(CThostFtdcMdApi* pCThostFtdcMdApi, CThostFtdcUserLogoutField* pUserLogout, int nRequestID) {
	return pCThostFtdcMdApi->ReqUserLogout(pUserLogout, nRequestID);
}

///�����ѯ�鲥��Լ
int CThostFtdcMdApi_ReqQryMulticastInstrument(CThostFtdcMdApi* pCThostFtdcMdApi, CThostFtdcQryMulticastInstrumentField* pQryMulticastInstrument, int nRequestID) {
	return pCThostFtdcMdApi->ReqQryMulticastInstrument(pQryMulticastInstrument, nRequestID);
}


// =================== ���׽ӿ� ======================

///����TraderApi
///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
///@return ��������UserApi
extern "C" CTP_API_EXPORT CThostFtdcTraderApi * CThostFtdcTraderApi_CreateFtdcTraderApi(const char* pszFlowPath) {
	return CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath);
}

///��ȡAPI�İ汾��Ϣ
///@retrun ��ȡ���İ汾��
extern "C" CTP_API_EXPORT const char* CThostFtdcTraderApi_GetApiVersion() {
	return CThostFtdcTraderApi::GetApiVersion();
}

///ɾ���ӿڶ�����
///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
extern "C" CTP_API_EXPORT void CThostFtdcTraderApi_Release(CThostFtdcTraderApi * pCThostFtdcTraderApi) {
	return pCThostFtdcTraderApi->Release();
}

///��ʼ��
///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
extern "C" CTP_API_EXPORT void CThostFtdcTraderApi_Init(CThostFtdcTraderApi * pCThostFtdcTraderApi) {
	return pCThostFtdcTraderApi->Init();
}

///�ȴ��ӿ��߳̽�������
///@return �߳��˳�����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_Join(CThostFtdcTraderApi * pCThostFtdcTraderApi) {
	return pCThostFtdcTraderApi->Join();
}
///��ȡ��ǰ������
///@retrun ��ȡ���Ľ�����
///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
extern "C" CTP_API_EXPORT const char* CThostFtdcTraderApi_GetTradingDay(CThostFtdcTraderApi * pCThostFtdcTraderApi) {
	return pCThostFtdcTraderApi->GetTradingDay();
}

///ע��ǰ�û������ַ
///@param pszFrontAddress��ǰ�û������ַ��
///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
extern "C" CTP_API_EXPORT void CThostFtdcTraderApi_RegisterFront(CThostFtdcTraderApi * pCThostFtdcTraderApi, char* pszFrontAddress) {
	return pCThostFtdcTraderApi->RegisterFront(pszFrontAddress);
}

///ע�����ַ����������ַ
///@param pszNsAddress�����ַ����������ַ��
///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:12001���� 
///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����12001������������˿ںš�
///@remark RegisterNameServer������RegisterFront
extern "C" CTP_API_EXPORT void CThostFtdcTraderApi_RegisterNameServer(CThostFtdcTraderApi * pCThostFtdcTraderApi, char* pszNsAddress) {
	return pCThostFtdcTraderApi->RegisterNameServer(pszNsAddress);
}

///ע�����ַ������û���Ϣ
///@param pFensUserInfo���û���Ϣ��
extern "C" CTP_API_EXPORT void CThostFtdcTraderApi_RegisterFensUserInfo(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcFensUserInfoField * pFensUserInfo) {
	return pCThostFtdcTraderApi->RegisterFensUserInfo(pFensUserInfo);
}

///ע��ص��ӿ�
///@param pSpi �����Իص��ӿ����ʵ��
extern "C" CTP_API_EXPORT void CThostFtdcTraderApi_RegisterSpi(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcTraderSpi * pSpi) {
	return pCThostFtdcTraderApi->RegisterSpi(pSpi);
}

///����˽������
///@param nResumeType ˽�����ش���ʽ  
///        THOST_TERT_RESTART:�ӱ������տ�ʼ�ش�
///        THOST_TERT_RESUME:���ϴ��յ�������
///        THOST_TERT_QUICK:ֻ���͵�¼��˽����������
///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
extern "C" CTP_API_EXPORT void CThostFtdcTraderApi_SubscribePrivateTopic(CThostFtdcTraderApi * pCThostFtdcTraderApi, THOST_TE_RESUME_TYPE nResumeType) {
	return pCThostFtdcTraderApi->SubscribePrivateTopic(nResumeType);
}

///���Ĺ�������
///@param nResumeType �������ش���ʽ  
///        THOST_TERT_RESTART:�ӱ������տ�ʼ�ش�
///        THOST_TERT_RESUME:���ϴ��յ�������
///        THOST_TERT_QUICK:ֻ���͵�¼�󹫹���������
///        THOST_TERT_NONE:ȡ�����Ĺ�����
///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ������������ݡ�
extern "C" CTP_API_EXPORT void CThostFtdcTraderApi_SubscribePublicTopic(CThostFtdcTraderApi * pCThostFtdcTraderApi, THOST_TE_RESUME_TYPE nResumeType) {
	return pCThostFtdcTraderApi->SubscribePublicTopic(nResumeType);
}

///�ͻ�����֤����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqAuthenticate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqAuthenticateField * pReqAuthenticateField, int nRequestID) {
	return pCThostFtdcTraderApi->ReqAuthenticate(pReqAuthenticateField, nRequestID);
}

///ע���û��ն���Ϣ�������м̷�����������ģʽ
///��Ҫ���ն���֤�ɹ����û���¼ǰ���øýӿ�
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_RegisterUserSystemInfo(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcUserSystemInfoField * pUserSystemInfo) {
	return pCThostFtdcTraderApi->RegisterUserSystemInfo(pUserSystemInfo);
}

///�ϱ��û��ն���Ϣ�������м̷���������Ա��¼ģʽ
///����Ա��¼�󣬿��Զ�ε��øýӿ��ϱ��ͻ���Ϣ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_SubmitUserSystemInfo(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcUserSystemInfoField * pUserSystemInfo) {
	return pCThostFtdcTraderApi->SubmitUserSystemInfo(pUserSystemInfo);
}

///�û���¼����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqUserLogin(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqUserLoginField * pReqUserLoginField, int nRequestID) {
	return pCThostFtdcTraderApi->ReqUserLogin(pReqUserLoginField, nRequestID);
}

///�ǳ�����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqUserLogout(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcUserLogoutField * pUserLogout, int nRequestID) {
	return pCThostFtdcTraderApi->ReqUserLogout(pUserLogout, nRequestID);
}

///�û������������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqUserPasswordUpdate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcUserPasswordUpdateField * pUserPasswordUpdate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqUserPasswordUpdate(pUserPasswordUpdate, nRequestID);
}

///�ʽ��˻������������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqTradingAccountPasswordUpdate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcTradingAccountPasswordUpdateField * pTradingAccountPasswordUpdate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, nRequestID);
}

///��ѯ�û���ǰ֧�ֵ���֤ģʽ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqUserAuthMethod(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqUserAuthMethodField * pReqUserAuthMethod, int nRequestID) {
	return pCThostFtdcTraderApi->ReqUserAuthMethod(pReqUserAuthMethod, nRequestID);
}

///�û�������ȡͼ����֤������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqGenUserCaptcha(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqGenUserCaptchaField * pReqGenUserCaptcha, int nRequestID) {
	return pCThostFtdcTraderApi->ReqGenUserCaptcha(pReqGenUserCaptcha, nRequestID);
}


///�û�������ȡ������֤������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqGenUserText(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqGenUserTextField * pReqGenUserText, int nRequestID) {
	return pCThostFtdcTraderApi->ReqGenUserText(pReqGenUserText, nRequestID);
}


///�û���������ͼƬ��֤��ĵ�½����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqUserLoginWithCaptcha(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqUserLoginWithCaptchaField * pReqUserLoginWithCaptcha, int nRequestID) {
	return pCThostFtdcTraderApi->ReqUserLoginWithCaptcha(pReqUserLoginWithCaptcha, nRequestID);
}

///�û��������ж�����֤��ĵ�½����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqUserLoginWithText(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqUserLoginWithTextField * pReqUserLoginWithText, int nRequestID) {
	return pCThostFtdcTraderApi->ReqUserLoginWithText(pReqUserLoginWithText, nRequestID);
}

///�û��������ж�̬����ĵ�½����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqUserLoginWithOTP(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqUserLoginWithOTPField * pReqUserLoginWithOTP, int nRequestID) {
	return pCThostFtdcTraderApi->ReqUserLoginWithOTP(pReqUserLoginWithOTP, nRequestID);
}

///����¼������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqOrderInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputOrderField * pInputOrder, int nRequestID) {
	return pCThostFtdcTraderApi->ReqOrderInsert(pInputOrder, nRequestID);
}

///Ԥ��¼������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqParkedOrderInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcParkedOrderField * pParkedOrder, int nRequestID) {
	return pCThostFtdcTraderApi->ReqParkedOrderInsert(pParkedOrder, nRequestID);
}

///Ԥ�񳷵�¼������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqParkedOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcParkedOrderActionField * pParkedOrderAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqParkedOrderAction(pParkedOrderAction, nRequestID);
}

///������������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputOrderActionField * pInputOrderAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqOrderAction(pInputOrderAction, nRequestID);
}

///��ѯ��󱨵���������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryMaxOrderVolume(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryMaxOrderVolumeField * pQryMaxOrderVolume, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryMaxOrderVolume(pQryMaxOrderVolume, nRequestID);
}

///Ͷ���߽�����ȷ��
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqSettlementInfoConfirm(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcSettlementInfoConfirmField * pSettlementInfoConfirm, int nRequestID) {
	return pCThostFtdcTraderApi->ReqSettlementInfoConfirm(pSettlementInfoConfirm, nRequestID);
}

///����ɾ��Ԥ��
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqRemoveParkedOrder(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcRemoveParkedOrderField * pRemoveParkedOrder, int nRequestID) {
	return pCThostFtdcTraderApi->ReqRemoveParkedOrder(pRemoveParkedOrder, nRequestID);
}

///����ɾ��Ԥ�񳷵�
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqRemoveParkedOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcRemoveParkedOrderActionField * pRemoveParkedOrderAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqRemoveParkedOrderAction(pRemoveParkedOrderAction, nRequestID);
}

///ִ������¼������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqExecOrderInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputExecOrderField * pInputExecOrder, int nRequestID) {
	return pCThostFtdcTraderApi->ReqExecOrderInsert(pInputExecOrder, nRequestID);
}

///ִ�������������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqExecOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputExecOrderActionField * pInputExecOrderAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqExecOrderAction(pInputExecOrderAction, nRequestID);
}

///ѯ��¼������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqForQuoteInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputForQuoteField * pInputForQuote, int nRequestID) {
	return pCThostFtdcTraderApi->ReqForQuoteInsert(pInputForQuote, nRequestID);
}

///����¼������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQuoteInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputQuoteField * pInputQuote, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQuoteInsert(pInputQuote, nRequestID);
}

///���۲�������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQuoteAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputQuoteActionField * pInputQuoteAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQuoteAction(pInputQuoteAction, nRequestID);
}

///����������������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqBatchOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputBatchOrderActionField * pInputBatchOrderAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqBatchOrderAction(pInputBatchOrderAction, nRequestID);
}

///��Ȩ�ԶԳ�¼������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqOptionSelfCloseInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputOptionSelfCloseField * pInputOptionSelfClose, int nRequestID) {
	return pCThostFtdcTraderApi->ReqOptionSelfCloseInsert(pInputOptionSelfClose, nRequestID);
}

///��Ȩ�ԶԳ��������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqOptionSelfCloseAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputOptionSelfCloseActionField * pInputOptionSelfCloseAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqOptionSelfCloseAction(pInputOptionSelfCloseAction, nRequestID);
}

///�������¼������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqCombActionInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputCombActionField * pInputCombAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqCombActionInsert(pInputCombAction, nRequestID);
}

///�����ѯ����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryOrder(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryOrderField * pQryOrder, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryOrder(pQryOrder, nRequestID);
}

///�����ѯ�ɽ�
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryTrade(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTradeField * pQryTrade, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryTrade(pQryTrade, nRequestID);
}

///�����ѯͶ���ֲ߳�
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInvestorPosition(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestorPositionField * pQryInvestorPosition, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInvestorPosition(pQryInvestorPosition, nRequestID);
}

///�����ѯ�ʽ��˻�
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryTradingAccount(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTradingAccountField * pQryTradingAccount, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryTradingAccount(pQryTradingAccount, nRequestID);
}

///�����ѯͶ����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInvestor(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestorField * pQryInvestor, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInvestor(pQryInvestor, nRequestID);
}

///�����ѯ���ױ���
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryTradingCode(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTradingCodeField * pQryTradingCode, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryTradingCode(pQryTradingCode, nRequestID);
}

///�����ѯ��Լ��֤����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInstrumentMarginRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInstrumentMarginRateField * pQryInstrumentMarginRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate, nRequestID);
}

///�����ѯ��Լ��������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInstrumentCommissionRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInstrumentCommissionRateField * pQryInstrumentCommissionRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate, nRequestID);
}

///�����ѯ������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryExchange(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryExchangeField * pQryExchange, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryExchange(pQryExchange, nRequestID);
}

///�����ѯ��Ʒ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryProduct(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryProductField * pQryProduct, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryProduct(pQryProduct, nRequestID);
}

///�����ѯ��Լ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInstrument(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInstrumentField * pQryInstrument, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInstrument(pQryInstrument, nRequestID);
}

///�����ѯ����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryDepthMarketData(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryDepthMarketDataField * pQryDepthMarketData, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryDepthMarketData(pQryDepthMarketData, nRequestID);
}

///�����ѯ����Ա���̻�
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryTraderOffer(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTraderOfferField * pQryTraderOffer, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryTraderOffer(pQryTraderOffer, nRequestID);
}

///�����ѯͶ���߽�����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQrySettlementInfo(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQrySettlementInfoField * pQrySettlementInfo, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQrySettlementInfo(pQrySettlementInfo, nRequestID);
}

///�����ѯת������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryTransferBank(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTransferBankField * pQryTransferBank, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryTransferBank(pQryTransferBank, nRequestID);
}

///�����ѯͶ���ֲ߳���ϸ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInvestorPositionDetail(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestorPositionDetailField * pQryInvestorPositionDetail, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInvestorPositionDetail(pQryInvestorPositionDetail, nRequestID);
}

///�����ѯ�ͻ�֪ͨ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryNotice(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryNoticeField * pQryNotice, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryNotice(pQryNotice, nRequestID);
}

///�����ѯ������Ϣȷ��
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQrySettlementInfoConfirm(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQrySettlementInfoConfirmField * pQrySettlementInfoConfirm, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm, nRequestID);
}

///�����ѯͶ���ֲ߳���ϸ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInvestorPositionCombineDetail(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestorPositionCombineDetailField * pQryInvestorPositionCombineDetail, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail, nRequestID);
}

///�����ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryCFMMCTradingAccountKey(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryCFMMCTradingAccountKeyField * pQryCFMMCTradingAccountKey, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey, nRequestID);
}

///�����ѯ�ֵ��۵���Ϣ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryEWarrantOffset(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryEWarrantOffsetField * pQryEWarrantOffset, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryEWarrantOffset(pQryEWarrantOffset, nRequestID);
}

///�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤��
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInvestorProductGroupMargin(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestorProductGroupMarginField * pQryInvestorProductGroupMargin, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin, nRequestID);
}

///�����ѯ��������֤����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryExchangeMarginRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryExchangeMarginRateField * pQryExchangeMarginRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryExchangeMarginRate(pQryExchangeMarginRate, nRequestID);
}

///�����ѯ������������֤����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryExchangeMarginRateAdjust(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryExchangeMarginRateAdjustField * pQryExchangeMarginRateAdjust, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust, nRequestID);
}

///�����ѯ����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryExchangeRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryExchangeRateField * pQryExchangeRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryExchangeRate(pQryExchangeRate, nRequestID);
}

///�����ѯ�����������Ա����Ȩ��
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQrySecAgentACIDMap(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQrySecAgentACIDMapField * pQrySecAgentACIDMap, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQrySecAgentACIDMap(pQrySecAgentACIDMap, nRequestID);
}

///�����ѯ��Ʒ���ۻ���
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryProductExchRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryProductExchRateField * pQryProductExchRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryProductExchRate(pQryProductExchRate, nRequestID);
}

///�����ѯ��Ʒ��
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryProductGroup(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryProductGroupField * pQryProductGroup, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryProductGroup(pQryProductGroup, nRequestID);
}

///�����ѯ�����̺�Լ��������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryMMInstrumentCommissionRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryMMInstrumentCommissionRateField * pQryMMInstrumentCommissionRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryMMInstrumentCommissionRate(pQryMMInstrumentCommissionRate, nRequestID);
}

///�����ѯ��������Ȩ��Լ������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryMMOptionInstrCommRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryMMOptionInstrCommRateField * pQryMMOptionInstrCommRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryMMOptionInstrCommRate(pQryMMOptionInstrCommRate, nRequestID);
}

///�����ѯ����������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInstrumentOrderCommRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInstrumentOrderCommRateField * pQryInstrumentOrderCommRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInstrumentOrderCommRate(pQryInstrumentOrderCommRate, nRequestID);
}

///�����ѯ�ʽ��˻�
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQrySecAgentTradingAccount(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTradingAccountField * pQryTradingAccount, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQrySecAgentTradingAccount(pQryTradingAccount, nRequestID);
}

///�����ѯ�����������ʽ�У��ģʽ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQrySecAgentCheckMode(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQrySecAgentCheckModeField * pQrySecAgentCheckMode, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQrySecAgentCheckMode(pQrySecAgentCheckMode, nRequestID);
}

///�����ѯ������������Ϣ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQrySecAgentTradeInfo(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQrySecAgentTradeInfoField * pQrySecAgentTradeInfo, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQrySecAgentTradeInfo(pQrySecAgentTradeInfo, nRequestID);
}

///�����ѯ��Ȩ���׳ɱ�
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryOptionInstrTradeCost(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryOptionInstrTradeCostField * pQryOptionInstrTradeCost, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost, nRequestID);
}

///�����ѯ��Ȩ��Լ������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryOptionInstrCommRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryOptionInstrCommRateField * pQryOptionInstrCommRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryOptionInstrCommRate(pQryOptionInstrCommRate, nRequestID);
}

///�����ѯִ������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryExecOrder(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryExecOrderField * pQryExecOrder, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryExecOrder(pQryExecOrder, nRequestID);
}

///�����ѯѯ��
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryForQuote(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryForQuoteField * pQryForQuote, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryForQuote(pQryForQuote, nRequestID);
}

///�����ѯ����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryQuote(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryQuoteField * pQryQuote, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryQuote(pQryQuote, nRequestID);
}

///�����ѯ��Ȩ�ԶԳ�
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryOptionSelfClose(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryOptionSelfCloseField * pQryOptionSelfClose, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryOptionSelfClose(pQryOptionSelfClose, nRequestID);
}

///�����ѯͶ�ʵ�Ԫ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInvestUnit(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestUnitField * pQryInvestUnit, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInvestUnit(pQryInvestUnit, nRequestID);
}

///�����ѯ��Ϻ�Լ��ȫϵ��
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryCombInstrumentGuard(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryCombInstrumentGuardField * pQryCombInstrumentGuard, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryCombInstrumentGuard(pQryCombInstrumentGuard, nRequestID);
}

///�����ѯ�������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryCombAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryCombActionField * pQryCombAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryCombAction(pQryCombAction, nRequestID);
}

///�����ѯת����ˮ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryTransferSerial(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTransferSerialField * pQryTransferSerial, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryTransferSerial(pQryTransferSerial, nRequestID);
}

///�����ѯ����ǩԼ��ϵ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryAccountregister(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryAccountregisterField * pQryAccountregister, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryAccountregister(pQryAccountregister, nRequestID);
};

///�����ѯǩԼ����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryContractBank(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryContractBankField * pQryContractBank, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryContractBank(pQryContractBank, nRequestID);
}

///�����ѯԤ��
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryParkedOrder(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryParkedOrderField * pQryParkedOrder, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryParkedOrder(pQryParkedOrder, nRequestID);
}

///�����ѯԤ�񳷵�
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryParkedOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryParkedOrderActionField * pQryParkedOrderAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryParkedOrderAction(pQryParkedOrderAction, nRequestID);
}

///�����ѯ����֪ͨ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryTradingNotice(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTradingNoticeField * pQryTradingNotice, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryTradingNotice(pQryTradingNotice, nRequestID);
}

///�����ѯ���͹�˾���ײ���
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryBrokerTradingParams(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryBrokerTradingParamsField * pQryBrokerTradingParams, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryBrokerTradingParams(pQryBrokerTradingParams, nRequestID);
}

///�����ѯ���͹�˾�����㷨
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryBrokerTradingAlgos(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryBrokerTradingAlgosField * pQryBrokerTradingAlgos, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryBrokerTradingAlgos(pQryBrokerTradingAlgos, nRequestID);
}

///�����ѯ��������û�����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQueryCFMMCTradingAccountToken(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQueryCFMMCTradingAccountTokenField * pQueryCFMMCTradingAccountToken, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken, nRequestID);
}

///�ڻ����������ʽ�ת�ڻ�����
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqFromBankToFutureByFuture(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqTransferField * pReqTransfer, int nRequestID) {
	return pCThostFtdcTraderApi->ReqFromBankToFutureByFuture(pReqTransfer, nRequestID);
}

///�ڻ������ڻ��ʽ�ת��������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqFromFutureToBankByFuture(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqTransferField * pReqTransfer, int nRequestID) {
	return pCThostFtdcTraderApi->ReqFromFutureToBankByFuture(pReqTransfer, nRequestID);
}

///�ڻ������ѯ�����������
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQueryBankAccountMoneyByFuture(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqQueryAccountField * pReqQueryAccount, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQueryBankAccountMoneyByFuture(pReqQueryAccount, nRequestID);
}

///�����ѯ�����Լ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryClassifiedInstrument(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryClassifiedInstrumentField * pQryClassifiedInstrument, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryClassifiedInstrument(pQryClassifiedInstrument, nRequestID);
}

///��������Żݱ���
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryCombPromotionParam(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryCombPromotionParamField * pQryCombPromotionParam, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryCombPromotionParam(pQryCombPromotionParam, nRequestID);
}

///Ͷ���߷��ս���ֲֲ�ѯ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryRiskSettleInvstPosition(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryRiskSettleInvstPositionField * pQryRiskSettleInvstPosition, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryRiskSettleInvstPosition(pQryRiskSettleInvstPosition, nRequestID);
}

///���ս����Ʒ��ѯ
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryRiskSettleProductStatus(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryRiskSettleProductStatusField * pQryRiskSettleProductStatus, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryRiskSettleProductStatus(pQryRiskSettleProductStatus, nRequestID);
}