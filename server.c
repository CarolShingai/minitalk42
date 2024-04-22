/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:33:24 by cshingai          #+#    #+#             */
/*   Updated: 2024/04/22 20:27:35 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr(int signal)
{

	static unsigned char	character;
	static int	idx;

	character |= (signal == SIGUSR1);
	idx = 0;
	if (idx == 8)
	{
		
	}
	idx++;
	write(STDOUT_FILENO, "Sinal recebido.\n", 17);
	write(1, &signal, 5);
}

int	main(void)
{
	__pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = handler_sigusr;
	pid = getpid();
	sigaction(SIGINT, &sa, NULL);
	while (1)
	{
		ft_printf("%d\n", pid);
		sleep(1);
	}
}
