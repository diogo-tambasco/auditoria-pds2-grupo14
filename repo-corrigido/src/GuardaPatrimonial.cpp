#include "GuardaPatrimonial.hpp"
#include "InterfaceJogo.hpp"
#include <stdexcept>
#include <string>

GuardaPatrimonial::GuardaPatrimonial(std::string nome, int nivel)
    : Inimigo(
        nome.empty() ? "Guarda Patrimonial" : nome,
        /*hp*/     300,
        /*defesa*/ 40,   // alta defesa física e mágica (equipamento completo)
        /*forca*/  25,
        nivel,
        /*xp*/     400)
{
    validarNivel(nivel, "GuardaPatrimonial");

    // Ataque físico com cassetete
    adicionarHabilidade(Habilidade(
        "Cassetete",
        TipoHabilidade::FISICO,
        0, 0, _forcaBase, ""));

    // DEBUFF: atordoamento — força cai drasticamente por 1 turno
    adicionarHabilidade(Habilidade(
        "Atordoamento",
        TipoHabilidade::DEBUFF,
        0, 0, 12 * nivel, "forca", 1));

    // DEBUFF: gás lacrimogêneo — reduz defesa do alvo por 2 turnos
    adicionarHabilidade(Habilidade(
        "Gás Lacrimogêneo",
        TipoHabilidade::DEBUFF,
        0, 0, 8 * nivel, "defesa", 2));

    // HOT: bandagem de campo — cura contínua em si mesmo por 2 turnos
    adicionarHabilidade(Habilidade(
        "Bandagem de Campo",
        TipoHabilidade::HOT,
        0, 0, 6 * nivel, "", 2));
}

void GuardaPatrimonial::executarTurno(Personagem& alvo) {
    if (!alvo.estaVivo()) return;

    processarEfeitosContinuos();
    if (!estaVivo()) return;

    _contadorTurnos++;

    // A cada 5 turnos: Bandagem de Campo — HOT em si mesmo (maior prioridade)
    if (_contadorTurnos % 5 == 0) {
        InterfaceJogo::exibirTexto(
            _nome + " abre o kit de primeiros socorros rapidamente — "
            "Bandagem de Campo! Recuperando HP por 2 turnos.");
        aplicarHoT("Bandagem de Campo", 6 * _nivel, 2);
        // Ainda ataca no mesmo turno
        InterfaceJogo::exibirTexto(
            _nome + " avança sem hesitar!");
        alvo.receberDano(_forcaBase, TipoHabilidade::FISICO);
        return;
    }

    // A cada 4 turnos: Gás Lacrimogêneo — debuff de defesa no alvo
    if (_contadorTurnos % 4 == 0) {
        InterfaceJogo::exibirTexto(
            _nome + " dispara o spray de gás lacrimogêneo — "
            "Sua defesa cai por 2 turnos!");
        alvo.aplicarDebuff("Gás Lacrimogêneo", "defesa", 8 * _nivel, 2);
        return;
    }

    // A cada 3 turnos: Atordoamento — debuff de força severo por 1 turno
    if (_contadorTurnos % 3 == 0) {
        InterfaceJogo::exibirTexto(
            _nome + " acerta um golpe preciso no crânio — "
            "Atordoamento! Sua força cai drasticamente por 1 turno!");
        alvo.aplicarDebuff("Atordoamento", "forca", 12 * _nivel, 1);
        return;
    }

    // Turno padrão: Cassetete
    InterfaceJogo::exibirTexto(
        _nome + " avança com o cassetete!");
    alvo.receberDano(_forcaBase, TipoHabilidade::FISICO);
}

std::string GuardaPatrimonial::getDeclaracaoStatus() const {
    std::string status = "🛡️ 🚨 [INIMIGO INCOMUM: Guarda] 🛡️\n";
    status += "=======================================================\n";
    status += " 👤 NOME : " + this->getNome() + " [Nível " + std::to_string(this->getNivel()) + "]\n";
    status += " ⚕️ EXTRA : Kit de Primeiros Socorros & Controle de Área\n";
    status += "=======================================================\n";
    status += " ❤️ HP    : " + std::to_string(_hp) + " / " + std::to_string(_hpMax) + "\n";
    status += " ⚔️ FORÇA : " + std::to_string(_forcaBase) + "\n";
    status += " 🛡️ DEFESA: " + std::to_string(_defesaBase) + " (Blindagem Balística)\n";
    status += "=======================================================";
    return status;
}
