/*   Programmed by:    Bautista, Samantha Michaela O.   S16B

     Description:     This is an AI intelligent program that has 2 modes (Manual and Automated). The Agent must meet her grandma
                    with a flower, a bread and the Woodsman in order to win. If the Agent goes to a location of a pit then the program will end
                    and you lose, if the Agent meet the Wolf, if she has a bread then the Wolf will eat the bread then the Agent will live, else the 
                    Wolf will eat the Agent then the program will end and you lose. The Agent can use 3 moves (Rotate, Sense, and Forward).

     Last modified:    February 7, 2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>



int Grid(int, int, int);
int Arrow(int,char);	
int LPit(int,int,int,int,int,char,int,int,int,int,int,int,int,int,int,int,int,int,int,
		  int,int,int,int,int,int,int,int,int,int,int,int,int,int);		  
int Sense(int,int,int,int,char,char,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,
	int,int,int,int,int,int);	  
int PrintResults(int,int,int,char[],char[]);		  

/*
	This Function Displays the raw Grid without the Elements
	
	@param (int) line is the row of the grid
	@param (int) i is the column of the grid
	@param (int) nGrid is the user input for the size of the box
	
*/
int Grid(int line, int i, int nGrid)  //for the size of the grid/box
	{
		for (line=1; line<=nGrid; line++)
		{
		 	
			
			for (i=1;  i <= nGrid; i++ )
				
				
				printf("_ ");
				printf("\n");
		}
	}
	
/*
	This Function Displays the description and elements of the grid
	
	@param (int) nNum_Rotate is number of rotate the Agent has done
	@param (int) nNum_Sense is the number of sense the Agent has done
	@param (int) nNum_Forward is the number of forward the Agent has done
	@param (char[20]) cSenses is what the Agent has sense
	@param (char[10]) cRotate is move the Agent has done
	
*/	
int PrintResults (int nNum_Rotate, int nNum_Sense, int nNum_Forward, char cSenses[20], char cRotate[10])
{
	

	printf("Rotate: %d %s ",nNum_Rotate, cRotate);
	printf("Sense: %d %s ", nNum_Sense, cSenses);
	printf("Forward: %d\n", nNum_Forward);
	printf("Legend: ^ > < v - Agent(LRRH),\n");
	printf("P-pit, F-flower, W-Wolf, B-\n");
	printf("Bakeshop, M-Woodsman, G-Granny\n");
	printf("\n");
}

/*
	This Function gives the instruction, will the Agent turn left or turn right
	
	@param (int) Move is number which will indicate if the Agent will turn left or turn right
	@param (char) cLRRH is the before and after arrow  
	
	@return cLRRH returns the updated arrow
	
	
*/
int Arrow (int Move, char cLRRH)
{
	
	if (Move % 4 != 0) //left
	{
		if (cLRRH == '<') 
			{
				cLRRH = 'v';
			}
			else if (cLRRH == '^') 
			{
				cLRRH = '<';
			}
			else if (cLRRH == '>') 
			{
				cLRRH = '^';
			}
			else if (cLRRH == 'v') 
			{
				cLRRH = '>';
			}
			
	}
	
	else if (Move % 4 == 0)// right 
	{
		if (cLRRH == '<') 
			{
				cLRRH = '^';
			
			}
			else if (cLRRH == '^') 
			{
				cLRRH = '>';
			
			}
			else if (cLRRH == '>') 
			{
				cLRRH = 'v';
			
			}
			else if (cLRRH == 'v') 
			{
				cLRRH = '<';
			
			}
			
	}
	return cLRRH;
}

