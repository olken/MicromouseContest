#Source Microcontrolleur

Microcontrolleur Atmega328P

####Liste des fichiers :
  * **Init.c :**  
    Initialise les registre afin de configurer correctement le fonctionnement du µC (Source Clock...).    
  * **I2C_Slave.c :**  
    Gére la communication I2C avec la raspberry-pi.  
  * **Moteur.c :**  
    Fonction necessaire au contrôle des moteur, comprend la generation du signal PWM ainsi que la fonction d'asservissement.
  * **test_X.c**
    Fichier de test des différentes fonction contenue dans le fichier X.
  * **Global.h**
    Contient les définitions communes à tous les fichiers, ainsi que les paramétres et permet de choisir quelle fonction main va être compilé. (Afin de crée un unique projet Atmel Studio). 
  * **Main.c :**  
    Fonction principale qui structure l'ensemble de l'algoritme.
