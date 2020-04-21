#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    vector<int> heap;

    for (auto iter : operations)
    {
        // 명령어 처리
        if (iter[0] == 'I') // 큐에 숫자 삽입
        {
            const int value = atoi(iter.substr(1, iter.length()).c_str());
            heap.emplace_back(value);
            sort(heap.begin(), heap.end());
            continue;
        }
        
        if (heap.empty())
        {
            continue;
        }

        if(iter[2]=='-') // 큐에서 최솟값 삭제
        {
            heap.erase(heap.begin());
            heap.shrink_to_fit();
        }
        else // 큐에서 최댓값 삭제
        {
            heap.erase(heap.begin() + heap.size()-1);
            heap.shrink_to_fit();
        }
    }

    if (heap.empty())
    {
        answer.emplace_back(0);
        answer.emplace_back(0);
    }
    else
    {
        answer.emplace_back(heap[heap.size()-1]);
        answer.emplace_back(heap[0]);
    }
    return answer;
}

int main()
{
    //vector<string> operations = {"I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D - 1", "D - 1", "I 5", "I 6"};
    vector<string> operations = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };
    solution(operations);
}