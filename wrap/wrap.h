#if !defined(EXPORT_H)
#define EXPORT_H
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_CTP_API_EXPORT
#define CTP_API_EXPORT __declspec(dllexport)
#else
#define CTP_API_EXPORT __declspec(dllimport)
#endif
#else
#define CTP_API_EXPORT 
#endif
#endif

// =================== 行情接口 ===================

extern "C" CTP_API_EXPORT  CThostFtdcMdApi * CThostFtdcMdApi_CreateFtdcMdApi(const char* pszFlowPath = "", const bool bIsUsingUdp = false, const bool bIsMulticast = false);

///获取API的版本信息
///@retrun 获取到的版本号
extern "C" CTP_API_EXPORT  const char* CThostFtdcMdApi_GetApiVersion();

///删除接口对象本身
///@remark 不再使用本接口对象时,调用该函数删除接口对象
extern "C" CTP_API_EXPORT  void CThostFtdcMdApi_Release(CThostFtdcMdApi * pCThostFtdcMdApi);

///初始化
///@remark 初始化运行环境,只有调用后,接口才开始工作
extern "C" CTP_API_EXPORT  void CThostFtdcMdApi_Init(CThostFtdcMdApi * pCThostFtdcMdApi);

///等待接口线程结束运行
///@return 线程退出代码
extern "C" CTP_API_EXPORT  int CThostFtdcMdApi_Join(CThostFtdcMdApi * pCThostFtdcMdApi);

///获取当前交易日
///@retrun 获取到的交易日
///@remark 只有登录成功后,才能得到正确的交易日
extern "C" CTP_API_EXPORT  const char* CThostFtdcMdApi_GetTradingDay(CThostFtdcMdApi * pCThostFtdcMdApi);

///注册前置机网络地址
///@param pszFrontAddress：前置机网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
extern "C" CTP_API_EXPORT  void CThostFtdcMdApi_RegisterFront(CThostFtdcMdApi * pCThostFtdcMdApi, char* pszFrontAddress);

///注册名字服务器网络地址
///@param pszNsAddress：名字服务器网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
///@remark RegisterNameServer优先于RegisterFront
extern "C" CTP_API_EXPORT  void CThostFtdcMdApi_RegisterNameServer(CThostFtdcMdApi * pCThostFtdcMdApi, char* pszNsAddress);

///注册名字服务器用户信息
///@param pFensUserInfo：用户信息。
extern "C" CTP_API_EXPORT  void CThostFtdcMdApi_RegisterFensUserInfo(CThostFtdcMdApi * pCThostFtdcMdApi, CThostFtdcFensUserInfoField * pFensUserInfo);

///注册回调接口
///@param pSpi 派生自回调接口类的实例
extern "C" CTP_API_EXPORT  void CThostFtdcMdApi_RegisterSpi(CThostFtdcMdApi * pCThostFtdcMdApi, CThostFtdcMdSpi * pSpi);

///订阅行情。
///@param ppInstrumentID 合约ID  
///@param nCount 要订阅/退订行情的合约个数
///@remark 
extern "C" CTP_API_EXPORT  int CThostFtdcMdApi_SubscribeMarketData(CThostFtdcMdApi * pCThostFtdcMdApi, char** ppInstrumentID, int nCount);

///退订行情。
///@param ppInstrumentID 合约ID  
///@param nCount 要订阅/退订行情的合约个数
///@remark 
extern "C" CTP_API_EXPORT  int CThostFtdcMdApi_UnSubscribeMarketData(CThostFtdcMdApi * pCThostFtdcMdApi, char** ppInstrumentID, int nCount);

///订阅询价。
///@param ppInstrumentID 合约ID  
///@param nCount 要订阅/退订行情的合约个数
///@remark 
extern "C" CTP_API_EXPORT  int CThostFtdcMdApi_SubscribeForQuoteRsp(CThostFtdcMdApi * pCThostFtdcMdApi, char** ppInstrumentID, int nCount);

///退订询价。
///@param ppInstrumentID 合约ID  
///@param nCount 要订阅/退订行情的合约个数
///@remark 
extern "C" CTP_API_EXPORT  int CThostFtdcMdApi_UnSubscribeForQuoteRsp(CThostFtdcMdApi * pCThostFtdcMdApi, char** ppInstrumentID, int nCount);

