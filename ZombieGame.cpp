#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <cstdlib>
using namespace std;
bool game_over = false;
int width = 17;
int height =17;
int Vaccine =0;
int Round = 0;
int Level =1;
int Credit=0;
int Kill =0;
int Ammo= 0;
int r= 3; //reloaded
int zarfiat = 3;
int h=3; 
int Px=1, Py=1;
int Dx=15 , Dy=15;
int temp = 0; //for handling round change
int temp2=0; //its value will equal old credit, needed when a vaccine is collected 
int bord = 5; //borde shotgun
int arr_i_Z[25];
int arr_y_Z[25];

int arr_i_V[25];
int arr_y_V[25];

int arr_i_A[25];
int	arr_y_A[25];


int vzade_i;
int vzade_y;
bool vzade = false;
int Azade_i;
int Azade_y;
bool Azade = false;
//bool vbashe = true;
bool reload=false;
bool no_ammo=false;
bool r_por=false;
bool rdone= false; //gun was reloaded

bool eat=false;   //zombie bokhoratesh
bool death=false;

int cnt=0; //count vaccine
bool nextlevel = false; //raftn b level bad vaghti b D reside bashe
bool in_bade = false; //yany boro aval hme vaccina ro biar

bool z_zade = false; //zombie zade koshte 
int z_zade_i=0;
int z_zade_y=0;
int tedad = Level; //tedad zambie ha to har level
bool no_r=false; //vaghti shelik mikone valy kheshab khalie

bool Upgrade = false;

bool comment_zombie = false;  //the comment that is cout when a zombie is killed


