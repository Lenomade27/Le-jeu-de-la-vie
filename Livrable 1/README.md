# Livrable 1
## Fonctionnalités implémentées

choix_mode :
choix_mode(int it,int temp,bool modeb,string lien);
La classe choix du mode va nous permttre de faire une facade a notre programme 
Elle est très peu utiliser car elle sert de constructeur aux coeur de notre programme la ou tout et lier 
Grace a l'héritage cela nous empeche de faire un constructeur dans notre classe jeux-de-la-vie qui va lui récuperer 
la Méthode la plus importante de notre programme qui vas tout relier.

jeux_de_la_vie : 
jeux_de_la_vie(int it, int temp, bool mode, string lien) : choix_mode(it, temp, mode, lien)
Constructeur de choix_mode récupérer grace a notre héritage permets de récuperer les valeurs de bases 
void jeux_de_la_vie_jeux();
Notre Jeux méthode qui va contenir toute les principales méthode de notre programme et qui va s'occuper de tout se qu'est itération et choix du mode. 


grille : 
Grille(string lien);
Constructeur avec un lien de fichier en paramètre pour initialiser la grille
static bool test_grille(Grille* grille_test);
Méthode qui va tester si la grille est redondante
static void set_voisin(Grille* grille_vois,int i ,int j,bool mode);
Méthode qui va regarder les voisin d'une case
static void afficherGrille(Grille* grille_aff);
Méthode pour afficher la grille (optionnel/test)
static void refresh_grille(Grille* grille_aff);
Méthode qui va mettre a jour notre grille et changer les cases qui doivent être changer

case : 
Case();
Constructeur de case morte
Case(int type);
Constructeur de case vivante
void set_case(int type);
Setter qui nous permet d'enregistrée l'états d'avant d'une cellule tout en changeant l'actuel

gestion_fichier : 
static void create_fichier(Grille* grille,string lien,string lien_nom) ;
//Méthode pour créer un fichier avec le nom de l'origine_out
static vector<vector<int>> get_fichier_data(string lien);  
//Méthode pour récuperer le contenue d'un fichier
static string create_file();

affichage : 
affichage(Grille* grille_aff);
Constructeur qui va crée notre fenetre
void update_affichage(Grille* grille_aff);
Mets a jour l'affichage
~affichage();
Permet de supprimer la fenetre quand l'objet est détruits
    
observer : 
fouille_grille(Grille* grille_obs);
Méthode qui va chercher dans notre grille  



## Extensions implémentées
Aucune extension ont été ajouter // A voir avec Rayane



## Execution du programme

Lors du début de notre programmes nous allons demander a l'utilisateur de nous envoiyer les bases tel que le chemins du fichier ou le mode qu'il souhaite selectionner ... pour bien faire tourner notre programme.
Il construit ainsi un jeu_de_la_vie avec c'est information. jeu_de_la_vie va directement éxecuter notre programme selon le mode choisis. 
### Mode Graphique
Le mode graphique est un mode qui va pouvoir afficher chaque itération de notre grille. L'utilisateur peut choisir le temps entre chaque itération pour pouvoir voir la grille.
On va ainsi créer une grille et un affichage. 
Puis on va faire attendre notre programme pour faire s'afficher notre grille innital mis par l'utilisateur
Après cela nous allons réaliser les itération. La boucle auras comme condition que si l'états est répéter entre deux itération le programme se coupe ou encore que si nos itération sont a 0 (finis) pareil et pour finir si on ferme notre fenetre.
Dans cette boucle nous allons appeler plusieur méthode. Tout d'abord nous allons marquer les cases que nous devons regarder car toute ne vont pas changer d'états (ex : Une case autour d'aucune case vivante ne changeras pas)
Puis sur c'est case nous allons compter le nombre de case vivante autour pour voir si elle changerons 
Pour finir nous mettons a jour notre grille pour afficher les nouveaux états.
Et on utilise la méthode qui vas l'afficher sur notre affichage graphique.

### Mode Console 
Le mode console contrairement au mode graphique n'affiche rien est a pour but d'enregistrer les états des grilles a chaque itération.
Elle va conserver dans notre programme la moitier de nos itération. Les fichier créer serons mis dans un dossier créer par notre utilisateur grace a notre code 
et les fichier aurons se type de nom <nom_du_fichier_dentree>_out.txt 
Tout d'abord nous allons créer notre grille et notre dossier .
Puis nous allons passez au itération . Contrairement aux mode graphique celui ci n'en a que deux si itération arrive a zéro ou que les états sont répétitif.
Comme dans le mode graphique nous allons compter et marquer les cases que l'on va regarder 
Seulement a la fin nous allons juste crée un fichier pour la grille actuelle de notre boucle.
## Axes d'amélioration

Optimisation de notre programme. Mettre en private certaint parametre pour plus de sécuriter 
Et encore optimiser notre observateur pour éviter de marquer les cases plusieurs fois 
Rajouter des extensions 
Récuperer tout les fichier pour le mode console et non pas que la premiere moitiers
// Voir se que rayane a modifier et ce qu'il na pas toucher




