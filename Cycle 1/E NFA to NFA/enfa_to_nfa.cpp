#include <bits/stdc++.h>

using namespace std;

const int N = 100;		      // Maximum states
int n, m;
vector<int> nt[N][N], nt1[N][N];     // nt = nfa with epsilon transition, nt1 nfa without epsilon transition
set<int> closure[N];

void print_without_eps()
{
    cout << "\nNFA without epsilon moves:\n";
    cout << "============================\n";
    cout << "\t\tSymbols\n";
    cout << "Q";
    for (int j = 0; j < m; j++)
    cout <<"\t" << char(j + 'a');
    cout << "\n";


    for (int i = 0; i < n; i++)
    {
        cout << "Q" << i << "\t";
        for (int j = 1; j <= m; j++)
        {
            cout << "{";
            for (int ii : nt1[i][j])
                cout << ii << " ";
            cout << "}\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    cout << "No. of states: ";
    cin >> n;
    cout << "No. of input symbols: ";
    cin >> m;
    cout << "Enter transitions:\n\n";

    // Transition table
    for (int i = 0; i < n; i++)
    {
        cout << "State " << i << endl;
        for (int j = 0; j <= m; j++)
        {

            cout << "\tNo of transitions for ";
            if (j == 0)
                cout << "eps";
            else
                cout << char(j + 'a' - 1);
            cout << ": ";
            int temp;
            cin >> temp;
            nt[i][j].resize(temp);
            if (temp == 0)
            {
            }
            else if (temp == 1)
            {
                cout << "\tEnter the state: ";
            }
            else
            {
                cout << "\tEnter the " << temp << " states: ";
            }
            for (int k = 0; k < nt[i][j].size(); k++)
            {
                cin >> nt[i][j][k];
            }
        }
        cout << endl;
    }

    // Finding epsilon closure for each state
    for (int i = 0; i < n; i++)
    {
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(i);
        vis[i] = 1;
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            for (int k = 0; k < nt[top][0].size(); k++)
            {
                int cur = nt[top][0][k];
                if (vis[cur] == 0)
                {
                    vis[cur] = 1;
                    q.push(cur);
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == 1)
                closure[i].insert(j);
        }
    }

    // Find epsilon* --> symbol --> epsilon* for each state and symbol
    for (int i = 0; i < n; i++)
    {
        for (int ii : closure[i])
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k = 0; k < nt[ii][j].size(); k++)
                {
                    int cur = nt[ii][j][k];
                    for (int iii : closure[cur])
                    {
                        nt1[i][j].push_back(iii);
                    }
                }
            }
        }
    }
    print_without_eps();
    return 0;
}

/* 
Output

No. of states: 3
No. of input symbols: 3
Enter transitions:

State 0
	No of transitions for eps: 1
	Enter the state: 1
	No of transitions for a: 1
	Enter the state: 0
	No of transitions for b: 0
	No of transitions for c: 0

State 1
	No of transitions for eps: 1
	Enter the state: 2
	No of transitions for a: 0
	No of transitions for b: 1
	Enter the state: 1
	No of transitions for c: 0

State 2
	No of transitions for eps: 0
	No of transitions for a: 0
	No of transitions for b: 0
	No of transitions for c: 1
	Enter the state: 2


NFA without epsilon moves:
============================
	     Symbols
Q	a	    b	    c
Q0	{0 1 2 }{1 2 }	{2 }	
Q1	{}	    {1 2 }	{2 }	
Q2	{}	    {}	    {2 }

*/	


