#include "game/gmemory.h"
#include "game/mem.h"

int gmemory_init() {
  assoc_register_mem(mem_malloc, mem_realloc, mem_free);
  db_register_mem(mem_malloc, mem_strdup, mem_free);
  memoryRegisterAlloc(gmalloc, grealloc, gfree);
  return 0;
}