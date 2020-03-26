#include<string>
#include<iostream>
using namespace std;

#define Play_Max 10
#define Tehai_Num 13
#define Supai_Num 9
#define Zihai_Num 7

struct Mahjong
{
	bool sozu[Supai_Num];  //索子
	bool pinzu[Supai_Num]; //筒子
	bool manzu[Supai_Num]; //萬子
	bool zihai[Zihai_Num]; //字牌

						   //string sort; //麻雀牌の種類
						   //int locate;  //どの位置から出されたか
}tile;

int main()
{
	struct Mahjong tile[Tehai_Num];

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

	int play = 0, locate;
	string sort;

	// 牌情報入力
	while (play < Play_Max)
	{
		cout << "麻雀牌の種類を入力してください：";
		cin >> sort;

		cout << "左から何番目の位置から出されたか入力して下さい：";
		cin >> locate;
		cout << "\n";

		if (sort.find("souzu") != std::string::npos)
		{

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

	//チェック
	/*for (int i = 0; i < play; i++)
	{
	cout << i + 1 << "回目\n" << "左から" << tile[i].locate << "番目から"
	<< tile[i].sort << "が出された\n\n";
	}*/
	//cout << "Check：" << mjTiles;


}