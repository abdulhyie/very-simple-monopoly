#include<iostream>
#include<iomanip>
#include<conio.h>
#include<string>
#include<windows.h>
#include<cstdlib>
#include<ctime>

using namespace std;

void playerNames();
void displayBoard();
void GamePlay();
void input();
void turnDecider();
void arrayClear();
void arrayRotate(char arr[], int size);

string name_1, name_2;
string property_name = "None";
bool turn;
int temp_1, temp_2, diceRoll, diceRoll_2;
int cash_1 = 1500, cash_2 = 1500, property_price, property_rent;
char mark_1[11][11], mark_2[11][11];
char isSold[11][11];
char chestCards[16] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P' };
char chanceCards[16] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P' };

int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);			//maximizes console window
	srand(time(0));
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
			isSold[i][j] = 'N';
		}
	}
	mark_1[0][0] = 'X';
	mark_2[0][0] = 'O';
	playerNames();
	while (1){
		displayBoard();
		arrayClear();
		input();
		system("cls");
		displayBoard();
		GamePlay();
		system("cls");
		if (turn == false){
			turn = true;
		}
		else{
			turn = false;
		}
		if(cash_1<=0){
			cout<<endl<<setw(70)<<name_2<<" Has Won the Monopoly."<<endl;
			return 0;
			system("pause>0");
		}
		else if(cash_2<=0){
			cout<<endl<<setw(70)<<name_1<<" Has Won the Monopoly."<<endl;
			return 0;
			system("pause>0");
		}
	}
	system("pause>0");
}

