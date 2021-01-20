#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
void vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        vote(name);
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
void vote(string name)
{
    int invalid = 0;
    // TODO
    for(int i = 0; i < candidate_count; i++){
        if(strcmp(name, candidates[i].name) == 0){
            candidates[i].votes++;
        }
    }
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max = 0;
    string winner = NULL;
    for(int i = 0; i < candidate_count; i++){
        if(max < candidates[i].votes){
            winner = candidates[i].name;
            max = candidates[i].votes;
        }
    }
    printf("Winner is %s with %i votes.\n", winner, max);
    return;
}

