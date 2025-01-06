# TP2-Synthese

Le projet se compose des fichiers suivants :

main.c : Le point d'entrée principal du client TFTP.
tftp_utils.c / tftp_utils.h : Fonctions utilitaires pour les opérations TFTP.
puttftp_utils.c / puttftp_utils.h : Fonctions pour gérer les uploads de fichiers.
pull.h : Fichier d'en-tête pour les opérations de téléchargement.
constants.h : Constantes utilisées dans tout le projet.
test.txt : Fichier d'exemple créé pour tester les uploads.
gettftp : Exécutable pour télécharger des fichiers.
tftp_client : Exécutable pour envoyer des fichiers.
Pour compiler le client TFTP, naviguez vers le répertoire du projet et exécutez :
gcc -o tftp_client main.c tftp_utils.c puttftp_utils.c -lnsl
Envoyer un Fichier
Pour envoyer un fichier au serveur TFTP, utilisez la commande puttftp suivie de l'adresse du serveur et du nom du fichier :

bash

./tftp_client puttftp localhost test.txt
Sortie Attendue :


File transfer completed successfully


Télécharger un Fichier
./tftp_client gettftp localhost ones1024
Received block 1
Received block 2
Received block 3
...
File transfer complete.