void Draw(){ 
	

	cout<<"Level: "<<Level<<"  "<<"Vaccine: "<<Vaccine<<"  "<<"Credit: "<<Credit<<"  "<<"Round: "<<Round<<endl;
 	cout<<"Health: [";
	 for(int i=0; i<h; i++){
	 	cout<<'|';
	 }
	 cout<<"]  "<<"Ammo: "<<r<<'/'<<Ammo<<"  "<<"Kill: "<<Kill<<endl;
 	
 		
 	
 	if(comment_zombie == true){
 		
 		if(Kill%14 ==1){
 			cout<<"First Blood"<<endl;
		 }
		if(Kill%14 ==2){
			cout<<"Double Kill"<<endl;
		}
		if(Kill%14 ==3){
			if(Round%2==0){
				cout<<"Triple Kill"<<endl;
			}
			else {
				cout<<"Hattrick"<<endl;
			}
		}
		if(Kill%14 ==4){
			cout<<"Team Killer"<<endl;
		}
		if(Kill%14 ==5){
			cout<<"Headshot"<<endl;
		}
		if(Kill%14 ==6){
			cout<<"Rampage"<<endl;
		}
		if(Kill%14 ==7){
			cout<<"Killing Spree"<<endl;
		}
		if(Kill%14 ==8){
			cout<<"Unstoppable"<<endl;
		}
		if(Kill%14 ==9){
			cout<<"Monster Kill"<<endl;
		}
		if(Kill%14 ==10){
			cout<<"Multi Kill"<<endl;
		}
		if(Kill%14 ==11){
			cout<<"Ludicrouskill"<<endl;
		}
		if(Kill%14 ==12){
			cout<<"Ultra Kill"<<endl;
		}
		if(Kill%14 ==13){
			cout<<"Dominating"<<endl;
		}
		if(Kill%14 == 0){
			cout<<"Godlike"<<endl;
		}
		cout<<(Level+1)<<"Credits gained!"<<endl;
		
		 comment_zombie = false;
	 }
	
 	
 	if(no_r == true){
 		cout<<"No charged ammo!"<<endl;
 		no_r = false;
	 }
 	if(Level==21){
 		system("cls");
 		cout<<"Congratulations!"<<endl;
 		cout<<" You have successfully collected all the vaccine!"<<endl;
 		cout<<"Now it is time to return to the Earth"<<endl;
 		cout<<"Good Bye!"<<endl;
 		game_over= true;
	 }
    if(nextlevel==true){
    	
    	cout<<"You Won! You have reached level "<<Level<<endl;
    	Round=0;
    	cnt=0;
    	nextlevel=false;
	}
	if(in_bade==true){
		cout<<"First get all the vaccines."<<endl;
		in_bade = false;
	}
 	if(eat==true && death==false){
 		system("cls");
 		cout<<"The zombie is eating you! You lost one of your healths!"<<endl;
 		Round=0;
 		Level=1;
 		Px=1;
 		Py=1;
 		h--;
 		eat=false;
 		death=false;
	 }
	 else if(death==true){
	 	/*system("cls");
	 	cout<<"You Died!"<<endl;
	 	cout<<"You Lose! Would you like to try again?"<<endl;*/
	 	char a;
	 	cin>>a;
	 	a = tolower(a);
	 	if(a=='n'){
	 		//goto Menu;
	 		cout<<"Good Bye!";
	 	//	game_over=true;
		 }
		 if(a=='y'){
		 	cout<<"The game will restart in 5 seconds"<<endl;
		 	
		 }
	 }
 	if(reload==true){
 		if(no_ammo==true){
 			cout<<"No Ammo!"<<endl;
 			no_ammo=false;
		 }
		if(r_por==true){
			cout<<"The gun is already charged"<<endl;
			r_por=false;
		}
		if(rdone==true){
			cout<<"Reloaded"<<endl;
			rdone=false;
		}
		
		reload=false; 
	 }
 	 srand(time(0));
     
 	//MAP DESCRIPTION                             Always
 	char map[17][17];
 	for(int j=0; j<17; j++){
 		for(int i=0; i<17; i++){
 	
 	    if(j==16 || j==0){
 	    	map[i][j]='-';
		 }
		else if( i==0 || i==16){
		map[i][j]='|';
		}
		
		
			
		else 
		map[i][j]=' ';
 			
		 }
		 
	 }
	 
	 
	 	//PLAYER LOCATION                            Always
 	int i= Px;                                  
 	int j= Py;
 	if(map[i][j] ==' '){
 		map[i][j] = 'P';
	 }
 	
	 
 	//ZOMBIE LOCATION                            
	 
	 if(Round==0){
	 	               
 	for(int k=0; k<Level; k++){                //tekrari nabudanesh ba P check shode only
 	aval:	int i = rand() % 15 +2;
 		int j = rand() % 15+2;
 		if(i==0){
 			i=5;
		 }
		if(i==16){
			i--;
		}
		if(j==0){
			j++;
		}
		if(j==16){
			j--;
		}
		if(i==Px && j==Py){       //k roo ham naioftn
		if(i==1){
			i=2;
		}
		else if(i==15){
			i=14;
		}
		else if(j==1){
			j=2;
		}
		else if(j==15){
			j=14;
		}
		else {
			i--;
		}	
		}
		 arr_i_Z[k] = i;
	    arr_y_Z[k] = j;
		
		
		if(map[i][j]==' '){
			map[i][j]='Z';
		}
		else{
			goto aval;
		}
		tedad=Level;
	 }
}
//to move
if(Round%2 == 1){
	for(int k=0; k<tedad; k++){
		int a = arr_i_Z[k];
		int b = arr_y_Z[k];
		
		if( (a==z_zade_i) && (b==z_zade_y) &&(z_zade==true)){
		   
		   arr_i_Z[k]= 40;
		   arr_y_Z[k]=40;
		   z_zade=false;
		   break;
	}
		
		   if(Px==a){
		    	if(Py>b){
		    	    b++;	
				}
				if(Py<b){
					b--;
				}
			}
			else if(Py==b){
				if(Px>a){
					a++;
				}
				if(Px<a){
					a--;
				}
			}
			else {
				if((a==1) && (Py>b)){
					b++;
				}
				if((a==1) && (Py<b)){
					b--;
				}
				if((a==15) && (Py>b)){
					b++;
				}
				if((a==15) && (Py<b)){
					b--;
				}
				else{
					if(Py>b){
						b++;
					}
					else{
						b--;
					}
				}
			}
		
				arr_i_Z[k] = a;
				arr_y_Z[k] = b;
			
				 if(map[a][b] = ' '){	
			map[a][b]= 'Z';
		}
		else{
		a++;
		b--;
		map[a][b]= 'Z';
	}
		}	
}
//sabet
else if(Round %2 == 0){
	
		for(int i=0; i<17; i++){
 			for(int j=0; j<17; j++){
 				for(int k=0; k<tedad; k++){
 					if((arr_i_Z[k]==i) && (arr_y_Z[k]==j)){
 						
 					   /* if ( (z_zade = true) &&  (i==z_zade_i) &&  (j==z_zade_y) ){
					    z_zade =false;
				    	arr_i_Z[k]=110;
 				        arr_y_Z[k]= 110;
				}*/
 				if( (i==z_zade_i) && (j==z_zade_y) &&(z_zade==true)){
		   
		   arr_i_Z[k]=41;
 		   arr_y_Z[k]= 42;
		   z_zade=false;
		   break;
	}	    
						else if(map[i][j] == ' '){
						 
 						map[i][j]='Z';
 				}
					 }
				 }
 				
			 }
		 }
		 
	
}
	

	 
	 //VACCINE LOCATION                           //only when entering a new Level
	 
	 
	 	if(Round==0){
		 
	 	for(int k=0; k<Level; k++){
avalv : int i = rand() % 17;
 		int j = rand() % 17;
 		if(i==0){
 			i++;
		 }
		if(i==16){
			i--;
		}
		if(j==0){
			j++;
		}
		if(j==16){
			j--;
		}
		arr_i_V[k] = i;
		arr_y_V[k] = j;
		
		if(map[i][j]==' '){
			map[i][j]='V';
		}
		else{
			goto avalv;
		}
	 }
}
if(Round>0){
	for(int i=0; i<17; i++){
 			for(int j=0; j<17; j++){
 				for(int k=0; k<17; k++){
 					if((arr_i_V[k]==i) && (arr_y_V[k]==j)){
 						
 					if ((vzade==true) && (i==vzade_i) && (j==vzade_y)){
 					map[i][j] = 'P';
 					vzade = false;
 					arr_i_V[k]=43;
 				    arr_y_V[k]= 44;
 				    cout<<"Vaccine collected"<<endl;
			        cout<<Level+1<<' '<<"Credit gained"<<endl;
 				//	vbashe= false;
				    }	
 						
 					else if( map[i][j]==' '){
 						map[i][j]='V';
 				    }
 				
					 }
				 }
 				
			 }
		 }
}

 	
 
 	
 	//D LOCATION
 	i= Dx;
 	j= Dy;
 	if(map[i][j] ==' '){
 		map[i][j] = 'D';
	 }
 	
 	
 	//A LOCATION                          //only when entering a new Level
 	
 	
 	if(Round==0){
 	for(int k=0; k<(Level+1)/2; k++){
avala : int i = rand() % 15 +2;
 		int j = rand() % 15+2;
 		if(i==0){
 			i++;
		 }
		if(i==16){
			i--;
		}
		if(j==0){
			j++;
		}
		if(j==16){
			j--;
		}
		arr_i_A[k] = i;
		arr_y_A[k] = j;
		
		if(map[i][j]==' '){
			map[i][j]='A';
				
		}
		else{
			goto avala;
		}
	
		
	 }
}

 else if(Round>0){
 		for(int i=0; i<17; i++){
 			for(int j=0; j<17; j++){
 				for(int k=0; k<(Level+1)/2; k++){
 					if((arr_i_A[k]==i) && (arr_y_A[k]==j)){
 						if ((Azade==true) && (i==Azade_i) && (j==Azade_y)){
 					map[i][j] = 'P';
 					Azade = false;
 					arr_i_A[k]=44;          //terminating A location so it wont be on map
 				    arr_y_A[k]= 45;
 				    cout<<"Ammo collected"<<endl;
 			
				    }
 					
						
 					else if( map[i][j]==' '){
 						map[i][j]='A';
 				    }	 
 					
 					
 					
					 }
				 }
 				
			 }
		 }
 		
	 }
 	
 	
 	//COUT MAP                                       //Always
 	for(int j=0; j<17; j++){
 		for(int i=0; i<17; i++){
 			cout<<map[i][j];
		 }
 	
 	cout<<endl;
 	
 	if(Upgrade==true){
	cout<<0<<'_'<<"Return to game"<<endl;
 	cout<<1<<'_'<<"Upgrade capacity of magazine : 1 bullet (maximum is 7 bullets, now is "<<zarfiat<<") , Credit required: "<<(Level*zarfiat)<<endl;
 	cout<<2<<'_'<<"Upgrade range of shotgun: 1 times the size of the person himself (maximum is 10 times, now is "<<bord<<") ,Credit required: "<<(bord+Level)<<endl;
 	cout<<3<<'_'<<"get an additional health (maximum is 5 healths, now is "<<h<<"), Credit required: "<<((Level+1)*h)<<endl;
 	int up; //upgrade answer
 	cin>>up;
 	if(up == 0){
 		system("cls");
 		Round=0;
	 }
	else if(up== 1){
		
		if(Credit < (Level*zarfiat) ){
			cout<<"Unfortunately, your credit is not enough to get this item. Please gain "<<((Level*zarfiat) - Credit)<<" more credit by playing."<<endl;
		}
		else if(zarfiat == 7){
			cout<<"The selected item is maximum."<<endl;
		}
		else {
			zarfiat++;
			r++;
			int result = Credit - (Level*zarfiat);
			Credit = result;
			cout<<"Upgrade is done successfully"<<endl;
			cout<<"Your magazine capacity is now "<<zarfiat<<'.'<<endl;
		}
	}
	else if(up== 2){
		if(Credit < (bord+Level) ){
			cout<<"Unfortunately, your credit is not enough to get this item. Please gain "<<( (bord+Level)- Credit)<<" more credit by playing."<<endl;
		}
		else if(bord == 10){
			cout<<"The selected item is maximum."<<endl;
		}
		else {
			bord++;
			int result = Credit - (bord+Level);
			Credit = result;
			cout<<"Upgrade is done successfully"<<endl;
			cout<<"Your shotgun range is now "<<bord<<'.'<<endl;
		}
	}
	else if(up== 3){
		if(Credit < ((Level+1)*h) ){
			cout<<"Unfortunately, your credit is not enough to get this item. Please gain "<<( (bord+Level)- Credit)<<" more credit by playing."<<endl;
		}
		else if( h== 5){
			cout<<"The selected item is maximum."<<endl;
		}
		else {
			h++;
			int result = Credit - ((Level+1)*h);
			Credit = result;
			cout<<"Additional health received successfully"<<endl;
			cout<<"Your health is now "<<h<<'.'<<endl;
		}
	}
	else {
		cout<<"Please just enter a number from the menue."<<endl;
	}
	Upgrade = false;
 	
 }
}

}





