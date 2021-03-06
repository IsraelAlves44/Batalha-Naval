// Batalha Naval.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


using namespace std;

void play(string playersName);
void initialMenu();

void screenCleaner() {
	system("CLS");
}

void startBoard(char board[10][10],char mask[10][10]) {

	int row, column;

	for (row = 0; row < 10; row++)
	{
		for (column = 0; column < 10; column++)
		{
			board[row][column] = 'A';
			mask[row][column] = '*';
		}
	}
}

void showBoard(char board[10][10],char mask[10][10]) {
	
	int row, column;

	for (row = 0; row < 10; row++)
	{
		for (column = 0; column < 10; column++)
		{
			cout << " " << mask[row][column];
		}
		cout << "\n";
	}
}
void boatPosition(char board[10][10]) {
	
	int amount = 10, positionAmount = 0;

	while (positionAmount < amount)
	{
		int boatRowPosition = rand() % 10;
		int boatColumnPosition = rand() % 10;
		
		if (board[boatRowPosition][boatColumnPosition] == 'A') {
			board[boatRowPosition][boatColumnPosition] = 'p';
			positionAmount++;
		}
	}

}
void pointVerification(char board[10][10], int playedRow, int playedColumn, int *points, string *message) {

	switch (board[playedRow][playedColumn])
	{
	case 'p':
		*points += 10;
		*message = "Você acertou um barco!";
		break;
	case 'A':
		*message = "Você acertou a água!";
	default:
		break;
	}
}

void endFeedback(int option, string playersName){

	switch (option)
	{
	case 1:
		play(playersName);
		break;
	case 2:
		initialMenu();
		break;
	case 3:
		cout << "Até mais :)";
		break;
	default:
		break;
	}
}

void play(string playersName) {
	char board[10][10], mask[10][10]{};
	int row{}, column{};
	int playedRow, playedColumn;
	int gameStatus = 1;
	int points = 0;
	int attempts = 0, maximunAttempts = 5;
	int option = 0;
	string message = "Bem-vindo ao Jogo!"; //feedback para o jogador
	

	

	startBoard(board, mask);

	boatPosition(board);

	while (attempts < maximunAttempts)
	{
		
		showBoard(board, mask);

		cout << "\nPontos: " << points;
		cout << "\n" << message;
		cout << "\nTentativas Restantes: " << maximunAttempts - attempts;

		cout << "\n" << playersName << ", digite uma linha: ";
		cin >> playedRow;
		cout << "\n" << playersName << ", digite uma coluna: ";
		cin >> playedColumn;

	
		pointVerification(board, playedRow, playedColumn, &points, &message);
		

		// Revela o que está no tabuleiro
		mask[playedRow][playedColumn] = board[playedRow][playedColumn];

		attempts++;
		
	}
	cout << "Fim de jogo! O que deseja fazer?";
	cout << "\n1 - Jogar Novamente";
	cout << "\n2 - Ir para o Menu";
	cout << "\n3 - Sair";
	cout << "\nDigite a opção e aperte ENTER: ";
	cin >> option;

	endFeedback(option, playersName);

}

void initialMenu() 
{
	int option{};
	string playersName;

	while (option < 1 || option > 3) {

		screenCleaner();
		cout << "Bem-vindo ao jogo";
		cout << "\n1 - Jogar";
		cout << "\n2 - Sobre";
		cout << "\n3 - Sair";
		cout << "\nEscolha uma opção e tecle ENTER: ";
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "Digite seu nome: ";
			cin >> playersName;
			cout << "Jogo iniciado\n\n";
			play(playersName);
			break;
		case 2:
			cout << "Informações do jogo";
			break;;
		case 3:
			cout << "\nAté mais :)";
			break;
		default:
			cout << "Erro, nenhuma opção valida!";
			break;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	setlocale(LC_ALL, "pt_BR.UTF-8");
	
	initialMenu();

	return 0;
   
}