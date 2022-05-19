#ifndef NODE_H
#define NODE_H

enum	node_type_e
{
	NODE_COMMAND,
	NODE_VAR,
};

enum	val_type_e
{
	VAL_SINT = 1,
	VAL_UINT,
	VAL_SLLONG,
	VAL_ULLONG,
	VAL_FLOAT,
	VAL_LDOUBLE,
	VAL_CHR,
	VAL_STR,
};

union symval_u
{
    long               sint;
    unsigned long      uint;
    long long          sllong;
    unsigned long long ullong;
    double             sfloat;
    long double        ldouble;
    char               chr;
    char              *str;
};

typedef struct s_node
{
	enum node_type_e	type;
	enum val_type_e		val_type;
	union symval_u		val;
	int					children;
	struct s_node		*first_child;
	struct s_node		*next_sibling;
	struct s_node		*prev_sibling;

}	t_node;

t_node	*new_node(enum node_type_e type);
void	add_child_node(t_node *parent, t_node *child);
void	free_node_tree(t_node *node);
void	set_node_val_str(t_node *node, char *val);




#endif
