#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	float duration;
	char name[20],singer[20],lyricist[20],album[20],composer[20],genre[20];
	struct node *next;
	struct node *prev;
	struct node *song;
}node;
node *lptr,*nptr;
void appendinfile(node *lptr)
{
	nptr=lptr;
	FILE *p;
	p=fopen("playlist","w");
	while(nptr!=NULL)
	{
		fprintf(p,"%s\t%s\t%s\t%s\t%s\t%s\t%0.2f\n",nptr->name,nptr->singer,nptr->lyricist,nptr->composer,nptr->album,nptr->genre,nptr->duration);
		nptr=nptr->next;
	}
	fclose(p);
	printf("appended\n");
}
node* insert(node *lptr)
{
	node* Temp=(node*)malloc(sizeof(node));
	if(lptr==NULL)
	{
		printf("enter song name:");
		gets(Temp->name);
		gets(Temp->name);
		printf("enter singer name:");
		gets(Temp->singer);
		printf("enter lyricist name:");
		gets(Temp->lyricist);
		printf("enter composer name:");
		gets(Temp->composer);
		printf("enter film/album name:");
		gets(Temp->album);
		printf("enter genre name:");
		gets(Temp->genre);
	//	gets(Temp->genre);
		printf("enter song duration:");
		scanf("%f", &Temp->duration);
		Temp->prev=NULL;
		Temp->next=NULL;
		lptr=Temp;
		nptr=Temp;
	}
	else
	{
		printf("enter song name:");
		gets(Temp->name);
		gets(Temp->name);
		printf("enter singer name:");
		gets(Temp->singer);
		printf("enter lyricist name:");
		gets(Temp->lyricist);
		printf("enter composer name:");
		gets(Temp->composer);
		printf("enter film/album name:");
		gets(Temp->album);
		printf("enter genre name:");
		gets(Temp->genre);
	//	gets(Temp->genre);
		printf("enter song duration:");
		scanf("%f", &Temp->duration);
		nptr=lptr;
		while(nptr->next!=NULL)
		{
			nptr=nptr->next;
		}
		nptr->next=Temp;
		Temp->prev=nptr;
		Temp->next=NULL;
		nptr=Temp;
		//Temp->next=NULL;
	}
	appendinfile(lptr);
	return lptr;
}
void display(node *lptr)
{
	nptr=lptr;
	//printf("%s",nptr->name);
	while(nptr!=NULL)
	{
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%0.2f\n",nptr->name,nptr->singer,nptr->lyricist,nptr->composer,nptr->album,nptr->genre,nptr->duration);
		nptr=nptr->next;
	}
}
/* Question 1 Function to Insert Song */
void InsertSong() 
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    printf("Enter singer: ");
    scanf("%s", newnode->singer);
    printf("Enter lyricist: ");
    scanf("%s", newnode->lyricist);
    printf("Enter album/film: ");
    scanf("%s", newnode->album);
    printf("Enter composer: ");
    scanf("%s", newnode->composer);
    printf("Enter genre: ");
    scanf("%s", newnode->genre);
    printf("Enter duration: ");
    scanf("%f", newnode->duration);
    // add any other attribute inputs you want here
    newnode->next = NULL;
    if (lptr == NULL) 
	{
        lptr = newnode;
    } 
	else 
	{
        struct node* currnode = lptr;
        while (currnode->next != NULL) 
		{
            currnode = currnode->next;
        }
        currnode->next = newnode;
    }
    printf("Song inserted successfully!\n");
}
/*Question 2 Remove duplicates */
void removeDuplicates(struct node* lptr) 
{
    node* current = lptr;
    node* temp;

    // Traverse the list
    while (current != NULL) 
	{
        // Compare each node with all subsequent nodes
        temp = current;
        while (temp->next != NULL) 
		{
            // If a duplicate is found, remove it
            if (strcmp(current->singer, temp->next->singer) == 0 && strcmp(current->album, temp->next->album) == 0 &&strcmp(current->genre, temp->next->genre) == 0 &current->duration == temp->next->duration) 
			{
                node* duplicate = temp->next;
                temp->next = temp->next->next;
                free(duplicate);
            } 
			else 
			{
                temp = temp->next;
            }
        }
        current = current->next;
    }
}
/* Question 4 Function to Delete Song */ 
node* delete_song(node *lptr,char song)
{
	nptr=lptr;
	node *p;
	while(nptr->next!=NULL)
	{
		p=nptr;
		if(strcmp(song,nptr->name))
		{
			if(nptr==lptr)
			{
				lptr=nptr->next;
				free(p);
			}
			else
			{
				p->next=nptr->next;
				free(p);
			}
		}
		nptr=nptr->next;
	}
}
/*Question 5th Create Playlist */
struct music_listing* create_playlist(char* attribute, char* value) 
{
    struct node* playlist_head = NULL;
    struct node* curr_music = music_list_head;
    
