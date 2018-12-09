#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define size 20

struct Data_item{
    int data;
    int key;
    };

struct Data_item* hashArray[size];
struct Data_item* temp_item;
struct Data_item* item;

int Hash_func(int key){
    return key%size;    //Hash function : k mod m 
    }
    
struct Data_item *search(int key){
    int hash_index = Hash_func(key);
    
    while(hashArray[hash_index] != NULL){
        
        if(hashArray[hash_index] ->key == key)
            return hashArray[hash_index];
            
            ++hash_index;
            
            hash_index %= size;
            }
            
            return NULL;
    }

void insert (int key , int data){

    struct Data_item *item = (struct Data_item*) malloc(sizeof(struct Data_item));
    item->data = data;
    item->key = key ;
    
    int hash_index = Hash_func(key);
    
    while(hashArray[hash_index] != NULL && hashArray[hash_index]->key !=-1){
        ++hash_index;
        
        hash_index %= size;
        }
        
    hashArray[hash_index] = item;
}


struct Data_item* delete1(struct Data_item* item){

    int key = item->key;
    
    int hash_index = Hash_func(key);
    
    while(hashArray[hash_index] != NULL){
    
        if(hashArray[hash_index]->key == key){
            struct Data_item* temp = hashArray[hash_index];
            
            hashArray[hash_index] = temp_item;
            return temp;
            }
            
            ++hash_index;
            
            hash_index %= size;
            }
        return NULL;
   }
   
void display_output(){
    int i = 0;
    
    for(i=0; i<size; i++){
    
        if(hashArray[i] != NULL)
            printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
        else
            printf(" ** ");
        }
    
    printf("\n");
}

int main(){
    temp_item = (struct Data_item*) malloc(sizeof(struct Data_item));
    temp_item->data = -1;
    temp_item->key - -1;
    
    insert(1,19);
    insert(2,83);
    insert(37,81);
    insert(5,43);
    insert(23,28);
    insert(14,39);
    
    display_output();
    
    item = search(23);
    
    if(item != NULL)
        printf("Element found: %d\n",item->data);
    else
        printf("Element not found\n");
        
    delete1(item);
    item = search(23);
    
    if(item != NULL)
        printf("Element found: %d\n",item->data);
    else
        printf("Element not found\n");
   }













      
    
    
    
    
