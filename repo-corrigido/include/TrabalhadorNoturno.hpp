#ifndef TRABALHADOR_NOTURNO_HPP
#define TRABALHADOR_NOTURNO_HPP

#include "Inimigo.hpp"
#include <string>

/**
 * @file TrabalhadorNoturno.hpp
 * @brief Declaração do inimigo TrabalhadorNoturno.
 */

/**
 * @class TrabalhadorNoturno
 * @brief Oponente rápido e frágil, movido a pura exaustão.
 *
 * Possui pouquíssimo HP, mas tem alta chance de acerto crítico (dano dobrado).
 * Exige que o jogador o elimine rapidamente antes de levar rajadas de críticos.
 *
 * @invariant _nivel >= 1
 */
class TrabalhadorNoturno : public Inimigo {
public:
    /**
     * @brief Constrói um Trabalhador Noturno para um determinado nível.
     * @param nome Nome do inimigo (usa "Trabalhador Noturno Estressado" se vazio).
     * @param nivel Nível de escalonamento dos atributos (deve ser >= 1).
     * @throws std::invalid_argument Se nivel < 1.
     */
    explicit TrabalhadorNoturno(std::string nome, int nivel);

    /**
     * @brief Executa o turno: 40% de chance de crítico (dano x2), senão ataque normal.
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

#endif // TRABALHADOR_NOTURNO_HPP
