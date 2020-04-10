#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

struct compareGenre
{
	template<typename T>
	bool operator()(const T& l, const T& r) const
	{
		return l.second > r.second;
	}
};

bool comparePlay(const pair<int, int>& l, const pair<int, int>& r)
{
	if (l.second == r.second)
	{
		return l.first < r.first;
	}
	return l.second > r.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
	vector<int> answer;

	// 1. 재생 횟수를 다 더한 key 값이 genre인 map을 만든다.
	unordered_map<string, int> hashGenres;
	multimap<string, pair<int, int>> hashPlays;
	const int numOfMusics = static_cast<int>(genres.size());
	for (int idx = 0; idx < numOfMusics; idx++)
	{
		if (hashGenres.find(genres[idx]) == hashGenres.end())
		{
			hashGenres.insert(make_pair(genres[idx], plays[idx]));
		}
		else
		{
			hashGenres[genres[idx]] += plays[idx];
		}
		// 2. 장르를 키값으로 가지고, <고유번호, 플레이 횟수>를 value로 가지는 map을 추가한다.
		hashPlays.insert(make_pair(genres[idx], make_pair(idx, plays[idx])));
	}

	// 3. 정렬된 장르 벡터를 얻는다.
	set<pair<string, int>, compareGenre> hashGenresSorted(hashGenres.begin(), hashGenres.end());


	// 4. 정렬된 장르 순서대로, 노래 재생 횟수대로 answer에 추가
	for (auto iter : hashGenresSorted)
	{
		auto it = hashPlays.find(iter.first);
		int numOfPlays = static_cast<int>(hashPlays.count(iter.first));
		// 한 개면 바로 추가
		if (numOfPlays == 1)
		{
			answer.emplace_back(it->second.first);
			continue;
		}

		// 정렬 후 앞에 2개만 추가
		std::vector<pair<int, int>> sortedPlay;
		for (int i = 0; i < numOfPlays; ++i, ++it)
		{
			sortedPlay.emplace_back(it->second);
		}
		sort(sortedPlay.begin(), sortedPlay.end(), comparePlay);

		for (int idx = 0; idx < 2; idx++)
		{
			answer.emplace_back(sortedPlay[idx].first);
		}
	}

	return answer;
}

int main()
{
	vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> plays = { 500, 600, 150, 800, 2500 };
	solution(genres, plays);
	return 0;
}
