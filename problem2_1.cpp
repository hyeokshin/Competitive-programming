#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
	int answer = 0;
	priority_queue<int, vector<int>> que;
	int i = 0;
	for (int day = 0; day != k; day++)
	{
		if (dates[i] == day)
		{
			que.push(supplies[i]);
			i++;
		}
		if (!stock)
		{
			stock += que.top();
			que.pop();
			answer++;
		}
		stock--;
	}
	return answer;
}


int main()
{
	const int stock = 4;
	const vector<int> dates = { 4, 10, 15 };
	const vector<int> supplies = { 20, 5, 10 };
	const int k = 30;

	solution(stock, dates, supplies, k);
	return 0;
}
