#include "ADT/arraydin/arraydin.h"
#include "ADT/mesinkarkata/mesinkata.h"
#include "ADT/mesinkarkata/mesinkar.h"
#include "ADT/queue/queue.h"
#include "ADT/boolean/boolean.h"
#include "list_game.h"

boolean IsInQueue(Queue queuegame, char* elQ);
/*I.S. Queue game mungkin kosong*/
/*F.S. Elemen queue ditemukan atau tidak*/

void deletegame(ArrayDin *array, Queue queuegame);
/*I.S. Array game mungkin kosong*/
/*F.S. Nomor games yang ingin dihapus telah hilang dari array*/