#include <getopt.h>
#include <dirent.h>
#include <string.h>

#include "lib.h"
#include "conf.h"
#include "main.h"


int parse_args(int argc, char *argv[]) {
    int opt;
    int opt_index;

    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
        {"l", no_argument, 0, 'l'},
        {"list-lg", no_argument, 0, 0},
        {"list-ld", no_argument, 0, 0},
        {"new", no_argument, 0, 'n'},
        {0, 0, 0, 0}
    };
    while ((opt = getopt_long(argc, argv, "hvln", long_options, &opt_index)) != -1) {
    switch (opt) {
        case 'h':
            print_help();
            return 0;
        case 'v':
            print_version();
            return 0;
        case 'l':
            print_named_paths(launchagents);
            print_named_paths(launchdaemons);

            return 0;
        case 0:
            if (strcmp(long_options[opt_index].name, "list-lg") == 0) {
                print_named_paths(launchagents);
                return 0;
            } else if (strcmp(long_options[opt_index].name, "list-ld") == 0) {
                print_named_paths(launchdaemons);
                return 0;
            }

            break;
        default:
            return 1;
    }
    }

    if (optind == 1) {
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int result = parse_args(argc, argv);

    if (result != 0) {
        print_help();
    }
}
