#include<string>
#include<iostream>
using namespace std;

#define Play_Max 50

struct Mahjong
{
	string sort; //�����v�̎��
	int locate;  //�ǂ̈ʒu����o���ꂽ��
}tile;

int main()
{
	struct Mahjong tile[Play_Max];
	int play = 0;

	// �v������
	while (play < Play_Max)
	{
		cout << "�����v�̎�ނ���͂��Ă��������F";
		cin >> tile[play].sort;

		if (tile[play].sort == "end")
		{
			break;
		}

		cout << "�����牽�Ԗڂ̈ʒu����o���ꂽ�����͂��ĉ������F";
		cin >> tile[play].locate;
		cout << "\n";

		play++;

	}

	//�`�F�b�N
	for (int i = 0; i < play; i++)
	{
		cout << i + 1 << "���\n" << "������" << tile[i].locate << "�Ԗڂ���"
			<< tile[i].sort << "���o���ꂽ\n\n";
	}
	//cout << "Check�F" << mjTiles;


}