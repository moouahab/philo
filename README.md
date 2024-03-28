# Philosophers
La simulation du Dîner des Philosophes est un projet visant à modéliser de manière informatique le célèbre problème philosophique, où des philosophes se disputent des ressources limitées dans un contexte de repas, mettant en lumière les défis de la concurrence et de la coopération

#### objectif du projet 

-    Maîtriser la création et la gestion des threads : Utiliser les threads pour représenter chaque philosophe et permettre une exécution asynchrone des actions.
-    Compréhension et mise en œuvre des mutex : Utiliser des mutex pour protéger l'accès aux ressources partagées telles que les fourchettes, afin d'éviter les conditions de concurrence et garantir la cohérence des données.
-   Cretion du temps et événements asynchrones : Mettre en œuvre la logique de gestion du temps pour surveiller les événements asynchrones tels que le temps écoulé depuis le dernier repas de chaque philosophe et détecter les décès éventuels.

-    Programmation concurrente : Comprendre et appliquer les concepts de programmation concurrente pour coordonner les actions des threads et éviter les courses de données.

 -   Synchronisation et communication entre threads : Apprendre à synchroniser et à communiquer entre les threads pour coordonner les activités des philosophes, en utilisant des mécanismes tels que les mutex et les variables conditionnelles.

 -   Optimisation des performances et de la fiabilité : Optimiser les performances et la robustesse du programme pour une simulation efficace et fiable du dîner des philosophes dans divers scénarios, tout en maintenant une approche asynchrone et sans blocage grâce à l'utilisation de threads.
#### Function Autoriser 


| Fonction              | Description                                                                                                           | Valeur de Retour |
|-----------------------|-----------------------------------------------------------------------------------------------------------------------|------------------|
| `usleep`              | Suspend l'exécution du programme pendant un certain nombre de microsecondes.                                          | 0 si réussi, -1 en cas d'erreur |
| `gettimeofday`        | Récupère le temps écoulé depuis une date de référence (epoch) sous forme de struct timeval.                          | 0 si réussi, -1 en cas d'erreur |
| `pthread_create`      | Crée un nouveau thread qui exécute une fonction spécifiée.                                                            | 0 si réussi, code d'erreur POSIX en cas d'échec |
| `pthread_detach`      | Détache un thread, permettant au système d'exploitation de récupérer automatiquement les ressources associées à ce thread une fois qu'il a terminé son exécution. | 0 si réussi, code d'erreur POSIX en cas d'échec |
| `pthread_join`        | Attend la fin d'exécution d'un thread spécifié et récupère la valeur de retour de ce thread.                           | 0 si réussi, code d'erreur POSIX en cas d'échec |
| `pthread_mutex_init`  | Initialise un mutex, un objet de synchronisation utilisé pour protéger les sections critiques du code contre l'accès simultané par plusieurs threads. | 0 si réussi, code d'erreur POSIX en cas d'échec |
| `pthread_mutex_destroy` | Détruit un mutex, libérant les ressources associées.                                                                 | 0 si réussi, code d'erreur POSIX en cas d'échec |
| `pthread_mutex_lock`   | Bloque le mutex, permettant à un thread de sécuriser l'accès à une section critique du code.                        | 0 si réussi, code d'erreur POSIX en cas d'échec |
| `pthread_mutex_unlock` | Débloque le mutex, permettant à d'autres threads de sécuriser l'accès à la section critique du code une fois qu'un thread a terminé son travail. | 0 si réussi, code d'erreur POSIX en cas d'échec |
