#include "user.h"
// 存放链表的表头
static User* userLinkedHead = NULL;
// 存放当前记录的结构体地址
static User* userCurrent = NULL;

void userDemo(void) {
    // 获取用户链表
    char sql_str[] = "select * from user;";
    User* userLinked = getUserLinked(sql_str);
    // 打印用户链表
    printUserLinked(userLinked);
    // 释放用户链表
    freeUserLinked(userLinked);
}

static int normal_callback(void* NOTUsed, int argc, char** argv, char** azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

// 查询数据库时的回调函数
static int select_callback(void* data, int col_count, char** col_values, char** col_name) {
    int i;
    userCurrent = (User *)calloc(1, sizeof(User));
    for (i = 0; i < col_count; i++) {
        if (strcmp(col_name[i], "ID") == 0) {
            userCurrent->data.id = atoi(col_values[i]);
        }
        if (strcmp(col_name[i], "X1") == 0) {
            userCurrent->data.x1 = atoi(col_values[i]);
        }
        if (strcmp(col_name[i], "Y1") == 0) {
            userCurrent->data.y1 = atoi(col_values[i]);
        }
        if (strcmp(col_name[i], "X2") == 0) {
            userCurrent->data.x2 = atoi(col_values[i]);
        }
        if (strcmp(col_name[i], "Y2") == 0) {
            userCurrent->data.y2 = atoi(col_values[i]);
        }
        if (strcmp(col_name[i], "white_counter") == 0) {
            userCurrent->data.white_counter = atoi(col_values[i]);
        }
        if (strcmp(col_name[i], "black_counter") == 0) {
            userCurrent->data.black_counter = atoi(col_values[i]);
        }
        if (strcmp(col_name[i], "threshold") == 0) {
            userCurrent->data.threshold = atoi(col_values[i]);
        }
    }
    // 创建链表头
    if (userLinkedHead == NULL) {
        userLinkedHead = userCurrent;
        return 0;
    }
    // 采用头插的方式插入链表
    userCurrent->next = userLinkedHead->next;
    userLinkedHead->next = userCurrent;

    return 0;
}

// 将链表中的数据打印出来
void printUserLinked(User* userLinked) {
    User* userCurrent = userLinked;
    while (userCurrent) {
        printf("x1 = %d\n", userCurrent->data.x1);
        printf("y1 = %d\n", userCurrent->data.y1);
        printf("x2 = %d\n", userCurrent->data.x2);
        printf("y2 = %d\n", userCurrent->data.y2);
        printf("white = %d\n", userCurrent->data.white_counter);
        printf("black = %d\n", userCurrent->data.black_counter);
        printf("threshold = %d\n", userCurrent->data.threshold);
        userCurrent = userCurrent->next;
    }
}

// 当程序退出的时候，要释放堆中的内存空间
void freeUserLinked(User* userLinked) {
    User* freeCurrent = userLinked;
    User* freePre = userLinked;
    while (freeCurrent) {
        freeCurrent = freePre->next;
        free(freePre);
        freePre = freeCurrent;
    }
    userLinkedHead = NULL;
}

// 通过传入查询sql字符串来获取查询的链表
User* getUserLinked(char* sql) {
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    
    if (!sql)
    {
        return NULL;
    }
    rc = sqlite3_open(DB_FILE, &db);
    if (rc)
    {
        fprintf(stderr, "Can't open database : %s \n", sqlite3_errmsg(db));
        return NULL;
    }
    else {
        printf("Opened database successfully\n");
    }

    rc = sqlite3_exec(db, sql, select_callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error : %s\n", zErrMsg);
        return NULL;
    }
    else {
        printf("user DB exec success\n");
    }

    sqlite3_close(db);
    db = 0;

    return userLinkedHead;
}

// 通过sql来更新数据库
int execUserDB(char* sql) {
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    if (!sql)
    {
        return -1;
    }
    rc = sqlite3_open(DB_FILE, &db);
    if (rc)
    {
        fprintf(stderr, "Can't open database : %s \n", sqlite3_errmsg(db));
        return -1;
    }
    else {
        printf("%s successfully\n", sql);
    }

    rc = sqlite3_exec(db, sql, normal_callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error : %s\n", zErrMsg);
        return -1;
    }
    else {
        printf("user DB exec %s success\n", sql);
    }

    sqlite3_close(db);

    db = 0;
    return 0;
}

//create sql table
int my_table_create(void)
{
    char sql_str[] =  "CREATE TABLE IF NOT EXISTS class(\
            ID  INT PRIMARY KEY NOT NULL, \
            X1  INT ,\
            Y1  INT ,\
            X2  INT ,\
            Y2  INT ,\
            white_counter  INT ,\
            black_counter  INT ,\
            threshold      INT);";
    return execUserDB(sql_str);
}

//delete sql table
int my_table_drop(void)
{
    char sql_str[] = "DROP TABLE class;";
    return execUserDB(sql_str);
}

//clean sql table
int my_table_clear(void)
{
    int rc = 0;
    rc = my_table_drop();
    if (rc < 0)
    {
        return rc;
    }
    return my_table_create();
}

//replace database(update and insert)
//if value = 0 , this key = NULL
int my_table_replace(int id_value, int x1_value, int y1_value, int x2_value, int y2_value, int white_counter, int black_counter, int threshold)
{
    char sql_str[1024] = { 0 };
    snprintf(sql_str, sizeof(sql_str), "replace into class \
            (ID, X1, Y1, X2, Y2, white_counter, black_counter, threshold) \
            values (%d, %d, %d, %d, %d, %d, %d, %d);", \
        id_value, x1_value, y1_value, x2_value, y2_value, white_counter, black_counter, threshold);
    return execUserDB(sql_str);
}

int my_table_replace_withmdata(mdata_t* d)
{
    return my_table_replace(d->id, d->x1, d->y1, d->x2, d->y2, d->white_counter, d->black_counter, d->threshold);
}

int my_table_query_print(void)
{
    char sql_str[] = "select * from class;";
    return execUserDB(sql_str);
}

//query database
//
User *my_table_query(void)
{
    char sql_str[] = "select * from class;";
    return getUserLinked(sql_str);
}

int my_table_update_withlist(User* headlist)
{
    User* userCurrent = headlist;
    int ret = 0;
    if (!headlist)
    {
        return -1;
    }
    ret = my_table_clear();
    if (ret < 0)
    {
        return ret;
    }
    while (userCurrent) {
        my_table_replace(userCurrent->data.id, userCurrent->data.x1, userCurrent->data.y1, userCurrent->data.x2, userCurrent->data.y2, \
            userCurrent->data.white_counter, userCurrent->data.black_counter, userCurrent->data.threshold);
        userCurrent = userCurrent->next;
    }
    return 0;
}