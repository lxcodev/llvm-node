import * as llvm from "../../";

test("can call initialize functions", () => {
  llvm.initializeAllTargetInfos();
  llvm.initializeAllTargets();
  llvm.initializeAllTargetMCs();
  llvm.initializeAllAsmParsers();
  llvm.initializeAllAsmPrinters();

  llvm.initializeNativeTarget();
  llvm.initializeNativeTargetAsmParser();
  llvm.initializeNativeTargetAsmPrinter();
});
