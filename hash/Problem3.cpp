#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	std::unordered_map<std::string, std::vector<std::string>> hashMap;
	for (auto iter : clothes)
	{
		auto temp = hashMap.find(iter[1]);
		if (temp != hashMap.end())
		{
			temp->second.emplace_back(iter[0]);
		}
		else
		{
			std::vector<std::string> tempVector;
			tempVector.emplace_back(iter[0]);
			hashMap.insert(std::make_pair(iter[1], tempVector));
		}
	}
	
	for (auto iter : hashMap)
    {
		answer *= (static_cast<int>(iter.second.size())+1);
	}
    answer -= 1;

	return answer;
}