///用户登录请求
extern "C" CTP_API_EXPORT  int CThostFtdcMdApi_ReqUserLogin(CThostFtdcMdApi * pCThostFtdcMdApi, CThostFtdcReqUserLoginField * pReqUserLoginField, int nRequestID);

///登出请求
extern "C" CTP_API_EXPORT  int CThostFtdcMdApi_ReqUserLogout(CThostFtdcMdApi * pCThostFtdcMdApi, CThostFtdcUserLogoutField * pUserLogout, int nRequestID);

///请求查询组播合约
extern "C" CTP_API_EXPORT  int CThostFtdcMdApi_ReqQryMulticastInstrument(CThostFtdcMdApi * pCThostFtdcMdApi, CThostFtdcQryMulticastInstrumentField * pQryMulticastInstrument, int nRequestID);


// =================== 交易接口 ======================

///创建TraderApi
///@param pszFlowPath 存贮订阅信息文件的目录，默认为当前目录
///@return 创建出的UserApi
extern "C" CTP_API_EXPORT CThostFtdcTraderApi * CThostFtdcTraderApi_CreateFtdcTraderApi(const char* pszFlowPath = "");

///获取API的版本信息
///@retrun 获取到的版本号
extern "C" CTP_API_EXPORT const char* CThostFtdcTraderApi_GetApiVersion();

///删除接口对象本身
///@remark 不再使用本接口对象时,调用该函数删除接口对象
extern "C" CTP_API_EXPORT void CThostFtdcTraderApi_Release(CThostFtdcTraderApi * pCThostFtdcTraderApi);

///初始化
///@remark 初始化运行环境,只有调用后,接口才开始工作
extern "C" CTP_API_EXPORT void CThostFtdcTraderApi_Init(CThostFtdcTraderApi * pCThostFtdcTraderApi);

///等待接口线程结束运行
///@return 线程退出代码
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_Join(CThostFtdcTraderApi * pCThostFtdcTraderApi);
///获取当前交易日
///@retrun 获取到的交易日
///@remark 只有登录成功后,才能得到正确的交易日
extern "C" CTP_API_EXPORT const char* CThostFtdcTraderApi_GetTradingDay(CThostFtdcTraderApi * pCThostFtdcTraderApi);

///注册前置机网络地址
///@param pszFrontAddress：前置机网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
extern "C" CTP_API_EXPORT void CThostFtdcTraderApi_RegisterFront(CThostFtdcTraderApi * pCThostFtdcTraderApi, char* pszFrontAddress);

///注册名字服务器网络地址
///@param pszNsAddress：名字服务器网络地址。
///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
///@remark RegisterNameServer优先于RegisterFront
extern "C" CTP_API_EXPORT void CThostFtdcTraderApi_RegisterNameServer(CThostFtdcTraderApi * pCThostFtdcTraderApi, char* pszNsAddress);

///注册名字服务器用户信息
///@param pFensUserInfo：用户信息。
extern "C" CTP_API_EXPORT void CThostFtdcTraderApi_RegisterFensUserInfo(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcFensUserInfoField * pFensUserInfo);

///注册回调接口
///@param pSpi 派生自回调接口类的实例
extern "C" CTP_API_EXPORT void CThostFtdcTraderApi_RegisterSpi(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcTraderSpi * pSpi);

///订阅私有流。
///@param nResumeType 私有流重传方式  
///        THOST_TERT_RESTART:从本交易日开始重传
///        THOST_TERT_RESUME:从上次收到的续传
///        THOST_TERT_QUICK:只传送登录后私有流的内容
///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
extern "C" CTP_API_EXPORT void CThostFtdcTraderApi_SubscribePrivateTopic(CThostFtdcTraderApi * pCThostFtdcTraderApi, THOST_TE_RESUME_TYPE nResumeType);

///订阅公共流。
///@param nResumeType 公共流重传方式  
///        THOST_TERT_RESTART:从本交易日开始重传
///        THOST_TERT_RESUME:从上次收到的续传
///        THOST_TERT_QUICK:只传送登录后公共流的内容
///        THOST_TERT_NONE:取消订阅公共流
///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
extern "C" CTP_API_EXPORT void CThostFtdcTraderApi_SubscribePublicTopic(CThostFtdcTraderApi * pCThostFtdcTraderApi, THOST_TE_RESUME_TYPE nResumeType);

