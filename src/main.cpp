#include "Application.h"
#include "UI.h"

int main(int argc, char *argv[])
{
    Application *app;
    UI interface;

    if(argc < 2)
    {
        interface.showError("Unexpected number of parameters");
        return 1;
    }

    app = new Application(argv[1]);
    app->execute();

    delete app;

    return 0;
}