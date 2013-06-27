/*
 * Type.hpp
 *
 *  Created on: Jun 18, 2013
 *      Author: desaic
 */

#ifndef TYPE_HPP_
#define TYPE_HPP_
#include <string>
namespace llvm{
class Type;
class Value;
class BasicBlock;
};
///@brief a class representing primitive types,
///arrays, and structs.
///By default, @typeId is AST_INVALID;
class AstType
{
public:
  enum AstTypeEnum{
    AST_VOID = 0,
    AST_DOUBLE,
    AST_FLOAT,
    AST_INT,
    AST_INT64,
    AST_INVALID
  };
  AstType();
  AstType(int _id);
  AstType(const AstType & ty);
  AstType & operator=(const AstType& ty);
  int getId()const;
  void set(int id);
  virtual ~AstType();
  llvm::Type * getLLVMType() const ;
  std::string toString()const;
private:
  int typeId;
};

///@brief not implemented
class StructType: public AstType
{
public:
  std::string name;
  StructType():AstType(AST_INVALID){}
  StructType(std::string * _name):
    AstType(AST_INVALID),name(*_name){}
};

bool needCast(const AstType * src, const AstType * dst);
llvm::Value * cast(const AstType * src, const AstType * dst,
    llvm::Value * S,llvm::BasicBlock *block);
#endif /* TYPE_HPP_ */
