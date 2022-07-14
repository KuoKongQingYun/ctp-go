#include <iostream>
#include "ThostFtdcMdApi.h"
#include "ThostFtdcTraderApi.h"
#include "wrap.h"
// =================== 行情接口 ===================

CThostFtdcMdApi* CThostFtdcMdApi_CreateFtdcMdApi(const char* pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast) {
	return CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath, bIsUsingUdp, bIsMulticast);
}

///获取API的版本信息
///@retrun 获取到的版本号
const char* CThostFtdcMdApi_GetApiVersion() {
	return CThostFtdcMdApi::GetApiVersion();
}

///删除接口对象本身
///@remark 不再使用本接口对象时,调用该函数删除接口对象
void CThostFtdcMdApi_Release(CThostFtdcMdApi* pCThostFtdcMdApi) {
	pCThostFtdcMdApi->Release();
}

///初始化
///@remark 初始化运行环境,只有调用后,接口才开始工作
void CThostFtdcMdApi_Init(CThostFtdcMdApi* pCThostFtdcMdApi) {
	pCThostFtdcMdApi->Init();
}

///等待接口线程结束运行
///@return 线程退出代码
int CThostFtdcMdApi_Join(CThostFtdcMdApi* pCThostFtdcMdApi) {
	return pCThostFtdcMdApi->Join();
}

///获取当前交易日
///@retrun 获取到的交易日
///@remark 只有登录成功后,才能得到正确的交易日
const char* CThostFtdcMdApi_GetTradingDay(CThostFtdcMdApi* pCThostFtdcMdApi) {
	return pCThostFtdcMdApi->GetTradingDay();
}

///注册前置机网络地址
///@param pszFrontAddress：前置机网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
void CThostFtdcMdApi_RegisterFront(CThostFtdcMdApi* pCThostFtdcMdApi, char* pszFrontAddress) {
	return pCThostFtdcMdApi->RegisterFront(pszFrontAddress);
}

///注册名字服务器网络地址
///@param pszNsAddress：名字服务器网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
///@remark RegisterNameServer优先于RegisterFront
void CThostFtdcMdApi_RegisterNameServer(CThostFtdcMdApi* pCThostFtdcMdApi, char* pszNsAddress) {
	return pCThostFtdcMdApi->RegisterNameServer(pszNsAddress);
}

///注册名字服务器用户信息
///@param pFensUserInfo：用户信息。
void CThostFtdcMdApi_RegisterFensUserInfo(CThostFtdcMdApi* pCThostFtdcMdApi, CThostFtdcFensUserInfoField* pFensUserInfo) {
	return pCThostFtdcMdApi->RegisterFensUserInfo(pFensUserInfo);
}

///注册回调接口
///@param pSpi 派生自回调接口类的实例
void CThostFtdcMdApi_RegisterSpi(CThostFtdcMdApi* pCThostFtdcMdApi, CThostFtdcMdSpi* pSpi) {
	return pCThostFtdcMdApi->RegisterSpi(pSpi);
}

///订阅行情。
///@param ppInstrumentID 合约ID  
///@param nCount 要订阅/退订行情的合约个数
///@remark 
int CThostFtdcMdApi_SubscribeMarketData(CThostFtdcMdApi* pCThostFtdcMdApi, char** ppInstrumentID, int nCount) {
	return pCThostFtdcMdApi->SubscribeMarketData(ppInstrumentID, nCount);
}

///退订行情。
///@param ppInstrumentID 合约ID  
///@param nCount 要订阅/退订行情的合约个数
///@remark 
int CThostFtdcMdApi_UnSubscribeMarketData(CThostFtdcMdApi* pCThostFtdcMdApi, char** ppInstrumentID, int nCount) {
	return pCThostFtdcMdApi->UnSubscribeMarketData(ppInstrumentID, nCount);
}

