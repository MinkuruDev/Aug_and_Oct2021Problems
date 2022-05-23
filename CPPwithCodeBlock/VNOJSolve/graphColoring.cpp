#include <iostream>
#include <vector>
#define Graph vector<vector<bool>>

using namespace std;

vector<int> nearbyVertex(Graph G, int vertex){
    vector<int> nearby;
    for(int i = 1; i<G.size(); i++){
        if(G[vertex][i]) nearby.push_back(i);
    }

    return nearby;
}

vector<int> greedyColoring(Graph G){
    int X = G.size();
    vector<int> color(X, 0);
    color[1] = 1;
    int totalColor = 1;

    for(int i = 2; i < X; i++){
        vector<bool> available(totalColor + 1, true);

        auto nearby = nearbyVertex(G, i);
        for(int j = 0; j<nearby.size(); j++){
            available[color[nearby[j]]] = false;
        }

        for(int j = 1; j<=totalColor; j++){
            if(available[j]){
                color[i] = j;
                break;
            }
        }

        if(color[i] == 0){
            totalColor = totalColor + 1;
			color[i] = totalColor;
        }
    }

    return color;
}

int main(){
    cout << "nhap vao so dinh va so canh cua do thi: ";
    int X, U; cin >> X >> U;
    Graph graph(X + 1, vector<bool> (X + 1, 0));
    int a,b;
    for(int i = 1; i<=U; i++){
        cout << "nhap canh so " << i << ": ";
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    auto color = greedyColoring(graph);
    for(int i = 1; i<=X; i++){
        cout << "dinh so " << i << " mau so " << color[i] << endl;
    }
    return 0;
}