/*
	This Function senses what is in front of the Agent
	
	@param (int) X, Y is the location of the sense
	@param (int) nGrid is limitation of the sense
	@param (char) cLRRH is the arrow of the Agent
	@param (char) cSense is the indicator of the element in front of the Agent
	@param (int) rowP1, rowP2, rowP3  is the location of rows of the Pits
	@param (int) columnP1, columnP2, columnP3  is the location of columns of the Pits
	@param (int) rowF1, rowF2, rowF3  is the location of rows of the Flowers
	@param (int) columnF1, columnF2, columnF3  is the location of columns of the Flowers
	@param (int) rowB1, rowB2, rowB3  is the location of rows of the Bakeshops
	@param (int) columnB1, columnB2, columnB3  is the location of columns of the Bakeshop
	@param (int) rowW1 is the location of row of the Wolf
	@param (int) columnW1 is the location of column of the Wolf
	@param (int) rowM1 is the location of row of the Woodsman
	@param (int) columnM1 is the location of column of the Woodsman
	@param (int) rowG1 is the location of row of the Granny
	@param (int) columnG1 is the location of column of the Granny
	
	@return cSense returns what is in front of the Agent
*/
int Sense(int Y, int X, int line, int nGrid, char cLRRH, char cSense, int rowP1, int columnP1, int rowP2, int columnP2, int rowP3, int columnP3,
			int rowF1, int columnF1, int rowF2, int columnF2, int rowF3,  int columnF3, int rowB1, int columnB1, int rowB2, int columnB2, 							
			int rowB3, int columnB3, int rowW1, int columnW1, int rowM1, int columnM1, int rowG1, int columnG1) 
{
	if (cLRRH == '^') 
		{
			if (Y == 1)
			{
				cSense = 'N';  // None
			}
			else 
			{
				Y--;
				
				if ((Y == rowP1 && X == columnP1)  || (Y == rowP2 && X == columnP2 )  || (Y == rowP3 && X == columnP3))
				{
					cSense = 'D'; // Death
				} 
				else if ((Y == rowF1 && X == columnF1) || (Y == rowF2 && X == columnF2)  || (Y == rowF3 && X == columnF3)) 
				{
					cSense = 'C'; //scent
				}
				else if ((Y == rowB1 && X == columnB1) || (Y == rowB2 && X == columnB2)  || (Y == rowB3 && X == columnB3))
				{
					cSense = 'H'; //heat
				}
				else if (Y == rowW1 && X == columnW1) 
				{
					cSense = 'O'; //howl
				}
				else if (Y == rowM1 && X == columnM1) 
				{
					cSense = 'S'; //sound
				}
				else if (Y == rowG1 && X == columnG1) 
				{
					cSense = 'L'; //grandma
				} 
				else
				{
					cSense = 'N';	//None
				} 
			}
		}
		
		
	if (cLRRH == '>') 
		{
			if (X == nGrid)
			{
				cSense = 'N';  // None
			}
			else 
			{
				X++;
				
				if ( (Y == rowP1 && X == columnP1) || (Y == rowP2 && X == columnP2 )  || (Y == rowP3 && X == columnP3))
				{
					cSense = 'D'; // Death
				} 
				else if ((Y == rowF1 && X == columnF1) || (Y == rowF2 && X == columnF2)  || (Y == rowF3 && X == columnF3)) 
				{
					cSense = 'C'; //scent
				}
				else if ((Y == rowB1 && X == columnB1) || (Y == rowB2 && X == columnB2)  || (Y == rowB3 && X == columnB3))
				{
					cSense = 'H'; //heat
				}
				else if (Y == rowW1 && X == columnW1) 
				{
					cSense = 'O'; //howl
				}
				else if (Y == rowM1 && X == columnM1) 
				{
					cSense = 'S'; //sound
				}
				else if (Y == rowG1 && X == columnG1) 
				{
					cSense = 'L'; //grandma
				} 
				else
				{
					cSense = 'N';	//None
				} 
			}
		}
	
	
	
	if (cLRRH == 'v') 
		{
			if (Y == nGrid)
			{
				cSense = 'N';  // None
			}
			else 
			{
				Y++;
				
				if ( (Y == rowP1 && X == columnP1) || (Y == rowP2 && X == columnP2 )  || (Y == rowP3 && X == columnP3))
				{
					cSense = 'D'; // Death
				} 
				else if ((Y == rowF1 && X == columnF1) || (Y == rowF2 && X == columnF2)  || (Y == rowF3 && X == columnF3)) 
				{
					cSense = 'C'; //scent
				}
				else if ((Y == rowB1 && X == columnB1) || (Y == rowB2 && X == columnB2)  || (Y == rowB3 && X == columnB3))
				{
					cSense = 'H'; //heat
				}
				else if (Y == rowW1 && X == columnW1) 
				{
					cSense = 'O'; //howl
				}
				else if (Y == rowM1 && X == columnM1) 
				{
					cSense = 'S'; //sound
				}
				else if (Y == rowG1 && X == columnG1) 
				{
					cSense = 'L'; //grandma
				} 
				else
				{
					cSense = 'N';	//None
				} 
			}
		}
		
		
	if (cLRRH == '<') 
		{
			if (X == 1)
			{
				cSense = 'N';  // None
			}
			else 
			{
				X--;
				
				if ( (Y == rowP1 && X == columnP1) || (Y == rowP2 && X == columnP2 )  || (Y == rowP3 && X == columnP3))
				{
					cSense = 'D'; // Death
				} 
				else if ((Y == rowF1 && X == columnF1) || (Y == rowF2 && X == columnF2)  || (Y == rowF3 && X == columnF3)) 
				{
					cSense = 'C'; //scent
				}
				else if ((Y == rowB1 && X == columnB1) || (Y == rowB2 && X == columnB2)  || (Y == rowB3 && X == columnB3))
				{
					cSense = 'H'; //heat
				}
				else if (Y == rowW1 && X == columnW1) 
				{
					cSense = 'O'; //howl
				}
				else if (Y == rowM1 && X == columnM1) 
				{
					cSense = 'S'; //sound
				}
				else if (Y == rowG1 && X == columnG1) 
				{
					cSense = 'L'; //grandma
				} 
				else
				{
					cSense = 'N';	//None
				} 
			}
		}
	return cSense;
}

/*
	This Function displays the grid with the location of each elements
	
	@param (int) line is the row 
	@param (int) i is the column 
	@param (int) nGrid is limitation of the sense
	@param (char) cLRRH is the arrow of the Agent
	@param (char) cSense is the indicator of the element in front of the Agent
	@param (int) rowP1, rowP2, rowP3  is the location of rows of the Pits
	@param (int) columnP1, columnP2, columnP3  is the location of columns of the Pits
	@param (int) rowF1, rowF2, rowF3  is the location of rows of the Flowers
	@param (int) columnF1, columnF2, columnF3  is the location of columns of the Flowers
	@param (int) rowB1, rowB2, rowB3  is the location of rows of the Bakeshops
	@param (int) columnB1, columnB2, columnB3  is the location of columns of the Bakeshop
	@param (int) rowW1 is the location of row of the Wolf
	@param (int) columnW1 is the location of column of the Wolf
	@param (int) rowM1 is the location of row of the Woodsman
	@param (int) columnM1 is the location of column of the Woodsman
	@param (int) rowG1 is the location of row of the Granny
	@param (int) columnG1 is the location of column of the Granny
	
	@return nothing
*/
int LPit(int line, int i, int nGrid, int X, int Y, char cLRRH, 
		 int rowP1, int columnP1, int rowP2, int columnP2, 							
		 int rowP3, int columnP3, int Pit, int rowF1, 								
		 int columnF1, int rowF2, int columnF2, int rowF3, 						
		 int columnF3, int Flower, int rowB1, 						
		 int columnB1, int rowB2, int columnB2, 							
		 int rowB3, int columnB3, int Bakeshop,
		 int rowW1, int columnW1, int rowM1, int columnM1,
		 int rowG1, int columnG1)

	{
			
        for (line=1; line<=nGrid; line++)
        {


            for (i=1; i <= nGrid; i++ )

      			 if ((Pit <= 3) && (Flower <= 3) && (Bakeshop <= 3))
				  	{
				  	
				  	if ((line == Y) && (i == X))
               			{
               				printf("%c ", cLRRH);
						}	
				  	else if ((line == rowP1 && i == columnP1) || (line == rowP2 && i == columnP2) || (line == rowP3 && i == columnP3))
					  	{
                 			 printf("P ");
               			}
               		else if ((line == rowF1 && i == columnF1) || (line == rowF2 && i == columnF2) || (line == rowF3 && i == columnF3))
					  	{
                 			 printf("F ");
               			}
               		else if ((line == rowB1 && i == columnB1) || (line == rowB2 && i == columnB2) || (line == rowB3 && i == columnB3))
					  	{
                 			 printf("B ");
               			}
					else if (line == rowW1 && i == columnW1)
						{
							printf ("W ");
						}
					else if (line == rowM1 && i == columnM1)
						{
							printf ("M ");
						}
					else if (line == rowG1 && i == columnG1)
						{
							printf ("G ");
						}
               		 else
						{
                			printf("_ ");
               			}
					}
				
      		printf("\n");	
        }
        

    }


