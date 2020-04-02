#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

//vector<std::string> participant = { "leo", "kiki", "eden" };
//vector<std::string> completion = { "eden", "kiki" };
vector<std::string> participant = { "mislav", "stanko", "mislav", "ana", "mislav", "ana" };
vector<std::string> completion = { "mislav", "ana", "stanko", "mislav", "mislav" };
//vector<string> participant = { "marina", "josipa", "nikola", "vinko", "filipa" };
//vector<string> completion = { "josipa", "filipa", "marina", "nikola" };

// 한명 빼고 완주
// 완주하지 못한 선수 이름 리턴
// 1 <= 선수 수 <- 100,000
// 1 <= 이름 길이 <= 20
// 동명 이인 가능
string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";

	unordered_map<string, int> completionMap;
	for (auto iter : completion)
	{
		if (completionMap.find(iter) != completionMap.end())
		{
			completionMap[iter]++;
		}
		else
		{
			completionMap.insert(make_pair(iter, 1));
		}
	}

	for (auto iter : participant)
	{
		if (completionMap.find(iter) == completionMap.end()) {
			answer = iter;
			break;
		}
		else
		{
			completionMap[iter]--;
			if (completionMap[iter] < 0)
			{
				answer = iter;
				break;
			}
		}
	}

	return answer;
}

int main()
{
	const std::string answer = solution(participant, completion);
	std::cout << answer << std::endl;
	return 0;
}
