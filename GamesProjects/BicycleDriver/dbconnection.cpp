#include "dbconnection.h"
#include "variable.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

DbConnection::DbConnection()
{
    /*int qstate;
    row = NULL;
    res = NULL;*/

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, server, my_user, pass, dbname, port, my_unix_socet, clientflag);

    //fill_users_map();
}

StorageData* StorageData::init_data_storage()
{
    StorageData* connected_to;
    if (SAVE_DATA_TO) {
        connected_to = new DbConnection;
    } else {
        connected_to = new FileConnection;
    }
    return connected_to;
}

bool DbConnection::fill_users_map()
{
    if (!conn) {
        puts("Connection to database has failed!");
        return false;
    }
    puts("Successful connection to database!");
    
    string query = "SELECT * FROM users ORDER BY score DESC LIMIT 10";
    const char* q = query.c_str();

    qstate = mysql_query(conn, q);
    if (qstate)
    {
        cout << "Query failed: " << mysql_error(conn) << endl;
        return false;
    }
    res = mysql_store_result(conn);

    users_map.clear();
    while (row = mysql_fetch_row(res))
    {
        users_map.insert(std::pair<std::string, std::string>(row[2], row[1]));
    }
    
    mysql_free_result(res);  // Free buffer (after processing every result) 

    return true;
}

bool DbConnection::write_score()
{
    if (!conn) {
        puts("Connection to database has failed!");
        return false;
    }
    puts("write_score - Successful connection to database!");
        
    if (store_data->check_player_exists())
    {
        //check if score is bigger than existing one in database
        if (store_data->check_players_score())
        {
            //if it is bigger than update
            store_data->update_score();
        }
        else
            puts("Score for this user is less than one in database!");

    }
    else
    {
        //insert
        store_data->create_new_score();
    }

    return true;
}

bool DbConnection::check_player_exists()
{
    int check;

    if (!conn) {
        puts("Connection to database has failed!");
        return false;
    }
    puts("check_player_exists - Successful connection to database!");

    string query_check = "SELECT EXISTS(SELECT * from `users` WHERE nickname='" + input_name + "');";
    const char* q1 = query_check.c_str();
    qstate = mysql_query(conn, q1);
    if (qstate)
    {
        std::cout << "Query failed: " << mysql_error(conn) << std::endl;
        return false;
    }
    std::cout << "SELECT EXISTS qstate is: " << qstate << std::endl;

    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);
    check = atoi(row[0]);
    mysql_free_result(res);

    std::cout << "row[0] in check_player_exists is: " << row[0] << endl;
    std::cout << "check in check_player_exists is: " << check << endl;

    return check;
}

bool DbConnection::check_players_score()
{
    //check if score is bigger than existing one in database

    string query_score = "SELECT score from `users` WHERE nickname='" + input_name + "';";
    const char* q11 = query_score.c_str();
    qstate = mysql_query(conn, q11);
    std::cout << "SELECT score's qstate is: " << qstate << std::endl;
    if (qstate)
    {
        std::cout << "Query failed: " << mysql_error(conn) << std::endl;
        return false;
    }
    puts("check_players_score - Successful connection to database!");

    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);
    string score_to_check = row[0];
    mysql_free_result(res);
    std::cout << "SELECT score_to_check value is: " << stoi(score_to_check) << std::endl;

    if (stoi(score_to_check) < score) return true;
            
    return false;
}

bool DbConnection::create_new_score()
{
    if (!conn) {
        puts("Connection to database has failed!");
        return false;
    }
    puts("Successful connection to database!");


    std::stringstream ss;
    ss << (score);
    string query2;

    query2.append("INSERT INTO `users` ( nickname, score ) VALUES ( '");
    query2.append(input_name);
    query2.append("', ");
    query2 += ss.str();
    query2.append(" );");
    std::cout << "query2 is: " << query2 << std::endl;

    const char* q2 = query2.c_str();
    qstate = mysql_query(conn, q2);
    std::cout << "Update or INSERT qstate is: " << qstate << std::endl;
    if (qstate)
    {
        std::cout << "Query failed: " << mysql_error(conn) << std::endl;
        return false;
    }

    return true;
}

bool DbConnection::update_score()
{
    if (!conn) {
        puts("Connection to database has failed!");
        return false;
    }
    puts("update_score - Successful connection to database!");

    std::stringstream ss;
    ss << (score);
    string query2;

    
    query2.append("UPDATE users SET score = ");
    query2 += ss.str();
    query2.append(" WHERE nickname='");
    query2.append(input_name);
    query2.append("';");
    std::cout << "Query UPDATE: " << mysql_error(conn) << std::endl;
    

    std::cout << "query2 is: " << query2 << std::endl;

    const char* q2 = query2.c_str();
    qstate = mysql_query(conn, q2);
    std::cout << "Update or INSERT qstate is: " << qstate << std::endl;

    if (qstate)
    {
        std::cout << "Query failed: " << mysql_error(conn) << std::endl;
        return false;
    }

    return true;
}
