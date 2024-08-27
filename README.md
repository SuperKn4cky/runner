
# Runner - Labyrinthe 3D avec Raycasting

## Description

**Runner** est un jeu de labyrinthe en 3D développé durant ma première année de Bachelor en informatique. Le jeu utilise la technique de **raycasting** pour générer une vue à la première personne, permettant au joueur de se déplacer dans un environnement en trois dimensions.

## Fonctionnalités

- **Labyrinthe 3D** : Le joueur explore un labyrinthe en vue à la première personne.
- **Raycasting** : Utilisation d'une technique de rendu simplifiée pour simuler un environnement 3D à partir d'une carte 2D.
- **Déplacements** : Le joueur peut se déplacer dans toutes les directions, sauter et sprinter, offrant ainsi une liberté totale de mouvement dans le labyrinthe.

## Technologie Utilisée

Le projet est construit avec **[LibLapin](https://github.com/Damdoshi/LibLapin)**, une bibliothèque graphique simple et efficace pour le développement de jeux en C. LibLapin offre des fonctionnalités pour la gestion des fenêtres, le rendu graphique et la gestion des événements (clavier, souris), ce qui la rend idéale pour un projet de première année.

## Compilation et Exécution

Pour compiler et exécuter le projet, assurez-vous d'avoir **LibLapin** installée sur votre système.

1. Clonez le dépôt et compilez :
   ```bash
   git clone https://github.com/SuperKn4cky/runner
   cd runner
   make
   ```

2. Exécutez le jeu :
   ```bash
   ./runner
   ```

## Crédits

Projet réalisé par Quentin Gimenez.