///客户端认证请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqAuthenticate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqAuthenticateField * pReqAuthenticateField, int nRequestID);

///注册用户终端信息，用于中继服务器多连接模式
///需要在终端认证成功后，用户登录前调用该接口
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_RegisterUserSystemInfo(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcUserSystemInfoField * pUserSystemInfo);

///上报用户终端信息，用于中继服务器操作员登录模式
///操作员登录后，可以多次调用该接口上报客户信息
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_SubmitUserSystemInfo(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcUserSystemInfoField * pUserSystemInfo);

///用户登录请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqUserLogin(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqUserLoginField * pReqUserLoginField, int nRequestID);

///登出请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqUserLogout(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcUserLogoutField * pUserLogout, int nRequestID);

///用户口令更新请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqUserPasswordUpdate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcUserPasswordUpdateField * pUserPasswordUpdate, int nRequestID);

///资金账户口令更新请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqTradingAccountPasswordUpdate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcTradingAccountPasswordUpdateField * pTradingAccountPasswordUpdate, int nRequestID);

///查询用户当前支持的认证模式
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqUserAuthMethod(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqUserAuthMethodField * pReqUserAuthMethod, int nRequestID);

///用户发出获取图形验证码请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqGenUserCaptcha(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqGenUserCaptchaField * pReqGenUserCaptcha, int nRequestID);


///用户发出获取短信验证码请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqGenUserText(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqGenUserTextField * pReqGenUserText, int nRequestID);


///用户发出带有图片验证码的登陆请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqUserLoginWithCaptcha(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqUserLoginWithCaptchaField * pReqUserLoginWithCaptcha, int nRequestID);

///用户发出带有短信验证码的登陆请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqUserLoginWithText(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqUserLoginWithTextField * pReqUserLoginWithText, int nRequestID);

///用户发出带有动态口令的登陆请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqUserLoginWithOTP(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqUserLoginWithOTPField * pReqUserLoginWithOTP, int nRequestID);

///报单录入请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqOrderInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputOrderField * pInputOrder, int nRequestID);

///预埋单录入请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqParkedOrderInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcParkedOrderField * pParkedOrder, int nRequestID);

///预埋撤单录入请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqParkedOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcParkedOrderActionField * pParkedOrderAction, int nRequestID);

///报单操作请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputOrderActionField * pInputOrderAction, int nRequestID);

///查询最大报单数量请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryMaxOrderVolume(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryMaxOrderVolumeField * pQryMaxOrderVolume, int nRequestID);

///投资者结算结果确认
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqSettlementInfoConfirm(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcSettlementInfoConfirmField * pSettlementInfoConfirm, int nRequestID);

///请求删除预埋单
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqRemoveParkedOrder(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcRemoveParkedOrderField * pRemoveParkedOrder, int nRequestID);

///请求删除预埋撤单
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqRemoveParkedOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcRemoveParkedOrderActionField * pRemoveParkedOrderAction, int nRequestID);

///执行宣告录入请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqExecOrderInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputExecOrderField * pInputExecOrder, int nRequestID);

///执行宣告操作请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqExecOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputExecOrderActionField * pInputExecOrderAction, int nRequestID);

///询价录入请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqForQuoteInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputForQuoteField * pInputForQuote, int nRequestID);

///报价录入请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQuoteInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputQuoteField * pInputQuote, int nRequestID);

///报价操作请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQuoteAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputQuoteActionField * pInputQuoteAction, int nRequestID);

///批量报单操作请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqBatchOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputBatchOrderActionField * pInputBatchOrderAction, int nRequestID);

///期权自对冲录入请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqOptionSelfCloseInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputOptionSelfCloseField * pInputOptionSelfClose, int nRequestID);

///期权自对冲操作请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqOptionSelfCloseAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputOptionSelfCloseActionField * pInputOptionSelfCloseAction, int nRequestID);

///申请组合录入请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqCombActionInsert(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcInputCombActionField * pInputCombAction, int nRequestID);

