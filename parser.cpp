#include "parser.h"
#include <cstddef>
#include <memory>
#include <vector>

namespace {
    ParseResult parse_expression(const std::vector<Token>& tokens, std::size_t& index);
    ParseResult parse_term(const std::vector<Token>& tokens, std::size_t& index);
    ParseResult parse_factor(const std::vector<Token>& tokens, std::size_t& index);

    ParseResult parse_factor(const std::vector<Token>& tokens, std::size_t& index) {
        ParseResult result;
        result.root = nullptr;

        if (index > tokens.size()) {
            result.status = make_error("Unexpected end of input", 0);
            return result;
        }

        const Token& token = tokens[index];

        if (token.type == TokenType::Number) {
            auto node = std::make_unique<NumberNode>();
            node->type = AstNodeType::Number;
            node->err_position = token.err_position;
            node->value = token.value;

            ++index;

            result.root = std::move(node);
            result.status = make_ok();
            return result;
        }

        if (token.type == TokenType::LParen) {
            ++index;
            ParseResult inner = parse_expression(tokens, index);
            if (!is_ok(inner.status)) {
                return inner;
            }

            if (index >= tokens.size() || tokens[index].type != TokenType::RParen) {
                ParseResult error_result;
                error_result.root = nullptr;
                error_result.status = make_error("Expected ') '", token.err_position);
                return error_result;
            }
            ++index;
        }

        if (token.type == TokenType::Minus) {
            const std::size_t operator_position = token.err_position;
            ++index;

            ParseResult operand = parse_factor(tokens, index);
            if (!is_ok(operand.status)) {
                return operand;
            }

            auto node = std::make_unique<UnaryNode>();
            node->type = AstNodeType::Unary;
            node->err_position = operator_position;
            node->op = UnaryOperator::Negate;
            node->operand = std::move(operand.root);

            result.root = std::move(node);
            result.status = make_ok();
            return result;
        }
        result.status = make_error("Expected number, '(' or unary '-'", token.err_position);
        return result;
    }

}
ParseResult parse(const std::vector<Token>& tokens) {
    (void)tokens;

    ParseResult result;
    result.root = nullptr;
    result.status = make_error("Parser not implemented yet.", 0);
    return result;
}
