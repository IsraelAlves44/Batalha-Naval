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
			cout << "Jogo iniciado";
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