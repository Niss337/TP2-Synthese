# TP2-Synthèse

Ce projet constitue un client TFTP pour l'envoi et le téléchargement de fichiers. Voici la structure des fichiers et les instructions d'utilisation.

## Structure des Fichiers

Le projet se compose des fichiers suivants :

- **`main.c`** : Le point d'entrée principal du client TFTP.
- **`tftp_utils.c` / `tftp_utils.h`** : Fonctions utilitaires pour les opérations TFTP.
- **`puttftp_utils.c` / `puttftp_utils.h`** : Fonctions pour gérer les uploads de fichiers.
- **`pull.h`** : Fichier d'en-tête pour les opérations de téléchargement.
- **`constants.h`** : Constantes utilisées dans tout le projet.
- **`test.txt`** : Fichier d'exemple créé pour tester les uploads.
- **`gettftp`** : Exécutable pour télécharger des fichiers.
- **`tftp_client`** : Exécutable pour envoyer des fichiers.

## Compilation du Client TFTP

Pour compiler le client TFTP, naviguez vers le répertoire du projet et exécutez la commande suivante :

```bash
gcc -o tftp_client main.c tftp_utils.c puttftp_utils.c -lnsl
