#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
class Solution{
    public:
    static bool Compare(vector<int> &trip1, vector<int> &trip2)
    {
        return trip1[1] < trip2[1];
    }

    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        sort(trips.begin(), trips.end(),Compare);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        int currentPassengers=0;

        for(const auto &trip: trips)
        {
            // 하차
            while(!heap.empty() && heap.top().first <= trip[1])
            {
                currentPassengers -= trip[0];
                heap.pop();
            }

            // 승차
            currentPassengers += trip[0];
            heap.push({trip[1],trip[0]});

            if(currentPassengers > capacity)
            {
                return false;
            }
            return true;
        }
    }
};

/*
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        vector<pair<int,int>> v ;
        
        for(int i=0;i<trips.size();i++)
        {
            v.push_back({trips[i][1],trips[i][0]}) ; // pushing fromi , numPassengersi
            
            v.push_back({trips[i][2],-trips[i][0]}) ; // pushing toi , -numPassengersi
        }
        
        sort(v.begin(),v.end()) ;
        
        int curr = 0 ;
        
        for(int i=0;i<v.size();i++)
        {
            curr+=v[i].second ;
            
            if(curr>capacity)
                return false ;
        }
        
        return true ;      
    }
};
*/