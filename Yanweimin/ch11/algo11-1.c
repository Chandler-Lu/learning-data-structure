 /* algo11-1.c ����bo11-1.c�ĳ��� */
#include "../ch1/c1.h"
 typedef int InfoType; /* ������������������� */
 #include "../ch9/c9.h"
 #include "../ch10/c10-1.h" /* ����KeyType��RedType��SqList */
 #include "../ch10/bo10-1.c"
 #define k 5 /* k·�鲢 */
 #include "bo11-1.c"
 #define N 3 /* ��ÿС���ļ���N������(�ɽ������ļ�һ�ζ����ڴ�ĳ�ΪС�ļ�) */
 #define M 10 /* �����M�����ݻ��� */

 void print(RedType t)
 {
   printf("(%d,%d)",t.key,t.otherinfo);
 }

 void main()
 {
   RedType a[k*N]={{16,1},{15,2},{10,3},{20,4},{9,5},{18,6},{22,7},{20,8},{40,9},{15,10},{25,11},{6,12},{12,13},{48,14},{37,15}}; /* ��k*N����¼������ */
   RedType r,t={MAXKEY}; /* С�ļ�β���Ľ�����־ */
   SqList l;
   int i,j;
   char fname[k][3],fori[4]="ori",fout[4]="out",s[3];
   LoserTree ls;
   /* ������a����1�����ļ�(���ܽ������ļ�һ�ζ����ڴ�ĳ�Ϊ���ļ�) */
   fp[k]=fopen(fori,"wb"); /* ��д�ķ�ʽ�򿪴��ļ�fori */
   fwrite(a,sizeof(RedType),k*N,fp[k]); /* ������a�е�����д���ļ�fori��(��ʾ1�����ļ�) */
   fclose(fp[k]); /* �ر��ļ�fori */
   fp[k]=fopen(fori,"rb"); /* �Զ��ķ�ʽ�򿪴��ļ�fori */
   printf("���ļ��ļ�¼Ϊ:\n");
   for(i=1;i<=N*k;i++)
   {
     fread(&r,sizeof(RedType),1,fp[k]); /* ���ν����ļ�fori�����ݶ���r */
     print(r); /* ���r������ */
     if(i%M==0)
       printf("\n");
   }
   printf("\n");
   rewind(fp[k]); /* ʹfp[k]��ָ�����·��ش��ļ�fori����ʼλ�ã��Ա����¶����ڴ棬������������ļ� */
   for(i=0;i<k;i++) /* �����ļ�fori�����ݷֳ�k�飬ÿ��N������ */
   { /* �����ֱ�浽С�ļ�f0,f1,���� */
     fread(&l.r[1],sizeof(RedType),N,fp[k]); /* �����ļ�fori��N�����ݶ���l */
     l.length=N;
     InsertSort(&l); /* ��l�����ڲ����� */
     _itoa(i,s,10); /* ����k���ļ���f0,f1,f2,�� */
     strcpy(fname[i],"f");
     strcat(fname[i],s);
     fp[i]=fopen(fname[i],"wb"); /* ��д�ķ�ʽ���ļ�f0,f1,�� */
     fwrite(&l.r[1],sizeof(RedType),N,fp[i]); /* ��������N�����ݷֱ�д��f0,f1,�� */
     fwrite(&t,sizeof(RedType),1,fp[i]); /* ���ļ�������־�ֱ�д��f0,f1,�� */
     fclose(fp[i]); /* �ر��ļ�f0,f1,�� */
   }
   fclose(fp[k]); /* �رմ��ļ�fori */
   for(i=0;i<k;i++)
   { /* ���δ�f0,f1,f2,��,k���ļ� */
     _itoa(i,s,10); /* ����k���ļ���f0,f1,f2,�� */
     strcpy(fname[i],"f");
     strcat(fname[i],s);
     fp[i]=fopen(fname[i],"rb"); /* �Զ��ķ�ʽ���ļ�f0,f1,�� */
     printf("�������ļ�f%d�ļ�¼Ϊ:\n",i);
     for(j=0;j<=N;j++)
     {
       fread(&r,sizeof(RedType),1,fp[i]); /* ���ν�f0,f1,�������ݶ���r */
       print(r); /* ���r������ */
     }
     printf("\n");
     rewind(fp[i]); /* ʹfp[i]��ָ�����·���f0,f1,������ʼλ�ã��Ա����¶����ڴ� */
   }
   fp[k]=fopen(fout,"wb"); /* ��д�ķ�ʽ�򿪴��ļ�fout */
   K_Merge(ls,b); /* ���ð�����ls��k������鲢���еļ�¼�鲢������鲢�Σ������ļ�fout */
   for(i=0;i<k;i++)
     fclose(fp[i]); /* �ر��ļ�f0,f1,�� */
   fclose(fp[k]); /* �ر��ļ�fout */
   fp[k]=fopen(fout,"rb"); /* �Զ��ķ�ʽ�򿪴��ļ�fout��֤���� */
   printf("�����Ĵ��ļ��ļ�¼Ϊ:\n");
   for(i=1;i<=N*k+1;i++)
   {
     fread(&t,sizeof(RedType),1,fp[k]);
     print(t);
     if(i%M==0)
       printf("\n");
   }
   printf("\n");
   fclose(fp[k]); /* �ر��ļ�fout */
 }