#ifndef EFEITO_POR_TEMPO_HPP
#define EFEITO_POR_TEMPO_HPP

#include <string>
#include "Habilidade.hpp"

/**
 * @file EfeitoPorTempo.hpp
 * @brief Estrutura de um efeito contínuo (DoT, HoT, Buff, Debuff).
 */

/**
 * @brief Estrutura que define as propriedades de um efeito de dano contínuo (DoT).
 * * Mantém os dados necessários para que efeitos como veneno, queimadura ou 
 * sangramento persistam na memória do alvo por múltiplos turnos.
 */
struct EfeitoPorTempo {
    TipoHabilidade tipo;       /**< DOT, HOT, SUPORTE (Buff) ou DEBUFF */
    int valorPorTurno;         /**< Dano, Cura ou o valor do modificador de atributo */
    int turnosRestantes;       /**< Contador de rodadas ativo */
    std::string nomeEfeito;    /**< Ex: "Veneno", "Regeneração", "Grito de Guerra" */
    std::string atributoAfetado; /**< [NOVO] "hp", "defesa" ou "forca" (Útil para Buffs/Debuffs) */
};

#endif // EFEITO_POR_TEMPO_HPP
