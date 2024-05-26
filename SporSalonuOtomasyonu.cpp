/*                                  A�a��daki   #include "ConsoleColor.h"    kodu yaz�lar� renklendirmek i�in kullan�lm��t�r.
									Bu kodu kullanmak i�in projenize Header olarak kodlar� eklemeniz gerekmektedir
								�lgili Kodlar Payla��lm��t�r.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <iomanip>
#include <time.h>
#include <Windows.h>
#include <sstream>
#include "ConsoleColor.h"
using namespace std;
//Yaz�lar Sar� Olacak
string MenuTitle;
int nom = 0;
int counter = 0;
char s = 0;

//�yeler �le �lgili Bilgiler
class Member
{
public:
	int no;
	string name, surname;
	string regisdate, enddate;
	void EnterInfo();
	void ShowInfo(int number);
};
void Member::EnterInfo()
{
	void gotoxy(short x, short y);
	gotoxy(23, 11);
	cin >> name;
	gotoxy(23, 13);
	cin >> surname;
	gotoxy(23, 15);
	cin >> regisdate;
	gotoxy(23, 17);
	cin >> enddate;
	no = 1;

}
void Member::ShowInfo(int number)
{
	void gotoxy(short x, short y);
	gotoxy(3, 8 + number);
	cout << no;
	gotoxy(15, 8 + number);
	cout << name;
	gotoxy(38, 8 + number);
	cout << surname;
	gotoxy(63, 8 + number);
	cout << regisdate;
	gotoxy(85, 8 + number);
	cout << enddate;

}
//�ye Eklerken Di�er �yeleri Kontrol Etme
class MemberControl
{
public:
	int no;
	string name, surname;
	string regisdate, enddate;
};
//Dosya ��lemleri
class Gym
{
public:
	void AddMember();
	void ShowMember();
	void DeleteMember();
	void UpdateMember();

};
void Gym::AddMember()
{
	void MainMenu();
	void gotoxy(short x, short y);
	void AddNewMember();
	void Wait(int time);
	int c0;
	Member member;
	MemberControl control;
	fstream file;
	Gym gym;
	member.EnterInfo();
	do
	{
		file.open("Members.txt", ios::in | ios::app | ios::out);
		c0 = 0;
		while (file >> control.no >> control.name >> control.surname >> control.regisdate >> control.enddate)
		{
			if (member.no == control.no)
			{
				c0++;
			}
		}
		file.close();
		if (c0 > 0)
		{
			member.no = member.no + 1;
		}
	} while (c0 > 0);
	file.open("Members.txt", ios::out | ios::app);
	file.setf(ios::left);
	file << setw(10) << member.no << setw(20) << member.name << setw(20) << member.surname << setw(20) <<
		member.regisdate << setw(20) << member.enddate << endl;
	file.close();
	gotoxy(20, 22);
	cout << green << "Ba�ar�yla Eklenmi�tir.";
	Wait(1);
	cout << white;
	gotoxy(1, 25);
	cout << "[1] YEN� �YE EKLE";
	gotoxy(1, 26);
	cout << "[9] ANA MENU";
	gotoxy(1, 27);
	cout << "[X] �IKI�";
	gotoxy(1, 29);
	cout << "SE��M�N�Z : [ ]";
	gotoxy(14, 29);
	cin >> s;
	if (s == '1')
	{
		system("CLS");
		AddNewMember();
		gym.AddMember();
	}
	else if (s == '9')
	{
		system("CLS");
		MainMenu();
	}
	else if (s == 'X' || s == 'x')
	{
		exit(0);
	}
	else
	{
		cout << "Yanl�� Se�im Yapt�n�z.Ana Men�ye Y�nlendiriliyosunuz.";
		for (int i = 0; i < 3; i++)
		{
			Wait(1);
			cout << ".";
		}
		MainMenu();
	}
}
void Gym::ShowMember()
{
	void gotoxy(short x, short y);
	void Wait(int time);
	void MainMenu();
	int number = 0;
	fstream file;
	Member member;
	file.open("Members.txt", ios::in | ios::app);
	while (file >> member.no >> member.name >> member.surname >> member.regisdate >> member.enddate)
	{
		member.ShowInfo(number);
		number += 2;
	}
	file.close();

}
void Gym::UpdateMember()
{
	void nomf();
	void AddNewMember();
	void Again();
	void Wait(int time);
	void gotoxy(short x, short y);
	void MemberUpdate();
	void MainMenu();
	Gym gym;
	Member member;
	MemberControl memcont;
	int no;
	gotoxy(40, 8 + (nom * 2) + 4);
	cin >> no;
	fstream file;
	fstream filetemp;
	file.open("Members.txt", ios::in | ios::out | ios::app);
	filetemp.open("Memberstemp.txt", ios::in | ios::out | ios::app);
	filetemp.setf(ios::left);
	while (file >> member.no >> member.name >> member.surname >> member.regisdate >> member.enddate)
	{
		if (no == member.no)
		{
			system("CLS");
			AddNewMember();
			gotoxy(22, 8);
			cout << "   KAYIT G�NCELLEME";
			member.EnterInfo();
			member.no = no;

		}

	}
	file.close();
	file.open("Members.txt", ios::in | ios::out | ios::app);
	while (file >> memcont.no >> memcont.name >> memcont.surname >> memcont.regisdate >> memcont.enddate)
	{
		if (no == memcont.no)
		{
			filetemp << setw(10) << member.no << setw(20) << member.name <<
				setw(20) << member.surname << setw(20) <<
				member.regisdate << setw(20) << member.enddate << endl;
		}
		else
		{
			filetemp << setw(10) << memcont.no << setw(20) << memcont.name <<
				setw(20) << memcont.surname << setw(20) <<
				memcont.regisdate << setw(20) << memcont.enddate << endl;
		}

	}
	file.close();
	remove("Members.txt");
	filetemp.close();
	rename("Memberstemp.txt", "Members.txt");

	if (counter == nom)
	{

		cout << red << "Kullan�c� Bulunamad�."; cout << white;
	}
	else
	{
		gotoxy(20, 22);
		cout << green << "Kullan�c� G�ncellendi."; cout << white;
	}

	gotoxy(1, 25);
	cout << "[1] �YE G�NCELLE";
	gotoxy(1, 27);
	cout << "[9] ANA MENU";
	gotoxy(1, 29);
	cout << "[X] �IKI�";
	gotoxy(1, 31);
	cout << "SE��M�N�Z : [ ]";
	gotoxy(14, 31);
	cin >> s;
	if (s == '1')
	{
		nomf();
		system("CLS");
		counter = 0; MemberUpdate();
		if (nom != 0)
		{
			gym.ShowMember(); gym.UpdateMember();
		}
		else
		{
			Again();
		}
	}
	else if (s == '9')
	{
		system("CLS");
		MainMenu();
	}
	else if (s == 'X' || s == 'x')
	{
		exit(0);
	}
	else
	{
		cout << "Yanl�� Se�im Yapt�n�z.Ana Men�ye Y�nlendiriliyosunuz.";
		for (int i = 0; i < 3; i++)
		{
			Wait(1);
			cout << ".";
		}
		MainMenu();
	}

}
void Gym::DeleteMember()
{
	void nomf();
	void Again();
	void Wait(int time);
	void gotoxy(short x, short y);
	void MemberDelete();
	void MemberViews();
	void MainMenu();
	Member member;
	Gym gym;
	int no;
	gotoxy(35, 8 + (nom * 2) + 4);
	cin >> no;
	fstream file;
	fstream filetemp;
	file.open("Members.txt", ios::in | ios::out | ios::app);
	filetemp.open("Memberstemp.txt", ios::in | ios::out | ios::app);
	filetemp.setf(ios::left);
	while (file >> member.no >> member.name >> member.surname >> member.regisdate >> member.enddate)
	{
		if (no != member.no)
		{

			filetemp << setw(10) << member.no << setw(20) << member.name << setw(20) << member.surname << setw(20) <<
				member.regisdate << setw(20) << member.enddate << endl;
		}
		else
		{
			counter++;
		}
	}
	file.close();
	remove("Members.txt");
	filetemp.close();
	rename("Memberstemp.txt", "Members.txt");
	if (counter == 0)
	{
		gotoxy(40, 6 + (nom * 2) + 3);
		cout << red << "Kullan�c� Bulunamad�.  "; cout << white;
	}
	else
	{
		nom = nom - 1;
		system("CLS");
		MemberViews();
		gotoxy(47, 2);
		cout << "   KAYIT S�LME    ";
		gym.ShowMember();
		gotoxy(40, 6 + (nom * 2) + 3);
		cout << green << "    Kullan�c� Silindi.   "; cout << white;
	}

	gotoxy(1, (nom * 2) + 15);
	cout << "[1] �YE S�L";
	gotoxy(1, (nom * 2) + 17);
	cout << "[9] ANA MENU";
	gotoxy(1, (nom * 2) + 19);
	cout << "[X] �IKI�";
	gotoxy(1, (nom * 2) + 21);
	cout << "SE��M�N�Z : [ ]";
	gotoxy(14, (nom * 2) + 21);
	cin >> s;
	if (s == '1')
	{
		nomf();
		system("CLS");
		counter = 0; MemberDelete();
		if (nom != 0)
		{
			gym.ShowMember(); gym.DeleteMember();
		}
		else
		{
			Again();
		}
	}
	else if (s == '9')
	{
		system("CLS");
		MainMenu();
	}
	else if (s == 'X' || s == 'x')
	{
		exit(0);
	}
	else
	{
		cout << "Yanl�� Se�im Yapt�n�z.Ana Men�ye Y�nlendiriliyosunuz.";
		for (int i = 0; i < 3; i++)
		{
			Wait(1);
			cout << ".";
		}
		MainMenu();
	}


}

void nomf()
{
	nom = 0;
	fstream file;
	Member member;
	file.open("Members.txt", ios::in | ios::app);
	while (file >> member.no >> member.name >> member.surname >> member.regisdate >> member.enddate)
	{
		nom++;
	}
	file.close();
}


/*									Ekran Yaz�lar�

*/

