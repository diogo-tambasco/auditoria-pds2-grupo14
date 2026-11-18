#ifndef COMBATE_INVALIDO_EXCEPTION_HPP
#define COMBATE_INVALIDO_EXCEPTION_HPP

#include <stdexcept>
#include <string>

/**
 * @file CombateInvalidoException.hpp
 * @brief Exceção lançada quando um combate não pode começar.
 */

/**
 * @class CombateInvalidoException
 * @brief Exceção lançada quando o estado dos combatentes impede o início do combate.
 *
 * Exemplos de situações inválidas:
 * - Tentar iniciar um combate com um combatente já morto.
 * - Combatente nulo passado por referência inválida.
 */
class CombateInvalidoException : public std::logic_error {
public:
    /**
     * @brief Cria a exceção com a mensagem informada.
     * @param mensagem Descrição do problema.
     */
    explicit CombateInvalidoException(const std::string& mensagem)
        : std::logic_error("[Combate] " + mensagem) {}
};

#endif // COMBATE_INVALIDO_EXCEPTION_HPP
