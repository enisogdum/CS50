#include <cs50.h>
#include <string.h>

#include <stdio.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX] = {0};

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
int find_lock(int winner, int loser);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    int i = 0;

    while (i < candidate_count)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
        i++;
    }
    
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int i = 0;
    int j = 0;
    for ( i = 0; i < candidate_count - 1; i++)
    {
        for ( j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
        
    }
    
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int i, j;

    for ( i = 0; i < candidate_count; i++)
    {
        for ( j = i + 1; j < candidate_count; j++)
        {
            if ((preferences[i][j] != preferences[j][i]))
            {
                    pair_count++;
                    if (preferences[i][j] > preferences[j][i])
                    {
                      pairs[pair_count - 1].winner = i;
                      pairs[pair_count - 1].loser = j;;
                    }
                    else
                    {
                    pairs[pair_count - 1].winner = j;
                    pairs[pair_count - 1].loser = i;
                    }
                
            }
            
        }
        
    }
    
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int i = 0;
    int j;
    int swapped = 1;
    pair temp;


while (swapped)
{
    j=0;
    swapped=0;
   while (j < pair_count - i - 1)
   {

    if (preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner] < preferences[pairs[j + 1].winner][pairs[j + 1].loser] - preferences[pairs[j + 1].loser][pairs[j + 1].winner])
    {
        temp = pairs[j];
        pairs[j] = pairs[j + 1];
        pairs[j + 1] = temp;
        swapped=1; 
    }

    j++;

   }

   i++;
}
    
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
   int i = 0;

   for ( i = 0; i < pair_count; i++)
   {

     if(!(find_lock(pairs[i].winner, pairs[i].loser)))
     {
        locked[pairs[i].winner][pairs[i].loser] = true;
     }
   }
   
}

int find_lock(int winner, int loser)
{
    int i, j, k;
    int first = winner;

    for ( j = 0; j < candidate_count; j++)
    {
        if (locked[j][winner] == true)
        {
            if (j == loser)
            {
                return 1;
            }
            else
            {
               if(find_lock(j, loser))
               {
                return 1;
               }
            }
            
        }
        
    }
    return 0;

}


// Print the winner of the election
void print_winner(void)
{
    int i, j;
    bool winner;

    for (i = 0; i < candidate_count; i++)
    {
        winner = true;

        for (j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == true)
            {
                winner = false;
                break;
            }
        }

        if (winner)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
}

