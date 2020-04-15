#include "native-addon.h"
#include <iostream>

Napi::Object NativeAddon::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "NativeAddon", {
    InstanceMethod("RunCallback", &NativeAddon::RunCallback),
    InstanceMethod("RunMathCallback", &NativeAddon::RunMathCallback)
  });

  exports.Set("NativeAddon", func);
  return exports;
}

NativeAddon::NativeAddon(const Napi::CallbackInfo& info) 
: Napi::ObjectWrap<NativeAddon>(info)  { }


Napi::Value NativeAddon::RunCallback(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "You need to pass an argument!")
          .ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsFunction()) {
        Napi::TypeError::New(env, "You need to pass a function as a callback!")
          .ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::Function callbackFn = info[0].As<Napi::Function>();
    return callbackFn.Call({});
}

Napi::Value NativeAddon::RunMathCallback(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "You need to pass an argument!")
          .ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsFunction()) {
        Napi::TypeError::New(env, "You need to pass a function as a callback!")
          .ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[1].IsNumber() || !info[2].IsNumber()) {
        Napi::TypeError::New(env, "You need to pass a Number as a callback parameter!")
          .ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::Function callbackFn = info[0].As<Napi::Function>();
    Napi::Number firstArg = info[1].As<Napi::Number>();
    Napi::Number secondArg = info[2].As<Napi::Number>();
    return callbackFn.Call({
      firstArg,
      secondArg,
    });
}
