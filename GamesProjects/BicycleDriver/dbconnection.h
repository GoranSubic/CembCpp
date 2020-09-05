#ifndef BIKES_DBCONNECTION_H
#define BIKES_DBCONNECTION_H

#include <mysql.h>
#include <map>
#include <string>
#include "constants.h"

using namespace std;

class StorageData {
protected:
	StorageData() {};
public:
	virtual ~StorageData() {};

	/// <summary>
	/// Initialize storage for data:
	/// if const SAVE_DATA_TO is 1(mysql db) or 0(file)
	/// </summary>
	/// <returns>Pointer to StorageData object</returns>
	static StorageData* init_data_storage();
	virtual bool fill_users_map() = 0;
	virtual bool write_score() = 0;
	virtual bool check_player_exists() = 0;
	virtual bool check_players_score() = 0;
	virtual bool create_new_score() = 0;
	virtual bool update_score() = 0;
	multimap<int, string> users_map;
};

class FileConnection : public StorageData {
public:
	FileConnection() {};
	~FileConnection() {};
	bool fill_users_map() override { return true; };
	bool write_score() override { return true; };
	bool check_player_exists() override { return true; };
	bool check_players_score() override { return true; };
	bool create_new_score() override { return true; };
	bool update_score() override { return true; };
};

class DbConnection : public StorageData {
public:
	DbConnection();
	~DbConnection();

	/// <summary>
	/// List registered users
	/// </summary>
	/// <returns>true if results, false on empty or error</returns>
	bool fill_users_map() override;

	/// <summary>
	/// Get input_name and write new score for user (if exists) to database
	/// If user not exists than write new user to database
	/// </summary>
	/// <returns>True on success</returns>
	bool write_score() override;
	bool check_player_exists() override;
	bool check_players_score() override;
	bool create_new_score() override;
	bool update_score() override;
private:
	const char* server = "localhost";
	const char* my_user = "root";
	const char* pass = "Passw0rd";
	const string dbname = "bicycler";
	const int port = 3306;
	const char* my_unix_socet = NULL;
	unsigned long clientflag = 0;
};

#endif