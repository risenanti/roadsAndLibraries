#include <bits/stdc++.h>
using namespace std;

void DFS(int vertice, bool visited[] ,list<int> *adj);

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int numberOfCities;
        int numberOfRoads;
        long cLib;
        long cRoad;
        cin >> numberOfCities >> numberOfRoads >> cLib >> cRoad;

        if(cRoad>=cLib)
        {
            cout<< (cLib*numberOfCities) << endl;
            return 0;
        }

        list<int> *city = new list<int>[numberOfCities+1];
        bool *visited = new bool[numberOfCities+1];
        for (int i = 0; i < numberOfCities; i++)
        {
            visited[i] = false;
        }

        //add edges to graph
        for(int a1 = 0; a1 < numberOfRoads; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            city[city_1].push_back(city_2);
            city[city_2].push_back(city_1);
        }

        DFS(1, visited, city);

        for (int i = 1; i < numberOfCities+1; i++)
        {
        	cout<< visited[i] <<" "<<endl;
        }

        delete[] city;
        delete[] visited;
    }
    return 0;
}

void DFS(int vertice, bool visited[] ,list<int> *adj)
{
	visited[vertice] = true;

	//process node

	list<int>::iterator i;
	for(i = adj[vertice].begin(); i != adj[vertice].end(); ++i)
	{
		DFS(*i, visited, adj);
	}
}
