#ifndef MEM_H
#define MEM_H

int mem_malloc(size_t size);
int mem_realloc(void *ptr, size_t size);
int mem_free(void *ptr);
int mem_strdup(char *a1);

int assoc_register_mem(void *malloc_func, void *realloc_func, void *free_func);
int db_register_mem(void *malloc_func, void *strdup_func, void *free_func);
int memoryRegisterAlloc(void *malloc_func, void *realloc_func, void *free_func);

#endif