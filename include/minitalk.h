/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:36:51 by cshingai          #+#    #+#             */
/*   Updated: 2024/05/10 15:19:27 by cshingai         ###   ########.fr       */
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
void	handle_client_sign(int sign);
void	ft_send_signal(int pid, char c);
#endif
