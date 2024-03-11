#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    // loop through the candiadates loop and look for the voter name and its index
    for (int i = 0, n = candidate_count; i < n; i++)
    {
        if (strcmp(name, candidates[i].name) == 0) // if index candidates name marthes the given string name
        {
            preferences[voter][rank] = i; // voter rank preference is i index of candidates array
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    // loop throught the preference array
    for (int i = 0, n = voter_count; i < n; i++)
    {

        // if the candidate is not eliminated
        // 0 is the first prefenrence
        int preference = 0;
        int candidateIndex = preferences[i][preference];
        if (candidates[candidateIndex].eliminated == false)
        {
            candidates[candidateIndex].votes++;
        }
        else // candidate is eliminated
        {
            // the next prefrence
            preference++;
            candidateIndex = preferences[i][preference];
            candidates[candidateIndex].votes++; // update the candidates vote count
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    int halfVote = voter_count / 2;

    // loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > halfVote)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    int smallestValueIndex = 0;
    for (int i = 0; i < candidate_count - 1; i++)
    {
        if (candidates[i].eliminated == false && candidates[i + 1].eliminated == false) // only look at the
        {
            if (candidates[smallestValueIndex].votes > candidates[i + 1].votes)
            {
                smallestValueIndex = i + 1;
            }
        }
    }
    int minVotes = candidates[smallestValueIndex].votes; // number of fewest vote
    return minVotes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes > min)
        {
            // one of the candidate that is not eliminated, has vote bigger than min
            return false;
        }
    }
    // if were here meanig the loop didnt catch any vote that are higher than min, everyone has the min vote equally
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}
