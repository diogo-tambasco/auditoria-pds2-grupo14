#ifndef ENTRADA_SIMULADA_HPP
#define ENTRADA_SIMULADA_HPP

#include <iostream>
#include <sstream>
#include <string>

/**
 * @file EntradaSimulada.hpp
 * @brief Ajudante de teste que substitui o teclado (std::cin) por um texto fixo.
 */

/**
 * @class EntradaSimulada
 * @brief Troca o buffer de std::cin por um texto enquanto o objeto existir (RAII).
 *
 * Sem isso, testes que chamam InterfaceJogo::solicitarEscolha ou Combate::iniciar
 * ficam esperando alguém digitar, e o `make test` nunca termina.
 *
 * Uso:
 * @code
 * EntradaSimulada entrada("2\n");
 * int escolha = InterfaceJogo::solicitarEscolha({"A", "B"}); // devolve 2
 * @endcode
 */
class EntradaSimulada {
public:
    /**
     * @brief Passa a ler std::cin a partir do texto informado.
     * @param texto Tudo o que o "usuário" vai digitar, com '\n' entre as linhas.
     */
    explicit EntradaSimulada(const std::string& texto)
        : _buffer(texto), _original(std::cin.rdbuf(_buffer.rdbuf())) {
        std::cin.clear();
    }

    /** @brief Devolve o teclado original e limpa as flags de erro do std::cin. */
    ~EntradaSimulada() {
        std::cin.rdbuf(_original);
        std::cin.clear();
    }

    EntradaSimulada(const EntradaSimulada&) = delete;
    EntradaSimulada& operator=(const EntradaSimulada&) = delete;

    /**
     * @brief Gera várias linhas iguais (útil para combates longos).
     * @param linha Conteúdo de cada linha, sem o '\n'.
     * @param vezes Quantidade de repetições.
     * @return Texto com a linha repetida, uma por linha.
     */
    static std::string repetir(const std::string& linha, int vezes) {
        std::string texto;
        for (int i = 0; i < vezes; i++) texto += linha + "\n";
        return texto;
    }

private:
    std::istringstream _buffer;   ///< Texto que faz o papel do teclado.
    std::streambuf* _original;    ///< Buffer original de std::cin, restaurado no destrutor.
};

#endif // ENTRADA_SIMULADA_HPP
