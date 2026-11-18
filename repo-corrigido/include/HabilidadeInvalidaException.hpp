#ifndef HABILIDADE_INVALIDA_EXCEPTION_HPP
#define HABILIDADE_INVALIDA_EXCEPTION_HPP

#include <stdexcept>
#include <string>

/**
 * @file HabilidadeInvalidaException.hpp
 * @brief Exceção lançada quando uma Habilidade é construída com parâmetros inválidos.
 */

/**
 * @class HabilidadeInvalidaException
 * @brief Exceção lançada quando os parâmetros de construção de uma Habilidade são inválidos.
 *
 * Herda de std::invalid_argument para ser compatível com o tratamento genérico
 * de exceções de argumento inválido da STL.
 */
class HabilidadeInvalidaException : public std::invalid_argument {
public:
    /**
     * @brief Cria a exceção com a mensagem informada.
     * @param mensagem Descrição do problema.
     */
    explicit HabilidadeInvalidaException(const std::string& mensagem)
        : std::invalid_argument("[Habilidade] " + mensagem) {}
};

#endif // HABILIDADE_INVALIDA_EXCEPTION_HPP
