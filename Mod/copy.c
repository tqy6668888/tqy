#include<copy.h>
int main(int argc,char**argv){
	int srcfd,destfd;
	srcfd=open(argv[1],O_RDONLY);
	destfd=open(argv[2],O_WRONLY|O_CREAT,0664);

	int offset=atoi(argv[3]);
	lseek(srcfd,offset,SEEK_SET);
	lseek(destfd,offset,SEEK_SET);

	int len;
	int blocksize=atoi(argv[4]);
	char buffer[blocksize];
	bzero(buffer,sizeof(buffer));
	len=read(srcfd,buffer,sizeof(buffer));
	write(destfd,buffer,len);

	close(srcfd);
	close(destfd);
}
