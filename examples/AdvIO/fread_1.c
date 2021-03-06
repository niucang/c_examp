/** Demonstrates the use of fread() -- please read fwrite_1.c before you read
 *  this code.
 **/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 256
#define MAX_NAME 30

int main() {
   FILE *fpRead;
   char *fname = "test1.bin"; 
   int data;
   size_t numbytes= 0;

   /** open a file  in 'read' mode-- read fopen_1.c for more details 
    * */
   if( (fpRead =fopen(fname, "r")) == NULL) 
   {
      perror("failed to open test1.bin for reading");
      return EXIT_FAILURE;
   }

   /** fread() reads at most 2nd parameter multiplied by 3rd parameter 
    *  number of bytes from the file pointed to by the last parameter 
    *  and stores it in the memory location pointed by the first parameter.
    **/

   numbytes= fread(&data, sizeof(int), 1, fpRead);
   /* test that the required bytes have been read */
   if(numbytes != sizeof(int))
   {
       fprintf(stderr, "Error: we could not read an integer.\n");
       fclose(fpRead);
       return EXIT_FAILURE;
   }
   /* output the data */
   printf("\n The number read from the file = %d\n", data);

   fclose(fpRead);

   return(EXIT_SUCCESS);
}

