#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> arguments) {
    vector<int> answer;
    multiset<int> que;
    multiset<int>::iterator iter;
    string sub;

    for (auto s : arguments) 
    {
        sub = s.substr(0, 2);
        if (sub == "I ")
        {
            que.insert(stoi(s.substr(2, s.length() - 2)));
        }
        else if (s.substr(2, 1) == "1" && que.size() > 0)
        { 
            que.erase(--que.end()); 
        }
        else if (que.size() > 0) 
        { 
            que.erase(que.begin()); 
        }
    }

    if (que.size() == 0) 
    { 
        answer.push_back(0); answer.push_back(0); 
    }
    else 
    {
        iter = --que.end(); answer.push_back(*iter);
        iter = que.begin(); answer.push_back(*iter);
    }

    return answer;
}

int main()
{
    //vector<string> operations = {"I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D - 1", "D - 1", "I 5", "I 6"};
    vector<string> operations = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };
    solution(operations);
}