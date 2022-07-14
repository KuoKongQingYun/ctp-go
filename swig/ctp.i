%module(directors="1") ctp
%{
#include <iconv.h>
#include "ThostFtdcMdApi.h"
#include "ThostFtdcTraderApi.h"
#include "../../wrap/wrap.h"
#include "string_array.h"
%}

%insert(cgo_comment)
%{
#cgo CFLAGS:-fvisibility=hidden -O2
#cgo amd64 CFLAGS: -m64
#cgo amd64 LDFLAGS: -L${SRCDIR}/swig -L${SRCDIR}/wrap
#cgo CFLAGS: -I${SRCDIR}/swig
#cgo LDFLAGS: -static -lctpwrapgo -lwrap -liconv -lstdc++
%}

%insert(cgo_comment_typedefs)
%{
#include <stdlib.h>
#include "string_array.h"
%}

%typemap(out,fragment="AllocateString") char[ANY], char[] 
%{
    if ($1) {
        iconv_t cd = iconv_open("utf-8", "gb2312");
        if (cd != (iconv_t)-1) {
            char **in = &$1;
            size_t inlen = strlen($1);
            size_t buflen = inlen*2;
            size_t outlen = buflen;
            char *buf = (char *)malloc(buflen);
            char *out = buf;
            if (iconv(cd, in, &inlen, &out, &outlen) != static_cast<size_t>(-1))
			{
				size_t size = buflen - outlen;
				$result = Swig_AllocateString(buf, size);
			}
            iconv_close(cd);
            free(buf);
        }
    }else{
        $result = Swig_AllocateString(NULL, 0);
    }
%}
%typemap(gotype) (char** ppInstrumentID, int nCount) "[]string"
%typemap(imtype) (char** ppInstrumentID, int nCount) "*C.StringArray"
%typemap(goin) (char** ppInstrumentID, int nCount)
%{
    length := len($input)
    stringArray := C.newStringArray(C.int(length))
    defer C.deleteStringArray(stringArray)
    for i, s := range $input {
        cstring := C.CString(s)
        C.setStringArray(stringArray, C.int(i),cstring)
        C.free(unsafe.Pointer(cstring))
    }
    $result = stringArray
%}
%typemap(in) (char** ppInstrumentID, int nCount)
%{
    StringArray* t = (StringArray*)$input ;
    $1 = t->pArray;
    $2 = t->nSize;
%}
%typemap(argout) (char **ppInstrumentID, int nCount) ""


%feature("director") CThostFtdcMdSpi; 
%feature("director") CThostFtdcTraderSpi;
// %ignore CThostFtdcMdApi;
// %ignore CThostFtdcTraderApi;
%ignore THOST_FTDC_VTC_BankBankToFuture;
%ignore THOST_FTDC_VTC_BankFutureToBank;
%ignore THOST_FTDC_VTC_FutureBankToFuture;
%ignore THOST_FTDC_VTC_FutureFutureToBank;
%ignore THOST_FTDC_FTC_BankLaunchBankToBroker;
%ignore THOST_FTDC_FTC_BrokerLaunchBankToBroker;
%ignore THOST_FTDC_FTC_BankLaunchBrokerToBank;
%ignore THOST_FTDC_FTC_BrokerLaunchBrokerToBank;
%include "ThostFtdcUserApiDataType.h"
%include "ThostFtdcUserApiStruct.h"
%include "ThostFtdcMdApi.h"
%include "ThostFtdcTraderApi.h"
%include "../../wrap/wrap.h"