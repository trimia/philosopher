/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:09:30 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/14 13:51:46 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_initmutex(t_phil *philo ,t_chopstick *stick)
{
	int	i;

	i = 0;
	while (i < philo->input.n_ph)
	{
		pthread_mutex_init(&stick[i].staybeef , NULL);
		pthread_mutex_init(&philo[i].stop, NULL);
		pthread_mutex_init(&philo[i].input.writing, NULL);
	}
}

void	ft_destroymutex(t_phil *philo, t_chopstick *stick)
{
	int	i;

	i = 0;
	while (i < philo->input.n_ph)
	{
		pthread_mutex_destroy(&stick[i].staybeef);
		pthread_mutex_destroy(&philo[i].stop);
		pthread_mutex_destroy(&philo[i].input.writing);
	}
}