///订阅询价。
///@param ppInstrumentID 合约ID  
///@param nCount 要订阅/退订行情的合约个数
///@remark 
int CThostFtdcMdApi_SubscribeForQuoteRsp(CThostFtdcMdApi* pCThostFtdcMdApi, char** ppInstrumentID, int nCount) {
	return pCThostFtdcMdApi->SubscribeForQuoteRsp(ppInstrumentID, nCount);
}

///退订询价。
///@param ppInstrumentID 合约ID  
///@param nCount 要订阅/退订行情的合约个数
///@remark 
int CThostFtdcMdApi_UnSubscribeForQuoteRsp(CThostFtdcMdApi* pCThostFtdcMdApi, char** ppInstrumentID, int nCount) {
	return pCThostFtdcMdApi->UnSubscribeForQuoteRsp(ppInstrumentID, nCount);
}

///用户登录请求
int CThostFtdcMdApi_ReqUserLogin(CThostFtdcMdApi* pCThostFtdcMdApi, CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID) {
	return pCThostFtdcMdApi->ReqUserLogin(pReqUserLoginField, nRequestID);
}

///登出请求
int CThostFtdcMdApi_ReqUserLogout(CThostFtdcMdApi* pCThostFtdcMdApi, CThostFtdcUserLogoutField* pUserLogout, int nRequestID) {
	return pCThostFtdcMdApi->ReqUserLogout(pUserLogout, nRequestID);
}

///请求查询组播合约
int CThostFtdcMdApi_ReqQryMulticastInstrument(CThostFtdcMdApi* pCThostFtdcMdApi, CThostFtdcQryMulticastInstrumentField* pQryMulticastInstrument, int nRequestID) {
	return pCThostFtdcMdApi->ReqQryMulticastInstrument(pQryMulticastInstrument, nRequestID);
}


// =================== 交易接口 ======================

///创建TraderApi
///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
///@return 创建出的UserApi
CThostFtdcTraderApi * CThostFtdcTraderApi_CreateFtdcTraderApi(const char* pszFlowPath) {
	return CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath);
}

///获取API的版本信息
///@retrun 获取到的版本号
const char* CThostFtdcTraderApi_GetApiVersion() {
	return CThostFtdcTraderApi::GetApiVersion();
}

///删除接口对象本身
///@remark 不再使用本接口对象时,调用该函数删除接口对象
void CThostFtdcTraderApi_Release(CThostFtdcTraderApi * pCThostFtdcTraderApi) {
	return pCThostFtdcTraderApi->Release();
}

///初始化
///@remark 初始化运行环境,只有调用后,接口才开始工作
void CThostFtdcTraderApi_Init(CThostFtdcTraderApi * pCThostFtdcTraderApi) {
	return pCThostFtdcTraderApi->Init();
}

///等待接口线程结束运行
///@return 线程退出代码
int CThostFtdcTraderApi_Join(CThostFtdcTraderApi * pCThostFtdcTraderApi) {
	return pCThostFtdcTraderApi->Join();
}
///获取当前交易日
///@retrun 获取到的交易日
///@remark 只有登录成功后,才能得到正确的交易日
const char* CThostFtdcTraderApi_GetTradingDay(CThostFtdcTraderApi * pCThostFtdcTraderApi) {
	return pCThostFtdcTraderApi->GetTradingDay();
}

///注册前置机网络地址
///@param pszFrontAddress：前置机网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
void CThostFtdcTraderApi_RegisterFront(CThostFtdcTraderApi * pCThostFtdcTraderApi, char* pszFrontAddress) {
	return pCThostFtdcTraderApi->RegisterFront(pszFrontAddress);
}

///注册名字服务器网络地址
///@param pszNsAddress：名字服务器网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
///@remark RegisterNameServer优先于RegisterFront
void CThostFtdcTraderApi_RegisterNameServer(CThostFtdcTraderApi * pCThostFtdcTraderApi, char* pszNsAddress) {
	return pCThostFtdcTraderApi->RegisterNameServer(pszNsAddress);
}

