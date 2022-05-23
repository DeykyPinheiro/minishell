#ifndef SHELL_H
#define SHELL_H

// imprimir o caracter de recebimento
void	print_prompt1(void);
void	print_prompt2(void);

// receber o comando da CLI
char	*read_cmd(void);

int dump(int argc, char **argv);

struct builtin_s
{
    char *name;
    int (*func)(int argc, char **argv);
};

extern struct builtin_s builtins[];

extern int builtins_count;

#endif
