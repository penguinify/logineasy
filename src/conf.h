#ifndef CONF_H
#define CONF_H

#define VERSION "v0.1"
struct NamedPath {
    char *name;
    char *path;
    // 0 will concat with $HOME, 1 will not.
    int syspath;

};
extern struct NamedPath launchagents[2];
extern struct NamedPath launchdaemons[1];

#endif // LIB_H
