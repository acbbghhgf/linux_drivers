#pragma once
#ifndef __USER_H__
#define __USER_H__

#include <stdio.h>
#include <stdlib.h>
#include "sqlite/sqlite3.h"
#include <string.h>

#define DB_FILE     "mdata.db"

typedef struct mdata{
    int id;
    int x1;//田字格top_left_x
    int y1;//田字格top_left_y
    int x2;//田字格tail_right_x
    int y2;//田字格tail_right_y
    int white_counter;//白色最小值
    int black_counter;//黑色最大值
    int threshold;//最终阈值
}mdata_t;

// 使用结构体来保存数据库中的数据
typedef struct USER {
    mdata_t data;
    struct USER* next;// 数据从数据库中提取出来是用链表保存
} User;

// 查询user表Demo
void userDemo(void);
// 查询数据时的回调函数
static int select_callback(void* data, int col_count, char** col_values, char** col_name);
// 打印UserLinked链表
void printUserLinked(User* userLinked);
// 获取UserLinked链表
User* getUserLinked(char* sql);
// 释放链表中的数据
void freeUserLinked(User* userLinked);
// 更新数据库



//创建数据库
int my_table_create(void);
//删除数据库
int my_table_drop(void);
//清除数据库
int my_table_clear(void);

int execUserDB(char* sql);

int my_table_replace(int id_value, int x1_value, int y1_value, int x2_value, int y2_value, int white_counter, int black_counter, int threshold);
int my_table_replace_withmdata(mdata_t* d);

int my_table_query_print(void);

//查询数据库返回数据链表，不使用的时候需要freeUserLinked释放
User* my_table_query(void);

#endif
