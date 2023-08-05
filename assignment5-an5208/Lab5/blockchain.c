#include "hash.h"
#include <stdlib.h>
#include <stdio.h>

struct Blockchain * initialize(){
    struct Blockchain* chain = (struct Blockchain*) malloc (sizeof(struct Blockchain));
    chain->head = NULL;
    chain->size = 0;
    return chain;
}

//make a new block for the data and insert it into the blockchain
void add(struct Blockchain* chain, int init_data){
    struct Block *blk = (struct Block*) malloc(BLOCK_SIZE);
    blk->data = init_data;
    blk->height = chain->size + 1;
    blk->prevBlock = chain->head;
    if(chain->head != NULL){
        blk->prevHash = SSHA(toString(chain->head), BLOCK_SIZE);
    }
    else{
        blk->prevHash = NULL;
    }

    //Insert this block into the chain
    chain->head = blk;
    chain->size += 1;
}
//print data of blocks in the chain in descending order of height
void print(struct Blockchain* chain){
    printf("print: \n");
    struct Block *cur = chain->head;
    //Stop when the last block is accessed
    while(cur != NULL){
        printf("[ %d : %d ]  ", cur->height, cur->data);
        //Get to the block of lower height
        cur = cur->prevBlock;
    }
    printf("\n");
}

//traverse the chain to find out if any block is tempered with
//check 2 blocks to see if the digests match up
int verify(struct Blockchain* chain){
    struct Block *curr = chain->head;
    //Stop when the last block is accessed
    while(curr != NULL){
        //Skip the last block
        if (curr->prevBlock != NULL){
            //Stop when the first instance of modification is spotted
            if(match(curr->prevHash, SSHA(toString(curr->prevBlock), BLOCK_SIZE), DIGEST_SIZE) != 0){
                printf("verify: Verification failed: block %d is not valid\n", curr->height - 1);
                return 1;
            }
        }
        curr = curr->prevBlock;
    }
    //No changes spotted
    printf("verify: All blocks have been verified.\n");
    return 0;
}
//delete a block after traversing index in the blockchain
//should trigger verify
int delete(struct Blockchain* chain, int index){
    struct Block *curr = chain->head;
    struct Block *left = NULL;
    
    while(curr != NULL){
        if(curr->height == index){
            //The deleted block is not the head
            if(left != NULL){
                left->prevHash = curr->prevHash;
                left->prevBlock = curr->prevBlock;
            }
            else{
                chain->head = curr->prevBlock;
            }
            printf("Block %d is deleted.\n", index);
            chain->size --;
            return 1;
        }
        
        left = curr;
        curr = curr->prevBlock;
    }
    //If there is an error, probably index out of bound
    return 0;
}

//alter data in a single block
//this should trigger verify
int alter_block(struct Blockchain *chain, int index, int new_data){
    struct Block *curr = chain->head;
    int i =0;
    while(curr != NULL){
        if(curr->height == index){
            curr->data = new_data;
            printf("alter_block: block %d is altered.\n", index);
            return 1;
        }
        curr = curr->prevBlock;
        i++;
    }
    //If there is an error, probably index out of bound
    return 0;
}

//alter data in a block and set the next block's prevHash to the altered's 
//this should still trigger verify, unless the altered block is the first or second
//...since the block before the preceding block would not match its prevHash
int alter_2_blocks(struct Blockchain *chain, int index, int new_data){
    struct Block *curr = chain->head;
    //the block preceding this block i.e. height+1
    struct Block *left = NULL;
    int i = 0;
    while(curr != NULL){
        if (curr->height == index){
            //skip the first block
            //modify the previous block    
            if(left != NULL){
                curr->data = new_data;
                left->prevBlock = curr;
                left->prevHash = SSHA(toString(curr), BLOCK_SIZE);
                printf("alter_2_blocks: block %d is altered.\n", index);
                return 1;
            }
            else{
                curr->data = new_data;
            }
        }
        i++;
        left = curr;
        curr = curr->prevBlock;
    }
    return 0; //an error, probably index out of bound. Nothing is changed.
}

int main(){
    struct Blockchain *blockchain = initialize();
    for (int i = 1; i<=20; i++){
        add(blockchain, 10*i);
    }
    print(blockchain);
    verify(blockchain);

    //delete(blockchain, 5);
    
    //alter_block(blockchain, 10, 5000);
    
    alter_2_blocks(blockchain, 5, 5000);

    verify(blockchain);
    print(blockchain); 
    return 0;
}
