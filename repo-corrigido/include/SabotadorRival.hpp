#ifndef SABOTADOR_RIVAL_HPP
#define SABOTADOR_RIVAL_HPP

#include "Inimigo.hpp"
#include <string>

/**
 * @file SabotadorRival.hpp
 * @brief Declaração do inimigo SabotadorRival.
 */

/**
 * @class SabotadorRival
 * @brief Agente que usa táticas de guerrilha urbana com explosivos e químicos.
 *
 * O mais perigoso dos incomuns — baixo HP mas arsenal devastador:
 * - Coquetel Molotov todo turno (ESPECIAL).
 * - Queimadura Química todo turno (DOT, 3 turnos).
 * - Gás Paralisante a cada 3 turnos (DEBUFF de força no alvo, 2 turnos).
 * - Explosão Total a cada 5 turnos (ULTRA — perfura o escudo do jogador completamente).
 *
 * @invariant _nivel >= 1
 * @invariant _contadorTurnos >= 0
 */
class SabotadorRival : public Inimigo {
public:
    /**
     * @brief Constrói um Sabotador Rival para um determinado nível.
     * @param nome Nome do inimigo (usa "Sabotador Rival" se vazio).
     * @param nivel Nível de escalonamento dos atributos (deve ser >= 1).
     * @throws std::invalid_argument Se nivel < 1.
     */
    explicit SabotadorRival(std::string nome, int nivel);

    /**
     * @brief Executa o turno com arsenal químico-explosivo completo.
     *
     * Rotação:
     * - Todo turno: Coquetel Molotov (ESPECIAL) + Queimadura Química (DOT, 3 turnos).
     * - A cada 3 turnos: Gás Paralisante adicional (DEBUFF de força, 2 turnos).
     * - A cada 5 turnos: Explosão Total (ULTRA) substitui o Molotov — perfura o escudo.
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

#endif // SABOTADOR_RIVAL_HPP
