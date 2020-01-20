/*************************************************************************
	> File Name: datebase.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月20日 星期一 20时31分33秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

static int callback(void *NOTUsed, int argc, char **argv, char **azColName)
{
    int i;
    for(i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char **argv)
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    char sql_str[1024];

    //open sqlite3 db
    rc = sqlite3_open("test.db", &db);
    if(rc)
    {
        fprintf(stderr, "Can't open database : %s \n", sqlite3_errmsg(db));
        exit(0);
    }
    else{
        printf("Opened database successfully\n");
    }

    //create sql statement
    sql = "CREATE TABLE IF NOT EXISTS class(\
            ID  INT PRIMARY KEY NOT NULL, \
            X1  INT ,\
            Y1  INT ,\
            X2  INT ,\
            Y2  INT ,\
            white_counter  INT ,\
            black_counter  INT ,\
            threshold      INT);";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error : %s\n", zErrMsg);
    }
    else{
        printf("Table created successfully\n");
    }

    //insert database
    sql = "insert into class (ID, X1, Y1, X2, Y2) values (3, 33, 44, 55, 66); \
        insert into class (ID, X1, Y1, X2, Y2) values (4, 33, 44, 55, 66); \
        insert into class (ID, X1, Y1, X2, Y2) values (5, 33, 44, 55, 66); \
        insert into class (ID, X1, Y1, X2, Y2) values (6, 33, 44, 55, 66);";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL insert error : %s\n", zErrMsg);
    }
    else{
        printf("Table insert successfully\n");
    }

    //update database
    sql = "update class set X1 = 88 where ID = 6; \
            select * from class;";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL insert error : %s\n", zErrMsg);
    }
    else{
        printf("Table insert successfully\n");
    }

    memset(sql_str, 0, sizeof(sql_str));
    //replace(update and insert)
    snprintf(sql_str, sizeof(sql_str), "replace into class \
            (ID, X1, Y1, X2, Y2, white_counter, black_counter, threshold) \
            values (%d, %d, %d, %d, %d, %d, %d, %d)", \
            1, 22, 33, 44, 55, 123, 55, 79);
    rc = sqlite3_exec(db, sql_str, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL replace error : %s\n", zErrMsg);
    }
    else{
        printf("Table replace successfully\n");
    }
    memset(sql_str, 0, sizeof(sql_str));
    //insert id = 2
    snprintf(sql_str, sizeof(sql_str), "replace into class \
            (ID, X1, Y1, X2, Y2, white_counter, black_counter, threshold) \
            values (%d, %d, %d, %d, %d, %d, %d, %d)", \
            2, 220, 330, 440, 550, 123, 55, 79);
    rc = sqlite3_exec(db, sql_str, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL replace error : %s\n", zErrMsg);
    }
    else{
        printf("Table replace successfully\n");
    }
    memset(sql_str, 0, sizeof(sql_str));
    
    //query sqlite3
    sprintf(sql_str, "select * from class;");
    rc = sqlite3_exec(db, sql_str, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL select error : %s\n", zErrMsg);
    }
    else{
        printf("Table select successfully\n");
    }

    //delete id =2
    sql = "DELETE from class where ID=2; select * from class";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL delete error : %s\n", zErrMsg);
    }
    else{
        printf("Table delete successfully\n");
    }

    
    //close sql
    sqlite3_close(db);

    return 0;
}
