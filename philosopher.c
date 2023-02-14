/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:05:59 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/14 13:52:42 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_makingthingsready(t_phil *philo, char **argv, t_chopstick *stick)
{
	int nb;
	t_routine	routine;

	nb = philo->input.n_ph;

	// printf("\nnbofphil%d\n",nb);
	// philo->who_am_i = 0;
	// philo->am_i_alive = 1;
	// philo->input.stillrunning = 1;
	// philo->status.status = 0;
	// philo->right.chopstick = 0;
	// philo->left.chopstick = 0;
	// philo->what_i_am_doing.eating = 0;
	// philo->what_i_am_doing.sleeping = 0;
	// philo->what_i_am_doing.thinking = 0;
	ft_initmutex(philo, stick);
	pthread_create(&philo->input.newsies, NULL, &ft_monitor, (void *)philo);
	ft_init_thread(philo, stick);
	
}

int	ft_check(char **argv, t_phil *philo)
{
	int 	i;
	// t_phil	philo[ft_atoi(argv[1])];

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
	t_phil	philo[250];
	t_chopstick stick[250];
	// t_phil	philo[ft_atoi(argv[1])];


	if(!(argc == 5))
	{
		// printf("ao");
		return (0);
	}
	if (ft_check(argv , philo) == 0)
		return (0);
	ft_makingthingsready(philo, argv, stick);
	ft_join(philo);
	ft_destroymutex(philo, stick);


	return (1);
}
