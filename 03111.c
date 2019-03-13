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
/*检查错误位*/
int CheckErrorbit(inputdata)
{
   int *outputdata;
   outputdata = (int*)(0x8000);
   int maxerrorbit = 5; // 这边 L74 spec上面未说明最大错误位数为多少，先假设他为5
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


//块检查
int * checkblock()
{
	int x = y =0;
	int inputdata = 0x3E;//假设写进去的数据为
    int blockAddress = 0x00;
    int pageAddress = 0x00;
    int columnAddress = 0x00;
    int dataLength = 0x2000;
    int memoryOffset = 0x8000;
    for(int i = 0; i<0x1000;i++)
	{
	    if(CheckFactoryBad(blockAddress) == TRUE)//判断是不是出厂坏块
		{
            if(EraseBlock( blockAddress) == TRUE)//判断擦除命令有没有执行成功
			{
	           for(int j = 0;j < 0x100;j++)
			   {

	               WriteFlashPage(blockAddress,pageAddress,columnAddress,datalength,memoryOffset);  
	               ReadFlashPage(blockAddress,pageAddress,columnAddress,datalength,memoryOffset);//读出对应位置的数据
                   if(CheckErrorbit(inputdata) == 0)
				   {
                      a[1][y] = blockaddress;//存储对应的运行坏块地址
					  y++;
					  break;
				   }
	  	            pageaddress +=1;
			   }
			}
	        else
			{
               a[1][y] = blockaddress;//擦除失败存储对应的块地址
			   y++;
			   break;
			}
		}
	    else
		{
           a[0][x] = blockaddress;//存储原厂坏块对应的地址
		   x++;
		   break;
		}
        blockAddress +=1;
	}
    return a;
}


