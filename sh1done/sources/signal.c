/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:33:02 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/16 16:33:03 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void		ft_putstr_s(char *str)
{
	write(1, str, ft_strlen(str));
}

static void		passif(int value)
{
	(void)value;
	ft_putchar('\n');
	prompt(NULL, 0);
}

static void		signal_message(int signum)
{
	ft_putchar('\n');
	(void)signum;
}

void			signal_message_exec(int signum)
{
	if (signum == SIGINT)
		ft_putstr_s("\033[31mSIGINT\033[00m: Terminal interrupt.");
	else if (signum == SIGTERM)
		ft_putstr_s("\033[31mSIGTERM\033[00m: Terminate.");
	else if (signum == SIGFPE)
		ft_putstr_s("\033[31mSIGFPE\033[00m: Erroneous arithmetic op.");
	else if (signum == SIGABRT)
		ft_putstr_s("\033[31mSIGABRT\033[00m: Process abort.");
	else if (signum == SIGSEGV)
		ft_putstr_s("\033[31mSIGSEGV\033[00m: Segmentation violation.");
	else if (signum == SIGTSTP)
		ft_putstr_s("\033[31mSIGTSTP\033[00m: Not allowed.");
	else
	{
		ft_putstr_s("\033[31mUNKNOW\033[00m: Terminate by [");
		ft_putnbr(signum);
		ft_putchar(']');
	}
	ft_putchar('\n');
}

void			gestion_signal(int value)
{
	void	*ft;

	ft = passif;
	if (value == 1)
		ft = signal_message;
	signal(SIGFPE, ft);
	signal(SIGSEGV, ft);
	signal(SIGABRT, ft);
	signal(SIGTERM, ft);
	signal(SIGTSTP, ft);
	signal(SIGINT, ft);
}
