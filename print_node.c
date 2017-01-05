/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:07:50 by cnovo-ri          #+#    #+#             */
/*   Updated: 2016/12/22 15:20:42 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			print_node(t_list **node)
{
	t_list		*current;

	current = *node;
	while (current != NULL)
	{
		printf("%s", current->value)
		current = current->next;
	}
}
