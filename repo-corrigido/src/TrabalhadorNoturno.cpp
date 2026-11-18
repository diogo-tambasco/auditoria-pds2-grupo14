#include "TrabalhadorNoturno.hpp"
#include "InterfaceJogo.hpp"
#include <cstdlib>   // rand()
#include <stdexcept>
#include <string>

TrabalhadorNoturno::TrabalhadorNoturno(std::string nome, int nivel)
    : Inimigo(
        nome.empty() ? "Trabalhador Noturno Estressado" : nome,
        /*hp*/     150,   // frágil
        /*defesa*/  15,
        /*forca*/  20,   // alto, mas compensa com pouco HP
        nivel,
        /*xp*/     90)
{
    validarNivel(nivel, "TrabalhadorNoturno");

    adicionarHabilidade(Habilidade(
        "Surto de Raiva",
        TipoHabilidade::FISICO,
        0, 0,
        _forcaBase,
        ""));

    adicionarHabilidade(Habilidade(
        "Golpe Crítico (Adrenalina)",
        TipoHabilidade::FISICO,
        0, 0,
        _forcaBase * 2,   // dano dobrado no crítico
        ""));
}

void TrabalhadorNoturno::executarTurno(Personagem& alvo) {
    if (!alvo.estaVivo()) return;

    processarEfeitosContinuos();
    if (!estaVivo()) return;

    _contadorTurnos++;

    // 40% de chance de crítico
    const bool critico = (rand() % 100) < 40;

    if (critico) {
        InterfaceJogo::exibirTexto("\n🚨 💥 [GOLPE CRÍTICO] " + _nome + " entra em colapso de raiva e ativa Surto de Raiva!");
        alvo.receberDano(_forcaBase * 2, TipoHabilidade::FISICO);
    } else {
        InterfaceJogo::exibirTexto("\n👊 [ATAQUE FÍSICO] " + _nome + " desfere um soco desesperado de exaustão!");
        alvo.receberDano(_forcaBase, TipoHabilidade::FISICO);
    }
}

std::string TrabalhadorNoturno::getDeclaracaoStatus() const {
    std::string status = "🕒 😤 [INIMIGO COMUM: Trabalhador Noturno] 🕒\n";
    status += "=======================================================\n";
    status += " 👤 NOME : " + this->getNome() + " [Nível " + std::to_string(this->getNivel()) + "]\n";
    status += " 🚨 STATUS: Estressado (40% de chance de Crítico x2)\n";
    status += "=======================================================\n";
    status += " ❤️ HP    : " + std::to_string(_hp) + " / " + std::to_string(_hpMax) + "\n";
    status += " ⚔️ FORÇA : " + std::to_string(_forcaBase) + "\n";
    status += " 🛡️ DEFESA: " + std::to_string(_defesaBase) + "\n";
    status += "=======================================================";
    return status;
}
