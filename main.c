#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/utsname.h>
#include<string.h>
#include<wait.h>
#include<in_built.h>
char cwd[1024],cwr[1024],home[1024];
char co[1024],cp[1024],ct[1024];
char queue[100][1024];
pid_t qu[100];
int qp=0,flq[100];
struct utsname a;
/*void p_wd(char c[])
  {
  printf("%s\n",c);
  }*/
void p_wd(char c[]);

void echo(char c[]);

void ch_dir(char c[],int done,char ho[]);

void pwd(char t[],char r[],char ho[]);
/*{
  char d1[2]=" ";
  char *token[100];
  int m=0,i,k;
  token[m]=strtok(c,d1);
  while(token[m]!=NULL)
  {
//printf("%s\n",token[m]);
m++;
token[m]=strtok(NULL,d1);
}
if(done==1)
{
k=strlen(token[m-1]);
token[m-1][k-1]='\0';
}
int re;
if(token[1]!=NULL)
{
re=chdir(token[1]);
if(re==-1)
fprintf(stderr,"Change directory failed\n");
}
else 
chdir(home);
}*/
/*
   void echo(char c[])
   {
   int i;
   for(i=5;i<strlen(c);i++)
   {
   if((c[i]!=34 && c[i]!='\n'))
   printf("%c",c[i]);
   }
   printf("\n");
   }*/
/*void pwd(char t[],char r[])
  {
  getcwd(t,1023);
  int i,len1,len2;
  len1=strlen(t);
  len2=strlen(home);
  if(len1<len2)
  strcpy(r,t);
  else if(strncmp(t,home,len2-1)==0)
  {
  r[0]='~';
  r[1]='/';
  for(i=0;i<len1-len2;i++)
  {
  r[i+2]=t[len2+i+1];
  }	
  r[len2-len1+2]='\0';
  }
  else
  strcpy(r,t);
  }*/
pid_t pidg=-1;
void foo(int a)
{
	printf("Stopping process..%d\n",pidg);
	kill(pidg,9);
}
void com(char c[],int done)
{
	/*//pid_t pid=fork();
	  int pid=0;
	  char d1[2];
	  d1[0]=32;
	  d1[1]=0;
	  char *token;
	  int m=0;
	  if(pid<0)
	  {
	  perror("fork failed.");
	  exit(1);
	  }
	  else if(pid==0){
	  char* args[10];
	  token=strtok(c,d1);
	  while(token!=NULL)
	  {
	  strcpy(args[m],token);
	  printf("%s\n",args[m]);
	  token = strtok(NULL,d1);
	  m++;
	  }
	  }*/
	//printf("yoyo");


	char d1[2]=" ";
	char *token[100];
	char temp[1024];
	strcpy(temp,c);
	int m=0,i,k,flag1=0,len;
	token[m]=strtok(c,d1);
	while(token[m]!=NULL)
	{
		//printf("%s\n",token[m]);
		m++;
		token[m]=strtok(NULL,d1);
	}
	if(done==1)
	{
		k=strlen(token[m-1]);
		token[m-1][k-1]='\0';
	}
	if(strcmp(token[m-1],"&")==0)
	{
		flag1=1;
		token[m-1]=strtok(NULL,d1);
	}
	//printf("%s\n",token[0]);
	if(flag1==0)
	{
		pid_t pid=fork();
		pid_t pida=getpid();
		int re=0;
		if(pid<0)
		{
			perror("fork failed.");
			exit(1);
		}		
		else if(pid==0){
			signal(SIGINT, SIG_DFL);
			//printf("%d\n",getpid());
			re=execvp(token[0],token);
			if(re<0)
			{
				fprintf(stderr,"%s command can't be run\n",token[0]);
				exit(1);
			}
		}
		pidg=pid;
		signal(SIGTSTP,foo);
		wait(NULL);
		signal(SIGTSTP,SIG_IGN);
	}
	else
	{

		pid_t pid=fork();
		pid_t pida=getpid();
		int re=0;
		if(pid<0)
		{
			perror("fork failed.");
			exit(1);
		}		
		else if(pid==0){
			signal(SIGINT, SIG_DFL);
			re=execvp(token[0],token);
			if(re<0)
			{
				fprintf(stderr,"%s command can't be run\n",token[0]);
				exit(1);
			}
		}
		else{
			if(done==1)
			{
				len=strlen(temp);
				temp[len-1]='\0';
			}
			strcpy(queue[qp],temp);
			qu[qp]=pid;
			qp++;	
		}

	}
	/*signal(SIGINT, SIG_IGN);
	  signal(SIGSTOP,SIG_IGN);
	  if(flag1==0)
	  }
	 *signal(SIGINT, SIG_IGN);
	 signal(SIGSTOP,SIG_IGN);
	 if(flag1==0)
	 {
	 wait(NULL);
	 }
	 else
	 {
	 kill(pid,SIGSTOP);
	 if(done==1)
	 {
	 len=strlen(temp);
	 temp[len-1]='\0';
	 }
	 strcpy(queue[qp],temp);
	 qu[qp]=pid;
	 qp++;
	 }
	 return;	*/
}

