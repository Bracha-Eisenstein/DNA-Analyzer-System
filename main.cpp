#include "controller/controller.h"
#include "view/interface/cli.h"
int main()
{
    Data d;
    Cli c;    
    Controller controller(&c, &d);
    controller.start();
    controller.run();
    controller.exit();
    return 0;
}
