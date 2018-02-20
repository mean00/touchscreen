
#include "screen.h"
#include "vector"
typedef Screen *ScreenSpawner(const char **args);
typedef struct screenEntry
{
    const char      *screenName;
    ScreenSpawner   *spawner;
    int             nbArg;
};

class ScreenManager
{
public:
             ScreenManager(Ucglib *theucg);
        bool spawnScreen(const char *name, int nb, const char **arg);
        bool clicked(int x,int y);
        bool registerScreen(const char *name, int nbArgs,ScreenSpawner *spawner );
        bool redraw();
protected:
        Screen *currentScreen;
        std::vector <screenEntry *>entries;
        Ucglib *ucg;
};