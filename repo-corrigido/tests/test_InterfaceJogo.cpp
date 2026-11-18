/**
 * @file test_InterfaceJogo.cpp
 * @brief Testes de unidade para a classe InterfaceJogo usando doctest (TDD).
 *
 * Como InterfaceJogo lida com I/O, os testes verificam que os métodos
 * existem e podem ser chamados sem causar erros (não lançam exceções).
 */

#include "doctest.h"
#include "InterfaceJogo.hpp"
#include "Aventureiro.hpp"
#include "EntradaEncerradaException.hpp"
#include "EntradaSimulada.hpp"

// =========================================================
// SUITE: InterfaceJogo - Métodos Estáticos
// =========================================================

TEST_SUITE("InterfaceJogo - Metodos estaticos") {

    TEST_CASE("exibirTexto não lança exceção com texto") {
        CHECK_NOTHROW(InterfaceJogo::exibirTexto("Texto de teste"));
    }

    TEST_CASE("exibirTexto com string vazia não lança exceção") {
        CHECK_NOTHROW(InterfaceJogo::exibirTexto(""));
    }

    TEST_CASE("exibirStatus não lança exceção") {
        Aventureiro a("Herói", 100, 5, 15);
        CHECK_NOTHROW(InterfaceJogo::exibirStatus(a));
    }

    TEST_CASE("limparTela não lança exceção") {
        CHECK_NOTHROW(InterfaceJogo::limparTela());
    }

    TEST_CASE("renderizarDivisor não lança exceção") {
        CHECK_NOTHROW(InterfaceJogo::renderizarDivisor());
    }

    TEST_CASE("solicitarEscolha devolve a opção digitada") {
        EntradaSimulada entrada("2\n");
        std::vector<std::string> opcoes = {"Atacar", "Defender", "Fugir"};
        CHECK(InterfaceJogo::solicitarEscolha(opcoes) == 2);
    }

    TEST_CASE("solicitarEscolha ignora número fora do intervalo e pede de novo") {
        EntradaSimulada entrada("0\n4\n-1\n3\n");
        std::vector<std::string> opcoes = {"Atacar", "Defender", "Fugir"};
        CHECK(InterfaceJogo::solicitarEscolha(opcoes) == 3);
    }

    TEST_CASE("solicitarEscolha ignora texto não numérico e pede de novo") {
        EntradaSimulada entrada("abc\nxyz\n1\n");
        std::vector<std::string> opcoes = {"Atacar", "Defender", "Fugir"};
        CHECK(InterfaceJogo::solicitarEscolha(opcoes) == 1);
    }

    TEST_CASE("solicitarEscolha lança exceção quando a entrada acaba (EOF)") {
        EntradaSimulada entrada("");
        std::vector<std::string> opcoes = {"Atacar", "Defender", "Fugir"};
        CHECK_THROWS_AS(InterfaceJogo::solicitarEscolha(opcoes), EntradaEncerradaException);
    }

    TEST_CASE("solicitarEscolha sem opções devolve 0 sem ler a entrada") {
        EntradaSimulada entrada("");
        CHECK(InterfaceJogo::solicitarEscolha({}) == 0);
    }

    TEST_CASE("pausar não trava quando a entrada acaba") {
        EntradaSimulada entrada("");
        CHECK_NOTHROW(InterfaceJogo::pausar());
    }
}
