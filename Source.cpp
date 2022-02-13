#include<SFML/Graphics.hpp>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<ctype.h>
void instructions(char arr[50]);
void catg(void);
int pick(void);
int main()
{
	int count, counter, count1 = 0;//declaration of counters
	int choice, d, readCount, size, length, i, show = 0;
	int noofgames = 0;//total number of games counter
	int noofgameswon = 0;//no. of games won counter

	char c, again, guess;//character to take input
	char str[50];//char array to take the name from the file
	char username[50];//taking the user name
	char word[50];//copying of the name from str to word
	char displayarray[50];//displaying the correct guesses
	char incorrect[5];//incorrect guesses 
	char nof[100] = "Number of games";//Initilzed strings
	char nofwon[100] = "Number of games won";
	FILE* fp;//file pointer to point the predefined files in the system
	FILE* fpuser;//to point the user name file

	time_t t;//time function predefined
	time(&t);
	srand(time(NULL));//taking random value every time
	while (show< 1)//displaying the intro of the game once
	{
		sf::Font font1;
		if (!font1.loadFromFile("Stay and Shine.ttf"))//fonts cannot be load
		{
			printf("The file cannot be opened");
		}
		sf::RenderWindow start(sf::VideoMode(620, 480), "HANGMAN");//window definintion

		sf::Text text1;//text name
		// select the font
		text1.setFont(font1); // font is a sf::Font

		// set the string to display
		text1.setString(" Welcome to  HANGMAN!!\n\n Press enter to continue");

		// set the character size
		text1.setCharacterSize(40); // in pixels, not points!

		// set the color
		text1.setFillColor(sf::Color::Magenta);

		// set the text style
		text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
		text1.setPosition(50, 250);

		sf::Text ins;
		// select the font
		ins.setFont(font1);
		//writing the instructions of the game 
		ins.setString(" Read the instructions Carefully!!\n\n\n1.You have to guess a word from a specific category.\n2.You only have five guesses, so be careful!\n3.Your wrong guesses could hang the man.\n");
		ins.setCharacterSize(22);//font size
		ins.setStyle(sf::Text::Bold);//bold format
		ins.setFillColor(sf::Color::Red);//red colour
		ins.setPosition(20, 50);//setting the position


		show++;// to terminate the loop
		while (start.isOpen())
		{
			sf::Event event;
			while (start.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed://closing the window
					start.close();
					break;
				case sf::Event::KeyPressed://closing the window
					if (event.key.code == sf::Keyboard::Enter)
					{
						start.close();
					}
					break;

				}

			}

			start.clear();
			start.draw(text1);//displaying all the functions
			start.draw(ins);
			start.display();
		}
	}

	printf("Please enter a username:");
	scanf("%s", &username);//taking user name
	fpuser = fopen(username, "a+");//opening file of the user if exist and not both
	printf("\n\n");
	printf("\t\t\t\tHANGMAN\n");
	instructions(username);//calling function

game:
	counter = 0;
	noofgames++;//The number of games increases from 0 every time
	printf("\nPress Enter to continue.");
	_getch();//taking charachter
	system("CLS");//clear screeen
	catg();//defined function

