/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lore.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:39:53 by jcario            #+#    #+#             */
/*   Updated: 2023/11/10 22:22:18 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dialogue()
{
	ft_printf("\n\n\n");
	ft_printf("Jadis, dans un temps des plus reculés aujourd'hui oublié,\n");
	ft_printf("Un T-rex veillait sur ses oeufs, tous au chaud dans leur ");
	ft_printf("nid.\nUn calme parfait rompu par le gang des Pteranodons !\n");
	ft_printf("Ces terribles prédateurs volants avaient en effet pour ");
	ft_printf("habitude\nDe voler les oeufs des jeunes T-rex, et de faire de ");
	ft_printf("ces futurs dinos, \nDes recrues pour les servir, des chasseurs ");
	ft_printf("pour les nourrir, des bouffons pour leur sourire.\n\n");
	ft_printf("Mais ce Dino était celui de trop :  Jamais Dino n'acceptera\n");
	ft_printf("de voir ses bébés servir les Ptéras !\nNi une, ni deux, ");
	ft_printf("il se lance alors à la course aux oeufs !\n");
	ft_printf("%s-Vous n'aurez pas mes enfants !\n", GREEN);
	ft_printf("%s-Ce ne sont déjà plus tes enfants, \n", RED);
	ft_printf("MOUAHAHAHAHA !!%s\n\n\n", WHITE);
}


/*
Jadis, dans un temps des plus reculés aujourd'hui oublié,
Un T-rex veillait sur ses oeufs, tous au chaud dans leur nid.
Un calme parfait rompu par le gang des Pteranodons !
Ces terribles prédateurs volants avaient en effet pour habitude
De voler les oeufs des jeunes T-rex, et de faire de ces futurs dinos,
Des recrues pour les servir, des chasseurs pour les nourrir, des bouffons pour leur sourire.

Mais ce Dino était celui de trop : Jamais Dino n'acceptera de voir ses
bébés servir les Ptéras ! Ni une ni deux il se lance alors à la course aux oeufs !
-Vous n'aurez pas mes enfants !
-Ce ne sont déjà plus tes enfants, HAHAHAHAHAHA !


*/
