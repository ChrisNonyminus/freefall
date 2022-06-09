#ifndef GAME_DB_H
#define GAME_DB_H

extern int master_db_handle;
extern int critter_db_handle;

int db_close(int);
int db_select(int);
void db_enable_hash_table();

int db_init(char *a1, int a2, char *a3);
int game_init_databases(void);

#endif