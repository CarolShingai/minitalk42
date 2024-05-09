/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:36:04 by cshingai          #+#    #+#             */
/*   Updated: 2024/05/09 16:56:22 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int		g_is_received;

int	main(int argc, char **argv)
{
	int		idx;
	__pid_t	pid;

	idx = 0;
	if (argc != 3)
		return (ft_printf("Invalid number of arguments."));
	if (ft_valid_pid(argv[1]))
		return (ft_printf("Invalid PID! Please inseart a valid PID."));
	pid = ft_atoi(argv[1]);
	signal_config_client();
	while(argv[2][idx])
	{
		ft_send_msg(pid,argv[2][idx]);
		idx++;
	}
	// ft_send_msg(pid, *argv[2]);
	return (0);
}

//Configuring the signal for the client
void	signal_config_client(void)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = &handle_client_sign;
	if ((sigaction(SIGUSR1, &sa, NULL) == - 1) || (sigaction(SIGUSR2, &sa, NULL) == -1))
			ft_printf("ERROR!");
		exit(1);
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

void	ft_send_msg(int pid, char c)
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