void comp(char c[],int in,int out)
{
	/*//pid_t pid=fork();
	  int pid=0;
	  char d1[2];
	  d1[0]=32;
	  d1[1]=0;
	  char *token;
	  int m=0;
	  if(pid<0)
	  {
	  perror("fork failed.");
	  exit(1);
	  }
	  else if(pid==0){
	  char* args[10];
	  token=strtok(c,d1);
	  while(token!=NULL)
	  {
	  strcpy(args[m],token);
	  printf("%s\n",args[m]);
	  token = strtok(NULL,d1);
	  m++;
	  }
	  }*/
	//printf("yoyo");


	char d1[2]=" ";
	char *token[100];
	int m=0,i,k,flag1=0,len;
	token[m]=strtok(c,d1);
	while(token[m]!=NULL)
	{
		//printf("%s\n",token[m]);
		m++;
		token[m]=strtok(NULL,d1);
	}
	//printf("%s\n",token[0]);
	pid_t pid=fork();
	pid_t pida=getpid();
	int re=0;
	if(pid<0)
	{
		perror("fork failed.");
		exit(1);
	}		
	else if(pid==0){
		if(in!=0)
		{
			dup2(in,0);
			close(in);			
		}
		if(out!=1)
		{
			dup2(out,1);
			close(out);			
		}	
		//printf("%d\n",getpid());
		re=execvp(token[0],token);
		/*if(re<0)
		  {
		  fprintf(stderr,"%s command can't be run\n",token[0]);
		  exit(1);
		  }*/
	}
	wait(NULL);
	/*signal(SIGINT, SIG_IGN);
	  signal(SIGSTOP,SIG_IGN);
	  if(flag1==0)
	  }
	 *signal(SIGINT, SIG_IGN);
	 signal(SIGSTOP,SIG_IGN);
	 if(flag1==0)
	 {
	 wait(NULL);
	 }
	 else
	 {
	 kill(pid,SIGSTOP);
	 if(done==1)
	 {
	 len=strlen(temp);
	 temp[len-1]='\0';
	 }
	 strcpy(queue[qp],temp);
	 qu[qp]=pid;
	 qp++;
	 }
	 return;	*/
	}

void comr(char c[],char filename[],int way)
{
	/*//pid_t pid=fork();
	  int pid=0;
	  char d1[2];
	  d1[0]=32;
	  d1[1]=0;
	  char *token;
	  int m=0;
	  if(pid<0)
	  {
	  perror("fork failed.");
	  exit(1);
	  }
	  else if(pid==0){
	  char* args[10];
	  token=strtok(c,d1);
	  while(token!=NULL)
	  {
	  strcpy(args[m],token);
	  printf("%s\n",args[m]);
	  token = strtok(NULL,d1);
	  m++;
	  }
	  }*/
	//printf("yoyo");

	int fd;
	int in,out;
	out=dup(1);
	if(way==0)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC,0644);
	else
		fd= open(filename,O_CREAT |O_RDWR |O_APPEND,0644);

	if(fd == -1){
		perror("Failed to open file");
	}

	close(1);
	if(dup2(fd, 1) != 1)  // 1 refers to stdout
		perror("dup2 fail");

	char d1[2]=" ";
	char *token[100];
	int m=0,i,k,flag1=0,len;

	token[m]=strtok(c,d1);
	while(token[m]!=NULL)
	{
		//printf("%s\n",token[m]);
		m++;
		token[m]=strtok(NULL,d1);
	}
	//printf("%s\n",token[0]);
	pid_t pid=fork();
	int re=0;
	if(pid<0)
	{
		perror("fork failed.");
		exit(1);
	}
	else if(pid==0){
		signal(SIGINT, SIG_DFL);
		re=execvp(token[0],token);
		if(re<0!=0)
		{
			fprintf(stderr,"%s command can't be run\n",token[0]);
			exit(1);
		}
	}

	wait(NULL);
	close(fd);
	dup2(out,1);
	return;
}




