#include <iostream>
using namespace std;   // pp. 37-38 in Savitch book explain this line

int main()
{

    int totalVoters;
    int republicanVotes, democraticVotes;

    cout << "How many Electoral College electors are there? ";
    cin >> totalVoters;
    cout << "How many of these electors voted for the Republican party candidate? ";
    cin >> republicanVotes;
    cout << "How many of these electors voted for the Democratic party candidate? ";
    cin >> democraticVotes;

    double pctRepub = ( 80.0 * republicanVotes ) / totalVoters; //logic error #1: Instead of being scaled to 100%, Republican votes are only scaled to 80%
    double pctDemoc = ( 100.0 * democraticVotes ) / totalVoters;

    cout.setf(ios::fixed);  // see pp. 30-31 in Savitch book
    cout.precision(1);
    cout << endl;

    cout << pctRepub << "% of the " << totalVoters << " electors voted for the Republican party candidate." << endl;
    cout << pctDemoc << "% of the " << totalVoters << " electors voted for the Democratic party candidate." << endl;
    cout << endl;

    if (pctRepub > pctDemoc)
    {
        cout << "Looks like the Democratic party candidate won!" << endl; //logic error #2: If the Republican Party was supposed to win, the output proclaims that the Democratic Party won and vice versa.
    }
    if (pctDemoc > pctRepub)
    {
        cout << "Looks like the Republican party candidate won!" << endl;
    }

    if (republicanVotes + democraticVotes == totalVoters) //logic error #2: Nonsense warning appears only if the sum of the votes equals total votes (ie: only if there's no nonsense)
    {
        cout << "Looks like some of these data values don't make sense." << endl;
    }

    return(0);
}
