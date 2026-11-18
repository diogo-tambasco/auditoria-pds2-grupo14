#ifndef ESCOLHA_HPP
#define ESCOLHA_HPP

#include <string>

/**
 * @file Escolha.hpp
 * @brief Estrutura de uma opção (aresta) do grafo narrativo.
 */

/** * @struct Escolha 
 * @brief Define uma ramificação (opção) direcionada a partir de uma cena da história.
 * * Cada escolha atua como uma aresta em um grafo narrativo, conectando a cena atual
 * a um novo nó (destino), além de carregar metadados que podem modificar o estado do jogo.
 */
struct Escolha {
    std::string texto;       ///< Texto descritivo exibido no menu de opções para o jogador.
    int destinoID;           ///< ID identificador da próxima cena para onde o jogador será direcionado.
    bool geraCombate;        ///< Flag indicando se a seleção desta opção engatilha um combate imediato.
    std::string tipoInimigo; ///< String identificadora do monstro a ser gerado caso @c geraCombate seja true.
    int itemGanhoID;         ///< ID do item concedido ao jogador (0 se nenhum bônus for aplicado, >0 para itens válidos).
};

#endif // ESCOLHA_HPP