///注册名字服务器用户信息
///@param pFensUserInfo：用户信息。
void CThostFtdcTraderApi_RegisterFensUserInfo(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcFensUserInfoField * pFensUserInfo) {
	return pCThostFtdcTraderApi->RegisterFensUserInfo(pFensUserInfo);
}

///注册回调接口
///@param pSpi 派生自回调接口类的实例
void CThostFtdcTraderApi_RegisterSpi(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcTraderSpi * pSpi) {
	return pCThostFtdcTraderApi->RegisterSpi(pSpi);
}

///订阅私有流。
///@param nResumeType 私有流重传方式  
///        THOST_TERT_RESTART:从本交易日开始重传
///        THOST_TERT_RESUME:从上次收到的续传
///        THOST_TERT_QUICK:只传送登录后私有流的内容
///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
void CThostFtdcTraderApi_SubscribePrivateTopic(CThostFtdcTraderApi * pCThostFtdcTraderApi, THOST_TE_RESUME_TYPE nResumeType) {
	return pCThostFtdcTraderApi->SubscribePrivateTopic(nResumeType);
}

///订阅公共流。
///@param nResumeType 公共流重传方式  
///        THOST_TERT_RESTART:从本交易日开始重传
///        THOST_TERT_RESUME:从上次收到的续传
///        THOST_TERT_QUICK:只传送登录后公共流的内容
///        THOST_TERT_NONE:取消订阅公共流
///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
void CThostFtdcTraderApi_SubscribePublicTopic(CThostFtdcTraderApi * pCThostFtdcTraderApi, THOST_TE_RESUME_TYPE nResumeType) {
	return pCThostFtdcTraderApi->SubscribePublicTopic(nResumeType);
}

///客户端认证请求
int CThostFtdcTraderApi_ReqAuthenticate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqAuthenticateField * pReqAuthenticateField, int nRequestID) {
	return pCThostFtdcTraderApi->ReqAuthenticate(pReqAuthenticateField, nRequestID);
}

///注册用户终端信息，用于中继服务器多连接模式
///需要在终端认证成功后，用户登录前调用该接口
int CThostFtdcTraderApi_RegisterUserSystemInfo(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcUserSystemInfoField * pUserSystemInfo) {
	return pCThostFtdcTraderApi->RegisterUserSystemInfo(pUserSystemInfo);
}

///上报用户终端信息，用于中继服务器操作员登录模式
///操作员登录后，可以多次调用该接口上报客户信息
int CThostFtdcTraderApi_SubmitUserSystemInfo(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcUserSystemInfoField * pUserSystemInfo) {
	return pCThostFtdcTraderApi->SubmitUserSystemInfo(pUserSystemInfo);
}

///用户登录请求
int CThostFtdcTraderApi_ReqUserLogin(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqUserLoginField * pReqUserLoginField, int nRequestID) {
	return pCThostFtdcTraderApi->ReqUserLogin(pReqUserLoginField, nRequestID);
}

///登出请求
int CThostFtdcTraderApi_ReqUserLogout(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcUserLogoutField * pUserLogout, int nRequestID) {
	return pCThostFtdcTraderApi->ReqUserLogout(pUserLogout, nRequestID);
}

///用户口令更新请求
int CThostFtdcTraderApi_ReqUserPasswordUpdate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcUserPasswordUpdateField * pUserPasswordUpdate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqUserPasswordUpdate(pUserPasswordUpdate, nRequestID);
}

///资金账户口令更新请求
int CThostFtdcTraderApi_ReqTradingAccountPasswordUpdate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcTradingAccountPasswordUpdateField * pTradingAccountPasswordUpdate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, nRequestID);
}

///查询用户当前支持的认证模式
int CThostFtdcTraderApi_ReqUserAuthMethod(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqUserAuthMethodField * pReqUserAuthMethod, int nRequestID) {
	return pCThostFtdcTraderApi->ReqUserAuthMethod(pReqUserAuthMethod, nRequestID);
}