///请求查询报单
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryOrder(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryOrderField * pQryOrder, int nRequestID);

///请求查询成交
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryTrade(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTradeField * pQryTrade, int nRequestID);

///请求查询投资者持仓
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInvestorPosition(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestorPositionField * pQryInvestorPosition, int nRequestID);

///请求查询资金账户
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryTradingAccount(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTradingAccountField * pQryTradingAccount, int nRequestID);

///请求查询投资者
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInvestor(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestorField * pQryInvestor, int nRequestID);

///请求查询交易编码
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryTradingCode(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTradingCodeField * pQryTradingCode, int nRequestID);

///请求查询合约保证金率
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInstrumentMarginRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInstrumentMarginRateField * pQryInstrumentMarginRate, int nRequestID);

///请求查询合约手续费率
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInstrumentCommissionRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInstrumentCommissionRateField * pQryInstrumentCommissionRate, int nRequestID);

///请求查询交易所
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryExchange(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryExchangeField * pQryExchange, int nRequestID);

///请求查询产品
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryProduct(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryProductField * pQryProduct, int nRequestID);

///请求查询合约
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInstrument(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInstrumentField * pQryInstrument, int nRequestID);

///请求查询行情
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryDepthMarketData(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryDepthMarketDataField * pQryDepthMarketData, int nRequestID);

///请求查询交易员报盘机
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryTraderOffer(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTraderOfferField * pQryTraderOffer, int nRequestID);

///请求查询投资者结算结果
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQrySettlementInfo(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQrySettlementInfoField * pQrySettlementInfo, int nRequestID);

///请求查询转帐银行
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryTransferBank(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTransferBankField * pQryTransferBank, int nRequestID);

///请求查询投资者持仓明细
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInvestorPositionDetail(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestorPositionDetailField * pQryInvestorPositionDetail, int nRequestID);

///请求查询客户通知
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryNotice(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryNoticeField * pQryNotice, int nRequestID);

///请求查询结算信息确认
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQrySettlementInfoConfirm(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQrySettlementInfoConfirmField * pQrySettlementInfoConfirm, int nRequestID);

///请求查询投资者持仓明细
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInvestorPositionCombineDetail(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestorPositionCombineDetailField * pQryInvestorPositionCombineDetail, int nRequestID);

///请求查询保证金监管系统经纪公司资金账户密钥
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryCFMMCTradingAccountKey(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryCFMMCTradingAccountKeyField * pQryCFMMCTradingAccountKey, int nRequestID);

///请求查询仓单折抵信息
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryEWarrantOffset(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryEWarrantOffsetField * pQryEWarrantOffset, int nRequestID);

///请求查询投资者品种/跨品种保证金
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInvestorProductGroupMargin(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestorProductGroupMarginField * pQryInvestorProductGroupMargin, int nRequestID);

///请求查询交易所保证金率
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryExchangeMarginRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryExchangeMarginRateField * pQryExchangeMarginRate, int nRequestID);

///请求查询交易所调整保证金率
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryExchangeMarginRateAdjust(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryExchangeMarginRateAdjustField * pQryExchangeMarginRateAdjust, int nRequestID);

///请求查询汇率
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryExchangeRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryExchangeRateField * pQryExchangeRate, int nRequestID);

///请求查询二级代理操作员银期权限
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQrySecAgentACIDMap(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQrySecAgentACIDMapField * pQrySecAgentACIDMap, int nRequestID);

///请求查询产品报价汇率
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryProductExchRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryProductExchRateField * pQryProductExchRate, int nRequestID);

///请求查询产品组
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryProductGroup(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryProductGroupField * pQryProductGroup, int nRequestID);

///请求查询做市商合约手续费率
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryMMInstrumentCommissionRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryMMInstrumentCommissionRateField * pQryMMInstrumentCommissionRate, int nRequestID);

///请求查询做市商期权合约手续费
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryMMOptionInstrCommRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryMMOptionInstrCommRateField * pQryMMOptionInstrCommRate, int nRequestID);

///请求查询报单手续费
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInstrumentOrderCommRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInstrumentOrderCommRateField * pQryInstrumentOrderCommRate, int nRequestID);

