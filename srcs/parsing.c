/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:15:10 by camerico          #+#    #+#             */
/*   Updated: 2025/02/24 17:26:19 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//fait attention qu'il n'y ait pas 2 sorties ou 2 personnage a l'ecran;
//si on va a la sortie sans que le collectible_left soit a 0 on ne fait rien
//la case suivante est la sortie et le collectible_left est a 0 , alors message : "you won"
// on initialise le collectible_left en comptant le nb de C sur la map initiale
// la carte doit etre entouree par des murs ==> sinon retourne une erreur
// la carte doit contenir un chemin valide


// si possible, on change l'orientation du pacman
