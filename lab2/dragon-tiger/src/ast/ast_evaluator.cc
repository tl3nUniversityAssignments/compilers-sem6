#include "ast_evaluator.hh"
#include "../utils/errors.hh"

namespace ast {

int32_t ASTEvaluator::visit(const IntegerLiteral& node) {
    return node.value;
}

int32_t ASTEvaluator::visit(const StringLiteral& node) {
    utils::error(node.loc, "string literals not supported in evaluator");
    return 0;
}

int32_t ASTEvaluator::visit(const BinaryOperator& node) {
    int32_t left = node.get_left().accept(*this);
    int32_t right = node.get_right().accept(*this);

    switch (node.op) {
        case o_plus: return left + right;
        case o_minus: return left - right;
        case o_times: return left * right;
        case o_divide: 
            if (right == 0) {
                utils::error(node.loc, "division by zero");
            }
            return left / right;
        case o_eq: return left == right;
        case o_neq: return left != right;
        case o_lt: return left < right;
        case o_le: return left <= right;
        case o_gt: return left > right;
        case o_ge: return left >= right;
        default:
            utils::error(node.loc, "unsupported operator");
    }
}

int32_t ASTEvaluator::visit(const Sequence& node) {
    const auto exprs = node.get_exprs();
    if (exprs.empty()) {
        utils::error(node.loc, "empty sequence not allowed in evaluator");
    }
    int32_t result = 0;
    for (auto expr : exprs) {
        result = expr -> accept(*this);
    }
    return result;
}

int32_t ASTEvaluator::visit(const Let& node) {
    utils::error(node.loc, "let expressions not supported in evaluator");
    return 0;
}

int32_t ASTEvaluator::visit(const Identifier& node) {
    utils::error(node.loc, "identifiers not supported in evaluator");
    return 0;
}

int32_t ASTEvaluator::visit(const IfThenElse& node) {
    int32_t condition = node.get_condition().accept(*this);

    if (condition) {
        return node.get_then_part().accept(*this);
    } else {
        const auto& else_part = node.get_else_part();
        if (dynamic_cast<const Sequence*>(&else_part) && 
            dynamic_cast<const Sequence*>(&else_part)->get_exprs().empty()) {
            return 0;
        }
        return else_part.accept(*this);
    }
}

int32_t ASTEvaluator::visit(const VarDecl& node) {
    utils::error(node.loc, "variable declarations not supported in evaluator");
    return 0;
}

int32_t ASTEvaluator::visit(const FunDecl& node) {
    utils::error(node.loc, "function declarations not supported in evaluator");
    return 0;
}

int32_t ASTEvaluator::visit(const FunCall& node) {
    utils::error(node.loc, "function calls not supported in evaluator");
    return 0;
}

int32_t ASTEvaluator::visit(const WhileLoop& node) {
    utils::error(node.loc, "while loops not supported in evaluator");
    return 0;
}

int32_t ASTEvaluator::visit(const ForLoop& node) {
    utils::error(node.loc, "for loops not supported in evaluator");
    return 0;
}

int32_t ASTEvaluator::visit(const Break& node) {
    utils::error(node.loc, "break statements not supported in evaluator");
    return 0;
}

int32_t ASTEvaluator::visit(const Assign& node) {
    utils::error(node.loc, "assignments not supported in evaluator");
    return 0;
}

} // namespace ast