void pinfo(char c[],int done)
{
	char d1[2]=" ";
	char *token[100];
	int m=0,i,k,flag1=0;
	token[m]=strtok(c,d1);
	while(token[m]!=NULL)
	{
		//printf("%s\n",token[m]);
		m++;
		token[m]=strtok(NULL,d1);
	}
	if(done==1)
	{
		k=strlen(token[m-1]);
		token[m-1][k-1]='\0';
	}
	printf("pid:  %s\n",token[1]);
	char yo[100]="/proc/";
	char mo[100];
	char bo1[100];
	char bo2[100];
	strcat(yo,token[1]);
	strcpy(mo,yo);
	strcat(mo,"/status");
	strcpy(bo1,"grep State ");
	strcat(bo1,mo);
	com(bo1,0);
	strcpy(bo2,"grep VmSize ");
	strcat(bo2,mo);
	com(bo2,0);
	strcat(yo,"/exe");
	char buf[100];
	readlink(yo,buf,100);
	printf("Executable Path:  %s\n",buf);

}
	void jobs(char c[],int done)
	{
		int i,len,m=0;
		len=strlen(c);
		for(i=0;i<qp;i++)
		{
			if(flq[i]==0)
			{
				printf("[%d] %s [%d]\n",m+1,queue[i],qu[i]);	
				m++;
			}
		}
	}
	void redirh(char c[])
	{
		int len=strlen(c),i,in=-1,ou=-1;
		char filename[100],fp=0;
		for(i=0;i<len;i++)
		{
			if(c[i]=='<')
			{
				in=i;
			}
			if(c[i]=='>')
				ou=i;
		}
		if(in!=-1 && ou==-1)
		{
			for(i=in+1;i<len;i++)
			{
				if(c[i]!=' ')
				{
					filename[fp]=c[i];
					fp++;
				}
			}
			filename[fp]='\0';
			//printf("%s\n",filename);
			c[in]=' ';
			for(i=in+1;i<in+1+strlen(filename);i++)
			{
				c[i]=filename[i-in-1];
			}
			c[in+1+strlen(filename)]='\0';
			com(c,0);
			//printf("%s\n",c);
		}
		else if(in==-1 && ou!=-1){
			int fd;
			for(i=ou+1;i<len;i++)
			{
				if(c[i]!=' ')
				{
					filename[fp]=c[i];
					fp++;
				}
			}
			filename[fp]='\0';
			int flag=0;
			//printf("%s\n",filename);

			if(c[ou-1]=='>')
				flag=1;
			if(flag==0)
			{
				c[ou]='\0';
				comr(c,filename,flag);
			}
			else
			{
				c[ou-1]='\0';
				comr(c,filename,flag);
			}

		}
		else{
			char filename2[100];		
			for(i=in+1;i<ou;i++)
			{
				if(c[i]!=' ')
				{
					filename[fp]=c[i];
					fp++;
				}
			}
			filename[fp]='\0';
			fp=0;
			for(i=ou+1;i<len;i++)
			{
				if(c[i]!=' ')
				{
					filename2[fp]=c[i];
					fp++;
				}
			}
			filename2[fp]='\0';
			printf("%s %s\n",filename,filename2);
			int way=0,fd,out;
			out=dup(1);
			if(c[ou-1]=='>')
				way=1;

			if(way==0)
				fd = open(filename2, O_WRONLY | O_CREAT | O_TRUNC,0644);
			else
				fd= open(filename2,O_CREAT |O_RDWR |O_APPEND,0644);

			if(fd == -1){
				perror("Failed to open file");
			}
			close(1);
			if(dup2(fd, 1) != 1)  // 1 refers to stdout{
			{
				perror("dup2 fail");
				return;
			}
			if(way!=1)
				c[ou]='\0';
			else
				c[ou-1]='\0';
			c[in]=' ';
			printf("%s\n",c);
			com(c,0);
			close(fd);
			dup2(out,1);

		}
		}
		void redir_pipe(char c[],int done)
		{
			int len=strlen(c),i,flag=0,redir=0;
			if(done==1)
			{
				c[len-1]='\0';
				len--;
			}
			//now three cases only pipes,pipes and redirections,only redirections
			for(i=0;i<len;i++)
			{
				if(c[i]=='|')
				{
					flag=1;	
				}
				if(c[i]=='<' || c[i]=='>')
				{
					redir=1;
				}

			}
			if(redir==1 && flag==0)
			{
				redirh(c);
			}
			else if(redir==1 && flag==1)
			{
				printf("It is not implemented\n");		
			}
			else if(redir==0 && flag==1)
			{
			int stin,stout;
			stin=dup(0);
			stout=dup(1);
			char d1[2]="|";
			char *token[100];
			int m=0,i,k,flag1=0,len;
			token[m]=strtok(c,d1);
			while(token[m]!=NULL)
			{
				m++;
				token[m]=strtok(NULL,d1);
			}
			int in=0;

			pid_t pid;
			int pipefds[2];

			for(i=0;i<m-1;i++)
			{
				pipe(pipefds);
				comp(token[i],in,pipefds[1]);
				close(pipefds[1]);			
				in = pipefds[0];
			}
			char d2[2]=" ";
			char *token2[100];
			int mt=0;
			token2[mt]=strtok(token[m-1],d2);
			while(token2[mt]!=NULL)
			{
				mt++;
				token2[mt]=strtok(NULL,d2);
			}
			pid=fork();
			if(pid==-1){
				dup2(stin, 0);
				dup2(stout,1);
				close(stin);
				close(stout);

			}
			else if(pid==0)
			{
				if (in != 0)
					dup2 (in, 0);
				execvp(token2[0],token2);  
				dup2(stin, 0);
				dup2(stout,1);
				close(stin);
				close(stout);
			}
			wait(NULL);

		}
	}
	void kjob(char c[],int done)
	{
		int len;
		len=strlen(c);
		if(done==1)
		{
			c[len-1]='\0';
		}

		char d1[2]=" ";
		char *token[100];
		int m=0,i,k,flag1=0;
		token[m]=strtok(c,d1);
		while(token[m]!=NULL)
		{
			//printf("%s\n",token[m]);
			m++;
			token[m]=strtok(NULL,d1);
		}
		if(m!=3)
		{
			fprintf(stderr,"sorry bro\n");
			return;
		}	
		int in,signo;
		pid_t rpid=-1;
		in=token[1][0]-'0';
		signo=token[2][0]-'0';
		m=0;
		for(i=0;i<qp;i++)
		{
			if(flq[i]==0)
			{
				if(m+1==in)
				{
					rpid=qu[i];
					break;
				}
				m++;
			}
		}
		//printf("%d\n",rpid);
		if(rpid!=-1)
			kill(rpid,signo);
		else
			fprintf(stderr,"sorry bro\n");
	}
	void fg(char c[],int done)
	{

		int len;
		len=strlen(c);
		if(done==1)
		{
			c[len-1]='\0';
		}

		char d1[2]=" ";
		char *token[100];
		int m=0,i,k,flag1=0;
		token[m]=strtok(c,d1);
		while(token[m]!=NULL)
		{
			//printf("%s\n",token[m]);
			m++;
			token[m]=strtok(NULL,d1);
		}
		if(m!=2)
		{
			fprintf(stderr,"incorrect format\n");
			return;
		}
		int in=token[1][0]-'0';
		pid_t rpid=-1;
		m=0;
		for(i=0;i<qp;i++)
		{
			if(flq[i]==0)
			{
				if(m+1==in)
				{
					rpid=qu[i];
					break;
				}
				m++;
			}
		}
		if(rpid!=-1)
		{
			waitpid(rpid,NULL,0);
		}
		else
			fprintf(stderr,"incorrect job number\n");
		//signal(SIGTTOU, SIG_IGN);
	}
	void killallbg()
	{
		int i;
		for(i=0;i<qp;i++)
		{
			if(flq[i]==0)
			{
				kill(qu[i],9);
			}
		}
	}
	void check_command(char c[])
	{
		strcpy(cp,c);
		int m=0,i,flag,k;
		const char d2[2]=";";
		char *token[100];
		//part 1 space delimeter
		token[m] =strtok(cp,d2);
		while(token[m]!=NULL)
		{	
			//printf("%s\n",token[m]);
			//	com(token);
			m++;
			token[m] = strtok(NULL,d2);
		}
		k=m-1;
		m=0;
		flag=0;
		if(flag==0)
			while(token[m]!=NULL)
			{
				flag=0;
				for(i=0;i<strlen(token[m]);i++)
				{
					if(token[m][i]=='<' || token[m][i]=='>' || token[m][i]=='|')
					{
						flag=3;
					}
				}
				/*
				   if(strcmp(token[m],"echo")==0)
				   {
				   ec(c);
				   flag=1;
				   }
				   if(strcmp(token[m],"cd")==0)
				   {
				   cd(token[m+1]);
				   flag=1;
				   }*/
				if(flag==0)
				{
					if(strncmp(token[m],"pwd ",4)==0)
					{
						p_wd(cwd);
						m++;	
						flag=1;
					}
					else if(strncmp(token[m],"echo",4)==0)
					{
						echo(token[m]);
						m++;
						flag=1;
					}
					else if(strncmp(token[m],"cd",2)==0)
					{
						if(m==k)
							ch_dir(token[m],1,home);
						else
							ch_dir(token[m],0,home);

						m++;
						flag=1;
					}
					else if(strncmp(token[m],"pinfo",5)==0)
					{
						if(m==k)
							pinfo(token[m],1);
						else
							pinfo(token[m],0);
						m++;
						flag=1;
					}
					else if(strncmp(token[m],"jobs",4)==0)
					{
						if(m==k)
							jobs(token[m],1);
						else
							jobs(token[m],0);
						m++;
						flag=1;
					}
					else if(strncmp(token[m],"kjob",4)==0)
					{

						if(m==k)
							kjob(token[m],1);
						else
							kjob(token[m],0);
						m++;
						flag=1;
					}
					else if(strncmp(token[m],"fg",2)==0)
					{
						if(m==k)
						  fg(token[m],1);
						  else
						  fg(token[m],0);
						  m++;
						  flag=1;
					}
					else if(strncmp(token[m],"killallbg",2)==0)
					{
						if(m==k)
						  killallbg();
						  else
						  killallbg();
						  m++;
						  flag=1;
					}
					if(flag==0)
					{
						if(m==k)
						{	
							com(token[m],1);
							m++;
						}
						else
						{
							com(token[m],0);	
							m++;
						}
					}
				}
				else if(flag==3)
				{
					if(m==k)
						redir_pipe(token[m],1);
					else
						redir_pipe(token[m],0);
					m++;
				}
			}
	}
	//global variables
	/*void ign(int a)
	  {
	  printf("yoyo");
	  }
	  void ign1(int a)
	  {
	  glb=a;
	  }*/
	int main()
	{
		char b[1024];
		size_t bufsize=1024;
		strcpy(cwr,"~");
		int loopv=1;
		getcwd(cwd,1023);
		strcpy(home,cwd);
		pid_t pidi;
		int status,it;
		for(it=0;it<100;it++)
		{
			flq[it]=0;
		}
		while(loopv)
		{
			signal(SIGINT, SIG_IGN);
			signal(SIGTSTP, SIG_IGN);
			signal (SIGINT, SIG_IGN);
			signal (SIGTSTP, SIG_IGN);
			signal (SIGQUIT, SIG_IGN);
			signal (SIGTTIN, SIG_IGN);
			signal (SIGTTOU, SIG_IGN);
			int check;
			char *line;
			uname(&a);
			pwd(cwd,cwr,home);
			printf("<%s@%s:%s>",getenv("USER"),a.nodename,cwr);
			line=fgets(b,1024,stdin);
			if(strcmp(b,"quit\n")==0)
			{
				printf("exiting Shell\n");
				break;
			}
			if(line==NULL){
				printf("exiting Shell\n");
				break;
			}
			//printf("%s\n",b);
			while((pidi = waitpid(-1, &status, WNOHANG)) > 0) {
			  fprintf(stderr,"[proc %d exited with code %d]\n",
			  pidi, WEXITSTATUS(status));
			  for(it=0;it<qp;it++)
			  {
			  if(pidi==qu[it])
			  {
			  flq[it]=1;
			  }

			  }
			  }
			if(b[0]!='\n')
				check_command(b);
		}
		return 0;
	}
