#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>   /* for uint32_t */

#define BITS_PER_WORD (sizeof(uint32_t) * 8)
#define WORD_OFFSET(b) ((b) / BITS_PER_WORD)
#define BIT_OFFSET(b)  ((b) % BITS_PER_WORD)
#define BITMAP_SIZE 1
uint32_t bitmap[BITMAP_SIZE] = {0};

static void set_bit(uint32_t *bitmap,unsigned int nr_bit)  /* nr_bit must be start from 0 */
{ 
   bitmap[WORD_OFFSET(nr_bit)] |= (1U << BIT_OFFSET(nr_bit));
}
static void clear_bit(uint32_t *bitmap,unsigned int nr_bit)
{
   bitmap[WORD_OFFSET(nr_bit)] &= ~(1U << BIT_OFFSET(nr_bit));  
}
static void toggle_bit(uint32_t *bitmap,unsigned int nr_bit) /* 0 if both bits are the same or set to 1 */
{
   bitmap[WORD_OFFSET(nr_bit)] ^= (1U << BIT_OFFSET(nr_bit));
}
static int get_bit(uint32_t *bitmap,unsigned int nr_bit)
{
    uint32_t bit = (bitmap[WORD_OFFSET(nr_bit)] &= (1U << BIT_OFFSET(nr_bit)));
    return bit!=0;
} 

int main(int argc,char **argv)
{
  set_bit(bitmap,7);
  fprintf(stdout,"bitmap set 7th bit: 0x%x\n",bitmap[0]);
  clear_bit(bitmap,7);
  fprintf(stdout,"bitmap clear 7th bit: 0x%x\n",bitmap[0]);
  set_bit(bitmap,12);
  fprintf(stdout,"bitmap set 12th bit: 0x%x\n",bitmap[0]);
  clear_bit(bitmap,12);
  fprintf(stdout,"bitmap clear 12th bit: 0x%x\n",bitmap[0]);
  toggle_bit(bitmap,7);
  fprintf(stdout,"bitmap toggle 7th bit: 0x%x\n",bitmap[0]);
  fprintf(stdout,"bitmap get 7th bit: %d\n",get_bit(bitmap,7));

  return 0;

}
