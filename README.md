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


## Utilisation des Threads

### Qu'est-ce qu'un thread?

Un thread, ou fil d'exécution, est une unité d'exécution indépendante dans un programme. Chaque thread peut exécuter une tâche distincte en parallèle avec d'autres threads, permettant ainsi de réaliser des opérations simultanément. Cela peut améliorer les performances, surtout sur des systèmes multi-cœurs.

### Pourquoi utiliser des threads dans ce projet?

Les threads sont utilisés pour simuler les actions des philosophes de manière concurrente. Chaque philosophe est représenté par un thread qui effectue des cycles de réflexion, de prise de fourchette, de repas, et de repos. Les threads permettent de gérer ces actions simultanément, offrant une simulation plus réaliste.

### Exemple de Code

Voici un extrait de code montrant comment les threads sont créés et utilisés dans ce projet :

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "philo.h"

void *thread_function(void *arg) {
    // Logique du philosophe
    return NULL;
}

int main() {
    pthread_t thread;
    if (pthread_create(&thread, NULL, thread_function, NULL)) {
        fprintf(stderr, "Erreur de création du thread\n");
        return 1;
    }
    if (pthread_join(thread, NULL)) {
        fprintf(stderr, "Erreur de jonction du thread\n");
        return 2;
    }
    printf("Thread terminé\n");
    return 0;
}
```
### Synchronisation avec Mutex

La synchronisation est essentielle pour éviter les conditions de concurrence. Dans ce projet, les mutex sont utilisés pour protéger l'accès aux ressources partagées comme les fourchettes. Voici un exemple de leur utilisation :

```c
bool check_total_meals(t_philo *philo, t_data *data) {
    bool total_meals;

    total_meals = false;
    pthread_mutex_lock(&data->mutex_meals);
    if (philo->life.nbr_of_meals == philo->total_meals)
        total_meals = true;
    pthread_mutex_unlock(&data->mutex_meals);
    return (total_meals);
}
```

L'utilisation des threads nécessite une attention particulière à la gestion des ressources partagées et à la synchronisation pour éviter les conditions de concurrence. Des mécanismes comme les mutex sont utilisés pour synchroniser l'accès aux ressources partagées.


## Authors

- [@moouahab](https://github.com/moouahab)

