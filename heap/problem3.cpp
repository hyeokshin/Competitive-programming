#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

struct compareProcess
{
    bool operator()(const vector<int>& l, const vector<int>& r) const
    {
        return l[1] > r[1];
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    int numOfJobs = static_cast<int>(jobs.size());
    int currentTime = 0;
    int currentIndex = 0;

    sort(jobs.begin(), jobs.end());

    priority_queue<vector<int>, vector<vector<int>>, compareProcess> heap;
    while (1)
    {
        if (currentIndex < numOfJobs)
        {
            if (jobs[currentIndex][0] <= currentTime)
            {
                heap.push(jobs[currentIndex]);
                currentIndex++;
                continue;
            }
        }

        if (!heap.empty())
        {
            currentTime += heap.top()[1];
            answer += (currentTime - heap.top()[0]);
            heap.pop();
        }
        else
        {
            if (numOfJobs <= currentIndex)
            {
                break;
            }
            currentTime = jobs[currentIndex][0];
        }
    }

    return floor(answer /= numOfJobs);
}

int main()
{
    vector<vector<int>> jobs = { {0, 3}, {1, 9}, {2, 6} };
    solution(jobs);
    return 0;
}
