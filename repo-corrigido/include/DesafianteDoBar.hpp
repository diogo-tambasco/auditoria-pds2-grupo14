#ifndef DESAFIANTE_DO_BAR_HPP
#define DESAFIANTE_DO_BAR_HPP

#include "Inimigo.hpp"
#include <string>

/**
 * @file DesafianteDoBar.hpp
 * @brief Declaração do inimigo DesafianteDoBar.
 */

/**
 * @class DesafianteDoBar
 * @brief Cidadão comum que frequenta os fundos do bar em busca de uma válvula de escape.
 *
 * Inimigo introdutório do Clube de Luta. Usa apenas dano físico bruto (socos e chutes),
 * tem baixa defesa física e nenhuma resistência mágica. Serve para o jogador aprender
 * a gerenciar HP e testar ataques básicos.
 *
 * @invariant _nivel >= 1
 * @invariant _hp >= 0 && _hp <= _hpMax
 */
class DesafianteDoBar : public Inimigo {
public:
    /**
     * @brief Constrói um Desafiante do Bar para um determinado nível.
     * @param nome Nome do inimigo (usa "Desafiante do Bar" se vazio).
     * @param nivel Nível de escalonamento dos atributos (deve ser >= 1).
     * @throws std::invalid_argument Se nivel < 1.
     */
    explicit DesafianteDoBar(std::string nome, int nivel);

    /**
     * @brief Executa o turno do Desafiante: sempre ataque físico direto.
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

#endif // DESAFIANTE_DO_BAR_HPP
