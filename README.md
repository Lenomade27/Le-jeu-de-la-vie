
# **Le Jeu de la Vie - Implémentation en C++ avec une interface graphique** 🧬

## **Description du Projet** 📝

Le **Jeu de la Vie**, conçu par le mathématicien John Conway, est un automate cellulaire simulant l'évolution d'une population de cellules selon des règles précises. Ce projet met en œuvre une version en **C++**, exploitant les principes de la **programmation orientée objet (POO)**, avec une interface graphique basée sur la bibliothèque **SFML**.

---

## **Caractéristiques Principales** ⚙️

- **Simulation basée sur les règles classiques :**
  - Une cellule morte possédant exactement trois voisines vivantes devient vivante.
  - Une cellule vivante avec deux ou trois voisines vivantes reste vivante; sinon, elle meurt.
- **Lecture des configurations initiales depuis un fichier texte.**
- **Deux modes de simulation :**
  1. **Mode console :** Exporte les résultats de simulation sous forme de fichiers.
  2. **Mode graphique :** Affiche une simulation interactive en temps réel.
- **Extensions avancées :**
  - Grille torique (les bords opposés de la grille sont connectés).
  - Cellules obstacles (fixes, vivantes ou mortes).

---

## **Dépendances** ⛓️
- **Langage :** C++ standard (C++11 ou supérieur)
- **Bibliothèque graphique :** [SFML](https://www.sfml-dev.org/)
- **STL C++ :** Utilisation des structures et algorithmes standards.

---

## **Installation et Exécution** 💻

### **1. Cloner le dépôt**
```bash
git clone https://github.com/Lenomade27/Le-jeu-de-la-vie.git
cd Le-jeu-de-la-vie
```

### **2. Installer les dépendances nécessaires**

#### **Installation de SFML**
- **Sous Ubuntu :**
  ```bash
  sudo apt-get update
  sudo apt-get install libsfml-dev

#### **Installation de Clang et Make**
- **Sous Ubuntu :**
  ```bash
  sudo apt-get install clang make
  ```

### **3. Compiler le projet avec Make**

Une fois les dépendances installées, compilez le projet à l'aide du **Makefile** :
1. Nettoyez les anciens fichiers compilés (si nécessaire) :
   ```bash
   make clean
   ```
2. Compilez le projet :
   ```bash
   make
   ```
3. Exécutez le programme :
   - **Mode console :**
     ```bash
     cd bin
     ./main <chemin_fichier_configuration> console <chemin_fichier_ecriture>
     ```
   - **Mode graphique :**
     ```bash
     cd bin
     ./main <chemin_fichier_configuration> graphique <durée_itération>
     ```

---

## **Structure du Dépôt** 🌳

### **Répertoire racine**
- `README.md` : Documentation du projet.

### **Arborescence**
```
Le-jeu-de-la-vie/
├── docs/                  # Documentation (diagrammes UML, guide, etc.)
├── src/                   # Code source
│   ├── main.cpp           # Point d'entrée du programme
│   ├── jeux_de_la_vie.cpp # Logique principale du jeu
│   ├── grille.cpp         # Gestion de la grille et des cellules
│   └── ...                # Autres fichiers source
├── include/               # Fichiers d'en-tête
│   ├── jeux_de_la_vie.h   # Déclaration des classes
│   └── ...
├── assets/                # Ressources
│   ├── examples/          # Fichiers d'état initial de la grille
│   └── ...
├── tests/                 # Tests unitaires & mode console

```
---

## **Diagrammes UML** 🔲

Les diagrammes suivants sont inclus dans le répertoire `docs/` :
- **Diagramme de cas d'utilisation** : Explique les interactions utilisateur.
- **Diagramme de classes** : Représente les relations entre les objets du système.
- **Diagramme d'activité** : Décrit le flux d'exécution du programme.
- **Diagramme de séquence** : Illustre les échanges entre objets lors de la simulation.

---

## **Licence** ✒️

Ce projet est sous licence [MIT](./LICENSE).

---

## **Contact** 📧

Pour toute question ou suggestion, veuillez ouvrir une **issue** sur ce dépôt.

---

 **Merci de votre intérêt pour ce projet ! Amusez-vous bien avec le Jeu de la Vie !** 💪
