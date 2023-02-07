/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:05:59 by mmariani          #+#    #+#             */
/*   Updated: 2023/02/07 22:27:12 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_makingthingsready(t_phil *philo, int nb, char **argv)
{
	t_routine	*routine;

	philo->who_i_am = 0;
	philo->am_i_alive = 1;
	philo->what_am_i.eating = 0;
	philo->what_am_i.sleeping = 0;
	philo->what_am_i.thinking = 0;
	ft_init_thread(philo, &routine, nb);
	
}

void	*ft_routine()
{

}

int	ft_check(char **argv, t_time *input)
{
	int i;

	i = 1;
	while(i < input->n_ph )
	{
		if (ft_isdigit(argv[i])==0)
			return (0);
		i++;
	}
	input->n_ph = argv[1];
	input->tt_die = argv[2];
	input->tt_eat = argv[3];
	input->tt_sleep = argv[4];
	return (1);
}

void	ft_init_thread(t_phil *philo, t_routine *routine, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		pthread_create(philo->who_i_am++, NULL, ft_routine, routine);

	}
}

int	main (int argc, char **argv)
{
	t_phil *philo;
	t_time *input;

	if(argc != 4)
		return (0);
	if (ft_check(argv , &input) == 0)
		return (0);
	ft_makingthingsready(&philo, input->n_ph, argv);

	return (0);
}