start:
	choice = pick();//defined function
	system("CLS");
	switch (choice)
	{
		/* cases for the category user enter and then accordance 
		with that file opens and these files are predefined and
		they open in read mode
		*/
	case 1:
		printf("You have to guess the name of a movie!");
		fp = fopen("movies.txt", "r");
		if (fp == NULL)//if the file cannot be opened
		{
			printf("Unable to open file. Sorry but there is a problem in this category.\n");
			printf("\nPlease choose another category:");
			goto start;
		}
		break;
	case 2:
		printf("You have to guess the name of a country! ");
		fp = fopen("countries.txt", "r");
		if (fp == NULL)
		{
			printf("Unable to open file. Sorry but there is a problem in this category.\n");
			printf("\nPlease choose another category:");
			goto start;
		}	
		break;
	case 3:
		printf("You have to guess the name of a vegetable! ");
		fp = fopen("vegetables.txt", "r");
		if (fp == NULL)
		{
			printf("Unable to open file. Sorry but there is a problem in this category.\n");
			printf("\nPlease choose another category:");
			goto start;
		}
		
		break;
	case 4:
		printf("You have to guess  the name of a fruit! ");
		fp = fopen("fruits.txt", "r");
		if (fp == NULL)
		{
			printf("Unable to open file. Sorry but there is a problem in this category.\n");
			printf("\nPlease choose another category:");
			goto start;//goto start of the program
		}
		
		break;
	case 5:
		printf("You have to guess the name of an animal!  ");
		fp = fopen("animals.txt", "r");
		if (fp == NULL)
		{
			printf("Unable to open file. Sorry but there is a problem in this category.\n");
			printf("\nPlease choose another category:");
			goto start;
		}
		
		break;
	case 6:
		printf("You have to guess the name of a sport! ");
		fp = fopen("sports.txt", "r");
		if (fp == NULL)
		{
			printf("Unable to open file. Sorry but there is a problem in this category.\n");
			printf("\nPlease choose another category:");
			goto start;
		}
		
		break;
	case 7:
		printf("You have to guess the name of a Pakistani city! ");
		fp = fopen("Pakistani cities.txt", "r");
		if (fp == NULL)
		{
			printf("Unable to open file. Sorry but there is a problem in this category.\n");
			printf("\nPlease choose another category:");
			goto start;
		}
		
		break;
	default:
		//if any of these 7 keys are not pressed
		printf("Invlaid Input");
		printf("\nPlease enter a number between 1 and 7:");
		pick();
		goto start;
		break;
	}
	int x;
	x = rand() % 30 + 1;
	readCount = 1;// initilizing the counter for read
	while (!feof(fp))// till the end of the file
	{
		fscanf(fp, "%s", str);//taking data from file
		if ((x % ++readCount) == 0)//conditon to pick random name from the file
		{

			strcpy(word, str);// if condition satisfies name copies in word
		}

	}
	//printf("%s", word);
	length = strlen(word);//length of the word 
	fclose(fp);//closing the file 
	for (i = 0; i < 5; i++)
	{
		/*
		In this first the user sees dashes for 5
		places because at the start there is no incorrect guesses
		so initially in the character array we have intilize the array
		with dashes
		*/
		incorrect[i] = '_';
	}
	sf::Font font1;//loading font from the file 
	if (!font1.loadFromFile("Stay and Shine.ttf"))
	{
		printf("The file cannot be opened");
	}
	sf::RenderWindow start(sf::VideoMode(620, 480), "HANGMAN");//opening of the window
	sf::RectangleShape stand1(sf::Vector2f(220, 20));
	stand1.rotate(90);//rotation
	stand1.setPosition(110, 20);//setting the position
	stand1.setFillColor(sf::Color::White);//setting the color
	sf::RectangleShape siri1(sf::Vector2f(35, 5));//defining a new shape
	siri1.rotate(90);//rotation
	siri1.setPosition(180, 20);
	siri1.setFillColor(sf::Color::White);
	sf::RectangleShape line_a(sf::Vector2f(150, 5));
	line_a.rotate(0);
	line_a.setPosition(110, 20);
	sf::Text text1;
	// select the font
	text1.setFont(font1); // font is a sf::Font

	// set the string to display
	text1.setString(" Welcome to  HANGMAN\n\n Press enter to continue");
	// set the character size
	text1.setCharacterSize(40); // in pixels, not points!

	// set the color
	text1.setFillColor(sf::Color::Red);

	// set the text style
	text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text1.setPosition(50, 250);
	while (start.isOpen())
	{
		sf::Event event;//event to display on window
		while (start.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				start.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Enter)
				{
					start.close();
				}
				break;


			}

		}

		start.clear();
		start.draw(text1);
		start.draw(stand1);
		start.draw(line_a);
		start.draw(siri1);
		start.display();
	}

	for (i = 0; i < length; i++)
	{
		/*
		This is basically the character array to take show the right guesses
		but in the start as there is no guess so this array is also initilize with 
		dashes
		*/
		displayarray[i] = '_';
	}

	while (counter < 6)//to execute for five times
	{
		printf("\t\tWord: ");
		for (i = 0; i < length; i++)//in length we have the length of the word
		{
			printf("%c", displayarray[i]);//showing the dashes according to the length of the word
			printf(" ");//space between the dashes
		}

		count1 = 0;
		for (i = 0; i < length; i++)
		{
			//condition for guessing the right name!!
			if (displayarray[i] == word[i])//if the user guessed name and the word from file matches
				count1++;// increment in the counter
		}
		if (count1 == length)//if the counter increases to the length of the string
		{
			printf("\nYou guessed the word with %d chances left!", 5 - counter);
			printf("\nYou won the game!");
			noofgameswon++;
			printf("Would you like to play again? y for yes /any key else for no");//asking to play agian or not
			again = _getch();
			if (again == 'y'|| again=='Y')
			{
				goto game;
			}
			else if (again != 'y' && again!='Y')
			{
				/*
				As the user didn't want to play more saving his progress in the file
				so writng data in the file
				*/
				fprintf(fpuser, "\nDate: %s", ctime(&t));
				fprintf(fpuser, "%s: %d\n%s: %d\nNumber of games lost: %d", nof, noofgames, nofwon, noofgameswon, noofgames - noofgameswon);
				fflush(fpuser);//clearing the buffer
				rewind(fpuser);//taking the cursor to again at the start of the file
				printf("\nPress Enter to get your stats!");
				_getch();
				printf("\n\nStats for %s:\n", username);//displaying the stats on the screen
				while (!feof(fpuser))//till the end of the file of the user
				{
					c = fgetc(fpuser);
					printf("%c", c);//character by character displaying
				}
				fclose(fpuser);//closing the file of the user
				printf("\nPress Enter to exit the game.");
				_getch();
				return 0;
			}
		}

		printf("\n\nEnter a letter to see if it is part of the word or not:");
		scanf(" %c", &guess);//taking the guess from the user
		system("CLS");
		for (i = 0; i < 5; i++)//till five incorrect guesses
		{
			while (incorrect[i] == guess || toupper(incorrect[i])==guess)// if user has already guessed the letter
			{
				printf("\n\nYou have already guessed this letter. Try another one:");
				scanf(" %c", &guess);//again taking the guess
			}
		}

		count = 0;
		for (i = 0; i < length; i++)//  checking for the right guesses
		{
			/*
			If the name entered by the user 
			is in lower or upper case of the word then mark it as correct
			*/
			if (word[i] == guess || toupper(guess) == word[i] || tolower(guess)==word[i])
			{
				displayarray[i] = word[i];//showing the right guess in the place of the dashes
				count++;//  increment in the counter
			}

		}
		printf("\n\nIncorrect guesses: ");
		if (count == 0)// if the counter didn't get any increment
		{
			incorrect[counter] = guess;//showing the incorrect guess in the place of the dashes
			counter++;// increment in the counter
		}

		printf("\n");
		for (i = 0; i < 5; i++)
		{
			printf("%c", incorrect[i]);// printing the incorrect guess
			printf(" ");
		}

		printf("\n");

		if (counter == 0)// if the word guessed is right then
		{
			sf::Font font1;
			if (!font1.loadFromFile("Stay and Shine.ttf"))
			{
				printf("The file cannot be opened");
			}
			sf::RenderWindow start(sf::VideoMode(620, 480), "HANGMAN");
			sf::RectangleShape stand1(sf::Vector2f(220, 20));
			stand1.rotate(90);
			stand1.setPosition(110, 20);
			stand1.setFillColor(sf::Color::White);
			sf::RectangleShape siri1(sf::Vector2f(35, 5));
			siri1.rotate(90);
			siri1.setPosition(180, 20);
			siri1.setFillColor(sf::Color::White);
			sf::RectangleShape linea(sf::Vector2f(150, 5));
			linea.rotate(0);
			linea.setPosition(110, 20);
			sf::Text text1;
			// select the font
			text1.setFont(font1); // font is a sf::Font

			// set the string to display
			text1.setString("Going Great\n\n Press enter to continue");
			// set the character size
			text1.setCharacterSize(40); // in pixels, not points!

			// set the color
			text1.setFillColor(sf::Color::Red);

			// set the text style
			text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
			text1.setPosition(50, 250);
			while (start.isOpen())
			{
				sf::Event event;
				while (start.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::Closed:
						start.close();
						break;
					case sf::Event::KeyPressed:
						if (event.key.code == sf::Keyboard::Enter)
						{
							start.close();
						}
						break;

					}

				}

				start.clear();
				start.draw(text1);
				start.draw(stand1);
				start.draw(linea);
				start.draw(siri1);
				start.display();
			}

		}

		if (counter == 1)// if one word guessed is wrong
		{
			sf::RenderWindow show(sf::VideoMode(620, 480), "HANGMAN");
			sf::Font font;
			if (!font.loadFromFile("Stay and Shine.ttf"))
			{
				printf("The file cannot be opened");
			}
			sf::Text text;
			// select the font
			text.setFont(font); // font is a sf::Font

			// set the string to display
			text.setString("Save Him!!\n\n Press enter to continue");
			// set the character size
			text.setCharacterSize(40); // in pixels, not points!

			// set the color
			text.setFillColor(sf::Color::Red);

			// set the text style
			text.setStyle(sf::Text::Bold | sf::Text::Underlined);
			text.setPosition(50, 250);
			sf::RectangleShape stand(sf::Vector2f(220, 20));
			stand.rotate(90);
			stand.setPosition(110, 20);
			stand.setFillColor(sf::Color::White);
			sf::RectangleShape siri(sf::Vector2f(35, 5));
			siri.rotate(90);
			siri.setPosition(180, 20);
			sf::CircleShape shape(25);
			shape.setPosition(153, 56);
			shape.setFillColor(sf::Color::Red);
			sf::RectangleShape linesiri(sf::Vector2f(150, 5));
			linesiri.rotate(0);
			linesiri.setPosition(110, 20);
			while (show.isOpen())
			{
				sf::Event event;
				while (show.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::Closed:
						show.close();
						break;
					case sf::Event::KeyPressed:
						if (event.key.code == sf::Keyboard::Enter)
						{
							show.close();
						}
						break;


					}

				}

				show.clear();
				show.draw(shape);
				show.draw(linesiri);
				show.draw(stand);
				show.draw(siri);
				show.draw(text);
				show.display();
			}
		}
		if (counter == 2)// if two words guessed are wrong
		{
			sf::RenderWindow show1(sf::VideoMode(620, 480), "HANGMAN");
			sf::Font font2;
			if (!font2.loadFromFile("Stay and Shine.ttf"))
			{
				printf("The file cannot be opened");
			}




			sf::Text text2;
			// select the font
			text2.setFont(font2); // font is a sf::Font

			// set the string to display
			text2.setString("Save Him!!\n\nPress enter to continue");
			// set the character size
			text2.setCharacterSize(40); // in pixels, not points!

			// set the color
			text2.setFillColor(sf::Color::Red);

			// set the text style
			text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
			text2.setPosition(50, 250);
			sf::RectangleShape stand2(sf::Vector2f(220, 20));
			stand2.rotate(90);
			stand2.setPosition(110, 20);
			stand2.setFillColor(sf::Color::White);
			sf::RectangleShape siri2(sf::Vector2f(35, 5));
			siri2.rotate(90);
			siri2.setPosition(180, 20);
			sf::CircleShape shape1(25);
			shape1.setPosition(153, 56);
			shape1.setFillColor(sf::Color::Red);
			sf::RectangleShape linesiri1(sf::Vector2f(150, 5));
			linesiri1.rotate(0);
			linesiri1.setPosition(110, 20);
			sf::RectangleShape body(sf::Vector2f(70, 5));
			body.rotate(90);
			body.setPosition(180, 105);
			while (show1.isOpen())
			{
				sf::Event event;
				while (show1.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::Closed:
						show1.close();
						break;
					case sf::Event::KeyPressed:
						if (event.key.code == sf::Keyboard::Enter)
						{
							show1.close();
						}
						break;


					}

				}

				show1.clear();
				show1.draw(shape1);
				show1.draw(linesiri1);
				show1.draw(stand2);
				show1.draw(siri2);
				show1.draw(text2);
				show1.draw(body);
				show1.display();
			}
		}
		if (counter == 3)// if the third word guessed is wrong
		{
			sf::RenderWindow show2(sf::VideoMode(620, 480), "HANGMAN");
			sf::Font font3;
			if (!font3.loadFromFile("Stay and Shine.ttf"))
			{
				printf("The file cannot be opened");
			}




			sf::Text text3;
			// select the font
			text3.setFont(font3); // font is a sf::Font

			// set the string to display
			text3.setString("Save Him!!\n\nPress enter to continue");
			// set the character size
			text3.setCharacterSize(40); // in pixels, not points!

			// set the color
			text3.setFillColor(sf::Color::Red);

			// set the text style
			text3.setStyle(sf::Text::Bold | sf::Text::Underlined);
			text3.setPosition(50, 250);
			sf::RectangleShape stand3(sf::Vector2f(220, 20));
			stand3.rotate(90);
			stand3.setPosition(110, 20);
			stand3.setFillColor(sf::Color::White);
			sf::RectangleShape siri3(sf::Vector2f(35, 5));
			siri3.rotate(90);
			siri3.setPosition(180, 20);
			sf::CircleShape shape2(25);
			shape2.setPosition(153, 56);
			shape2.setFillColor(sf::Color::Red);
			sf::RectangleShape linesiri2(sf::Vector2f(150, 5));
			linesiri2.rotate(0);
			linesiri2.setPosition(110, 20);
			sf::RectangleShape body1(sf::Vector2f(70, 5));
			body1.rotate(90);
			body1.setPosition(180, 105);
			sf::RectangleShape lefthand(sf::Vector2f(50, 5));
			lefthand.rotate(45);
			lefthand.setPosition(180, 105);
			while (show2.isOpen())
			{
				sf::Event event;
				while (show2.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::Closed:
						show2.close();
						break;
					case sf::Event::KeyPressed:
						if (event.key.code == sf::Keyboard::Enter)
						{
							show2.close();
						}
						break;

					}

				}

				show2.clear();
				show2.draw(shape2);
				show2.draw(linesiri2);
				show2.draw(stand3);
				show2.draw(siri3);
				show2.draw(text3);
				show2.draw(body1);
				show2.draw(lefthand);
				show2.display();
			}

		}

		if (counter == 4)// if the incorrect guesses are now 4
		{
			sf::RenderWindow show3(sf::VideoMode(620, 480), "HANGMAN");
			sf::Font font4;
			if (!font4.loadFromFile("Stay and Shine.ttf"))
			{
				printf("The file cannot be opened");
			}




			sf::Text text4;
			// select the font
			text4.setFont(font4); // font is a sf::Font

			// set the string to display
			text4.setString("One chance left!!\n\nPress enter to continue");
			// set the character size
			text4.setCharacterSize(40); // in pixels, not points!

			// set the color
			text4.setFillColor(sf::Color::Red);

			// set the text style
			text4.setStyle(sf::Text::Bold | sf::Text::Underlined);
			text4.setPosition(50, 250);
			sf::RectangleShape stand4(sf::Vector2f(220, 20));
			stand4.rotate(90);
			stand4.setPosition(110, 20);
			stand4.setFillColor(sf::Color::White);
			sf::RectangleShape siri4(sf::Vector2f(35, 5));
			siri4.rotate(90);
			siri4.setPosition(180, 20);
			sf::CircleShape shape3(25);
			shape3.setPosition(153, 56);
			shape3.setFillColor(sf::Color::Red);
			sf::RectangleShape linesiri3(sf::Vector2f(150, 5));
			linesiri3.rotate(0);
			linesiri3.setPosition(110, 20);
			sf::RectangleShape body2(sf::Vector2f(70, 5));
			body2.rotate(90);
			body2.setPosition(180, 105);
			sf::RectangleShape lefthand1(sf::Vector2f(50, 5));
			lefthand1.rotate(45);
			lefthand1.setPosition(180, 105);
			sf::RectangleShape righthand(sf::Vector2f(50, 5));
			righthand.rotate(135);
			righthand.setPosition(180, 108);
			while (show3.isOpen())
			{
				sf::Event event;
				while (show3.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::Closed:
						show3.close();
						break;
					case sf::Event::KeyPressed:
						if (event.key.code == sf::Keyboard::Enter)
						{
							show3.close();
						}
						break;





					}

				}

				show3.clear();
				show3.draw(shape3);
				show3.draw(linesiri3);
				show3.draw(stand4);
				show3.draw(siri4);
				show3.draw(text4);
				show3.draw(body2);
				show3.draw(lefthand1);
				show3.draw(righthand);
				show3.display();
			}
		}
		if (counter == 5)// if the incorrect guesses are five
		{
			sf::RenderWindow show4(sf::VideoMode(620, 480), "HANGMAN");
			sf::Font font5;
			if (!font5.loadFromFile("Stay and Shine.ttf"))
			{
				printf("The file cannot be opened");
			}




			sf::Text text5;
			// select the font
			text5.setFont(font5); // font is a sf::Font

			// set the string to display
			text5.setString(" Ahhh!! You can't save him!!\n\n Press escape to close window");
			// set the character size
			text5.setCharacterSize(40); // in pixels, not points!

			// set the color
			text5.setFillColor(sf::Color::Red);

			// set the text style
			text5.setStyle(sf::Text::Bold | sf::Text::Underlined);
			text5.setPosition(50, 250);
			sf::RectangleShape stand5(sf::Vector2f(220, 20));
			stand5.rotate(90);
			stand5.setPosition(110, 20);
			stand5.setFillColor(sf::Color::White);
			sf::RectangleShape siri5(sf::Vector2f(35, 5));
			siri5.rotate(90);
			siri5.setPosition(180, 20);
			sf::CircleShape shape4(25);
			shape4.setPosition(153, 56);
			shape4.setFillColor(sf::Color::Red);
			sf::RectangleShape linesiri4(sf::Vector2f(150, 5));
			linesiri4.rotate(0);
			linesiri4.setPosition(110, 20);
			sf::RectangleShape body3(sf::Vector2f(70, 5));
			body3.rotate(90);
			body3.setPosition(180, 105);
			sf::RectangleShape lefthand2(sf::Vector2f(50, 5));
			lefthand2.rotate(45);
			lefthand2.setPosition(180, 105);
			sf::RectangleShape righthand1(sf::Vector2f(50, 5));
			righthand1.rotate(135);
			righthand1.setPosition(180, 108);
			sf::RectangleShape leg(sf::Vector2f(50, 5));
			leg.rotate(45);
			leg.setPosition(180, 168);
			sf::RectangleShape leg1(sf::Vector2f(50, 5));
			leg1.rotate(135);
			leg1.setPosition(180, 172);
			while (show4.isOpen())
			{
				sf::Event event;
				while (show4.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::Closed:
						show4.close();
						break;
					case sf::Event::KeyPressed:
						if (event.key.code == sf::Keyboard::Escape)
						{
							show4.close();
						}
						break;





					}

				}

				show4.clear();
				show4.draw(shape4);
				show4.draw(linesiri4);
				show4.draw(stand5);
				show4.draw(siri5);
				show4.draw(text5);
				show4.draw(body3);
				show4.draw(lefthand2);
				show4.draw(righthand1);
				show4.draw(leg);
				show4.draw(leg1);
				show4.display();
			}

			printf("The word was %s.", word);// showing the exact name
			printf("\nYou lost the game.\n");//lost the game
			printf("\nWould you like to play again? y for yes /any key to leave");
			again = _getch();
			if (again == 'y' || again=='Y')
				goto game;
			else
			{
				/*Writing the stats into the file*/
				fprintf(fpuser, "\nDate: %s", ctime(&t));
				fprintf(fpuser, "%s: %d\n%s: %d\nNumber of games lost: %d", nof, noofgames, nofwon, noofgameswon, noofgames - noofgameswon);
				fflush(fpuser);
				rewind(fpuser);//taking the cursor at the begining of the fike
				printf("\n\nStats for %s:\n", username);
				while (!feof(fpuser))
				{
					c = fgetc(fpuser);
					printf("%c", c);//displaying the stats
				}
				fclose(fpuser);//  closing the file
				printf("\nPress Enter to exit the game.");
				_getch();
				return 0;
			}
		}
	}

}

int pick()
{
	/* function to take the input from user in the  categories*/
	int pick;
	printf("\nEnter the choice : ");
	scanf("%d", &pick);
	return pick;
}
void instructions(char arr[50])
{
	/* Basic intro of the game*/
	int i, length = strlen(arr);
	for (i = 0; i < length; i++)
		arr[i] = toupper(arr[i]);
	printf("\t\t\t\tHello %s!", arr);
	printf("\n\t\t\t Welcome to our Hangman Game!\n");
	printf("\n");
	printf("\n\t\t\tEnjoy the Game!\n");
}
void catg(void)
{
	/* Showing the categories to select*/
	printf("\n\n");
	printf("You can choose to guess a word from one of the following categories:  \n");
	printf("1. Movies \t\t2. Countries\t3. Vegetables\n");
	printf("4. Fruits\t\t5. Animals\t6. Sports\n");
	printf("7. Pakistani Cities");
	printf("\nPress the number of the category you'd like to guess a word from:");
}