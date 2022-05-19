#ifndef PARSER_H
#define PARSER_H

#include "scanner.h"
#include "source.h"
#include "node.h"

t_node	*parse_simple_command(t_token *tok);

#endif
