 #define     PASS    1
#define     FALSE   0
#define     TRUE    1

int CheckFactoryBad(int blockAddress)
{
    int result;
    
    //
    // ......
    //
    if ( result == PASS )
    {
	    return TRUE;
	}
	else
	{
        return FALSE;	
	}
}  

int EraseBlock(int blockAddress)
{
    int result;
    
    //
    // ......
    //
    if ( result == PASS )
    {
	    return TRUE;
	}
	else
	{
        return FALSE;	
	}
}

void WriteFlashPage(int blockAddress,int pageAddress,int columnAddress,int dataLength,int memoryOffset)
{
    //
    // ......
    //
}

void ReadFlashPage(int blockAddress,int pageAddress,int columnAddress,int dataLength,int memoryOffset)
{
    //
    // ......
    //
}
/*������λ*/
int CheckErrorbit(inputdata)
{
   int *outputdata;
   outputdata = (int*)(0x8000);
   int maxerrorbit = 5; // ��� L74 spec����δ˵��������λ��Ϊ���٣��ȼ�����Ϊ5
   int result;
   int i = 0;
   int j = 0;
   while((outputdata-0x8000 +1) < 8192)
   {
       result = inputdata ^ (*outputdata);
       while(j<32)
	   {
        if(result & (1<<j))
		{
	       i++;
		}
	     j++;
	   }
	   j = 0;
	   outputdata++;
   }
   if(i > 5) 
   {
	 return FALSE;
   }
   else
   {
	 return TRUE;
   }
}


//����
int * checkblock()
{
	int x = y =0;
	int inputdata = 0x3E;//����д��ȥ������Ϊ
    int blockAddress = 0x00;
    int pageAddress = 0x00;
    int columnAddress = 0x00;
    int dataLength = 0x2000;
    int memoryOffset = 0x8000;
    for(int i = 0; i<0x1000;i++)
	{
	    if(CheckFactoryBad(blockAddress) == TRUE)//�ж��ǲ��ǳ�������
		{
            if(EraseBlock( blockAddress) == TRUE)//�жϲ���������û��ִ�гɹ�
			{
	           for(int j = 0;j < 0x100;j++)
			   {

	               WriteFlashPage(blockAddress,pageAddress,columnAddress,datalength,memoryOffset);  
	               ReadFlashPage(blockAddress,pageAddress,columnAddress,datalength,memoryOffset);//������Ӧλ�õ�����
                   if(CheckErrorbit(inputdata) == 0)
				   {
                      a[1][y] = blockaddress;//�洢��Ӧ�����л����ַ
					  y++;
					  break;
				   }
	  	            pageaddress +=1;
			   }
			}
	        else
			{
               a[1][y] = blockaddress;//����ʧ�ܴ洢��Ӧ�Ŀ��ַ
			   y++;
			   break;
			}
		}
	    else
		{
           a[0][x] = blockaddress;//�洢ԭ�������Ӧ�ĵ�ַ
		   x++;
		   break;
		}
        blockAddress +=1;
	}
    return a;
}


