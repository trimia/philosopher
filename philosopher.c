/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:05:59 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/14 19:26:36 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_philostart(t_phil *philo, t_chopstick *stick, t_time *input)
{
	
	ft_init_thread(philo, stick, input);
	usleep(50);
	pthread_create(&input->newsies, NULL, &ft_monitor, (void *)philo);
	ft_join(philo, input);
	ft_killmutex(philo, stick, input);
}

void	ft_makingthingsready(char **argv,t_time *input)
{
	t_phil	philo[250];
	t_chopstick stick[250];

	input->n_ph = ft_atoi(argv[1]);
	input->n_ph = ft_atoi(argv[1]);
	input->tt_die = ft_atoi(argv[2]);
	input->tt_eat = ft_atoi(argv[3]);
	input->tt_sleep = ft_atoi(argv[4]);
	input->stillrunning = 1;
	printf("\n\\n");
	// ft_initmutex(philo, stick, input);
	ft_philostart(philo, stick, input);
	
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
	
	return (1);
}


int	main (int argc, char **argv)
{
	t_time input;
	
	// t_phil	philo[ft_atoi(argv[1])];


	if(!(argc == 5))
	{
		printf("ao");
		return (0);
	}
	// if (ft_check(argv) == 0)
	// 	return (0);
	ft_makingthingsready(argv, &input);
	// ft_destroymutex(philo, stick, input);
	// ft_join(philo);
	// ft_destroymutex(philo, stick);


	return (1);
}
