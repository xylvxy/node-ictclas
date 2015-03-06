#include <node.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace v8;


#ifdef WIN32
    #pragma comment(lib, "NLPIR.lib")
#else
    #include<pthread.h>
    #define OS_LINUX
#endif
#include "NLPIR.h"

Handle<Value> initICTCLAS(const Arguments& args) {
	HandleScope scope;
	Handle<Value> arg = args[0];
  String::Utf8Value initDir(arg);
  bool initRst = NLPIR_Init(*initDir, UTF8_CODE);
  if(!initRst){
    NLPIR_Exit();
  	ThrowException(Exception::TypeError(String::New("initial failure")));
  }
  return scope.Close(Undefined());
}

Handle<Value> importDictFile(const Arguments& args) {
  HandleScope scope;
  Handle<Value> arg = args[0];
  String::Utf8Value dictFile(arg);
  FILE *fp;
  fp = fopen(*dictFile, "r");
  if(fp == NULL){
    ThrowException(Exception::TypeError(String::New("can not open the dict file")));
    return scope.Close(False());
  }
  unsigned wordCount = 0;//ICTCLAS_ImportUserDictFile(*dictFile, CODE_TYPE_UTF8);
  return scope.Close(Number::New(wordCount));
}

Handle<Value> segment(const Arguments& args) {
  HandleScope scope;
  Handle<Value> arg0 = args[0];
  String::Utf8Value txt(arg0);
  const char* sRst = ICTCLAS_ParagraphProcess(*txt);
  return scope.Close(String::New(sRst));
}

Handle<Value> segmentA(const Arguments& args) {
  HandleScope scope;
  Handle<Value> arg0 = args[0];
  String::Utf8Value txt(arg0);
  const char* sRst = ICTCLAS_ParagraphProcess(*txt);
  return scope.Close(String::New(sRst));
}
void Init(Handle<Object> target) {
  NODE_SET_METHOD(target, "init", initICTCLAS);
  NODE_SET_METHOD(target, "segment", segment);
  NODE_SET_METHOD(target, "segmentA", segmentA);
  NODE_SET_METHOD(target, "importDictFile", importDictFile);
}

NODE_MODULE(ictclas, Init)