///用户发出获取图形验证码请求
int CThostFtdcTraderApi_ReqGenUserCaptcha(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqGenUserCaptchaField * pReqGenUserCaptcha, int nRequestID) {
	return pCThostFtdcTraderApi->ReqGenUserCaptcha(pReqGenUserCaptcha, nRequestID);
}


///用户发出获取短信验证码请求
int CThostFtdcTraderApi_ReqGenUserText(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqGenUserTextField * pReqGenUserText, int nRequestID) {
	return pCThostFtdcTraderApi->ReqGenUserText(pReqGenUserText, nRequestID);
}


///用户发出带有图片验证码的登陆请求
int CThostFtdcTraderApi_ReqUserLoginWithCaptcha(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqUserLoginWithCaptchaField * pReqUserLoginWithCaptcha, int nRequestID) {
	return pCThostFtdcTraderApi->ReqUserLoginWithCaptcha(pReqUserLoginWithCaptcha, nRequestID);
}

///用户发出带有短信验证码的登陆请求
int CThostFtdcTraderApi_ReqUserLoginWithText(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqUserLoginWithTextField * pReqUserLoginWithText, int nRequestID) {
	return pCThostFtdcTraderApi->ReqUserLoginWithText(pReqUserLoginWithText, nRequestID);
}

///用户发出带有动态口令的登陆请求
int CThostFtdcTraderApi_ReqUserLoginWithOTP(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqUserLoginWithOTPField * pReqUserLoginWithOTP, int nRequestID) {
	return pCThostFtdcTraderApi->ReqUserLoginWithOTP(pReqUserLoginWithOTP, nRequestID);
}

///报单录入请求
int CThostFtdcTraderApi_ReqOrderInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputOrderField * pInputOrder, int nRequestID) {
	return pCThostFtdcTraderApi->ReqOrderInsert(pInputOrder, nRequestID);
}

///预埋单录入请求
int CThostFtdcTraderApi_ReqParkedOrderInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcParkedOrderField * pParkedOrder, int nRequestID) {
	return pCThostFtdcTraderApi->ReqParkedOrderInsert(pParkedOrder, nRequestID);
}

///预埋撤单录入请求
int CThostFtdcTraderApi_ReqParkedOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcParkedOrderActionField * pParkedOrderAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqParkedOrderAction(pParkedOrderAction, nRequestID);
}

///报单操作请求
int CThostFtdcTraderApi_ReqOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputOrderActionField * pInputOrderAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqOrderAction(pInputOrderAction, nRequestID);
}

///查询最大报单数量请求
int CThostFtdcTraderApi_ReqQryMaxOrderVolume(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryMaxOrderVolumeField * pQryMaxOrderVolume, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryMaxOrderVolume(pQryMaxOrderVolume, nRequestID);
}

///投资者结算结果确认
int CThostFtdcTraderApi_ReqSettlementInfoConfirm(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcSettlementInfoConfirmField * pSettlementInfoConfirm, int nRequestID) {
	return pCThostFtdcTraderApi->ReqSettlementInfoConfirm(pSettlementInfoConfirm, nRequestID);
}

///请求删除预埋单
int CThostFtdcTraderApi_ReqRemoveParkedOrder(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcRemoveParkedOrderField * pRemoveParkedOrder, int nRequestID) {
	return pCThostFtdcTraderApi->ReqRemoveParkedOrder(pRemoveParkedOrder, nRequestID);
}

///请求删除预埋撤单
int CThostFtdcTraderApi_ReqRemoveParkedOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcRemoveParkedOrderActionField * pRemoveParkedOrderAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqRemoveParkedOrderAction(pRemoveParkedOrderAction, nRequestID);
}

///执行宣告录入请求
int CThostFtdcTraderApi_ReqExecOrderInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputExecOrderField * pInputExecOrder, int nRequestID) {
	return pCThostFtdcTraderApi->ReqExecOrderInsert(pInputExecOrder, nRequestID);
}

///执行宣告操作请求
int CThostFtdcTraderApi_ReqExecOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputExecOrderActionField * pInputExecOrderAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqExecOrderAction(pInputExecOrderAction, nRequestID);
}

