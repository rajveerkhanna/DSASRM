#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_HASH_SIZE 1000

int hash_table[MAX_HASH_SIZE];
bool slot_occupied[MAX_HASH_SIZE];
int current_size = 0;

// Hashing function
int hash(int key) {
    return abs(key) % MAX_HASH_SIZE;
}

bool insert_key(int key) {
    if (current_size >= MAX_HASH_SIZE)
        return false; // Exceeding the maximum hash table size

    int index = hash(key);

    while (slot_occupied[index]) {
        if (hash_table[index] == key)
            return false; // Key already exists in the hash table
        index = (index + 1) % MAX_HASH_SIZE;
    }

    hash_table[index] = key;
    slot_occupied[index] = true;
    current_size++;
    return true;
}

bool remove_key(int key) {
    int index = hash(key);

    for (int i = 0; i < MAX_HASH_SIZE; i++) { // Handling collisions with linear probing
        if (!slot_occupied[index])
            return false; // Key not found

        if (hash_table[index] == key) {
            slot_occupied[index] = false;
            current_size--;
            return true;
        }

        index = (index + 1) % MAX_HASH_SIZE;
    }

    return false; // Key not found
}

bool search_key(int key) {
    int index = hash(key);

    for (int i = 0; i < MAX_HASH_SIZE; i++) {
        if (!slot_occupied[index])
            return false; // Key not found

        if (hash_table[index] == key)
            return true;

        index = (index + 1) % MAX_HASH_SIZE;
    }
   return false; // Key not found
}

int get_random_key() {
    if (current_size == 0)
        return -1; // Empty hash table

    int random_index = rand() % current_size;
    return hash_table[random_index];
}

int main() {
    srand((unsigned int)time(NULL)); // Seeding the random number generator
    int choice, key;

    while (1) {
        printf("1. Insert Key\n");
        printf("2. Remove Key\n");
        printf("3. Search Key\n");
        printf("4. Get Random Key\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a key to insert: ");
                scanf("%d", &key);
                if (insert_key(key))
                    printf("Key %d inserted successfully.\n", key);
                else
                 printf("Key %d already exists or maximum hash table size reached.\n", key);
                break;
            case 2:
                printf("Enter a key to remove: ");
                scanf("%d", &key);
                if (remove_key(key))
                    printf("Key %d removed successfully.\n", key);
                else
                    printf("Key %d not found.\n", key);
                break;
            case 3:
                printf("Enter a key to search: ");
                scanf("%d", &key);
                if (search_key(key))
                    printf("Key %d is present.\n", key);
                else
                    printf("Key %d is not present.\n", key);
                break;
            case 4:
                key = get_random_key();
                if (key != -1)
                    printf("Random key: %d\n", key);
                else
                    printf("The hash table is empty.\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
return 0;
}
