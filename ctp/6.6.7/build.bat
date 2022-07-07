cd /d %~dp0

cl /O2 -I. /DCTP_VERSION=6.6.7 /DISLIB /DWIN32 /DLIB_CTP_API_EXPORT /LD /MT /Fe..\..\wrap\wrap.dll ..\..\wrap\wrap.cpp thosttraderapi_se.lib thostmduserapi_se.lib 

swig -c++ -go -intgosize 64 ..\..\swig\ctp.i
g++ -o..\..\swig\ctpwrapgo.o -c -m64 -I. -I..\..\swig ..\..\swig\ctp_wrap.cxx
gcc -o..\..\swig\string_array.o -c -m64 ..\..\swig\string_array.c
ar -crv ..\..\swig\libctpwrapgo.a ..\..\swig\ctpwrapgo.o ..\..\swig\string_array.o
del ..\..\swig\ctpwrapgo.o
del ..\..\swig\string_array.o
move ..\..\swig\ctp.go ..\..\ctp_windows.go
cd ..\..
go install -x