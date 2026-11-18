#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "Personagem.hpp"
#include "Habilidade.hpp"
#include <string>
#include <vector>

/**
 * @file Inimigo.hpp
 * @brief Declaração da classe base abstrata Inimigo.
 */

/**
 * @class Inimigo
 * @brief Classe base para todas as entidades hostis do jogo.
 *
 * Acrescenta a Personagem o contador de turnos (usado pela IA de cada inimigo)
 * e a recompensa de XP entregue ao jogador na vitória.
 */
class Inimigo : public Personagem {
public:
    /** @brief Destrutor virtual para garantir a destruição correta das subclasses. */
    virtual ~Inimigo() = default;

    /**
     * @brief Retorna a recompensa de XP concedida ao derrotar o inimigo.
     * @return Quantidade de XP (sempre >= 0).
     */
    int getXPRecompensa() const;

protected:
    /**
     * @brief Construtor da classe Inimigo.
     * @param nome Nome do inimigo.
     * @param hp Pontos de vida.
     * @param defesa Pontos de defesa.
     * @param forca Pontos de força.
     * @param nivel Nível do inimigo.
     * @param xp Experiência concedida ao derrotá-lo.
     */
    Inimigo(std::string nome, int hp, int defesa, int forca, int nivel, int xp);

    /**
     * @brief Valida que o nível de um inimigo é pelo menos 1.
     *
     * Compartilhado por todas as subclasses (antes era copiado em cada arquivo).
     * @param nivel Valor a validar.
     * @param contexto Nome da classe, usado na mensagem de erro.
     * @throws std::invalid_argument Se nivel < 1.
     */
    static void validarNivel(int nivel, const std::string& contexto);

    int _contadorTurnos;   ///< Contador de rodadas utilizado para gerenciar o padrão do monstro.
    int _xpRecompensa;     ///< Experiência concedida ao jogador.
};

#endif // INIMIGO_HPP
