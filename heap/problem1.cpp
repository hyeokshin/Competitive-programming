#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K)
{
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> heap(scoville.begin(), scoville.end());

	while (heap.top() < K)
	{
		const int a = heap.top();
		heap.pop();
		const int b = heap.top();
		heap.pop();
		const int newScoville = a + b * 2;
		heap.push(newScoville);

		answer++;
		if (heap.size() == 1 && heap.top() < K)
		{
			return -1;
		}
	}

	return answer;
}

int main()
{
	std::vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
	auto results = solution(scoville, 7);

	return 0;
}