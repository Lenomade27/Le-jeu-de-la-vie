# Livrable 1
## Fonctionnalités implémentées

### choix_mode :
**choix_mode(int it,int temp,bool modeb,string lien);**

La classe choix du mode va nous permettre de faire une façade à notre programme 
Elle est très peu utilisée car elle sert de constructeur au cœur de notre 
Programme là où tout est lié. Grâce à l'héritage, cela nous empêche de faire un constructeur 
dans notre classe jeux-de-la-vie, qui va lui récupérer la méthode la plus 
Importante de notre programme qui va tout relier.

### jeux_de_la_vie : 
**jeux_de_la_vie(int it, int temp, bool mode, string lien) : choix_mode(it, temp, mode, lien)** \
Constructeur de choix_mode récupéré grâce à notre héritage permet de récupérer les valeurs de base

**void jeux_de_la_vie_jeux();**\
Notre jeu méthode qui va contenir toutes les principales méthodes de notre programme et qui 
Va s'occuper de tout ce qu'est l'itération et le choix du mode.


### grille : 
**Grille(string lien);**\
Constructeur avec un lien de fichier en paramètre pour initialiser la grille

<strong>static bool test_grille(Grille* grille_test);</strong>\
Méthode qui va tester si la grille est redondante

<strong>static void set_voisin(Grille* grille_vois,int i ,int j,bool mode);</strong>\
Méthode qui va regarder les voisins d'une case

<strong>static void afficherGrille(Grille* grille_aff);</strong>\
Méthode pour afficher la grille 

<strong>static void refresh_grille(Grille* grille_aff);</strong>\
Méthode qui va mettre à jour notre grille et changer les cases qui doivent être changées

### case : 
**Case();**\
Constructeur de case morte

**Case(int type);**\
Constructeur de case vivante

**void set_case(int type);** \
Setter qui nous permet d'enregistrer l'état d'avant d'une cellule tout en changeant l'actuel

### gestion_fichier : 
<strong>static void create_fichier(Grille* grille,string lien,string lien_nom) ;</strong>\
Méthode pour créer un fichier avec le nom de l'origine_out

**static vector<vector<int>> get_fichier_data(string lien);**  
Méthode pour récupérer le contenu d'un fichier

**static string create_file();**\
Renvoie le lien d'un dossier créé

### affichage : 
<strong>affichage(Grille* grille_aff);</strong>\
Constructeur qui va créer notre fenêtre

<strong>void update_affichage(Grille* grille_aff);</strong>\
Mets à jour l'affichage

**~affichage();**\
Permet de supprimer la fenêtre quand l'objet est détruit
    
### observer : 
<strong>fouille_grille(Grille* grille_obs);</strong>\
 Méthode qui va chercher dans notre grille 



## Extensions implémentées
Aucune extension ont été ajouter // A voir avec Rayane



## Execution du programme

Lors du début de notre programme, nous allons demander à l'utilisateur de nous envoyer les bases telles que le chemin du fichier ou le mode qu'il souhaite sélectionner... pour bien faire tourner notre programme.
Il construit ainsi un jeu de la vie avec ces informations. Jeu_de_la_vie va directement exécuter notre programme selon le mode choisi.
### Mode Graphique

Le mode graphique est un mode qui va pouvoir afficher chaque itération de notre grille. L'utilisateur peut choisir le temps entre chaque itération pour pouvoir voir la grille.
On va ainsi créer une grille et un affichage. 
Puis, on va faire attendre notre programme pour faire s'afficher notre grille initiale mise par l'utilisateur
Après cela, nous allons réaliser les itérations. La boucle aura comme condition que si l'état est répété entre deux itérations, le programme se coupe ou encore que si nos itérations sont à 0 (finies), pareil et pour finir, si on ferme notre fenêtre.
Dans cette boucle, nous allons appeler plusieurs méthodes. Tout d'abord, nous allons marquer les cases que nous devons regarder car toutes ne vont pas changer d'états (ex : Une case autour d'aucune case vivante ne changera pas)
Puis, sur ces cases, nous allons compter le nombre de cases vivantes autour pour voir si elles changeront 
Pour finir, nous mettons à jour notre grille pour afficher les nouveaux états.
Et on utilise la méthode qui va l'afficher sur notre affichage graphique.

### Mode Console 
Le mode console, contrairement au mode graphique, n'affiche rien et a pour but d'enregistrer les états des grilles à chaque itération.
Elle va conserver dans notre programme la moitié de nos itérations. Les fichiers créés seront mis dans un dossier créé par notre utilisateur grâce à notre code 
et les fichiers auront ce type de nom <nom_du_fichier_dentree>_out.txt 
Tout d'abord, nous allons créer notre grille et notre dossier.
Puis nous allons passer aux itérations. Contrairement aux modes graphiques, celui-ci n'en a que deux si l'itération arrive à zéro ou que les états sont répétitifs.
Comme dans le mode graphique, nous allons compter et marquer les cases que l'on va regarder 
Seulement à la fin, nous allons juste créer un fichier pour la grille actuelle de notre boucle.
## Axes d'amélioration
Optimisation de notre programme. Mettre en privé certains paramètres pour plus de sécurité 
Et encore optimiser notre observateur pour éviter de marquer les cases plusieurs fois 
Rajouter des extensions 
Récupérer tous les fichiers pour le mode console et non pas que la première moitié