int main()
{

    
    int nGrid; // this is the size of the grid
    int i, line;
    int Number_Of_Pits;
    int Location_of_Pit_row_1;
    int Location_of_Pit_column_1;
    int Location_of_Pit_row_2;
    int Location_of_Pit_column_2;
    int Location_of_Pit_row_3;
    int Location_of_Pit_column_3;
    int Number_Of_Flower;
    int Location_of_Flower_row_1;
    int Location_of_Flower_column_1;
    int Location_of_Flower_row_2;
    int Location_of_Flower_column_2;
    int Location_of_Flower_row_3;
    int Location_of_Flower_column_3;
    int Number_Of_Bakeshop;
    int Location_of_Bakeshop_row_1;
    int Location_of_Bakeshop_column_1;
    int Location_of_Bakeshop_row_2;
    int Location_of_Bakeshop_column_2;
    int Location_of_Bakeshop_row_3;
    int Location_of_Bakeshop_column_3;
    int Wolf;
    int Location_of_Wolf_row;
	int Location_of_Wolf_column;
	int Woodsman;
	int Location_of_Woodsman_row;
	int Location_of_Woodsman_column;
	int Granny;
	int Location_of_Granny_row;
	int Location_of_Granny_column;
	
    
    int Pit, Flower, Bakeshop;
    int rowP1, rowP2, rowP3;
	int columnP1, columnP2, columnP3;
	int rowF1, rowF2, rowF3;
	int columnF1, columnF2, columnF3;
	int rowB1, rowB2, rowB3;						
	int	columnB1, columnB2, columnB3; 							
	int	rowW1,  columnW1;
	int	rowM1,  columnM1;
	int	rowG1,  columnG1;
	
	//Number of actions
	int nNum_Rotate = 0;
	int nNum_Sense = 0;
	int nNum_Forward = 0;
	
	//String to indicate
	char cRotate [10];
	char cLRotate [] = "(left)";
	char cRRotate [] = "(right)";
	char cNRotate [] = "";
	
	char cSenses [20]; 
	char cPSenses [] = "(Breeze)";
	char cWSenses [] = "(Howl)";
	char cFSenses [] = "(Scent)";
	char cBSenses [] = "(Heat)";
	char cMSenses [] = "(Sound)";
	char cGSenses [] = "(Light)";
	char cNSenses [] = "(none)";
	char cbSenses [] = "";
	
	int Move = 0;
	int X = 1;
	int Y = 1;
	char cLRRH = '^'; // little Red Riding Hood	
    int a = 1;
    char cSense = 'n';
    int nMode;
    
    char cHave_Bread = 'n'; //none
    char cHave_Flower = 'n';  // none
    char cHave_Woodsman = 'n'; // none

		do
		{
        printf("Enter the Size of Your Box: ");
        scanf("%d", &nGrid);
        
        	if (nGrid < 8)
        		printf("Your box is too small (min of 8x8)\n");
        	else if (nGrid > 15)
        		printf("You have exceeded the size of Grid (max of 15x15)\n");
   		}
   		while ((nGrid < 8) || (nGrid > 15));

    Grid(line, i, nGrid); 
		
   		printf("\nEnter the Location of the Elements\n");
		
            do 
            {

                printf("Enter the Number of Pits: ");
                scanf("%d", &Number_Of_Pits);

                if (Number_Of_Pits > 3 )
                	printf("You exceeded the Number of Pits (max of 3)\n");
                else if (Number_Of_Pits == 0)
                	printf("You must put a Number\n");
            }
            while ((Number_Of_Pits > 3) || (Number_Of_Pits == 0));


        if ( Number_Of_Pits == 1 )
            {

            printf("Enter the Location of the Pit #1 (row column): ");
            scanf("%d%d", &Location_of_Pit_row_1, &Location_of_Pit_column_1);
		
            }
		
        else if ( Number_Of_Pits == 2 )
            {
            printf("Enter the Location of the Pit #1 (row column): ");
            scanf("%d%d", &Location_of_Pit_row_1, &Location_of_Pit_column_1);
            printf("Enter the Location of the Pit #2 (row column): ");
            scanf("%d%d", &Location_of_Pit_row_2, &Location_of_Pit_column_2 );
            }
            
        else if ( Number_Of_Pits == 3 )
            {
            printf("Enter the Location of the Pit #1 (row column): ");
            scanf("%d%d", &Location_of_Pit_row_1, &Location_of_Pit_column_1);
            printf("Enter the Location of the Pit #2 (row column): ");
            scanf("%d%d", &Location_of_Pit_row_2, &Location_of_Pit_column_2 );
            printf("Enter the Location of the Pit #3 (row column): ");
            scanf("%d%d", &Location_of_Pit_row_3, &Location_of_Pit_column_3 );
            }


		do //user input the number of flowers
            {

                printf("Enter the Number of Flowers: ");
                scanf("%d", &Number_Of_Flower);

                if (Number_Of_Flower > 3 )
               		printf("You exceeded the Number of Flowers (max of 3)\n");
                else if (Number_Of_Flower == 0)
                	printf("You must put a Number\n");
                
            }
            while ((Number_Of_Flower > 3) || (Number_Of_Flower == 0));
            
        
        if ( Number_Of_Flower == 1 )
            {

            printf("Enter the Location of the Flower #1 (row column): ");
            scanf("%d%d", &Location_of_Flower_row_1, &Location_of_Flower_column_1);
	
		
            }
		
        else if ( Number_Of_Flower == 2 )
            {
            printf("Enter the Location of the Flower #1 (row column): ");
            scanf("%d%d", &Location_of_Flower_row_1, &Location_of_Flower_column_1);
            printf("Enter the Location of the Flower #2 (row column): ");
            scanf("%d%d", &Location_of_Flower_row_2, &Location_of_Flower_column_2 );
          
           }
            
        else if ( Number_Of_Flower == 3 )
            {
            printf("Enter the Location of the Flower #1 (row column): ");
            scanf("%d%d", &Location_of_Flower_row_1, &Location_of_Flower_column_1);
            printf("Enter the Location of the Flower #2 (row column): ");
            scanf("%d%d", &Location_of_Flower_row_2, &Location_of_Flower_column_2 );
            printf("Enter the Location of the Flower #3 (row column): ");
            scanf("%d%d", &Location_of_Flower_row_3, &Location_of_Flower_column_3 );
         
            }
        
        do //user input the number of BakeShop
            {

                printf("Enter the Number of Bakeshops: ");
                scanf("%d", &Number_Of_Bakeshop);

                if (Number_Of_Bakeshop > 3 )
             	   printf("You exceeded the Number of Bakeshop (max of 3)\n");
                else if (Number_Of_Bakeshop == 0)
               		printf("You must put a Number\n");
            }
            while ((Number_Of_Bakeshop > 3) || (Number_Of_Bakeshop == 0));
			
		
		 
        if ( Number_Of_Bakeshop == 1 )
            {

            printf("Enter the Location of the Bakeshop #1 (row column): ");
            scanf("%d%d", &Location_of_Bakeshop_row_1, &Location_of_Bakeshop_column_1);
	
		
            }
		
        else if ( Number_Of_Bakeshop == 2 )
            {
            printf("Enter the Location of the Bakeshop #1 (row column): ");
            scanf("%d%d", &Location_of_Bakeshop_row_1, &Location_of_Bakeshop_column_1);
            printf("Enter the Location of the Bakeshop #2 (row column): ");
            scanf("%d%d", &Location_of_Bakeshop_row_2, &Location_of_Bakeshop_column_2 );
          
           }
            
        else if ( Number_Of_Bakeshop == 3 )
            {
            printf("Enter the Location of the Bakeshop #1 (row column): ");
            scanf("%d%d", &Location_of_Bakeshop_row_1, &Location_of_Bakeshop_column_1);
            printf("Enter the Location of the Bakeshop #2 (row column): ");
            scanf("%d%d", &Location_of_Bakeshop_row_2, &Location_of_Bakeshop_column_2 );
            printf("Enter the Location of the Bakeshop #3 (row column): ");
            scanf("%d%d", &Location_of_Bakeshop_row_3, &Location_of_Bakeshop_column_3 );
         
            }	    
		printf("\n");
		printf("Enter the Location of Wolf (row column): ");
        scanf("%d%d", &Location_of_Wolf_row, &Location_of_Wolf_column);
		printf("Enter the Location of Woodsman (row column): ");
        scanf("%d%d", &Location_of_Woodsman_row, &Location_of_Woodsman_column);
	    printf("Enter the Location of Granny (row column): ");
        scanf("%d%d", &Location_of_Granny_row, &Location_of_Granny_column);  
        printf("\n");
        

	LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1, Location_of_Pit_row_2, Location_of_Pit_column_2, 
   		Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
		Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
		Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
		Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column, Location_of_Woodsman_row, Location_of_Woodsman_column,
		Location_of_Granny_row, Location_of_Granny_column ); 
		
		strcpy(cRotate, cNRotate);
		strcpy (cSenses, cbSenses);
		
		PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
		getch();
		
		printf("\n");
		do
        {
    	    printf("Enter Mode (1) Manual, (2) Automated, (3) Random: ");
    	    scanf("%d", &nMode);
    	    
    	    if ((nMode <= 0) || (nMode >= 4))
    	    {
    	    	printf("Input is Invalid\n");
    		}
		} 
		while ((nMode <= 0) || (nMode >= 4));
		printf("\n");
	
	//change for shorter code
	rowP1 = Location_of_Pit_row_1;
	rowP2 = Location_of_Pit_row_2;
	rowP3 = Location_of_Pit_row_3;
	columnP1 = Location_of_Pit_column_1;
	columnP2 = Location_of_Pit_column_2;
	columnP3 = Location_of_Pit_column_3;
	rowF1 = Location_of_Flower_row_1;
	rowF2 = Location_of_Flower_row_2;
	rowF3 = Location_of_Flower_row_3;
	columnF1 = Location_of_Flower_column_1;
	columnF2 = Location_of_Flower_column_2;
	columnF3 = Location_of_Flower_column_3;
 	rowB1 = Location_of_Bakeshop_row_1;
	rowB2 = Location_of_Bakeshop_row_2;
	rowB3 =	Location_of_Bakeshop_row_3;
	columnB1 = Location_of_Bakeshop_column_1;
	columnB2 = Location_of_Bakeshop_column_2;
	columnB3 = Location_of_Bakeshop_column_3;
	rowW1 =  Location_of_Wolf_row;
	columnW1 = Location_of_Wolf_column;
	rowM1 = Location_of_Woodsman_row;
	columnM1 = Location_of_Woodsman_column;
	rowG1 = Location_of_Granny_row;
	columnG1 = Location_of_Granny_column;
	

