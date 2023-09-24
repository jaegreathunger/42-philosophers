/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:26:20 by jaeshin           #+#    #+#             */
/*   Updated: 2023/09/24 12:58:34 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_total	*total;
	int		i;

	total = init_total(argc, argv);
	init_err(total);
	i = 0;
	while (i < total->args->nbr_of_phil)
	{
		printf("Philosoper %d", total->philos[i].id);
		printf(" right_c - %d left_c - %d\n", \
		 total->philos[i].r_chopstick, total->philos[i].l_chopstick);
		i++;
	}
	return (0);
}