void Input(){
	char input;
	cin>>input;
	input = tolower(input);

	switch(input){
		case 'w' :
			if(Py==1){
				break;
			}
			else{
			    Py--;
				break;	
			}
		
		
		case 'd' :
			if(Px==15){
				break;
			}
			else{
				Px++;
			    break;	
			}
		
		
		case 's' :
			if(Py==15){
				break;
			}
			else{
			Py++;
			break;	
			}
		
		
		case 'a' :
			if(Px==1){
				break;
			}
			else{
			    Px--;
			    break;	
			}
			
			
		case 'r' :
			reload=true;
			if(Ammo==0){
				no_ammo=true;
			}
			else if(r==zarfiat){
				r_por = true;
			}
			else{
				while(r<zarfiat && Ammo>0){
					r++;
					Ammo--;
				}
				rdone = true;
				}
			break;
		case 'e' :
			game_over = true;
			break;
		case 't' :
			if(r==0){
				no_r = true;
			}
			else{
			for(int k=0; k<tedad ; k++){
				if ( (Px==arr_i_Z[k]) && (Py - arr_y_Z[k] <= bord)){
					z_zade_i = arr_i_Z[k];
					z_zade_y = arr_y_Z[k];
					Kill++;
					tedad--;
					r--;
					z_zade = true;
					int temp3 = Credit;
					Credit = temp3 + Level +1;
				}
			}
		}
		comment_zombie = true;
			break;
			
		case 'f' :
			if(r==0){
				no_r = true;
			}
			else{
			 for(int k=0; k<tedad ; k++){
				if ( ( (arr_i_Z[k] - Px)<= bord) && (Py==arr_y_Z[k]) ){
					z_zade_i = arr_i_Z[k];
					z_zade_y = arr_y_Z[k];
					Kill++;
					tedad--;
					r--;
					z_zade = true;
					int temp3 = Credit;
					Credit = temp3 + Level +1;
				}
			}
		}
		comment_zombie = true;
			break;
			
		case 'g' :
				if(r==0){
				no_r = true;
			}
			else{
			 for(int k=0; k<tedad ; k++){
				if ( (arr_i_Z[k] == Px) && ( (arr_y_Z[k] - Py) <= bord) ){
					z_zade_i = arr_i_Z[k];
					z_zade_y = arr_y_Z[k];
					Kill++;
					tedad--;
					r--;
					z_zade = true;
					int temp3 = Credit;
					Credit = temp3 + Level +1;
				}
			}
		}
		comment_zombie = true;
			break;
			
		case 'h' :
				if(r==0){
				no_r = true;
			}
			else{
			 for(int k=0; k<tedad ; k++){
				if (  ((Px - arr_i_Z[k] )<= bord) && ( arr_y_Z[k] == Py )){
					z_zade_i = arr_i_Z[k];
					z_zade_y = arr_y_Z[k];
					Kill++;
					tedad--;
					r--;
					z_zade = true;
					int temp3 = Credit;
					Credit = temp3 + Level +1;
				}
			}
		}
		comment_zombie = true;
			break;
		case 'u' :
			Upgrade = true; ;                   //baiad besazim upgrado *******
			break;
		case 'm' :
			game_over=true;
			break;
		//	n=4;
			
			//goto Menu;                       //Sink **
			//break;
	    default :
	    	break;
			
	}
		
	
	//gaining vaccine
	for(int k=0; k<Level; k++){
		if( (Px== arr_i_V[k]) && (Py== arr_y_V[k]) ){
			vzade_i = Px;
			vzade_y = Py; 
			Vaccine++;
			vzade = true;
			temp2 = Credit;
			Credit= temp2 + Level + 1; 
			cnt++;
			
		}
	}
	//gaining ammo
	for(int k=0; k<Level; k++){
		if( (Px== arr_i_A[k]) && (Py== arr_y_A[k]) ){
			Azade_i = Px;
			Azade_y = Py; 
			Ammo++;
			Azade = true;	
		}
	}
	
	
	
	
	//zombie eats the player
	for(int k=0; k<tedad; k++){
		cnt=0; //vagarna v gereftn beham mikhore
		if( (Px - arr_i_Z[k] == 1) && (Py==arr_y_Z[k]) ) {
//			h--;
			eat = true;
			if(h==0){
				death=true;
				system("cls");
	 	cout<<"You Died!"<<endl;
	 	cout<<"You Lose! Would you like to try again?"<<endl;

				sleep(5);
				game_over=true;
			cnt=0;
			}
		}
		
		if((arr_i_Z[k] - Px ==1) && (Py==arr_y_Z[k]) ){
//			h--;
			eat=true;
			if(h==0){
				death=true;
				system("cls");
	 	cout<<"You Died!"<<endl;
	 	cout<<"You Lose! Would you like to try again?"<<endl;

				
				sleep(5);
				game_over=true;
			}
		}
		if((arr_y_Z[k] - Py ==1) && (Px==arr_i_Z[k]) ){
//			h--;
			eat=true;
			if(h==0){
				death=true;
				system("cls");
	 	cout<<"You Died!"<<endl;
	 	cout<<"You Lose! Would you like to try again?"<<endl;

				sleep(5);
				game_over=true;
			}
		}
		if((arr_y_Z[k] - Py ==1) && (Px==arr_i_Z[k]) ){
//			h--;
			eat=true;
			if(h==0){
				death=true;
				system("cls");
	 	cout<<"You Died!"<<endl;
	 	cout<<"You Lose! Would you like to try again?"<<endl;

				sleep(5);
				game_over=true;
			}
		}
		if((arr_i_Z[k] - Px == 1) && (arr_y_Z[k] - Py == 1)){             
//		    h--;                                                        //* *  *
			eat=true;                                                   //* z  *                                                        
			if(h==0){                                                   //* *  p
				death=true;
				system("cls");
	 	cout<<"You Died!"<<endl;
	 	cout<<"You Lose! Would you like to try again?"<<endl;

				sleep(5);
				game_over=true;
			}
		}
		if((Px - arr_i_Z[k] == 1) && (Py - arr_y_Z[k] == 1)){ 
//		    h--;                            
			eat=true;                                                   //* *  p
			                                                            //* z  *
			if(h==0){                                                   //* *  *
				death=true;
				system("cls");
	 	cout<<"You Died!"<<endl;
	 	cout<<"You Lose! Would you like to try again?"<<endl;

				sleep(5);
				game_over=true;
			}
		}
		if((arr_i_Z[k] - Px == 1) && (Py - arr_y_Z[k] == 1)){                                  
//			h--;                                                        //* *  *
		    eat=true;                                                   //* z  *
			if(h==0){                                                   //p *  *
				death=true;
				system("cls");
	 	cout<<"You Died!"<<endl;
	 	cout<<"You Lose! Would you like to try again?"<<endl;

				sleep(5);
				game_over=true;
			}
		}
		if((Px - arr_i_Z[k] == 1) && (Py - arr_y_Z[k] == 1)){ 
//		    h--;                                 
			eat=true;                                                   //* *  *
			//h--;                                                      //* z  *
			if(h==0){                                                   //p *  *
				death=true;
				system("cls");
	 	cout<<"You Died!"<<endl;
	 	cout<<"You Lose! Would you like to try again?"<<endl;

				sleep(5);
				game_over=true;
			}
		}
	}
	
	//player gets to D
	if(Px==15 && Py==15){
	    if(Level-cnt >= 0){
		Level++;
		Round=0;
		Px=1;
		Py=1;
		cnt=0;
		nextlevel=true;	
		}
		else{
			in_bade = true;
		}
		
	}
		Round++;
	}





