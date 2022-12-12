#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack1(int W, int wt[], int val[], int n)
{
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

// Backtracking
int knapSack2(int W, int wt[], int val[], int n)
{
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++)
    {
        for (int w = W; w >= 0; w--)
        {

            if (wt[i - 1] <= w)
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W];
}

// Branch & Bound
struct Item
{
    float weight;
    int value;
};

struct Node
{
    int level, profit, bound;
    float weight;
};

bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int bound(Node u, int n, int W, Item arr[])
{
    if (u.weight >= W)
        return 0;

    int profit_bound = u.profit;

    int j = u.level + 1;
    int totweight = u.weight;

    while ((j < n) && (totweight + arr[j].weight <= W))
    {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }

    if (j < n)
        profit_bound += (W - totweight) * arr[j].value /
                        arr[j].weight;

    return profit_bound;
}

int knapSack3(int W, Item arr[], int n)
{
    sort(arr, arr + n, cmp);

    queue<Node> Q;
    Node u, v;

    u.level = -1;
    u.profit = u.weight = 0;
    Q.push(u);

    int maxProfit = 0;
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();

        if (u.level == -1)
            v.level = 0;

        if (u.level == n - 1)
            continue;

        v.level = u.level + 1;

        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v, n, W, arr);

        if (v.bound > maxProfit)
            Q.push(v);

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
    }

    return maxProfit;
}

int main()
{
    /*int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };*/
    int W ;
    cin>>W;
    // int n = sizeof(val) / sizeof(val[0]);
    int n;
    cin>>n;
    int val[n];
    int wt[n];
    Item arr[] = {{10,60}, {20,100}, {30,120}};
    for(int i = 0; i<n; i++)
    {
        cout<<"profit of "<<i+1<<" object";
        cin>>val[i];
        cout<<"Weight of "<<i+1<<" object";
               
        cin>>wt[i];
    }
    cout << "Dynamic Programming : " << knapSack1(W, wt, val, n) << endl;
    cout << "Backtracking : " << knapSack2(W, wt, val, n) << endl;
    cout << "Branch & Bound : " << knapSack3(W, arr, n) << endl;
    return 0;
}
