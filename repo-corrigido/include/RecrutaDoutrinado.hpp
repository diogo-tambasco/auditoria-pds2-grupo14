#ifndef RECRUTA_DOUTRINADO_HPP
#define RECRUTA_DOUTRINADO_HPP

#include "Inimigo.hpp"
#include <string>

/**
 * @file RecrutaDoutrinado.hpp
 * @brief Declaração do inimigo RecrutaDoutrinado.
 */

/**
 * @class RecrutaDoutrinado
 * @brief Membro intermediário do Projeto Mayhem que já passou pela iniciação.
 *
 * Comportamento misto de agressor físico e lutador psicológico:
 * - Ataque físico padrão (FISICO).
 * - Sangramento a cada 2 turnos (DOT).
 * - Buff de força em si mesmo a cada 4 turnos (SUPORTE) — a doutrinação intensifica a raiva.
 * - Debuff de defesa no jogador a cada 5 turnos (DEBUFF) — desequilibra para o próximo golpe.
 *
 * @invariant _nivel >= 1
 * @invariant _contadorTurnos >= 0
 */
class RecrutaDoutrinado : public Inimigo {
public:
    /**
     * @brief Constrói um Recruta Doutrinado para um determinado nível.
     * @param nome Nome do inimigo (usa "Recruta Doutrinado" se vazio).
     * @param nivel Nível de escalonamento dos atributos (deve ser >= 1).
     * @throws std::invalid_argument Se nivel < 1.
     */
    explicit RecrutaDoutrinado(std::string nome, int nivel);

    /**
     * @brief Executa o turno com rotação de 4 habilidades distintas baseada no contador.
     *
     * Rotação:
     * - Turno padrão: Soco Treinado (FISICO).
     * - A cada 2 turnos: Sangramento (DOT, 3 turnos).
     * - A cada 4 turnos: Grito de Doutrina (SUPORTE — buff de força em si, 2 turnos).
     * - A cada 5 turnos: Intimidação (DEBUFF — reduz defesa do alvo, 2 turnos).
     *
     * @param alvo Personagem que receberá os efeitos do turno.
     * @pre alvo referencia um Personagem válido.
     */
    void executarTurno(Personagem& alvo) override;
    /**
     * @brief Monta o status do inimigo para exibir no combate.
     * @return Texto com nome, nível e HP, pronto para imprimir.
     */
    std::string getDeclaracaoStatus() const override;
};

#endif // RECRUTA_DOUTRINADO_HPP
