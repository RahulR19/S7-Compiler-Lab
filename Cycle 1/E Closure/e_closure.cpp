#include <bits/stdc++.h>

using namespace std;

const int N = 100;      // Maximum size for nt and closure
int n, m;             	 // n = no. of states, m = no. of transitions
vector<int> nt[N][N];   // To store transition table           
set<int> closure[N];	 // To store e-closure              

void print_closure()
{
    cout << "\n Epsilon Closure:\n";
    cout << "============================\n";
    cout << "Q\tClosure\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Q" << i << "\t";
            cout << "{";
            for (int ii : closure[i])
                cout << ii << " ";
            cout << "}\t";
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
    print_closure();
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


 Epsilon Closure:
============================
Q	Closure
Q0	{0 1 2 }	
Q1	{1 2 }	
Q2	{2 }	



*/



