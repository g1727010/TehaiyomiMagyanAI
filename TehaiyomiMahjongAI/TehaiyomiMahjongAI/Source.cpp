#include<string>
#include<iostream>
using namespace std;

#define Play_Max 10
#define Tehai_Num 13
#define Supai_Num 9
#define Zihai_Num 7

struct Mahjong
{
	bool sozu[Supai_Num];  //���q
	bool pinzu[Supai_Num]; //���q
	bool manzu[Supai_Num]; //�ݎq
	bool zihai[Zihai_Num]; //���v

						   //string sort; //�����v�̎��
						   //int locate;  //�ǂ̈ʒu����o���ꂽ��
}tile;

int main()
{
	struct Mahjong tile[Tehai_Num];

	// ������
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

	// �v������
	while (play < Play_Max)
	{
		cout << "�����v�̎�ނ���͂��Ă��������F";
		cin >> sort;

		cout << "�����牽�Ԗڂ̈ʒu����o���ꂽ�����͂��ĉ������F";
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

	//�`�F�b�N
	/*for (int i = 0; i < play; i++)
	{
	cout << i + 1 << "���\n" << "������" << tile[i].locate << "�Ԗڂ���"
	<< tile[i].sort << "���o���ꂽ\n\n";
	}*/
	//cout << "Check�F" << mjTiles;


}