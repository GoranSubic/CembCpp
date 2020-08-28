/**
 *  Main function cpp - documenting code
 *
 */

#include "dbconnection.h"
#include "variable.h"
#include "init.h"
#include "menu.h"

using namespace std;

int main(int argc, char* argv[])
{
    if ((store_data = StorageData::init_data_storage()) == NULL)
        return 0;
    store_data->fill_users_map();

    if (!init_all())
        return 0;

    if (!load_files())
        return 0;

    int opt = start_menu();

    delete store_data;

    return 1;
}
