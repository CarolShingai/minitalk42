/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:33:24 by cshingai          #+#    #+#             */
/*   Updated: 2024/04/11 19:24:11 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int	idx;

	idx = 0;
	if (argc != 3)
		return ft_printf("Invalid number of arguments");
	while (argv[1][idx]){
		if (ft_isdigit(argv[1][idx] != 1))
		{
			error();
			idx++;
		}
	}
}
