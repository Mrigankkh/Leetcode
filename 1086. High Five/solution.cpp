struct compare{

    bool operator()(int p, int q)
    {
        return p<q;
    }
};
class Solution {
    
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        set<int> students;
        unordered_map<int, priority_queue<int, vector<int>, compare>> marks;
        for(auto item : items)
        {
            students.insert(item[0]);
            if(marks.find(item[0])== marks.end())
            {
                 priority_queue<int, vector<int>, compare> pq;
                 pq.push(item[1]);
                marks[item[0]] = pq;
            }
            else
            {
                marks[item[0]].push(item[1]); 
            }
        }

        vector<vector<int>> ans;

        for(auto stu : students)
        {
            int sum = 0;
           for(int f=0;f<5;f++)
        {   sum+= marks[stu].top();
        marks[stu].pop();}
          ans.push_back({stu,sum/5});
        }
          

        return ans;
    }

};