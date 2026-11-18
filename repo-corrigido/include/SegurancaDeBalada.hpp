#ifndef SEGURANCA_DE_BALADA_HPP
#define SEGURANCA_DE_BALADA_HPP

#include "Inimigo.hpp"
#include <string>

/**
 * @file SegurancaDeBalada.hpp
 * @brief Declaração do inimigo SegurancaDeBalada.
 */

/**
 * @class SegurancaDeBalada
 * @brief Brutamontes que tenta bloquear o acesso a áreas restritas.
 *
 * Possui mais HP que os outros comuns e foca em resistência física.
 * A cada 3 turnos assume postura defensiva (escudo), absorvendo metade do dano.
 * Serve como teste de resistência física do jogador.
 *
 * @invariant _nivel >= 1
 * @invariant _contadorTurnos >= 0
 */
class SegurancaDeBalada : public Inimigo {
public:
    /**
     * @brief Constrói um Segurança de Balada para um determinado nível.
     * @param nome Nome do inimigo (usa "Segurança de Balada" se vazio).
     * @param nivel Nível de escalonamento dos atributos (deve ser >= 1).
     * @throws std::invalid_argument Se nivel < 1.
     */
    explicit SegurancaDeBalada(std::string nome, int nivel);

    /**
     * @brief Executa o turno: ataque físico padrão; a cada 3 turnos ativa escudo defensivo.
     * @param alvo Personagem que receberá o dano.
     * @pre alvo referencia um Personagem válido.
     */
    void executarTurno(Personagem& alvo) override;
    /**
     * @brief Monta o status do inimigo para exibir no combate.
     * @return Texto com nome, nível e HP, pronto para imprimir.
     */
    std::string getDeclaracaoStatus() const override;
};

#endif // SEGURANCA_DE_BALADA_HPP
