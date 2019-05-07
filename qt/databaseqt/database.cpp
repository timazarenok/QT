#include "database.h"



Database::Database(QObject *parent): QObject(parent)
{
    if(!QFile(DATABASE_PATH).exists())
        {
            restoreDataBase();
        }
        else
        {
            openDataBase();
        }
}

void conect_to_database()
{

}
bool openDataBase()
{

}
bool restoreDataBase()
{

}
void closeDataBase()
{

}
bool createTable()
{

}

