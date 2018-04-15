#include <conio.h>
#include <stdio.h>
#include <math.h>

int time_of_flying_hours = 4;

#define n 5
#define m 12
#define l 10

int _delay_minute( int time_minut)
{
	int t;
	int Time = time_minut;
	int time_wait = 1;
	time_minut *= 60;
	for (time_wait; time_wait < time_minut; time_wait++)
	{
		for (t = 0; t < 26771.0417; t++){
		}
	}
	return Time;
}


 int main()
 {
 	char str;
	int i; 
	int j;
	int k;
 	
	FILE *file;
	FILE *file_aviamodel;
	FILE *file_earth;
	
	char array_avia[10];
	char array_meteo[12];
	char array_weather[10];
	
	char aviatemperature[5];
	char aviahard[5];
	
	char weather[10];
	char earthtemperature[4];
	char wind[3];
	char windspeed[2];

	
	int counter;
		
 	int time_of_flying_in_5_minytes = time_of_flying_hours * 12;
 	
	int time = time_of_flying_in_5_minytes;
	
	int time_before_end_of_flying = time_of_flying_in_5_minytes * 5;
	
	for( time; time > 0; time --)
	{
		time_before_end_of_flying -= _delay_minute( 5) ;
		printf( "time_before_end_of_flying = %i \n", time_before_end_of_flying);
		
    	
    	
    	file_aviamodel = fopen("aviaparametrs.txt", "r");
 		if ((file_aviamodel = fopen("aviaparametrs.txt","r")) == NULL)
		{
    	    printf("unopening\n");
    	}
    	else{
    		for (i = 0; i < 10; i++)
      	    {
      	    	array_avia[i] = fgetc (file_aviamodel);
			}
    	}
    	fclose (file_aviamodel);
    	
    	    	
    	file_earth = fopen("meteostantion.txt", "r");
 		if ((file_earth = fopen("meteostantion.txt","r")) == NULL)
		{
    	    printf("unopening\n");
    	}
    	else{
      	    for (i = 0; i < 22; i++)
      	    {
      	    	if( i < 12){
      	    		array_meteo[i] = fgetc (file_earth);
				}
      	    	else{
      	    		array_weather[i - 12] = fgetc (file_earth);
				}
			}
			
    	}
    	fclose (file_earth);
    			
	   	
    	file = fopen("parametrs.txt", "w");
 		if ((file = fopen("parametrs.txt","w")) == NULL)
		{
    	    printf("unopening\n");
    	}
    	else{
    	    fprintf (file, " time fly %i\t", time_before_end_of_flying);
    		fclose (file);
    	}
    
	
// заливаем первый массив		
    
    file = fopen("parametrs.txt", "a");
 	if ((file = fopen("parametrs.txt","a")) == NULL)
	{
        printf("unopening\n");
    }
    else{
    	for( j = 0; j < 2; j++){
    		for( i = 0; i < n; i++){
    			str = array_avia[5 * j + i];
        		fprintf (file, "%c", str);    			
			}
		fprintf(file, "\t");
		}
		fclose (file);
    }
    
// заливаем второй массив		
    
    file = fopen("parametrs.txt", "a");
 	if ((file = fopen("parametrs.txt","a")) == NULL)
	{
        printf("unopening\n");
    }
    else{
    	for( j = 0; j < 3; j++){
    		for( i = 0; i < (m / 3); i++){
    			str = array_meteo[4 * j + i];
        		fprintf (file, "%c", str);    			
			}
		fprintf(file, "\t");
		}
		fclose (file);
    }    
    
    // заливаем второй массив		
    
    file = fopen("parametrs.txt", "a");
 	if ((file = fopen("parametrs.txt","a")) == NULL)
	{
        printf("unopening\n");
    }
    else{
   		for( i = 0; i < l; i++){
   			str = array_weather[i];
       		fprintf (file, "%c", str);    			
		}
		fprintf(file, "\t");
		fclose (file);
    }   
    
  	
    	
    	
	}
			
	getch();
	return 0;
	return 0;
 }
