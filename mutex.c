/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:09:30 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/14 19:22:54 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_initmutex(t_phil *philo ,t_chopstick *stick, t_time *input)
{
	int	i;

	i = 0;
	// printf("\ninitmutex\n");

	pthread_mutex_init(&input->writing, NULL);
	while (i < input->n_ph)
	{
		pthread_mutex_init(&philo[i].left->staybeef , NULL);
		pthread_mutex_init(&philo[i].right->staybeef , NULL);
		pthread_mutex_init(&philo[i].stop, NULL);
		i++;
	  	// printf("\n mutex while %d\n",i);
	}
}

void	ft_killmutex(t_phil *philo, t_chopstick *stick, t_time *input)
{
	int	i;

	i = 0;
	while (i < input->n_ph)
	{
	pthread_mutex_destroy(&philo[i].left->staybeef);
	pthread_mutex_destroy(&philo[i].right->staybeef);
	pthread_mutex_destroy(&philo[i].stop);
		i++;
	}
	pthread_mutex_destroy(&input->writing);
}