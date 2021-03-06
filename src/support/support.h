#ifndef SUPPORT_H
#define SUPPORT_H
#include <nan.h>

#include "target-registry.h"

NAN_METHOD(InitializeAllTargetInfos);
NAN_METHOD(InitializeAllTargets);
NAN_METHOD(InitializeAllTargetMCs);
NAN_METHOD(InitializeAllAsmParsers);
NAN_METHOD(InitializeAllAsmPrinters);

NAN_METHOD(InitializeNativeTarget);
NAN_METHOD(InitializeNativeTargetAsmParser);
NAN_METHOD(InitializeNativeTargetAsmPrinter);

NAN_MODULE_INIT(InitSupport);

#endif