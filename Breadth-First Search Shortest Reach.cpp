#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include<limits>
using namespace std;

struct entity
{
    int node;
    int weight;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T, N, M, from, to, s;
    entity e, e1;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        vector<vector<int>> aList(N);
        vector<int> output(N, numeric_limits<int>::max());
        vector<int> finished(N, -1);
        vector<int>::iterator it;
        for (int i = 0; i < M; i++)
        {
            cin >> from >> to;
            it = find(aList[from - 1].begin(), aList[from - 1].end(), to - 1);
            if (it == aList[from - 1].end())
            {
                aList[from - 1].push_back(to - 1);
                aList[to - 1].push_back(from - 1);
            }
        }
        cin >> s;
        output[s - 1] = 0;
        queue<entity> myqueue;

        for (int v : aList[s - 1])
        {
            // cout << v;
            e.node = v;
            e.weight = 6;
            myqueue.push(e);

        }
        finished[s - 1] = 1;
        while (!myqueue.empty())
        {

            e = myqueue.front();

            if (e.weight < output[e.node])
            {
                output[e.node] = e.weight;
            }
            finished[e.node] = 1;
            myqueue.pop();
            for (int v : aList[e.node])
            {
                if (finished[v] != 1)
                {
                    e1.node = v;
                    e1.weight = 6 + e.weight;
                    myqueue.push(e1);
                }
            }
        }
        for (int i = 0; i < output.size(); i++)
        {
            if (i != s - 1)
            {
                if (output[i] != numeric_limits<int>::max())
                    cout << output[i] << " ";
                else
                    cout << -1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}