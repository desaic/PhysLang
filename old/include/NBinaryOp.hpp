/*
 * NBinaryOp.hpp
 *
 *  Created on: Jun 24, 2013
 *      Author: desaic
 */

#ifndef NBINARYOP_HPP_
#define NBINARYOP_HPP_

#include "NExpression.hpp"
class NBinaryOp : public NExpression {
public:
  NExpression* lhs;
  NExpression* rhs;
  int op;
  NBinaryOp(NExpression *_lhs, int op, NExpression* _rhs);
  virtual void updateType();
  virtual ~NBinaryOp();
  virtual llvm::Value* codeGen(CodeGenContext& context);
private:
  bool isArithmetic();
  llvm::Value * genBinOp(
      llvm::Value * vals[], const AstType * types[],CodeGenContext& context);
  llvm::Value * genCmpInst(
      const AstType & operandTy,llvm::Value * vals[],CodeGenContext& context);
  bool isComparison();
};
#endif /* NBINARYOP_HPP_ */

