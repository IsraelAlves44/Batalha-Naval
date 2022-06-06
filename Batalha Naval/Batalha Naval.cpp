// Batalha Naval.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <locale.h>


using namespace std;

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

void play() {
	char board[10][10], mask[10][10]{};
	int row{}, column{};
	int playedRow, playedColumn;
	int gameStatus = 1;

	startBoard(board, mask);

	while (gameStatus == 1)
	{
		screenCleaner();
		showBoard(board, mask);

		cout << "Digite uma linha: \n";
		cin >> playedRow;
		cout << "Digite uma coluna: \n"; 
		cin >> playedColumn;
		
		// Revela o que está no tabuleiro
		mask[playedRow][playedColumn] = board[playedRow][playedColumn];
	}
	
}

void initialMenu() 
{
	int option{};

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
			cout << "Jogo iniciado\n\n";
			play();
			break;
		case 2:
			cout << "Informações do jogo";
			break;;
		case 3:
			cout << "Até mais :)";
			break;
		default:
			cout << "Erro, nenhuma opção valida!";
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "pt_BR.UTF-8");
	
	initialMenu();

	

	

	return 0;
   
}