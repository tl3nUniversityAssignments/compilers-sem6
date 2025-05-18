#ifndef AST_EVALUATOR_HH
#define AST_EVALUATOR_HH

#include "nodes.hh"
#include "../utils/errors.hh"

namespace ast {

class ASTEvaluator : public ConstASTIntVisitor {
public:
    ASTEvaluator() = default;
    virtual ~ASTEvaluator() = default;

    int32_t visit(const IntegerLiteral &node) override;    
    int32_t visit(const StringLiteral &node) override;
    int32_t visit(const BinaryOperator &node) override;    
    int32_t visit(const Sequence &node) override;    
    int32_t visit(const Let &node) override;
    int32_t visit(const Identifier &node) override;
    int32_t visit(const IfThenElse &node) override;   
    int32_t visit(const VarDecl &node) override;
    int32_t visit(const FunDecl &node) override;
    int32_t visit(const FunCall &node) override;
    int32_t visit(const WhileLoop &node) override;
    int32_t visit(const ForLoop &node) override;
    int32_t visit(const Break &node) override;
    int32_t visit(const Assign &node) override;
};

}

#endif