///请求查询资金账户
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQrySecAgentTradingAccount(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTradingAccountField * pQryTradingAccount, int nRequestID);

///请求查询二级代理商资金校验模式
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQrySecAgentCheckMode(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQrySecAgentCheckModeField * pQrySecAgentCheckMode, int nRequestID);

///请求查询二级代理商信息
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQrySecAgentTradeInfo(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQrySecAgentTradeInfoField * pQrySecAgentTradeInfo, int nRequestID);

///请求查询期权交易成本
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryOptionInstrTradeCost(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryOptionInstrTradeCostField * pQryOptionInstrTradeCost, int nRequestID);

///请求查询期权合约手续费
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryOptionInstrCommRate(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryOptionInstrCommRateField * pQryOptionInstrCommRate, int nRequestID);

///请求查询执行宣告
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryExecOrder(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryExecOrderField * pQryExecOrder, int nRequestID);

///请求查询询价
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryForQuote(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryForQuoteField * pQryForQuote, int nRequestID);

///请求查询报价
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryQuote(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryQuoteField * pQryQuote, int nRequestID);

///请求查询期权自对冲
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryOptionSelfClose(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryOptionSelfCloseField * pQryOptionSelfClose, int nRequestID);

///请求查询投资单元
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryInvestUnit(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryInvestUnitField * pQryInvestUnit, int nRequestID);

///请求查询组合合约安全系数
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryCombInstrumentGuard(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryCombInstrumentGuardField * pQryCombInstrumentGuard, int nRequestID);

///请求查询申请组合
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryCombAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryCombActionField * pQryCombAction, int nRequestID);

///请求查询转帐流水
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryTransferSerial(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTransferSerialField * pQryTransferSerial, int nRequestID);

///请求查询银期签约关系
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryAccountregister(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryAccountregisterField * pQryAccountregister, int nRequestID);;

///请求查询签约银行
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryContractBank(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryContractBankField * pQryContractBank, int nRequestID);

///请求查询预埋单
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryParkedOrder(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryParkedOrderField * pQryParkedOrder, int nRequestID);

///请求查询预埋撤单
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryParkedOrderAction(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryParkedOrderActionField * pQryParkedOrderAction, int nRequestID);

///请求查询交易通知
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryTradingNotice(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryTradingNoticeField * pQryTradingNotice, int nRequestID);

///请求查询经纪公司交易参数
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryBrokerTradingParams(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryBrokerTradingParamsField * pQryBrokerTradingParams, int nRequestID);

///请求查询经纪公司交易算法
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryBrokerTradingAlgos(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryBrokerTradingAlgosField * pQryBrokerTradingAlgos, int nRequestID);

///请求查询监控中心用户令牌
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQueryCFMMCTradingAccountToken(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQueryCFMMCTradingAccountTokenField * pQueryCFMMCTradingAccountToken, int nRequestID);

///期货发起银行资金转期货请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqFromBankToFutureByFuture(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqTransferField * pReqTransfer, int nRequestID);

///期货发起期货资金转银行请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqFromFutureToBankByFuture(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqTransferField * pReqTransfer, int nRequestID);

///期货发起查询银行余额请求
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQueryBankAccountMoneyByFuture(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcReqQueryAccountField * pReqQueryAccount, int nRequestID);

///请求查询分类合约
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryClassifiedInstrument(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryClassifiedInstrumentField * pQryClassifiedInstrument, int nRequestID);

///请求组合优惠比例
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryCombPromotionParam(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryCombPromotionParamField * pQryCombPromotionParam, int nRequestID);

///投资者风险结算持仓查询
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryRiskSettleInvstPosition(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryRiskSettleInvstPositionField * pQryRiskSettleInvstPosition, int nRequestID);

///风险结算产品查询
extern "C" CTP_API_EXPORT int CThostFtdcTraderApi_ReqQryRiskSettleProductStatus(CThostFtdcTraderApi * pCThostFtdcTraderApi, CThostFtdcQryRiskSettleProductStatusField * pQryRiskSettleProductStatus, int nRequestID);