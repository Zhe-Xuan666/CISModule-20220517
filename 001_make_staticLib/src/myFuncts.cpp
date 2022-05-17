#include "myFuncts.h"
#include "get_image.h"

bool initFuncts(char *_iniFile)
{
    if (ini_gets("RESOLUTION", "Width", "2592", buffIni, 8, iniFile))
    {
        IMAGE_WIDTH = atoi(buffIni);
    }
    else
    {
        puts("Can't set parameter Width");
        return false;
    }

    if (ini_gets("RESOLUTION", "Height", "1944", buffIni, 8, iniFile))
    {
        IMAGE_HEIGHT = atoi(buffIni);
    }
    else
    {
        puts("Can't set parameter Height");
        return false;
    }
/*
    if (ini_gets("RESOLUTION", "Resize_Width", "2592", buffIni, 8, iniFile))
    {
        RESIZE_WIDTH = atoi(buffIni);
    }
    else
    {
        puts("Can't set parameter Resize_Width");
        return false;
    }

    if (ini_gets("RESOLUTION", "Resize_Height", "1944", buffIni, 8, iniFile))
    {
        RESIZE_HEIGHT = atoi(buffIni);
    }
    else
    {
        puts("Can't set parameter Resize_Height");
        return false;
    }

    if (ini_gets("RESOLUTION", "Resize_Height", "2624", buffIni, 8, iniFile))
    {
        RESIZE_HEIGHT = atoi(buffIni);
    }
    else
    {
        puts("Can't set parameter Resize_Height");
        return false;
    }
*/
    int multi_num;
    switch(BIT_DEPTH)
    {  
        case 6:
        case 7:
        case 8:
            multi_num = 1; 
            break;

        case 20:
            multi_num = 4; 
            break;
        
        default:
            multi_num = 2;
            break;
    }
    
    if(IMAGE_WIDTH%(64/multi_num)==0)
    {
        RESIZE_WIDTH = IMAGE_WIDTH;
        RESIZE_HEIGHT = IMAGE_HEIGHT;
        IMAGE_SIZE = IMAGE_WIDTH * IMAGE_HEIGHT * multi_num;
        RESIZE_IMAGE_SIZE = IMAGE_SIZE;
        ALIGN_BYTES = 0;
    }
    else
    {
        RESIZE_WIDTH = IMAGE_WIDTH;
        RESIZE_HEIGHT = IMAGE_HEIGHT;
        IMAGE_SIZE = IMAGE_WIDTH * IMAGE_HEIGHT * multi_num;
        RESIZE_IMAGE_SIZE = IMAGE_SIZE;
        IMAGE_WIDTH = (IMAGE_WIDTH/(64/multi_num)+1)*(64/multi_num);
        IMAGE_SIZE = IMAGE_WIDTH * IMAGE_HEIGHT * multi_num;
        ALIGN_BYTES = IMAGE_WIDTH * multi_num;
    }
    printf("IMAGE_WIDTH= %d \r\n",IMAGE_WIDTH);
    printf("IMAGE_HEIGHT= %d \r\n",IMAGE_HEIGHT);
    printf("IMAGE_SIZE= %d \r\n",IMAGE_SIZE);
    printf("RESIZE_WIDTH= %d \r\n",RESIZE_WIDTH);
    printf("RESIZE_HEIGHT= %d \r\n",RESIZE_HEIGHT);
    printf("RESIZE_IMAGE_SIZE= %d \r\n",RESIZE_IMAGE_SIZE);
    printf("ALIGN_BYTES= %d \r\n",ALIGN_BYTES);
    /*
    printf("IMAGE_WIDTH= %d \r\n",IMAGE_WIDTH);
    printf("IMAGE_HEIGHT= %d \r\n",IMAGE_HEIGHT);
    printf("IMAGE_SIZE= %d \r\n",IMAGE_SIZE);
    printf("BufferType= %d \r\n",BufferType);
    */
    /*
    if (ini_gets("RESOLUTION", "Size", "10077696", buffIni, 10, iniFile))
    {
        IMAGE_SIZE = atoi(buffIni);
    }
    else
    {
        puts("Can't set parameter Size");
        return false;
    }*/

    return true;
}
