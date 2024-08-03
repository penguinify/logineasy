#include "lib.h"
#include "conf.h"
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int print_dir(char *path) {
    DIR *d = opendir(path);

    if (d == NULL) {
        printf("Could not access \"%s\".\n", path);
        return 1;
    }

    struct dirent *de;

    while ((de = readdir(d)) != NULL) {
        char firstchar = de->d_name[0];
        if (firstchar == '.')
            continue;

        printf("  %s\n", de->d_name); 
    }

    closedir(d);

    return 0;
}

void print_named_paths(struct NamedPath *paths) {
    
    size_t pathsize = sizeof(&paths);

    for (int i = 0; i * 24 < pathsize; i += 1 ) {
        struct NamedPath path = paths[i];

        printf("%s (%s)\n", path.name, path.path);

        char subpath[256];
        if (path.syspath == 0) {
            snprintf(subpath, sizeof(subpath), "%s%s", getenv("HOME"), path.path);
        } else {
            snprintf(subpath, sizeof(subpath), "%s", path.path);
        }
        
        if (print_dir(subpath) != 0) {
            printf("Error Printing Directory!\n");
            return;
        }
    }

}

void print_help() {
    printf("Usage: logineasy [options]\n");
    printf("Remove and add login items through the CLI for OSX/Darwin\n");
    printf("  -h --help     Show this help message :)\n");
    printf("  -v --version  Print the app version\n\n");

    printf("  -l --list     List out launch agents and launch daemons\n");
    printf("  --list-lg     List out launch agents\n");
    printf("  --list-ld     List out launch daemons\n\n");

    printf("  -n --new      Create a new login item\n");
    
}

void print_version() {
    printf("logineasy %s\n", VERSION);
}
