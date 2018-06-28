#include"Sequence.h"
char strc[1500001];
char* substr[1500001];
int cmpl(const void* p,const void* q)
{
	return strcmp(*(char **)p, *(char **)q);
}
Sequence::Sequence(){val="";cntA=cntT=cntC=cntG=0;}
Sequence::Sequence(const string& filename)
{
	char tmp;
	val="";cntA=cntT=cntC=cntG=0;
	freopen(filename.c_str(),"r",stdin);
	while (cin>>tmp) 
	if (tmp=='A'||tmp=='T'||tmp=='G'||tmp=='C')
	{
		val+=tmp;
		if (tmp=='A') {cntA++;continue;}
		if (tmp=='T') {cntT++;continue;}
		if (tmp=='G') {cntG++;continue;}
		if (tmp=='C') {cntC++;continue;}
	}
	freopen("CON","r",stdin);
}
int Sequence::length() {return val.length();}
int Sequence::numberOf(char base)
{
	if (base=='A') return cntA;
	if (base=='T') return cntT;
	if (base=='G') return cntG;
	if (base=='C') return cntC;
	return 0;
}
string Sequence::longestConsecutive()
{
	int cur=1,maxl=1,start=0;
	int tmpl=1,st=0;
	while (cur<int(val.length()))
	{
		if (cur>0)
		{
			if (val[cur]==val[cur-1]) 
			{
				tmpl++;
				if (tmpl>maxl) start=st,maxl=tmpl;	
			}
			else tmpl=1,st=cur;
		}
		cur++;
		/*cur+=maxl;
		char ch=val[cur];
		int j;
		for (j=cur-1;j>0 && ch==val[j];j--) tmpl++;
		st=j+1;*/
	}
	return val.substr(start,maxl);
}
string Sequence::longestRepeated()
{
	memcpy(strc,val.c_str(),val.size());
	for (int i=0;i<int(val.size());i++) substr[i]=&strc[i];
	qsort(substr,val.size(),sizeof(char*),cmpl);
	int maxlen=0,index=0;
	for(int i=0;i<int(val.size())-1;i++)
	{  
      	int tmp=comlen(substr[i],substr[i+1]);  
      	if(tmp>maxlen)
		{  
        	maxlen=tmp;
        	index=i;  
      	}  
   	}  
   	char tmp[500001];
   	strncpy(tmp,substr[index],maxlen);
   	tmp[maxlen]='\0';
   	string ans=tmp;
   	return ans;
}
int Sequence::comlen(const char* s1,const char* s2)
{
	int len=0;
    while((*s1)==(*s2) && *s1 && *s2)
    {
        len++;
        s1++;s2++;
    }		
    return len;
}			
