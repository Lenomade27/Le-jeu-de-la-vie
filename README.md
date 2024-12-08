# Le-jeu-de-la-vie
 ## Principe
   Le jeu de la vie désigne un automate cellulaire proposé par le mathématicien John Conway. Il décrit l’évolution d’une population de cellules sur un intervalle de temps discret. Les cellules placées dans une   
   grille rectangulaire deux dimensionnelle sont caractérisées par deux états ; elles sont soit vivantes, soit mortes. A l’exclusion des bordures, le voisinage d’une cellule est formé par 8 autres cellules 
   directement adjacentes. 
   
   Pour passer de l’itération  à l’itération t les règles suivantes : t +1 , l’état des cellules dans la grille est actualisé selon
   - Une cellule morte possédant exactement trois voisines vivantes devient vivante.
   - Une cellule vivante possédant deux ou trois voisines vivantes reste vivante, sinon elle meurt.

 ## Spécifications fonctionnelles
   1. L’utilisateur lance le programme et fournit le chemin du fichier contenant l’état initial des cellules en paramètre.
   2. Le programme consomme le fichier avec le format précédemment décrit et génère l’ensemble des  objets du programme (grille, cellules).
   3. A chaque itération les cellules changent d’état selon les règles énoncées plus haut.
   4. L’exécution se termine lorsque l’automate n’évolue plus ou après un nombre d’itération fixé arbitrairement.
   5. Deux modes de fonctionnement seront implémentés :
   - Le premier, en mode console, fournira les états des  premières itérations de votre jeu de la vie. A chaque itération le programme écrit l’état des cellules dans un fichier selon le format décrit   
   précedemment. Ces résultats sont stockés dans des dossiers nommés <nom_du_fichier_dentree>_out et utilisés pour correction.
   - Le second, en mode graphique, affiche la grille et l’état des cellules sur une interface graphique. Pour aboutir, vous disposez d’un exemple de code capable d’afficher une fenêtre graphique et une grille de
   cellules. Celui-ci devra être adapté en une version orientée objet. La simulation démarre au lancement du programme. La durée entre deux itérations est contrôlable.


 ## Extensions
   1. Gestion d’une grille torique. Les cellules placées aux extrémités de la grille sont adjacentes ; en d’autres termes les cellules en colonne 0 sont voisines des cellules en colonne N-1 avec N nombre de 
   colonnes. Le principe est similaire en ligne.
   2. Introduction de cellules obstacle. L’état des cellules obstacles n’évolue pas au cours de l’exécution. Ces dernières possèdent un état vivant ou mort. Modifiez votre code, sans altérer le fonctionnement de 
   base.
