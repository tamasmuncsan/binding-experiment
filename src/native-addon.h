#include <napi.h>

class NativeAddon : public Napi::ObjectWrap<NativeAddon> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        NativeAddon(const Napi::CallbackInfo& info);

    private:
        Napi::Value RunCallback(const Napi::CallbackInfo& info);
        Napi::Value RunMathCallback(const Napi::CallbackInfo& info);
};
