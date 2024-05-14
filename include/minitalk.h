/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:36:51 by cshingai          #+#    #+#             */
/*   Updated: 2024/05/14 17:21:13 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/src/ft_printf.h"

void	signal_config_client(void);
int		ft_valid_pid(char *pid);
void	client_handler(int sign);
void	ft_send_msg(int pid, char *str);
void	ft_send_signal(int pid, char c);
#endif
