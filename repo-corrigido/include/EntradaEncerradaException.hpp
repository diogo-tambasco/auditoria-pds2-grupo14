#ifndef ENTRADA_ENCERRADA_EXCEPTION_HPP
#define ENTRADA_ENCERRADA_EXCEPTION_HPP

#include <stdexcept>
#include <string>

/**
 * @file EntradaEncerradaException.hpp
 * @brief Exceção para entrada do usuário encerrada (EOF).
 */

/**
 * @class EntradaEncerradaException
 * @brief Exceção lançada quando a entrada do usuário termina (EOF, Ctrl+D ou arquivo redirecionado acabou).
 *
 * Sem ela, InterfaceJogo::solicitarEscolha ficava em loop infinito pedindo uma
 * opção que nunca chegaria. Combate não engole esta exceção: ela sobe até a main,
 * que encerra o jogo de forma limpa.
 */
class EntradaEncerradaException : public std::runtime_error {
public:
    /**
     * @brief Cria a exceção com a mensagem informada.
     * @param mensagem Descrição do motivo do encerramento.
     */
    explicit EntradaEncerradaException(const std::string& mensagem)
        : std::runtime_error("[Entrada] " + mensagem) {}
};

#endif // ENTRADA_ENCERRADA_EXCEPTION_HPP