///询价录入请求
int CThostFtdcTraderApi_ReqForQuoteInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputForQuoteField * pInputForQuote, int nRequestID) {
	return pCThostFtdcTraderApi->ReqForQuoteInsert(pInputForQuote, nRequestID);
}

///报价录入请求
int CThostFtdcTraderApi_ReqQuoteInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputQuoteField * pInputQuote, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQuoteInsert(pInputQuote, nRequestID);
}

///报价操作请求
int CThostFtdcTraderApi_ReqQuoteAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputQuoteActionField * pInputQuoteAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQuoteAction(pInputQuoteAction, nRequestID);
}

///批量报单操作请求
int CThostFtdcTraderApi_ReqBatchOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputBatchOrderActionField * pInputBatchOrderAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqBatchOrderAction(pInputBatchOrderAction, nRequestID);
}

///期权自对冲录入请求
int CThostFtdcTraderApi_ReqOptionSelfCloseInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputOptionSelfCloseField * pInputOptionSelfClose, int nRequestID) {
	return pCThostFtdcTraderApi->ReqOptionSelfCloseInsert(pInputOptionSelfClose, nRequestID);
}

///期权自对冲操作请求
int CThostFtdcTraderApi_ReqOptionSelfCloseAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputOptionSelfCloseActionField * pInputOptionSelfCloseAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqOptionSelfCloseAction(pInputOptionSelfCloseAction, nRequestID);
}

///申请组合录入请求
int CThostFtdcTraderApi_ReqCombActionInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputCombActionField * pInputCombAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqCombActionInsert(pInputCombAction, nRequestID);
}

///请求查询报单
int CThostFtdcTraderApi_ReqQryOrder(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryOrderField * pQryOrder, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryOrder(pQryOrder, nRequestID);
}

///请求查询成交
int CThostFtdcTraderApi_ReqQryTrade(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTradeField * pQryTrade, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryTrade(pQryTrade, nRequestID);
}

///请求查询投资者持仓
int CThostFtdcTraderApi_ReqQryInvestorPosition(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestorPositionField * pQryInvestorPosition, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInvestorPosition(pQryInvestorPosition, nRequestID);
}

///请求查询资金账户
int CThostFtdcTraderApi_ReqQryTradingAccount(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTradingAccountField * pQryTradingAccount, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryTradingAccount(pQryTradingAccount, nRequestID);
}

///请求查询投资者
int CThostFtdcTraderApi_ReqQryInvestor(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestorField * pQryInvestor, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInvestor(pQryInvestor, nRequestID);
}

///请求查询交易编码
int CThostFtdcTraderApi_ReqQryTradingCode(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTradingCodeField * pQryTradingCode, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryTradingCode(pQryTradingCode, nRequestID);
}

///请求查询合约保证金率
int CThostFtdcTraderApi_ReqQryInstrumentMarginRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInstrumentMarginRateField * pQryInstrumentMarginRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInstrumentMarginRate(pQryInstrumentMarginRate, nRequestID);
}

///请求查询合约手续费率
int CThostFtdcTraderApi_ReqQryInstrumentCommissionRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInstrumentCommissionRateField * pQryInstrumentCommissionRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInstrumentCommissionRate(pQryInstrumentCommissionRate, nRequestID);
}

///请求查询交易所
int CThostFtdcTraderApi_ReqQryExchange(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryExchangeField * pQryExchange, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryExchange(pQryExchange, nRequestID);
}

///请求查询产品
int CThostFtdcTraderApi_ReqQryProduct(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryProductField * pQryProduct, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryProduct(pQryProduct, nRequestID);
}

///请求查询合约
int CThostFtdcTraderApi_ReqQryInstrument(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInstrumentField * pQryInstrument, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInstrument(pQryInstrument, nRequestID);
}

///请求查询行情
int CThostFtdcTraderApi_ReqQryDepthMarketData(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryDepthMarketDataField * pQryDepthMarketData, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryDepthMarketData(pQryDepthMarketData, nRequestID);
}

