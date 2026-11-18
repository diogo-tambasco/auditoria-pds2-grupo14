#include "Inimigo.hpp"
#include <stdexcept>
#include <string>

// ============================================================================
// CONSTRUTOR
// ============================================================================

Inimigo::Inimigo(std::string nome, int hp, int defesa, int forca, int nivel, int xp)
    : Personagem(nome, hp, defesa, forca, nivel), _contadorTurnos(0), _xpRecompensa(xp) {}

// ============================================================================
// MÉTODOS
// ============================================================================

int Inimigo::getXPRecompensa() const {
    return _xpRecompensa;
}

void Inimigo::validarNivel(int nivel, const std::string& contexto) {
    if (nivel < 1) {
        throw std::invalid_argument(
            contexto + ": nivel deve ser >= 1, recebido: " + std::to_string(nivel));
    }
}