void playerNames()
{
	cout << setw(92) << "Welcome to MONOPOLY Game!" << endl;
	cout << setw(86) << ".::Made by::." << endl;
	cout << setw(85) << "Atika Farooq" << endl;
	cout << setw(84) << "Maida Akram" << endl;
	cout << setw(83) << "Abdul Hai" << endl;
	cout << endl << setw(87) << "Player {1} Name: ";
	getline(cin, name_1);
	cout << setw(87) << "Player {2} Name: ";
	getline(cin, name_2);
	system("cls");
	turnDecider();
}
void displayBoard()
{
	cout << "player1 " << name_1 << "ID" << "player2:" << name_2 << endl;
	if (turn == false)
		cout << name_1 << " turn" << endl;
	else
		cout << name_2 << " turn" << endl;
	for (int i = 0; i < 122; i++){
		cout << '_';
	}
	cout << endl;
	cout << "|          |          |          |          |          |          |          |          |          |          |          |" << setw(12) << name_1 << "'s Money:\t" << cash_1 << endl
		<< "| Go Start | Property |   Chest  | Property |    Tax   | Property | Property |  Chance? | Property | Property |Just Visit|" << setw(12) << name_2 << "'s Money:\t" << cash_2 << endl
		<< "|    200   |    220   |          |    220   |     80   |    220   |    220   |          |    220   |    220   |          |   ---------------------------- " << endl
		<< "|    " << mark_1[0][0] << mark_2[0][0] << "    |    " << mark_1[0][1] << mark_2[0][1] << "    |    " << mark_1[0][2] << mark_2[0][2]
		<< "    |    " << mark_1[0][3] << mark_2[0][3] << "    |    " << mark_1[0][4] << mark_2[0][4] << "    "
		<< "|    " << mark_1[0][5] << mark_2[0][5] << "    |    " << mark_1[0][6] << mark_2[0][6] << "    |    " << mark_1[0][7] << mark_2[0][7] << "    |    "
		<< mark_1[0][8] << mark_2[0][8] << "    |    " << mark_1[0][9] << mark_2[0][9] << "    |    " << mark_1[0][10] << mark_2[0][10] << "    |" << setw(21) << "Information" << endl
		<< "|__________|__________|__________|__________|__________|__________|__________|__________|__________|__________|__________|" << setw(13) << "Type: " << property_name << endl
		<< "|          |                                                                                                  |          |          " << endl
		<< "| Property |                                                                                                  | Property |" << endl
		<< "|    400   |                                                                                                  |    300   |" << setw(14) << "Price: " << property_price << endl
		<< "|    " << mark_1[1][0] << mark_2[1][0] << "    |                                                                                                  |    " << mark_1[1][10] << mark_2[1][10] << "    |" << endl
		<< "|__________|                                                                                                  |__________|" << endl
		<< "|          |                                                                                                  |          |" << setw(13) << "Rent: " << property_rent << endl
		<< "|    Tax   |                                                                                                  | Property |" << endl
		<< "|    120   |                                                                                                  |    300   |" << endl
		<< "|    " << mark_1[2][0] << mark_2[2][0] << "    |                                                                                                  |    " << mark_1[2][10] << mark_2[2][10] << "    |" << setw(15) << endl
		<< "|__________|                                                                                                  |__________|" << endl
		<< "|          |                                                                                                  |          |" << endl
		<< "| Property |                                                                                                  | Property |" << endl
		<< "|    400   |                                                                                                  |    300   |" << endl
		<< "|    " << mark_1[3][0] << mark_2[3][0] << "    |                                                                                                  |    " << mark_1[3][10] << mark_2[3][10] << "    |" << endl
		<< "|__________|                                                                                                  |__________|" << endl
		<< "|          |                                                                                                  |          |" << endl
		<< "|  Chance? |                                                                                                  | Property |" << endl
		<< "|          |                                                                                                  |    300   |" << endl
		<< "|    " << mark_1[4][0] << mark_2[4][0] << "    |                                                                                                  |    " << mark_1[4][10] << mark_2[4][10] << "    |" << endl
		<< "|__________|                                                                                                  |__________|" << endl
		<< "|          |                                                                                                  |          |" << endl
		<< "| Property |                                                                                                  | Property |" << endl
		<< "|    400   |                                                                                                  |    300   |" << endl
		<< "|    " << mark_1[5][0] << mark_2[5][0] << "    |                                                                                                  |    " << mark_1[5][10] << mark_2[5][10] << "    |" << endl
		<< "|__________|                                                                                                  |__________|" << endl
		<< "|          |                                                                                                  |          |" << endl
		<< "| Property |                                                                                                  | Property |" << endl
		<< "|    400   |                                                                                                  |    300   |" << endl
		<< "|    " << mark_1[6][0] << mark_2[6][0] << "    |                                                                                                  |    " << mark_1[6][10] << mark_2[6][10] << "    |" << endl
		<< "|__________|                                                                                                  |__________|" << endl
		<< "|          |                                                                                                  |          |" << endl
		<< "|  Chest   |                                                                                                  |   Chest  |" << endl
		<< "|          |                                                                                                  |          |" << endl
		<< "|    " << mark_1[7][0] << mark_2[7][0] << "    |                                                                                                  |    " << mark_1[7][10] << mark_2[7][10] << "    |" << endl
		<< "|__________|                                                                                                  |__________|" << endl
		<< "|          |                                                                                                  |          |" << endl
		<< "| Property |                                                                                                  | Property |" << endl
		<< "|    400   |                                                                                                  |    300   |" << endl
		<< "|    " << mark_1[8][0] << mark_2[8][0] << "    |                                                                                                  |    " << mark_1[8][10] << mark_2[8][10] << "    |" << endl
		<< "|__________|                                                                                                  |__________|" << endl
		<< "|          |                                                                                                  |          |" << endl
		<< "| Property |                                                                                                  | Property |" << endl
		<< "|    400   |                                                                                                  |    300   |" << endl
		<< "|    " << mark_1[9][0] << mark_2[9][0] << "    |                                                                                                  |    " << mark_1[9][10] << mark_2[9][10] << "    |" << endl
		<< "|__________|__________________________________________________________________________________________________|__________|" << endl
		<< "|          |          |          |          |          |          |          |          |          |          |          |" << endl
		<< "|Go to jail| Property | Property | Property | Property | Property | Property | Property |  Chance? | Property |F Parking |" << endl
		<< "|    50    |    180   |    180   |    180   |    180   |    180   |    180   |    180   |          |    180   |          |" << endl
		<< "|    " << mark_1[10][0] << mark_2[10][0] << "    |    " << mark_1[10][1] << mark_2[10][1] << "    |    " << mark_1[10][2] << mark_2[10][2] << "    |    " << mark_1[10][3] << mark_2[10][3] << "    |    " << mark_1[10][4] << mark_2[10][4] << "    "
		<< "|    " << mark_1[10][5] << mark_2[10][5] << "    |    " << mark_1[10][6] << mark_2[10][6] << "    |    " << mark_1[10][7] << mark_2[10][7] << "    |    " << mark_1[10][8] << mark_2[10][8] << "    |    " << mark_1[10][9] << mark_2[10][9] << "    |    " << mark_1[10][10] << mark_2[10][10] << "    |" << endl
		<< "|__________|__________|__________|__________|__________|__________|__________|__________|__________|__________|__________|" << endl;
}
void input()
{
	if (turn == false){
		cout << setw(65) << endl << "Enter any key: " << endl;
		_getch();
		diceRoll = rand() % 6 + 1;
		diceRoll_2 = rand() % 6 + 1;
		temp_1 += diceRoll + diceRoll_2;
		if (temp_1 <= 10){
			mark_1[0][temp_1] = 'X';
		}
		else if (temp_1 <= 20){
			mark_1[temp_1 - 10][10] = 'X';
		}
		else if (temp_1 <= 30){
			mark_1[10][10 - (temp_1 - 20)] = 'X';
		}
		else if (temp_1 <= 40){
			mark_1[10 - (temp_1 - 30)][0] = 'X';
		}
		else if (temp_1 <= 50){
			temp_1 = temp_1 - 40;
			mark_1[0][temp_1] = 'X';
		}
		else if (temp_1 <= 60){
			temp_1 = temp_1 - 50;
			mark_1[0][temp_1] = 'X';
		}
	}
	else{
		cout << setw(65) << endl << "Enter any key: " << endl;
		_getch();
		diceRoll = rand() % 6 + 1;
		diceRoll_2 = rand() % 6 + 1;
		temp_2 += diceRoll + diceRoll_2;
		if (temp_2 <= 10){
			mark_2[0][temp_2] = 'O';
		}
		else if (temp_2 <= 20){
			mark_2[temp_2 - 10][10] = 'O';
		}
		else if (temp_2 <= 30){
			mark_2[10][10 - (temp_2 - 20)] = 'O';
		}
		else if (temp_2 <= 40){
			mark_2[10 - (temp_2 - 30)][0] = 'O';
		}
		else if (temp_2 <= 50){
			temp_2 = temp_2 - 40;
			mark_2[0][temp_2] = 'O';
		}
		else if (temp_2 <= 60){
			temp_2 = temp_2 - 50;
			mark_2[0][temp_2] = 'O';
		}
	}
	if (turn == false){
		if (mark_1[0][1] == 'X' || mark_1[0][3] == 'X' || mark_1[0][5] == 'X' || mark_1[0][6] == 'X' || mark_1[0][8] == 'X' || mark_1[0][9] == 'X'){
			property_name = "Property";
			property_price = 220;
			property_rent = 40;
		}
		else if (mark_1[1][10] == 'X' || mark_1[2][10] == 'X' || mark_1[3][10] == 'X' || mark_1[4][10] == 'X' || mark_1[5][10] == 'X' || mark_1[6][10] == 'X' || mark_1[8][10] == 'X' || mark_1[9][10] == 'X'){
			property_name = "Property";
			property_price = 300;
			property_rent = 50;
		}
		else if (mark_1[10][1] == 'X' || mark_1[10][2] == 'X' || mark_1[10][3] == 'X' || mark_1[10][4] == 'X' || mark_1[10][5] == 'X' || mark_1[10][6] == 'X' || mark_1[10][7] == 'X' || mark_1[10][9] == 'X'){
			property_name = "Property";
			property_price = 180;
			property_rent = 30;
		}
		else if (mark_1[1][0] == 'X' || mark_1[1][0] == 'X' || mark_1[3][0] == 'X' || mark_1[3][0] == 'X' || mark_1[5][0] == 'X' || mark_1[5][0] == 'X' || mark_1[6][0] == 'X' || mark_1[6][0] == 'X' || mark_1[8][0] == 'X' || mark_1[8][0] == 'X' || mark_1[9][0] == 'X' || mark_1[9][0] == 'X'){
			property_name = "Property";
			property_price = 400;
			property_rent = 60;
		}
		else if (mark_1[0][2] == 'X' || mark_1[7][10] == 'X' || mark_1[7][0] == 'X'){
			property_name = "Chest";
			property_price = 0;
			property_rent = 0;
		}
		else if (mark_1[0][7] == 'X' || mark_1[10][8] == 'X' || mark_1[4][0] == 'X'){
			property_name = "Chance?";
			property_price = 0;
			property_rent = 0;
		}
		else if (mark_1[0][4] == 'X'){
			property_name = "Tax";
			property_price = 80;
			property_rent = 0;
		}
		else if (mark_1[2][0] == 'X'){
			property_name = "Tax";
			property_price = 120;
			property_rent = 0;
		}
		else if (mark_1[0][10] == 'X'){
			property_name = "Just Visit";
			property_price = 0;
			property_rent = 0;
		}
		else if (mark_1[10][10] == 'X'){
			property_name = "F Parking";
			property_price = 0;
			property_rent = 0;
		}
		else if (mark_1[10][0] == 'X'){
			property_name = "Go To Jail";
			property_price = 50;
			property_rent = 0;
		}
		else if (mark_1[0][0] == 'X'){
			property_name = "Go Start";
			property_price = 0;
			property_rent = 0;
		}
	}
	else{
		if (mark_2[0][1] == 'O' || mark_2[0][3] == 'O' || mark_2[0][5] == 'O' || mark_2[0][6] == 'O' || mark_2[0][8] == 'O' || mark_2[0][9] == 'O'){
			property_name = "Property";
			property_price = 220;
			property_rent = 40;
		}
		else if (mark_2[1][10] == 'O' || mark_2[2][10] == 'O' || mark_2[3][10] == 'O' || mark_2[4][10] == 'O' || mark_2[5][10] == 'O' || mark_2[6][10] == 'O' || mark_2[8][10] == 'O' || mark_2[9][10] == 'O'){
			property_name = "Property";
			property_price = 300;
			property_rent = 50;
		}
		else if (mark_2[10][1] == 'O' || mark_2[10][2] == 'O' || mark_2[10][3] == 'O' || mark_2[10][4] == 'O' || mark_2[10][5] == 'O' || mark_2[10][6] == 'O' || mark_2[10][7] == 'O' || mark_2[10][9] == 'O'){
			property_name = "Property";
			property_price = 180;
			property_rent = 30;
		}
		else if (mark_2[1][0] == 'O' || mark_2[1][0] == 'O' || mark_2[3][0] == 'O' || mark_2[3][0] == 'O' || mark_2[5][0] == 'O' || mark_2[5][0] == 'O' || mark_2[6][0] == 'O' || mark_2[6][0] == 'O' || mark_2[8][0] == 'O' || mark_2[8][0] == 'O' || mark_2[9][0] == 'O' || mark_2[9][0] == 'O'){
			property_name = "Property";
			property_price = 400;
			property_rent = 60;
		}
		else if (mark_2[0][2] == 'O' || mark_2[7][10] == 'O' || mark_2[7][0] == 'O'){
			property_name = "Chest";
			property_price = 0;
			property_rent = 0;
		}
		else if (mark_2[0][7] == 'O' || mark_2[10][8] == 'O' || mark_2[4][0] == 'O'){
			property_name = "Chance?";
			property_price = 0;
			property_rent = 0;
		}
		else if (mark_2[0][4] == 'O'){
			property_name = "Tax";
			property_price = 80;
			property_rent = 0;
		}
		else if (mark_2[2][0] == 'O'){
			property_name = "Tax";
			property_price = 120;
			property_rent = 0;
		}
		else if (mark_2[0][10] == 'O'){
			property_name = "Just Visit";
			property_price = 0;
			property_rent = 0;
		}
		else if (mark_2[10][10] == 'O'){
			property_name = "F Parking";
			property_price = 0;
			property_rent = 0;
		}
		else if (mark_2[10][0] == 'O'){
			property_name = "Go To Jail";
			property_price = 50;
			property_rent = 0;
		}
		else if (mark_2[0][0] == 'O'){
			property_name = "Go Start";
			property_price = 0;
			property_rent = 0;
		}
	}
}
void turnDecider()
{
	int dice_1, dice_2, sum_1, sum_2;
	check:
	cout << endl << setw(70) << name_1 << " Press any key to roll dice.";
	_getch();
	dice_1 = rand() % 6 + 1;
	dice_2 = rand() % 6 + 1;
	sum_1 = dice_1 + dice_2;
	cout << setw(75) << endl << "Dice 1: " << dice_1 << "\t\tDice_2: " << dice_2 << endl;
	cout << setw(70) << name_2 << " Press any key to roll dice.";
	_getch();
	dice_1 = rand() % 6 + 1;
	dice_2 = rand() % 6 + 1;
	sum_2 = dice_1 + dice_2;
	cout << setw(75) << endl << "Dice 1: " << dice_1 << "\t\tDice_2: " << dice_2 << endl;
	if (sum_1 > sum_2){
		cout << setw(75) << name_1 << " will go first." << endl;
		turn = false;
		Sleep(1500);
	}
	else if (sum_2 > sum_1){
		cout << setw(75) << name_2 << " will go first." << endl;
		turn = true;
		Sleep(1500);
	}
	else{
		cout << setw(70) << "Both Dices are equal. Roll again." << endl;
		Sleep(1500);
		goto check;
		system("cls");
	}
	system("cls");
}
void GamePlay()
{
	int opt;
	if (turn == false){
		if (property_name == "Property"){
			cout << endl << setw(75) << "Do you want to buy this property for " << property_price << "?" << endl;
			cout << setw(59) << "1 - Yes.\t\t\t2 - No.";
			cin >> opt;
			if (opt == 1){
				cash_1 -= property_price;
			}
		}
		else if (property_name == "Chest"){
			cout << endl << setw(70) << "You have a chest card. Press any key to pick a card." << endl;
			_getch();
			if (chestCards[0] == 'A'){
				cout << endl << setw(70) << "Advance to Go (Collect $200)" << endl;
				_getch();
				cash_1 += 200;
				arrayClear();
				temp_1 = 0;
				mark_1[0][0] = 'X';
			}
			else if (chestCards[0] == 'B'){
				cout << endl << setw(70) << "Bank error in your favor. Collect $200." << endl;
				_getch();
				cash_1 += 200;
			}
			else if (chestCards[0] == 'C'){
				cout << endl << setw(70) << "Doctor's fees. Pay $50." << endl;
				_getch();
				cash_1 -= 50;
			}
			else if (chestCards[0] == 'D'){
				cout << endl << setw(70) << "From sale of stock you get $50." << endl;
				_getch();
				cash_1 += 50;
			}
			else if (chestCards[0] == 'E'){
				cout << endl << setw(70) << "Get Out of Jail Free. This card may be kept until needed or sold/traded." << endl;
				_getch();
			}
			else if (chestCards[0] == 'F'){
				cout << endl << setw(70) << "Go to Jail. Go directly to jail. Do not pass Go, do not collect $200." << endl;
				_getch();
				arrayClear();
				temp_1 = 30;
				mark_1[10][0] = 'X';
			}
			else if (chestCards[0] == 'G'){
				cout << endl << setw(70) << "Grand Opera Night Collect $50 from every player for opening night seats. " << endl;
				_getch();
				cash_1 += 50;
			}
			else if (chestCards[0] == 'H'){
				cout << endl << setw(70) << "Holiday Fund matures. Receive $100." << endl;
				_getch();
				cash_1 += 100;
			}
			else if (chestCards[0] == 'I'){
				cout << endl << setw(70) << "Income tax refund. Collect $20." << endl;
				_getch();
				cash_1 += 20;
			}
			else if (chestCards[0] == 'J'){
				cout << endl << setw(70) << "It is your birthday. Collect $10 from every player" << endl;
				_getch();
				cash_1 += 10;
			}
			else if (chestCards[0] == 'K'){
				cout << endl << setw(70) << "Life insurance matures. Collect $100." << endl;
				_getch();
				cash_1 += 100;
			}
			else if (chestCards[0] == 'L'){
				cout << endl << setw(70) << "Hospital Fees. Pay $50." << endl;
				_getch();
				cash_1 -= 50;
			}
			else if (chestCards[0] == 'M'){
				cout << endl << setw(70) << "School fees. Pay $50." << endl;
				_getch();
				cash_1 -= 50;
			}
			else if (chestCards[0] == 'N'){
				cout << endl << setw(70) << "Receive $25 consultancy fee." << endl;
				_getch();
				cash_1 += 25;
			}
			else if (chestCards[0] == 'O'){
				cout << endl << setw(70) << "You inherit $100." << endl;
				_getch();
				cash_1 -= 100;
			}
			else if (chestCards[0] == 'P'){
				cout << endl << setw(70) << "You have won second prize in a beauty contest. Collect $10." << endl;
				_getch();
				cash_1 += 10;
			}
			arrayRotate(chestCards, 16);
		}
		else if (property_name == "Chance?"){
			cout << endl << setw(70) << "You have a chance card. Press any key to pick a card." << endl;
			_getch();
			if (chanceCards[0] == 'A'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_1[3][0] = 'X';
				temp_1 = 37;
			}
			else if (chanceCards[0] == 'B'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_1[3][0] = 'X';
				temp_1 = 37;
			}
			else if(chanceCards[0] == 'C'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_1[3][0] = 'X';
				temp_1 = 37;
			}
			else if (chanceCards[0] == 'D'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_1[3][0] = 'X';
				temp_1 = 37;
			}
			else if (chanceCards[0] == 'E'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_1[3][0] = 'X';
				temp_1 = 37;
			}
			else if (chanceCards[0] == 'F'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_1[3][0] = 'X';
				temp_1 = 37;
			}
			else if (chanceCards[0] == 'G'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_1[3][0] = 'X';
				temp_1 = 37;
			}
			else if (chestCards[0] == 'H'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_1[1][0] = 'X';
				temp_1 = 39;
			}
			else if (chanceCards[0] == 'I'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_1[1][0] = 'X';
				temp_1 = 39;
			}
			else if (chanceCards[0] == 'J'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_1[1][0] = 'X';
				temp_1 = 39;
			}
			else if (chanceCards[0] == 'K'){
				cout << endl << setw(50) << "Collect Free $200" << endl;
				_getch();
				cash_1 += 200;
			}
			else if (chanceCards[0] == 'L'){
				cout << endl << setw(50) << "Get $100 from every player." << endl;
				_getch();
				cash_1 += 100;
			}
			else if (chanceCards[0] == 'M'){
				cout << endl << setw(50) << "Pay $200 from Bank." << endl;
				_getch();
				cash_1 -= 200;
			}
			else if (chanceCards[0] == 'N'){
				cout << endl << setw(50) << "Advance to Go." << endl;
				_getch();
				arrayClear();
				cash_1 += 200;
				mark_1[0][0] = 'X';
				temp_1 = 0;
			}
			else if (chanceCards[0] == 'O'){
				cout << endl << setw(50) << "Move Farword 1 block." << endl;
				_getch();
				temp_1 += 1;
			}
			else if (chanceCards[0] == 'P'){
				cout << endl << setw(50) << "Move forward 5 block." << endl;
				_getch();
				temp_1 += 5;
			}
			arrayRotate(chanceCards, 16);
		}
		else if (property_name == "Tax"){
			cout << endl << setw(67) << "You have to pay " << property_price << " Tax." << endl;
			_getch();
			cash_1 -= property_price;
		}
		else if (property_name == "Go To Jail"){
			cout << endl << setw(73) << "You have been sent to jail. Pay 50 to get out?" << endl;
			_getch();
			cash_1 -= property_price;
		}
		else if (property_name == "Just Visit"){
			cout << endl << setw(75) << "Just Visit. Its really nice here." << endl;
			_getch();
		}
		else if (property_name == "F Parking"){
			cout << endl << setw(75) << "You can Park here for free." << endl;
			_getch();
		}
		else if (property_name == "Go Start"){
			cout << endl << setw(65) << "Start" << endl;
			_getch();
			cash_1 += 200;
		}
	}
	else{
		if (property_name == "Property"){
			cout << setw(75) << "Do you want to buy this property for " << property_price << "?" << endl;
			cout << setw(59) << "1 - Yes.\t\t\t2 - No.";
			cin >> opt;
			if (opt == 1){
				cash_2 -= property_price;
			}
		}
		else if (property_name == "Chest"){
			cout << endl << setw(70) << "You have a chance card. Press any key to pick a card." << endl;
			_getch();
			if (chestCards[0] == 'A'){
				cout << endl << setw(70) << "Advance to Go (Collect $200)" << endl;
				_getch();
				cash_2 += 200;
				arrayClear();
				temp_2 = 0;
				mark_2[0][0] = 'O';
			}
			else if (chestCards[0] == 'B'){
				cout << endl << setw(70) << "Bank error in your favor. Collect $200." << endl;
				_getch();
				cash_2 += 200;
			}
			else if (chestCards[0] == 'C'){
				cout << endl << setw(70) << "Doctor's fees. Pay $50." << endl;
				_getch();
				cash_2 -= 50;
			}
			else if (chestCards[0] == 'D'){
				cout << endl << setw(70) << "From sale of stock you get $50." << endl;
				_getch();
				cash_2 += 50;
			}
			else if (chestCards[0] == 'E'){
				cout << endl << setw(70) << "Get Out of Jail Free. This card may be kept until needed or sold/traded." << endl;
				_getch();
			}
			else if (chestCards[0] == 'F'){
				cout << endl << setw(70) << "Go to Jail. Go directly to jail. Do not pass Go, do not collect $200." << endl;
				_getch();
				arrayClear();
				temp_2 = 30;
				mark_2[10][0] = 'O';
			}
			else if (chestCards[0] == 'G'){
				cout << endl << setw(70) << "Grand Opera Night Collect $50 from every player for opening night seats. " << endl;
				_getch();
				cash_2 += 50;
			}
			else if (chestCards[0] == 'H'){
				cout << endl << setw(70) << "Holiday Fund matures. Receive $100." << endl;
				_getch();
				cash_2 += 100;
			}
			else if (chestCards[0] == 'I'){
				cout << endl << setw(70) << "Income tax refund. Collect $20." << endl;
				_getch();
				cash_2 += 20;
			}
			else if (chestCards[0] == 'J'){
				cout << endl << setw(70) << "It is your birthday. Collect $10 from every player" << endl;
				_getch();
				cash_2 += 10;
			}
			else if (chestCards[0] == 'K'){
				cout << endl << setw(70) << "Life insurance matures. Collect $100." << endl;
				_getch();
				cash_2 += 100;
			}
			else if (chestCards[0] == 'L'){
				cout << endl << setw(70) << "Hospital Fees. Pay $50." << endl;
				_getch();
				cash_2 -= 50;
			}
			else if (chestCards[0] == 'M'){
				cout << endl << setw(70) << "School fees. Pay $50." << endl;
				_getch();
				cash_2 -= 50;
			}
			else if (chestCards[0] == 'N'){
				cout << endl << setw(70) << "Receive $25 consultancy fee." << endl;
				_getch();
				cash_2 += 25;
			}
			else if (chestCards[0] == 'O'){
				cout << endl << setw(70) << "You inherit $100." << endl;
				_getch();
				cash_2 -= 100;
			}
			else if (chestCards[0] == 'P'){
				cout << endl << setw(70) << "You have won second prize in a beauty contest. Collect $10." << endl;
				_getch();
				cash_2 += 10;
			}
			arrayRotate(chestCards, 16);
		}
		else if (property_name == "Chance?"){
			cout << endl << setw(70) << "You have a chance card. Press any key to pick a card." << endl;
			_getch();
			if (chanceCards[0] == 'A'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_2[3][0] = 'O';
				temp_2 = 37;
			}
			else if (chanceCards[0] == 'B'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_2[3][0] = 'O';
				temp_2 = 37;
			}
			else if (chanceCards[0] == 'C'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_2[3][0] = 'O';
				temp_2 = 37;
			}
			else if (chanceCards[0] == 'D'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_2[3][0] = 'O';
				temp_2 = 37;
			}
			else if (chanceCards[0] == 'E'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_2[3][0] = 'O';
				temp_2 = 37;
			}
			else if (chanceCards[0] == 'F'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_2[3][0] = 'O';
				temp_2 = 37;
			}
			else if (chanceCards[0] == 'G'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_2[3][0] = 'O';
				temp_2 = 37;
			}
			else if (chestCards[0] == 'H'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_2[1][0] = 'O';
				temp_2 = 39;
			}
			else if (chanceCards[0] == 'I'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_2[1][0] = 'O';
				temp_2 = 39;
			}
			else if (chanceCards[0] == 'J'){
				cout << endl << setw(50) << "Free Space" << endl;
				_getch();
				arrayClear();
				mark_2[1][0] = '0';
				temp_2 = 39;
			}
			else if (chanceCards[0] == 'K'){
				cout << endl << setw(50) << "Collect Free $200" << endl;
				_getch();
				cash_2 += 200;
			}
			else if (chanceCards[0] == 'L'){
				cout << endl << setw(50) << "Get $100 from every player." << endl;
				_getch();
				cash_2 += 200;
			}
			else if (chanceCards[0] == 'M'){
				cout << endl << setw(50) << "Pay $200 from Bank." << endl;
				_getch();
				cash_2 -= 200;
			}
			else if (chanceCards[0] == 'N'){
				cout << endl << setw(50) << "Advance to Go." << endl;
				_getch();
				arrayClear();
				cash_2 += 200;
				mark_2[0][0] = '0';
				temp_2 = 0;
			}
			else if (chanceCards[0] == 'O'){
				cout << endl << setw(50) << "Move Farword 1 block." << endl;
				_getch();
				temp_2 += 1;
			}
			else if (chanceCards[0] == 'P'){
				cout << endl << setw(50) << "Move forward 5 block." << endl;
				_getch();
				temp_2 += 5;
			}
			arrayRotate(chanceCards, 16);
		}
		else if(property_name == "Tax"){
			cout << endl << setw(67) << "You have to pay " << property_price << " Tax." << endl;
			_getch();
			cash_2 -= property_price;
		}
		else if (property_name == "Go To Jail"){
			cout << endl << setw(73) << "You have been sent to jail. Pay 50 to get out?" << endl;
			_getch();
			cash_2 -= property_price;
		}
		else if (property_name == "Just Visit"){
			cout << endl << setw(75) << "Just Visit. Its really nice here." << endl;
			_getch();
		}
		else if (property_name == "F Parking"){
			cout << endl << setw(75) << "You can Park here for free." << endl;
			_getch();
		}
		else if (property_name == "Go Start"){
			cout << endl << setw(65) << "Start" << endl;
			_getch();
			cash_2 += 200;
		}
	}
}
void arrayClear()
{
	if (turn == false){
		for (int i = 0; i < 11; i++){
			for (int j = 0; j < 11; j++){
				mark_1[i][j] = ' ';
			}
		}
	}
	else{
		for (int i = 0; i < 11; i++){
			for (int j = 0; j < 11; j++){
				mark_2[i][j] = ' ';
			}
		}
	}
}
void arrayRotate(char arr[], int size)
{
	char temp;
	for
		(int i=0; i<size-1; i++) 
	{
		temp=arr[i];
		arr[i]= arr[i+1];
		arr[i+1]=temp;
	}
}
