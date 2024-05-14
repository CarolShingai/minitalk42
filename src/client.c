/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:06:24 by cshingai          #+#    #+#             */
/*   Updated: 2024/05/14 17:22:02 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_is_received;

int	ft_valid_pid(char *pid)
{
	int	idx;

	idx = 0;
	while (pid[idx])
	{
		if (!ft_isdigit(pid[idx]))
			return (1);
		idx++;
	}
	return (0);
}

// handler the signal for client
void	client_handler(int sign)
{
	ft_printf("entrou");
	if (sign == SIGUSR2)
	{
		ft_printf("character was received");
		g_is_received = 1;
	}
}

void	ft_send_msg(int pid, char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		ft_send_signal(pid, str[i]);
		i++;
	}
}


void	ft_send_signal(int pid, char c)
{
	static int	bit_idx;
	static char	bit;

	bit_idx = 0;
	bit = 0;
	while (bit_idx < 8)
	{
		g_is_received = 0;
		bit = c >> bit_idx & 1;
		if (bit)
			kill(pid, SIGUSR1);
		else if (bit == 0)
			kill(pid, SIGUSR2);
		// while (!g_is_received)
		// 	;
		bit_idx++;
	}

}

int	main(int argc, char *argv[])
{
	__pid_t				pid;
	struct	sigaction	sa_signal;

	if (argc != 3)
		return (ft_printf("Invalid number of arguments."));
	if (ft_valid_pid(argv[1]))
		return (ft_printf("Invalid PID! Please inseart a valid PID."));
	sa_signal.sa_flags = 0;
	sa_signal.sa_handler = &client_handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	pid = ft_atoi(argv[1]);
	ft_send_msg(pid, argv[2]);
	ft_printf("sign:%d\n", g_is_received);
	return (0);
}