if (nMode == 1) //Manual
{
	do
	{
		
		if ( ((X == 1) && (Y == 1)) && (nNum_Rotate == 0) )
			{
				cLRRH = '>';
				nNum_Rotate++;
				Move++;
				
			LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   				Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
				Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
				Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
				Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
				Location_of_Granny_row, Location_of_Granny_column ); 
		
				strcpy(cRotate, cRRotate);
				strcpy(cSenses, cbSenses);
				
				PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);	
				getch();	
			}
		
		else if ( (cSense == 'D') || (cSense == 'O'))
			{
				if ((cLRRH == '<') || (cLRRH == '>'))
				{	
					if (cLRRH == '<')
					{
						strcpy(cRotate, cLRotate);
						strcpy (cSenses, cbSenses );
						cLRRH = 'v';
					}
					else if (cLRRH == '>')
					{
						cLRRH = 'v';
						strcpy(cRotate, cRRotate);
						strcpy (cSenses, cbSenses );
					}
					
				}
				
				else if ((cLRRH == '^') || (cLRRH == 'v'))
				{
					if (cLRRH == '^')
					{
						cLRRH = '>';
						strcpy(cRotate, cRRotate);
						strcpy (cSenses, cbSenses );	
					}
					else if (cLRRH == 'v')
					{
						cLRRH = '>';
						strcpy(cRotate, cLRotate);
						strcpy (cSenses, cbSenses );
					}
				}
			
				
			nNum_Rotate++;
			Move++;
			
			
			LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   				Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
				Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
				Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
				Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
				Location_of_Granny_row, Location_of_Granny_column ); 
	
			PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
			
			getch();		
			}
		
		else if ((X == 1) && (Y == 1) && (nNum_Rotate >= 1)) // 1
			{
				if (cLRRH == '^')
				{
					cLRRH = '<';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );
					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					getch();	
				}	
				
				else if (cLRRH == '<')
				{
					cLRRH = 'v';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					getch();	
				}	
			}
			
		else  if ((X == nGrid) && (Y == 1))	// 2
			{
				if (cLRRH == '^')
				{
					cLRRH = '<';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					getch();
				}	
				
				else if (cLRRH == '>')
				{
					cLRRH = 'v';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cRRotate);
					strcpy (cSenses, cbSenses );
					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					getch();
				}	
			}
		else if ((X == 1) && (Y == nGrid)) // 3
			{
				if (cLRRH == '<')
				{
					cLRRH = '^';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cRRotate);
					strcpy (cSenses, cbSenses );
				
					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					getch();
				}	
				
				else if (cLRRH == 'v')
				{
					cLRRH = '>';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					getch();
				}
			}
		
		else if ((X == nGrid) && (Y == nGrid)) // 4
			{
				if (cLRRH == 'v')
				{
					cLRRH = '<';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					getch();
				}	
				
				else if (cLRRH == '>')
				{
					cLRRH = '^';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					
					getch();
				}
			}
				
		else 
			{
				if (Move % 4 != 0) //left
				{
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

				}
				else if (Move % 4 == 0) //right
				{
					strcpy(cRotate, cRRotate);
					strcpy (cSenses, cbSenses );
				}
				
				Arrow (Move, cLRRH);
				cLRRH = Arrow (Move, cLRRH);
				nNum_Rotate++;
				Move++;

			LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   				Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
				Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
				Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
				Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
				Location_of_Granny_row, Location_of_Granny_column ); 
		
				PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);	
				getch();		
				
			}
		
		
		
		
	
	
	//sense
	
	do
	{
	cSense = Sense(Y, X, line, nGrid, cLRRH, cSense, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, 
			Location_of_Pit_column_2, Location_of_Pit_row_3, Location_of_Pit_column_3, Location_of_Flower_row_1, 
			Location_of_Flower_column_1, Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, 
			Location_of_Flower_column_3, Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, 
			Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, Location_of_Bakeshop_column_3, Location_of_Wolf_row,
			Location_of_Wolf_column, Location_of_Woodsman_row, Location_of_Woodsman_column, Location_of_Granny_row, Location_of_Granny_column);
		
		if (cSense == 'D')	
		{
			strcpy(cSenses, cPSenses);
			strcpy(cRotate, cNRotate);
		}	
		else if (cSense == 'C')
		{
			strcpy(cSenses, cFSenses);
			strcpy(cRotate, cNRotate);
		}
		else if (cSense == 'H')
		{
			strcpy(cSenses, cBSenses);
			strcpy(cRotate, cNRotate);
		}
		else if (cSense == 'O')
		{
			strcpy(cSenses, cWSenses);
			strcpy(cRotate, cNRotate);
		}
		else if (cSense == 'S')
		{
			strcpy(cSenses, cMSenses);
			strcpy(cRotate, cNRotate);
		}
		else if (cSense == 'L')
		{
			strcpy(cSenses, cGSenses);
			strcpy(cRotate, cNRotate);
		}
		else if (cSense == 'N')
		{
			strcpy(cSenses, cNSenses);
			strcpy(cRotate, cNRotate);
		}
		
		
	nNum_Sense++;
	Move++;
	
	LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   		Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
		Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
		Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
		Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
		Location_of_Granny_row, Location_of_Granny_column ); 
		
	
	PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
	
	getch();
	
	
	//if forward
	
	 if ( (cSense == 'C') || (cSense == 'H') || (cSense == 'S') || (cSense == 'L') || (cSense == 'N'))
		{
			if (cLRRH == '<')
			{
				if ((X > nGrid) || (X == 1))
					{
					X = X - 0;
					}
			
				else
				X--;
				Move++;	
			}
			else if (cLRRH == '>') 
			{
				if((X == nGrid) || (X < 1))
					{
					X = X - 0;
					}
			
				else
				X++;
				Move++;
			}
			else if (cLRRH == '^') 
			{	
				if ((Y > nGrid) || ( Y == 1))	
					{
					Y = Y - 0;
					}
				
				else 												
					Y--;
					Move++;
				
			}
			
			else if (cLRRH == 'v') 
			{
				if ((Y == nGrid) || ( Y < 1))
					{
					Y = Y - 0;
					}
				
				else 	
					Y++;
					Move++;
			}
			nNum_Forward++;
			Move++;
			
			strcpy(cRotate, cNRotate);
			strcpy (cSenses, cbSenses);

			
		LPit(line, i, nGrid, X, Y, cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   			Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
			Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
			Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
			Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
			Location_of_Granny_row, Location_of_Granny_column ); 

	 		PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
	 	;
	 	
	 	if ( ((Y == rowF1) && (X == columnF1)) || ((Y == rowF2) && (X == columnF2)) || ((Y == rowF3) && (X == columnF3)) )
			{
				cHave_Flower = 'y'; // yes
				Move++; 
			}
		
		else if ( ((Y == rowB1) && (X == columnB1)) || ((Y == rowB2) && (X == columnB2)) || ((Y == rowB3) && (X == columnB3)) )
			{
				cHave_Bread = 'y';
				Move++;
			}
	 	else if ((Y == rowM1) && (X == columnM1))
			{
				cHave_Woodsman = 'y';
				Move++;
			}
		
		
		getch();
							
		}
		
	 }
	while((cSense == 'C') || (cSense == 'H') || (cSense == 'S')  ); 
	
	
	}
	while ( ((Y != rowG1) || (X != columnG1)) || (cHave_Flower != 'y') || (cHave_Bread != 'y') || (cHave_Woodsman != 'y'));
}

