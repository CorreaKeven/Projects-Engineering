/*
LINUX!!


Comandos do Shell:

ls 		-> Mostra arquivos do diretório
ls -l		-> Mostra diretorio com informações completas
ls -l -a	-> Mostra diretorio com arquivos ocultos, informações completas
mkdir		-> comando para criar diretorio
pwd 		-> Mostra qual é o diretório atual
ls xTAB		-> Completa o nome do arquivo que procuras 
ls /		-> Mostra os arquivos do diretório mais alto (nível /)
cd x		-> Vai para o diretório x
cd		-> Vai ao diretório o home do usuario
cd .		-> Vai para o diretório corrente (home)
cd ..		-> vai para o diretório acima
cd ~		-> Vai ao diretório o home do usuario (utilizado mais em comando de cópias)
man comando	-> Mostra o manual do comando
man função c	-> Mostra o manual da função c
top 		-> mostra processos e recursos usados
ps 		-> processos criados pelo shell corrente
ps ax		-> todos os processos
kill PID 	-> Mata o processo do numero PID xxxx
kill -15 PID 	-> default: sigterm pede para o processo terminar
kill -9 PID 	-> sigkill, mata o processo sem perguntar
tar cf x.tar x	-> c: criar, f: nomde do arquivo tar a seruir
tar xf arq.tar	-> x: extrai, f: nomde do arquivo tar a seruir
tar xfz x.tar.gz-> x: extrai, f: nomde do arquivo tar a seruir, z:gzip, j -> bzp2


 
Caracteres de escape do terminal
Ctrl c -> pede para terminar um programa em execução
Ctrl z -> suspende execução do programa sem descarregá-lo da memória
bg	-> Reinicia a execução como tarefa de funto
fg	-> Reinicia a execução como tarefa de frente

Compilação em gcc:
gedit x 			-> Abre o gedit e cria o nome do arquivo x sem extenção
gedit Aula11.c 			-> Abre o gedit e cria o nome do arquivo Aula11 com extenção .c
gedit Aula11.c &		-> Abre o gedit e cria o nome do arquivo Aula11 com extenção .c executando o gedit como processo de fundo
gcc prog.c			-> Gera um programa chamado a.out
gcc -o Aula11  -Wall Aula11.c	-> -o a seguir do nome do programa executável gerado. -Wall Ativa mensagens de warning


particularidades ls:
dudu@EdCury:~/Documentos/PUC/PPEE$ ls -l
total 164
-rwxrwxr-x 1 dudu dudu 7161 Mar 21 17:55 Aula1
...

-rwxrwxr-x -> r= read, w=write, x=execute;
rwx 	-> u -> user, dono do arquivo
rwx	-> g -> group
r-x	-> o -> outros
dudu	-> grupo
dudu	-> usuário

Pastas:

/
/bin 	-> Exexutáveis
/etc 	-> Config do sistema
/lib 	-> Bibliotecas
/dev 	-> Acesso a dispositivos
/home	-> diretorio home do usurio
/usr
/usr/bin
/usr/lib
/usr/include
/usr/etc
/usr/share
*/

#include <stdio.h>
int main()
{
int c;
while(c = getchar() != 1){
	putchar(c);
	}
return 0;
}