int main(){
//	system("Color 0D");
cout<<" ######   #######  ##     ## #### ########      #######    #####    #######    #####   \n\
##    ## ##     ## ##     ##  ##  ##     ##    ##     ##  ##   ##  ##     ##  ##   ##  \n\
##       ##     ## ##     ##  ##  ##     ##           ## ##     ##        ## ##     ## \n\
##       ##     ## ##     ##  ##  ##     ##     #######  ##     ##  #######  ##     ## \n\
##       ##     ##  ##   ##   ##  ##     ##    ##        ##     ##        ## ##     ## \n\
##    ## ##     ##   ## ##    ##  ##     ##    ##         ##   ##  ##     ##  ##   ##  \n\
 ######   #######     ###    #### ########     #########   #####    #######    ##### "<<endl;
 sleep(5);
 system("cls");
	Menu : cout<<1<<'_'<<"New Game"<<endl;
	cout<<2<<'_'<<"Settings"<<endl;
	cout<<3<<'_'<<"Credits"<<endl;
	cout<<4<<'_'<<"Help"<<endl;
	cout<<5<<'_'<<"Exist"<<endl;
	int n;
	cin>>n;
	system("cls");
	if(n==1){
		//enter the game sink
			while( game_over == false){
            	Draw();
	            Input();
            	system("cls");	
	}
	if(game_over=true){
		game_over=false;
		Level=0;
		Round=0;
		h=3;
		Kill=0;
		Ammo=0;
		r=3;
		zarfiat=3;
		
			goto Menu;
	}
		
	}
	if(n==2){
		cout<<"Final level is: 20"<<endl;
		cout<<"press m to go back to Menu"<<endl;
		char answer;
		cin>>answer;
		if(answer=='m'){
			system("cls");
			goto Menu;
		}
		
		
	}
	if(n==3){
		cout<<"Helia Naderi"<<endl;
		cout<<"Aryana Taghavi"<<endl;
		sleep(5);
		system("cls");
		goto Menu;
		
	}
	
	
	if(n==4){
	    cout<<"Move up: w"<<endl;
	    cout<<"Move right: d"<<endl;
	    cout<<"Move down: s"<<endl;
	    cout<<"Move left: a"<<endl;
	    
	    cout<<"Shoot up: t"<<endl;
	    cout<<"Shoot right: f"<<endl;
	    cout<<"Shoot down: g"<<endl;
	    cout<<"Shoot left: h"<<endl;
	     cout<<"Reload: r"<<endl;
	     cout<<"Exit: e"<<endl;
	     cout<<"Upgrade: u"<<endl;
	     cout<<"Menu: m"<<endl;
	     
	     char str4;
	     cin>>str4;
	     system("cls");
	     if(str4=='m'){
	     	goto Menu;
		 }
		 if(str4 == 'e'){
		 	goto Menu;
		 }
    }
	
	
	
	
	if(n==5){
		cout<<"Are you sure you want to exit the game? "<<endl;
		char str3;
		cin>>str3;
		system("cls");
		if(str3 == 'n'){
			goto Menu;
		}
		if(str3 == 'y'){
			cout<<"Good Bye!";
		}
	}
	
	
	 
	if(n!=1 && n!=2 && n!=3 && n!=4 && n!=5){
		cout<<"Please enter a number from above"<<endl;
		goto Menu;
		
	}
	
	
}

	
