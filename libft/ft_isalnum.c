/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 23:02:28 by cel-oiri          #+#    #+#             */
/*   Updated: 2018/10/18 23:15:08 by cel-oiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int s)
{
	if ((s < 'A' || s > 'Z') && (s < 'a' || s > 'z') && (s < '0' || s > '9'))
		return (0);
	else
		return (1);
}
