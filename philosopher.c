/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:05:59 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/09 18:16:24 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_makingthingsready(t_phil *philo, char **argv)
{
	int nb;
	t_routine	routine;

	nb = philo->input.n_ph;
	printf("\nnbofphil%d\n",nb);
	philo->who_i_am = 0;
	philo->am_i_alive = 1;
	philo->status = 0;
	philo->what_i_am_doing.eating = 0;
	philo->what_i_am_doing.sleeping = 0;
	philo->what_i_am_doing.thinking = 0;
	ft_init_thread(philo, &routine);
	
}

int	ft_check(char **argv, t_phil *philo)
{
	int i;

	i = 1;
	// while(i < input->n_ph )
	// {
	// 	if (ft_isdigit((argv[i])==0)
	// 		return (0);
	// 	i++;
	// }
	philo->input.n_ph = ft_atoi(argv[1]);
	philo->input.tt_die = ft_atoi(argv[2]);
	philo->input.tt_eat = ft_atoi(argv[3]);
	philo->input.tt_sleep = ft_atoi(argv[4]);
	return (1);
}

int	main (int argc, char **argv)
{
	t_phil philo[250];

	if(argc != 4)
		return (0);
	if (ft_check(argv , philo) == 0)
		return (0);
	ft_makingthingsready(philo, argv);
	ft_join(philo);

	return (1);
}