///请求查询交易员报盘机
int CThostFtdcTraderApi_ReqQryTraderOffer(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTraderOfferField * pQryTraderOffer, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryTraderOffer(pQryTraderOffer, nRequestID);
}

///请求查询投资者结算结果
int CThostFtdcTraderApi_ReqQrySettlementInfo(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQrySettlementInfoField * pQrySettlementInfo, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQrySettlementInfo(pQrySettlementInfo, nRequestID);
}

///请求查询转帐银行
int CThostFtdcTraderApi_ReqQryTransferBank(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTransferBankField * pQryTransferBank, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryTransferBank(pQryTransferBank, nRequestID);
}

///请求查询投资者持仓明细
int CThostFtdcTraderApi_ReqQryInvestorPositionDetail(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestorPositionDetailField * pQryInvestorPositionDetail, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInvestorPositionDetail(pQryInvestorPositionDetail, nRequestID);
}

///请求查询客户通知
int CThostFtdcTraderApi_ReqQryNotice(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryNoticeField * pQryNotice, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryNotice(pQryNotice, nRequestID);
}

///请求查询结算信息确认
int CThostFtdcTraderApi_ReqQrySettlementInfoConfirm(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQrySettlementInfoConfirmField * pQrySettlementInfoConfirm, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQrySettlementInfoConfirm(pQrySettlementInfoConfirm, nRequestID);
}

///请求查询投资者持仓明细
int CThostFtdcTraderApi_ReqQryInvestorPositionCombineDetail(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestorPositionCombineDetailField * pQryInvestorPositionCombineDetail, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInvestorPositionCombineDetail(pQryInvestorPositionCombineDetail, nRequestID);
}

///请求查询保证金监管系统经纪公司资金账户密钥
int CThostFtdcTraderApi_ReqQryCFMMCTradingAccountKey(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryCFMMCTradingAccountKeyField * pQryCFMMCTradingAccountKey, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryCFMMCTradingAccountKey(pQryCFMMCTradingAccountKey, nRequestID);
}

///请求查询仓单折抵信息
int CThostFtdcTraderApi_ReqQryEWarrantOffset(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryEWarrantOffsetField * pQryEWarrantOffset, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryEWarrantOffset(pQryEWarrantOffset, nRequestID);
}

///请求查询投资者品种/跨品种保证金
int CThostFtdcTraderApi_ReqQryInvestorProductGroupMargin(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestorProductGroupMarginField * pQryInvestorProductGroupMargin, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInvestorProductGroupMargin(pQryInvestorProductGroupMargin, nRequestID);
}

///请求查询交易所保证金率
int CThostFtdcTraderApi_ReqQryExchangeMarginRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryExchangeMarginRateField * pQryExchangeMarginRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryExchangeMarginRate(pQryExchangeMarginRate, nRequestID);
}

///请求查询交易所调整保证金率
int CThostFtdcTraderApi_ReqQryExchangeMarginRateAdjust(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryExchangeMarginRateAdjustField * pQryExchangeMarginRateAdjust, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryExchangeMarginRateAdjust(pQryExchangeMarginRateAdjust, nRequestID);
}

///请求查询汇率
int CThostFtdcTraderApi_ReqQryExchangeRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryExchangeRateField * pQryExchangeRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryExchangeRate(pQryExchangeRate, nRequestID);
}

///请求查询二级代理操作员银期权限
int CThostFtdcTraderApi_ReqQrySecAgentACIDMap(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQrySecAgentACIDMapField * pQrySecAgentACIDMap, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQrySecAgentACIDMap(pQrySecAgentACIDMap, nRequestID);
}

///请求查询产品报价汇率
int CThostFtdcTraderApi_ReqQryProductExchRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryProductExchRateField * pQryProductExchRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryProductExchRate(pQryProductExchRate, nRequestID);
}

