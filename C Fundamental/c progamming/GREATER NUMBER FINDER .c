  // wap for prompot user to enter two number  then find greater one 
 #include<stdio.h>
  int main(){
  	 int num_1;
  	 int num_2;
  	  printf(" ENTER THE FIRST NUMBER :");
  	  scanf("%d",&num_1);
 	  printf(" ENTER THE SECOND NUMBER :");
  	  scanf("%d",&num_2);
  	   // using if else 
  	    if (num_1>num_2){
  	    	printf("THE MAXIMUM NUMBER IS :%d",num_1);
	      } else{
	      	printf("THE MAXIMUM NUMBER IS :%d",num_2);
	      }
 	  return 0;
  }
