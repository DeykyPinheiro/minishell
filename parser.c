#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include "parser.h"
#include "scanner.h"
#include "node.h"
#include "source.h"


t_node	*parse_simple_command(t_token *tok)
{
	if(!tok)
	{
		return NULL;
	}

	t_node *cmd = new_node(NODE_COMMAND);
	if(!cmd)
	{
		free_token(tok);
		return NULL;
	}

	t_source *src = tok->src;

	do
	{
		if(tok->text[0] == '\n')
		{
			free_token(tok);
			break;
		}

		t_node *word = new_node(NODE_VAR);
		if(!word)
		{
			free_node_tree(cmd);
			free_token(tok);
			return NULL;
		}
		set_node_val_str(word, tok->text);
		add_child_node(cmd, word);

		free_token(tok);

	} while((tok = tokenize(src)) != &eof_token);

	return cmd;
}
