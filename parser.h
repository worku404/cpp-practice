@pragma once
#include <cstddef>
#include <memory>

enum class AstNodeType {
    Number,
    Unary,
    Binary
};

enum class UnaryOperator{
    Negate
};

enum class BinaryOperator{
    Add,
    Subtract,
    Multiply,
    Divide
};

// Base class
struct AstNode {
    virtual ~AstNode() = default;
    AstNodeType type;
    std::size_t err_position;
};

struct NumberNode : AstNode {
    long long value;
};

struct UnaryNode: AstNode {
    UnaryOperator op;
    std::unique_ptr<AstNode> operand;
};

struct BinaryNode : AstNode {
    BinaryOperator op;
    std::unique_ptr<AstNode> left;
    std::unique_ptr<AstNode> right;
};
