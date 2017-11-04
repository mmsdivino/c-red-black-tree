# c-red-black-tree
An implementation of Red-Black Tree in C.

This code is a project for discipline Data Structures and Algorithms (MATA40) in Federal University of Bahia. Follow description in Portuguese.

## Árvores Vermelho-Preto

### Descrição Geral do Trabalho

Neste trabalho o aluno implementará uma árvore Vermelho-Preto. Cada nó da árvore possuirá uma chave, que terá um valor inteiro, a cor do nó (vermelho ou preto) e os apontadores necessários para outros nós da árvore. As chaves dos nós da árvore possuem valores distintos.

O programa terá como entrada um conjunto de operações a serem realizadas sobre a árvore. Os formatos de entrada e saída são descritos a seguir. O programa deve ler da entrada padrão e escrever os resultados na saída padrão.

### Formato da Entrada

A entrada constará de uma sequência de operações, terminada com uma operação de **término de sequência de operações**. As operações que podem ocorrer são:

1. **insere nó:** esta operação consiste de uma linha contendo a letra ’i’, seguida de um espaço, seguido de um número inteiro. Esta operação causa a inserção de um nó na árvore cuja chave será o número inteiro. Caso já haja nó na árvore com valor de chave igual a este número, a operação não gera efeito na árvore.

2. **consulta nó:** esta operação consiste de uma linha contendo a letra ’c’, seguida por um espaço, seguido por um valor inteiro. Esta operação verifica se há ou não nó na árvore com valor de chave igual ao número inteiro digitado.

3. **lista chaves dos nós da árvore em ordem:** esta operação consiste de uma linha contendo a letra ’p’, seguida de um espaço, seguido da letra ’c’ ou ’d’. Se a segunda letra é ’c’, esta operação lista as chaves dos nós da árvore em ordem crescente. Se a segunda letra for ’d’, esta operação lista as chaves dos nós da árvore em ordem decrescente.

4. **lista chaves de um determinado nível da árvore:** esta operação consiste de uma linha contendo a letra ’n’, seguida de um espaço, seguido de um número inteiro maior ou igual a 1. Esta operação lista as chaves dos nós da árvore que tiverem nível igual ao número fornecido. Assuma que a raiz da árvore possui nível 1.

5. **imprime árvore (percurso em ordem):** esta operação consiste de uma linha contendo a letra ’d’. Esta operação imprime a estrutura da árvore, seguindo um percurso em ordem.

6. **imprime árvore por nível (busca em largura):** esta operação consiste de uma linha contendo a letra ’l’. Esta operação imprime a estrutura da árvore, nível por nível, a partir da raiz.

7. **imprime altura:** esta operação consiste de uma linha contendo a letra ’a’. Esta operação apresenta a altura da árvore.

8. **término da sequência de operações:** a sequência de operações será terminada por uma linha com a letra ’e’.

### Formato da Saída

Cada operação deverá apresentar a saída da seguinte forma:

1. **insere nó:** esta operação não gera saída.

2. **consulta nó:** se houver nó na árvore com chave igual ao valor inteiro digitado, esta operação gera, na saída, a sequência de caracteres ’existe no com chave: ’ seguida pelo valor da chave. Caso não haja, esta operação gera, na saída, a sequência de caracteres ’nao existe no com chave: ’, seguida pelo valor da chave.

3. **lista chaves dos nós da árvore em ordem:** esta operação lista as chaves dos nós, na ordem determinada, uma em cada linha.

4. **lista chaves dos nós de um determinado nível da árvore:** esta operação lista as chaves dos nós, uma em cada linha. A sequência das chaves dos nós listados deve seguir a ordem da representação gráfica da árvore, da esquerda para a direita.

5. **imprime árvore (percurso em ordem):** esta operação listará os valores referentes a cada nó, um por linha, seguindo a ordem de visita de um percurso em ordem da árvore. Para cada nó, os dados devem ser apresentados no seguinte formato: a sequência de caracteres *’chave:’*, seguida de um espaço, seguido do valor da chave armazenada no nó, seguido de um espaço, seguido pela sequência de caracteres *’cor:’*, seguida por um espaço, seguido pela sequência de caracteres *vermelho* ou *preto*, dependendo da cor do nó, seguida por um espaço, seguido pela sequência de caracteres *’fesq:’*, seguida por um espaço, seguido pelo valor da chave armazenada no filho à esquerda, seguido por um espaço, seguido pela sequência de caracteres *’fdir:’*, seguida por um espaço, seguido pelo valor da chave armazenada no filho à direita. Caso não haja filho à esquerda ou filho à direita, a sequência de caracteres *nil* deve ser gerada, no local correspondente à chave do filho.

6. **imprime árvore (busca em largura):** esta operação listará os valores referentes a cada nó, um por linha, nível por nível, a partir da raiz (busca em largura). Os dados a serem apresentados são os mesmos do item acima.

Apenas a sequência de apresentação dos nós é diferente. Para os nós de um mesmo nível, a ordem de apresentação dos nós deve seguir a ordem da esquerda para a direita, considerando-se uma representação gráfica da árvore.

7. **imprime altura:** esta operação apresenta um valor natural (maior ou igual a zero), correspondente à altura da árvore. Considere que o nível da raiz é 1. Uma árvore com apenas um nó possui, com isto, altura 1.

8. **término da sequência de operações:** esta operação não gera saída.

**Importante:** o programa não deve gerar nenhum caractere a mais na saída, além dos indicados acima.

Não deve haver espaço entre linhas na saída.