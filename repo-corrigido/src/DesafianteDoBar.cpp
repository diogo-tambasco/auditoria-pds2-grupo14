#include "DesafianteDoBar.hpp"
#include "InterfaceJogo.hpp"
#include <cstdlib>   // rand()
#include <stdexcept>
#include <string>

DesafianteDoBar::DesafianteDoBar(std::string nome, int nivel)
    : Inimigo(
        nome.empty() ? "Desafiante do Bar" : nome,
        /*hp*/     150,
        /*defesa*/  15,
        /*forca*/   15,
        nivel,
        /*xp*/      60)
{
    validarNivel(nivel, "DesafianteDoBar");

    // Arsenal: apenas soco bruto — sem habilidades especiais
    adicionarHabilidade(Habilidade(
        "Soco Bêbado",
        TipoHabilidade::FISICO,
        /*custoE*/ 0, /*custoMP*/ 0,
        /*valor*/  _forcaBase,
        /*atributo*/ ""));
}

void DesafianteDoBar::executarTurno(Personagem& alvo) {
    if (!alvo.estaVivo()) return;

    processarEfeitosContinuos();
    if (!estaVivo()) return;

    _contadorTurnos++;

    InterfaceJogo::exibirTexto("\n👊 [ATAQUE FÍSICO] " + _nome + " avança cambaleando com um Soco Bêbado!");
    alvo.receberDano(_forcaBase, TipoHabilidade::FISICO);
}

std::string DesafianteDoBar::getDeclaracaoStatus() const {
    std::string status = "🍺 [INIMIGO COMUM: Desafiante] 🍺\n";
    status += "=======================================================\n";
    status += " 👤 NOME : " + this->getNome() + " [Nível " + std::to_string(this->getNivel()) + "]\n";
    status += "=======================================================\n";
    status += " ❤️ HP    : " + std::to_string(_hp) + " / " + std::to_string(_hpMax) + "\n";
    status += " ⚔️ FORÇA : " + std::to_string(_forcaBase) + " (Soco Bêbado)\n";
    status += " 🛡️ DEFESA: " + std::to_string(_defesaBase) + "\n";
    status += "=======================================================";
    return status;
}
