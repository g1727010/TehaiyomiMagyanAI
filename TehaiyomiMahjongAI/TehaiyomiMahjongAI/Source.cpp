#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<sstream>
#include<ctime>
#include<cstdlib>

using namespace std;

#define Play_Max 10
#define Tehai_Num 13
#define Supai_Num 9
#define Zihai_Num 7

enum Mark
{
	SOUZU_1 = 1,
	SOUZU_2,
	SOUZU_3,
	SOUZU_4,
	SOUZU_5,
	SOUZU_6,
	SOUZU_7,
	SOUZU_8,
	SOUZU_9,

	PINZU_1,
	PINZU_2,
	PINZU_3,
	PINZU_4,
	PINZU_5,
	PINZU_6,
	PINZU_7,
	PINZU_8,
	PINZU_9,

	MANZU_1,
	MANZU_2,
	MANZU_3,
	MANZU_4,
	MANZU_5,
	MANZU_6,
	MANZU_7,
	MANZU_8,
	MANZU_9,

	ZIHAI_1,
	ZIHAI_2,
	ZIHAI_3,
	ZIHAI_4,
	ZIHAI_5,
	ZIHAI_6,
	ZIHAI_7,
	ZIHAI_8,

	MARK_MAX,
};

class Util {
private:
	static bool is_init_mark_table_;
	static std::map<std::string, Mark> mark_table_;

	static void init_mark_enum()
	{
		mark_table_["sozu1"] = Mark::SOUZU_1;
		mark_table_["sozu2"] = Mark::SOUZU_2;
		mark_table_["sozu3"] = Mark::SOUZU_3;
		mark_table_["sozu4"] = Mark::SOUZU_4;
		mark_table_["sozu5"] = Mark::SOUZU_5;
		mark_table_["sozu6"] = Mark::SOUZU_6;
		mark_table_["sozu7"] = Mark::SOUZU_7;
		mark_table_["sozu8"] = Mark::SOUZU_8;
		mark_table_["sozu8"] = Mark::SOUZU_9;

		・・・

			mark_table_["tyun"] = Mark::ZIHAI_8;
		mark_table_["中"] = Mark::ZIHAI_8;
	}

public:
	static Mark get_mark_enum(std::string s)
	{
		if (!is_init_mark_table_) {
			is_init_mark_table_ = true;
			init_mark_enum();
		}

		return mark_table_[s];
	}
};
bool Util::is_init_mark_table_ = false;
std::map<std::string, Mark> Util::mark_table_;

class Tehai {
private:
	Mark mark_[13];
	bool has_mark_[Mark::MARK_MAX];

public:
	Tehai() {}
	~Tehai() {}

};

class Teller {
	std::vector<Tehai> guess;
};

struct Mahjong
{
	bool sozu[Supai_Num];  //索子
	bool pinzu[Supai_Num]; //筒子
	bool manzu[Supai_Num]; //萬子
	bool zihai[Zihai_Num]; //字牌

						   //string sort; //麻雀牌の種類
						   //int locate;  //どの位置から出されたか
};




int main()
{
	Mahjong tile[Tehai_Num];

	// 初期化
	for (int i = 0; i < Tehai_Num; i++)
	{
		for (int j = 0; j < Supai_Num; j++)
		{
			tile[i].sozu[j] = true;
			tile[i].pinzu[j] = true;
			tile[i].manzu[j] = true;
		}

		for (int j = 0; j < Zihai_Num; j++)
		{
			tile[i].zihai[j] = true;
		}
	}

	int play = 0, locate, outputNum;
	string sort; //入力した牌の種類
	stringstream ss;

	string hai[34] = { "sozu1","sozu2","sozu3","sozu4","sozu5","sozu6","sozu7","sozu8","sozu9",
		"pinzu1","pinzu2","pinzu3","pinzu4","pinzu5","pinzu6","pinzu7","pinzu8","pinzu9",
		"manzu1","manzu2","manzu3","manzu4","manzu5","manzu6","manzu7","manzu8","manzu9",
		"ton","nan","sya","pei","haku","hatu","tyun"
	};

	string tehai[13];
	int randomNum;

	srand((unsigned int)time(NULL));

	// 牌情報入力
	while (play < Play_Max)
	{
		for (int i = 0; i < Tehai_Num; i++)
		{
			randomNum = rand() % 34;
			tehai[i] = hai[randomNum];

			cout << tehai[i] << " ";
		}

		cout << "\n\n";

		cout << "麻雀牌の種類を入力してください（例：souzu1、東、白）：";
		cin >> sort;

		cout << "左から何番目の位置から出されたか入力して下さい：";
		cin >> locate;
		cout << "\n";

		ss << sort;

		if (sort.find("souzu") != std::string::npos)
		{
			ss >> outputNum;
			cout << outputNum;
		}
		else if (sort.find("manzu") != std::string::npos)
		{
		}
		else if (sort.find("pinzu") != std::string::npos)
		{
		}
		else
		{

		}

		play++;
	}
