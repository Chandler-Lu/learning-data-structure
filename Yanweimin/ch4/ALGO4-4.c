 /* algo4-4.c ���������ؼ��������ļ�bookidx.txt���㷨4.9��4.14 */
 /* Ϊ����algo4-5.c��׼�� */
#include "../ch1/c1.h"
 typedef int ElemType;
 #include "../ch2/c2-5.h"
 #include "../ch2/bo2-6.c"
 #include "c4-2.h"
 #include "bo4-2.c"

 #define MaxKeyNum 25 /* ���������������(�ؼ��ʵ������) */
 #define MaxLineLen 51 /* ��Ŀ��(����+���)buf����󳤶� */
 #define MaxWordNum 10 /* �ʱ�(һ����Ĺؼ���)��������� */
 #define MaxNoIdx 10 /* ���ô�(��ָ��д)������� */
 typedef struct
 {
   char *item[MaxWordNum]; /* �ʱ�(�ַ���)ָ������ */
   int last; /* �ʵ����� */
 }WordListType; /* �ʱ�����(˳���) */

 typedef struct
 {
   HString key; /* �ؼ���(�ѷ�������,c4-2.h) */
   LinkList bnolist; /* ����������������(c2-5.h) */
 }IdxTermType; /* ���������� */

 typedef struct
 {
   IdxTermType item[MaxKeyNum+1];
   int last; /* �ؼ��ʵĸ��� */
 }IdxListType; /* ����������(�����) */

 typedef struct
 {
   char *item[MaxNoIdx]; /* ���ôʱ�ָ������ */
   int last; /* ���ôʵ����� */
 }NoIdxType; /* ���ôʱ�����(�����) */

 /* ȫ�ֱ��� */
 char buf[MaxLineLen+1]; /* ��ǰ��Ŀ��(����'\0') */
 WordListType wdlist; /* �ݴ�һ����Ĵʱ� */
 NoIdxType noidx; /* ���ôʱ� */

 void InitIdxList(IdxListType *idxlist)
 { /* ��ʼ����������������idxlistΪ�ձ�������idxliat.item[0]��һ�մ� */
   (*idxlist).last=0;
   InitString(&(*idxlist).item[0].key); /* bo4-2.c */
   InitList(&(*idxlist).item[0].bnolist); /* bo2-6.c */
 }

 void ExtractKeyWord(int *BookNo)
 { /* ��buf����ȡ�����ؼ��ʵ��ʱ�wdlist����Ŵ���BookNo */
   int i,l,f=1; /* f���ַ���������־ 0: ���� 1: δ���� */
   char *s1,*s2;
   if(buf[0]<'0'||buf[0]>'9') /* buf������ĸ�������� */
     exit(OVERFLOW);
   for(i=1;i<=wdlist.last;i++) /* �ͷ���һ����Ŀ�ڴʱ�wdlist�Ĵ洢�ռ� */
   {
     free(wdlist.item[i]);
     wdlist.item[i]=NULL;
   }
   wdlist.last=0;
   *BookNo=(buf[0]-'0')*100+(buf[1]-'0')*10+(buf[2]-'0'); /* ǰ��λΪ��� */
   s2=&buf[2]; /* s1ָ����ŵ�β�ַ� */
   do
   { /* ��ȡ�����ؼ��ʵ��ʱ�wdlist */
     s1=s2+1; /* s1����ƶ�һ������ */
     s2=strchr(s1,' '); /* s2ָ��s1�ĵ�һ���ո�,��û��,����NULL */
     if(!s2) /* ����β */
     {
       s2=strchr(s1,'\12'); /* s2ָ��buf�����һ���ַ�(�س���) */
       f=0;
     }
     l=s2-s1; /* ���ʳ��� */
     if(s1[0]>='A'&&s1[0]<='Z') /* ��������ĸΪ��д */
     { /* д��ʱ� */
       wdlist.item[wdlist.last]=(char *)malloc((l+1)*sizeof(char));
       /* ���ɴ��ռ�(����'\0') */
       for(i=0;i<l;i++)
         wdlist.item[wdlist.last][i]=s1[i]; /* д��ʱ� */
       wdlist.item[wdlist.last][l]=0;
       for(i=0;i<noidx.last;i++) /* �����Ƿ�Ϊ���ô� */
         if(!strcmp(wdlist.item[wdlist.last],noidx.item[i]))
           break;
       if(i!=noidx.last) /* �ǳ��ô� */
       {
         free(wdlist.item[wdlist.last]); /* �Ӵʱ���ɾ���ô� */
         wdlist.item[wdlist.last]=NULL;
       }
       else
         wdlist.last++; /* �ʱ�����+1 */
     }
   }while(f);
 }

 void GetWord(int i,HString *wd)
 { /* ��wd���شʱ�wdlist�е�i���ؼ��� */
   StrAssign(wd,wdlist.item[i]); /* ���ɹؼ����ַ��� bo4-2.c */
 }

 int Locate(IdxListType *idxlist,HString wd,Status *b)
 { /* ��������idxlist�в�ѯ�Ƿ������wd��ȵĹؼ��ʡ�������,�򷵻��� */
   /* ���������е�λ��,��bȡֵTRUE;���򷵻ز���λ��,��bȡֵFALSE */
   int i,m;
   for(i=(*idxlist).last;(m=StrCompare((*idxlist).item[i].key,wd))>0;--i); /* bo4-2.c */
   if(m==0) /* �ҵ� */
   {
     *b=TRUE;
     return i;
   }
   else
   {
     *b=FALSE;
     return i+1;
   }
 }

 void InsertNewKey(IdxListType *idxlist,int i,HString wd)
 { /* ��������idxlist�ĵ�i���ϲ����¹ؼ���wd,����ʼ���������������Ϊ�ձ� */
   int j;
   InitList(&(*idxlist).item[(*idxlist).last+1].bnolist); /* bo2-6.c */
   for(j=(*idxlist).last;j>=i;--j) /* ���������� */
     (*idxlist).item[j+1]=(*idxlist).item[j];
   InitString(&(*idxlist).item[i].key); /* bo4-2.c */
   StrCopy(&(*idxlist).item[i].key,wd); /* �����������µ������� bo4-2.c */
   InitList(&(*idxlist).item[i].bnolist); /* ��ʼ�����������Ϊ�ձ� bo2-6.c */
   (*idxlist).last++;
 }

 void InsertBook(IdxListType *idxlist,int i,int bno)
 { /* ��������idxlist�ĵ�i���в������Ϊbno������ */
   Link p;
   if(!MakeNode(&p,bno)) /* ����ʧ�� bo2-6.c */
     exit(OVERFLOW);
   p->next=NULL;
   Append(&(*idxlist).item[i].bnolist,p); /* �����µ�������� bo2-6.c */
 }

 void InsIdxList(IdxListType *idxlist,int bno)
 { /* �����Ϊbno�Ĺؼ��ʲ��������� */
   int i,j;
   Status b;
   HString wd;
   InitString(&wd); /* bo4-2.c */
   for(i=0;i<wdlist.last;i++)
   {
     GetWord(i,&wd);
     j=Locate(idxlist,wd,&b);
     if(!b)
       InsertNewKey(idxlist,j,wd); /* �����µ������� */
     InsertBook(idxlist,j,bno); /* ����������� */
   }
 }

 void PutText(FILE *f,IdxListType idxlist)
 { /* �����ɵ�������idxlist������ļ�f */
   int i,j;
   Link p;
   fprintf(f,"%d\n",idxlist.last);
   for(i=1;i<=idxlist.last;i++)
   {
     for(j=0;j<idxlist.item[i].key.length;j++)
       fprintf(f,"%c",idxlist.item[i].key.ch[j]);
     fprintf(f,"\n%d\n",idxlist.item[i].bnolist.len);
     p=idxlist.item[i].bnolist.head;
     for(j=1;j<=idxlist.item[i].bnolist.len;j++)
     {
       p=p->next;
       fprintf(f,"%d ",p->data);
     }
     fprintf(f,"\n");
   }
 }

 void main()
 {
   FILE *f; /* �κ�ʱ������һ���ļ� */
   IdxListType idxlist; /* ������ */
   int BookNo; /* ��ű��� */
   int k,l;
   f=fopen("NoIdx.txt","r"); /* �򿪳��ô��ļ� */
   if(!f)
     exit(OVERFLOW);
   fscanf(f,"%d",&noidx.last); /* ���ôʸ��� */
   for(k=0;k<noidx.last;k++) /* �ѳ��ô��ļ������ݿ���noidx�� */
   {
     fscanf(f,"%s",buf);
     l=strlen(buf);
     noidx.item[k]=(char*)malloc(l*sizeof(char));
     strcpy(noidx.item[k],buf);
   }
   fclose(f);
   f=fopen("BookInfo.txt","r"); /* ����Ŀ�ļ� */
   if(!f)
     exit(FALSE);
   InitIdxList(&idxlist); /* ��ʼ��������idxlistΪ�� */
   wdlist.last=0; /* �ʱ����ȳ�ֵΪ0 */
   while(!feof(f))
   {
     fgets(buf,MaxLineLen,f);
     l=strlen(buf);
     if(l<=1)
       break;
     ExtractKeyWord(&BookNo); /* ��buf����ȡ�ؼ��ʵ��ʱ�����Ŵ���BookNo */
     InsIdxList(&idxlist,BookNo);
   }
   fclose(f);
   f=fopen("BookIdx.txt","w");
   if(!f)
     exit(INFEASIBLE);
   PutText(f,idxlist); /* �����ɵ�������idxlist������ļ�f */
   fclose(f);
 }