# Auditoria e correções: PDS2-2026-PF-grupo14

Auditoria do projeto final do Grupo 14 de PDS2 (RPG textual com tema de Fight Club), usando os critérios de avaliação da disciplina, e uma cópia com as correções aplicadas.

Repositório original: https://github.com/WillianJunior/PDS2-2026-PF-grupo14 (commit auditado `1f2eb64`).

## Resultado

| | Antes | Depois |
|---|---|---|
| `make test` termina sozinho | Não (trava esperando o teclado) | Sim |
| Testes passando | 78 de 83 | 88 de 88 |
| Cobertura de linhas | 75% (sem os 5 testes travados) | 83% Linux · 85% macOS |
| Arquivos com mais de uma classe | 6 | 0 |
| Documentação Doxygen | Vazia | 37 páginas de classe, 0 avisos |

## O que tem aqui

- `correcoes.html`: explicação completa de cada arquivo alterado, o motivo da mudança e os conselhos. Baixe e abra no navegador.
- `AUDITORIA.md`: a auditoria do código original, critério por critério.
- `repo/`: o código original, sem alterações.
- `repo-corrigido/`: a cópia com as correções. Para conferir: `make clean && make test`.
- `repo-corrigido/doc/html/index.html`: a documentação Doxygen gerada.
- `mudancas.diff`: todas as mudanças entre `repo/` e `repo-corrigido/`.
- `evidencias/`: saída completa do `make test` no Linux (g++ 13) e no macOS (clang).
- `jogo_saida.txt`: uma partida automática completa, do início ao fim.

## O que fica com o grupo

1. Preencher nome, usuário do GitHub e e-mail nos arquivos `20250xxxxx.txt`. A nota individual conta os commits que batem com esses dados.
2. Usar o mesmo nome e e-mail no git em todas as máquinas.
3. Aplicar as correções em commits pequenos, um por problema.
4. Rodar `make clean && make test` uma vez em Linux antes de entregar.
