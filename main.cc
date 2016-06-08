
#include <iostream>
#include <node.h>
#include <windows.h>

#if defined(__GNUG__)
    constexpr auto COMPILER_NAME = "g++";
#elif defined(_MSC_VER)
    constexpr auto COMPILER_NAME = "msvc";
#endif

namespace addon {

    using std::cout;
    using std::endl;
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;

    void alert(const FunctionCallbackInfo<Value> &args) {
        Isolate *isolate = args.GetIsolate();
        auto title = (LPCWSTR) *String::Value(args[0]->ToString());
        auto content = (LPCWSTR) *String::Value(args[1]->ToString());
        MessageBoxW(0, content, title, MB_OK | MB_ICONINFORMATION);

    }

    void getCompilerName(const FunctionCallbackInfo<Value> &args) {
        Isolate *isolate = args.GetIsolate();
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, COMPILER_NAME));
    }

    void init(Local<Object> exports) {
        NODE_SET_METHOD(exports, "alert", alert);
        NODE_SET_METHOD(exports, "getCompilerName", getCompilerName);
    }

    NODE_MODULE(main, init)

}
