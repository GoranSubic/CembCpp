/**
 *  Main function cpp - documenting code
 *
 */

#include "init.h"
#include "menu.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (!init_all())
        return 0;

    if (!load_files())
        return 0;

    int opt = start_menu();

    return 1;
}
