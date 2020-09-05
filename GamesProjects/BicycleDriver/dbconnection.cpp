#include <soci/soci.h>
#include <soci/mysql/soci-mysql.h>
#include "dbconnection.h"
#include "variable.h"
#include <string>
#include <sstream>
#include <iostream>
#include <exception>

using namespace std;

DbConnection::DbConnection()
{
    try
    {
        string str_port = to_string(port);
        string params;
        params.append("dbname='" + dbname + "' user='" + my_user + "' pass=" + pass);

        /*params.append("dbname='" + dbname + "' user='" + my_user + "' pass=" + pass + " host='" + server + "' port=");
        params.append(str_port);
        params.append(" connect_timeout=10 options='-c client_encoding=utf8'");*/

        sql = new soci::session(soci::mysql, params);
    }
    catch (soci::mysql_soci_error const& e)
    {
        cerr << "MySql error: " << e.err_num_
            << " " << e.what() << endl;
    }
    catch (exception const& e)
    {
        cerr << "Some other error: " << e.what() << endl;
    }
}

DbConnection::~DbConnection()
{
    (*sql).close();
    std::cout << "Destructor!!!!!! " << endl;
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
    users_map.clear();

    try {
        // Retrieve rows from users table
        soci::rowset<soci::row> rs = ((*sql).prepare << "SELECT * FROM users ORDER BY score DESC LIMIT 10");

        // Iterate through the result set
        for (soci::rowset<soci::row>::const_iterator it = rs.begin(); it != rs.end(); ++it) {
            const soci::row& r = *it;

            users_map.insert(std::pair<int, std::string>(r.get<int>(2), r.get<string>(1)));
        }
    }
    catch (soci::mysql_soci_error const& e)
    {
        cerr << "MySql error: " << e.err_num_
            << " " << e.what() << endl;
    }
    catch (exception const& e)
    {
        cerr << "Some other error: " << e.what() << endl;
    }

    return true;
}

bool DbConnection::write_score()
{
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
    int check = 0;
    int entry;

    try {
        soci::statement st = ((*sql).prepare << "SELECT EXISTS(SELECT * from `users` WHERE nickname='" + input_name + "');", 
            soci::into(entry));
        st.execute();

        if (st.fetch())
        {
            check = entry;
        }
    }
    catch (soci::mysql_soci_error const& e)
    {
        cerr << "MySql error: " << e.err_num_
            << " " << e.what() << endl;
        return false;
    }
    catch (exception const& e)
    {
        cerr << "Some other error: " << e.what() << endl;
        return false;
    }

    //puts("check_player_exists - Successful connection to database!");
    return check;
}

bool DbConnection::check_players_score()
{
    //check if score is bigger than existing one in database
    int query_score = 0;
    try {
        soci::statement st = ((*sql).prepare << "SELECT score from `users` WHERE nickname='" + input_name + "';",
            soci::into(query_score));
        st.execute();

        if (st.fetch())
        {
            std::cout << "query_score in check_player_exists is: " << query_score << endl;
        }
        else
        {
            std::cout << "There is no st.fetch() result!" << endl;
            return false;
        }
    }
    catch (soci::mysql_soci_error const& e)
    {
        cerr << "MySql error: " << e.err_num_
            << " " << e.what() << endl;
        return false;
    }
    catch (exception const& e)
    {
        cerr << "Some other error: " << e.what() << endl;
        return false;
    }

    if (score > query_score) return true;
            
    return false;
}

bool DbConnection::create_new_score()
{
    std::stringstream ss;
    ss << (score);
    string query2;

    query2.append("INSERT INTO `users` ( nickname, score ) VALUES ( '");
    query2.append(input_name);
    query2.append("', ");
    query2 += ss.str();
    query2.append(" );");
    std::cout << "query2 is: " << query2 << std::endl;

    try {
        soci::statement st = ((*sql).prepare << query2);
        st.execute();
    }
    catch (soci::mysql_soci_error const& e)
    {
        cerr << "MySql error: " << e.err_num_
            << " " << e.what() << endl;
        return false;
    }
    catch (exception const& e)
    {
        cerr << "Some other error: " << e.what() << endl;
        return false;
    }

    return true;
}

bool DbConnection::update_score()
{
    std::stringstream ss;
    ss << (score);
    string query2;

    query2.append("UPDATE users SET score = ");
    query2 += ss.str();
    query2.append(" WHERE nickname='");
    query2.append(input_name);
    query2.append("';");
    std::cout << "query2 is: " << query2 << std::endl;
    
    try {
        soci::statement st = ((*sql).prepare << query2);
        st.execute();
    }
    catch (soci::mysql_soci_error const& e)
    {
        cerr << "MySql error: " << e.err_num_
            << " " << e.what() << endl;
        return false;
    }
    catch (exception const& e)
    {
        cerr << "Some other error: " << e.what() << endl;
        return false;
    }

    return true;
}
