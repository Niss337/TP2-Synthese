# TP2-Synthèse

Ce projet constitue un client TFTP permettant l'envoi et le téléchargement de fichiers. Il est conçu pour interagir avec un serveur TFTP, offrant une interface simple pour transférer des fichiers.

## Structure des Fichiers

Le projet se compose des fichiers suivants :

- **`main.c`** : Le point d'entrée principal du client TFTP. Ce fichier gère la logique de base et les commandes de l'utilisateur.
- **`tftp_utils.c` / `tftp_utils.h`** : Contient des fonctions utilitaires pour faciliter les opérations TFTP, telles que l'envoi et la réception de paquets.
- **`puttftp_utils.c` / `puttftp_utils.h`** : Fournit des fonctions spécifiques pour gérer les uploads de fichiers vers le serveur TFTP.
- **`pull.h`** : Fichier d'en-tête pour les opérations de téléchargement. Il contient des déclarations de fonctions pour récupérer des fichiers.
- **`constants.h`** : Définit les constantes utilisées tout au long du projet, comme les ports et les messages d'erreur.
- **`test.txt`** : Un fichier d'exemple créé pour tester les uploads et les téléchargements.
- **`gettftp`** : Exécutable pour télécharger des fichiers depuis le serveur TFTP.
- **`tftp_client`** : Exécutable pour envoyer des fichiers vers le serveur TFTP.
## Compilation du Client TFTP

```bash
gcc -o tftp_client main.c tftp_utils.c puttftp_utils.c -lnsl
