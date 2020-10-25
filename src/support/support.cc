#include <llvm/Support/TargetSelect.h>
#include "support.h"

NAN_METHOD(InitializeAllTargetInfos) {
    llvm::InitializeAllTargetInfos();
}

NAN_METHOD(InitializeAllTargets) {
    llvm::InitializeAllTargets();
}

NAN_METHOD(InitializeAllTargetMCs) {
    llvm::InitializeAllTargetMCs();
}

NAN_METHOD(InitializeAllAsmParsers) {
    llvm::InitializeAllAsmParsers();
}

NAN_METHOD(InitializeAllAsmPrinters) {
    llvm::InitializeAllAsmPrinters();
}

NAN_METHOD(InitializeNativeTarget) {
    llvm::InitializeNativeTarget();
}

NAN_METHOD(InitializeNativeTargetAsmParser) {
    llvm::InitializeNativeTargetAsmParser();
}

NAN_METHOD(InitializeNativeTargetAsmPrinter) {
    llvm::InitializeNativeTargetAsmPrinter();
}

NAN_MODULE_INIT(InitSupport) {
    Nan::Set(target, 
        Nan::New<v8::String>("initializeAllTargetInfos").ToLocalChecked(),
        Nan::GetFunction(Nan::New<v8::FunctionTemplate>(InitializeAllTargetInfos)).ToLocalChecked()
    );

    Nan::Set(target, 
        Nan::New<v8::String>("initializeAllTargets").ToLocalChecked(),
        Nan::GetFunction(Nan::New<v8::FunctionTemplate>(InitializeAllTargets)).ToLocalChecked()
    );

     Nan::Set(target, 
        Nan::New<v8::String>("initializeAllTargetMCs").ToLocalChecked(),
        Nan::GetFunction(Nan::New<v8::FunctionTemplate>(InitializeAllTargetMCs)).ToLocalChecked()
    );

     Nan::Set(target, 
        Nan::New<v8::String>("initializeAllAsmParsers").ToLocalChecked(),
        Nan::GetFunction(Nan::New<v8::FunctionTemplate>(InitializeAllAsmParsers)).ToLocalChecked()
    );

     Nan::Set(target, 
        Nan::New<v8::String>("initializeAllAsmPrinters").ToLocalChecked(),
        Nan::GetFunction(Nan::New<v8::FunctionTemplate>(InitializeAllAsmPrinters)).ToLocalChecked()
    );

    Nan::Set(target, 
        Nan::New<v8::String>("initializeNativeTarget").ToLocalChecked(),
        Nan::GetFunction(Nan::New<v8::FunctionTemplate>(InitializeNativeTarget)).ToLocalChecked()
    );

     Nan::Set(target, 
        Nan::New<v8::String>("initializeNativeTargetAsmParser").ToLocalChecked(),
        Nan::GetFunction(Nan::New<v8::FunctionTemplate>(InitializeNativeTargetAsmParser)).ToLocalChecked()
    );

     Nan::Set(target, 
        Nan::New<v8::String>("initializeNativeTargetAsmPrinter").ToLocalChecked(),
        Nan::GetFunction(Nan::New<v8::FunctionTemplate>(InitializeNativeTargetAsmPrinter)).ToLocalChecked()
    );

    TargetRegistryWrapper::Init(target);
    TargetWrapper::Init(target);
}