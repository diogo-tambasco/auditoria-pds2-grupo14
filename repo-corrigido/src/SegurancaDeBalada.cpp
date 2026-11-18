#include "SegurancaDeBalada.hpp"
#include "InterfaceJogo.hpp"
#include <cstdlib>   // rand()
#include <stdexcept>
#include <string>

SegurancaDeBalada::SegurancaDeBalada(std::string nome, int nivel)
    : Inimigo(
        nome.empty() ? "Segurança de Balada" : nome,
        /*hp*/     140,   // mais HP que os outros comuns
        /*defesa*/  25,   // resistente fisicamente
        /*forca*/   15,
        nivel,
        /*xp*/     200)
{
    validarNivel(nivel, "SegurancaDeBalada");

    adicionarHabilidade(Habilidade(
        "Empurrão de Segurança",
        TipoHabilidade::FISICO,
        0, 0,
        _forcaBase,
        ""));
}

void SegurancaDeBalada::executarTurno(Personagem& alvo) {
    if (!alvo.estaVivo()) return;

    processarEfeitosContinuos();
    if (!estaVivo()) return;

    _contadorTurnos++;

    // A cada 3 turnos assume postura defensiva (ativa o escudo interno)
    if (_contadorTurnos % 3 == 0) {
        _escudoAtivo = true;
        InterfaceJogo::exibirTexto("\n🛡️  [POSTURA] " + _nome + " cruza os braços e finca a base!");
        InterfaceJogo::exibirTexto("    > Escudo Ativo: Impacto de ataques comuns mitigado pela metade até a próxima rodada.");
    }

    InterfaceJogo::exibirTexto("\n💥 [ATAQUE] " + _nome + " projeta o corpo à frente com um Empurrão de Segurança!");
    alvo.receberDano(_forcaBase, TipoHabilidade::FISICO);
}

std::string SegurancaDeBalada::getDeclaracaoStatus() const {
    std::string status = "🕴️ 🛑 [INIMIGO COMUM: Segurança] 🕴️\n";
    status += "=======================================================\n";
    status += " 👤 NOME : " + this->getNome() + " [Nível " + std::to_string(this->getNivel()) + "]\n";
    status += " 🛡️ ESCUDO: " + std::string(_escudoAtivo ? "ATIVADO (50% Mitigação)" : "Inativo") + "\n";
    status += "=======================================================\n";
    status += " ❤️ HP    : " + std::to_string(_hp) + " / " + std::to_string(_hpMax) + "\n";
    status += " ⚔️ FORÇA : " + std::to_string(_forcaBase) + "\n";
    status += " 🛡️ DEFESA: " + std::to_string(_defesaBase) + "\n";
    status += "=======================================================";
    return status;
}
