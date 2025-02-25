#pragma once

#include "ASTExpr.h"
#include "ASTStmt.h"

/*! \brief Class for free expression
 */
class ASTFreeStmt : public ASTStmt {
    std::shared_ptr<ASTExpr> ARG;
public:
  std::vector<std::shared_ptr<ASTNode>> getChildren() override;
  ASTFreeStmt(std::unique_ptr<ASTExpr> ARG) : ARG(std::move(ARG)) {}
  ASTExpr* getArg() const { return ARG.get(); }
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;

protected:
  std::ostream& print(std::ostream &out) const override;
};
