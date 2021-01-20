#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

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

int pair_comparison (const void * candidate1, const void * candidate2)
{
    pair c1 = *((pair*)candidate1);
    pair c2 = *((pair*)candidate2);
    return ((preferences[c1.winner][c1.loser] - preferences[c1.loser][c2.winner]) - (preferences[c2.winner][c2.loser] - preferences[c2.loser][c2.winner]));

}

bool helper(int index, bool visited[]){
    if(visited[index]){
        return true;
    }
    visited[index] = true;
    for(int i = 0; i < candidate_count; i++){
        if(locked[index][i] && helper(i, visited)){
            return true;
        }
    }
    return false;
}

bool checkIsCycleExists(int index){
    bool isVisited[candidate_count];
    for(int i = 0; i < candidate_count; i++){
        isVisited[i] = false;
    }
    return helper(index, isVisited);
}

bool isWinner(int j){
    for(int i = 0; i < candidate_count; i++){
        if(locked[i][j] == true){
            return false;
        }
    }
    return true;
}

int getWinner(){
    for(int i = 0; i < candidate_count; i++){
        if(isWinner(i) == true){
            return i;
        }
    }
    return -1;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for(int i = 0; i < candidate_count; i++){
        if(strcmp(name, candidates[i]) == 0){
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for(int i = 0; i < candidate_count; i++){
        for(int j = i + 1; j < candidate_count; j++){
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for(int i = 0; i < candidate_count; i++){
        for(int j = 0; j < candidate_count; j++){
            if(preferences[i][j] > preferences[j][i]){
                pair candidates_pair;
                candidates_pair.winner = i;
                candidates_pair.loser = j;
                pairs[pair_count++] = candidates_pair;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    qsort(pairs, pair_count, sizeof(pair), pair_comparison);
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for(int i = 0; i < candidate_count; i++){
        locked[pairs[i].winner][pairs[i].loser] = true;
        if(checkIsCycleExists(pairs[i].winner)){
           locked[pairs[i].winner][pairs[i].loser] = false;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int person = getWinner();
    if(person != -1){
        printf("%s is winner.\n", candidates[person]);
    }
    return;
}
