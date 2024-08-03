#include "conf.h"

struct NamedPath launchagents[2] = 
{
    {"Login Items (User)","/Library/LaunchAgents",0},
    {"Login Items (System)","/System/Library/LaunchAgents",1}
};

struct NamedPath launchdaemons[1] = 
{
    {"Launch Daemons (System)","/System/Library/LaunchDaemons",1}
};
