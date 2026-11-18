#ifndef MODIFICADOR_ATRIBUTO_HPP
#define MODIFICADOR_ATRIBUTO_HPP

#include <string>

/**
 * @file ModificadorAtributo.hpp
 * @brief Estrutura de um modificador de atributo (Buff/Debuff) ativo.
 */

/**
 * @struct ModificadorAtributo
 * @brief Estrutura que define um efeito de Buff ou Debuff ativo em um Personagem.
 */
struct ModificadorAtributo {
    std::string nomeEfeito;   ///< Nome da habilidade que originou o modificador.
    std::string atributo;     ///< O atributo alvo da alteração ("forca" ou "defesa").
    int valor;                ///< Valor do modificador (positivo para Buff, negativo para Debuff).
    int turnosRestantes;      ///< Contador de turnos até o efeito expirar.
};

#endif // MODIFICADOR_ATRIBUTO_HPP