    while (curr_music != NULL) {
        if (strcmp(attribute, "singer") == 0 && strcmp(curr_music->singer, value) == 0) 
		{
            // add current music to playlist
            struct music_listing* new_music = (struct music_listing*) malloc(sizeof(struct music_listing));
            *new_music = *curr_music; // copy current music
            new_music->next = NULL;
            
            // add new_music to playlist in lexicographic order of song name
            if (playlist_head == NULL || strcmp(new_music->album_film, playlist_head->album_film) < 0) 
			{
                new_music->next = playlist_head;
                playlist_head = new_music;
            } 
			else 
			{
                struct music_listing* prev_music = playlist_head;
                struct music_listing* curr_playlist_music = playlist_head->next;
                
                while (curr_playlist_music != NULL && strcmp(new_music->album_film, curr_playlist_music->album_film) >= 0) 
				{
                    prev_music = curr_playlist_music;
                    curr_playlist_music = curr_playlist_music->next;
                }
                
                new_music->next = curr_playlist_music;
                prev_music->next = new_music;
            }
        } 
		else if (strcmp(attribute, "film") == 0 && strcmp(curr_music->album_film, value) == 0) 
		{
            // add current music to playlist
            struct music_listing* new_music = (struct music_listing*) malloc(sizeof(struct music_listing));
            *new_music = *curr_music; // copy current music
            new_music->next = NULL;
            
            // add new_music to playlist in lexicographic order of song name
            if (playlist_head == NULL || strcmp(new_music->album_film, playlist_head->album_film) < 0) 
			{
                new_music->next = playlist_head;
                playlist_head = new_music;
            }
			else 
			{
                struct music_listing* prev_music = playlist_head;
                struct music_listing* curr_playlist_music = playlist_head->next;
                
                while (curr_playlist_music != NULL && strcmp(new_music->album_film, curr_playlist_music->album_film) >= 0) 
				{
                    prev_music = curr_playlist_music;
                    curr_playlist_music = curr_playlist_music->next;
                }
                
                new_music->next = curr_playlist_music;
                prev_music->next = new_music;
            }
        }
        
        curr_music = curr_music->next;
    }
    
    return playlist_head;
}


/* Question 6th Print Songs according to serial numbers */
void displaySong(struct Node *lptr, int index) 
{
    int i = 1;
    struct Node *current = lptr;
    struct Node *prev = NULL;
    struct Node *next = NULL;
    while (current != NULL) 
	{
        if (i == index) 
		{
            printf("Singer: %s\n", current->song->singer);
            printf("Lyricist: %s\n", current->song->lyricist);
            printf("Album/Film: %s\n", current->song->album);
            printf("Composer: %s\n", current->song->composer);
            printf("Genre: %s\n", current->song->genre);
            printf("Duration: %d seconds\n", current->song->duration);
            if (prev != NULL) {
                printf("Previous song: %s - %s (%s)\n", prev->song->singer, prev->song->album, prev->song->genre);
            }
            if (next != NULL) 
			{
                printf("Next song: %s - %s (%s)\n", next->song->singer, next->song->album, next->song->genre);
            }
            return;
        }
        prev = current;
        current = current->next;
        next = current != NULL ? current->next : NULL;
        i++;
    }
    printf("Invalid song index.\n");
}
/* Question 7th Display the details of kth song */
void displayKthSong(node* playlist, int k, char* direction) 
{
    static node* current = NULL;
    static int position = 0;

    // Initialize the current position and current node if necessary
    if (current == NULL) 
	{
        current = playlist;
        position = 1;
    }

    // Update the current position and current node based on the direction
    if (strcmp(direction, "up") == 0) 
	{
        while (current != NULL && position > k) 
		{
            current = current->next;
            position--;
        }
    } else if (strcmp(direction, "down") == 0) 
	{
        while (current != NULL && position < k) 
		{
            current = current->next;
            position++;
        }
    } 
	else 
	{
        // If the direction is invalid, display an error message
        printf("Invalid direction.\n");
        return;
    }

    // Display the details of the current song
    printf("Position: %d\n", position);
    printf("Singer: %s\n", current->singer);
    printf("Lyricist: %s\n", current->lyricist);
    printf("Album: %s\n", current->album);
    printf("Composer: %s\n", current->composer);
    printf("Genre: %s\n", current->genre);
    printf("Duration: %d seconds\n", current->duration);
    // Add any other attributes you choose here
}

/* Question 9 Filter the playlist */
struct node* filter_playlist(struct node* lptr, char* attribute, char* value) 
{
    struct node* filtered_list = NULL; // Initialize the filtered playlist to empty
    struct node* current = lptr; // Start from the head of the playlist
    while (current != NULL) 
	{
        // Compare the attribute value in the current node with the given value
        if (strcmp(attribute, "singer") == 0 && strcmp(current->singer, value) == 0) 
		{
            // Add the current node to the filtered playlist if the attribute value matches
            struct node* new_node = (struct node*) malloc(sizeof(struct node));
            // Copy the contents of the current node to the new node
            strcpy(new_node->singer, current->singer);
            strcpy(new_node->lyricist, current->lyricist);
            strcpy(new_node->album_film, current->album_film);
            strcpy(new_node->composer, current->composer);
            strcpy(new_node->genre, current->genre);
            new_node->duration = current->duration;
            // Add the new node to the filtered playlist
            new_node->next = filtered_list;
            filtered_list = new_node;
        }
        // Repeat the same for other attributes such as lyricist, album/film, composer, genre, etc.
        // ...
        current = current->next; // Move to the next node in the playlist
    }
    return filtered_list; // Return the filtered playlist
}

