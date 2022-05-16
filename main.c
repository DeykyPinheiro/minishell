#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "shell.h"

int main(int argc, char **argv)
{
	char *cmd;
	// le o comando então for verdadeiro
	do
	{
		// imprime "> " e fica lendo
		print_prompt1();
		cmd = read_cmd();
		if(!cmd)
		{
			exit(EXIT_SUCCESS);
		}
		if(cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
		{
			free(cmd);
			continue;
		}
		if(strcmp(cmd, "exit\n") == 0)
		{
			free(cmd);
			break;
		}
		printf("%s\n", cmd);
		free(cmd);
	} while(1);
	exit(EXIT_SUCCESS);
}

// le o comando da CLI
char *read_cmd(void)
{
	// buffer para a leitura com tamanho 1024
	// ptr com o comando se ja for a segunda vez
	// tamanho do buffer lido até então
	char buf[1024];
	char *ptr = NULL;
	char ptrlen = 0;

	// le da entrada padrao 1024 casas, e salva no buff
	while(fgets(buf, 1024, stdin))
	{
		int buflen = strlen(buf);

		// cria um ponteiro caso não exista
		if (!ptr)
		{
			ptr = malloc(buflen+1);
		}
		else
		{
			// se ja existir, expande a memoria para o
			// tamanho inicial + o ponto atual
			char *ptr2 = realloc(ptr, ptrlen+buflen+1);
			if(ptr2)
			{
				ptr = ptr2;
			}
			else
			{
				free(ptr);
				ptr = NULL;
			}
		}

		// se o ptr não existir sai com o erro
		if(!ptr)
		{
			fprintf(stderr, "error: failed to alloc buffer: %s\n",
					strerror(errno));
			return NULL;
		}

		// copia o novo buffer no ptr + ptrlen(que a posicao atual)
		strcpy(ptr+ptrlen, buf);


		// verifica o a ultma posicao se for '\n'
		// se só tiver uma posicao ou se for '\\' retorna o ponteiro
		// se não imprime o modo interativo e continuar recebendo
		// so termina o comando quando recebe um enter se não fica concatenando
		if(buf[buflen-1] == '\n')
		{
			if (buflen == 1 || buf[buflen-2] != '\\')
			{
				return ptr;
			}

			ptr[ptrlen+buflen-2] = '\0';
			buflen -= 2;
			print_prompt2();
		}
		ptrlen += buflen;
	}

	return ptr;
}