///请求查询产品组
int CThostFtdcTraderApi_ReqQryProductGroup(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryProductGroupField * pQryProductGroup, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryProductGroup(pQryProductGroup, nRequestID);
}

///请求查询做市商合约手续费率
int CThostFtdcTraderApi_ReqQryMMInstrumentCommissionRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryMMInstrumentCommissionRateField * pQryMMInstrumentCommissionRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryMMInstrumentCommissionRate(pQryMMInstrumentCommissionRate, nRequestID);
}

///请求查询做市商期权合约手续费
int CThostFtdcTraderApi_ReqQryMMOptionInstrCommRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryMMOptionInstrCommRateField * pQryMMOptionInstrCommRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryMMOptionInstrCommRate(pQryMMOptionInstrCommRate, nRequestID);
}

///请求查询报单手续费
int CThostFtdcTraderApi_ReqQryInstrumentOrderCommRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInstrumentOrderCommRateField * pQryInstrumentOrderCommRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInstrumentOrderCommRate(pQryInstrumentOrderCommRate, nRequestID);
}

///请求查询资金账户
int CThostFtdcTraderApi_ReqQrySecAgentTradingAccount(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTradingAccountField * pQryTradingAccount, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQrySecAgentTradingAccount(pQryTradingAccount, nRequestID);
}

///请求查询二级代理商资金校验模式
int CThostFtdcTraderApi_ReqQrySecAgentCheckMode(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQrySecAgentCheckModeField * pQrySecAgentCheckMode, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQrySecAgentCheckMode(pQrySecAgentCheckMode, nRequestID);
}

///请求查询二级代理商信息
int CThostFtdcTraderApi_ReqQrySecAgentTradeInfo(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQrySecAgentTradeInfoField * pQrySecAgentTradeInfo, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQrySecAgentTradeInfo(pQrySecAgentTradeInfo, nRequestID);
}

///请求查询期权交易成本
int CThostFtdcTraderApi_ReqQryOptionInstrTradeCost(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryOptionInstrTradeCostField * pQryOptionInstrTradeCost, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryOptionInstrTradeCost(pQryOptionInstrTradeCost, nRequestID);
}

///请求查询期权合约手续费
int CThostFtdcTraderApi_ReqQryOptionInstrCommRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryOptionInstrCommRateField * pQryOptionInstrCommRate, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryOptionInstrCommRate(pQryOptionInstrCommRate, nRequestID);
}

///请求查询执行宣告
int CThostFtdcTraderApi_ReqQryExecOrder(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryExecOrderField * pQryExecOrder, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryExecOrder(pQryExecOrder, nRequestID);
}

///请求查询询价
int CThostFtdcTraderApi_ReqQryForQuote(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryForQuoteField * pQryForQuote, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryForQuote(pQryForQuote, nRequestID);
}

///请求查询报价
int CThostFtdcTraderApi_ReqQryQuote(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryQuoteField * pQryQuote, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryQuote(pQryQuote, nRequestID);
}

///请求查询期权自对冲
int CThostFtdcTraderApi_ReqQryOptionSelfClose(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryOptionSelfCloseField * pQryOptionSelfClose, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryOptionSelfClose(pQryOptionSelfClose, nRequestID);
}

///请求查询投资单元
int CThostFtdcTraderApi_ReqQryInvestUnit(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestUnitField * pQryInvestUnit, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryInvestUnit(pQryInvestUnit, nRequestID);
}

///请求查询组合合约安全系数
int CThostFtdcTraderApi_ReqQryCombInstrumentGuard(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryCombInstrumentGuardField * pQryCombInstrumentGuard, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryCombInstrumentGuard(pQryCombInstrumentGuard, nRequestID);
}

///请求查询申请组合
int CThostFtdcTraderApi_ReqQryCombAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryCombActionField * pQryCombAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryCombAction(pQryCombAction, nRequestID);
}

///请求查询转帐流水
int CThostFtdcTraderApi_ReqQryTransferSerial(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTransferSerialField * pQryTransferSerial, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryTransferSerial(pQryTransferSerial, nRequestID);
}

