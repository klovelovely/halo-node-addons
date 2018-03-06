// hello.cc
#include <node.h>

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void _haloAllo(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Kavalon :3"));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "haloAllo", _haloAllo);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo