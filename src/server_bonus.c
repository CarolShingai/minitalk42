/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:36:00 by cshingai          #+#    #+#             */
/*   Updated: 2024/05/15 16:25:42 by cshingai         ###   ########.fr       */
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
	ft_printf(" |   | ooo        ooooo  o8o               o8o ", "");
	ft_printf("     .             oooo  oooo        |   |\n");
	ft_printf(" |   | `88.       .888'  `*                `*  ", "");
	ft_printf("   .o8             `888  `888        |   |\n");
	ft_printf(" |   |  888b     d'888  oooo  ooo. .oo.   oooo ", "");
	ft_printf(" .o888oo  .oooo.    888   888  oooo  |   |\n");
	ft_printf(" |   |  8  `888'   888   888   888   888   888 ", "");
	ft_printf("   888    .oP'888   888   888888.    |   |\n");
	ft_printf(" |   |  8    Y     888   888   888   888   888 ", "");
	ft_printf("   888 . d8(  888   888   888 `88b.  |   |\n");
	ft_printf(" |   | o8o        o888o o888o o888o o888o o888o", "");
	ft_printf("   '888  `Y888''8o o888o o888o o888o |   |\n");
	ft_printf(" |___|                                         ", "");
	ft_printf("                                     |___|\n");
	ft_printf("(_____)-----------------------------------------", "");
	ft_printf("-----------------------------------(_____)\n");
	ft_printf("            ----- Welcome to Minitalk! ------ ");
	ft_printf("The PID number is: %d ------\n\n", getpid());
}

void	handler_sigusr(int signal, siginfo_t *info, void *context)
{
	static unsigned char	character;
	static int				bit;
	(void ) context;

	if (signal == SIGUSR1)
		character = character | (1 << bit);
	bit++;
	write(STDOUT_FILENO, "Sinal recebido.\n", 17);
	write(1, &signal, 5);
	kill(info->si_pid, SIGUSR2);
	if (bit == 8)
	{
		write(1, &character, 1);
		if (character == '\0')
			kill(info->si.pid);
		character = 0;
		bit = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler_sigusr;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	welcome_display();
	return (0);
}
