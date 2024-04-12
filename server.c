/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:33:24 by cshingai          #+#    #+#             */
/*   Updated: 2024/04/12 19:08:12 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	__pid_t				pid;
	struct	sigaction	siga;

	pid = getpid();

	ft_printf("%d", pid);
	// int	idx;

	// idx = 0;
	// if (argc != 3)
	// 	return ft_printf("Invalid number of arguments");
	// while (argv[1][idx]){
	// 	if (ft_isdigit(argv[1][idx] != 1))
	// 	{
	// 		error();
	// 		idx++;
	// 	}
	// }
}
