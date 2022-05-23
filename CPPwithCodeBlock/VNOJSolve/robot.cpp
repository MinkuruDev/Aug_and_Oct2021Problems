#include <bits/stdc++.h>

using namespace std;

struct Creature{
    int x,y;
    long long mood;
    int operator-(Creature other){
        return abs(x - other.x) + abs(y - other.y);
    }
};

void logCreatures(Creature robot, vector<Creature> creatures){
    printf("robot: %d %d\n", robot.x, robot.y);
    Creature creature = *creatures.begin();
    printf("first creature: %d %d %d\n", creature.x, creature.y, creature.mood);
    creature = creatures.back();
    printf("last creature: %d %d %d\n", creature.x, creature.y, creature.mood);
}

int calculateMood(Creature robot, vector<Creature> creatures){
    int sum = 0;
    for(auto it = creatures.begin(); it<creatures.end(); it++){
        sum += robot - *it;
    }
    return sum;
}

bool updateMood(vector<Creature> &creatures, Creature robot){
    bool flag = true;
    for(auto it = creatures.begin(); it<creatures.end(); it++){
        (*it).mood -= robot - (*it);
        if((*it).mood < 0) flag = false;
    }

    return flag;
}

string findBestWay(Creature robot, int n, vector<Creature> creatures){
    string result = "";

    int Emove, Nmove;
    while(true){
        // do East move
        robot.x++;
        if(robot.x <= n) Emove = calculateMood(robot, creatures);
        else Emove = (1 << 15) - 1;
        robot.x--;

        // do North move
        robot.y++;
        if(robot.y <= n) Nmove = calculateMood(robot, creatures);
        else Nmove = (1 << 15) - 1;
        robot.y--;

        //logCreatures(robot, creatures);
        if(robot.x == n && robot.y == n) break;
        if(Nmove < Emove){
            result.push_back('N');
            robot.y++;
            if(! updateMood(creatures, robot)){
                result = "Impossible";
                break;
            }
        }else{
            result.push_back('E');
            robot.x++;
            if(! updateMood(creatures, robot)){
                result = "Impossible";
                break;
            }
        }
    }

    //logCreatures(robot, creatures);
    return result;
}

void tryBetterWay(string path, Creature robot, vector<Creature> creatures){
    swap(path[0], path[1]);
    cout << path;
}

int main(){
    Creature robot; robot.x = 1; robot.y = 1;
    vector<Creature> creatures;
    int n,a,b,k;
    long long s;
    cin >> n >> s >> a >> b >> k;

    Creature creature;
    creature.x = a; creature.y = b; creature.mood = s;
    creatures.push_back(creature);
    if (k>1){
        Creature c;
        c.x = a + k - 1;
        c.y = b + k - 1;
        c.mood = s;
        creatures.push_back(c);
    }

    string path = findBestWay(robot, n, creatures);
    tryBetterWay(path, robot, creatures);
    return 0;
}
