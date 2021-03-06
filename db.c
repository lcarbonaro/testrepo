#include <stdio.h>
#include <mysql.h>

int main(void)
{
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    
    char *server = "sql5.freesqldatabase.com";  // was: 0.0.0.0 for c9
    char *user = "sql551836";                   // was: lcarbonaro for c9            
    char *password = "hU9*tS5*";                // was: "" for c9
    char *database = "sql551836";               // was: "test" for c9

    char *sql;

    // just checking mysql library
    //printf("MySQL client version: %s\n", mysql_get_client_info());

    conn = mysql_init(NULL);

    // connect to database
    // assumes MySQL server is up and running, and that database exists
    if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0))  // last 3 parms port, socket, flag are defaults
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
    }
    else
    {
        // run sql query
        sql = "select * from `test`";    // sql command to fetch all records from table called test

        if (mysql_query(conn, sql))   // run the sql; zero (or false) means success; non-zero (or true) means error occurred
        {
            fprintf(stderr, "%s\n", mysql_error(conn));
        }
        else
        {
            //printf("SQL statement:%s\n",sql);  
            result = mysql_use_result(conn);  // assign query result to variable res

            // output query results
            printf("SQL results:\n");
            while ((row = mysql_fetch_row(result)) != NULL)
            {
                printf("%s: %s \n", row[0],row[1]);
            }
        }

        // free up result variable and close connection
        mysql_free_result(result);
        mysql_close(conn);
    }

    return 0;
}

// ref:
// http://jhrokku1022.wordpress.com/2013/09/11/codeblocks-c-in-win-7-connects-to-mysql-in-linux/ (method 2 for Code::Blocks set-up)
// note: also need to add libmysql to linker settings in code:blocks
// if compiling this manually using gcc add parms -I/usr/include/mysql -lmysqlclient (for c9)
// might need to "sudo apt-get install libmysqlclient-dev" to install mysql libs and header files
