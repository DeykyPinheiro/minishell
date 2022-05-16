#include <stdio.h>
#include "shell.h"

// imprime "$ " para poder receber o comando
void print_prompt1(void)
{
	fprintf(stderr, "$ ");
}

// imprime "> " para poder receber o comando
void print_prompt2(void)
{
	fprintf(stderr, "> ");
}
