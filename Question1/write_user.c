#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

#define WR_DATA _IOW('a','a',int32_t*)


int main()
{
        int fd;
        int32_t val,num;
        printf("ioctl based character driver\n");
        fd=open("/dev/chr_device",O_RDWR);
        if(fd < 0)
        {
                printf("cannot open the device file\n");
                return 0;
        }
        printf("enter the data to send...\n");
        scanf("%d",&num);
        printf("writing value to the driver..\n");
        ioctl(fd,WR_DATA,(int32_t*)&num);
        printf("closing the driver\n");
        close(fd);
}