//�mlecin Pozisyonunu De�i�tirme
void gotoxy(short x, short y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//Ba�l�k
void Title()
{

	for (int i = 0; i < 5; i++)
	{
		cout << setw(40);
		for (int j = 0; j < 17; j++)
		{
			if (i == 0 || j == 0 || i == 4)
			{
				cout << blue << "*";
			}
			if (i == 1 || i == 3)
			{
				if (j == 16)
					cout << setw(16) << "*";
			}


			if (i == 2 && j == 5)
			{
				cout << green << "Spor Salonu Otomasyonu" << setw(5) << blue << "*" << endl
					<< setw(40) << "*" << "       " << green << "Yazan:Taha Bugra Ak" << setw(6) << blue << "*";
				break;
			}
			else cout << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << white;
}
//�er�eve
void Frame(int x, int y)
{
	gotoxy(x, y);
	for (int i = 0; i < 27; i++)//�st yatay
	{
		gotoxy(1 + i, 8);
		cout << "-";
	}
	cout << MenuTitle;
	for (int i = 0; i < 28; i++)//�st yatay
	{
		gotoxy(32 + i, 8);
		cout << "-";
	}
	for (int i = 0; i < 15; i++)//sol dikey
	{
		gotoxy(0, 8 + i);
		cout << "|";
	}
	for (int i = 0; i < 60; i++)//�st yatay
	{
		gotoxy(1 + i, 9);
		cout << "=";
	}
	for (int i = 0; i < 15; i++)//sa� dikey
	{
		gotoxy(60, 8 + i);
		cout << "|";
	}
	for (int i = 0; i < 59; i++)//alt yatay
	{
		gotoxy(1 + i, 21);
		cout << "=";
	}
	for (int i = 0; i < 61; i++)//ek alt yatay
	{
		gotoxy(0 + i, 23);
		cout << "+";
	}
}
//Yeni �ye Ekleme Ekran�
void AddNewMember()
{
	void Wait(int wait);
	void MainMenu();
	MenuTitle = "YEN� KAYIT EKLEME";
	Title();
	Frame(22, 8);
	gotoxy(4, 11);
	cout << "YEN� �YE ADI     : ";
	gotoxy(4, 13);
	cout << "YEN� �YE SOYADI  : ";
	gotoxy(4, 15);
	cout << "BA�LANGI� TAR�H� : ";
	gotoxy(4, 17);
	cout << "B�T�� TAR�H�     : ";
	gotoxy(20, 22);

}
//�ye G�r�nt�leme
void MemberViews()
{
	for (int i = 0; i < 3; i++)
	{
		gotoxy(40, 1 + i);
		cout << "|";
		gotoxy(70, 1 + i);
		cout << "|";
	}
	for (int i = 0; i < 31; i++)
	{
		gotoxy(40 + i, 0);
		cout << "=";
		gotoxy(40 + i, 4);
		cout << "=";
	}
	gotoxy(47, 2);
	cout << "KAYIT G�R�NT�LEME";
	gotoxy(3, 6);
	cout << "NO";
	gotoxy(19, 6);
	cout << "ADI";
	gotoxy(42, 6);
	cout << "SOYADI";
	gotoxy(61, 6);
	cout << "BA�LANGI� TAR�H�";
	gotoxy(85, 6);
	cout << "B�T�� TAR�H�";
	for (int i = 0; i < 100; i++)
	{
		gotoxy(1 + i, 7);
		cout << "-";
	}

	if (nom > 0)
	{
		for (int i = 0; i < (nom * 2) + 4; i++)
		{
			gotoxy(0, 6 + i);
			cout << "|";

			gotoxy(100, 6 + i);
			cout << "|";
		}
		for (int i = 0; i < (nom * 2) + 3; i++)
		{
			gotoxy(8, 6 + i);
			cout << "|";
			gotoxy(32, 6 + i);
			cout << "|";
			gotoxy(56, 6 + i);
			cout << "|";
			gotoxy(80, 6 + (i));
			cout << "|";
		}

		for (int i = 0; i < 99; i++)
		{
			gotoxy(1 + i, 4 + (nom * 2) + 4);
			cout << "=";
		}

		for (int i = 0; i < 101; i++)
		{
			gotoxy(0 + i, 6 + ((nom * 2) + 4));
			cout << "+";
		}
		gotoxy(40, 6 + (nom * 2) + 3);
		cout << "G�r�nt�leme T�r� : T�M�";
	}
	else
	{
		gotoxy(40, 8);
		cout << red << "KULLANICI L�STES� BO�" << white;
	}




}
//�ye G�ncelleme
void MemberUpdate()
{
	MemberViews();
	gotoxy(47, 2);
	cout << "KAYIT G�NCELLEME";
	gotoxy(63, 2);
	cout << " ";
	if (nom != 0)
	{
		gotoxy(0, 8 + ((nom * 2) + 4));
		cout << "G�ncellemek �stedi�iniz �ye Numaras� : [  ]";
	}

}
//�ye Sil
void MemberDelete()
{
	MemberViews();
	gotoxy(47, 2);
	cout << "   KAYIT S�LME    ";
	if (nom != 0)
	{
		gotoxy(0, 8 + ((nom * 2) + 4));
		cout << "Silmek �stedi�iniz �ye Numaras� : [  ]";
	}


}
//ilk Menu Yaz�lar�
void Menu_Start()
{

	gotoxy(4, 11);
	cout << "[1] YEN� KAYIT EKLEME";
	gotoxy(4, 13);
	cout << "[2] KAYIT G�R�NT�LEME";
	gotoxy(4, 15);
	cout << "[3] KAYIT G�NCELLEME";
	gotoxy(4, 17);
	cout << "[4] KAYIT S�LME";
	gotoxy(4, 19);
	cout << "[X] PROGRAMDAN �IK";
	gotoxy(1, 25);
	cout << "Yapmak �stedi�iniz ��lemi Se�iniz : [ ]";
	gotoxy(38, 25);
}
//Bekletme Fonksiyonu
void Wait(int time)
{
	clock_t wait;
	wait = clock() + time * CLOCKS_PER_SEC;
	while (clock() < wait) {}
}
//Tekrar Fonksiyonu
void Again()
{
	void MainMenu();
	if (nom == 0)
	{
		gotoxy(1, (nom * 2) + 9);
		cout << "[9] ANA MENU";
		gotoxy(1, (nom * 2) + 11);
		cout << "[X] �IKI�";
		gotoxy(1, (nom * 2) + 13);
		cout << "SE��M�N�Z : [ ]";
		gotoxy(14, (nom * 2) + 13);
		cin >> s;
		if (s == '9')
		{
			system("CLS");
			MainMenu();
		}
		else if (s == 'X' || s == 'x')
		{
			exit(0);
		}
		else
		{
			cout << "Yanl�� Se�im Yapt�n�z.Ana Men�ye Y�nlendiriliyosunuz.";
			for (int i = 0; i < 3; i++)
			{
				Wait(1);
				cout << ".";
			}
			MainMenu();
		}
	}
	else
	{
		gotoxy(1, (nom * 2) + 15);
		cout << "[9] ANA MENU";
		gotoxy(1, (nom * 2) + 17);
		cout << "[X] �IKI�";
		gotoxy(1, (nom * 2) + 19);
		cout << "SE��M�N�Z : [ ]";
		gotoxy(14, (nom * 2) + 19);
		cin >> s;
		if (s == '9')
		{
			system("CLS");
			MainMenu();
		}
		else if (s == 'X' || s == 'x')
		{
			exit(0);
		}
		else
		{
			cout << "Yanl�� Se�im Yapt�n�z.Ana Men�ye Y�nlendiriliyosunuz.";
			for (int i = 0; i < 3; i++)
			{
				Wait(1);
				cout << ".";
			}
			MainMenu();
		}
	}
}
//Ana Menu
void MainMenu()
{
	system("CLS");
	char islem;

	Member member;
	Gym gym;
	do
	{
		nomf();
		MenuTitle = "MEN�";
		Title();
		Frame(28, 8);
		Menu_Start();
		cin >> islem;
		gotoxy(20, 22);
		switch (islem)
		{
		case '1':system("CLS"); AddNewMember(); gym.AddMember();           break;
		case '2':system("CLS"); MemberViews(); gym.ShowMember();  Again(); break;
		case '3':system("CLS"); counter = 0; MemberUpdate();
			if (nom != 0)
			{
				gym.ShowMember(); gym.UpdateMember();
			}
			else
			{
				Again();
			}

			break;
		case '4':system("CLS"); counter = 0; MemberDelete();
			if (nom != 0)
			{
				gym.ShowMember(); gym.DeleteMember();
			}
			else
			{
				Again();
			}



			break;
		case 'x': cout << "�IKI�"; exit(0); break;
		case 'X': cout << "�IKI�"; exit(0); break;
		default:cout << red << "Yanl�� Se�im Yapt�n�z"; cout << white; islem = 0; Wait(2); system("CLS");
			break;
		}
	} while (islem == 0);


}

int main()
{
	setlocale(LC_ALL, "Turkish");
	MainMenu();
	cout << endl << endl << endl;
	return 0;
}