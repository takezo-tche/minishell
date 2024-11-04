/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbetcher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:26:35 by mbetcher          #+#    #+#             */
/*   Updated: 2024/11/03 17:26:36 by mbetcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	create_nodes(t_data *data)
{
	char	*tab;
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	tab = data->line;

	while (tab[i])
	{
		if (tab[i] == ''')
		{
			i++;
			while (tab[i] != ''')
				i++;
		}
		if (tab[i] == '\"')
		{
			i++;
			while (tab[i] != '\"')
				i++;
		}
		if (tab[i] == '|')
		{
			append_nodes(data, last, i);
			last = i + 1;
		}
		i++;
	}
	ft_free_tab(tab);
}

void	append_nodes(t_data *data, int last, int i)
{
	t_node	*last_node;
	
	last_node = find_last_node(data);
}



si data->start_node == NULL, malloc directement un noeud et faire pointe node_start sur ce noeud
sinon trouve le dernier noeud et faire pointe le dernier noeud sur le noeud cree
gerer l initialisation de fd du noeud(les mettre a 0 et 1 par defaut);










pour considere un pipe, il faut seulement qu il soit pas entre deux quotes


si je split seulement avec les espaces, je me retrouve a chercher l

comment gerer la creation des noeuds ?

spliter ma chaine
passer dans ma chaine en verifiant s il y a un tableau avec tab[0] = '|' et tab[1] = NULL
si oui
{
	creer un noeud avec tt ce qu il y a avant, les concatener et mettre ca dans node->command
	
}
initialiser les fd a chaque creation de noeud
faire pointer le dernier noeud sur le noeud cree 
continuer tant qu il y a un '|' ou qu on est sur la fin de la chaine
