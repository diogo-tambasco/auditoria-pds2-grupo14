#include "RecrutaDoutrinado.hpp"
#include "InterfaceJogo.hpp"
#include <stdexcept>
#include <string>

RecrutaDoutrinado::RecrutaDoutrinado(std::string nome, int nivel)
    : Inimigo(
        nome.empty() ? "Recruta Doutrinado" : nome,
        /*hp*/     300,
        /*defesa*/ 30,   // alta defesa física — força uso de ESPECIAL
        /*forca*/  35,
        nivel,
        /*xp*/     400)
{
    validarNivel(nivel, "RecrutaDoutrinado");

    // Ataque físico padrão
    adicionarHabilidade(Habilidade(
        "Soco Treinado",
        TipoHabilidade::FISICO,
        0, 0, _forcaBase, ""));

    // DOT: sangramento físico por 3 turnos
    adicionarHabilidade(Habilidade(
        "Sangramento",
        TipoHabilidade::DOT,
        0, 0, 4 * nivel, "", 3));

    // SUPORTE: buff de força em si mesmo por 2 turnos (doutrinação amplifica a raiva)
    adicionarHabilidade(Habilidade(
        "Grito de Doutrina",
        TipoHabilidade::SUPORTE,
        0, 0, 5 * nivel, "forca", 2));

    // DEBUFF: reduz defesa do alvo por 2 turnos (quebra a guarda para o próximo golpe)
    adicionarHabilidade(Habilidade(
        "Intimidação",
        TipoHabilidade::DEBUFF,
        0, 0, 6 * nivel, "defesa", 2));
}

void RecrutaDoutrinado::executarTurno(Personagem& alvo) {
    if (!alvo.estaVivo()) return;

    processarEfeitosContinuos();
    if (!estaVivo()) return;

    _contadorTurnos++;

    // A cada 5 turnos: Intimidação — debuff de defesa no alvo (maior prioridade)
    if (_contadorTurnos % 5 == 0) {
        InterfaceJogo::exibirTexto(
            _nome + " invade seu espaço e grita na sua cara — Intimidação! "
            "Sua defesa cai por 2 turnos!");
        alvo.aplicarDebuff("Intimidação", "defesa", 6 * _nivel, 2);
        return;
    }

    // A cada 4 turnos: Grito de Doutrina — buff de força em si mesmo
    if (_contadorTurnos % 4 == 0) {
        InterfaceJogo::exibirTexto(
            _nome + " recita as regras do clube em voz alta — "
            "Grito de Doutrina! Sua força aumenta por 2 turnos!");
        aplicarBuff("Grito de Doutrina", "forca", 5 * _nivel, 2);
        // Ainda ataca no mesmo turno com a força potencializada
        InterfaceJogo::exibirTexto(
            _nome + " avança com vigor redobrado!");
        alvo.receberDano(_forcaBase, TipoHabilidade::FISICO);
        return;
    }

    // A cada 2 turnos: Sangramento — DoT físico por 3 turnos
    if (_contadorTurnos % 2 == 0) {
        InterfaceJogo::exibirTexto(
            _nome + " rasga um corte profundo — Sangramento aplicado!");
        alvo.aplicarDoT("Sangramento", 4 * _nivel, 3);
        return;
    }

    // Turno padrão: Soco Treinado
    InterfaceJogo::exibirTexto(
        _nome + " avança sem recuar, ignorando a própria dor!");
    alvo.receberDano(_forcaBase, TipoHabilidade::FISICO);
}

std::string RecrutaDoutrinado::getDeclaracaoStatus() const {
    std::string status = "📢 [INIMIGO INCOMUM: Recruta] 📢\n";
    status += "=======================================================\n";
    status += " 👤 NOME : " + this->getNome() + " [Nível " + std::to_string(this->getNivel()) + "]\n";
    status += " ⚔️ ESTILO: Pressão Física Crítica (Buffs/Debuffs de Turno)\n";
    status += "=======================================================\n";
    status += " ❤️ HP    : " + std::to_string(_hp) + " / " + std::to_string(_hpMax) + "\n";
    status += " ⚔️ FORÇA : " + std::to_string(_forcaBase) + "\n";
    status += " 🛡️ DEFESA: " + std::to_string(_defesaBase) + " (Alta Resistência)\n";
    status += "=======================================================";
    return status;
}
