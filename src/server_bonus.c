/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:36:00 by cshingai          #+#    #+#             */
/*   Updated: 2024/05/17 19:22:57 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	welcome_display(void)
{
	ft_printf(" _____                                         ");
	ft_printf("                                     _____\n");
	ft_printf("( ___ )-----------------------------------------", "");
	ft_printf("-----------------------------------( ___ )\n");
	ft_printf(" |   |                                         ", "");
	ft_printf("                                     |   |\n");
	ft_printf(" |   | " PURPLE"ooo        ooooo  o8o               o8o ", ""RESET);
	ft_printf("     .             oooo  oooo       "RESET" |   |\n");
	ft_printf(" |   | " PURPLE"`88.       .888'  `*                `*  ", ""RESET);
	ft_printf(PURPLE"   .o8             `888  `888       " RESET" |   |\n");
	ft_printf(" |   | "PURPLE" 888b     d'888  oooo  ooo. .oo.   oooo ", "");
	ft_printf(" .o888oo  .oooo.    888   888  oooo " RESET" |   |\n");
	ft_printf(" |   | "PURPLE" 8  `888'   888   888   888   888   888 ", "");
	ft_printf("   888    .oP'888   888   888888.  "RESET"  |   |\n");
	ft_printf(" |   | "PURPLE" 8    Y     888   888   888   888   888 ", "");
	ft_printf("   888 . d8(  888   888   888 `88b. "RESET" |   |\n");
	ft_printf(" |   | "PURPLE"o8o        o888o o888o o888o o888o o888o", "");
	ft_printf("   '888  `Y888''8o o888o o888o o888o "RESET"|   |\n");
	ft_printf(" |___|                                         ", "");
	ft_printf("                                     |___|\n");
	ft_printf("(_____)-----------------------------------------", "");
	ft_printf("-----------------------------------(_____)\n");
	ft_printf("            ----- Welcome to Minitalk! ------ ");
	ft_printf("The PID number is: " ORANGE"%d" RESET"------\n\n", getpid());
}

void	handler_sigusr(int signal, siginfo_t *info, void *context)
{
	static unsigned char	character;
	static int				bit;

	if (!context)
		return ;
	else if (signal == SIGUSR1)
		character = character | (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &character, 1);
		if (character == '\0')
			kill(info->si_pid, SIGUSR1);
		character = 0;
		bit = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	ft_valid_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(void)
{
	struct sigaction	sa_signal;

	ft_memset(&sa_signal, 0, sizeof(sa_signal));
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_sigaction = &handler_sigusr;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	welcome_display();
	while (1)
		pause();
	return (0);
}
