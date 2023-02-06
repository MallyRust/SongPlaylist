#include<iostream>
#include <cstring>
#include<string>

using namespace std;

class node {
public:
    char data[30];
    node* next;
    node* prev;
};


char name[30];
node* head = NULL;
node* cur = NULL;

void addNewSong() {
    cout << "\nEnter Song Name to add: \n";
    while ((getchar()) != '\n');
    cin.getline(name, 30);

    struct node* newNode = (struct node*)malloc(sizeof(struct node)); //allocate memory for new node
    strcpy(newNode->data, name);

    if (head == NULL) { 
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    else {
        cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }

        newNode->prev = cur; 
        cur->next = newNode;
        newNode->next = NULL;
    }
}


void deleteSong() {

    if (head == NULL) {
        cout << "\nThere is no songs in the playlist to delete.\n";
        return;
    }
    cout << "\nEnter Song Name to delete: \n";
    while ((getchar()) != '\n');
    cin.getline(name, 30); 
    cout << '\n';

    node* ptr = head;

    do {
        if (ptr->next == ptr && strcmp(ptr->data, name) == 0) { //if there's 1 node and it's same as user want to delete
            cout << "One file deleted! Playlist is Empty Now!\n";
            head = NULL;
            delete ptr;
            return;
        }
        else if (strcmp(ptr->data, name) == 0) { //if same input as user want to delete
            struct node* prev = ptr->prev;
            struct node* next = ptr->next;
            prev->next = next;
            next->prev = prev;
            head = next;
            delete ptr;
            cout << "Song is deleted!\n";
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);
    cout << "\nNo song is there!\n";
}

void showAllSongs() {
    if (head == NULL) {
        cout << "There is no songs in the playlist\n";
        return;
    }

    else {
        node* temp = head;

        while (temp != NULL) { //traverse link till the last node
            cout << "\nMusic Playlist: \n";
            cout << temp->data;
            cout << '\n';
            temp = temp->next; 
        }
    }
}

int main() {
    int option;

menu:

    cout << "\n1.Add new Song\n2.Delete Song\n3.Show all songs\n";
    cin >> option;

    if (option == 1) {
        addNewSong();
        cout << "\nDo you want to add more songs? (1-yes || 2-no)\n";


        cin >> option;
        if (option == 1) {
            addNewSong();
        }

        else {
            goto menu;
        }

    }

    else if (option == 2) {
        deleteSong();
    }

    else if (option == 3) {
        showAllSongs();
    }

    goto menu;

    return 0;
}
