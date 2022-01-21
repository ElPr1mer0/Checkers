#pragma once

namespace Checkers {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	bool turn = true; //помечаю ход, для того, чтобы можно было перенести шашку в другое место
	bool check_must_beat_checker = false; // использую для того, чтобы несколько раз не вызывать фун проверки на нужно ли бить
	bool change_picture_turn = true; // для смены картинки хода 
	int Pi, Pj; // нужно для проверки на то, если человек нажимает несколько раз на одну и ту же шашку для хода/отмены хода  + запоминаем координаты шашки
	bool beaten = false;  // проверка на то, побили ли шашку
	bool white = true; // сразу белые ходят, пробую для оптимизации хода в процедуре check_game_pole()
	
	class CHECKERS {
	public:
		void set_checker_data(int i, int j, int checker) {
			this->i = i;
			this->j = j;
			this->checker = checker;
		};
		int get_i() { return i; };
		int get_j() { return j; };
		int get_checker() { return checker; };
		bool active = false;
		bool beaten = false;
		bool can_turn = false;
	private:
		int i, j; // кординаты в массиве
		int checker; // 0-белая шашка, 1-черная шашка, 2-белая дамка, 3-черная дамка	
	};
	CHECKERS* checkers = new CHECKERS[24];

	public ref class MyForm1 : public System::Windows::Forms::Form
	{

		array <Button^, 2>^ game_pole = gcnew array <Button^, 2>(8, 8);		//создаю массив кнопок
		
		void game_start() {
			game_pole[0, 0] = but1;
			game_pole[1, 0] = but2;
			game_pole[2, 0] = but3;
			game_pole[3, 0] = but4;
			game_pole[4, 0] = but5;
			game_pole[5, 0] = but6;
			game_pole[6, 0] = but7;
			game_pole[7, 0] = but8;

			game_pole[0, 1] = but9;
			game_pole[1, 1] = but10;
			game_pole[2, 1] = but11;
			game_pole[3, 1] = but12;
			game_pole[4, 1] = but13;
			game_pole[5, 1] = but14;
			game_pole[6, 1] = but15;
			game_pole[7, 1] = but16;

			game_pole[0, 2] = but17;
			game_pole[1, 2] = but18;
			game_pole[2, 2] = but19;
			game_pole[3, 2] = but20;
			game_pole[4, 2] = but21;
			game_pole[5, 2] = but22;
			game_pole[6, 2] = but23;
			game_pole[7, 2] = but24;

			game_pole[0, 3] = but25;
			game_pole[1, 3] = but26;
			game_pole[2, 3] = but27;
			game_pole[3, 3] = but28;
			game_pole[4, 3] = but29;
			game_pole[5, 3] = but30;
			game_pole[6, 3] = but31;
			game_pole[7, 3] = but32;

			game_pole[0, 4] = but33;
			game_pole[1, 4] = but34;
			game_pole[2, 4] = but35;
			game_pole[3, 4] = but36;
			game_pole[4, 4] = but37;
			game_pole[5, 4] = but38;
			game_pole[6, 4] = but39;
			game_pole[7, 4] = but40;

			game_pole[0, 5] = but41;
			game_pole[1, 5] = but42;
			game_pole[2, 5] = but43;
			game_pole[3, 5] = but44;
			game_pole[4, 5] = but45;
			game_pole[5, 5] = but46;
			game_pole[6, 5] = but47;
			game_pole[7, 5] = but48;

			game_pole[0, 6] = but49;
			game_pole[1, 6] = but50;
			game_pole[2, 6] = but51;
			game_pole[3, 6] = but52;
			game_pole[4, 6] = but53;
			game_pole[5, 6] = but54;
			game_pole[6, 6] = but55;
			game_pole[7, 6] = but56;

			game_pole[0, 7] = but57;
			game_pole[1, 7] = but58;
			game_pole[2, 7] = but59;
			game_pole[3, 7] = but60;
			game_pole[4, 7] = but61;
			game_pole[5, 7] = but62;
			game_pole[6, 7] = but63;
			game_pole[7, 7] = but64;

			game_pole[1, 0]->Tag = "1";
			game_pole[3, 0]->Tag = "1";
			game_pole[5, 0]->Tag = "1";
			game_pole[7, 0]->Tag = "1";

			game_pole[0, 1]->Tag = "1";
			game_pole[2, 1]->Tag = "1";
			game_pole[4, 1]->Tag = "1";
			game_pole[6, 1]->Tag = "1";

			game_pole[1, 2]->Tag = "1";
			game_pole[3, 2]->Tag = "1";
			game_pole[5, 2]->Tag = "1";
			game_pole[7, 2]->Tag = "1";

			game_pole[0, 3]->Tag = "5";
			game_pole[2, 3]->Tag = "5";
			game_pole[4, 3]->Tag = "5";
			game_pole[6, 3]->Tag = "5";

			game_pole[1, 4]->Tag = "5";
			game_pole[3, 4]->Tag = "5";
			game_pole[5, 4]->Tag = "5";
			game_pole[7, 4]->Tag = "5";

			game_pole[0, 5]->Tag = "0";
			game_pole[2, 5]->Tag = "0";
			game_pole[4, 5]->Tag = "0";
			game_pole[6, 5]->Tag = "0";

			game_pole[1, 6]->Tag = "0";
			game_pole[3, 6]->Tag = "0";
			game_pole[5, 6]->Tag = "0";
			game_pole[7, 6]->Tag = "0";

			game_pole[0, 7]->Tag = "0";
			game_pole[2, 7]->Tag = "0";
			game_pole[4, 7]->Tag = "0";
			game_pole[6, 7]->Tag = "0";

			turn = true; //помечаю ход, для того, чтобы можно было перенести шашку в другое место
			check_must_beat_checker = false;
			change_picture_turn = true; // для смены картинки хода 
			beaten = false;
			white = true; 
			
			int k = 0;//счетчик для массива шашок
			for (int i = 0; i < 8; ++i) {
				for (int j = 0; j < 8; ++j) {
					// стартовые значения
					if (game_pole[j, i]->Tag == "1") {//  черная шашка
						checkers[k].set_checker_data(j, i, 1);
						checkers[k].can_turn = false;
						checkers[k].active = false;
						checkers[k].beaten = false;
						game_pole[j, i]->BackgroundImage = imageList1->Images[5]; 
						k++;
					}
					else if (game_pole[j, i]->Tag == "0") {//белая шашка
							checkers[k].set_checker_data(j, i, 0);
							checkers[k].can_turn = true;
							checkers[k].active = false;
							checkers[k].beaten = false;
							game_pole[j, i]->BackgroundImage = imageList1->Images[5];
							k++;
					}
				}
			}
			picture->Image = imageList1->Images[0]; // для иконки хода
			check_game_pole();
		}

		bool check_win() {
			int counter = 0;
			for (int i = 0; i < 24; i++) {
				if (checkers[i].can_turn) {
					if (checkers[i].beaten) {
						counter++;
					}
				}
			}
			if (counter == 12) return true;
			else return false;
		}
		
		void check_game_pole() { // проверка поля
			
				for (int i = 0; i < 8; ++i) {
					for (int j = 0; j < 8; ++j) {
						if (game_pole[j, i]->Tag == "1" ) {
							game_pole[j, i]->Image = imageList1->Images[1]; //черная шашка		//Tag нужен для того, чтобы клетки отличать
						}
						else if (game_pole[j, i]->Tag == "0" ) {
							game_pole[j, i]->Image = imageList1->Images[0]; //белая шашка
						}
						 else if (game_pole[j, i]->Tag == "5") { //пустое поле
							game_pole[j, i]->Image = imageList1->Images[5];
						}
						else if (game_pole[j, i]->Tag == "2" ) {
							game_pole[j, i]->Image = imageList1->Images[2]; // белая дамка
						}
						else if (game_pole[j, i]->Tag == "3") {
							game_pole[j, i]->Image = imageList1->Images[3]; // черная дамка
						}
					}
				}
		};

		void change_turn() {
			
			for (int i = 0; i < 24; i++) {
				if (checkers[i].can_turn) {
					checkers[i].can_turn = false;		
				}
				else{
					checkers[i].can_turn = true;
				}
			}
			if (change_picture_turn) {
				picture->Image = imageList1->Images[1];
				change_picture_turn = false;
				white = false;
			}
			else {
				picture->Image = imageList1->Images[0];
				change_picture_turn = true;
				white = true;
			}
		}

		bool can_beat_again(int x) {
			bool checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
			bool two_checkers = false;
			int l = Pj;  // для запоминания координат при битье дамкой
			int Pl, Pm; // запоминаю координаты дамки 
			if (!beaten) return false;
			switch (x){
			case 0:
				if (((Pj + 2 < 8) && (Pi - 2 > -1)) && ((game_pole[Pj + 1, Pi - 1]->Tag == "1")|| (game_pole[Pj + 1, Pi - 1]->Tag == "3")) && (game_pole[Pj + 2, Pi - 2]->Tag == "5") ||
					((Pj - 2 > -1) && (Pi - 2 > -1)) && ((game_pole[Pj - 1, Pi - 1]->Tag == "1") || (game_pole[Pj - 1, Pi - 1]->Tag == "3")) && (game_pole[Pj - 2, Pi - 2]->Tag == "5") ||
					((Pj - 2 > -1) && (Pi + 2 < 8)) && ((game_pole[Pj - 1, Pi + 1]->Tag == "1") || (game_pole[Pj - 1, Pi + 1]->Tag == "3")) && (game_pole[Pj - 2, Pi + 2]->Tag == "5") ||
					((Pj + 2 < 8) && (Pi + 2 < 8)) && ((game_pole[Pj + 1, Pi + 1]->Tag == "1") || (game_pole[Pj + 1, Pi + 1]->Tag == "3")) && (game_pole[Pj + 2, Pi + 2]->Tag == "5")) {
					return true;
				}
				break;
			case 1:
				if (((Pj + 2 < 8) && (Pi - 2 > -1)) && ((game_pole[Pj + 1, Pi - 1]->Tag == "0") || (game_pole[Pj + 1, Pi - 1]->Tag == "2")) && (game_pole[Pj + 2, Pi - 2]->Tag == "5") ||
					((Pj - 2 > -1) && (Pi - 2 > -1)) && ((game_pole[Pj - 1, Pi - 1]->Tag == "0") || (game_pole[Pj - 1, Pi - 1]->Tag == "2")) && (game_pole[Pj - 2, Pi - 2]->Tag == "5") ||
					((Pj - 2 > -1) && (Pi + 2 < 8)) && ((game_pole[Pj - 1, Pi + 1]->Tag == "0") || (game_pole[Pj - 1, Pi + 1]->Tag == "2")) && (game_pole[Pj - 2, Pi + 2]->Tag == "5") ||
					((Pj + 2 < 8) && (Pi + 2 < 8)) && ((game_pole[Pj + 1, Pi + 1]->Tag == "0") || (game_pole[Pj + 1, Pi + 1]->Tag == "2")) && (game_pole[Pj + 2, Pi + 2]->Tag == "5")) {
					return true;
				}
				break;
			case 2:
				l = Pj + 1;
				for (int m = Pi-1; m > -1; m--) {
					if (l > 7) { // чтобы не было выхода за границу массива
						break;
					}
					if ((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) {
						if (checker) {                       //здесь ищу первую шашку, которую мы бьем
							two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
						}
						else {
							Pl = l; //запоминаю эти координаты
							Pm = m;
							checker = true;
						}
					}
					if ((checker) && (game_pole[l, m]->Tag == "5")&&(!two_checkers)) {
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pl) && (checkers[k].get_j() == Pm)) { // если побили шашку, то находим ее и помечаем это
								return true;
							}
						}
					}				
					if (((game_pole[l, m]->Tag == "2") || (game_pole[l, m]->Tag == "0")) && (!checker)) break; // если нашли шашку/дамку нашей команды, то мы уже не можем бить в этом направлении
					l++; // тоже увеличиваю, чтобы искало по диагонале 			
				}
				
				two_checkers = false;
				l = Pj - 1;
				checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
						//влево вверх
				for (int m = Pi-1; m > -1; m--) {
					if (l < 0) { // чтобы не было выхода за границу массива
						break;
					}
					if ((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) {
						if (checker) {                       //здесь ищу первую шашку, которую мы бьем
							two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
						}
						else {
							Pl = l; //запоминаю эти координаты
							Pm = m;
							checker = true;
						}
						
					}
					if ((checker) && (game_pole[l, m]->Tag == "5") && (!two_checkers)) {
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pl) && (checkers[k].get_j() == Pm)) {
								return true;
							}
						}
					}
					if (((game_pole[l, m]->Tag == "2") || (game_pole[l, m]->Tag == "0")) && (!checker)) break;
					l--; // тоже увеличиваю, чтобы искало по диагонале 				
				}

				two_checkers = false;
				l = Pj - 1;
				checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
						//влево вниз 
				for (int m = Pi+1; m < 8; m++) {
					if (l < 0) { // чтобы не было выхода за границу массива
						break;
					}
					if ((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) {
						if (checker) {                       //здесь ищу первую шашку, которую мы бьем
							two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
						}
						else {
							Pl = l; //запоминаю эти координаты
							Pm = m;
							checker = true;
						}
					}
					if ((checker) && (game_pole[l, m]->Tag == "5") && (!two_checkers)) {
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pl) && (checkers[k].get_j() == Pm)) {
								return true;
							}
						}
					}
					if (((game_pole[l, m]->Tag == "2") || (game_pole[l, m]->Tag == "0")) && (!checker)) break;
					l--; // тоже увеличиваю, чтобы искало по диагонале 				
				}

				two_checkers = false;
				l = Pj + 1;
				checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
						//вправо вниз 
				for (int m = Pi+1; m < 8; m++) {
					if (l > 7) { // чтобы не было выхода за границу массива
						break;
					}
					if ((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) {						 
						if (checker) {                       //здесь ищу первую шашку, которую мы бьем
							two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
						}
						else {
							Pl = l; //запоминаю эти координаты
							Pm = m;
							checker = true;
						}
					}
					if ((checker) && (game_pole[l, m]->Tag == "5") && (!two_checkers)) {
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pl) && (checkers[k].get_j() == Pm)) {
								return true;
							}
						}
					}
					if (((game_pole[l, m]->Tag == "2") || (game_pole[l, m]->Tag == "0")) && (!checker)) break;
					l++; // тоже увеличиваю, чтобы искало по диагонале 				
				}
				break;
			case 3:
				l = Pj + 1;
				for (int m = Pi-1; m > -1; m--) {
					if (l > 7) { // чтобы не было выхода за границу массива
						break;
					}
					if ((game_pole[l, m]->Tag == "0") || (game_pole[l, m]->Tag == "2")) {
						if (checker) {                       //здесь ищу первую шашку, которую мы бьем
							two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
						}
						else {
							Pl = l; //запоминаю эти координаты
							Pm = m;
							checker = true;
						}
					}
					if ((checker) && (game_pole[l, m]->Tag == "5") && (!two_checkers)) {
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pl) && (checkers[k].get_j() == Pm)) { // если побили шашку, то находим ее и помечаем это
								return true;
							}
						}
					}
					if (((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) && (!checker)) break;
					l++; // тоже увеличиваю, чтобы искало по диагонале 			
				}

				two_checkers = false;
				l = Pj - 1;
				checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
						//влево вверх
				for (int m = Pi-1; m > -1; m--) {
					if (l < 0) { // чтобы не было выхода за границу массива
						break;
					}
					if ((game_pole[l, m]->Tag == "0") || (game_pole[l, m]->Tag == "2")) {
						if (checker) {                       //здесь ищу первую шашку, которую мы бьем
							two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
						}
						else {
							Pl = l; //запоминаю эти координаты
							Pm = m;
							checker = true;
						}

					}
					if ((checker) && (game_pole[l, m]->Tag == "5") && (!two_checkers)) {
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pl) && (checkers[k].get_j() == Pm)) {
								return true;
							}
						}
					}
					if (((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) && (!checker)) break;
					l--; // тоже увеличиваю, чтобы искало по диагонале 					
				}
				
				two_checkers = false;
				l = Pj - 1;
				checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
						//влево вниз 
				for (int m = Pi+1; m < 8; m++) {
					if (l < 0) { // чтобы не было выхода за границу массива
						break;
					}
					if ((game_pole[l, m]->Tag == "0") || (game_pole[l, m]->Tag == "2")) {
						if (checker) {                       //здесь ищу первую шашку, которую мы бьем
							two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
						}
						else {
							Pl = l; //запоминаю эти координаты
							Pm = m;
							checker = true;
						}
					}
					if ((checker) && (game_pole[l, m]->Tag == "5") && (!two_checkers)) {
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pl) && (checkers[k].get_j() == Pm)) {
								return true;
							}
						}
					}
					if (((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) && (!checker)) break;
					l--; // тоже увеличиваю, чтобы искало по диагонале 				
				}

				two_checkers = false;
				l = Pj + 1;
				checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
						//вправо вниз 
				for (int m = Pi + 1; m < 8; m++) {
					if (l > 7) { // чтобы не было выхода за границу массива
						break;
					}
					if ((game_pole[l, m]->Tag == "0") || (game_pole[l, m]->Tag == "2")) {
						if (checker) {                       //здесь ищу первую шашку, которую мы бьем
							two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
						}
						else {
							Pl = l; //запоминаю эти координаты
							Pm = m;
							checker = true;
						}
					}
					if ((checker) && (game_pole[l, m]->Tag == "5") && (!two_checkers)) {
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pl) && (checkers[k].get_j() == Pm)) {
								return true;
							}
						}
					}
					if (((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) && (!checker)) break;
					l++; // тоже увеличиваю, чтобы искало по диагонале 					
				}
				break;
			}	
			return false;
		} 

		bool must_beat(int x, int i, int j) {//принимает шашку, её координаты из массива (i,j)
			bool checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
			bool two_checkers = false;
			bool pusto = false; // для обычного хода дамки
			int l = Pj;  // для запоминания координат при битье дамкой
			int Pl, Pm; // запоминаю координаты дамки 
			switch (x) {
			case 0:// белая шашка
				if (check_must_beat_checker) {
					if (((j == Pj + 2) && (i == Pi - 2)) && ((game_pole[Pj + 1, Pi - 1]->Tag == "1")|| (game_pole[Pj + 1, Pi - 1]->Tag == "3"))) { // если можно, то ок, иначе выходим из функции
						game_pole[Pj + 1, Pi - 1]->Tag = "5";
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pj + 1) && (checkers[k].get_j() == Pi - 1)) {
								checkers[k].beaten = true;
							}
						}
						beaten = true;
						return true;
					}
					else if (((j == Pj - 2) && (i == Pi - 2)) && ((game_pole[Pj - 1, Pi - 1]->Tag == "1")||(game_pole[Pj - 1, Pi - 1]->Tag == "3"))) { // где -+2 это через клетку, а где -+1 это сл клетка
						game_pole[Pj - 1, Pi - 1]->Tag = "5";
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pj - 1) && (checkers[k].get_j() == Pi - 1)) {
								checkers[k].beaten = true;
							}
						}
						beaten = true;
						return true;
					}
					else if (((j == Pj - 2) && (i == Pi + 2)) && ((game_pole[Pj - 1, Pi + 1]->Tag == "1")|| (game_pole[Pj - 1, Pi + 1]->Tag == "3"))) {
						game_pole[Pj - 1, Pi + 1]->Tag = "5";
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pj - 1) && (checkers[k].get_j() == Pi + 1)) {
								checkers[k].beaten = true;
							}
						}
						beaten = true;
						return true;
					}
					else if (((j == Pj + 2) && (i == Pi + 2)) && ((game_pole[Pj + 1, Pi + 1]->Tag == "1")|| (game_pole[Pj + 1, Pi + 1]->Tag == "3"))) {
						game_pole[Pj + 1, Pi + 1]->Tag = "5";
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pj + 1) && (checkers[k].get_j() == Pi + 1)) {
								checkers[k].beaten = true;
							}
						}
						beaten = true;
						return true;
					}
					else return false;
				}
				else if (((j == Pj - 1) && (i == Pi - 1)) || ((j == Pj + 1) && (i == Pi - 1))) {// для обычного хода если бить не надо
					return true;
				}						
				else{
					return false;
				}
				break;
			case 1://черная шашка
				if (check_must_beat_checker) {
					if (((j == Pj + 2) && (i == Pi - 2)) && ((game_pole[Pj + 1, Pi - 1]->Tag == "0")|| (game_pole[Pj + 1, Pi - 1]->Tag == "2"))) { // если можно, то ок, иначе выходим из функции
						game_pole[Pj + 1, Pi - 1]->Tag = "5";
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pj + 1) && (checkers[k].get_j() == Pi - 1)) {
								checkers[k].beaten = true;
							}
						}
						beaten = true;
						return true;
					}
					else if (((j == Pj - 2) && (i == Pi - 2)) && ((game_pole[Pj - 1, Pi - 1]->Tag == "0")|| (game_pole[Pj - 1, Pi - 1]->Tag == "2"))) { // где -+2 это через клетку, а где -+1 это сл клетка
						game_pole[Pj - 1, Pi - 1]->Tag = "5";
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pj - 1) && (checkers[k].get_j() == Pi - 1)) {
								checkers[k].beaten = true;
							}
						}
						beaten = true;
						return true;
					}
					else if (((j == Pj - 2) && (i == Pi + 2)) && ((game_pole[Pj - 1, Pi + 1]->Tag == "0")|| (game_pole[Pj - 1, Pi + 1]->Tag == "2"))) {
						game_pole[Pj - 1, Pi + 1]->Tag = "5";
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pj -1) && (checkers[k].get_j() == Pi + 1)) {
								checkers[k].beaten = true;
							}
						}
						beaten = true;
						return true;
					}
					else if (((j == Pj + 2) && (i == Pi + 2)) && ((game_pole[Pj + 1, Pi + 1]->Tag == "0")|| (game_pole[Pj + 1, Pi + 1]->Tag == "2"))) {
						game_pole[Pj + 1, Pi + 1]->Tag = "5";
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pj + 1) && (checkers[k].get_j() == Pi + 1)) {
								checkers[k].beaten = true;
							}
						}
						beaten = true;
						return true;
					}
					else return false; //если нужно бить, а человек не бьет, то возвращаем, так как обязательно нужно бить
				}
				else if (((j == Pj - 1) && (i == Pi + 1)) || ((j == Pj + 1) && (i == Pi + 1))) {
					return true;
				}
				else {
					return false;
				}
				break;

			case 2:// белая дамка		 
				//вправо вверх 				
				l = Pj + 1;
				for (int m = Pi - 1; m > -1; m--) {
					if (l > 7) { // чтобы не было выхода за границу массива
						break;
					}
					if ((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) {
						if (checker) {                       //здесь ищу первую шашку, которую мы бьем
							two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
						}
						else {
							Pl = l; //запоминаю эти координаты, чтобы потом шашку убрать с поля
							Pm = m;
							checker = true;
						}
					}
					else if ((game_pole[l, m]->Tag == "5")&&(j==l)&&(i==m)) {
						pusto = true;
					}
					if ((checker) && (game_pole[l, m]->Tag == "5") && (j == l) && (i == m)&&(!two_checkers)) {
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pl) && (checkers[k].get_j() == Pm)) { // если побили шашку, то находим ее и помечаем это
								game_pole[Pl, Pm]->Tag = "5";
								checkers[k].beaten = true;
								beaten = true;
								return true;	
							}
						}	
					}
					if ((pusto) && (!checker) && (!check_must_beat_checker)) { // для обычного хода
						return true;
					}
					if (((game_pole[l, m]->Tag == "2") || (game_pole[l, m]->Tag == "0")) && (!checker)) break;
					l++; // тоже увеличиваю, чтобы искало по диагонале 
					
				}
				
				two_checkers = false;
				pusto = false;
				l = Pj - 1;
				checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
						//влево вверх
				for (int m = Pi - 1; m > -1; m--) {
					if (l < 0) { // чтобы не было выхода за границу массива
						break;
					}
					if ((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) {
						if (checker) {
							two_checkers = true;
						}
						else {
							Pl = l; //запоминаю эти координаты, чтобы потом шашку убрать с поля
							Pm = m;
							checker = true;
						}
					}
					else if ((game_pole[l, m]->Tag == "5") && (j == l) && (i == m)) {
						pusto = true;
					}
					if ((checker) && (game_pole[l, m]->Tag == "5") && (j == l) && (i == m) && (!two_checkers)) {
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pl) && (checkers[k].get_j() == Pm)) {
								checkers[k].beaten = true;
								game_pole[Pl, Pm]->Tag = "5";
								beaten = true;
								return true;
							}
						}
					}
					if ((pusto) && (!checker)&&(!check_must_beat_checker)) {  // для обычного хода, если бить не надо
						return true;
					}
					if (((game_pole[l, m]->Tag == "2") || (game_pole[l, m]->Tag == "0")) && (!checker)) break;
					l--; // тоже увеличиваю, чтобы искало по диагонале 			
				}
				
				two_checkers = false;
				pusto = false;
				l = Pj - 1;
				checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
						//влево вниз 
				for (int m = Pi+1; m <8; m++) {
					if (l < 0) { // чтобы не было выхода за границу массива
						break;
					}
					if ((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) {
						if (checker) {
							two_checkers = true;
						}
						else {
							Pl = l; //запоминаю эти координаты, чтобы потом шашку убрать с поля
							Pm = m;
							checker = true;
						}
					}
					else if ((game_pole[l, m]->Tag == "5") && (j == l) && (i == m)) {
						pusto = true;
					}
					if ((checker) && (game_pole[l, m]->Tag == "5") && (j == l) && (i == m) && (!two_checkers)) {
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pl) && (checkers[k].get_j() == Pm)) {
								checkers[k].beaten = true;
								game_pole[Pl, Pm]->Tag = "5";
								beaten = true;
								return true;
							}
						}						
					}
					if ((pusto) && (!checker) && (!check_must_beat_checker)) {
						return true;
					}
					if (((game_pole[l, m]->Tag == "2") || (game_pole[l, m]->Tag == "0")) && (!checker)) break;
					l--; // тоже увеличиваю, чтобы искало по диагонале 			
				}

				two_checkers = false;
				pusto = false;
				l = Pj + 1;
				checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
						//вправо вниз 
				for (int m = Pi + 1; m < 8; m++) {
					if (l > 7) { // чтобы не было выхода за границу массива
						break;
					}
					if ((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) {
						if (checker) {
							two_checkers = true;
						}
						else {
							Pl = l; //запоминаю эти координаты, чтобы потом шашку убрать с поля
							Pm = m;
							checker = true;
						}
					}
					else if ((game_pole[l, m]->Tag == "5") && (j == l) && (i == m)) {
						pusto = true;
					}
					if ((checker) && (game_pole[l, m]->Tag == "5") && (j == l) && (i == m) && (!two_checkers)) {
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pl) && (checkers[k].get_j() == Pm)) {
								checkers[k].beaten = true;
								game_pole[Pl, Pm]->Tag = "5";
								beaten = true;
								return true;
							}
						}
					}
					if ((pusto) && (!checker) && (!check_must_beat_checker)) {
						return true;
					}
					if (((game_pole[l, m]->Tag == "2") || (game_pole[l, m]->Tag == "0")) && (!checker)) break;
					l++; // тоже увеличиваю, чтобы искало по диагонале 					
				}
				break;
			case 3: // черная дамка
				//вправо вверх 				
				l = Pj + 1;
				for (int m = Pi - 1; m > -1; m--) {
					if (l > 7) { // чтобы не было выхода за границу массива
						break;
					}
					if ((game_pole[l, m]->Tag == "0") || (game_pole[l, m]->Tag == "2")) {
						if (checker) {
							two_checkers = true;
						}
						else {
							Pl = l; //запоминаю эти координаты, чтобы потом шашку убрать с поля
							Pm = m;
							checker = true;
						}
					}
					else if ((game_pole[l, m]->Tag == "5") && (j == l) && (i == m)) {
						pusto = true;
					}
					if ((checker) && (game_pole[l, m]->Tag == "5") && (j == l) && (i == m) && (!two_checkers)) {
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pl) && (checkers[k].get_j() == Pm)) { // если побили шашку, то находим ее и помечаем это
								game_pole[Pl, Pm]->Tag = "5";
								checkers[k].beaten = true;
								beaten = true;
								return true;
							}
						}
					}
					if ((pusto) && (!checker) && (!check_must_beat_checker)) {
						return true;
					}
					if (((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) && (!checker)) break;
					l++; // тоже увеличиваю, чтобы искало по диагонале 				
				}

				two_checkers = false;
				pusto = false;
				l = Pj - 1;
				checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
						//влево вверх
				for (int m = Pi - 1; m > -1; m--) {
					if (l < 0) { // чтобы не было выхода за границу массива
						break;
					}
					if ((game_pole[l, m]->Tag == "0") || (game_pole[l, m]->Tag == "2")) {
						if (checker) {
							two_checkers = true;
						}
						else {
							Pl = l; //запоминаю эти координаты, чтобы потом шашку убрать с поля
							Pm = m;
							checker = true;
						}
					}
					else if ((game_pole[l, m]->Tag == "5") && (j == l) && (i == m)) {
						pusto = true;
					}
					if ((checker) && (game_pole[l, m]->Tag == "5") && (j == l) && (i == m) && (!two_checkers)) {
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pl) && (checkers[k].get_j() == Pm)) {
								checkers[k].beaten = true;
								game_pole[Pl, Pm]->Tag = "5";
								beaten = true;
								return true;
							}
						}
					}
					if ((pusto) && (!checker) && (!check_must_beat_checker)) {
						return true;
					}
					if (((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) && (!checker)) break;
					l--; // тоже увеличиваю, чтобы искало по диагонале					
				}
				
				two_checkers = false;
				pusto = false;
				l = Pj - 1;
				checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
						//влево вниз 
				for (int m = Pi + 1; m < 8; m++) {
					if (l < 0) { // чтобы не было выхода за границу массива
						break;
					}
					if ((game_pole[l, m]->Tag == "0") || (game_pole[l, m]->Tag == "2")) {
						if (checker) {
							two_checkers = true;
						}
						else {
							Pl = l; //запоминаю эти координаты, чтобы потом шашку убрать с поля
							Pm = m;
							checker = true;
						}
					}
					else if ((game_pole[l, m]->Tag == "5") && (j == l) && (i == m)) {
						pusto = true;
					}
					if ((checker) && (game_pole[l, m]->Tag == "5") && (j == l) && (i == m) && (!two_checkers)) {
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pl) && (checkers[k].get_j() == Pm)) {
								checkers[k].beaten = true;
								game_pole[Pl, Pm]->Tag = "5";
								beaten = true;
								return true;
							}
						}
					}
					if ((pusto) && (!checker) && (!check_must_beat_checker)) {
						return true;
					}
					if (((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) && (!checker)) break;
					l--; // тоже увеличиваю, чтобы искало по диагонале 			
				}
				
				two_checkers = false;
				pusto = false;
				l = Pj + 1;
				checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
						//вправо вниз 
				for (int m = Pi + 1; m < 8; m++) {
					if (l > 7) { // чтобы не было выхода за границу массива
						break;
					}
					if ((game_pole[l, m]->Tag == "0") || (game_pole[l, m]->Tag == "2")) {
						if (checker) {
							two_checkers = true;
						}
						else {
							Pl = l; //запоминаю эти координаты, чтобы потом шашку убрать с поля
							Pm = m;
							checker = true;
						}
					}
					else if ((game_pole[l, m]->Tag == "5") && (j == l) && (i == m)) {
						pusto = true;
					}
					if ((checker) && (game_pole[l, m]->Tag == "5") && (j == l) && (i == m) && (!two_checkers)) {
						for (int k = 0; k < 24; k++) {
							if ((checkers[k].get_i() == Pl) && (checkers[k].get_j() == Pm)) {
								checkers[k].beaten = true;
								game_pole[Pl, Pm]->Tag = "5";
								beaten = true;
								return true;
							}
						}
					}
					if ((pusto) && (!checker) && (!check_must_beat_checker)) {
						return true;
					}
					if (((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) && (!checker)) break;
					l++; // тоже увеличиваю, чтобы искало по диагонале 				
				}
				break;
			}

		}

		bool check_must_beat() {
			bool can_beat = false;
			bool checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
			bool two_checkers = false;
			int l = Pj;  // для запоминания координат при битье дамкой
			int Pl, Pm; // запоминаю координаты дамки 
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					for (int k = 0; k < 24; k++) {
						if ((checkers[k].get_i() == j) && (checkers[k].get_j() == i) && (checkers[k].can_turn)&&(!checkers[k].beaten)) {
							int l = j;  // для запоминания координат при битье дамкой
							switch (checkers[k].get_checker()) {	
							case 0:
								if (((j + 2 < 8) && (i - 2 > -1)) && ((game_pole[j + 1, i - 1]->Tag == "1")|| (game_pole[j + 1, i - 1]->Tag == "3")) && (game_pole[j + 2, i - 2]->Tag == "5") ||
									((j - 2 > -1) && (i - 2 > -1)) && ((game_pole[j - 1, i - 1]->Tag == "1") || (game_pole[j - 1, i - 1]->Tag == "3")) && (game_pole[j - 2, i - 2]->Tag == "5") ||
									((j - 2 > -1) && (i + 2 < 8)) && ((game_pole[j - 1, i + 1]->Tag == "1") || (game_pole[j - 1, i + 1]->Tag == "3")) && (game_pole[j - 2, i + 2]->Tag == "5") ||
									((j + 2 < 8) && (i + 2 < 8)) && ((game_pole[j + 1, i + 1]->Tag == "1") || (game_pole[j + 1, i + 1]->Tag == "3")) && (game_pole[j + 2, i + 2]->Tag == "5")) {
									game_pole[j, i]->BackgroundImage = imageList1->Images[6];
									checkers[k].active = true;
									can_beat = true;
								}
								break;
							case 1:
								if (((j + 2 < 8) && (i - 2 > -1)) && ((game_pole[j + 1, i - 1]->Tag == "0") || (game_pole[j + 1, i - 1]->Tag == "2")) && (game_pole[j + 2, i - 2]->Tag == "5") ||
									((j - 2 > -1) && (i - 2 > -1)) && ((game_pole[j - 1, i - 1]->Tag == "0") || (game_pole[j - 1, i - 1]->Tag == "2")) && (game_pole[j - 2, i - 2]->Tag == "5") ||
									((j - 2 > -1) && (i + 2 < 8)) && ((game_pole[j - 1, i + 1]->Tag == "0") || (game_pole[j - 1, i + 1]->Tag == "2")) && (game_pole[j - 2, i + 2]->Tag == "5") ||
									((j + 2 < 8) && (i + 2 < 8)) && ((game_pole[j + 1, i + 1]->Tag == "0") || (game_pole[j + 1, i + 1]->Tag == "2")) && (game_pole[j + 2, i + 2]->Tag == "5")) {
									checkers[k].active = true;
									game_pole[j, i]->BackgroundImage = imageList1->Images[6];
									can_beat = true;
								}
								break;
							case 2:								
								l = j + 1;  // чтобы сразу пропускать тек шашку и переходить к след
								for (int m = i - 1; m > -1; m--) {
									if (l > 7) { // чтобы не было выхода за границу массива
										break;
									}
									if ((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) {
										if (checker) {                       //здесь ищу первую шашку, которую мы бьем
											two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
										}
										else {
											Pl = l; //запоминаю эти координаты
											Pm = m;
											checker = true;
										}
									}
									
									if (((Pl+1<8)&&(Pm-1>-1))&&(checker) && (game_pole[Pl+1, Pm-1]->Tag == "5")&&(!two_checkers)) {
										for (int k = 0; k < 24; k++) {
											if ((checkers[k].get_i() == j) && (checkers[k].get_j() == i)) { // если побили шашку, то находим ее и помечаем это
												game_pole[j, i]->BackgroundImage = imageList1->Images[6];
												checkers[k].active = true;
												can_beat = true;
											}
										}
									}
									if (((game_pole[l, m]->Tag == "0") || (game_pole[l, m]->Tag == "2")) && (!checker)) break;
									l++; // тоже увеличиваю, чтобы искало по диагонале 									
								}

								l = j - 1;
								two_checkers = false;
								checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
										//влево вверх
								for (int m = i - 1; m > -1; m--) {
									if (l < 0) { // чтобы не было выхода за границу массива
										break;
									}
									if ((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) {
										if (checker) {                       //здесь ищу первую шашку, которую мы бьем
											two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
										}
										else {
											Pl = l; //запоминаю эти координаты
											Pm = m;
											checker = true;
										}
									}
									if (((Pl - 1 > -1) && (Pm - 1 > -1)) && (checker) && (game_pole[Pl - 1, Pm - 1]->Tag == "5") && (!two_checkers)) {
										for (int k = 0; k < 24; k++) {
											if ((checkers[k].get_i() == j) && (checkers[k].get_j() == i)) {
												game_pole[j, i]->BackgroundImage = imageList1->Images[6];
												checkers[k].active = true;
												can_beat = true;
											}
										}
									}
									if (((game_pole[l, m]->Tag == "0") || (game_pole[l, m]->Tag == "2")) && (!checker)) break;
									l--; // тоже увеличиваю, чтобы искало по диагонале 								
								}

								l = j - 1;
								two_checkers = false;
								checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
										//влево вниз 
								for (int m = i+1; m < 8; m++) {
									if (l < 0) { // чтобы не было выхода за границу массива
										break;
									}
									if ((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) {
										if (checker) {                       //здесь ищу первую шашку, которую мы бьем
											two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
										}
										else {
											Pl = l; //запоминаю эти координаты
											Pm = m;
											checker = true;
										}
									}
									if (((Pl - 1 > -1) && (Pm + 1 < 8)) && (checker) && (game_pole[Pl - 1, Pm + 1]->Tag == "5") && (!two_checkers)) {
										for (int k = 0; k < 24; k++) {
											if ((checkers[k].get_i() == j) && (checkers[k].get_j() == i)) {
												game_pole[j, i]->BackgroundImage = imageList1->Images[6];
												checkers[k].active = true;
												can_beat = true;
											}
										}
									}
									if (((game_pole[l, m]->Tag == "0") || (game_pole[l, m]->Tag == "2")) && (!checker)) break;
									l--; // тоже увеличиваю, чтобы искало по диагонале 								
								}

								l = j + 1;
								two_checkers = false;
								checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
										//вправо вниз 
								for (int m = i+1; m < 8; m++) {
									if (l > 7) { // чтобы не было выхода за границу массива
										break;
									}
									if ((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) {
										if (checker) {                       //здесь ищу первую шашку, которую мы бьем
											two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
										}
										else {
											Pl = l; //запоминаю эти координаты
											Pm = m;
											checker = true;
										}
									}
									if (((Pl + 1 < 8) && (Pm + 1 < 8)) && (checker) && (game_pole[Pl + 1, Pm + 1]->Tag == "5") && (!two_checkers)) {
										for (int k = 0; k < 24; k++) {
											if ((checkers[k].get_i() == j) && (checkers[k].get_j() == i)) {
												game_pole[j, i]->BackgroundImage = imageList1->Images[6];
												checkers[k].active = true;
												can_beat = true;
											}
										}
									}
									if (((game_pole[l, m]->Tag == "0") || (game_pole[l, m]->Tag == "2")) && (!checker)) break;
									l++; // тоже увеличиваю, чтобы искало по диагонале 									
								}

								break;
							case 3: // черная дамка
								//вправо вверх 				
								l = j + 1; //чтобы сразу пропускать саму шашку и сканировать дальше
								for (int m = i-1; m > -1; m--) {
									if (l > 7) { // чтобы не было выхода за границу массива
										break;
									}
									if ((game_pole[l, m]->Tag == "0") || (game_pole[l, m]->Tag == "2")) {
										if (checker) {                       //здесь ищу первую шашку, которую мы бьем
											two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
										}
										else {
											Pl = l; //запоминаю эти координаты
											Pm = m;
											checker = true;
										}
									}
									if (((Pl + 1 < 8) && (Pm - 1 > -1)) && (checker) && (game_pole[Pl + 1, Pm - 1]->Tag == "5") && (!two_checkers)) {
										for (int k = 0; k < 24; k++) {
											if ((checkers[k].get_i() == j) && (checkers[k].get_j() == i)) { // если побили шашку, то находим ее и помечаем это
												game_pole[j, i]->BackgroundImage = imageList1->Images[6];
												checkers[k].active = true;
												can_beat = true;
											}
										}
									}
									if (((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) && (!checker)) break;
									l++; // тоже увеличиваю, чтобы искало по диагонале 									
								}

								l = j-1;
								two_checkers = false;
								checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
										//влево вверх
								for (int m = i-1; m > -1; m--) {
									if (l < 0) { // чтобы не было выхода за границу массива
										break;
									}
									if ((game_pole[l, m]->Tag == "0") || (game_pole[l, m]->Tag == "2")) {
										if (checker) {                       //здесь ищу первую шашку, которую мы бьем
											two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
										}
										else {
											Pl = l; //запоминаю эти координаты
											Pm = m;
											checker = true;
										}
									}
									if (((Pl - 1 > -1) && (Pm - 1 > -1)) && (checker) && (game_pole[Pl - 1, Pm - 1]->Tag == "5") && (!two_checkers)) {
										for (int k = 0; k < 24; k++) {
											if ((checkers[k].get_i() == j) && (checkers[k].get_j() == i)) {
												game_pole[j, i]->BackgroundImage = imageList1->Images[6];
												checkers[k].active = true;
												can_beat = true;
											}
										}
									}
									if (((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) && (!checker)) break;
									l--; // тоже увеличиваю, чтобы искало по диагонале 						
								}

								l = j-1;
								two_checkers = false;
								checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
										//влево вниз 
								for (int m = i+1; m < 8; m++) {
									if (l < 0) { // чтобы не было выхода за границу массива
										break;
									}
									if ((game_pole[l, m]->Tag == "0") || (game_pole[l, m]->Tag == "2")) {
										if (checker) {                       //здесь ищу первую шашку, которую мы бьем
											two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
										}
										else {
											Pl = l; //запоминаю эти координаты
											Pm = m;
											checker = true;
										}
									}
									if (((Pl - 1 > -1) && (Pm + 1 < 8)) && (checker) && (game_pole[Pl - 1, Pm + 1]->Tag == "5") && (!two_checkers)) {
										for (int k = 0; k < 24; k++) {
											if ((checkers[k].get_i() == j) && (checkers[k].get_j() == i)) {
												game_pole[j, i]->BackgroundImage = imageList1->Images[6];
												checkers[k].active = true;
												can_beat = true;
											}
										}
									}
									if (((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) && (!checker)) break;
									l--; // тоже увеличиваю, чтобы искало по диагонале 							
								}

								l = j+1;
								two_checkers = false;
								checker = false; //  нужна для того, что искать шашку, а за ней пустое место (тогда значит можно бить)
										//вправо вниз 
								for (int m = i+1; m < 8; m++) {
									if (l > 7) { // чтобы не было выхода за границу массива
										break;
									}
									if ((game_pole[l, m]->Tag == "0") || (game_pole[l, m]->Tag == "2")) {
										if (checker) {                       //здесь ищу первую шашку, которую мы бьем
											two_checkers = true; 			//если их оказывается больше одной, то идем сюда			
										}
										else {
											Pl = l; //запоминаю эти координаты
											Pm = m;
											checker = true;
										}
									}
									if (((Pl + 1 < 8) && (Pm + 1 < 8)) && (checker) && (game_pole[Pl + 1, Pm + 1]->Tag == "5") && (!two_checkers)) {
										for (int k = 0; k < 24; k++) {
											if ((checkers[k].get_i() == j) && (checkers[k].get_j() == i)) {
												game_pole[j, i]->BackgroundImage = imageList1->Images[6];
												checkers[k].active = true;
												can_beat = true;
											}
										}
									}
									if (((game_pole[l, m]->Tag == "1") || (game_pole[l, m]->Tag == "3")) && (!checker)) break;
									l++; // тоже увеличиваю, чтобы искало по диагонале 						
								}
								break;
							}
						}
					}
					
				}
			}
			if (can_beat) {
				return true;
			}
			else {
				return false;
			}
		}
	
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::ImageList^ imageList1;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::PictureBox^ picture;
private: System::Windows::Forms::Button^ but25;
private: System::Windows::Forms::Button^ but33;
private: System::Windows::Forms::Button^ but17;
private: System::Windows::Forms::Button^ but9;
private: System::Windows::Forms::Button^ but1;
private: System::Windows::Forms::Button^ but57;
private: System::Windows::Forms::Button^ but49;
private: System::Windows::Forms::Button^ but41;
private: System::Windows::Forms::Button^ but26;
private: System::Windows::Forms::Button^ but34;
private: System::Windows::Forms::Button^ but18;
private: System::Windows::Forms::Button^ but10;
private: System::Windows::Forms::Button^ but2;
private: System::Windows::Forms::Button^ but58;
private: System::Windows::Forms::Button^ but50;
private: System::Windows::Forms::Button^ but42;
private: System::Windows::Forms::Button^ but27;
private: System::Windows::Forms::Button^ but35;
private: System::Windows::Forms::Button^ but19;
private: System::Windows::Forms::Button^ but11;
private: System::Windows::Forms::Button^ but3;
private: System::Windows::Forms::Button^ but59;
private: System::Windows::Forms::Button^ but51;
private: System::Windows::Forms::Button^ but43;
private: System::Windows::Forms::Button^ but28;
private: System::Windows::Forms::Button^ but36;
private: System::Windows::Forms::Button^ but20;
private: System::Windows::Forms::Button^ but12;
private: System::Windows::Forms::Button^ but4;
private: System::Windows::Forms::Button^ but60;
private: System::Windows::Forms::Button^ but52;
private: System::Windows::Forms::Button^ but44;
private: System::Windows::Forms::Button^ but29;
private: System::Windows::Forms::Button^ but37;
private: System::Windows::Forms::Button^ but21;
private: System::Windows::Forms::Button^ but13;
private: System::Windows::Forms::Button^ but5;
private: System::Windows::Forms::Button^ but61;
private: System::Windows::Forms::Button^ but53;
private: System::Windows::Forms::Button^ but45;
private: System::Windows::Forms::Button^ but30;
private: System::Windows::Forms::Button^ but38;
private: System::Windows::Forms::Button^ but22;
private: System::Windows::Forms::Button^ but14;
private: System::Windows::Forms::Button^ but6;
private: System::Windows::Forms::Button^ but62;
private: System::Windows::Forms::Button^ but54;
private: System::Windows::Forms::Button^ but46;
private: System::Windows::Forms::Button^ but31;
private: System::Windows::Forms::Button^ but39;
private: System::Windows::Forms::Button^ but23;
private: System::Windows::Forms::Button^ but15;
private: System::Windows::Forms::Button^ but7;
private: System::Windows::Forms::Button^ but63;
private: System::Windows::Forms::Button^ but55;
private: System::Windows::Forms::Button^ but47;
private: System::Windows::Forms::Button^ but32;
private: System::Windows::Forms::Button^ but40;
private: System::Windows::Forms::Button^ but24;
private: System::Windows::Forms::Button^ but16;
private: System::Windows::Forms::Button^ but8;
private: System::Windows::Forms::Button^ but64;
private: System::Windows::Forms::Button^ but56;
private: System::Windows::Forms::Button^ but48;
private: System::Windows::Forms::Panel^ panel1;
public: System::Windows::Forms::ContextMenuStrip^ context_menu;
private:


private: System::Windows::Forms::ToolStripMenuItem^ начатьСначалаToolStripMenuItem;






private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;

	private: System::ComponentModel::IContainer^ components;

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->picture = (gcnew System::Windows::Forms::PictureBox());
			this->but25 = (gcnew System::Windows::Forms::Button());
			this->but33 = (gcnew System::Windows::Forms::Button());
			this->but17 = (gcnew System::Windows::Forms::Button());
			this->but9 = (gcnew System::Windows::Forms::Button());
			this->but1 = (gcnew System::Windows::Forms::Button());
			this->but57 = (gcnew System::Windows::Forms::Button());
			this->but49 = (gcnew System::Windows::Forms::Button());
			this->but41 = (gcnew System::Windows::Forms::Button());
			this->but26 = (gcnew System::Windows::Forms::Button());
			this->but34 = (gcnew System::Windows::Forms::Button());
			this->but18 = (gcnew System::Windows::Forms::Button());
			this->but10 = (gcnew System::Windows::Forms::Button());
			this->but2 = (gcnew System::Windows::Forms::Button());
			this->but58 = (gcnew System::Windows::Forms::Button());
			this->but50 = (gcnew System::Windows::Forms::Button());
			this->but42 = (gcnew System::Windows::Forms::Button());
			this->but27 = (gcnew System::Windows::Forms::Button());
			this->but35 = (gcnew System::Windows::Forms::Button());
			this->but19 = (gcnew System::Windows::Forms::Button());
			this->but11 = (gcnew System::Windows::Forms::Button());
			this->but3 = (gcnew System::Windows::Forms::Button());
			this->but59 = (gcnew System::Windows::Forms::Button());
			this->but51 = (gcnew System::Windows::Forms::Button());
			this->but43 = (gcnew System::Windows::Forms::Button());
			this->but28 = (gcnew System::Windows::Forms::Button());
			this->but36 = (gcnew System::Windows::Forms::Button());
			this->but20 = (gcnew System::Windows::Forms::Button());
			this->but12 = (gcnew System::Windows::Forms::Button());
			this->but4 = (gcnew System::Windows::Forms::Button());
			this->but60 = (gcnew System::Windows::Forms::Button());
			this->but52 = (gcnew System::Windows::Forms::Button());
			this->but44 = (gcnew System::Windows::Forms::Button());
			this->but29 = (gcnew System::Windows::Forms::Button());
			this->but37 = (gcnew System::Windows::Forms::Button());
			this->but21 = (gcnew System::Windows::Forms::Button());
			this->but13 = (gcnew System::Windows::Forms::Button());
			this->but5 = (gcnew System::Windows::Forms::Button());
			this->but61 = (gcnew System::Windows::Forms::Button());
			this->but53 = (gcnew System::Windows::Forms::Button());
			this->but45 = (gcnew System::Windows::Forms::Button());
			this->but30 = (gcnew System::Windows::Forms::Button());
			this->but38 = (gcnew System::Windows::Forms::Button());
			this->but22 = (gcnew System::Windows::Forms::Button());
			this->but14 = (gcnew System::Windows::Forms::Button());
			this->but6 = (gcnew System::Windows::Forms::Button());
			this->but62 = (gcnew System::Windows::Forms::Button());
			this->but54 = (gcnew System::Windows::Forms::Button());
			this->but46 = (gcnew System::Windows::Forms::Button());
			this->but31 = (gcnew System::Windows::Forms::Button());
			this->but39 = (gcnew System::Windows::Forms::Button());
			this->but23 = (gcnew System::Windows::Forms::Button());
			this->but15 = (gcnew System::Windows::Forms::Button());
			this->but7 = (gcnew System::Windows::Forms::Button());
			this->but63 = (gcnew System::Windows::Forms::Button());
			this->but55 = (gcnew System::Windows::Forms::Button());
			this->but47 = (gcnew System::Windows::Forms::Button());
			this->but32 = (gcnew System::Windows::Forms::Button());
			this->but40 = (gcnew System::Windows::Forms::Button());
			this->but24 = (gcnew System::Windows::Forms::Button());
			this->but16 = (gcnew System::Windows::Forms::Button());
			this->but8 = (gcnew System::Windows::Forms::Button());
			this->but64 = (gcnew System::Windows::Forms::Button());
			this->but56 = (gcnew System::Windows::Forms::Button());
			this->but48 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->context_menu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->начатьСначалаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture))->BeginInit();
			this->panel1->SuspendLayout();
			this->context_menu->SuspendLayout();
			this->SuspendLayout();
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->Tag = L"5";
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"белая_ш.png");
			this->imageList1->Images->SetKeyName(1, L"черная_ш.png");
			this->imageList1->Images->SetKeyName(2, L"белая_д.png");
			this->imageList1->Images->SetKeyName(3, L"черная_д.png");
			this->imageList1->Images->SetKeyName(4, L"белое поле.png");
			this->imageList1->Images->SetKeyName(5, L"черное поле .png");
			this->imageList1->Images->SetKeyName(6, L"фон.jpg");
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// picture
			// 
			resources->ApplyResources(this->picture, L"picture");
			this->picture->Name = L"picture";
			this->picture->TabStop = false;
			// 
			// but25
			// 
			resources->ApplyResources(this->but25, L"but25");
			this->but25->ImageList = this->imageList1;
			this->but25->Name = L"but25";
			this->but25->Tag = L"5";
			this->but25->UseVisualStyleBackColor = true;
			this->but25->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but33
			// 
			resources->ApplyResources(this->but33, L"but33");
			this->but33->Name = L"but33";
			this->but33->UseVisualStyleBackColor = true;
			// 
			// but17
			// 
			resources->ApplyResources(this->but17, L"but17");
			this->but17->Name = L"but17";
			this->but17->UseVisualStyleBackColor = true;
			// 
			// but9
			// 
			this->but9->BackColor = System::Drawing::SystemColors::ControlDark;
			resources->ApplyResources(this->but9, L"but9");
			this->but9->ImageList = this->imageList1;
			this->but9->Name = L"but9";
			this->but9->Tag = L"1";
			this->but9->UseVisualStyleBackColor = false;
			this->but9->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but1
			// 
			resources->ApplyResources(this->but1, L"but1");
			this->but1->Name = L"but1";
			this->but1->UseVisualStyleBackColor = true;
			// 
			// but57
			// 
			resources->ApplyResources(this->but57, L"but57");
			this->but57->ImageList = this->imageList1;
			this->but57->Name = L"but57";
			this->but57->Tag = L"0";
			this->but57->UseVisualStyleBackColor = true;
			this->but57->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but49
			// 
			resources->ApplyResources(this->but49, L"but49");
			this->but49->Name = L"but49";
			this->but49->UseVisualStyleBackColor = true;
			// 
			// but41
			// 
			resources->ApplyResources(this->but41, L"but41");
			this->but41->ImageList = this->imageList1;
			this->but41->Name = L"but41";
			this->but41->Tag = L"0";
			this->but41->UseVisualStyleBackColor = true;
			this->but41->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but26
			// 
			resources->ApplyResources(this->but26, L"but26");
			this->but26->Name = L"but26";
			this->but26->UseVisualStyleBackColor = true;
			// 
			// but34
			// 
			resources->ApplyResources(this->but34, L"but34");
			this->but34->ImageList = this->imageList1;
			this->but34->Name = L"but34";
			this->but34->Tag = L"5";
			this->but34->UseVisualStyleBackColor = true;
			this->but34->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but18
			// 
			this->but18->BackColor = System::Drawing::SystemColors::ControlDark;
			resources->ApplyResources(this->but18, L"but18");
			this->but18->ImageList = this->imageList1;
			this->but18->Name = L"but18";
			this->but18->Tag = L"1";
			this->but18->UseVisualStyleBackColor = false;
			this->but18->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but10
			// 
			resources->ApplyResources(this->but10, L"but10");
			this->but10->Name = L"but10";
			this->but10->UseVisualStyleBackColor = true;
			// 
			// but2
			// 
			this->but2->BackColor = System::Drawing::SystemColors::ControlDark;
			resources->ApplyResources(this->but2, L"but2");
			this->but2->ImageList = this->imageList1;
			this->but2->Name = L"but2";
			this->but2->Tag = L"1";
			this->but2->UseVisualStyleBackColor = false;
			this->but2->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but58
			// 
			resources->ApplyResources(this->but58, L"but58");
			this->but58->Name = L"but58";
			this->but58->UseVisualStyleBackColor = true;
			// 
			// but50
			// 
			resources->ApplyResources(this->but50, L"but50");
			this->but50->ImageList = this->imageList1;
			this->but50->Name = L"but50";
			this->but50->Tag = L"0";
			this->but50->UseVisualStyleBackColor = true;
			this->but50->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but42
			// 
			resources->ApplyResources(this->but42, L"but42");
			this->but42->Name = L"but42";
			this->but42->UseVisualStyleBackColor = true;
			// 
			// but27
			// 
			resources->ApplyResources(this->but27, L"but27");
			this->but27->ImageList = this->imageList1;
			this->but27->Name = L"but27";
			this->but27->Tag = L"5";
			this->but27->UseVisualStyleBackColor = true;
			this->but27->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but35
			// 
			resources->ApplyResources(this->but35, L"but35");
			this->but35->Name = L"but35";
			this->but35->UseVisualStyleBackColor = true;
			// 
			// but19
			// 
			resources->ApplyResources(this->but19, L"but19");
			this->but19->Name = L"but19";
			this->but19->UseVisualStyleBackColor = true;
			// 
			// but11
			// 
			this->but11->BackColor = System::Drawing::SystemColors::ControlDark;
			resources->ApplyResources(this->but11, L"but11");
			this->but11->ImageList = this->imageList1;
			this->but11->Name = L"but11";
			this->but11->Tag = L"1";
			this->but11->UseVisualStyleBackColor = false;
			this->but11->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but3
			// 
			resources->ApplyResources(this->but3, L"but3");
			this->but3->Name = L"but3";
			this->but3->UseVisualStyleBackColor = true;
			// 
			// but59
			// 
			resources->ApplyResources(this->but59, L"but59");
			this->but59->ImageList = this->imageList1;
			this->but59->Name = L"but59";
			this->but59->Tag = L"0";
			this->but59->UseVisualStyleBackColor = true;
			this->but59->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but51
			// 
			resources->ApplyResources(this->but51, L"but51");
			this->but51->Name = L"but51";
			this->but51->UseVisualStyleBackColor = true;
			// 
			// but43
			// 
			resources->ApplyResources(this->but43, L"but43");
			this->but43->ImageList = this->imageList1;
			this->but43->Name = L"but43";
			this->but43->Tag = L"0";
			this->but43->UseVisualStyleBackColor = true;
			this->but43->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but28
			// 
			resources->ApplyResources(this->but28, L"but28");
			this->but28->Name = L"but28";
			this->but28->UseVisualStyleBackColor = true;
			// 
			// but36
			// 
			resources->ApplyResources(this->but36, L"but36");
			this->but36->ImageList = this->imageList1;
			this->but36->Name = L"but36";
			this->but36->Tag = L"5";
			this->but36->UseVisualStyleBackColor = true;
			this->but36->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but20
			// 
			this->but20->BackColor = System::Drawing::SystemColors::ControlDark;
			resources->ApplyResources(this->but20, L"but20");
			this->but20->ImageList = this->imageList1;
			this->but20->Name = L"but20";
			this->but20->Tag = L"1";
			this->but20->UseVisualStyleBackColor = false;
			this->but20->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but12
			// 
			resources->ApplyResources(this->but12, L"but12");
			this->but12->Name = L"but12";
			this->but12->UseVisualStyleBackColor = true;
			// 
			// but4
			// 
			this->but4->BackColor = System::Drawing::SystemColors::ControlDark;
			resources->ApplyResources(this->but4, L"but4");
			this->but4->ImageList = this->imageList1;
			this->but4->Name = L"but4";
			this->but4->Tag = L"1";
			this->but4->UseVisualStyleBackColor = false;
			this->but4->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but60
			// 
			resources->ApplyResources(this->but60, L"but60");
			this->but60->Name = L"but60";
			this->but60->UseVisualStyleBackColor = true;
			// 
			// but52
			// 
			resources->ApplyResources(this->but52, L"but52");
			this->but52->ImageList = this->imageList1;
			this->but52->Name = L"but52";
			this->but52->Tag = L"0";
			this->but52->UseVisualStyleBackColor = true;
			this->but52->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but44
			// 
			resources->ApplyResources(this->but44, L"but44");
			this->but44->Name = L"but44";
			this->but44->UseVisualStyleBackColor = true;
			// 
			// but29
			// 
			resources->ApplyResources(this->but29, L"but29");
			this->but29->ImageList = this->imageList1;
			this->but29->Name = L"but29";
			this->but29->Tag = L"5";
			this->but29->UseVisualStyleBackColor = true;
			this->but29->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but37
			// 
			resources->ApplyResources(this->but37, L"but37");
			this->but37->Name = L"but37";
			this->but37->UseVisualStyleBackColor = true;
			// 
			// but21
			// 
			resources->ApplyResources(this->but21, L"but21");
			this->but21->Name = L"but21";
			this->but21->UseVisualStyleBackColor = true;
			// 
			// but13
			// 
			this->but13->BackColor = System::Drawing::SystemColors::ControlDark;
			resources->ApplyResources(this->but13, L"but13");
			this->but13->ImageList = this->imageList1;
			this->but13->Name = L"but13";
			this->but13->Tag = L"1";
			this->but13->UseVisualStyleBackColor = false;
			this->but13->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but5
			// 
			resources->ApplyResources(this->but5, L"but5");
			this->but5->Name = L"but5";
			this->but5->UseVisualStyleBackColor = true;
			// 
			// but61
			// 
			resources->ApplyResources(this->but61, L"but61");
			this->but61->ImageList = this->imageList1;
			this->but61->Name = L"but61";
			this->but61->Tag = L"0";
			this->but61->UseVisualStyleBackColor = true;
			this->but61->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but53
			// 
			resources->ApplyResources(this->but53, L"but53");
			this->but53->Name = L"but53";
			this->but53->UseVisualStyleBackColor = true;
			// 
			// but45
			// 
			resources->ApplyResources(this->but45, L"but45");
			this->but45->ImageList = this->imageList1;
			this->but45->Name = L"but45";
			this->but45->Tag = L"0";
			this->but45->UseVisualStyleBackColor = true;
			this->but45->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but30
			// 
			resources->ApplyResources(this->but30, L"but30");
			this->but30->Name = L"but30";
			this->but30->UseVisualStyleBackColor = true;
			// 
			// but38
			// 
			resources->ApplyResources(this->but38, L"but38");
			this->but38->ImageList = this->imageList1;
			this->but38->Name = L"but38";
			this->but38->Tag = L"5";
			this->but38->UseVisualStyleBackColor = true;
			this->but38->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but22
			// 
			this->but22->BackColor = System::Drawing::SystemColors::ControlDark;
			resources->ApplyResources(this->but22, L"but22");
			this->but22->ImageList = this->imageList1;
			this->but22->Name = L"but22";
			this->but22->Tag = L"1";
			this->but22->UseVisualStyleBackColor = false;
			this->but22->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but14
			// 
			resources->ApplyResources(this->but14, L"but14");
			this->but14->Name = L"but14";
			this->but14->UseVisualStyleBackColor = true;
			// 
			// but6
			// 
			this->but6->BackColor = System::Drawing::SystemColors::ControlDark;
			resources->ApplyResources(this->but6, L"but6");
			this->but6->ImageList = this->imageList1;
			this->but6->Name = L"but6";
			this->but6->Tag = L"1";
			this->but6->UseVisualStyleBackColor = false;
			this->but6->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but62
			// 
			resources->ApplyResources(this->but62, L"but62");
			this->but62->Name = L"but62";
			this->but62->UseVisualStyleBackColor = true;
			// 
			// but54
			// 
			resources->ApplyResources(this->but54, L"but54");
			this->but54->ImageList = this->imageList1;
			this->but54->Name = L"but54";
			this->but54->Tag = L"0";
			this->but54->UseVisualStyleBackColor = true;
			this->but54->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but46
			// 
			resources->ApplyResources(this->but46, L"but46");
			this->but46->Name = L"but46";
			this->but46->UseVisualStyleBackColor = true;
			// 
			// but31
			// 
			resources->ApplyResources(this->but31, L"but31");
			this->but31->ImageList = this->imageList1;
			this->but31->Name = L"but31";
			this->but31->Tag = L"5";
			this->but31->UseVisualStyleBackColor = true;
			this->but31->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but39
			// 
			resources->ApplyResources(this->but39, L"but39");
			this->but39->Name = L"but39";
			this->but39->UseVisualStyleBackColor = true;
			// 
			// but23
			// 
			resources->ApplyResources(this->but23, L"but23");
			this->but23->Name = L"but23";
			this->but23->UseVisualStyleBackColor = true;
			// 
			// but15
			// 
			this->but15->BackColor = System::Drawing::SystemColors::ControlDark;
			resources->ApplyResources(this->but15, L"but15");
			this->but15->ImageList = this->imageList1;
			this->but15->Name = L"but15";
			this->but15->Tag = L"1";
			this->but15->UseVisualStyleBackColor = false;
			this->but15->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but7
			// 
			resources->ApplyResources(this->but7, L"but7");
			this->but7->Name = L"but7";
			this->but7->UseVisualStyleBackColor = true;
			// 
			// but63
			// 
			resources->ApplyResources(this->but63, L"but63");
			this->but63->ImageList = this->imageList1;
			this->but63->Name = L"but63";
			this->but63->Tag = L"0";
			this->but63->UseVisualStyleBackColor = true;
			this->but63->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but55
			// 
			resources->ApplyResources(this->but55, L"but55");
			this->but55->Name = L"but55";
			this->but55->UseVisualStyleBackColor = true;
			// 
			// but47
			// 
			resources->ApplyResources(this->but47, L"but47");
			this->but47->ImageList = this->imageList1;
			this->but47->Name = L"but47";
			this->but47->Tag = L"0";
			this->but47->UseVisualStyleBackColor = true;
			this->but47->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but32
			// 
			resources->ApplyResources(this->but32, L"but32");
			this->but32->Name = L"but32";
			this->but32->UseVisualStyleBackColor = true;
			// 
			// but40
			// 
			resources->ApplyResources(this->but40, L"but40");
			this->but40->ImageList = this->imageList1;
			this->but40->Name = L"but40";
			this->but40->Tag = L"5";
			this->but40->UseVisualStyleBackColor = true;
			this->but40->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but24
			// 
			this->but24->BackColor = System::Drawing::SystemColors::ControlDark;
			resources->ApplyResources(this->but24, L"but24");
			this->but24->ImageList = this->imageList1;
			this->but24->Name = L"but24";
			this->but24->Tag = L"1";
			this->but24->UseVisualStyleBackColor = false;
			this->but24->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but16
			// 
			resources->ApplyResources(this->but16, L"but16");
			this->but16->Name = L"but16";
			this->but16->UseVisualStyleBackColor = true;
			// 
			// but8
			// 
			this->but8->BackColor = System::Drawing::SystemColors::ControlDark;
			resources->ApplyResources(this->but8, L"but8");
			this->but8->ImageList = this->imageList1;
			this->but8->Name = L"but8";
			this->but8->Tag = L"1";
			this->but8->UseVisualStyleBackColor = false;
			this->but8->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but64
			// 
			resources->ApplyResources(this->but64, L"but64");
			this->but64->Name = L"but64";
			this->but64->UseVisualStyleBackColor = true;
			// 
			// but56
			// 
			resources->ApplyResources(this->but56, L"but56");
			this->but56->ImageList = this->imageList1;
			this->but56->Name = L"but56";
			this->but56->Tag = L"0";
			this->but56->UseVisualStyleBackColor = true;
			this->but56->Click += gcnew System::EventHandler(this, &MyForm1::but2_Click);
			// 
			// but48
			// 
			resources->ApplyResources(this->but48, L"but48");
			this->but48->Name = L"but48";
			this->but48->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->but48);
			this->panel1->Controls->Add(this->but56);
			this->panel1->Controls->Add(this->but64);
			this->panel1->Controls->Add(this->but8);
			this->panel1->Controls->Add(this->but16);
			this->panel1->Controls->Add(this->but24);
			this->panel1->Controls->Add(this->but40);
			this->panel1->Controls->Add(this->but32);
			this->panel1->Controls->Add(this->but47);
			this->panel1->Controls->Add(this->but55);
			this->panel1->Controls->Add(this->but63);
			this->panel1->Controls->Add(this->but7);
			this->panel1->Controls->Add(this->but15);
			this->panel1->Controls->Add(this->but23);
			this->panel1->Controls->Add(this->but39);
			this->panel1->Controls->Add(this->but31);
			this->panel1->Controls->Add(this->but46);
			this->panel1->Controls->Add(this->but54);
			this->panel1->Controls->Add(this->but62);
			this->panel1->Controls->Add(this->but6);
			this->panel1->Controls->Add(this->but14);
			this->panel1->Controls->Add(this->but22);
			this->panel1->Controls->Add(this->but38);
			this->panel1->Controls->Add(this->but30);
			this->panel1->Controls->Add(this->but45);
			this->panel1->Controls->Add(this->but53);
			this->panel1->Controls->Add(this->but61);
			this->panel1->Controls->Add(this->but5);
			this->panel1->Controls->Add(this->but13);
			this->panel1->Controls->Add(this->but21);
			this->panel1->Controls->Add(this->but37);
			this->panel1->Controls->Add(this->but29);
			this->panel1->Controls->Add(this->but44);
			this->panel1->Controls->Add(this->but52);
			this->panel1->Controls->Add(this->but60);
			this->panel1->Controls->Add(this->but4);
			this->panel1->Controls->Add(this->but12);
			this->panel1->Controls->Add(this->but20);
			this->panel1->Controls->Add(this->but36);
			this->panel1->Controls->Add(this->but28);
			this->panel1->Controls->Add(this->but43);
			this->panel1->Controls->Add(this->but51);
			this->panel1->Controls->Add(this->but59);
			this->panel1->Controls->Add(this->but3);
			this->panel1->Controls->Add(this->but11);
			this->panel1->Controls->Add(this->but19);
			this->panel1->Controls->Add(this->but35);
			this->panel1->Controls->Add(this->but27);
			this->panel1->Controls->Add(this->but42);
			this->panel1->Controls->Add(this->but50);
			this->panel1->Controls->Add(this->but58);
			this->panel1->Controls->Add(this->but2);
			this->panel1->Controls->Add(this->but10);
			this->panel1->Controls->Add(this->but18);
			this->panel1->Controls->Add(this->but34);
			this->panel1->Controls->Add(this->but26);
			this->panel1->Controls->Add(this->but41);
			this->panel1->Controls->Add(this->but49);
			this->panel1->Controls->Add(this->but57);
			this->panel1->Controls->Add(this->but1);
			this->panel1->Controls->Add(this->but9);
			this->panel1->Controls->Add(this->but17);
			this->panel1->Controls->Add(this->but33);
			this->panel1->Controls->Add(this->but25);
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->Name = L"panel1";
			// 
			// context_menu
			// 
			this->context_menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->начатьСначалаToolStripMenuItem,
					this->выходToolStripMenuItem
			});
			this->context_menu->Name = L"contextMenuStrip1";
			this->context_menu->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			resources->ApplyResources(this->context_menu, L"context_menu");
			this->context_menu->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm1::contextMenuStrip1_Opening);
			// 
			// начатьСначалаToolStripMenuItem
			// 
			this->начатьСначалаToolStripMenuItem->Name = L"начатьСначалаToolStripMenuItem";
			resources->ApplyResources(this->начатьСначалаToolStripMenuItem, L"начатьСначалаToolStripMenuItem");
			this->начатьСначалаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm1::начатьСначалаToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			resources->ApplyResources(this->выходToolStripMenuItem, L"выходToolStripMenuItem");
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm1::выходToolStripMenuItem_Click);
			// 
			// MyForm1
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ContextMenuStrip = this->context_menu;
			this->Controls->Add(this->picture);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm1";
			this->TransparencyKey = System::Drawing::Color::White;
			this->Shown += gcnew System::EventHandler(this, &MyForm1::MyForm1_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture))->EndInit();
			this->panel1->ResumeLayout(false);
			this->context_menu->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: System::Void MyForm1_Shown(System::Object^ sender, System::EventArgs^ e) {
		game_start();		
}


		   
private: System::Void but2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (turn) {//находим шашку на которую нажали и помечаем, что она сейчас будет ходить 
		if (beaten) { // если сюда попадаем, значит шашка, которая била может бить еще
			if (sender != game_pole[Pj, Pi]) {
				game_pole[Pj, Pi]->BackgroundImage = imageList1->Images[5];
				return;
			}
			else {
				for (int k = 0; k < 24; ++k) {
					if ((checkers[k].get_i() == Pj) && (checkers[k].get_j() == Pi) && (checkers[k].can_turn)) { //находим шашку и проверяем ее ли ход
						checkers[k].active = true;
						game_pole[Pj, Pi]->BackgroundImage = imageList1->Images[6];
					}
				}
			}
		}
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				 if (sender == game_pole[j, i]) { // при первом выборе шашки для хода
					 Pj = j;
					 Pi = i;
							if (check_must_beat()) { // если после проверки на возможность битья мы нашли шашку, которая должа бить, то идем сюда
								for (int k = 0; k < 24; ++k) {
									if ((checkers[k].get_i() == j) && (checkers[k].get_j() == i) && (checkers[k].active)&&(!checkers[k].beaten)) {
										game_pole[Pj, Pi]->BackgroundImage = imageList1->Images[6];
										check_must_beat_checker = true; // для того, чтобы при следующем нажатии снова не вызывать эту процедуру
										turn = false;
										return;
									}
								}
							}
							else{
								for (int k = 0; k < 24; ++k) {
									if ((checkers[k].get_i() == j) && (checkers[k].get_j() == i) && (checkers[k].can_turn) && (!checkers[k].beaten)) { //находим шашку и проверяем ее ли ход
										checkers[k].active = true;
										game_pole[j, i]->BackgroundImage = imageList1->Images[6]; // зеленое выделение шашки
										turn = false;
										Pj = j;
										Pi = i;
										return;
									}
								}
							}
														
				}	
			}
		}
	}
	else { // проверяем может ли шашка сюда походить и ходим
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (sender == game_pole[j, i]) {
					if ((j == Pj) && (i == Pi)&&(!beaten)&&(!check_must_beat_checker)) {	// проверка при выборе одной и той же шашки, а когда beaten true, значит пропускаем, так как шашка должа бить ещё раз
						for (int k = 0; k < 24; ++k) { //если одна и таже шашка, то нужно убрать ее свойство active назад в false, так как она не ходит (взяли в руки и поставили назад)
							if (checkers[k].active) {
								checkers[k].active = false;
								game_pole[Pj, Pi]->BackgroundImage = imageList1->Images[5];
							}
						}	
						turn = true; // возвращаем маркер на то, что ход отменен
						return;
					}
					else {
						if (game_pole[j, i]->Tag == "5") { //чтобы нельзя было ставить шашку на другую шашку
							for (int k = 0; k < 24; ++k) {
								if ((checkers[k].active) && (!checkers[k].beaten)&&(Pi==checkers[k].get_j())&&(Pj==checkers[k].get_i())){//находим шашку и ходим 
									game_pole[Pj, Pi]->BackgroundImage = imageList1->Images[6];
									int x = checkers[k].get_checker(); // проверка на возможность такого хода для данной шашки					
									if (!must_beat(x, i, j)) { // проверка при выборе одной и той же шашки, а когда beaten true, значит пропускаем, так как шашка должа бить ещё раз
										checkers[k].active = false;				// если шашка била, 
										game_pole[Pj, Pi]->BackgroundImage = imageList1->Images[5];
										turn = true; // чтобы выбрать шашку заново, а то иначе нужно по два раза жмякать на нее
										return;
									}

									if (((i == 0) && (checkers[k].get_checker() == 0))) { //здесь определяю какая шашка будет после хода / передвигаю их по полю
										game_pole[j, i]->Tag = "2";
									}
									else if (((i == 7) && (checkers[k].get_checker() == 1))) {
										game_pole[j, i]->Tag = "3";
									}
									else {
										game_pole[j, i]->Tag = game_pole[checkers[k].get_i(), checkers[k].get_j()]->Tag; // меняем Tag в кнопке, чтобы перемещать картинку
									}
									game_pole[checkers[k].get_i(), checkers[k].get_j()]->Tag = "5"; // 5 потому что будет пустое поле	
									

									if (game_pole[j, i]->Tag == "1") {//  черная шашка     
										checkers[k].set_checker_data(j, i, 1);
									}																//меняем координаты шашки	
									else if (game_pole[j, i]->Tag == "0") {//белая шашка
										checkers[k].set_checker_data(j, i, 0);
									}	
									else if (game_pole[j, i]->Tag == "2") {//белая дамка
										checkers[k].set_checker_data(j, i, 2);
									}
									else if (game_pole[j, i]->Tag == "3") {//черная дамка
										checkers[k].set_checker_data(j, i, 3);	
									}
									x = checkers[k].get_checker(); // снова переприсваиваем для того, что если после битья шашка стала дамкой, 
																//то нужно проверять может ли эта дамка еще бить

								Pj = j;	//меняем координаты для того, чтобы проверить может ли эта шашка бить ещё
								Pi = i;	
								
								check_game_pole(); // корректируем поле после хода		
								if (!can_beat_again(x)) { // если эта шашка больше бить не может, то смена хода
									change_turn(); // смена хода
									if (check_win()) { //проверка на победу
										game_start();
									}
									else {
										beaten = false;
										checkers[k].active = false;    //после хода шашка снова не активна
										game_pole[Pj, Pi]->BackgroundImage = imageList1->Images[5];
										turn = true;
										check_must_beat_checker = false;
										for (int k = 0; k < 24; k++) {
											if (checkers[k].active == true) {
												game_pole[checkers[k].get_i(),checkers[k].get_j() ]->BackgroundImage = imageList1->Images[5]; // если шашки больше бить не могут, то снимает выделение
											}
										}
									}
									
									
								}
								else {
									game_pole[Pj, Pi]->BackgroundImage = imageList1->Images[6]; // если может бить, то она еще выделена
								}
								return;
								}
							}


						}
						else {
							turn = true;
							for (int k = 0; k < 24; ++k) { //если одна и таже шашка, то нужно убрать ее свойство active назад в false, так как она не ходит (взяли в руки и поставили назад)
								checkers[k].active = false;
								game_pole[Pj, Pi]->BackgroundImage = imageList1->Images[5];
							}	
							return;
						}
					}
						
				}
			}
		}

		
	}
	//check_must_beat_checker = false;
}
private: System::Void contextMenuStrip1_Opening(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
	delete game_pole;
}
private: System::Void начатьСначалаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	game_start();
}
};





}