if (nMode == 2) // Automated
{
	Sleep(1000);
		do
	{
		
		if ( ((X == 1) && (Y == 1)) && (nNum_Rotate == 0) )
			{
				cLRRH = '>';
				nNum_Rotate++;
				Move++;
				
			LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   				Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
				Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
				Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
				Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
				Location_of_Granny_row, Location_of_Granny_column ); 
		
				strcpy(cRotate, cRRotate);
				strcpy(cSenses, cbSenses);
				
				PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);	
				Sleep(1000);	
			}
		
		else if ( (cSense == 'D') || (cSense == 'O'))
			{
				if ((cLRRH == '<') || (cLRRH == '>'))
				{	
					if (cLRRH == '<')
					{
						strcpy(cRotate, cLRotate);
						strcpy (cSenses, cbSenses );
						cLRRH = 'v';
					}
					else if (cLRRH == '>')
					{
						cLRRH = 'v';
						strcpy(cRotate, cRRotate);
						strcpy (cSenses, cbSenses );
					}
					
				}
				
				else if ((cLRRH == '^') || (cLRRH == 'v'))
				{
					if (cLRRH == '^')
					{
						cLRRH = '>';
						strcpy(cRotate, cRRotate);
						strcpy (cSenses, cbSenses );	
					}
					else if (cLRRH == 'v')
					{
						cLRRH = '>';
						strcpy(cRotate, cLRotate);
						strcpy (cSenses, cbSenses );
					}
				}
			
				
			nNum_Rotate++;
			Move++;
			
			
			LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   				Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
				Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
				Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
				Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
				Location_of_Granny_row, Location_of_Granny_column ); 
	
			PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
			
			Sleep(1000);		
			}
		
		else if ((X == 1) && (Y == 1) && (nNum_Rotate >= 1)) // 1
			{
				if (cLRRH == '^')
				{
					cLRRH = '<';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );
					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					Sleep(1000);	
				}	
				
				else if (cLRRH == '<')
				{
					cLRRH = 'v';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					Sleep(1000);	
				}	
			}
			
		else  if ((X == nGrid) && (Y == 1))	// 2
			{
				if (cLRRH == '^')
				{
					cLRRH = '<';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					Sleep(1000);
				}	
				
				else if (cLRRH == '>')
				{
					cLRRH = 'v';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cRRotate);
					strcpy (cSenses, cbSenses );
					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					Sleep(1000);
				}	
			}
		else if ((X == 1) && (Y == nGrid)) // 3
			{
				if (cLRRH == '<')
				{
					cLRRH = '^';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cRRotate);
					strcpy (cSenses, cbSenses );
				
					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					Sleep(1000);
				}	
				
				else if (cLRRH == 'v')
				{
					cLRRH = '>';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					Sleep(1000);
				}
			}
		
		else if ((X == nGrid) && (Y == nGrid)) // 4
			{
				if (cLRRH == 'v')
				{
					cLRRH = '<';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					Sleep(1000);
				}	
				
				else if (cLRRH == '>')
				{
					cLRRH = '^';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					
					Sleep(1000);
				}
			}
				
		else 
			{
				if (Move % 4 != 0) //left
				{
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

				}
				else if (Move % 4 == 0) //right
				{
					strcpy(cRotate, cRRotate);
					strcpy (cSenses, cbSenses );
				}
				
				Arrow (Move, cLRRH);
				cLRRH = Arrow (Move, cLRRH);
				nNum_Rotate++;
				Move++;

			LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   				Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
				Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
				Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
				Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
				Location_of_Granny_row, Location_of_Granny_column ); 
		
				PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);	
				Sleep(1000);		
				
			}
		
		
		
		
	
	
	//sense
	
	do
	{
	cSense = Sense(Y, X, line, nGrid, cLRRH, cSense, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, 
			Location_of_Pit_column_2, Location_of_Pit_row_3, Location_of_Pit_column_3, Location_of_Flower_row_1, 
			Location_of_Flower_column_1, Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, 
			Location_of_Flower_column_3, Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, 
			Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, Location_of_Bakeshop_column_3, Location_of_Wolf_row,
			Location_of_Wolf_column, Location_of_Woodsman_row, Location_of_Woodsman_column, Location_of_Granny_row, Location_of_Granny_column);
		
		if (cSense == 'D')	
		{
			strcpy(cSenses, cPSenses);
			strcpy(cRotate, cNRotate);
		}	
		else if (cSense == 'C')
		{
			strcpy(cSenses, cFSenses);
			strcpy(cRotate, cNRotate);
		}
		else if (cSense == 'H')
		{
			strcpy(cSenses, cBSenses);
			strcpy(cRotate, cNRotate);
		}
		else if (cSense == 'O')
		{
			strcpy(cSenses, cWSenses);
			strcpy(cRotate, cNRotate);
		}
		else if (cSense == 'S')
		{
			strcpy(cSenses, cMSenses);
			strcpy(cRotate, cNRotate);
		}
		else if (cSense == 'L')
		{
			strcpy(cSenses, cGSenses);
			strcpy(cRotate, cNRotate);
		}
		else if (cSense == 'N')
		{
			strcpy(cSenses, cNSenses);
			strcpy(cRotate, cNRotate);
		}
		
		
	nNum_Sense++;
	Move++;
	
	LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   		Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
		Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
		Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
		Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
		Location_of_Granny_row, Location_of_Granny_column ); 
		
	
	PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
	
	Sleep(1000);
	
	
	//if forward
	
	 if ( (cSense == 'C') || (cSense == 'H') || (cSense == 'S') || (cSense == 'L') || (cSense == 'N'))
		{
			if (cLRRH == '<')
			{
				if ((X > nGrid) || (X == 1))
					{
					X = X - 0;
					}
			
				else
				X--;
				Move++;	
			}
			else if (cLRRH == '>') 
			{
				if((X == nGrid) || (X < 1))
					{
					X = X - 0;
					}
			
				else
				X++;
				Move++;
			}
			else if (cLRRH == '^') 
			{	
				if ((Y > nGrid) || ( Y == 1))	
					{
					Y = Y - 0;
					}
				
				else 												
					Y--;
					Move++;
				
			}
			
			else if (cLRRH == 'v') 
			{
				if ((Y == nGrid) || ( Y < 1))
					{
					Y = Y - 0;
					}
				
				else 	
					Y++;
					Move++;
			}
			nNum_Forward++;
			Move++;
			
			strcpy(cRotate, cNRotate);
			strcpy (cSenses, cbSenses);

			
		LPit(line, i, nGrid, X, Y, cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   			Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
			Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
			Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
			Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
			Location_of_Granny_row, Location_of_Granny_column ); 

	 		PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
	 	;
	 	
	 	if ( ((Y == rowF1) && (X == columnF1)) || ((Y == rowF2) && (X == columnF2)) || ((Y == rowF3) && (X == columnF3)) )
			{
				cHave_Flower = 'y'; // yes
				Move++; 
			}
		
		else if ( ((Y == rowB1) && (X == columnB1)) || ((Y == rowB2) && (X == columnB2)) || ((Y == rowB3) && (X == columnB3)) )
			{
				cHave_Bread = 'y';
				Move++;
			}
	 	else if ((Y == rowM1) && (X == columnM1))
			{
				cHave_Woodsman = 'y';
				Move++;
			}
		
		
		
		Sleep(1000);
							
		}
		
	 }
	while((cSense == 'C') || (cSense == 'H') || (cSense == 'S')  ); 
	
	
	}
	while ( ((Y != rowG1) || (X != columnG1)) || (cHave_Flower != 'y') || (cHave_Bread != 'y') || (cHave_Woodsman != 'y'));
}


