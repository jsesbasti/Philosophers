/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-25 17:25:56 by jsebasti          #+#    #+#             */
/*   Updated: 2025-04-25 17:25:56 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum e_bool
{
	false,
	true
}	t_bool;

t_bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}