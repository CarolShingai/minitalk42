/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:06:24 by cshingai          #+#    #+#             */
/*   Updated: 2024/05/06 20:28:35 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		g_is_received;
	__pid_t	pid;

	if (argc != 3)
		return (ft_printf("Invalid number of arguments."));
	if (ft_valid_pid(argv[1]))
		return (ft_printf("Invalid PID! Please inseart a valid PID."));
	pid = ft_atoi(argv[1]);
	signal_config_client();
}

//Configuring the signal for the client
void	signal_config_client(void)
{
	struct sigaction	sa;

	sa.sa_flagas = 0;
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
	
}
