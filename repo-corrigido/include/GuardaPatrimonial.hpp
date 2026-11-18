#ifndef GUARDA_PATRIMONIAL_HPP
#define GUARDA_PATRIMONIAL_HPP

#include "Inimigo.hpp"
#include <string>

/**
 * @file GuardaPatrimonial.hpp
 * @brief Declaração do inimigo GuardaPatrimonial.
 */

/**
 * @class GuardaPatrimonial
 * @brief Vigilante que protege prédios corporativos durante a noite.
 *
 * Combina resistência com kit de campo:
 * - Ataque físico com cassetete (FISICO).
 * - Atordoamento a cada 3 turnos (DEBUFF severo de força por 1 turno).
 * - Gás Lacrimogêneo a cada 4 turnos (DEBUFF de defesa no alvo por 2 turnos).
 * - Bandagem de Campo a cada 5 turnos (HOT — cura contínua em si mesmo por 2 turnos).
 *
 * @invariant _nivel >= 1
 * @invariant _contadorTurnos >= 0
 */
class GuardaPatrimonial : public Inimigo {
public:
    /**
     * @brief Constrói um Guarda Patrimonial para um determinado nível.
     * @param nome Nome do inimigo (usa "Guarda Patrimonial" se vazio).
     * @param nivel Nível de escalonamento dos atributos (deve ser >= 1).
     * @throws std::invalid_argument Se nivel < 1.
     */
    explicit GuardaPatrimonial(std::string nome, int nivel);

    /**
     * @brief Executa o turno com rotação de 4 habilidades distintas baseada no contador.
     *
     * Rotação:
     * - Turno padrão: Cassetete (FISICO).
     * - A cada 3 turnos: Atordoamento (DEBUFF de força severo, 1 turno).
     * - A cada 4 turnos: Gás Lacrimogêneo (DEBUFF de defesa, 2 turnos).
     * - A cada 5 turnos: Bandagem de Campo (HOT em si mesmo, 2 turnos).
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

#endif // GUARDA_PATRIMONIAL_HPP
