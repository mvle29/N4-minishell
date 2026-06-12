# N4-minishell
Minishell!

Les deux mauvaises solutions :

Allouer args trop petit et l'agrandir à chaque mot → réallocations en cascade (ton idée memmove de tout à l'heure).
Expanser deux fois : une fois pour compter, une fois pour remplir → tout le travail en double.

La solution : stocker les mots dans une liste chaînée le temps de la découverte. Une liste n'a pas besoin de connaître sa taille à l'avance — ajouter un maillon coûte une allocation, peu importe qu'il y en ait déjà 2 ou 200. C'est sa force exacte là où le tableau est rigide.
Concrètement avec ta libft :
ct_list	*words;

words = NULL;
/* ... pendant l'expansion, à chaque mot terminé : */
ft_lstadd_back(&words, ft_lstnew(mot));   /* mot = char * fraîchement alloué */
À la fin, tu sais tout — ft_lstsize(words) te donne n — donc tu peux enfin créer le tableau, une seule fois, à la bonne taille :
cn = ft_lstsize(words);
args = ft_calloc(n + 1, sizeof(char *));
i = 0;
cur = words;
while (cur)
{
	args[i++] = cur->content;   /* on copie le POINTEUR, pas la string */
	cur = cur->next;
}
/* puis free les maillons t_list — PAS leur content,
   les strings appartiennent désormais à args */
La liste est un échafaudage : elle existe le temps de construire, puis disparaît. Les strings, elles, ne bougent jamais — allouées une fois pendant l'expansion, elles finissent dans args telles quelles. On n'a déplacé que des pointeurs.

--> banger de claude ca