if (nMode == 3) //Random
{
	do
	{
		
		if ( ((X == 1) && (Y == 1)) && (nNum_Rotate == 0) )
			{
				cLRRH = '>';
				nNum_Rotate++;
				
				
			LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   				Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
				Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
				Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
				Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
				Location_of_Granny_row, Location_of_Granny_column ); 
		
				strcpy(cRotate, cRRotate);
				strcpy(cSenses, cbSenses);
				
				PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);	
				getch();	
			}
		
		
		else if ((X == 1) && (Y == 1) && (nNum_Rotate >= 1)) // 1
			{
				if (cLRRH == '^')
				{
					cLRRH = '<';
					nNum_Rotate++;
					
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );
					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					getch();	
				}	
				
				else if (cLRRH == '<')
				{
					cLRRH = 'v';
					nNum_Rotate++;
					
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					getch();	
				}	
			}
			
		else  if ((X == nGrid) && (Y == 1))	// 2
			{
				if (cLRRH == '^')
				{
					cLRRH = '<';
					nNum_Rotate++;
					
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					getch();
				}	
				
				else if (cLRRH == '>')
				{
					cLRRH = 'v';
					nNum_Rotate++;
					
					
					strcpy(cRotate, cRRotate);
					strcpy (cSenses, cbSenses );
					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					getch();
				}	
			}
		else if ((X == 1) && (Y == nGrid)) // 3
			{
				if (cLRRH == '<')
				{
					cLRRH = '^';
					nNum_Rotate++;
					
					
					strcpy(cRotate, cRRotate);
					strcpy (cSenses, cbSenses );
				
					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					getch();
				}	
				
				else if (cLRRH == 'v')
				{
					cLRRH = '>';
					nNum_Rotate++;
					
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					getch();
				}
			}
		
		else if ((X == nGrid) && (Y == nGrid)) // 4
			{
				if (cLRRH == 'v')
				{
					cLRRH = '<';
					nNum_Rotate++;
					
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					getch();
				}	
				
				else if (cLRRH == '>')
				{
					cLRRH = '^';
					nNum_Rotate++;
					Move++;
					
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );

					
				LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   					Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
					Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
					Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
					Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
					Location_of_Granny_row, Location_of_Granny_column ); 
	
					PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
					
					getch();
				}
			}
				
		else 
			{
				if (Move % 4 != 0) //left
				{
					strcpy(cRotate, cLRotate);
					strcpy (cSenses, cbSenses );
					Move++;

				}
				else if (Move % 4 == 0) //right
				{
					strcpy(cRotate, cRRotate);
					strcpy (cSenses, cbSenses );
					Move++;
				}
				
				Arrow (Move, cLRRH);
				cLRRH = Arrow (Move, cLRRH);
				nNum_Rotate++;
				Move++;

			LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   				Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
				Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
				Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
				Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
				Location_of_Granny_row, Location_of_Granny_column ); 
		
				PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);	
				getch();		
				
			}
		
	//sense
	cSense = Sense(Y, X, line, nGrid, cLRRH, cSense, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, 
			Location_of_Pit_column_2, Location_of_Pit_row_3, Location_of_Pit_column_3, Location_of_Flower_row_1, 
			Location_of_Flower_column_1, Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, 
			Location_of_Flower_column_3, Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, 
			Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, Location_of_Bakeshop_column_3, Location_of_Wolf_row,
			Location_of_Wolf_column, Location_of_Woodsman_row, Location_of_Woodsman_column, Location_of_Granny_row, Location_of_Granny_column);
		
		if (cSense == 'D')	
		{
			strcpy(cSenses, cPSenses);
			strcpy(cRotate, cNRotate);
		}	
		else if (cSense == 'C')
		{
			strcpy(cSenses, cFSenses);
			strcpy(cRotate, cNRotate);
		}
		else if (cSense == 'H')
		{
			strcpy(cSenses, cBSenses);
			strcpy(cRotate, cNRotate);
		}
		else if (cSense == 'O')
		{
			strcpy(cSenses, cWSenses);
			strcpy(cRotate, cNRotate);
		}
		else if (cSense == 'S')
		{
			strcpy(cSenses, cMSenses);
			strcpy(cRotate, cNRotate);
		}
		else if (cSense == 'L')
		{
			strcpy(cSenses, cGSenses);
			strcpy(cRotate, cNRotate);
		}
		else if (cSense == 'N')
		{
			strcpy(cSenses, cNSenses);
			strcpy(cRotate, cNRotate);
		}
		
		
	nNum_Sense++;
	Move++;
	
	LPit(line, i, nGrid, X, Y,cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   		Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
		Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
		Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
		Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
		Location_of_Granny_row, Location_of_Granny_column ); 
		
	
	PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
	
	getch();
	
	
	//if forward
	
	 
			if (cLRRH == '<')
			{
				if ((X > nGrid) || (X == 1))
					{
					X = X - 0;
					}
			
				else
				X--;
				Move++;	
			}
			else if (cLRRH == '>') 
			{
				if((X == nGrid) || (X < 1))
					{
					X = X - 0;
					}
			
				else
				X++;
				Move++;
			}
			else if (cLRRH == '^') 
			{	
				if ((Y > nGrid) || ( Y == 1))	
					{
					Y = Y - 0;
					}
				
				else 												
					Y--;
					Move++;
				
			}
			
			else if (cLRRH == 'v') 
			{
				if ((Y == nGrid) || ( Y < 1))
					{
					Y = Y - 0;
					}
				
				else 	
					Y++;
					
			}
			nNum_Forward++;
			Move++;
			
			strcpy(cRotate, cNRotate);
			strcpy (cSenses, cbSenses);

			
		LPit(line, i, nGrid, X, Y, cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   			Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
			Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
			Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
			Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
			Location_of_Granny_row, Location_of_Granny_column ); 

	 		PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
	 	;
	 	
	 	if ( ((Y == rowF1) && (X == columnF1)) || ((Y == rowF2) && (X == columnF2)) || ((Y == rowF3) && (X == columnF3)) )
			{
				cHave_Flower = 'y'; // yes
				Move++; 
			}
		
		else if ( ((Y == rowB1) && (X == columnB1)) || ((Y == rowB2) && (X == columnB2)) || ((Y == rowB3) && (X == columnB3)) )
			{
				cHave_Bread = 'y';
				Move++;
			}
	 	else if ((Y == rowM1) && (X == columnM1))
			{
				cHave_Woodsman = 'y';
				Move++;
			}
		
		
		getch();
	
		if ((Y == rowP1) && (X == columnP1))
			{
			break;
			}
		
		else if ((Y == rowW1) && (X == columnW1))
		{
			if (cHave_Bread == 'n')
			{
				break;
			}
			else 
			{
				Y = Y + 0;
			}
		}
		
	}
	while ( ((Y != rowG1) || (X != columnG1)) || (cHave_Flower != 'y') || (cHave_Bread != 'y') || (cHave_Woodsman != 'y'));
}	
	
	if ((Y == rowG1) && (X == columnG1))
	{
		if ((cHave_Flower == 'y') && (cHave_Bread == 'y') && (cHave_Woodsman == 'y'))
		{
			printf("End! Little Red Riding Hood meets Granny with\n");
			printf("a flower, bread, and Woodsman");
		}
	}
	
	else if ((Y == rowP1) && (X == columnP1))
	{
		LPit(line, i, nGrid, X, Y, cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   			Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
			Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
			Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
			Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
			Location_of_Granny_row, Location_of_Granny_column ); 

	 	PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
		printf("Agent Fall into the Pit");
	}
	else if ((Y == rowW1) && (X == columnW1))
	{
		if (cHave_Bread == 'n')
		{
		LPit(line, i, nGrid, X, Y, cLRRH, Location_of_Pit_row_1, Location_of_Pit_column_1,Location_of_Pit_row_2, Location_of_Pit_column_2, 
   			Location_of_Pit_row_3, Location_of_Pit_column_3, Number_Of_Pits, Location_of_Flower_row_1, Location_of_Flower_column_1, 
			Location_of_Flower_row_2, Location_of_Flower_column_2, Location_of_Flower_row_3, Location_of_Flower_column_3, Number_Of_Flower,
			Location_of_Bakeshop_row_1, Location_of_Bakeshop_column_1, Location_of_Bakeshop_row_2, Location_of_Bakeshop_column_2, Location_of_Bakeshop_row_3, 
			Location_of_Bakeshop_column_3, Number_Of_Bakeshop, Location_of_Wolf_row, Location_of_Wolf_column,Location_of_Woodsman_row, Location_of_Woodsman_column,
			Location_of_Granny_row, Location_of_Granny_column ); 

	 	PrintResults(nNum_Rotate, nNum_Sense, nNum_Forward, cSenses, cRotate);
		printf("Agent is Eaten by the Wolf");
		}
	}

return 0;

}

