#include "parser.h"
#include <cstddef>
#include <iterator>
#include <memory>
#include <vector>

namespace {
    ParseResult parse_expression(const std::vector<Token>& tokens, std::size_t& index);
    ParseResult parse_term(const std::vector<Token>& tokens, std::size_t& index);
    ParseResult parse_factor(const std::vector<Token>& tokens, std::size_t& index);

    ParseResult parse_factor(const std::vector<Token>& tokens, std::size_t& index)
    {
        ParseResult result;
        result.root = nullptr;

        if (index > tokens.size())
        {
            result.status = make_error("Unexpected end of input", 0);
            return result;
        }

        const Token& token = tokens[index];

        if (token.type == TokenType::Number)
        {
            auto node = std::make_unique<NumberNode>();
            node->type = AstNodeType::Number;
            node->position = token.position;
            node->value = token.value;

            ++index;

            result.root = std::move(node);
            result.status = make_ok();
            return result;
        }

        if (token.type == TokenType::LParen)
        {
            ++index;
            ParseResult inner = parse_expression(tokens, index);
            if (!is_ok(inner.status)) {
                return inner;
            }

            if (index >= tokens.size() || tokens[index].type != TokenType::RParen) {
                ParseResult error_result;
                error_result.root = nullptr;
                error_result.status = make_error("Expected ') '", token.position);
                return error_result;
            }
            ++index;
        }

        if (token.type == TokenType::Minus)
        {
            const std::size_t operator_position = token.position;
            ++index;

            ParseResult operand = parse_factor(tokens, index);
            if (!is_ok(operand.status)) {
                return operand;
            }

            auto node = std::make_unique<UnaryNode>();
            node->type = AstNodeType::Unary;
            node->position = operator_position;
            node->op = UnaryOperator::Negate;
            node->operand = std::move(operand.root);

            result.root = std::move(node);
            result.status = make_ok();
            return result;
        }
        result.status = make_error("Expected number, '(' or unary '-'", token.position);
        return result;
    }

    ParseResult parse_term(const std::vector<Token>& tokens, std::size_t& index) {
        ParseResult left = parse_factor(tokens, index);
        if (!is_ok(left.status)) {
            return left;
        }

        while (index < tokens.size() &&
               (tokens[index].type == TokenType::Star ||
                tokens[index].type == TokenType::Slash)) {
            const Token operator_token = tokens[index];
            ++index;

            ParseResult right = parse_factor(tokens, index);
            if (!is_ok(right.status)) {
                return right;
            }

            auto node = std::make_unique<BinaryNode>();
            node->type = AstNodeType::Binary;
            node->position = operator_token.position;
            node->op = (operator_token.type == TokenType::Star)
                ? BinaryOperator::Multiply
                : BinaryOperator::Divide;
            node->left = std::move(left.root);
            node->right = std::move(right.root);

            left.root = std::move(node);
            left.status = make_ok();
        }

        return left;
    }


    ParseResult parse_expression(const std::vector<Token>& tokens, std::size_t& index) {
        ParseResult left = parse_term(tokens, index);
        if (!is_ok(left.status)) {
            return left;
        }

        while (index < tokens.size() &&
               (tokens[index].type == TokenType::Plus ||
                tokens[index].type == TokenType::Minus)) {
            const Token operator_token = tokens[index];
            ++index;

            ParseResult right = parse_term(tokens, index);
            if (!is_ok(right.status)) {
                return right;
            }

            auto node = std::make_unique<BinaryNode>();
            node->type = AstNodeType::Binary;
            node->position = operator_token.position;
            node->op = (operator_token.type == TokenType::Plus)
                ? BinaryOperator::Add
                : BinaryOperator::Subtract;
            node->left = std::move(left.root);
            node->right = std::move(right.root);

            left.root = std::move(node);
            left.status = make_ok();
        }

        return left;
    }

}

ParseResult parse(const std::vector<Token>& tokens) {
    ParseResult result;
    result.root = nullptr;

    if (tokens.empty()) {
        result.status = make_error("Expected expression", 0);
        return result;
    }

    std::size_t index = 0;
    ParseResult expression_result = parse_expression(tokens, index);
    if (!is_ok(expression_result.status)) {
        return expression_result;
    }

    if (index >= tokens.size()) {
        result.status = make_error("Unexpected end of input", tokens.back().position);
        return result;
    }

    if (tokens[index].type != TokenType::End) {
        result.status = make_error("Unexpected trailing input", tokens[index].position);
        return result;
    }

    return expression_result;
}
