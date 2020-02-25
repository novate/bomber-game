#ifndef DATABASE_H
#define DATABASE_H

#include <unistd.h>
#include <iomanip>
#include <iostream>
#include <mysql/mysql.h>
#include <vector>
#include <string>
using namespace std;

// use singleton design
// example: https://sourcemaking.com/design_patterns/singleton/cpp/1
class DatabaseConnection
{
public:
	void DatabaseInit();
	bool check_account(string account_name); // check if an account is registered
	bool check_password(string account_name, string password);
	bool reset_password(string account_name, string password);
	static DatabaseConnection *obj;
	static DatabaseConnection *get_instance(); // return a class instance
	MYSQL_RES *MysqlExecCommand(string command);

private:
	uint64_t id;
	MYSQL *MysqlHandler;
};

#endif