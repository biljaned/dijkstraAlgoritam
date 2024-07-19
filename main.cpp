#include <bits/stdc++.h>

using namespace std;

int main()
{

    ///algoritam ne radi u slucaju da postoje negativne grane u grafu

    cout << "Unesite broj cvorova i broj grana u grafu" << endl;
    int n,m;//broj cvorova i grana
    cin >> n >> m;
    cout << "Unesite grane i tezine za tezinski graf" << endl;
    vector<vector<pair<int,int>>> graf(n+1,vector<pair<int,int>>(0));
    for(int i=0; i<m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        graf[a].push_back({b,w});//grana a->b sa tezinom w
        graf[b].push_back({a,w});//grana b->a sa tezinom w
    }
    cout << "Unesite od kog cvora trazite najkracu distancu" << endl;
    int X;
    cin >> X;//cvor od kog trazimo najkrace distance do drugih
    priority_queue<pair<int,int>> red;//struktura koja cuva parove: predjena distanca, cvor do koga se stiglo
	//na kraju se uvek nalazi najveci element  
    red.push({0,X});
    vector<bool> visited(n+1,0);//vector posecenosti
    vector<int> min_dist(n+1);//ovde cuvamo kolika je najmanja distanca ostalih cvorova od cvora x
    while(red.size()){
        int node=red.top().second,tr_dist=-red.top().first;
        red.pop();
        if(visited[node]) continue;
        visited[node]=true;
        min_dist[node]=tr_dist;
        for(auto x:graf[node])
            red.push({-(tr_dist+x.second),x.first});
    }
    for(int i=1; i<=n; i++)
        cout << "Najmanja distanca od cvora " << X << " do cvora " << i << " je " << min_dist[i] << endl;


    return 0;
}
