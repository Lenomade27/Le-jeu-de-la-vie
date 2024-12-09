
# Livrable 1 - Groupe 5

## Fonctionnalités implémentées

### choix_mode :
```cpp
choix_mode(int it, int temp, bool modeb, string lien);
```
La classe `choix_mode` nous permet de créer une façade pour notre programme. Elle est peu utilisée, car elle sert principalement de constructeur au cœur de notre programme, là où tout est lié. Grâce à l'héritage, elle nous évite d'ajouter un constructeur dans la classe `jeux_de_la_vie`, qui récupère ainsi la méthode principale du programme, permettant de tout relier.

### jeux_de_la_vie :
```cpp
jeux_de_la_vie(int it, int temp, bool mode, string lien) : choix_mode(it, temp, mode, lien)
void jeux_de_la_vie_jeux();
```
Le constructeur de `choix_mode`, récupéré grâce à l'héritage, permet d'initialiser les valeurs de base. Cette méthode contient les principales fonctionnalités de notre programme. Elle gère notamment les itérations et le choix du mode.

### grille :
```cpp
Grille(string lien);
static bool test_grille(Grille* grille_test);
static void set_voisin(Grille* grille_vois, int i, int j, bool mode);
static void afficherGrille(Grille* grille_aff);
static void refresh_grille(Grille* grille_aff);
```
- Constructeur utilisant un lien de fichier en paramètre pour initialiser la grille.
- Méthodes pour tester si la grille est redondante, identifier les voisins d'une case, afficher et rafraîchir la grille.

### case :
```cpp
Case();
Case(int type);
void set_case(int type);
```
- Constructeurs pour créer une case morte ou vivante.
- Setter permettant d’enregistrer l'état précédent d'une cellule tout en modifiant son état actuel.

### gestion_fichier :
```cpp
static void create_fichier(Grille* grille, string lien, string lien_nom);
static vector<vector> get_fichier_data(string lien);
static string create_file();
```
- Méthodes pour créer un fichier, récupérer le contenu d’un fichier et générer le lien d’un dossier.

### affichage :
```cpp
affichage(Grille* grille_aff);
void update_affichage(Grille* grille_aff);
~affichage();
```
- Constructeur permettant de créer une fenêtre, mise à jour de l'affichage, et suppression de la fenêtre lors de la destruction de l'objet.

### observer :
```cpp
fouille_grille(Grille* grille_obs);
```
- Méthode permettant de chercher dans la grille.

## Exécution du programme

### Mode graphique
- Affiche chaque itération de la grille avec un délai choisi par l'utilisateur.
- Processus :
  1. Crée une grille et un affichage.
  2. Affiche la grille initiale.
  3. Exécute une boucle d'itérations avec conditions d'arrêt :
     - Répétition de l'état de la grille.
     - Nombre d'itérations atteint.
     - Fermeture de la fenêtre par l'utilisateur.

### Mode console
- Enregistre les états de la grille à chaque itération dans des fichiers.
- Processus :
  1. Création de la grille et du dossier.
  2. Boucle d'itérations avec conditions d'arrêt.
  3. Marquage et comptage des cases.
  4. Enregistrement des états dans des fichiers.

## Axes d'amélioration
- Optimiser davantage le programme.
- Rendre certains paramètres privés pour une meilleure sécurité.
- Améliorer l’observateur pour éviter de marquer plusieurs fois les mêmes cases.
- Ajouter des extensions.
- Récupérer tous les fichiers générés dans le mode console.
