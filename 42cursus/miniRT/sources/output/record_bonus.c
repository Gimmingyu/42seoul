/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:20:02 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:00:35 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../minirt.h"
#include "../math/vector.h"

#define THREAD 12

static void	*thread_record(void *tid)
{
	int			x;
	int			y;
	const int	chunk = scene_()->height / THREAD;
	const int	id = (int)tid;
	const int	y_ = id * chunk;

	x = scene_()->width;
	while (x--)
	{
		if (id == THREAD - 1)
			y = scene_()->height;
		else
			y = y_ + chunk;
		while (y-- > y_)
			record_samples(x, y);
	}
	pthread_exit(NULL);
	return (tid);
}

void		record(void)
{
	pthread_t		thread[THREAD];
	t_scene			*s;
	unsigned long	id;

	s = scene_();
	id = THREAD;
	while (id--)
		if (pthread_create(&thread[id], NULL, thread_record, (void *)id))
			quit(THREAD_ERROR, "record()");
	while (++id < THREAD)
		pthread_join(thread[id], NULL);
	record_(s->screen, s->raw, s->accumulated);
}
