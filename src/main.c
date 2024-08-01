#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <dirent.h>
#include <string.h>

#define VERSION "v0.1"
#define OK 0
#define ERROR 1

struct NamedPath {
    char *name;
    char *path;
    int syspath;
};

struct NamedPath launchagents[2] = 
{
    {"Login Items (User)","/Library/LaunchAgents",0},
    {"Login Items (System)","/System/Library/LaunchAgents",1}
};


struct NamedPath launchdaemons[1] = 
{
    {"Launch Daemons (System)","/System/Library/LaunchDaemons",1}
};

int print_dir(char *path) {
    DIR *d = opendir(path);

    if (d == NULL) {
        printf("Could not access \"%s\".\n", path);
        return ERROR;
    }

    struct dirent *de;

    while ((de = readdir(d)) != NULL) {
        char firstchar = de->d_name[0];
        if (firstchar == '.')
            continue;

        printf("  %s\n", de->d_name); 
    }

    closedir(d);

    return OK;
}


void print_help() {
    printf("Usage: logineasy [options]\n");
    printf("Remove and add login items through the CLI for OSX/Darwin\n");
    printf("  -h --help     Show this help message :)\n");
    printf("  -v --version  Print the app version\n");
    printf("  -l --list     List out launch agents and launch daemons\n");
    printf("  --list-lg     List out launch agents\n");
    printf("  --list-ld     List out launch daemons\n");
    
}

void print_version() {
    printf("logineasy %s\n", VERSION);
}

void print_launchagents() {
    for (int i = 0; i * 24 < sizeof(launchagents); i += 1 ) {
        struct NamedPath agent = launchagents[i];

        printf("%s (%s)\n", agent.name, agent.path);

        char *path;
        if (agent.syspath == 0) {
            path = strcat(getenv("HOME"), agent.path);
        } else {
            path = agent.path;
        }
        
        if (print_dir(path) != 0) {
            printf("Error Printing Directory!\n");
            return;
        }
    }

}

void print_launchdaemons() {
    for (int i = 0; i * 24 < sizeof(launchdaemons); i += 1 ) {
        struct NamedPath daemon = launchdaemons[i];

        printf("%s (%s)\n", daemon.name, daemon.path);

        char *path;
        if (daemon.syspath == 0) {
            path = strcat(getenv("HOME"), daemon.path);
        } else {
            path = daemon.path;
        }
        
        if (print_dir(path) != 0) {
            printf("Error Printing Directory!\n");
            return;
        }
    }

}


int parse_args(int argc, char *argv[]) {
    int opt;
    int opt_index;

    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
        {"l", no_argument, 0, 'l'},
        {"list-lg", no_argument, 0, 0},
        {"list-ld", no_argument, 0, 0},
        {0, 0, 0, 0}
    };
    while ((opt = getopt_long(argc, argv, "hvl", long_options, &opt_index)) != -1) {
    switch (opt) {
        case 'h':
            print_help();
            return OK;
        case 'v':
            print_version();
            return OK;
        case 'l':
            print_launchagents();
            print_launchdaemons();
            return OK;
        case 0:
            if (strcmp(long_options[opt_index].name, "list-lg") == 0) {
                print_launchagents();
                return OK;
            } else if (strcmp(long_options[opt_index].name, "list-ld") == 0) {
                print_launchdaemons();
                return OK;
            }

            break;
        default:
            return ERROR;
    }
    }

    if (optind == 1) {
        return ERROR;
    }

    return OK;
}

int main(int argc, char *argv[]) {
    int result = parse_args(argc, argv);

    if (result != OK) {
        print_help();
    }
}
