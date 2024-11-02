#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void display_prompt() {
    char cwd[PATH_MAX];
    char *username = getenv("USER");
    char hostname[HOST_NAME_MAX];

    // Récupérer le nom d'hôte
    gethostname(hostname, sizeof(hostname));
	int	i = 0;
    // Récupérer le répertoire courant
    if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s@", username);
		while(hostname[i] != '.')
		{
			printf("%c", hostname[i]);
			i++;
		}
		printf(":~%s$ \n", cwd + 14);
	}
	else
	{
		perror("getcwd() error");
	}
	printf("\n\n\n\n\n\n\%s", hostname);
}

int main() {
        display_prompt();
        // Ajoutez ici la logique pour lire les commandes, exécuter des processus, etc.
        // Utilisez readline pour lire l'entrée de l'utilisateur.
    return 0;
}



