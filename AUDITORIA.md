# Auditoria — PDS2-2026-PF-grupo14

Repo: https://github.com/WillianJunior/PDS2-2026-PF-grupo14 · commit `1f2eb64` · auditado em 2026-11-18
Ambiente: macOS, Apple clang 21, gcovr 8.8. **Não testado em Linux/g++** (o corretor provavelmente usa Linux; vale rodar lá antes de entregar).

## Veredito

O projeto está bom e funciona: compila sem nenhum warning (`-Wall -Wextra`), o jogo roda do início ao fim, 78 testes passam.
O risco que pode custar mais pontos é um só: **`make test` trava**. Corrigido isso, a nota estimada sobe de ~20 para ~25 de 26.

## O que foi medido

| Medição | Resultado |
|---|---|
| Compilação do jogo | OK, 0 warnings |
| Jogo rodando com entrada automática (`1` em tudo) | Chega ao "FIM DA JORNADA", sem crash (saída em `jogo_saida.txt`) |
| `make test` | **Trava.** 5 testes ficam esperando o teclado; sem teclado (EOF) entram em loop infinito com 80% de CPU |
| Testes que não leem teclado | 78/78 passam, 161/161 asserções |
| Cobertura de linhas (sem os 5 testes travados) | **75%** (956/1272). Funções 86%, branches 36% |
| `new`/`delete` manual | Nenhum. Usa smart pointers no `MotorJogo` |
| User Stories | 10, todas com 3 a 5 critérios |
| Cartões CRC | 10 |

Cobertura por arquivo mais baixa: `Combate.cpp` 13%, `InterfaceJogo.cpp` 40%, `Aventureiro.cpp` 46% — exatamente as partes que leem teclado.

## Nota estimada pelos critérios

| Critério | Máx | Hoje | Por quê |
|---|---|---|---|
| User Stories | 3 | 3 | 10 stories, critérios dentro de 3–5 |
| Cartões CRC | 3 | 3 | 10 cartões, colaborações presentes. Conferir se todos têm responsabilidade de conhecimento (atributo) além de ação — `Combate` só tem ações |
| Documentação e estilo | 4 | 3 | README completo; Doxygen presente, mas quase nenhum `@return` (vários headers com 0) |
| Funcionamento | 4 | 2 | Jogo roda; `make test` não termina sozinho — "roda parcialmente" (-2) |
| Boas práticas OO | 6 | 4 | `InimigoComum.hpp` e `InimigoIncomum.hpp` têm 3 classes cada (-2) |
| Programação defensiva | 3 | 3 | Exceções próprias, validação de entrada. Falha: EOF no `solicitarEscolha` vira loop infinito |
| Testes de unidade | 3 | 2–3 | 75% se os testes rodarem; se o corretor não conseguir rodar `make test`, a cobertura não sai |
| **Total** | **26** | **~20–21** | |

## O que corrigir, em ordem de pontos

1. **`make test` não pode esperar teclado** (+2 a +3). Os testes `solicitarEscolha - Limite *` e os 3 `Cenário de ...`/`Garantia de não-interrupção` de `Combate` leem `std::cin`.
   Saída simples: nos testes, trocar a entrada antes de chamar:
   `std::istringstream in("1\n1\n1\n"); auto* old = std::cin.rdbuf(in.rdbuf()); ... std::cin.rdbuf(old);`
   Isso também sobe a cobertura de `Combate`, `InterfaceJogo` e `Aventureiro`.
2. **Loop infinito no EOF** em `InterfaceJogo::solicitarEscolha` (src/InterfaceJogo.cpp:36-47): se `std::cin.eof()`, lançar exceção em vez de repetir. Hoje, Ctrl+D no jogo também trava.
3. **Uma classe por arquivo** (+2). Separar `InimigoComum.hpp/.cpp` em `DesafianteDoBar`, `TrabalhadorNoturno`, `SegurancaDeBalada`; idem `InimigoIncomum` (`RecrutaDoutrinado`, `GuardaPatrimonial`, `SabotadorRival`). Por segurança, mover também as exceções (`CombateInvalidoException`, `HabilidadeInvalidaException`) para arquivos próprios. Structs simples (`Escolha`, `EfeitoPorTempo`) provavelmente passam, mas é o mesmo critério.
4. **`@return` no Doxygen** (+1) em todo método que retorna valor.
5. **Rodar em Linux/g++ uma vez** com `make clean && make test`, do jeito que o corretor vai rodar.

## Riscos fora da nota técnica

- **Nota individual por commits.** Os arquivos `20250xxxxx.txt` dizem que só contam commits "de acordo com os dados de usuário cadastrados acima" — mas **nenhum dos 5 arquivos tem dados acima** (nome, usuário do GitHub, e-mail). E os mesmos alunos commitaram com identidades diferentes: `Davi Costa`/`davicostaaa`, `Kaio Gomes Vieira`/`szkaio`, `Joao Pedro Guimaraes Carvalho`/`João Pedro Guimarães Carvalho`/`jpgcarvalho9876`. Preencher os dados nos .txt com todas as identidades usadas.
- **Binários versionados.** 23 arquivos de `build/` estão no git (inclusive o executável `jogo` e dados de cobertura antigos). Remover com `git rm -r --cached build` e pôr `build/` no `.gitignore` — senão o corretor pode ler cobertura velha.

## Organização do repositório

A estrutura já segue o pedido (`design/`, `include/`, `src/`, `tests/`, `Makefile`, `Doxyfile`). Não precisa reorganizar pastas. Só:
- Separar os arquivos com várias classes (item 3).
- Tirar `build/` e `.vscode/` do git.
- Juntar `notas.md`, `notas-C6.md`, `notas-C7.md` (4–9 linhas cada) num só ou apagar.
- Há dois templates de PR em `.github/` (`pr_template.md` e `PULL_REQUEST_TEMPLATE.md`); o GitHub só usa o segundo.

## Conteúdo desta pasta

- `AUDITORIA.md` — este relatório
- `repo/` — clone intocado do commit auditado
- `jogo_saida.txt` — saída de uma partida automática completa
