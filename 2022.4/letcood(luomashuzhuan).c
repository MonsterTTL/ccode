int romanToInt(char * s){int temp=0;char t,t1;
 while(*s!='\0')
 {t=(*s); 
  t1=*(s+1);
  switch(t)
    {  case 'I':if(t1=='V')
                  {temp+=4;s++;break;}
                else if(t1=='X')
                  {temp+=9;s++;break;}
                else 
                   {temp+=1;break;}
       case 'V':temp+=5;
                break;
       case 'X':if(t1=='L')
                  {temp+=40;s++;break;}
                else if(t1=='C')
                  {temp+=90;s++;break;}
                else 
                   {temp+=10;break;}
       case 'L':temp+=50;
                break;
       case 'C':if(t1=='D')
                  {temp+=400;s++;break;}
                else if(t1=='M')
                  {temp+=900;s++;break;}
                else 
                   {temp+=100;break;}
       case 'D':temp+=500;
                 break;
       case 'M':temp+=1000;  
                 break;              

    }
    s++;

 }
 return temp;

}



int romanToInt2(char * s){int num=0;int mid=0;//plus
  char temp;
  int pre=0;
 while((temp=(*s))!='\0')
 {
  switch(temp)
  {case 'I':mid=1;break;
   case 'V':mid=5;break;
   case 'X':mid=10;break;
   case 'L':mid=50;break;
   case 'C':mid=100;break;
   case 'D':mid=500;break;
   case 'M':mid=1000;break;
  }
  if(mid>pre)
    num+=(mid-(2*pre));
   else
    num+=mid;
   pre=mid;
  s++;
 }
 return num;

}


char * longestCommonPrefix(char ** strs, int strsSize){
   static char store[202];int temp=0;int temp1=0;
    
    while(((strs[temp][temp1])^(strs[temp+1][temp1]))==0)
    { temp++;
      if(temp+1>=strsSize)
          {store[temp1]=strs[temp][temp1];
           temp=0;
           temp1++;
          }
    
    }
    return store;


}//gonggongzhui