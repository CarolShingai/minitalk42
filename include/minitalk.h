/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:36:51 by cshingai          #+#    #+#             */
/*   Updated: 2024/05/17 19:17:00 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/src/ft_printf.h"

# define RESET "\033[0m"
# define GREEN "\033[0;32m"
# define RED "\33[;31m"
# define ORANGE "\033[38;5;208m"
# define PURPLE "\033[38;5;141m"
# define BLINK "\033[5m"

void	ft_send_signal(int pid, char c);

#endif
