#pragma once

#include "ASTFunction.h"

// ASTProgram - a name and a list of functions
class ASTProgram {
  std::string name;
  std::vector<std::unique_ptr<ASTFunction>> FUNCTIONS;
public:
  ASTProgram(std::vector<std::unique_ptr<ASTFunction>> FUNCTIONS)
      : FUNCTIONS(std::move(FUNCTIONS)) {}
  void setName(std::string n) { name = n; }
  std::string getName() { return name; }
  std::vector<ASTFunction*> getFunctions();
  ASTFunction * findFunctionByName(std::string);
  void accept(ASTVisitor * visitor);
  std::unique_ptr<llvm::Module> codegen(std::string name);
};
