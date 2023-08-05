#include "hash.h"


typedef unsigned char BYTE;

//str: a string to be hashed. It will not be modified
//size: size of the string
unsigned char* SSHA(const unsigned char* str, size_t size){
    BYTE A,B,C,D,E;
    //Seed values H0 were provided
    A = 11;
    B = 22;
    C = 33;
    D = 44;
    E = 55;

    for (int i =0; i<size; i++){
        for(int r = 0; r<12;r++){
            BYTE OLD_A = A;
            BYTE F = (B & C) ^ D ;
            //no overflowing, we only need the last 8 bits
            A = E + F + (A >> 3) + str[i] + r;
            E = D;
            D = C;
            C = (B << 1);
            B = OLD_A;
        }
    }

    BYTE *digest = (BYTE*) malloc(DIGEST_SIZE);
    digest[0] = A;
    digest[1] = B;
    digest[2] = C;
    digest[3] = D;
    digest[4] = E;
    
    return digest;
}

//string representation of a Block
//Copy every data in blk into the BYTE
unsigned char* toString(struct Block *blk){
    BYTE *str = (BYTE*) malloc(BLOCK_SIZE);
    memcpy(str, blk, BLOCK_SIZE);
    return str;
}

void test_block(){
    
}

//Comparing two messages with the same size
//return 0 if the two messages match, 1 otherwise
int match(unsigned char* msg1, unsigned char * msg2, int size){
    for (int i = 0; i<size; i++){
        if(msg1[i] != msg2[i]){
            return 1;
        }
    }
    return 0;
}
/*
int main(){
    //Check hash activity with strings
    char *str1 = "hello World!";
    BYTE* digest1 = SSHA ((BYTE*)str1, strlen(str1));
    printf("digest1 = %d, %d, %d, %d, %d\n", digest1[0],digest1[1],digest1[2],digest1[3],digest1[4]);

    char *str2 = "Hello World!";
    BYTE* digest2 = SSHA ((BYTE*)str2, strlen(str2));
    printf("digest2 = %d, %d, %d, %d, %d\n", digest2[0],digest2[1],digest2[2],digest2[3],digest2[4]);
    //the output should be completely different
    //...but let's compare them to be sure
    printf("Are the two digests the same? %d\n", match(digest1, digest2, DIGEST_SIZE));

    //Check hash activity with Blocks
    struct Block *block1 = (struct Block*) malloc(BLOCK_SIZE);
    block1->height = 1;
    block1->data = 25;
    block1->prevHash = NULL;
    block1->prevBlock = NULL;

    //SSHA expects a BYTE pointer
    digest1 = SSHA(toString(block1), BLOCK_SIZE);
    printf("digest1 = %d, %d, %d, %d, %d\n", digest1[0],digest1[1],digest1[2],digest1[3],digest1[4]);

    struct Block *block2 = (struct Block*) malloc(BLOCK_SIZE);
    block2->height = 2;
    block2->data = 57;
    //this might be different between machines since digest1 is a memory reference
    block2->prevHash = digest1;
    block2->prevBlock = block1;
    digest2 = SSHA(toString(block2), BLOCK_SIZE);
    printf("digest2 = %d, %d, %d, %d, %d\n", digest2[0],digest2[1],digest2[2],digest2[3],digest2[4]);

    //Compare those blocks' digest messages
    printf("Are the two block the same? %d\n", match(digest1, digest2, DIGEST_SIZE));
}
*/