/*Problem 1: Music Playlist Management System (Singly Linked List)
Problem Statement
A music streaming application maintains a playlist where songs are played one after another in the order they were added.

Each song contains the following information:
Song ID
Song Name
Artist Name
Duration (in minutes)

Develop a menu-driven C program using a Singly Linked List to perform the following operations:
Add a new song to the end of the playlist.
Display all songs in the playlist.
Search for a song using its Song ID.
Delete a song from the playlist using its Song ID.
Count the total number of songs.
Exit the application.*/
#include<stdio.h>
#include<stdlib.h>
// Structure to represent a Song node
struct Song{
    int Song_ID;
    char Song_Name[100];
    char Artist_Name[100];
    int Duration;
    struct Song *next;   // Pointer to next song
};
int main()
{
    int n, choice, id, count = 0, i;
    // Pointers used in linked list operations
    struct Song *head = NULL, *temp = NULL, *newsong = NULL;
    printf("Enter number of Songs: ");
    scanf("%d", &n);
    // Creating the initial playlist
    for(i = 0; i < n; i++)
    {
        // Allocate memory for a new song
        newsong = (struct Song *)malloc(sizeof(struct Song));
        if(newsong == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }
        // Input song details
        printf("Enter Song_ID for node %d: ", i + 1);
        scanf("%d", &newsong->Song_ID);
        printf("Enter Song name for node %d: ", i + 1);
        scanf("%s", newsong->Song_Name);
        printf("Enter Artist_Name for node %d: ", i + 1);
        scanf("%s", newsong->Artist_Name);
        printf("Enter Duration for node %d: ", i + 1);
        scanf("%d", &newsong->Duration);
        // New node points to NULL
        newsong->next = NULL;
        // Insert first node
        if(head == NULL)
        {
            head = newsong;
            temp = newsong;
        }
        // Insert remaining nodes at end
        else
        {
            temp->next = newsong;
            temp = newsong;
        }
    }
    // Menu driven program
    while(1)
    {
        printf("\n----SELECT FROM THE OPTIONS (1-6)-----\n");
        printf("1. Add a new song to the end of the playlist.\n");
        printf("2. Display all songs in the playlist.\n");
        printf("3. Search for a song using its Song ID.\n");
        printf("4. Delete a song from the playlist using its Song ID.\n");
        printf("5. Count the total number of songs.\n");
        printf("6. Exit the application.\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            // Case 1 : Add new song at the end
            case 1:
                // Allocate memory for new song
                newsong = (struct Song *)malloc(sizeof(struct Song));
                if(newsong == NULL)
                {
                    printf("Memory allocation failed\n");
                    return 1;
                }
                // Input song details
                printf("Enter Song_ID : ");
                scanf("%d", &newsong->Song_ID);
                printf("Enter Song name : ");
                scanf("%s", newsong->Song_Name);
                printf("Enter Artist_Name : ");
                scanf("%s", newsong->Artist_Name);
                printf("Enter Duration : ");
                scanf("%d", &newsong->Duration);
                newsong->next = NULL;
                // If list is empty, make new node head
                if(head == NULL)
                {
                    head = newsong;
                }
                else
                {
                    // Traverse till last node
                    temp = head;
                    while(temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    // Attach new song at end
                    temp->next = newsong;
                }
                break;
            // Case 2 : Display playlist
            case 2:
                if(head == NULL)
                {
                    printf("Song Playlist is Empty.\n");
                    break;
                }
                temp = head;
                printf("Playlist...\n");
                // Traverse and display all songs
                while(temp != NULL)
                {
                    printf("Song ID : %d | Song Name : %s | Artist Name : %s | Duration : %d\n",
                           temp->Song_ID,temp->Song_Name,temp->Artist_Name,
                           temp->Duration);
                    temp = temp->next;
                }
                break;
            // Case 3 : Search song by ID
            case 3:
                printf("Enter Song ID to search: ");
                scanf("%d",&id);
                if(head == NULL)
                {
                    printf("List is empty.. No song in playlist...\n");
                }
                temp = head;
                // Traverse list to search song
                while(temp != NULL)
                {
                    if(temp->Song_ID == id)
                    {
                        printf("Song found...\n");
                        printf("Song ID : %d | Song Name : %s | Artist Name : %s | Duration : %d\n",
                               temp->Song_ID,
                               temp->Song_Name,
                               temp->Artist_Name,
                               temp->Duration);
                        break;
                    }
                    temp = temp->next;
                }
                break;
            // Case 4 : Delete song using Song ID
            case 4:
                printf("Enter song id to delete song: ");
                scanf("%d",&id);
                if(head == NULL)
                {
                    printf("List is Empty.\n");
                }
                // Delete first node
                else if(head->Song_ID == id)
                {
                    newsong = head;
                    head = head->next;
                    free(newsong);
                    printf("Song deleted.\n");
                }
                else
                {
                    temp = head;
                    // Find node just before the node to delete
                    while(temp->next != NULL && temp->next->Song_ID != id)
                    {
                        temp = temp->next;
                    }
                    if(temp->next == NULL)
                    {
                        printf("Song not found.\n");
                    }
                    else
                    {
                        // Delete node
                        newsong = temp->next;
                        temp->next = newsong->next;
                        free(newsong);
                        printf("Song deleted.\n");
                    }
                }
                break;
            // Case 5 : Count total songs
            case 5:
                count = 0;     // Reset count
                temp = head;
                // Traverse list and count nodes
                while(temp != NULL)
                {
                    count++;
                    temp = temp->next;
                }
                printf("Number of songs present in the playlist is %d.\n", count);
                break;
            // Case 6 : Exit
            case 6:
                 temp = head;
                while(temp != NULL)
                {
                    newsong = temp;
                    temp = temp->next;
                    free(newsong);
                }
                printf("Exiting the application.....\n");
                exit(0);
            // Invalid choice
            default:
                printf("Invalid choice\n...Choose from options 1 to 6.\n");
        }
    }
}