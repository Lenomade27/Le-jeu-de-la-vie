
# Livrable 2 – Groupe 5 (version avec illustration en dépot Moodle)

Dans le cadre de notre projet, nous avons utilisé des outils de modélisation, de gestion de versions et les principes de la programmation orientée objet (POO) pour concevoir et implémenter une solution fiable et robuste. Ce livrable détaille les étapes essentielles de la maquette et de la modélisation, tout en répondant aux critères fixés par le cahier des charges.

## Les Diagrammes UML : Pourquoi et Comment ?

Le langage UML (Unified Modeling Language) est un outil essentiel pour représenter la structure et le fonctionnement d’un système. C’est ainsi que nous avons utilisé quatre types de diagrammes UML pour documenter notre projet :

### Diagramme de cas d’utilisation :
- **Objectif :** Montrer comment les utilisateurs interagissent avec le système.
- Description : 
    - L’utilisateur du jeu de la vie peut lancer une simulation. 
    - Des étapes telles qu’indiquer l’emplacement du fichier d’initialisation ou le choix d’un mode sont nécessaires et conditionnent le lancement de la simulation.
    - Le choix des modes s’étend aux 2 fonctionnalités proposées par le mode console et le mode graphique.

### Diagramme de séquence :
- **Objectif :** Illustrer les interactions entre les différents composants du système et leur enchaînement logique.
- Description : 
    - Utilisation de 4 lignes de vies : l’utilisateur et les composants du modèle MVC.
    - Certaines étapes sont optionnelles (signifiées par le mot-clé OPT). 
    - Variables : `n` (nombre d’itérations avant arrêt d’écriture) et `nmax` (itérations maximales).

### Diagramme d’activités :
- **Objectif :** Décrire les processus dynamiques du système, notamment les étapes clés des fonctionnalités principales.
- Description : 
    - Succession d’étapes proche du diagramme de séquence.
    - Utile pour passer à une vision algorithmique, bien que limitée par l’absence d’une vision étoffée des classes.

### Diagramme de classes :
- **Objectif :** Représenter la structure statique du système (classes, attributs, méthodes et relations).
- Description :
    - Création des classes, intégration de design patterns, et définition des dépendances interclasse.
    - Découpage des fonctions métiers pour une meilleure conception du code.

## Respect du Pattern MVC (Modèle-Vue-Contrôleur)
Le pattern MVC a été utilisé pour structurer notre application :
- **Modèle :** Contient les données et la logique fonctionnelle.
- **Vue :** Responsable de l’affichage des données aux utilisateurs.
- **Contrôleur :** Gère les interactions entre le Modèle et la Vue.

Cette séparation permet une meilleure maintenance du code et facilite les tests.

## Environnement de Travail : Git et GitHub

### Git : Un outil indispensable
- **Fonctionnalités :**
    - Suivi de l’évolution du projet grâce à un historique clair.
    - Travail collaboratif en évitant les conflits de code.
    - Gestion des branches pour le développement et les tests.

### GitHub : Hébergement collaboratif
- **Avantages :**
    - Hébergement du dépôt Git pour le partage des branches et des commits.
    - Collaboration efficace avec une transparence totale.

**Pratiques appliquées :**
- Commit régulier avec des messages descriptifs.
- Branches personnelles pour un travail structuré.
- Pull requests pour valider les changements.

## Programmation Orientée Objet (POO)
Nous avons mis en œuvre les principes suivants :
- **Encapsulation :** Protection des données grâce à des classes bien définies.
- **Héritage :** Réutilisation de code pour les classes partageant des fonctionnalités communes.
- **Polymorphisme :** Adaptabilité des objets pour répondre à différents contextes.

## Test Unitaires : Notion explorée
Bien que les tests unitaires ne soient pas inclus dans ce livrable, nous avons étudié leur importance pour garantir la fiabilité du code et utilisé ces tests pour franchir des paliers de validation de certaines régions du code.

