/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:36:04 by cshingai          #+#    #+#             */
/*   Updated: 2024/05/10 15:39:51 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int		g_is_received;

int	main(int argc, char **argv)
{
	int					idx;
	__pid_t				pid;
	struct sigaction	sa;

	idx = 0;
	if (argc != 3)
		return (ft_printf("Invalid number of arguments."));
	if (ft_valid_pid(argv[1]))
		return (ft_printf("Invalid PID! Please inseart a valid PID."));
	sa.sa_flags = 0;
	sa.sa_handler = &handle_client_sign;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(argv[1]);
	while(argv[2][idx])
	{
		ft_send_signal(pid,argv[2][idx]);
		idx++;
	}
	return (0);
}

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
void	handle_client_sign(int sign)
{
	if (sign == SIGUSR1)
		ft_printf("character was received");
	else if (sign == SIGUSR2)
		g_is_received = 1;
}

void	ft_send_signal(int pid, char c)
{
	static int	i;
	static char	bit;

	i = 0;
	bit = 0;
	while (i < 8)
	{
		g_is_received = 0;
		bit = c >> i & 1;
		if (bit)
			kill(pid, SIGUSR1);
		else if (bit == 0)
			kill(pid, SIGUSR2);
		while (!g_is_received)
		;
		i++;
	}

}