///请求查询银期签约关系
int CThostFtdcTraderApi_ReqQryAccountregister(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryAccountregisterField * pQryAccountregister, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryAccountregister(pQryAccountregister, nRequestID);
};

///请求查询签约银行
int CThostFtdcTraderApi_ReqQryContractBank(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryContractBankField * pQryContractBank, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryContractBank(pQryContractBank, nRequestID);
}

///请求查询预埋单
int CThostFtdcTraderApi_ReqQryParkedOrder(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryParkedOrderField * pQryParkedOrder, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryParkedOrder(pQryParkedOrder, nRequestID);
}

///请求查询预埋撤单
int CThostFtdcTraderApi_ReqQryParkedOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryParkedOrderActionField * pQryParkedOrderAction, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryParkedOrderAction(pQryParkedOrderAction, nRequestID);
}

///请求查询交易通知
int CThostFtdcTraderApi_ReqQryTradingNotice(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTradingNoticeField * pQryTradingNotice, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryTradingNotice(pQryTradingNotice, nRequestID);
}

///请求查询经纪公司交易参数
int CThostFtdcTraderApi_ReqQryBrokerTradingParams(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryBrokerTradingParamsField * pQryBrokerTradingParams, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryBrokerTradingParams(pQryBrokerTradingParams, nRequestID);
}

///请求查询经纪公司交易算法
int CThostFtdcTraderApi_ReqQryBrokerTradingAlgos(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryBrokerTradingAlgosField * pQryBrokerTradingAlgos, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryBrokerTradingAlgos(pQryBrokerTradingAlgos, nRequestID);
}

///请求查询监控中心用户令牌
int CThostFtdcTraderApi_ReqQueryCFMMCTradingAccountToken(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQueryCFMMCTradingAccountTokenField * pQueryCFMMCTradingAccountToken, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken, nRequestID);
}

///期货发起银行资金转期货请求
int CThostFtdcTraderApi_ReqFromBankToFutureByFuture(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqTransferField * pReqTransfer, int nRequestID) {
	return pCThostFtdcTraderApi->ReqFromBankToFutureByFuture(pReqTransfer, nRequestID);
}

///期货发起期货资金转银行请求
int CThostFtdcTraderApi_ReqFromFutureToBankByFuture(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqTransferField * pReqTransfer, int nRequestID) {
	return pCThostFtdcTraderApi->ReqFromFutureToBankByFuture(pReqTransfer, nRequestID);
}

///期货发起查询银行余额请求
int CThostFtdcTraderApi_ReqQueryBankAccountMoneyByFuture(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqQueryAccountField * pReqQueryAccount, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQueryBankAccountMoneyByFuture(pReqQueryAccount, nRequestID);
}

///请求查询分类合约
int CThostFtdcTraderApi_ReqQryClassifiedInstrument(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryClassifiedInstrumentField * pQryClassifiedInstrument, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryClassifiedInstrument(pQryClassifiedInstrument, nRequestID);
}

///请求组合优惠比例
int CThostFtdcTraderApi_ReqQryCombPromotionParam(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryCombPromotionParamField * pQryCombPromotionParam, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryCombPromotionParam(pQryCombPromotionParam, nRequestID);
}

///投资者风险结算持仓查询
int CThostFtdcTraderApi_ReqQryRiskSettleInvstPosition(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryRiskSettleInvstPositionField * pQryRiskSettleInvstPosition, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryRiskSettleInvstPosition(pQryRiskSettleInvstPosition, nRequestID);
}

///风险结算产品查询
int CThostFtdcTraderApi_ReqQryRiskSettleProductStatus(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryRiskSettleProductStatusField * pQryRiskSettleProductStatus, int nRequestID) {
	return pCThostFtdcTraderApi->ReqQryRiskSettleProductStatus(pQryRiskSettleProductStatus, nRequestID);
}