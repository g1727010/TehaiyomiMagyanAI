#include<string>
#include<iostream>
using namespace std;

#define Play_Max 50

struct Mahjong
{
	string sort; //麻雀牌の種類
	int locate;  //どの位置から出されたか
}tile;

int main()
{
	struct Mahjong tile[Play_Max];
	int play = 0;

	// 牌情報入力
	while (play < Play_Max)
	{
		cout << "麻雀牌の種類を入力してください：";
		cin >> tile[play].sort;

		if (tile[play].sort == "end")
		{
			break;
		}

		cout << "左から何番目の位置から出されたか入力して下さい：";
		cin >> tile[play].locate;
		cout << "\n";

		play++;

	}

	//チェック
	for (int i = 0; i < play; i++)
	{
		cout << i + 1 << "回目\n" << "左から" << tile[i].locate << "番目から"
			<< tile[i].sort << "が出された\n\n";
	}
	//cout << "Check：" << mjTiles;


}