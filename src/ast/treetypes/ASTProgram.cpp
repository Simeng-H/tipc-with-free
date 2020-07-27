#include "ASTProgram.h"
#include "ASTVisitor.h"
#include "ASTinternal.h"

std::vector<ASTFunction*> ASTProgram::getFunctions() {
  return rawRefs(FUNCTIONS);
}

ASTFunction * ASTProgram::findFunctionByName(std::string name) {
    for(auto fn : getFunctions()) {
        if(fn->getName() == name) {
            return fn;
        }
    }
    return nullptr;
}

void ASTProgram::accept(ASTVisitor * visitor) {
  if (visitor->visit(this)) {
    for (auto f : getFunctions()) {
      f->accept(visitor);
    }
  }
  visitor->endVisit(this);
}
