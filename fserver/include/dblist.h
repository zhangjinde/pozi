#ifndef _DBLIST_H_
#define _DBLIST_H_
#include <malloc.h>
#include "dbnode.h"
#include "dbaccess.h"
/*
 struct list_mysql_node{
 struct list_mysql_node* prev;
 struct list_mysql_node* next;
 MYSQL mysql;
 long mills;
 };
 */
typedef struct list_mysql_node pool_linklist;
struct list_mysql_node* current;
unsigned int numbers;
pthread_mutex_t pmt;
void createDBList(struct list_mysql_node**);
//void insertDB(struct list_mysql_node*,struct mysql_node*);
void insertDB(struct list_mysql_node*, MYSQL*);
//struct list_mysql_node* next_DB_node(struct list_mysql_node*);
struct list_mysql_node* get_free_node(struct list_mysql_node*);
void insertDBNode(struct list_mysql_node*, struct list_mysql_node*);
void travelDB(struct list_mysql_node*);
void destroyDBList(struct list_mysql_node*);
unsigned int db_size();
#endif
