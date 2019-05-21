O jogo acompanha um mapa de teste chamado 'mapa.txt' (bem simples soh pra testar a abertura e escrita do arquivo).
Para que a execucao ocorra de forma satisfatoria todos os arquivos devem estar no mesmo diretorio.

O arquivo personagem.c eh somente um rascunho de structs e nao esta sendo utilizado no momento.
Caso alguma modificacao seja feita em um dos arquivos execute o comando abaixo:

gcc jogo -o jogo.c main.c

para executar o jogo em um terminal de linux execute o comando abaixo:

./jogo mapa.txt


ESTADO ATUAL DO JOGO:

	No momento o jogo ja abre o mapa no terminal e plota.
	Tambem ja esta criado a struct personagem juntamente com a movimentacao do mesmo pelo mapa.
