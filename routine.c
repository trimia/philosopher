/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:39:13 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/08 20:02:00 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	ft_takechopstick(t_phil * philo)
{
	
}

// ft_printmsg(philo->who_i_am, philo->what_i_am_doing.eating);
void	ft_printmsg(t_phil *philo, int tempo)
{
	if (philo->status == 1 )
		printf("\n%d ms = %d is eating", philo->who_i_am,tempo);
	if (philo->status == 2 )
		printf("\n%d ms = %d is sleeping", philo->who_i_am,tempo);
	if (philo->status == 3 )
		printf("\n%d ms = %d is thinking", philo->who_i_am,tempo);
	philo->status = 0;
}
