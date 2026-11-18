#include "SabotadorRival.hpp"
#include "InterfaceJogo.hpp"
#include <stdexcept>
#include <string>

SabotadorRival::SabotadorRival(std::string nome, int nivel)
    : Inimigo(
        nome.empty() ? "Sabotador Rival" : nome,
        /*hp*/     300,   // frágil — eliminar rapidamente
        /*defesa*/  20,
        /*forca*/  45,   // dano altíssimo
        nivel,
        /*xp*/     400)
{
    validarNivel(nivel, "SabotadorRival");

    // ESPECIAL: explosivo direto — dano mágico padrão
    adicionarHabilidade(Habilidade(
        "Coquetel Molotov",
        TipoHabilidade::ESPECIAL,
        0, 0, _forcaBase, ""));

    // DOT: queimadura química por 3 turnos
    adicionarHabilidade(Habilidade(
        "Queimadura Química",
        TipoHabilidade::DOT,
        0, 0, 5 * nivel, "", 3));

    // DEBUFF: gás paralisante — reduz força do alvo por 2 turnos
    adicionarHabilidade(Habilidade(
        "Gás Paralisante",
        TipoHabilidade::DEBUFF,
        0, 0, 10 * nivel, "forca", 2));

    // ULTRA: explosão total — perfura escudo completamente, dano máximo
    adicionarHabilidade(Habilidade(
        "Explosão Total",
        TipoHabilidade::ULTRA,
        0, 0, _forcaBase * 2, ""));
}

void SabotadorRival::executarTurno(Personagem& alvo) {
    if (!alvo.estaVivo()) return;

    processarEfeitosContinuos();
    if (!estaVivo()) return;

    _contadorTurnos++;

    // A cada 5 turnos: EXPLOSÃO TOTAL (ULTRA) — substitui o Molotov, perfura escudo
    if (_contadorTurnos % 5 == 0) {
        InterfaceJogo::exibirTexto(
            "\n[PERIGO] " + _nome + " detona tudo que tem — EXPLOSÃO TOTAL! "
            "Nenhum escudo vai te proteger disso!");
        alvo.receberDano(_forcaBase * 2, TipoHabilidade::ULTRA);

        // Queimadura se aplica normalmente após a explosão
        InterfaceJogo::exibirTexto(
            _nome + " deixa o ambiente em chamas — Queimadura Química aplicada!");
        alvo.aplicarDoT("Queimadura Química", 5 * _nivel, 3);
        return;
    }

    // A cada 3 turnos: Gás Paralisante adicional — debuff de força por 2 turnos
    if (_contadorTurnos % 3 == 0) {
        InterfaceJogo::exibirTexto(
            _nome + " arremessa uma granada de gás — "
            "Gás Paralisante! Sua força cai por 2 turnos!");
        alvo.aplicarDebuff("Gás Paralisante", "forca", 10 * _nivel, 2);
    }

    // Turno padrão (sempre acontece se não for turno múltiplo de 5): Molotov + Queimadura
    InterfaceJogo::exibirTexto(
        _nome + " arremessa um explosivo improvisado!");
    alvo.receberDano(_forcaBase, TipoHabilidade::ESPECIAL);

    InterfaceJogo::exibirTexto(
        _nome + " derrama ácido — Queimadura Química aplicada!");
    alvo.aplicarDoT("Queimadura Química", 5 * _nivel, 3);
}

std::string SabotadorRival::getDeclaracaoStatus() const {
    std::string status = "💣 🔥 [INIMIGO INCOMUM: Sabotador] 🔥 💣\n";
    status += "=======================================================\n";
    status += " 👤 NOME : " + this->getNome() + " [Nível " + std::to_string(this->getNivel()) + "]\n";
    status += " 🚨 ALERTA: Alto Dano Elemental (Foco em Queimaduras e ULTRA)\n";
    status += "=======================================================\n";
    status += " ❤️ HP    : " + std::to_string(_hp) + " / " + std::to_string(_hpMax) + " (Frágil)\n";
    status += " ⚔️ FORÇA : " + std::to_string(_forcaBase) + " (Dano Explosivo Puro)\n";
    status += " 🛡️ DEFESA: " + std::to_string(_defesaBase) + "\n";
    status += "=======================================================";
    return status;
}