/* Question 10 Play in Loop Function */
void playInLoop(struct node *lptr) 
{
    char playlistName[50];
    int k;
    
    printf("Enter the name of the play-list: ");
    scanf("%s", playlistName);
    
    printf("Enter the number of times to play in loop: ");
    scanf("%d", &k);
    
    // Find the play-list with the given name
    struct node *curr = lptr;
    while (curr != NULL && strcmp(curr->playlistName, playlistName) != 0) 
	{
        curr = curr->next;
    }
    
    if (curr == NULL) 
	{
        printf("Error: Play-list not found.\n");
        return;
    }
    
    // Play the songs k times in loop
    int i;
    for (i = 0; i < k; i++) 
	{
        printf("Playing play-list %s for the %d time:\n", playlistName, i+1);
        struct song *song = curr->songs;
        while (song != NULL) 
		{
            printf("%s by %s\n", song->title, song->singer);
            song = song->next;
        }
    }
}

/* Question 11 Function to Shuffle the song based on given attributes */
void shuffle(struct node* lptr, char* attribute[], char* value[], int num_attributes) 
{
    struct node* curr = lptr;
    struct node* shuffled_head = NULL;
    int count = 0;

    // Traverse through the linked list
    while (curr != NULL) 
	{
        int FLAG = 1;
        // Check if the current node satisfies the given attributes and their values
        for (int i = 0; i < num_attributes; i++) 
		{
            if (strcmp(attribute[i], "singer") == 0) 
			{
                if (strcmp(curr->singer, value[i]) != 0) 
				{
                    FLAG = 0;
                    break;
                }
            }
            else if (strcmp(attribute[i], "lyricist") == 0) 
			{
                if (strcmp(curr->lyricist, value[i]) != 0) 
				{
                    FLAG = 0;
                    break;
                }
            }
            else if (strcmp(attribute[i], "album") == 0) 
			{
                if (strcmp(curr->album, value[i]) != 0) 
				{
                    FLAG = 0;
                    break;
                }
            }
            // Add more attributes and their values as required
        }
		// If the current node satisfies the given attributes and their values and has not been flagged before, add it to the shuffled linked list
        if (match && !curr->flag)
		{
            struct node* new_node = (struct Node*)malloc(sizeof(struct node));
            new_node->singer = curr->singer;
            new_node->lyricist = curr->lyricist;
            new_node->album = curr->album;
            new_node->composer = curr->composer;
            new_node->genre = curr->genre;
            new_node->duration = curr->duration;
            new_node->flag = 0;
            new_node->next = shuffled_head;
            shuffled_head = new_node;
            count++;
        }

        curr = curr->next;
    }
    // If no song satisfies the given attributes and their values, print an error message
    if (count == 0) 
	{
        printf("No songs found matching the given attributes and their values.\n");
        return;
    }
    // Randomly select a song from the shuffled linked list
    int index = rand() % count;
    curr = shuffled_head;
    while (index > 0) 
	{
        curr = curr->next;
        index--;
    }
    // Mark the selected song with a flag to ensure it is not selected again till all other songs in the playlist are played randomly
    curr->flag = 1;
    // Display the selected song to the user
    printf("Shuffled Song:\n");
    printf("Singer: %s\n", curr->singer);
    printf("Lyricist: %s\n", curr->lyricist);
    printf("Album/Film: %s\n", curr->album);
    printf("Composer: %s\n", curr->composer);
    printf("Genre: %s\n", curr->genre);
    printf("Duration: %f\n", curr->duration);
}*/
int main()
{
	struct node* lptr=NULL;
    struct node* nptr=lptr;
    struct node* currnode = NULL;
	//last=lptr;
	int a,count=0;
	char song[20];
	while(a!=4)
	{
		printf("1.add song\n2.delete song\n3.Display\n4.Exit\nEnter your choice:");
		scanf("%d",&a);
		if(a==1)
		{
			count++;
			lptr=insert(lptr);
		}
		else if(a==2)
		{
			printf("enter song to be deleted:");
			gets(song);
			lptr=delete_song(lptr,song);
		}
		else if(a==3)
		{
			
			display(lptr);
		}
	} 	
	printf("\nEnter data to be inserted : ");
	scanf("%s\t%s\t%s\t%s\t%s\t%s\t%f", nptr->song, nptr->singer, nptr->lyricist, nptr->composer, nptr->album, nptr->genre, nptr->duration);
	InsertSong();
	printf("\nNew Linked list is as follows : ");
	printf("%s\t%s\t%s\t%s\t%s\t%s\t%f", nptr->song, nptr->singer, nptr->lyricist, nptr->composer, nptr->album, nptr->genre, nptr->duration);
	return 0;
}
